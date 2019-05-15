//
//  Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Jakob Moosbrugger
//                <https://github.com/casm-lang/libtptp>
//
//  This file is part of libtptp.
//
//  libtptp is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  libtptp is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with libtptp. If not, see <http://www.gnu.org/licenses/>.
//
//  Additional permission under GNU GPL version 3 section 7
//
//  libtptp is distributed under the terms of the GNU General Public License
//  with the following clarification and special exception: Linking libtptp
//  statically or dynamically with other modules is making a combined work
//  based on libtptp. Thus, the terms and conditions of the GNU General
//  Public License cover the whole combination. As a special exception,
//  the copyright holders of libtptp give you permission to link libtptp
//  with independent modules to produce an executable, regardless of the
//  license terms of these independent modules, and to copy and distribute
//  the resulting executable under terms of your choice, provided that you
//  also meet, for each linked independent module, the terms and conditions
//  of the license of that module. An independent module is a module which
//  is not derived from or based on libtptp. If you modify libtptp, you
//  may extend this exception to your version of the library, but you are
//  not obliged to do so. If you do not wish to do so, delete this exception
//  statement from your version.
//

#include "AstToZ3Pass.h"

#include <libtptp/transform/SourceToAstPass>

#include <libtptp/Logger>

#include <libpass/PassRegistry>

#include <libstdhl/File>
#include <libstdhl/Stack>

#include <z3++.h>

#include <map>

using namespace libtptp;

char AstToZ3Pass::id = 0;

static libpass::PassRegistration< AstToZ3Pass > PASS(
    "AstToZ3Pass", "transforms the specification into a z3 model", "ast-to-z3", 0 );

class VariableManager
{
  private:
    std::vector< std::map< std::string, z3::expr > > m_bound_vars;
    std::map< std::string, z3::expr > m_unbound_vars;

    std::map< std::string, z3::sort > m_sorts;
    z3::sort m_universal;
    libstdhl::Stack< z3::sort > m_const_sort;

  public:
    VariableManager( z3::context& context );

    void pushScope( void );
    void popScope( void );

    // const z3::expr& would be better, but c++ doesn't allow it
    const libstdhl::Optional< const z3::expr > get( const std::string& name );
    std::pair< typename decltype( m_unbound_vars )::iterator, bool > pushUnbound(
        const std::string& name, const z3::expr& var );
    std::pair< typename decltype( m_bound_vars )::value_type::iterator, bool > pushBound(
        const std::string& name, const z3::expr& var );

    const libstdhl::Optional< const z3::sort > getSort( const std::string& name );
    std::pair< typename decltype( m_sorts )::iterator, bool > pushSort(
        const std::string& name, const z3::sort& sort );

    libstdhl::Stack< z3::sort >& constSort( void );
    const z3::sort& universalSort( void );
};

class AstToZ3Visitor : public RecursiveVisitor
{
  private:
    struct Z3_expr
    {
        enum class Tag
        {
            EXPR,
            EXPR_VECTOR,
            SORT,
        } tag;

      private:
        union
        {
            z3::expr* expr;
            z3::expr_vector* expr_vec;
            z3::sort* sort;
        };

      public:
        // explicit conversions for template access using static cast
        explicit Z3_expr( z3::expr&& expr );
        explicit Z3_expr( z3::expr_vector&& expr );
        explicit Z3_expr( z3::sort&& expr );

        explicit operator z3::expr() const;
        explicit operator z3::expr_vector() const;
        explicit operator z3::sort() const;
    };

    class Z3Stack : public Stack< Z3_expr >
    {
      public:
        using Stack::Stack;

        using Stack::pop;
        using Stack::push;

        template < typename T >
        T pop( void )
        {
            const auto value = Stack::pop();
            return static_cast< const T >( value );
        }

        template < typename T >
        void push( T&& t )
        {
            Stack::push( Z3_expr( std::move( t ) ) );
        }

        Z3_expr::Tag topType( void )
        {
            return top().tag;
        }
    };

    std::shared_ptr< Context > m_astContext;
    z3::context m_context;
    z3::solver m_solver;
    Z3Stack m_stack;
    libtptp::Logger m_log;
    VariableManager m_variables;

  public:
    AstToZ3Visitor( libtptp::Logger log );

  public:
    void visit( Specification& node ) override;

    void visit( FirstOrderFormula& node ) override;
    void visit( TypedFirstOrderFormula& node ) override;
    void visit( TypedHigherOrderFormula& node ) override;
    void visit( TPTPProcessInstructionFormula& node ) override;
    void visit( ClauseNormalFormFormula& node ) override;
    void visit( TheoryComputableFunctionalsFormula& node ) override;
    void visit( FormulaData& node ) override;
    void visit( Role& node ) override;

    void visit( UnaryLogic& node ) override;
    void visit( BinaryLogic& node ) override;
    void visit( QuantifiedLogic& node ) override;
    void visit( InfixLogic& node ) override;
    void visit( LogicTuple& node ) override;
    void visit( SequentLogic& node ) override;

    void visit( VariableTerm& node ) override;
    void visit( ConditionalTerm& node ) override;
    void visit( DefinitionTerm& node ) override;

    void visit( FunctorAtom& node ) override;
    void visit( ConstantAtom& node ) override;
    void visit( DefinedAtom& node ) override;
    void visit( DefinitionAtom& node ) override;
    void visit( ConnectiveAtom& node ) override;

    void visit( AtomType& node ) override;
    void visit( BinaryType& node ) override;
    void visit( TypedAtom& node ) override;
    void visit( TupleType& node ) override;
    void visit( QuantifiedType& node ) override;
    void visit( SubType& node ) override;

    void visit( Identifier& node ) override;

    void visit( IntegerLiteral& node ) override;
    void visit( RationalLiteral& node ) override;
    void visit( RealLiteral& node ) override;
    void visit( DistinctObjectLiteral& node ) override;
    void visit( ListLiteral& node ) override;

    void visit( Token& node ) override;

    void visit( IncludeDefinition& node ) override;
    void visit( FormulaDefinition& node ) override;

    void visit( GeneralData& node ) override;
    void visit( GeneralList& node ) override;
    void visit( GeneralAggregator& node ) override;
    void visit( GeneralFunction& node ) override;
    void visit( Annotation& node ) override;

    z3::solver& solver( void );

  private:
    bool checkArgNum(
        const SourceLocation& loc, const std::string& name, size_t expected, size_t actual );
};

//////////////////////////////////
///// Helpers
//////////////////////////////////
z3::expr toInt( const z3::expr& real )
{
    return z3::expr( real.ctx(), Z3_mk_real2int( real.ctx(), real ) );
}

z3::expr toReal( const z3::expr& real )
{
    return z3::expr( real.ctx(), Z3_mk_int2real( real.ctx(), real ) );
}

z3::expr ceil( const z3::expr& e )
{
    return -toReal( toInt( -e ) );
}

z3::expr truncate( z3::expr e )
{
    return z3::ite( e >= 0, toInt( e ), ceil( e ) );
}

VariableManager::VariableManager( z3::context& context )
: m_universal( context.uninterpreted_sort( "$i" ) )
{
    m_sorts.emplace( "$i", m_universal );
    m_sorts.emplace( "$iType", m_universal );
    z3::sort s_bool = context.bool_sort();
    m_sorts.emplace( "$o", s_bool );
    m_sorts.emplace( "$oType", s_bool );
    // TODO: @moosbruggerj $tType
    m_sorts.emplace( "$real", context.real_sort() );
    m_sorts.emplace( "$rat", context.real_sort() );
    m_sorts.emplace( "$int", context.int_sort() );

    // set up const sort stack
    m_const_sort.push( s_bool );
}

void VariableManager::pushScope( void )
{
    m_bound_vars.emplace_back();
}

void VariableManager::popScope( void )
{
    m_bound_vars.pop_back();
}

// const z3::expr& would be better, but c++ doesn't allow it
const libstdhl::Optional< const z3::expr > VariableManager::get( const std::string& name )
{
    for( auto it = m_bound_vars.rbegin(); it != m_bound_vars.rend(); ++it )
    {
        if( it->find( name ) != it->end() )
        {
            return it->at( name );
        }
    }

    if( m_unbound_vars.find( name ) != m_unbound_vars.end() )
    {
        return m_unbound_vars.at( name );
    }

    return libstdhl::Optional< const z3::expr >();
}

std::pair< typename decltype( VariableManager::m_unbound_vars )::iterator, bool >
VariableManager::pushUnbound( const std::string& name, const z3::expr& var )
{
    return m_unbound_vars.emplace( name, var );
}

std::pair< typename decltype( VariableManager::m_bound_vars )::value_type::iterator, bool >
VariableManager::pushBound( const std::string& name, const z3::expr& var )
{
    return m_bound_vars.rbegin()->emplace( name, var );
}

const libstdhl::Optional< const z3::sort > VariableManager::getSort( const std::string& name )
{
    if( m_sorts.find( name ) != m_sorts.end() )
    {
        return m_sorts.at( name );
    }

    return libstdhl::Optional< const z3::sort >();
}

std::pair< typename decltype( VariableManager::m_sorts )::iterator, bool >
VariableManager::pushSort( const std::string& name, const z3::sort& sort )
{
    return m_sorts.emplace( name, sort );
}

libstdhl::Stack< z3::sort >& VariableManager::constSort( void )
{
    return m_const_sort;
}

const z3::sort& VariableManager::universalSort( void )
{
    return m_universal;
}

AstToZ3Visitor::Z3_expr::Z3_expr( z3::expr&& expr )
: tag( Tag::EXPR )
, expr( new z3::expr( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( z3::expr_vector&& expr )
: tag( Tag::EXPR_VECTOR )
, expr_vec( new z3::expr_vector( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( z3::sort&& expr )
: tag( Tag::SORT )
, sort( new z3::sort( expr ) )
{
}

AstToZ3Visitor::Z3_expr::operator z3::expr() const
{
    if( tag != Tag::EXPR )
    {
        throw std::domain_error( "union is not of stackType expr" );
    }
    auto r = *expr;
    delete expr;
    return r;
}

AstToZ3Visitor::Z3_expr::operator z3::expr_vector() const
{
    if( tag != Tag::EXPR_VECTOR )
    {
        throw std::domain_error( "union is not of stackType expr_vector" );
    }
    auto r = *expr_vec;
    delete expr_vec;
    return r;
}

AstToZ3Visitor::Z3_expr::operator z3::sort() const
{
    if( tag != Tag::SORT )
    {
        throw std::domain_error( "union is not of stackType sort" );
    }
    auto r = *sort;
    delete sort;
    return r;
}

AstToZ3Visitor::AstToZ3Visitor( libtptp::Logger log )
: m_solver( m_context )
, m_log( log )
, m_variables( m_context )
{
}

void AstToZ3Visitor::visit( Specification& node )
{
    // TODO: @moosbruggerj remove
    RecursiveVisitor::visit( node );
}

void AstToZ3Visitor::visit( FirstOrderFormula& node )
{
    m_astContext = std::make_shared< Context >( Context::fof() );

    RecursiveVisitor::visit( node );

    auto formula = m_stack.pop< z3::expr >();

    if( m_stack.size() != 0 )
    {
        std::stringstream ss;
        ss << "stack not empty after formula traversal, at FOF." << std::endl;
        ss << formula;
        throw std::logic_error( ss.str() );
    }

    m_solver.add( formula );
}

void AstToZ3Visitor::visit( TypedFirstOrderFormula& node )
{
    m_astContext = std::make_shared< Context >( Context::tff() );

    RecursiveVisitor::visit( node );

    auto formula = m_stack.pop< z3::expr >();

    if( m_stack.size() != 0 )
    {
        std::stringstream ss;
        ss << "stack not empty after formula traversal, at TFF." << std::endl;
        ss << formula;
        throw std::logic_error( ss.str() );
    }

    m_solver.add( formula );
}

void AstToZ3Visitor::visit( TypedHigherOrderFormula& node )
{
    throw std::logic_error( "TypedHigherOrderFormula not implemented" );
}

void AstToZ3Visitor::visit( TPTPProcessInstructionFormula& node )
{
    throw std::logic_error( "TPTPProcessInstructionFormula not implemented" );
}

void AstToZ3Visitor::visit( ClauseNormalFormFormula& node )
{
    throw std::logic_error( "ClauseNormalFormFormula not implemented" );
}

void AstToZ3Visitor::visit( TheoryComputableFunctionalsFormula& node )
{
    throw std::logic_error( "TheoryComputableFunctionalsFormula not implemented" );
}

void AstToZ3Visitor::visit( FormulaData& node )
{
    throw std::logic_error( "FormulaData not implemented" );
}

void AstToZ3Visitor::visit( Role& node )
{
    throw std::logic_error( "Role not implemented" );
}

void AstToZ3Visitor::visit( UnaryLogic& node )
{
    node.logic()->accept( *this );
    auto logic = m_stack.pop< z3::expr >();

    switch( node.connective() )
    {
        case UnaryLogic::Connective::NEGATION:
        {
            logic = !logic;
            break;
        }
        case UnaryLogic::Connective::EQUALITY:
        {
            m_log.error( { node.sourceLocation() }, "UnaryLogic::Connective::Equality" );
            throw std::logic_error( "UnaryLogic::Connective::EQUALITY not implemented" );
            break;
        }
        case UnaryLogic::Connective::INDEFINITE_DESCRIPTION:
        {
            throw std::logic_error(
                "UnaryLogic::Connective::INDEFINITE_DESCRIPTION not implemented" );
            break;
        }
        case UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION:
        {
            throw std::logic_error(
                "UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION not implemented" );
            break;
        }
        case UnaryLogic::Connective::DEFINITE_DESCRIPTION:
        {
            throw std::logic_error(
                "UnaryLogic::Connective::DEFINITE_DESCRIPTION not implemented" );
            break;
        }
        case UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION:
        {
            throw std::logic_error(
                "UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION not implemented" );
            break;
        }
    }
    m_stack.push( logic );
}

void AstToZ3Visitor::visit( BinaryLogic& node )
{
    node.left()->accept( *this );
    auto left = m_stack.pop< z3::expr >();

    node.right()->accept( *this );
    auto right = m_stack.pop< z3::expr >();

    z3::expr logic( m_context );
    switch( node.connective() )
    {
        case BinaryLogic::Connective::DISJUNCTION:
        {
            logic = left || right;
            break;
        }
        case BinaryLogic::Connective::CONJUNCTION:
        {
            logic = left && right;
            break;
        }
        case BinaryLogic::Connective::EQUIVALENCE:
        {
            logic = left == right;
            break;
        }
        case BinaryLogic::Connective::NON_EQUIVALENCE:
        {
            logic = left != right;
            break;
        }
        case BinaryLogic::Connective::IMPLICATION:
        {
            logic = z3::implies( left, right );
            break;
        }
        case BinaryLogic::Connective::REVERSE_IMPLICATION:
        {
            logic = z3::implies( right, left );
            break;
        }
        case BinaryLogic::Connective::NEGATED_DISJUNCTION:
        {
            logic = !( left || right );
            break;
        }
        case BinaryLogic::Connective::NEGATED_CONJUNCTION:
        {
            logic = !( left && right );
            break;
        }
        case BinaryLogic::Connective::APPLY:
        {
            throw std::logic_error( "BinaryLogic::Connective::APPLY not implemented" );
            break;
        }
    }
    m_stack.push( logic );
}

void AstToZ3Visitor::visit( QuantifiedLogic& node )
{
    // throw std::logic_error( "QuantifiedLogic not implemented" );

    m_variables.pushScope();
    m_astContext->flags() |= Context::FormulaFlag::CREATE_BOUND;

    // TODO: @moosbruggerj refactor
    // z3::expr_vector bound( m_context );
    node.variables()->accept( *this );
    z3::expr_vector bound = m_stack.pop< z3::expr_vector >();
    /*
    for( auto var : *( node.variables()->elements() ) )
    {
        var->accept( *this );
        bound.push_back( m_stack.pop< z3::expr >() );
    }
    */

    m_astContext->flags().unset( Context::FormulaFlag::CREATE_BOUND );
    node.logic()->accept( *this );
    m_variables.popScope();
}

void AstToZ3Visitor::visit( InfixLogic& node )
{
    m_variables.constSort().push( m_variables.universalSort() );

    node.lhs()->accept( *this );
    auto left = m_stack.pop< z3::expr >();

    node.rhs()->accept( *this );
    auto right = m_stack.pop< z3::expr >();

    m_variables.constSort().pop();

    z3::expr logic( m_context );
    switch( node.connective() )
    {
        case InfixLogic::Connective::EQUALITY:
        {
            logic = left == right;
            break;
        }
        case InfixLogic::Connective::INEQUALITY:
        {
            logic = left != right;
            break;
        }
    }
    m_stack.push( logic );
}

void AstToZ3Visitor::visit( LogicTuple& node )
{
    z3::expr_vector vec( m_context );

    for( auto l : *node.tuples() )
    {
        l->accept( *this );
        auto logic = m_stack.pop< z3::expr >();
        vec.push_back( logic );
    }
    m_stack.push( vec );
}

void AstToZ3Visitor::visit( SequentLogic& node )
{
    node.left()->accept( *this );
    auto left = m_stack.pop< z3::expr_vector >();

    node.right()->accept( *this );
    auto right = m_stack.pop< z3::expr_vector >();

    auto logic = z3::implies( z3::mk_and( left ), z3::mk_or( right ) );
    m_stack.push( logic );
}

void AstToZ3Visitor::visit( VariableTerm& node )
{
    z3::expr var( m_context );
    z3::sort sort( m_context );
    std::string name = node.name()->innerName();
    if( m_astContext->flags() & libtptp::Context::FormulaFlag::CREATE_BOUND )
    {
        if( node.type() )
        {
            ( *node.type() )->accept( *this );
            sort = m_stack.pop< z3::sort >();
        }
        else
        {
            auto sort_val = m_variables.getSort( "$i" );
            if( sort_val )
            {
                sort = *sort_val;
            }
            else
            {
                throw std::logic_error( "$i type not found." );
            }
        }
        var = m_context.constant( name.c_str(), sort );
        auto insert_val = m_variables.pushBound( name, var );
        if( !insert_val.second )
        {
            std::stringstream errstr;
            errstr << "variable '" << name << "' declared twice. Ignoring second occurance.";
            m_log.warning( { node.sourceLocation() }, errstr.str() );
            var = insert_val.first->second;
        }
    }
    else
    {
        auto found = m_variables.get( name );
        if( found )
        {
            var = *found;
        }
        else
        {
            std::stringstream errstr;
            errstr << "variable '" << name << "' not declared. Did you mean it to be a constant?";
            m_log.error( { node.sourceLocation() }, errstr.str() );
        }
    }

    m_stack.push( var );
}

void AstToZ3Visitor::visit( ConditionalTerm& node )
{
    node.condition()->accept( *this );
    auto cond = m_stack.pop< z3::expr >();

    node.leftTerm()->accept( *this );
    auto then = m_stack.pop< z3::expr >();

    node.rightTerm()->accept( *this );
    auto el = m_stack.pop< z3::expr >();

    z3::expr var = z3::ite( cond, then, el );
    m_stack.push( var );
}

void AstToZ3Visitor::visit( DefinitionTerm& node )
{
    throw std::logic_error( "DefinitionTerm not implemented" );
}

void AstToZ3Visitor::visit( FunctorAtom& node )
{
    z3::expr var( m_context );
    z3::expr_vector args( m_context );
    for( auto& el : *node.arguments() )
    {
        el->element()->accept( *this );
        args.push_back( m_stack.pop< z3::expr >() );
    }

    switch( node.kind() )
    {
        case Atom::Kind::PLAIN:
        {
            throw std::logic_error( "Atom::Kind::PLAIN not implemented" );
            break;
        }
        case Atom::Kind::DEFINED:
        {
            std::string name = node.name()->innerName();
            if( name == "uminus" )
            {
                if( checkArgNum( node.sourceLocation(), "$uminus", 1, args.size() ) )
                {
                    var = -args[ 0 ];
                }
            }
            else if( name == "sum" )
            {
                if( checkArgNum( node.sourceLocation(), "$sum", 2, args.size() ) )
                {
                    // if(args[0].is_arith() && args[1].is_arith())
                    var = args[ 0 ] + args[ 1 ];
                }
            }
            else if( name == "difference" )
            {
                if( checkArgNum( node.sourceLocation(), "$difference", 2, args.size() ) )
                {
                    var = args[ 0 ] - args[ 1 ];
                }
            }
            else if( name == "product" )
            {
                if( checkArgNum( node.sourceLocation(), "$product", 2, args.size() ) )
                {
                    var = args[ 0 ] * args[ 1 ];
                }
            }
            else if( name == "quotient" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient", 2, args.size() ) )
                {
                    var = args[ 0 ] / args[ 1 ];
                }
            }
            else if( name == "quotient_e" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_e", 2, args.size() ) )
                {
                    var = args[ 0 ] / args[ 1 ];
                }
            }
            else if( name == "quotient_t" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_t", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "quotient_f" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_f", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "remainder_e" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_e", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "remainder_t" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_t", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "remainder_f" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_f", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "floor" )
            {
                if( checkArgNum( node.sourceLocation(), "$floor", 1, args.size() ) )
                {
                    var = toReal( toInt( args[ 0 ] ) );
                }
            }
            else if( name == "ceiling" )
            {
                if( checkArgNum( node.sourceLocation(), "$ceiling", 1, args.size() ) )
                {
                    var = ceil( args[ 0 ] );
                }
            }
            else if( name == "truncate" )
            {
                if( checkArgNum( node.sourceLocation(), "$truncate", 1, args.size() ) )
                {
                    var = truncate( args[ 0 ] );
                }
            }
            else if( name == "round" )
            {
                if( checkArgNum( node.sourceLocation(), "$round", 1, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "to_int" )
            {
                if( checkArgNum( node.sourceLocation(), "$to_int", 1, args.size() ) )
                {
                    var = toInt( args[ 0 ] );
                }
            }
            else if( name == "to_rat" )
            {
                if( checkArgNum( node.sourceLocation(), "$to_rat", 1, args.size() ) )
                {
                    var = toReal( args[ 0 ] );
                }
            }
            else if( name == "to_real" )
            {
                if( checkArgNum( node.sourceLocation(), "$to_real", 1, args.size() ) )
                {
                    var = toReal( args[ 0 ] );
                }
            }
            else
            {
                std::stringstream errstr;
                errstr << "functor '$" << name << "' not defined.";
                m_log.error( { node.sourceLocation() }, errstr.str() );
            }
            break;
        }
        case Atom::Kind::SYSTEM:
        {
            throw std::logic_error( "Atom::Kind::SYSTEM not implemented" );
            break;
        }
        case Atom::Kind::TYPE:
        {
            throw std::logic_error( "Atom::Kind::TYPE not implemented" );
            break;
        }
    }
    m_stack.push( var );
}

void AstToZ3Visitor::visit( ConstantAtom& node )
{
    z3::expr constant( m_context );
    switch( node.kind() )
    {
        case Atom::Kind::PLAIN:
        {
            std::string name = node.constant()->innerName();
            constant = m_context.constant( name.c_str(), m_variables.constSort().top() );
            break;
        }
        case Atom::Kind::DEFINED:
        {
            // TODO: @moosbruggerj fix me
            break;
        }
        case Atom::Kind::SYSTEM:
        {
            // TODO: @moosbruggerj fix me
            break;
        }
        case Atom::Kind::TYPE:
        {
            // TODO: @moosbruggerj fix me
            break;
        }
    }

    m_stack.push( constant );
}

void AstToZ3Visitor::visit( DefinedAtom& node )
{
    // TODO: @moosbruggerj remove if no further cange
    node.literal()->accept( *this );
    auto literal = m_stack.pop< z3::expr >();
    m_stack.push( literal );
}

void AstToZ3Visitor::visit( DefinitionAtom& node )
{
    throw std::logic_error( "DefinitionAtom not implemented" );
}

void AstToZ3Visitor::visit( ConnectiveAtom& node )
{
    throw std::logic_error( "ConnectiveAtom not implemented" );
}

void AstToZ3Visitor::visit( AtomType& node )
{
}

void AstToZ3Visitor::visit( BinaryType& node )
{
}

void AstToZ3Visitor::visit( TypedAtom& node )
{
}

void AstToZ3Visitor::visit( TupleType& node )
{
}

void AstToZ3Visitor::visit( QuantifiedType& node )
{
}

void AstToZ3Visitor::visit( SubType& node )
{
}

void AstToZ3Visitor::visit( Identifier& node )
{
    throw std::logic_error( "internal error: Identifier::accept is not supposed to be called." );
}

void AstToZ3Visitor::visit( IntegerLiteral& node )
{
    auto val = static_cast< const libstdhl::Type::Integer& >( node.value() );
    auto z3_val = m_context.int_val( val.value() );
    m_stack.push( z3_val );
}

void AstToZ3Visitor::visit( RationalLiteral& node )
{
    auto val = static_cast< const libstdhl::Type::Rational& >( node.value() );
    auto z3_val = m_context.real_val( val.numerator().value(), val.denominator().value() );
    m_stack.push( z3_val );
}

void AstToZ3Visitor::visit( RealLiteral& node )
{
    auto z3_val = m_context.real_val( node.value().to_string().c_str() );
    m_stack.push( z3_val );
}

void AstToZ3Visitor::visit( DistinctObjectLiteral& node )
{
    auto val = static_cast< const libstdhl::Type::String& >( node.value() );
    auto str = val.toString();
    auto z3_val = m_context.string_val( str.substr( 1, str.size() - 2 ) );  // remove quotes
    m_stack.push( z3_val );
}

void AstToZ3Visitor::visit( ListLiteral& node )
{
    // mustn't be called from general list or name list in include
    // TODO: @moosbruggerj refactor
    z3::expr_vector vec( m_context );
    for( auto el : *node.elements() )
    {
        el->element()->accept( *this );
        vec.push_back( m_stack.pop< z3::expr >() );
    }

    m_stack.push( vec );
}

void AstToZ3Visitor::visit( Token& node )
{
}

void AstToZ3Visitor::visit( IncludeDefinition& node )
{
    m_log.error( { node.sourceLocation() }, "include definition invalid in execution pass" );
    throw std::logic_error( "invalid in execution pass." );
}

void AstToZ3Visitor::visit( FormulaDefinition& node )
{
    // TODO: @moosbruggerj fix me
    node.formula()->accept( *this );
}

void AstToZ3Visitor::visit( GeneralData& node )
{
}

void AstToZ3Visitor::visit( GeneralList& node )
{
}

void AstToZ3Visitor::visit( GeneralAggregator& node )
{
}

void AstToZ3Visitor::visit( GeneralFunction& node )
{
}

void AstToZ3Visitor::visit( Annotation& node )
{
}

z3::solver& AstToZ3Visitor::solver( void )
{
    return m_solver;
}

bool AstToZ3Visitor::checkArgNum(
    const SourceLocation& loc, const std::string& name, size_t expected, size_t actual )
{
    if( expected != actual )
    {
        std::stringstream errstr;
        errstr << "functor '" << name << "' expects " << expected << " arguments, " << actual
               << " provided.";
        m_log.error( { loc }, errstr.str() );
        return false;
    }
    return true;
}

void AstToZ3Pass::usage( libpass::PassUsage& pu )
{
    pu.require< SourceToAstPass >();
}

u1 AstToZ3Pass::run( libpass::PassResult& pr )
{
    libtptp::Logger log( &id, stream() );

    const auto& data = pr.output< SourceToAstPass >();
    const auto& specification = data->specification();

    AstToZ3Visitor visitor( log );

    try
    {
        visitor.visit( *specification );
    }
    catch( std::exception& e )
    {
        log.error( e.what() );
    }

    auto& solver = visitor.solver();
    auto result = solver.check();

    switch( result )
    {
        case z3::check_result::sat:
            std::cout << "sat\n";
            std::cout << solver.get_model() << std::endl;
            break;
        case z3::check_result::unsat:
            std::cout << "unsat\n";
            break;
        case z3::check_result::unknown:
            std::cout << "unknown\n";
            break;
    }

    if( log.errors() > 0 )
    {
        return false;
    }
    return true;
}

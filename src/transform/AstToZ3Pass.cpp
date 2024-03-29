//
//  Copyright (C) 2017-2024 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//  <https://github.com/casm-lang/libtptp/graphs/contributors>
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

#include <libtptp/analyze/ConsistencyCheckPass>

#include <libtptp/Logger>

#include <libpass/PassRegistry>

#include <libstdhl/File>
#include <libstdhl/Stack>

#include <z3++.h>

#include <map>
#include <sstream>

using namespace libtptp;

char AstToZ3Pass::id = 0;

static libpass::PassRegistration< AstToZ3Pass > PASS(
    "AstToZ3Pass", "transforms the specification into a z3 model", "ast-to-z3", 0 );

namespace libtptp
{
    class VariableManager
    {
      private:
        z3::context& m_context;  // is only valid while AstToZ3Visitor instance is valid
        std::vector< std::map< std::string, z3::expr > > m_boundVars;
        std::map< std::string, z3::expr > m_unboundVars;

        std::map< std::string, z3::sort > m_sorts;
        std::map< std::string, unsigned int > m_polymorphicSorts;
        std::map< std::string, z3::func_decl > m_sortConstructors;
        // TODO: @moosbruggerj fix type for higer order formulae, partial variable binding enable
        std::map< std::string, z3::func_decl > m_functions;
        z3::sort m_universal;
        libstdhl::Stack< z3::sort > m_constSort;
        libstdhl::Stack< std::string > m_symbolNames;

      public:
        VariableManager( z3::context& context );

        void pushScope( void );
        void popScope( void );

        const libstdhl::Optional< const z3::expr > get( const std::string& name );
        std::pair< typename decltype( m_unboundVars )::iterator, bool > pushUnbound(
            const std::string& name, const z3::expr& var );
        std::pair< typename decltype( m_boundVars )::value_type::iterator, bool > pushBound(
            const std::string& name, const z3::expr& var );

        const libstdhl::Optional< const z3::sort > getSort( const std::string& name );
        std::pair< typename decltype( m_sorts )::iterator, bool > pushSort(
            const std::string& name, const z3::sort& sort );

        const libstdhl::Optional< const z3::sort > getSort(
            const std::string& name, z3::sort_vector args );
        std::pair< typename decltype( m_polymorphicSorts )::iterator, bool > pushSort(
            const std::string& name, const unsigned int arity );

        libstdhl::Stack< z3::sort >& constSort( void );
        const z3::sort& universalSort( void );

        const libstdhl::Optional< const z3::func_decl > getSortConstructor(
            const std::string& name );
        std::pair< typename decltype( m_sortConstructors )::iterator, bool > pushSortConstructor(
            const std::string& name, const z3::func_decl& function );

        const libstdhl::Optional< const z3::func_decl > getFunction( const std::string& name );
        std::pair< typename decltype( m_functions )::iterator, bool > pushFunction(
            const std::string& name, const z3::func_decl& function );

        std::string getTupleName( const z3::sort_vector& sorts );

        libstdhl::Stack< std::string >& symbolNames( void );
        std::string getFunctionName( const z3::sort_vector& domain, const z3::sort& range );

      private:
        std::string getParametricSortName( const std::string name, const z3::sort_vector args );
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
                SORT_VECTOR,
                FUNC_DECL,
                TTYPE,
                TTYPE_VECTOR,
            } tag;

          private:
            union
            {
                z3::expr* expr;
                z3::expr_vector* expr_vec;
                z3::sort* sort;
                z3::sort_vector* sort_vec;
                z3::func_decl* func_decl;
                int vector_size;
                void* none;
            };

          public:
            // explicit conversions for template access using static cast
            explicit Z3_expr( const z3::expr&& expr );
            explicit Z3_expr( const z3::expr_vector&& expr );
            explicit Z3_expr( const z3::sort&& expr );
            explicit Z3_expr( const z3::sort_vector&& expr );
            explicit Z3_expr( const z3::func_decl&& expr );
            explicit Z3_expr( Tag tag );
            explicit Z3_expr( int size );  // constructs TTYPE_VECTOR

            void free() const;

            explicit operator z3::expr( void ) const;
            explicit operator z3::expr_vector( void ) const;
            explicit operator z3::sort( void ) const;
            explicit operator z3::sort_vector( void ) const;
            explicit operator z3::func_decl( void ) const;
            explicit operator int( void ) const;

            void check_none( void ) const;
            std::string description( void ) const;
            static std::string description( Tag tag );
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
                auto value = Stack::pop();
                return static_cast< T >( value );
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

            std::string topDescription( void )
            {
                return top().description();
            }

            void discardTop( void )
            {
                const auto value = Stack::pop();
                value.free();
            }
        };

        std::shared_ptr< Context > m_astContext;
        z3::context m_context;
        z3::solver m_solver;
        Z3Stack m_stack;
        libtptp::Logger m_log;
        VariableManager m_variables;
        bool m_hasConjecture = false;

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
        void visit( TypeAtom& node ) override;
        void visit( TupleAtom& node ) override;

        void visit( ApplyType& node ) override;
        void visit( NamedType& node ) override;
        void visit( FunctorType& node ) override;
        void visit( BinaryType& node ) override;
        void visit( TupleType& node ) override;
        void visit( QuantifiedType& node ) override;
        void visit( SubType& node ) override;
        void visit( RelationType& node ) override;
        void visit( VariableType& node ) override;

        void visit( Identifier& node ) override;

        void visit( IntegerLiteral& node ) override;
        void visit( RationalLiteral& node ) override;
        void visit( RealLiteral& node ) override;
        void visit( DistinctObjectLiteral& node ) override;
        void visit( ListLiteral& node ) override;

        void visit( IncludeDefinition& node ) override;
        void visit( FormulaDefinition& node ) override;

        void visit( GeneralData& node ) override;
        void visit( GeneralList& node ) override;
        void visit( GeneralAggregator& node ) override;
        void visit( GeneralFunction& node ) override;
        void visit( Annotation& node ) override;

        z3::solver& solver( void );
        bool hasConjecture( void );

      private:
        bool checkArgNum(
            const SourceLocation& loc, const std::string& name, size_t expected, size_t actual );
    };
}

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
: m_context( context )
, m_universal( context.uninterpreted_sort( "$i" ) )
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
    m_constSort.push( s_bool );
}

void VariableManager::pushScope( void )
{
    m_boundVars.emplace_back();
}

void VariableManager::popScope( void )
{
    m_boundVars.pop_back();
}

// const z3::expr& would be better, but c++ doesn't allow it
const libstdhl::Optional< const z3::expr > VariableManager::get( const std::string& name )
{
    for( auto it = m_boundVars.rbegin(); it != m_boundVars.rend(); ++it )
    {
        if( it->find( name ) != it->end() )
        {
            return it->at( name );
        }
    }

    if( m_unboundVars.find( name ) != m_unboundVars.end() )
    {
        return m_unboundVars.at( name );
    }

    return libstdhl::Optional< const z3::expr >();
}

std::pair< typename decltype( VariableManager::m_unboundVars )::iterator, bool >
VariableManager::pushUnbound( const std::string& name, const z3::expr& var )
{
    return m_unboundVars.emplace( name, var );
}

std::pair< typename decltype( VariableManager::m_boundVars )::value_type::iterator, bool >
VariableManager::pushBound( const std::string& name, const z3::expr& var )
{
    return m_boundVars.rbegin()->emplace( name, var );
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

const libstdhl::Optional< const z3::sort > VariableManager::getSort(
    const std::string& name, z3::sort_vector args )
{
    if( m_polymorphicSorts.find( name ) == m_polymorphicSorts.end() ||
        m_polymorphicSorts.at( name ) != args.size() )
    {
        return libstdhl::Optional< const z3::sort >();
    }
    std::string sortName = getParametricSortName( name, args );

    if( m_sorts.find( sortName ) != m_sorts.end() )
    {
        return m_sorts.at( sortName );
    }
    z3::sort sort = m_context.uninterpreted_sort( sortName.c_str() );
    m_sorts.emplace( sortName, sort );
    return sort;
}

std::pair< typename decltype( VariableManager::m_polymorphicSorts )::iterator, bool >
VariableManager::pushSort( const std::string& name, const unsigned int arity )
{
    return m_polymorphicSorts.emplace( name, arity );
}

libstdhl::Stack< z3::sort >& VariableManager::constSort( void )
{
    return m_constSort;
}

const z3::sort& VariableManager::universalSort( void )
{
    return m_universal;
}

const libstdhl::Optional< const z3::func_decl > VariableManager::getSortConstructor(
    const std::string& name )
{
    if( m_sortConstructors.find( name ) != m_sortConstructors.end() )
    {
        return m_sortConstructors.at( name );
    }

    return libstdhl::Optional< const z3::func_decl >();
}

std::pair< typename decltype( VariableManager::m_sortConstructors )::iterator, bool >
VariableManager::pushSortConstructor( const std::string& name, const z3::func_decl& function )
{
    return m_sortConstructors.emplace( name, function );
}

const libstdhl::Optional< const z3::func_decl > VariableManager::getFunction(
    const std::string& name )
{
    if( m_functions.find( name ) != m_functions.end() )
    {
        return m_functions.at( name );
    }

    return libstdhl::Optional< const z3::func_decl >();
}

std::pair< typename decltype( VariableManager::m_functions )::iterator, bool >
VariableManager::pushFunction( const std::string& name, const z3::func_decl& function )
{
    return m_functions.emplace( name, function );
}

std::string VariableManager::getTupleName( const z3::sort_vector& sorts )
{
    std::stringstream name;
    name << "__tuple(";
    for( auto s : sorts )
    {
        name << "/" << s.name().str();
    }
    name << ")";
    return name.str();
}

libstdhl::Stack< std::string >& VariableManager::symbolNames( void )
{
    return m_symbolNames;
}

std::string VariableManager::getFunctionName( const z3::sort_vector& domain, const z3::sort& range )
{
    std::stringstream basename;
    basename << "__function(";
    for( auto s : domain )
    {
        basename << "/" << s.name().str();
    }
    basename << ">" << range.name().str() << ")";
    int count = 1;

    std::string name = basename.str();
    while( m_functions.find( name ) != m_functions.end() )
    {
        std::stringstream ss;
        ss << count;
        ++count;
        name = basename.str() + ss.str();
    }
    return name;
}

std::string VariableManager::getParametricSortName(
    const std::string name, const z3::sort_vector args )
{
    std::stringstream basename;
    basename << "__par/" << name << "(";
    for( auto s : args )
    {
        basename << "/" << s.name().str();
    }
    basename << ")";
    return basename.str();
}

AstToZ3Visitor::Z3_expr::Z3_expr( const z3::expr&& expr )
: tag( Tag::EXPR )
, expr( new z3::expr( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( const z3::expr_vector&& expr )
: tag( Tag::EXPR_VECTOR )
, expr_vec( new z3::expr_vector( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( const z3::sort&& expr )
: tag( Tag::SORT )
, sort( new z3::sort( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( const z3::sort_vector&& expr )
: tag( Tag::SORT_VECTOR )
, sort_vec( new z3::sort_vector( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( const z3::func_decl&& expr )
: tag( Tag::FUNC_DECL )
, func_decl( new z3::func_decl( expr ) )
{
}

AstToZ3Visitor::Z3_expr::Z3_expr( Z3_expr::Tag tag )
: tag( tag )
, none( nullptr )
{
    if( tag != Tag::TTYPE )
    {
        throw std::domain_error( "constructor is only for ttype tags" );
    }
}

AstToZ3Visitor::Z3_expr::Z3_expr( int size )
: tag( Tag::TTYPE_VECTOR )
, vector_size( size )
{
}

void AstToZ3Visitor::Z3_expr::free() const
{
    switch( tag )
    {
        case Tag::EXPR:
        {
            delete expr;
            break;
        }
        case Tag::EXPR_VECTOR:
        {
            delete expr_vec;
            break;
        }
        case Tag::SORT:
        {
            delete sort;
            break;
        }
        case Tag::SORT_VECTOR:
        {
            delete sort_vec;
            break;
        }
        case Tag::FUNC_DECL:
        {
            delete func_decl;
            break;
        }
        case Tag::TTYPE:
            [[fallthrough]];
        case Tag::TTYPE_VECTOR:
        {
            break;
        }
    }
}

void AstToZ3Visitor::Z3_expr::check_none( void ) const
{
    if( tag != Tag::TTYPE )
    {
        throw std::domain_error( "union is not of none type" );
    }
}

std::string AstToZ3Visitor::Z3_expr::description( void ) const
{
    return Z3_expr::description( tag );
}

std::string AstToZ3Visitor::Z3_expr::description( Tag tag )
{
    switch( tag )
    {
        case Tag::EXPR:
        {
            return "expression";
        }
        case Tag::EXPR_VECTOR:
        {
            return "expression vector";
        }
        case Tag::SORT:
        {
            return "sort";
        }
        case Tag::SORT_VECTOR:
        {
            return "sort vector";
        }
        case Tag::FUNC_DECL:
        {
            return "function declaration";
        }
        case Tag::TTYPE:
        {
            return "ttype";
        }
        case Tag::TTYPE_VECTOR:
        {
            return "ttype vector";
        }
    }
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

AstToZ3Visitor::Z3_expr::operator z3::sort_vector() const
{
    if( tag != Tag::SORT_VECTOR )
    {
        throw std::domain_error( "union is not of stackType sort_vector" );
    }
    auto r = *sort_vec;
    delete sort_vec;
    return r;
}

AstToZ3Visitor::Z3_expr::operator z3::func_decl() const
{
    if( tag != Tag::FUNC_DECL )
    {
        throw std::domain_error( "union is not of stackType func_decl" );
    }
    auto r = *func_decl;
    delete func_decl;
    return r;
}

AstToZ3Visitor::Z3_expr::operator int() const
{
    if( tag != Tag::TTYPE_VECTOR )
    {
        throw std::domain_error( "union is not of stackType ttype_vector" );
    }
    return vector_size;
}

template <>
void AstToZ3Visitor::Z3Stack::pop< void >( void )
{
    const auto value = Stack::pop();
    value.check_none();
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
    m_astContext->flags() |= Context::FormulaFlag::FOF;

    RecursiveVisitor::visit( node );

    if( m_stack.topType() == Z3_expr::Tag::EXPR )
    {
        auto formula = m_stack.pop< z3::expr >();

        if( formula.is_bool() )
        {
            if( m_astContext->flags() & Context::FormulaFlag::NEEDS_NEGATION )
            {
                formula = !formula;
            }
            m_solver.add( formula );
        }
    }
    else
    {
        m_stack.discardTop();
    }

    if( m_stack.size() != 0 )
    {
        std::stringstream ss;
        ss << "stack not empty after formula traversal, at FOF." << std::endl;
        ss << m_stack.topDescription();
        throw std::logic_error( ss.str() );
    }
}

void AstToZ3Visitor::visit( TypedFirstOrderFormula& node )
{
    m_astContext->flags() |= Context::FormulaFlag::FOF;

    RecursiveVisitor::visit( node );

    if( m_stack.topType() == Z3_expr::Tag::EXPR )
    {
        auto formula = m_stack.pop< z3::expr >();

        if( formula.is_bool() )
        {
            if( m_astContext->flags() & Context::FormulaFlag::NEEDS_NEGATION )
            {
                formula = !formula;
            }
            m_solver.add( formula );
        }
    }
    else
    {
        m_stack.discardTop();
    }

    if( m_stack.size() != 0 )
    {
        std::stringstream ss;
        ss << "stack not empty after formula traversal, at TFF." << std::endl;
        ss << m_stack.topDescription();
        m_log.error( { node.sourceLocation() }, ss.str() );
        throw std::logic_error( ss.str() );
    }
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
    switch( node.kind() )
    {
        case Role::Kind::CONJECTURE:
        {
            m_astContext->flags() |= Context::FormulaFlag::NEEDS_NEGATION;
            m_hasConjecture = true;
            break;
        }
        case Role::Kind::NEGATED_CONJECTURE:
        {
            m_hasConjecture = true;
            break;
        }
        default:
        {
            // no action needed
            break;
        }
    }
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
    m_variables.pushScope();
    m_astContext->flags() |= Context::FormulaFlag::CREATE_BOUND;

    z3::expr_vector bound( m_context );
    for( auto& v : *node.variables() )
    {
        v->element()->accept( *this );
        bound.push_back( m_stack.pop< z3::expr >() );
    }

    m_astContext->flags().unset( Context::FormulaFlag::CREATE_BOUND );

    node.logic()->accept( *this );
    z3::expr logic = m_stack.pop< z3::expr >();
    z3::expr result( m_context );
    switch( node.quantifier() )
    {
        case QuantifiedLogic::Quantifier::UNIVERSAL:
        {
            result = z3::forall( bound, logic );
            break;
        }
        case QuantifiedLogic::Quantifier::EXISTENTIAL:
        {
            result = z3::exists( bound, logic );
            break;
        }
        default:
            // TODO: @moosbruggerj fix me
            break;
    }
    m_variables.popScope();
    m_stack.push( result );
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
    // TODO: @moosbruggerj if quantifier over $tType, generate exhaustive formula with each type
    // instantation
    z3::expr var( m_context );
    z3::sort sort( m_context );
    std::string name = node.name()->normalizedName();
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
        case Atom::Kind::SYSTEM:
        {
            m_log.error( { node.sourceLocation() }, "no system functors defined." );
            [[fallthrough]];
        }
        case Atom::Kind::PLAIN:
        {
            std::string name = node.name()->normalizedName();
            auto function = m_variables.getFunction( name );
            if( function )
            {
                var = ( *function )( args );
            }
            else
            {
                // if not found generate ($i * ...) > $i/$o function as per tptp definition, instead
                // of argument types
                std::stringstream errstr;
                errstr << "function '" << name << "' not found. Assuming '";
                if( args.size() == 0 )
                {
                    errstr << "()";
                }
                else if( args.size() != 1 )
                {
                    errstr << "( $i";
                    for( size_t i = 1; i < args.size(); ++i )
                    {
                        errstr << " * $i";
                    }
                    errstr << " )";
                }
                else
                {
                    errstr << "$i";
                }
                errstr << " > " << m_variables.constSort().top().name() << "'"
                       << ".";
                m_log.warning( { node.sourceLocation() }, errstr.str() );
                z3::sort_vector domain( m_context );
                for( size_t i = 0; i < args.size(); ++i )
                {
                    domain.push_back( m_variables.universalSort() );
                }
                z3::func_decl func =
                    m_context.function( name.c_str(), domain, m_variables.constSort().top() );
                m_variables.pushFunction( name, func );
                var = func( args );
            }
            break;
        }
        case Atom::Kind::DEFINED:
        {
            std::string name = node.name()->normalizedName();
            if( name == "$uminus" )
            {
                if( checkArgNum( node.sourceLocation(), "$uminus", 1, args.size() ) )
                {
                    var = -args[ 0 ];
                }
            }
            else if( name == "$sum" )
            {
                if( checkArgNum( node.sourceLocation(), "$sum", 2, args.size() ) )
                {
                    // if(args[0].is_arith() && args[1].is_arith())
                    var = args[ 0 ] + args[ 1 ];
                }
            }
            else if( name == "$difference" )
            {
                if( checkArgNum( node.sourceLocation(), "$difference", 2, args.size() ) )
                {
                    var = args[ 0 ] - args[ 1 ];
                }
            }
            else if( name == "$product" )
            {
                if( checkArgNum( node.sourceLocation(), "$product", 2, args.size() ) )
                {
                    var = args[ 0 ] * args[ 1 ];
                }
            }
            else if( name == "$quotient" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient", 2, args.size() ) )
                {
                    var = args[ 0 ] / args[ 1 ];
                }
            }
            else if( name == "$quotient_e" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_e", 2, args.size() ) )
                {
                    var = args[ 0 ] / args[ 1 ];
                }
            }
            else if( name == "$quotient_t" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_t", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$quotient_f" )
            {
                if( checkArgNum( node.sourceLocation(), "$quotient_f", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$remainder_e" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_e", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$remainder_t" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_t", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$remainder_f" )
            {
                if( checkArgNum( node.sourceLocation(), "$remainder_f", 2, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$floor" )
            {
                if( checkArgNum( node.sourceLocation(), "$floor", 1, args.size() ) )
                {
                    var = toReal( toInt( args[ 0 ] ) );
                }
            }
            else if( name == "$ceiling" )
            {
                if( checkArgNum( node.sourceLocation(), "$ceiling", 1, args.size() ) )
                {
                    var = ceil( args[ 0 ] );
                }
            }
            else if( name == "$truncate" )
            {
                if( checkArgNum( node.sourceLocation(), "$truncate", 1, args.size() ) )
                {
                    var = truncate( args[ 0 ] );
                }
            }
            else if( name == "$round" )
            {
                if( checkArgNum( node.sourceLocation(), "$round", 1, args.size() ) )
                {
                    throw std::logic_error( "not implemented" );
                }
            }
            else if( name == "$to_int" )
            {
                if( checkArgNum( node.sourceLocation(), "$to_int", 1, args.size() ) )
                {
                    var = toInt( args[ 0 ] );
                }
            }
            else if( name == "$to_rat" )
            {
                if( checkArgNum( node.sourceLocation(), "$to_rat", 1, args.size() ) )
                {
                    var = toReal( args[ 0 ] );
                }
            }
            else if( name == "$to_real" )
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
            // no action necessary, normal constant generation
            break;
        }
        case Atom::Kind::DEFINED:
        {
            m_log.error(
                { node.sourceLocation() },
                "no defined constants defined. Generating normal constant." );
            break;
        }
        case Atom::Kind::SYSTEM:
        {
            m_log.error(
                { node.sourceLocation() },
                "no system constants defined. Generating normal constant." );
            break;
        }
    }

    std::string name = node.constant()->normalizedName();
    auto variable = m_variables.get( name );
    if( variable )
    {
        constant = *variable;
    }
    else
    {
        constant = m_context.constant( name.c_str(), m_variables.constSort().top() );
        m_variables.pushUnbound( name, constant );
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

void AstToZ3Visitor::visit( TypeAtom& node )
{
    std::string name = node.atom()->normalizedName();
    auto size = m_variables.symbolNames().size();
    m_variables.symbolNames().push( name );
    node.type()->accept( *this );
    if( m_variables.symbolNames().size() > size )
    {
        // TODO: @moosbruggerj maybe pop (size - symbolNames.size()) times
        m_variables.symbolNames().pop();
    }
    switch( m_stack.topType() )
    {
        case Z3_expr::Tag::TTYPE:
        {
            m_stack.pop< void >();
            z3::sort sort = m_context.uninterpreted_sort( name.c_str() );
            m_variables.pushSort( name, sort );
            m_stack.push( sort );
            break;
        }
        case Z3_expr::Tag::SORT:
        {
            const auto sort = m_stack.pop< z3::sort >();
            z3::expr expr = m_context.constant( name.c_str(), sort );
            m_variables.pushUnbound( name, expr );
            m_stack.push( expr );
            break;
        }
        case Z3_expr::Tag::FUNC_DECL:
        {
            // everyting handled by BinaryType, because name is known there
            break;
        }
        case Z3_expr::Tag::TTYPE_VECTOR:
        {
            // everyting handled by BinaryType, because name is known there
            break;
        }
        default:
        {
            // TODO: @moosbruggerj fix for thf
            // missing expr, expr_vector, sort_vector
            std::stringstream err;
            err << m_stack.topDescription() << " not supported as type in type atom";
            m_log.error( { node.sourceLocation() }, err.str() );
            break;
        }
    }
}

void AstToZ3Visitor::visit( TupleAtom& node )
{
    z3::expr_vector atoms( m_context );
    z3::sort_vector atom_sorts( m_context );
    for( auto& a : *node.atoms() )
    {
        a->element()->accept( *this );
        if( m_astContext->flags() & Context::FormulaFlag::DISCARD_TUPLE )
        {
            m_stack.discardTop();
        }
        else
        {
            auto expr = m_stack.pop< z3::expr >();
            atoms.push_back( expr );
            atom_sorts.push_back( expr.get_sort() );
        }
    }

    if( m_astContext->flags() & Context::FormulaFlag::DISCARD_TUPLE )
    {
        z3::expr tuple( m_context );
        std::string tupleName = m_variables.getTupleName( atom_sorts );
        auto tupleConstructor = m_variables.getSortConstructor( tupleName );
        if( tupleConstructor )
        {
            tuple = ( *tupleConstructor )( atoms );
        }
        else
        {
            std::vector< const char* > names;
            std::vector< z3::sort > sorts;
            z3::func_decl_vector func_decls( m_context );
            for( auto s : atom_sorts )
            {
                sorts.push_back( s );
                names.push_back( s.name().str().c_str() );
            }
            auto constructor = m_context.tuple_sort(
                tupleName.c_str(), atom_sorts.size(), names.data(), sorts.data(), func_decls );
            m_variables.pushSortConstructor( tupleName, constructor );
            tuple = constructor( atoms );
        }
        m_stack.push( tuple );
    }
}

void AstToZ3Visitor::visit( ApplyType& node )
{
    throw std::logic_error( "ApplyType not implemented" );
}

void AstToZ3Visitor::visit( NamedType& node )
{
    std::string name = node.name()->normalizedName();
    if( name == "$tType" )
    {
        m_stack.push( Z3_expr::Tag::TTYPE );
    }
    else
    {
        auto sort = m_variables.getSort( name );
        if( sort )
        {
            m_stack.push( *sort );
        }
        else
        {
            std::stringstream err;
            err << "type '" << name << "' not found.";
            m_log.error( { node.sourceLocation() }, err.str() );
        }
    }
}

void AstToZ3Visitor::visit( FunctorType& node )
{
    // TODO: @moosbruggerj: catch functor types with $tType as argument, semantically impossible, as
    // a functor type can only defined with 'type($tType)', therefore $tType is not allowed in
    // instantiation, however the BNF grammer would allow it
    std::string name = node.name()->normalizedName();
    z3::sort_vector args( m_context );
    for( auto arg : *node.arguments() )
    {
        arg->element()->accept( *this );
        args.push_back( m_stack.pop< z3::sort >() );
    }
    auto sort = m_variables.getSort( name, args );
    if( !sort )
    {
        std::stringstream err;
        err << "parametric sort '" << node.name()->name() << "' not found.";
        m_log.error( { node.sourceLocation() }, err.str() );
        std::stringstream genName;
        genName << "__not_found(" << name << ")";
        m_stack.push( m_context.uninterpreted_sort( genName.str().c_str() ) );
    }
    else
    {
        m_stack.push( *sort );
    }
}

void AstToZ3Visitor::visit( BinaryType& node )
{
    switch( node.kind() )
    {
        case BinaryType::Kind::MAPPING:
        {
            std::string name;
            bool definedName = false;
            if( !m_variables.symbolNames().empty() )
            {
                name = m_variables.symbolNames().pop();
                definedName = true;
            }

            // TODO: @moosbruggerj fix for higher order formulae
            z3::func_decl result( m_context );
            // TODO: @moosbruggerj fix ttype for parameterized types
            node.right()->accept( *this );
            switch( m_stack.topType() )
            {
                case Z3_expr::Tag::SORT:
                {
                    auto right = m_stack.pop< z3::sort >();

                    node.left()->accept( *this );
                    switch( m_stack.topType() )
                    {
                        case Z3_expr::Tag::SORT:
                        {
                            // TODO: @moosbruggerj fix name
                            auto sort = m_stack.pop< z3::sort >();
                            if( !definedName )
                            {
                                z3::sort_vector domain( m_context );
                                domain.push_back( sort );
                                name = m_variables.getFunctionName( domain, right );
                            }
                            result = z3::function( name.c_str(), sort, right );
                            m_variables.pushFunction( name, result );
                            break;
                        }
                        case Z3_expr::Tag::SORT_VECTOR:
                        {
                            auto domain = m_stack.pop< z3::sort_vector >();
                            if( !definedName )
                            {
                                name = m_variables.getFunctionName( domain, right );
                            }
                            result = z3::function( name, domain, right );
                            m_variables.pushFunction( name, result );
                            break;
                        }
                        default:  // default arguments
                        {
                            std::stringstream err;
                            err << m_stack.topDescription() << " not supported as parameter type";
                            m_log.error( { node.sourceLocation() }, err.str() );
                            break;
                        }
                    }
                    m_stack.push( result );
                    break;
                }
                case Z3_expr::Tag::TTYPE:
                {
                    m_stack.discardTop();

                    node.left()->accept( *this );
                    switch( m_stack.topType() )
                    {
                        case Z3_expr::Tag::TTYPE:
                        {
                            // TODO: @moosbruggerj fix name
                            m_stack.discardTop();
                            if( !definedName )
                            {
                                m_log.error(
                                    { node.sourceLocation() },
                                    "polymorphic sort has no name. Higher order polymorphic types "
                                    "not supported." );
                            }
                            m_variables.pushSort( name, 1 );
                            break;
                        }
                        case Z3_expr::Tag::TTYPE_VECTOR:
                        {
                            auto args = m_stack.pop< int >();
                            if( !definedName )
                            {
                                m_log.error(
                                    { node.sourceLocation() },
                                    "polymorphic sort has no name. Higher order polymorphic types "
                                    "not supported." );
                            }
                            m_variables.pushSort( name, args );
                            break;
                        }
                        default:  // default arguments
                        {
                            std::stringstream err;
                            err << m_stack.topDescription() << " not supported as parameter type";
                            m_log.error( { node.sourceLocation() }, err.str() );
                            break;
                        }
                    }
                    m_stack.push( 0 );
                    break;
                }
                default:  // default right argument
                {
                    std::stringstream err;
                    err << m_stack.topDescription()
                        << " not supported as result type in mapping BinaryType.";
                    m_log.error( { node.sourceLocation() }, err.str() );
                    break;
                }
            }
            break;
        }
        case BinaryType::Kind::UNION:
        {
            // TODO: @moosbruggerj fix me
            break;
        }
    }
}

void AstToZ3Visitor::visit( TupleType& node )
{
    auto stackSize = m_stack.size();
    z3::sort_vector ret( m_context );
    for( auto& t : *node.tuples() )
    {
        t->element()->accept( *this );
        if( m_stack.size() != stackSize )
        {
            switch( m_stack.topType() )
            {
                case Z3_expr::Tag::SORT:
                {
                    ret.push_back( m_stack.pop< z3::sort >() );
                    break;
                }
                case Z3_expr::Tag::SORT_VECTOR:
                {
                    const auto vec = m_stack.pop< z3::sort_vector >();
                    for( auto e : vec )
                    {
                        ret.push_back( e );
                    }
                    break;
                }
                default:
                {
                    // TODO: @moosbruggerj fix for thf
                    // missing expr, expr_vector, ttype, func_decl
                    std::stringstream err;
                    err << m_stack.topDescription() << " not supported as type in tuple";
                    m_log.error( { node.sourceLocation() }, err.str() );
                    break;
                }
            }
        }
    }
    std::vector< const char* > names;
    std::vector< z3::sort > sorts;
    const auto name = m_variables.getTupleName( ret );
    z3::func_decl tuple( m_context );
    const auto tupleWrap = m_variables.getSortConstructor( name );
    if( tupleWrap )
    {
        tuple = *tupleWrap;
    }
    else
    {
        for( auto s : ret )
        {
            sorts.push_back( s );
            names.push_back( s.name().str().c_str() );
        }
        z3::func_decl_vector funcs( m_context );
        tuple = m_context.tuple_sort( name.c_str(), ret.size(), names.data(), sorts.data(), funcs );
        m_variables.pushSortConstructor( name, tuple );
    }
    m_stack.push( tuple.range() );
}

void AstToZ3Visitor::visit( QuantifiedType& node )
{
    throw std::logic_error( "QuantifiedType not implemented" );
}

void AstToZ3Visitor::visit( SubType& node )
{
    throw std::logic_error( "SubType not implemented" );
}

void AstToZ3Visitor::visit( RelationType& node )
{
    z3::sort_vector sorts( m_context );
    unsigned int args = 0;
    bool first = true;
    Z3_expr::Tag type = Z3_expr::Tag::TTYPE_VECTOR;
    for( auto& v : *node.elements() )
    {
        v->element()->accept( *this );
        if( first )
        {
            first = false;
            type = m_stack.topType();
        }
        if( type != m_stack.topType() )
        {
            std::stringstream errstr;
            errstr << "RelationType must have same individual types. Type mismatch."
                   << m_stack.topDescription() << " is not " << Z3_expr::description( type ) << ".";
            m_log.error( { node.sourceLocation() }, errstr.str() );
            break;
        }
        switch( m_stack.topType() )
        {
            case Z3_expr::Tag::TTYPE:
            {
                m_stack.discardTop();
                ++args;
                break;
            }
            case Z3_expr::Tag::SORT:
            {
                sorts.push_back( m_stack.pop< z3::sort >() );
                break;
            }
            // TODO: @moosbruggerj fix ttype, func_decl, expr for thf
            default:
            {
                std::stringstream errstr;
                errstr << m_stack.topDescription() << " is not supported as type in RelationType.";
                m_log.error( { node.sourceLocation() }, errstr.str() );
                break;
            }
        }
    }
    switch( type )
    {
        case Z3_expr::Tag::TTYPE:
        {
            m_stack.push( args );
            break;
        }
        case Z3_expr::Tag::SORT:
        {
            m_stack.push( sorts );
            break;
        }
        // TODO: @moosbruggerj fix ttype, func_decl, expr for thf
        default:
        {
            std::stringstream errstr;
            errstr << m_stack.topDescription() << " is not supported as type in RelationType.";
            m_log.error( { node.sourceLocation() }, errstr.str() );
            break;
        }
    }
}

void AstToZ3Visitor::visit( VariableType& node )
{
    throw std::logic_error( "VariableType not implemented" );
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

void AstToZ3Visitor::visit( IncludeDefinition& node )
{
    m_log.error( { node.sourceLocation() }, "include definition invalid in execution pass" );
    throw std::logic_error( "invalid in execution pass." );
}

void AstToZ3Visitor::visit( FormulaDefinition& node )
{
    m_astContext = std::make_shared< Context >( Context( {} ) );
    // TODO: @moosbruggerj name necessary?
    node.role()->accept( *this );
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

bool AstToZ3Visitor::hasConjecture( void )
{
    return m_hasConjecture;
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
    pu.require< ConsistencyCheckPass >();
}

u1 AstToZ3Pass::run( libpass::PassResult& pr )
{
    libtptp::Logger log( &id, stream() );

    const auto& data = pr.output< ConsistencyCheckPass >();
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

    // TODO: @moosbruggerj fix me, separated execution pass
    auto& solver = visitor.solver();
    auto result = solver.check();

    std::stringstream stream;
    switch( result )
    {
        case z3::check_result::sat:
            stream << solver.get_model();
            if( visitor.hasConjecture() )
            {
                pr.setOutput< AstToZ3Pass >( Output::Result::UNSATISFIABLE, stream.str() );
                // std::cout << "unsat\n";
            }
            else
            {
                pr.setOutput< AstToZ3Pass >( Output::Result::SATISFIABLE, stream.str() );
                // std::cout << "sat\n";
            }
            break;
        case z3::check_result::unsat:
            if( visitor.hasConjecture() )
            {
                pr.setOutput< AstToZ3Pass >( Output::Result::SATISFIABLE );
                // std::cout << "sat\n";
            }
            else
            {
                pr.setOutput< AstToZ3Pass >( Output::Result::UNSATISFIABLE );
                // std::cout << "unsat\n";
            }
            break;
        case z3::check_result::unknown:
            pr.setOutput< AstToZ3Pass >( Output::Result::UNKNOWN );
            // std::cout << "unknown\n";
            break;
    }

    if( log.errors() > 0 )
    {
        return false;
    }
    return true;
}

//
//  Copyright (C) 2017-2018 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
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

#include "AstDumpDotPass.h"

#include <libtptp/transform/SourceToAstPass>

#include <libpass/PassRegistry>

#include <libstdhl/File>

#include <fstream>
#include <iostream>
#include <stack>

using namespace libtptp;

char AstDumpDotPass::id = 0;

static libpass::PassRegistration< AstDumpDotPass > PASS(
    "AstDumpDotPass",
    "generates DOT graph of the AST and dumps to specified output path",
    "ast-dump",
    0 );

class AstDumpDotVisitor : public RecursiveVisitor
{
  private:
    /**
     * @brief RAII dot link
     */
    class DotLink
    {
      public:
        DotLink( AstDumpDotVisitor* visitor, void* node )
        : m_visitor( visitor )
        {
            if( not visitor->m_parentNodes.empty() )
            {
                auto parentNode = visitor->m_parentNodes.top();
                visitor->dumpLink( parentNode, node );
            }
            visitor->m_parentNodes.push( node );
        }

        ~DotLink()
        {
            m_visitor->m_parentNodes.pop();
        }

      private:
        AstDumpDotVisitor* m_visitor;
    };

  public:
    AstDumpDotVisitor( std::ostream& stream );

  private:
    std::ostream& m_stream;
    std::stack< void* > m_parentNodes; /**< holds the parent nodes of DotLink */

    template < class T >
    void handle( T& node, const std::string& label = "", const std::string& attributes = "" );
    void dumpLink( void* parent, void* node );
    void dumpNode( Node& node, const std::string& label, const std::string& attributes );

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

    void visit( FunctionTerm& node ) override;
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
};

AstDumpDotVisitor::AstDumpDotVisitor( std::ostream& stream )
: m_stream( stream )
{
}

template < class T >
void AstDumpDotVisitor::handle( T& node, const std::string& label, const std::string& attributes )
{
    DotLink link( this, &node );
    dumpNode( node, label, attributes );
    RecursiveVisitor::visit( node );
}

void AstDumpDotVisitor::dumpLink( void* parent, void* node )
{
    m_stream << "\"" << parent << "\" -> \"" << node << "\";\n";
}

void AstDumpDotVisitor::dumpNode(
    Node& node, const std::string& label, const std::string& attributes )
{
    m_stream << "\"" << &node << "\" [label=\"" << node.description();

    if( label != "" )
    {
        m_stream << "\n" << label;
    }

    m_stream << "\"";

    if( attributes != "" )
    {
        m_stream << " " << attributes;
    }

    m_stream << "];\n";
}

void AstDumpDotVisitor::visit( Specification& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( FirstOrderFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TypedFirstOrderFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TypedHigherOrderFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TPTPProcessInstructionFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( ClauseNormalFormFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TheoryComputableFunctionalsFormula& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( FormulaData& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( Role& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( UnaryLogic& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( BinaryLogic& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( QuantifiedLogic& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( InfixLogic& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( LogicTuple& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( SequentLogic& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( FunctionTerm& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( VariableTerm& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( ConditionalTerm& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( DefinitionTerm& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( FunctorAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( ConstantAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( DefinedAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( DefinitionAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( ConnectiveAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( AtomType& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( BinaryType& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TypedAtom& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( TupleType& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( QuantifiedType& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( SubType& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( Identifier& node )
{
    handle( node, node.name() );
}

void AstDumpDotVisitor::visit( IntegerLiteral& node )
{
    handle( node, node.value().to_string() );
}

void AstDumpDotVisitor::visit( RationalLiteral& node )
{
    auto rational = static_cast< const libstdhl::Type::Rational& >( node.value() );
    std::stringstream ss;
    ss << rational.numerator().to_string() << "/" << rational.denominator().to_string();
    handle( node, ss.str() );
}

void AstDumpDotVisitor::visit( RealLiteral& node )
{
    handle( node, node.value().to_string() );
}

void AstDumpDotVisitor::visit( DistinctObjectLiteral& node )
{
    auto string = static_cast< const libstdhl::Type::String& >( node.value() );
    handle( node, string.toString() );
}

void AstDumpDotVisitor::visit( ListLiteral& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( Token& node )
{
    if( node.token() != Grammar::Token::UNRESOLVED )
    {
        handle( node, node.tokenString(), "shape=box" );
    }
    else
    {
        RecursiveVisitor::visit( node );
    }
}

void AstDumpDotVisitor::visit( IncludeDefinition& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( FormulaDefinition& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( GeneralData& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( GeneralList& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( GeneralAggregator& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( GeneralFunction& node )
{
    handle( node );
}

void AstDumpDotVisitor::visit( Annotation& node )
{
    handle( node );
}

void AstDumpDotPass::usage( libpass::PassUsage& pu )
{
    pu.require< SourceToAstPass >();
    // pu.repeatUntil< ConsistencyCheckPass >();
}

u1 AstDumpDotPass::run( libpass::PassResult& pr )
{
    Logger log( stream() );

    const auto& data = pr.output< SourceToAstPass >();
    const auto& specification = data->specification();

    // const u1 dumpNodeLocation = true;  // TODO: add command-line switch

    const auto printDotGraph = [&]( std::ostream& out ) {
        out << "digraph \"main\" {\n";

        AstDumpDotVisitor visitor{ out };
        // visitor.setDumpNodeLocation( dumpNodeLocation );

        visitor.visit( *specification );

        out << "}\n";
    };

    if( outputPath() == "" )
    {
        log.debug( "writing dot graph to 'stdout'" );
        printDotGraph( std::cout );
    }
    else
    {
        const auto previousPass = libpass::PassRegistry::passInfo( pr.previousPass() );
        const std::string outputFile = specification->name() + "." + previousPass.name() + ".dot";

        if( not libstdhl::File::Path::exists( outputPath() ) )
        {
            try
            {
                libstdhl::File::Path::create( outputPath() );
            }
            catch( const std::domain_error& e )
            {
                log.error( e.what() );
            }
        }

        const auto outputFilePath = outputPath() + "/" + outputFile;

        std::ofstream dotFile( outputFilePath );
        if( not dotFile.is_open() )
        {
            log.error( "could not open '" + outputFilePath + "'" );
            return false;
        }

        log.debug( "writing dot graph to '" + outputFilePath + "'" );
        printDotGraph( dotFile );
    }

    return true;
}

void AstDumpDotPass::setOutputPath( const std::string& outputPath )
{
    m_outputPath = outputPath;
}

const std::string& AstDumpDotPass::outputPath( void ) const
{
    return m_outputPath;
}

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

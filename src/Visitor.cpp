//
//  Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
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

#include "Visitor.h"

#include "Atom.h"
#include "Definition.h"
#include "Formula.h"
#include "General.h"
#include "Logic.h"
#include "Node.h"
#include "Record.h"
#include "Term.h"
#include "Token.h"
#include "Trace.h"
#include "Type.h"

using namespace libtptp;

//
// RecursiveVisitor
//

void RecursiveVisitor::visit( Trace& node )
{
    node.records()->accept( *this );
}
void RecursiveVisitor::visit( Record& node )
{
    node.name()->accept( *this );
    node.formula()->accept( *this );
}

// TODO: annotations
void RecursiveVisitor::visit( FirstOrderFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( TypedFirstOrderFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( TypedHigherOrderFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( TPTPProcessInstructionFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( ClauseNormalFormFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( TheoryComputableFunctionalsFormula& node )
{
    node.logic()->accept( *this );
    if( node.annotations() )
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( FormulaData& node )
{
    node.dollar()->accept( *this );
    node.formulaType()->accept( *this );
    node.leftParen()->accept( *this );
    node.logic()->accept( *this );
    node.rightParen()->accept( *this );
    if( node.annotations() )  // should always be false for formula data
    {
        node.annotations().value()->accept( *this );
    }
}
void RecursiveVisitor::visit( FormulaRole& node )
{
    node.word()->accept( *this );
}

void RecursiveVisitor::visit( UnaryLogic& node )
{
    node.leftDelimiter()->accept( *this );
    node.connectiveToken()->accept( *this );
    node.logic()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( BinaryLogic& node )
{
    node.leftDelimiter()->accept( *this );
    node.left()->accept( *this );
    node.connectiveToken()->accept( *this );
    node.right()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( QuantifiedLogic& node )
{
    node.leftDelimiter()->accept( *this );
    node.quantifierToken()->accept( *this );
    node.variables()->accept( *this );
    node.colon()->accept( *this );
    node.logic()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( InfixLogic& node )
{
    node.leftDelimiter()->accept( *this );
    node.lhs()->accept( *this );
    node.connectiveToken()->accept( *this );
    node.rhs()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( LogicTuple& node )
{
    node.leftDelimiter()->accept( *this );
    node.leftBraceToken()->accept( *this );
    node.tuples()->accept( *this );
    node.rightBraceToken()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( SequentLogic& node )
{
    node.leftDelimiter()->accept( *this );
    node.left()->accept( *this );
    node.connectiveToken()->accept( *this );
    node.right()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( FunctionTerm& node )
{
    node.leftDelimiter()->accept( *this );
    node.atom()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( VariableTerm& node )
{
    node.leftDelimiter()->accept( *this );
    node.name()->accept( *this );
    if( node.colon() )
    {
        node.colon().value()->accept( *this );
    }
    if( node.type() )
    {
        node.type().value()->accept( *this );
    }
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( ConditionalTerm& node )
{
    node.leftDelimiter()->accept( *this );
    node.dollar()->accept( *this );
    node.ite()->accept( *this );
    node.leftParen()->accept( *this );
    node.condition()->accept( *this );
    node.comma1()->accept( *this );
    node.leftTerm()->accept( *this );
    node.comma2()->accept( *this );
    node.rightTerm()->accept( *this );
    node.rightParen()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( DefinitionTerm& node )
{
    node.leftDelimiter()->accept( *this );
    node.dollar()->accept( *this );
    node.let()->accept( *this );
    node.leftParen()->accept( *this );
    node.types()->accept( *this );
    node.comma1()->accept( *this );
    node.definitions()->accept( *this );
    node.comma2()->accept( *this );
    node.term()->accept( *this );
    node.rightParen()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( FunctorAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.name()->accept( *this );
    node.leftParen()->accept( *this );
    node.arguments()->accept( *this );
    node.rightParen()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( ConstantAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.constant()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( DefinedAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.literal()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( DefinitionAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.lhs()->accept( *this );
    node.assignment()->accept( *this );
    node.rhs()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( ConnectiveAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.connective()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( AtomType& node )
{
    node.leftDelimiter()->accept( *this );
    node.atom()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( BinaryType& node )
{
    node.leftDelimiter()->accept( *this );
    node.left()->accept( *this );
    node.connectiveToken()->accept( *this );
    node.right()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( TypedAtom& node )
{
    node.leftDelimiter()->accept( *this );
    node.atom()->accept( *this );
    node.colon()->accept( *this );
    node.type()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( TupleType& node )
{
    node.leftDelimiter()->accept( *this );
    node.leftBraceToken()->accept( *this );
    node.tuples()->accept( *this );
    node.rightBraceToken()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( QuantifiedType& node )
{
    node.leftDelimiter()->accept( *this );
    node.quantifierToken()->accept( *this );
    node.leftParen()->accept( *this );
    node.variables()->accept( *this );
    node.rightParen()->accept( *this );
    node.colon()->accept( *this );
    node.type()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( SubType& node )
{
    node.leftDelimiter()->accept( *this );
    node.lhs()->accept( *this );
    node.subtypesign()->accept( *this );
    node.rhs()->accept( *this );
    node.rightDelimiter()->accept( *this );
}

void RecursiveVisitor::visit( Identifier& node )
{
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( IntegerLiteral& node )
{
}

void RecursiveVisitor::visit( RationalLiteral& node )
{
}

void RecursiveVisitor::visit( RealLiteral& node )
{
}

void RecursiveVisitor::visit( StringLiteral& node )
{
    node.systemModifier()->accept( *this );
    node.definedModifier()->accept( *this );
}

void RecursiveVisitor::visit( ListLiteral& node )
{
    node.leftBraceToken()->accept( *this );
    node.elements()->accept( *this );
    node.rightBraceToken()->accept( *this );
}

void RecursiveVisitor::visit( Token& node )
{
}

void RecursiveVisitor::visit( IncludeDefinition& node )
{
    node.includeToken()->accept( *this );
    node.leftParenToken()->accept( *this );
    node.filename()->accept( *this );
    node.commaToken()->accept( *this );
    node.formulaSelection()->accept( *this );
    node.rightParenToken()->accept( *this );
    node.dotToken()->accept( *this );
}

void RecursiveVisitor::visit( FormulaDefinition& node )
{
    node.keyword()->accept( *this );
    node.leftParen()->accept( *this );
    node.name()->accept( *this );
    node.comma()->accept( *this );
    node.role()->accept( *this );
    node.comma2()->accept( *this );
    node.formula()->accept( *this );
    node.rightParen()->accept( *this );
    node.dot()->accept( *this );
}

void RecursiveVisitor::visit( GeneralData& node )
{
    node.data()->accept( *this );
}

void RecursiveVisitor::visit( GeneralList& node )
{
    node.list()->accept( *this );
}

void RecursiveVisitor::visit( GeneralAggregator& node )
{
    node.data()->accept( *this );
    node.colon()->accept( *this );
    node.term()->accept( *this );
}

void RecursiveVisitor::visit( GeneralFunction& node )
{
    node.name()->accept( *this );
    node.leftParen()->accept( *this );
    node.arguments()->accept( *this );
    node.rightParen()->accept( *this );
}

void RecursiveVisitor::visit( Annotation& node )
{
    node.source()->accept( *this );
    node.comma()->accept( *this );
    if( node.usefulInfo() )
    {
        node.usefulInfo().value()->accept( *this );
    }
}

//
// TraversalVisitor
//

TraversalVisitor::TraversalVisitor( const Traversal order, std::function< void( Node& ) > callback )
: m_order( order )
, m_callback( callback )
{
}

Traversal TraversalVisitor::order( void ) const
{
    return m_order;
}

std::function< void( Node& ) > TraversalVisitor::callback( void ) const
{
    return m_callback;
}

void TraversalVisitor::visit( Trace& node )
{
    if( order() == PREORDER )
    {
        callback()( node );
    }

    node.records()->accept( *this );

    if( order() == POSTORDER )
    {
        callback()( node );
    }
}
void TraversalVisitor::visit( Record& node )
{
    callback()( node );
}

void TraversalVisitor::visit( FirstOrderFormula& node )
{
    callback()( node );
}
void TraversalVisitor::visit( TypedFirstOrderFormula& node )
{
    callback()( node );
}

void TraversalVisitor::visit( UnaryLogic& node )
{
    callback()( node );
}
void TraversalVisitor::visit( BinaryLogic& node )
{
    callback()( node );
}
void TraversalVisitor::visit( QuantifiedLogic& node )
{
    callback()( node );
}
void TraversalVisitor::visit( SequentLogic& node )
{
    callback()( node );
}

void TraversalVisitor::visit( FunctionTerm& node )
{
    callback()( node );
}
void TraversalVisitor::visit( VariableTerm& node )
{
    callback()( node );
}
void TraversalVisitor::visit( ConditionalTerm& node )
{
    callback()( node );
}

void TraversalVisitor::visit( FunctorAtom& node )
{
    callback()( node );
}

void TraversalVisitor::visit( Identifier& node )
{
    callback()( node );
}

void TraversalVisitor::visit( StringLiteral& node )
{
    callback()( node );
}

void TraversalVisitor::visit( IntegerLiteral& node )
{
    callback()( node );
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

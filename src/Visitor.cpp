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

#include "Visitor.h"

#include "Atom.h"
#include "Formula.h"
#include "Logic.h"
#include "Node.h"
#include "Record.h"
#include "Term.h"
#include "Trace.h"

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

void RecursiveVisitor::visit( FirstOrderFormula& node )
{
    node.logic()->accept( *this );
}
void RecursiveVisitor::visit( TypedFirstOrderFormula& node )
{
    node.logic()->accept( *this );
}

void RecursiveVisitor::visit( UnaryLogic& node )
{
    node.logic()->accept( *this );
}
void RecursiveVisitor::visit( BinaryLogic& node )
{
    node.left()->accept( *this );
    node.right()->accept( *this );
}
void RecursiveVisitor::visit( QuantifiedLogic& node )
{
    node.logic()->accept( *this );
}
void RecursiveVisitor::visit( SequentLogic& node )
{
    node.left()->accept( *this );
    node.right()->accept( *this );
}

void RecursiveVisitor::visit( FunctionTerm& node )
{
    node.atom()->accept( *this );
}
void RecursiveVisitor::visit( VariableTerm& node )
{
    node.name()->accept( *this );
}
void RecursiveVisitor::visit( ConditionalTerm& node )
{
    node.condition()->accept( *this );
    node.left()->accept( *this );
    node.right()->accept( *this );
}

void RecursiveVisitor::visit( FunctorAtom& node )
{
    node.name()->accept( *this );
    node.arguments()->accept( *this );
}

void RecursiveVisitor::visit( Identifier& node )
{
    node.name()->accept( *this );
}

void RecursiveVisitor::visit( StringLiteral& node )
{
}

void RecursiveVisitor::visit( IntegerLiteral& node )
{
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

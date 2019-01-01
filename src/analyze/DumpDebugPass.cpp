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

#include "DumpDebugPass.h"

#include <libtptp/Atom>
#include <libtptp/Formula>
#include <libtptp/Logic>
#include <libtptp/Node>
#include <libtptp/Record>
#include <libtptp/Term>
#include <libtptp/Trace>

#include <libpass/PassLogger>
#include <libpass/PassRegistry>

#include <iostream>

using namespace libtptp;

char DumpDebugPass::id = 0;

static libpass::PassRegistration< DumpDebugPass > PASS(
    "TptpDumpDebugPass",
    "translates the TPTP fromat to the ASCII debug code representation",
    "tptp-dump",
    0 );

void DumpDebugPass::usage( libpass::PassUsage& pu )
{
}

u1 DumpDebugPass::run( libpass::PassResult& pr )
{
    libpass::PassLogger log( &id, stream() );

    // const auto data = pr.result< X >();
    // const auto tptp = data->tptp();

    DumpDebugVisitor visitor{ std::cout };
    // data->specification()->accept( visitor );

    return true;
}

//
// DumpDebugVisitor
//

DumpDebugVisitor::DumpDebugVisitor( std::ostream& stream )
: m_stream( stream )
{
}

void DumpDebugVisitor::visit( Trace& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( Record& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::visit( FirstOrderFormula& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( TypedFirstOrderFormula& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::visit( UnaryLogic& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( BinaryLogic& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( QuantifiedLogic& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( SequentLogic& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::visit( FunctionTerm& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( VariableTerm& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}
void DumpDebugVisitor::visit( ConditionalTerm& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::visit( FunctorAtom& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::visit( Identifier& node )
{
    dump( node );
    RecursiveVisitor::visit( node );
}

void DumpDebugVisitor::dump( Node& node ) const
{
    m_stream << "% " << node.description() << "\n";
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

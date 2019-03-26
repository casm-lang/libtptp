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

#include "DumpSourcePass.h"

#include <libtptp/Atom>
#include <libtptp/Formula>
#include <libtptp/Identifier>
#include <libtptp/Literal>
#include <libtptp/Logic>
#include <libtptp/Node>
#include <libtptp/Specification>
#include <libtptp/Term>

#include <libpass/PassLogger>
#include <libpass/PassRegistry>

#include <iostream>

using namespace libtptp;

char DumpSourcePass::id = 0;

static libpass::PassRegistration< DumpSourcePass > PASS(
    "TptpDumpSourcePass",
    "translates the TPTP fromat to the ASCII source code representation",
    "tptp-dump",
    0 );

void DumpSourcePass::usage( libpass::PassUsage& pu )
{
}

u1 DumpSourcePass::run( libpass::PassResult& pr )
{
    libpass::PassLogger log( &id, stream() );

    // const auto data = pr.result< X >();
    // const auto tptp = data->tptp();

    DumpSourceVisitor visitor{ std::cout };
    // data->specification()->accept( visitor );

    return true;
}

//
// DumpSourceVisitor
//

DumpSourceVisitor::DumpSourceVisitor( std::ostream& stream )
: m_stream( stream )
{
}

void DumpSourceVisitor::visit( Specification& node )
{
    m_stream << "% " << node.description() << ": " << node.name() << "\n";

    node.definitions()->accept( *this );
}

void DumpSourceVisitor::visit( Identifier& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.name();
}

void DumpSourceVisitor::visit( IntegerLiteral& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.value().to_string();
}

void DumpSourceVisitor::visit( RationalLiteral& node )
{
    RecursiveVisitor::visit( node );
    auto rational = static_cast< const libstdhl::Type::Rational& >( node.value() );
    m_stream << rational.numerator().to_string() << "/" << rational.denominator().to_string();
}

void DumpSourceVisitor::visit( RealLiteral& node )
{
    RecursiveVisitor::visit( node );
    m_stream << node.value().to_string();
}

void DumpSourceVisitor::visit( DistinctObjectLiteral& node )
{
    RecursiveVisitor::visit( node );
    auto string = static_cast< const libstdhl::Type::String& >( node.value() );
    m_stream << string.toString();
}

void DumpSourceVisitor::visit( Token& node )
{
    RecursiveVisitor::visit( node );
    if( node.token() != libtptp::Grammar::Token::UNRESOLVED )
    {
        m_stream << node.tokenString();
    }
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

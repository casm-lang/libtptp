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

#include "SourceToAstPass.h"

#include "../Lexer.h"
#include "../various/GrammarParser.tab.h"

#include <libtptp/Logger>

#include <libpass/PassRegistry>
#include <libpass/PassResult>
#include <libpass/PassUsage>

using namespace libtptp;

char SourceToAstPass::id = 0;

static libpass::PassRegistration< SourceToAstPass > PASS(
    "SourceToAstPass", "TBD", "tptp-parse", 0 );

void SourceToAstPass::usage( libpass::PassUsage& pu )
{
    pu.require< libpass::LoadFilePass >();
}

u1 SourceToAstPass::run( libpass::PassResult& pr )
{
    libtptp::Logger log( &id, stream() );

    const auto data = pr.output< libpass::LoadFilePass >();
    const auto filePath = data->filename();
    auto& fileStream = data->stream();

    const auto fileName = filePath.substr( filePath.find_last_of( "/\\" ) + 1 );
    const auto name = fileName.substr( 0, fileName.rfind( "." ) );

    auto specification = std::make_shared< Specification >();
    specification->setName( name );

    Lexer lexer( log, fileStream, std::cout );
    lexer.setFileName( filePath );

    Parser parser( log, lexer, *specification );
    parser.set_debug_level( m_debug );

    if( ( parser.parse() != 0 ) or not specification or ( log.errors() > 0 ) )
    {
        log.error( "could not parse `" + filePath + "´" );
        return false;
    }

    pr.setOutput< SourceToAstPass >( specification );
    return true;
}

void SourceToAstPass::setDebug( u1 debug )
{
    m_debug = debug;
}

u1 SourceToAstPass::debug( void ) const
{
    return m_debug;
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

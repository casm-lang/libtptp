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

#include <libstdhl/Test>

#include <libpass/libpass>

#include "main.h"

using namespace libtptp;
using namespace libpass;

static const auto uToken = std::make_shared< Token >( Grammar::Token::UNRESOLVED );

TEST( libtptp, example )
{
    const auto specification = libstdhl::Memory::make< Specification >();

    auto x = std::make_shared< Identifier >( "x" );
    auto v = std::make_shared< ConstantAtom >( x, Atom::Kind::PLAIN );

    auto y = std::make_shared< Identifier >( "y" );
    auto f = std::make_shared< FirstOrderFormula >( v );

    specification->add< FormulaDefinition >( y, Role::axiom(), f );

    PassManager pm;
    libstdhl::Logger log( pm.stream() );
    log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) );

    auto flush = [ &pm ]() {
        libstdhl::Log::ApplicationFormatter f( TEST_NAME );
        libstdhl::Log::OutputStreamSink c( std::cerr, f );
        pm.stream().flush( c );
    };

    PassResult pr;
    pr.setOutput< SourceToAstPass >( specification );
    pm.setDefaultResult( pr );
    pm.setDefaultPass< AstToZ3Pass >();

    EXPECT_EQ( pm.run( flush ), true );
}

TEST( libtptp, include_file )
{
    PassManager pm;

    libstdhl::Logger log( pm.stream() );
    log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) );

    auto flush = [ &pm ]() {
        libstdhl::Log::ApplicationFormatter f( TEST_NAME );
        libstdhl::Log::OutputStreamSink c( std::cerr, f );
        pm.stream().flush( c );
    };

    pm.add< SourceToAstPass >();
    pm.setDefaultPass< SourceToAstPass >();

    const std::string filename = TEST_NAME + ".tptp";
    auto file = libstdhl::File::open( filename, std::fstream::out );
    file << " include ( 'testfile' ). " << std::endl;
    file << " include ( 'testfile2', [somemethod, 'some_method', 3] ). ";
    file.close();

    const auto input = libstdhl::Memory::make< LoadFilePass::Input >( filename );
    PassResult pr;
    pr.setInputData< LoadFilePass >( input );
    pm.setDefaultResult( pr );

    EXPECT_EQ( pm.run( flush ), true );

    pm.result().output< LoadFilePass >()->close();
    libstdhl::File::remove( filename );
    EXPECT_EQ( libstdhl::File::exists( filename ), false );
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

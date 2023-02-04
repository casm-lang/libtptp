//
//  Copyright (C) 2017-2023 CASM Organization <https://casm-lang.org>
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

#define SOURCE_TEST( SCOPE, PASS, CONTENT, STATUS, DESCRIPTION, CONFIG )                          \
    TEST( libtptp, SCOPE##_##PASS##DESCRIPTION )                                                  \
    {                                                                                             \
        libpass::PassManager pm;                                                                  \
        libstdhl::Logger log( pm.stream() );                                                      \
        log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) ); \
        auto flush = [ &pm ]() {                                                                  \
            libstdhl::Log::ApplicationFormatter f( TEST_NAME );                                   \
            libstdhl::Log::OutputStreamSink c( std::cerr, f );                                    \
            pm.stream().flush( c );                                                               \
        };                                                                                        \
        const std::string filename = TEST_NAME + ".tptp";                                         \
        auto file = libstdhl::File::open( filename, std::fstream::out );                          \
        file << CONTENT;                                                                          \
        file.close();                                                                             \
        EXPECT_EQ( libstdhl::File::exists( filename ), true );                                    \
                                                                                                  \
        pm.setDefaultPass< PASS >();                                                              \
        pm.set< libtptp::PASS >( [ & ]( libtptp::PASS& pass ) { CONFIG } );                       \
                                                                                                  \
        libpass::PassResult pr;                                                                   \
        const auto input = libstdhl::Memory::make< libpass::LoadFilePass::Input >( filename );    \
        pr.setInputData< libpass::LoadFilePass >( input );                                        \
        pm.setDefaultResult( pr );                                                                \
                                                                                                  \
        EXPECT_EQ( pm.run( flush ), STATUS );                                                     \
                                                                                                  \
        pm.result().output< libpass::LoadFilePass >()->close();                                   \
        libstdhl::File::remove( filename );                                                       \
        EXPECT_EQ( libstdhl::File::exists( filename ), false );                                   \
    }

#define SOURCE_TEST_Z3( SCOPE, PASS, CONTENT, STATUS, DESCRIPTION, CONFIG, RESULT )               \
    TEST( libtptp, SCOPE##_##PASS##DESCRIPTION )                                                  \
    {                                                                                             \
        libpass::PassManager pm;                                                                  \
        libstdhl::Logger log( pm.stream() );                                                      \
        log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) ); \
        auto flush = [ &pm ]() {                                                                  \
            libstdhl::Log::ApplicationFormatter f( TEST_NAME );                                   \
            libstdhl::Log::OutputStreamSink c( std::cerr, f );                                    \
            pm.stream().flush( c );                                                               \
        };                                                                                        \
        const std::string filename = TEST_NAME + ".tptp";                                         \
        auto file = libstdhl::File::open( filename, std::fstream::out );                          \
        file << CONTENT;                                                                          \
        file.close();                                                                             \
        EXPECT_EQ( libstdhl::File::exists( filename ), true );                                    \
                                                                                                  \
        pm.setDefaultPass< PASS >();                                                              \
        pm.set< libtptp::PASS >( [ & ]( libtptp::PASS& pass ) { CONFIG } );                       \
                                                                                                  \
        libpass::PassResult pr;                                                                   \
        const auto input = libstdhl::Memory::make< libpass::LoadFilePass::Input >( filename );    \
        pr.setInputData< libpass::LoadFilePass >( input );                                        \
        pm.setDefaultResult( pr );                                                                \
                                                                                                  \
        EXPECT_EQ( pm.run( flush ), STATUS );                                                     \
        auto result = pm.result().output< libtptp::PASS >()->result();                            \
        EXPECT_EQ( result, RESULT );                                                              \
        switch( result )                                                                          \
        {                                                                                         \
            case libtptp::PASS::Output::Result::SATISFIABLE:                                      \
            {                                                                                     \
                log.info( "sat" );                                                                \
                break;                                                                            \
            }                                                                                     \
            case libtptp::PASS::Output::Result::UNSATISFIABLE:                                    \
            {                                                                                     \
                log.info( "unsat" );                                                              \
                break;                                                                            \
            }                                                                                     \
            case libtptp::PASS::Output::Result::UNKNOWN:                                          \
            {                                                                                     \
                log.info( "unknown" );                                                            \
                break;                                                                            \
            }                                                                                     \
        }                                                                                         \
        auto model = pm.result().output< libtptp::PASS >()->model();                              \
        if( model != "" )                                                                         \
        {                                                                                         \
            log.info( model );                                                                    \
        }                                                                                         \
                                                                                                  \
        pm.result().output< libpass::LoadFilePass >()->close();                                   \
        libstdhl::File::remove( filename );                                                       \
        EXPECT_EQ( libstdhl::File::exists( filename ), false );                                   \
    }

#define SOURCE_COMPARE_TEST( SCOPE, PASS, CONTENT, STATUS, DESCRIPTION, CONFIG )                  \
    TEST( libtptp, SCOPE##_##CONTENT##DESCRIPTION )                                               \
    {                                                                                             \
        libpass::PassManager pm;                                                                  \
        libstdhl::Logger log( pm.stream() );                                                      \
        log.setSource( libstdhl::Memory::make< libstdhl::Log::Source >( TEST_NAME, TEST_NAME ) ); \
        auto flush = [ &pm ]() {                                                                  \
            libstdhl::Log::ApplicationFormatter f( TEST_NAME );                                   \
            libstdhl::Log::OutputStreamSink c( std::cerr, f );                                    \
            pm.stream().flush( c );                                                               \
        };                                                                                        \
        const std::string filename = TEST_NAME + ".tptp";                                         \
        auto file = libstdhl::File::open( filename, std::fstream::out );                          \
        file << CONTENT;                                                                          \
        file.close();                                                                             \
        EXPECT_EQ( libstdhl::File::exists( filename ), true );                                    \
                                                                                                  \
        pm.add< SourceToAstPass >();                                                              \
        pm.setDefaultPass< libtptp::PASS >();                                                     \
                                                                                                  \
        const auto input = libstdhl::Memory::make< libpass::LoadFilePass::Input >( filename );    \
                                                                                                  \
        libpass::PassResult pr;                                                                   \
        pr.setInputData< libpass::LoadFilePass >( input );                                        \
        pm.setDefaultResult( pr );                                                                \
                                                                                                  \
        EXPECT_EQ( pm.run( flush ), STATUS );                                                     \
        EXPECT_EQ(                                                                                \
            TestHelper::compareTPTPFiles(                                                         \
                CONTENT, pm.result().output< libtptp::PASS >()->stream().str() ),                 \
            true );                                                                               \
                                                                                                  \
        pm.result().output< libpass::LoadFilePass >()->close();                                   \
        libstdhl::File::remove( filename );                                                       \
        EXPECT_EQ( libstdhl::File::exists( filename ), false );                                   \
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

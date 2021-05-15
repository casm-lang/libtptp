//
//  Copyright (C) 2017-2021 CASM Organization <https://casm-lang.org>
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

#include "main.h"

#include <z3++.h>

/**
   Demonstration of how Z3 can be used to prove validity of
   De Morgan's Duality Law: {e not(x and y) <-> (not x) or ( not y) }
   see: https://github.com/Z3Prover/z3/blob/master/examples/c%2B%2B/example.cpp
*/

TEST( libtptp, z3_demorgan )
{
    z3::context c;

    z3::expr x = c.bool_const( "x" );
    z3::expr y = c.bool_const( "y" );
    z3::expr conjecture = ( !( x && y ) ) == ( !x || !y );

    z3::solver s( c );
    // adding the negation of the conjecture as a constraint.
    s.add( !conjecture );
    std::cout << s << "\n";
    std::cout << s.to_smt2() << "\n";

    switch( s.check() )
    {
        case z3::unsat:
        {
            std::cout << "de-Morgan is valid\n";
            break;
        }
        case z3::sat:
        {
            std::cout << "de-Morgan is not valid\n";
            break;
        }
        case z3::unknown:
        {
            std::cout << "unknown\n";
            break;
        }
    }
}

TEST( libtptp, DISABLED_z3_tuples_behaviour )
{
    z3::context c;

    const char* names[] = { "i1", "i2" };
    z3::sort sorts[ 2 ] = { c.int_sort(), c.int_sort() };
    z3::func_decl_vector funcs( c );

    z3::expr in1 = c.int_const( "in1" );
    z3::expr in2 = c.int_const( "in2" );

    const auto tuple_fun = c.tuple_sort( "tuple", 2, names, sorts, funcs );

    const auto const3 = tuple_fun( in1, in2 );

    z3::func_decl f = c.function( "some_fun", tuple_fun.range(), c.bool_sort() );
    z3::expr const1 = c.constant( "const1", tuple_fun.range() );

    const auto tuple_fun2 = c.tuple_sort( "tuple2", 2, names, sorts, funcs );
    z3::expr const2 = c.constant( "const2", tuple_fun2.range() );
    z3::solver s( c );

    const auto tuple_fun_2 = c.tuple_sort( "tuple", 2, names, sorts, funcs );
    const auto const4 = tuple_fun_2( in1, in2 );

    const char* names2[] = { "i1", "i2", "i3" };
    z3::sort sorts2[ 3 ] = { c.int_sort(), c.int_sort(), c.int_sort() };

    const auto tuple_fun3 = c.tuple_sort( "tuple", 3, names2, sorts2, funcs );
    const auto const5 = tuple_fun3( in1, in2, in1 );

    s.add( f( const1 ) );
    EXPECT_THROW( s.add( f( const2 ) ), z3::exception );
    s.add( f( const3 ) );
    s.add( f( const4 ) );
    // exits with assertion validation
    // s.add( f( const5 ) );

    switch( s.check() )
    {
        case z3::unsat:
        {
            std::cout << "unsat";
            break;
        }
        case z3::sat:
        {
            std::cout << "sat";
            break;
        }
        case z3::unknown:
        {
            std::cout << "unknown\n";
            break;
        }
    }
    std::cout << s.get_model() << std::endl;
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

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

#include "macros.cpp"
#include "resources/tff_formula.cpp"

#include "main.h"

using namespace libtptp;
using namespace libpass;

static const std::string source_fof_constant = R"***(
fof(constant, theorem, x).
)***";

static const std::string source_fof_de_morgan = R"***(
fof(demorgan, negated_conjecture, ~((~x | ~y) <=> ~(x & y))).
)***";

static const std::string source_tff_quantified = R"***(
tff(quantified, conjecture, ?[X: $int, Y: $int]: $sum(X, 1) = Y).
)***";

static const std::string source_tff_basic_function = R"***(
tff(func, type, f: $int > $o).
tff(int_var, type, i: $int).
tff(func_use, axiom, f(1)).
tff(inverse_func, theorem, ~f(2)).
)***";

static const std::string source_tff_polymorphic_types = R"***(
tff(pol_type, type, pol: $tType > $tType).
tff(instance_var, type, ii: pol($int)).
tff(func_pol, type, fi: pol($int) > $o).
tff(use, type, fi(ii)).
)***";

static const std::string source_tff_multiple_polymorphic_types = R"***(
tff(pol_type, type, pol: ($tType * $tType * $tType) > $tType).
tff(instance_var, type, ii: pol($int, $i, $o)).
tff(func_pol, type, fi: pol($int, $i, $o) > $o).
tff(use, type, fi(ii)).
)***";

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_fof_constant,
    true,
    _fof_constant,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_fof_de_morgan,
    true,
    _fof_de_morgan,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_tff_quantified,
    true,
    _tff_quantified,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_tff_basic_function,
    true,
    _tff_basic_function,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    tff_small_example,
    true,
    _tff_small,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3, AstToZ3Pass, tff_test_basic, true, _tff_basic, , AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_tff_polymorphic_types,
    true,
    _tff_polymorph,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

SOURCE_TEST_Z3(
    z3,
    AstToZ3Pass,
    source_tff_multiple_polymorphic_types,
    true,
    _tff_multiple_polymorph,
    ,
    AstToZ3Pass::Output::Result::SATISFIABLE );

// SOURCE_TEST( z3, AstToZ3Pass, tff_test_tf1, true, _tff_tf1, );

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

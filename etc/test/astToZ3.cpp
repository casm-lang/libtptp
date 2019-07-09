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

#include <libstdhl/Test>

#include <libpass/libpass>

#include <libtptp/transform/AstToZ3Pass>

#include "macros.cpp"

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

SOURCE_TEST( z3, AstToZ3Pass, source_fof_constant, true, _fof_constant, );

SOURCE_TEST( z3, AstToZ3Pass, source_fof_de_morgan, true, _fof_de_morgan, );

SOURCE_TEST( z3, AstToZ3Pass, source_tff_quantified, true, _tff_quantified, );

SOURCE_TEST( z3, AstToZ3Pass, source_tff_basic_function, true, _tff_basic_function, );

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

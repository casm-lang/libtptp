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

#include <libstdhl/Test>

#include <libpass/libpass>

#include "main.h"
#include "testhelper.h"
#include "macros.cpp"

using namespace libtptp;
using namespace libpass;

std::string annotation_source_general_term = R"***(
fof(no_annotation, axiom, functor).
fof(lower_word_annotation, axiom, functor, general_data_word).
fof(general_function_annotation, axiom, functor, general_function(general_term)).
fof(variable_annotation, axiom, functor, VariableName).
fof(integer_annotation, axiom, functor, 7).
fof(real_annotation, axiom, functor, 3.3).
fof(rational_annotation, axiom, functor, 4/2).
fof(aggregate_annotation, axiom, functor, 4/2:abc).
fof(distinct_object_annotation, axiom, functor, "distinct object").
fof(recursive_aggregate_annotation, axiom, functor, 4/2:3:2:"distinct").
fof(list_annotation, axiom, functor, [5, 3, 3.4]).
fof(formula_annotation, axiom, functor, $fot(Variable)).
)***";

// enable as soon as Decimal is fixed
//SOURCE_COMPARE_TEST(libtptp, DumpSourcePass, annotation_source_general_term, true, , )

std::string annotation_useful_info_general_list = R"***(
fof(empty_list, axiom, functor, general_data_word, []).
fof(simple_integer_list, axiom, functor, general_data_word, [0, 1, 2, 3, 4]).
fof(mixed_types_list, axiom, functor, general_data_word, [0, 1.4, 2/3, Variable, "distinct object"]).
fof(recursive_list, axiom, functor, general_data_word, [[], [[0, 1], ab:a], Variable]).
)***";


// enable as soon as Decimal is fixed
//SOURCE_COMPARE_TEST(libtptp, DumpSourcePass, annotation_useful_info_general_list, true, , )


//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

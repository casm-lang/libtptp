//
//  Copyright (C) 2017-2020 CASM Organization <https://casm-lang.org>
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

// http://www.tptp.org/TPTP/Proposals/TPILanguage.html
static const std::string tpi_test_example = R"***(    tpi(1,start_group,old_and_new_axioms).
    tpi(2,start_group,old_axioms).
    tpi(3,input,'Axioms/SYN001+1.ax').
    tpi(4,start_group,new_axioms).
    tpi(5,input,'Axioms/SYN001+2.ax').
    tpi(6,end_group,old_axioms).
    tpi(7,input,'Axioms/SYN002+1.ax').
    tpi(8,end_group,new_axioms).
    tpi(9,end_group,old_and_new_axioms).
    tpi(10,input,'Axioms/SYN003+1.ax').
    tpi(11,start_group,the_conjecture).
    fof(a,conjecture,qq).
    tpi(12,end_group,the_conjecture).
    tpi(13,execute,
        'SZS_STATUS' = '$TPTP_HOME/Systems/E---1.6/eprover -s --auto --cpu-limit=300 --tstp-format $getgroups(old_axioms,the_conjecture)').
    tpi(14,write,'Conjecture status for old axioms:' & $getenv('SZS_STATUS')).
    tpi(15,execute,
        'SZS_STATUS' = '$TPTP_HOME/Systems/E---1.6/eprover -s --auto --cpu-limit=300 --tstp-format $getgroups(new_axioms,the_conjecture)').
    tpi(16,write,'Conjecture status for replacement axioms:' & $getenv('SZS_STATUS')).
    tpi(17,execute,
        'SZS_STATUS' = '$TPTP_HOME/Systems/E---1.6/eprover -s --auto --cpu-limit=300 --tstp-format $getgroups(old_and_new_axioms,the_conjecture)').
    tpi(18,write,'Conjecture status for old and new axioms:' & $getenv('SZS_STATUS')).
    tpi(19,execute,
        'SZS_STATUS' = '$TPTP_HOME/Systems/E---1.6/eprover -s --auto --cpu-limit=300 --tstp-format $getgroups(tpi)').
    tpi(20,write,'Conjecture status for all axioms:' & $getenv('SZS_STATUS')).
    tpi(21,exit,exit).
)***";
//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

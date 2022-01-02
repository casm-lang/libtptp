//
//  Copyright (C) 2017-2022 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//                <https://github.com/casm-lang/libtptp/graphs/contributors>
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

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=ALG&File=ALG181+1.p
static const std::string fof_test_depth =
    R"***(%--------------------------------------------------------------------------
% File     : ALG181+1 : TPTP v7.2.0. Released v2.7.0.
% Domain   : General Algebra
% Problem  : Quasigroups 5 QG4: REPRESENTATIVES-PAIRWISE-NOT-ISO-PROBLEM-2
% Version  : Especial.
% English  :

% Refs     : [Mei03] Meier (2003), Email to G.Sutcliffe
%          : [CM+04] Colton et al. (2004), Automatic Generation of Classifi
% Source   : [Mei03]
% Names    :

% Status   : Theorem
% Rating   : 0.08 v7.2.0, 0.00 v6.3.0, 0.07 v6.2.0, 0.09 v6.1.0, 0.00 v5.5.0, 0.11 v5.3.0, 0.27 v5.2.0, 0.25 v5.0.0, 0.00 v3.7.0, 0.14 v3.5.0, 0.22 v3.4.0, 0.25 v3.3.0, 0.11 v3.1.0, 0.22 v2.7.0
% Syntax   : Number of formulae    :    6 (   0 unit)
%            Number of atoms       :  205 ( 205 equality)
%            Maximal formula depth :   62 (  27 average)
%            Number of connectives :  245 (  46   ~;  40   |; 158   &)
%                                         (   0 <=>;   1  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of predicates  :    1 (   0 propositional; 2-2 arity)
%            Number of functors    :   14 (  10 constant; 0-2 arity)
%            Number of variables   :    0 (   0 sgn;   0   !;   0   ?)
%            Maximal term depth    :    3 (   2 average)
% SPC      : FOF_THM_RFO_PEQ

% Comments :
%--------------------------------------------------------------------------
fof(ax1,axiom,
    ( e10 != e11
    & e10 != e12
    & e10 != e13
    & e10 != e14
    & e11 != e12
    & e11 != e13
    & e11 != e14
    & e12 != e13
    & e12 != e14
    & e13 != e14 )).

fof(ax2,axiom,
    ( e20 != e21
    & e20 != e22
    & e20 != e23
    & e20 != e24
    & e21 != e22
    & e21 != e23
    & e21 != e24
    & e22 != e23
    & e22 != e24
    & e23 != e24 )).

fof(ax3,axiom,
    ( e10 != e20
    & e10 != e21
    & e10 != e22
    & e10 != e23
    & e10 != e24
    & e11 != e20
    & e11 != e21
    & e11 != e22
    & e11 != e23
    & e11 != e24
    & e12 != e20
    & e12 != e21
    & e12 != e22
    & e12 != e23
    & e12 != e24
    & e13 != e20
    & e13 != e21
    & e13 != e22
    & e13 != e23
    & e13 != e24
    & e14 != e20
    & e14 != e21
    & e14 != e22
    & e14 != e23
    & e14 != e24 )).

fof(ax4,axiom,
    ( op1(e10,e10) = e13
    & op1(e10,e11) = e12
    & op1(e10,e12) = e10
    & op1(e10,e13) = e11
    & op1(e10,e14) = e14
    & op1(e11,e10) = e10
    & op1(e11,e11) = e14
    & op1(e11,e12) = e11
    & op1(e11,e13) = e12
    & op1(e11,e14) = e13
    & op1(e12,e10) = e11
    & op1(e12,e11) = e13
    & op1(e12,e12) = e12
    & op1(e12,e13) = e14
    & op1(e12,e14) = e10
    & op1(e13,e10) = e14
    & op1(e13,e11) = e11
    & op1(e13,e12) = e13
    & op1(e13,e13) = e10
    & op1(e13,e14) = e12
    & op1(e14,e10) = e12
    & op1(e14,e11) = e10
    & op1(e14,e12) = e14
    & op1(e14,e13) = e13
    & op1(e14,e14) = e11 )).

fof(ax5,axiom,
    ( op2(e20,e20) = e20
    & op2(e20,e21) = e23
    & op2(e20,e22) = e24
    & op2(e20,e23) = e21
    & op2(e20,e24) = e22
    & op2(e21,e20) = e24
    & op2(e21,e21) = e21
    & op2(e21,e22) = e23
    & op2(e21,e23) = e22
    & op2(e21,e24) = e20
    & op2(e22,e20) = e21
    & op2(e22,e21) = e20
    & op2(e22,e22) = e22
    & op2(e22,e23) = e24
    & op2(e22,e24) = e23
    & op2(e23,e20) = e22
    & op2(e23,e21) = e24
    & op2(e23,e22) = e20
    & op2(e23,e23) = e23
    & op2(e23,e24) = e21
    & op2(e24,e20) = e23
    & op2(e24,e21) = e22
    & op2(e24,e22) = e21
    & op2(e24,e23) = e20
    & op2(e24,e24) = e24 )).

fof(co1,conjecture,
    ( ( ( h(e10) = e20
        | h(e10) = e21
        | h(e10) = e22
        | h(e10) = e23
        | h(e10) = e24 )
      & ( h(e11) = e20
        | h(e11) = e21
        | h(e11) = e22
        | h(e11) = e23
        | h(e11) = e24 )
      & ( h(e12) = e20
        | h(e12) = e21
        | h(e12) = e22
        | h(e12) = e23
        | h(e12) = e24 )
      & ( h(e13) = e20
        | h(e13) = e21
        | h(e13) = e22
        | h(e13) = e23
        | h(e13) = e24 )
      & ( h(e14) = e20
        | h(e14) = e21
        | h(e14) = e22
        | h(e14) = e23
        | h(e14) = e24 )
      & ( j(e20) = e10
        | j(e20) = e11
        | j(e20) = e12
        | j(e20) = e13
        | j(e20) = e14 )
      & ( j(e21) = e10
        | j(e21) = e11
        | j(e21) = e12
        | j(e21) = e13
        | j(e21) = e14 )
      & ( j(e22) = e10
        | j(e22) = e11
        | j(e22) = e12
        | j(e22) = e13
        | j(e22) = e14 )
      & ( j(e23) = e10
        | j(e23) = e11
        | j(e23) = e12
        | j(e23) = e13
        | j(e23) = e14 )
      & ( j(e24) = e10
        | j(e24) = e11
        | j(e24) = e12
        | j(e24) = e13
        | j(e24) = e14 ) )
   => ~ ( h(op1(e10,e10)) = op2(h(e10),h(e10))
        & h(op1(e10,e11)) = op2(h(e10),h(e11))
        & h(op1(e10,e12)) = op2(h(e10),h(e12))
        & h(op1(e10,e13)) = op2(h(e10),h(e13))
        & h(op1(e10,e14)) = op2(h(e10),h(e14))
        & h(op1(e11,e10)) = op2(h(e11),h(e10))
        & h(op1(e11,e11)) = op2(h(e11),h(e11))
        & h(op1(e11,e12)) = op2(h(e11),h(e12))
        & h(op1(e11,e13)) = op2(h(e11),h(e13))
        & h(op1(e11,e14)) = op2(h(e11),h(e14))
        & h(op1(e12,e10)) = op2(h(e12),h(e10))
        & h(op1(e12,e11)) = op2(h(e12),h(e11))
        & h(op1(e12,e12)) = op2(h(e12),h(e12))
        & h(op1(e12,e13)) = op2(h(e12),h(e13))
        & h(op1(e12,e14)) = op2(h(e12),h(e14))
        & h(op1(e13,e10)) = op2(h(e13),h(e10))
        & h(op1(e13,e11)) = op2(h(e13),h(e11))
        & h(op1(e13,e12)) = op2(h(e13),h(e12))
        & h(op1(e13,e13)) = op2(h(e13),h(e13))
        & h(op1(e13,e14)) = op2(h(e13),h(e14))
        & h(op1(e14,e10)) = op2(h(e14),h(e10))
        & h(op1(e14,e11)) = op2(h(e14),h(e11))
        & h(op1(e14,e12)) = op2(h(e14),h(e12))
        & h(op1(e14,e13)) = op2(h(e14),h(e13))
        & h(op1(e14,e14)) = op2(h(e14),h(e14))
        & j(op2(e20,e20)) = op1(j(e20),j(e20))
        & j(op2(e20,e21)) = op1(j(e20),j(e21))
        & j(op2(e20,e22)) = op1(j(e20),j(e22))
        & j(op2(e20,e23)) = op1(j(e20),j(e23))
        & j(op2(e20,e24)) = op1(j(e20),j(e24))
        & j(op2(e21,e20)) = op1(j(e21),j(e20))
        & j(op2(e21,e21)) = op1(j(e21),j(e21))
        & j(op2(e21,e22)) = op1(j(e21),j(e22))
        & j(op2(e21,e23)) = op1(j(e21),j(e23))
        & j(op2(e21,e24)) = op1(j(e21),j(e24))
        & j(op2(e22,e20)) = op1(j(e22),j(e20))
        & j(op2(e22,e21)) = op1(j(e22),j(e21))
        & j(op2(e22,e22)) = op1(j(e22),j(e22))
        & j(op2(e22,e23)) = op1(j(e22),j(e23))
        & j(op2(e22,e24)) = op1(j(e22),j(e24))
        & j(op2(e23,e20)) = op1(j(e23),j(e20))
        & j(op2(e23,e21)) = op1(j(e23),j(e21))
        & j(op2(e23,e22)) = op1(j(e23),j(e22))
        & j(op2(e23,e23)) = op1(j(e23),j(e23))
        & j(op2(e23,e24)) = op1(j(e23),j(e24))
        & j(op2(e24,e20)) = op1(j(e24),j(e20))
        & j(op2(e24,e21)) = op1(j(e24),j(e21))
        & j(op2(e24,e22)) = op1(j(e24),j(e22))
        & j(op2(e24,e23)) = op1(j(e24),j(e23))
        & j(op2(e24,e24)) = op1(j(e24),j(e24))
        & h(j(e20)) = e20
        & h(j(e21)) = e21
        & h(j(e22)) = e22
        & h(j(e23)) = e23
        & h(j(e24)) = e24
        & j(h(e10)) = e10
        & j(h(e11)) = e11
        & j(h(e12)) = e12
        & j(h(e13)) = e13
        & j(h(e14)) = e14 ) )).

%--------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Axioms&File=AGT001+0.ax
static const std::string fof_test_variables =
    R"***(%------------------------------------------------------------------------------
% File     : AGT001+0 : TPTP v7.2.0. Released v2.7.0.
% Domain   : Agents
% Axioms   : CPlanT system
% Version  : [Bar03] axioms : Especial.
% English  :

% Refs     : [Bar03] Barta, J. (2003), Email to G. Sutcliffe
% Source   : [Bar03]
% Names    :

% Status   : Satisfiable
% Syntax   : Number of formulae    :   20 (   0 unit)
%            Number of atoms       :   98 (   0 equality)
%            Maximal formula depth :    8 (   7 average)
%            Number of connectives :   79 (   1 ~  ;   0  |;  58  &)
%                                         (  14 <=>;   6 =>;   0 <=)
%                                         (   0 <~>;   0 ~|;   0 ~&)
%            Number of predicates  :   10 (   0 propositional; 2-4 arity)
%            Number of functors    :   47 (  47 constant; 0-0 arity)
%            Number of variables   :   35 (   0 singleton;  35 !;   0 ?)
%            Maximal term depth    :    1 (   1 average)
% SPC      : 

% Comments : Requires NUM005+0.ax NUM005+1.ax
%------------------------------------------------------------------------------
fof(a1_1,axiom,
    ( ! [A,C,N,L] :
        ( accept_team(A,L,C,N)
      <=> ( accept_city(A,C)
          & accept_leader(A,L)
          & accept_number(A,N) ) ) )).

fof(a1_2,axiom,
    ( ! [A,N,M] :
        ( ( accept_number(A,N)
          & less(M,N) )
       => accept_number(A,M) ) )).

fof(a1_3,axiom,
    ( ! [A,N,M,P] :
        ( ( accept_population(A,P,N)
          & less(M,N) )
       => accept_population(A,P,M) ) )).

fof(a1_4,axiom,
    ( ! [A,L,C] :
        ( the_agent_in_all_proposed_teams(A,L,C)
       => ( accept_leader(A,L)
          & accept_city(A,C) ) ) )).

fof(a1_5,axiom,
    ( ! [A,L,C] :
        ( any_agent_in_all_proposed_teams(A,L,C)
       => accept_leader(A,L) ) )).

fof(a1_6,axiom,
    ( ! [A,L,C] :
        ( the_agent_not_in_any_proposed_teams(A,L,C)
       => ~ ( accept_city(A,C)
            & accept_leader(A,L) ) ) )).

fof(a1_7,axiom,
    ( ! [A,N] :
        ( min_number_of_proposed_agents(A,N)
       => accept_number(A,N) ) )).

fof(a2_1,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n65)
          & accept_population(A,christian,n20)
          & accept_population(A,muslim,n7)
          & accept_population(A,native,n4)
          & accept_population(A,other,n4) )
      <=> accept_city(A,suffertown) ) )).

fof(a2_2,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n54)
          & accept_population(A,christian,n23)
          & accept_population(A,muslim,n3)
          & accept_population(A,native,n1)
          & accept_population(A,other,n9) )
      <=> accept_city(A,centraltown) ) )).

fof(a2_3,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n30)
          & accept_population(A,christian,n8)
          & accept_population(A,muslim,n60)
          & accept_population(A,native,n1)
          & accept_population(A,other,n1) )
      <=> accept_city(A,sunnysideport) ) )).

fof(a2_4,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n70)
          & accept_population(A,christian,n15)
          & accept_population(A,muslim,n1)
          & accept_population(A,native,n10)
          & accept_population(A,other,n4) )
      <=> accept_city(A,centrallakecity) ) )).

fof(a2_5,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n68)
          & accept_population(A,christian,n16)
          & accept_population(A,muslim,n1)
          & accept_population(A,native,n11)
          & accept_population(A,other,n4) )
      <=> accept_city(A,stjosephburgh) ) )).

fof(a2_6,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n70)
          & accept_population(A,christian,n13)
          & accept_population(A,muslim,n0)
          & accept_population(A,native,n15)
          & accept_population(A,other,n2) )
      <=> accept_city(A,northport) ) )).

fof(a2_7,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n12)
          & accept_population(A,christian,n3)
          & accept_population(A,muslim,n0)
          & accept_population(A,native,n85)
          & accept_population(A,other,n0) )
      <=> accept_city(A,coastvillage) ) )).

fof(a2_8,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n0)
          & accept_population(A,christian,n0)
          & accept_population(A,muslim,n0)
          & accept_population(A,native,n100)
          & accept_population(A,other,n0) )
      <=> accept_city(A,sunsetpoint) ) )).

fof(a2_9,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n75)
          & accept_population(A,christian,n24)
          & accept_population(A,muslim,n1)
          & accept_population(A,native,n0)
          & accept_population(A,other,n0) )
      <=> accept_city(A,towna) ) )).

fof(a2_10,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n75)
          & accept_population(A,christian,n25)
          & accept_population(A,muslim,n0)
          & accept_population(A,native,n0)
          & accept_population(A,other,n0) )
      <=> accept_city(A,citya) ) )).

fof(a2_11,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n70)
          & accept_population(A,christian,n20)
          & accept_population(A,muslim,n8)
          & accept_population(A,native,n0)
          & accept_population(A,other,n2) )
      <=> accept_city(A,townb) ) )).

fof(a2_12,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n78)
          & accept_population(A,christian,n20)
          & accept_population(A,muslim,n1)
          & accept_population(A,native,n0)
          & accept_population(A,other,n1) )
      <=> accept_city(A,cityb) ) )).

fof(a2_13,axiom,
    ( ! [A] :
        ( ( accept_population(A,atheist,n30)
          & accept_population(A,christian,n0)
          & accept_population(A,muslim,n65)
          & accept_population(A,native,n0)
          & accept_population(A,other,n5) )
      <=> accept_city(A,townc) ) )).

%------------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=SYN&File=SYN054+1.p
static const std::string fof_test_existential =
    R"***(%--------------------------------------------------------------------------
% File     : SYN054+1 : TPTP v7.2.0. Released v2.0.0.
% Domain   : Syntactic
% Problem  : Pelletier Problem 24
% Version  : Especial.
% English  :

% Refs     : [KM64]  Kalish & Montegue (1964), Logic: Techniques of Formal
%          : [Pel86] Pelletier (1986), Seventy-five Problems for Testing Au
%          : [Hah94] Haehnle (1994), Email to G. Sutcliffe
% Source   : [Hah94]
% Names    : Pelletier 24 [Pel86]

% Status   : Theorem
% Rating   : 0.00 v5.3.0, 0.09 v5.2.0, 0.00 v2.1.0
% Syntax   : Number of formulae    :    5 (   0 unit)
%            Number of atoms       :   12 (   0 equality)
%            Maximal formula depth :    4 (   4 average)
%            Number of connectives :    9 (   2 ~  ;   2  |;   2  &)
%                                         (   0 <=>;   3 =>;   0 <=)
%                                         (   0 <~>;   0 ~|;   0 ~&)
%            Number of predicates  :    4 (   0 propositional; 1-1 arity)
%            Number of functors    :    0 (   0 constant; --- arity)
%            Number of variables   :    6 (   0 singleton;   2 !;   4 ?)
%            Maximal term depth    :    1 (   1 average)
% SPC      : FOF_THM_EPR

% Comments :
%--------------------------------------------------------------------------
fof(pel24_1,axiom,
    ( ~ ( ? [X] :
            ( big_s(X)
            & big_q(X) ) ) )).

fof(pel24_2,axiom,
    ( ! [X] :
        ( big_p(X)
       => ( big_q(X)
          | big_r(X) ) ) )).

fof(pel24_3,axiom,
    ( ~ ( ? [X] : big_p(X) )
   => ? [Y] : big_q(Y) )).

fof(pel24_4,axiom,
    ( ! [X] :
        ( ( big_q(X)
          | big_r(X) )
       => big_s(X) ) )).

fof(pel24,conjecture,
    ( ? [X] :
        ( big_p(X)
        & big_r(X) ) )).

%--------------------------------------------------------------------------
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

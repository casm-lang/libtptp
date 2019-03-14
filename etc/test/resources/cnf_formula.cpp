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

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=ALG&File=ALG001-1.p
static const std::string cnf_test_basic =
    R"***(%------------------------------------------------------------------------------
% File     : ALG001-1 : TPTP v7.2.0. Released v1.0.0.
% Domain   : General Algebra
% Problem  : The composition of homomorphisms is a homomorphism
% Version  : [BL+86] axioms : Augmented.
% English  :

% Refs     : [BL+86] Boyer et al. (1986), Set Theory in First-Order Logic:
% Source   : [BL+86]
% Names    : Problem 221-223 [BL+86]

% Status   : Unsatisfiable
% Rating   : 0.83 v7.0.0, 1.00 v6.4.0, 0.93 v6.3.0, 0.91 v6.2.0, 0.90 v6.1.0, 1.00 v6.0.0, 0.90 v5.5.0, 1.00 v2.0.0
% Syntax   : Number of clauses     :  171 (  20 non-Horn;  19 unit; 139 RR)
%            Number of atoms       :  430 (  60 equality)
%            Maximal clause size   :    8 (   3 average)
%            Number of predicates  :   14 (   0 propositional; 1-5 arity)
%            Number of functors    :   67 (  14 constant; 0-5 arity)
%            Number of variables   :  388 (  36 singleton)
%            Maximal term depth    :    4 (   1 average)
% SPC      : CNF_UNS_RFO_SEQ_NHN

% Comments : Augmented with previous lemmas.
%------------------------------------------------------------------------------
%----Include Godel's set axioms
include('Axioms/SET003-0.ax').
%------------------------------------------------------------------------------
cnf(first_components_are_equal,axiom,
    ( ~ little_set(X)
    | ~ little_set(U)
    | ordered_pair(X,Y) != ordered_pair(U,V)
    | X = U )).

cnf(left_cancellation,axiom,
    ( ~ little_set(X)
    | ~ little_set(Y)
    | non_ordered_pair(Z,X) != non_ordered_pair(Z,Y)
    | X = Y )).

cnf(second_components_are_equal,axiom,
    ( ~ little_set(X)
    | ~ little_set(Y)
    | ~ little_set(U)
    | ~ little_set(V)
    | ordered_pair(X,Y) != ordered_pair(U,V)
    | Y = V )).

cnf(two_sets_equal,axiom,
    ( ~ subset(X,Y)
    | ~ subset(Y,X)
    | X = Y )).

cnf(property_of_first,axiom,
    ( ~ little_set(X)
    | ~ little_set(Y)
    | first(ordered_pair(X,Y)) = X )).

cnf(property_of_second,axiom,
    ( ~ little_set(X)
    | ~ little_set(Y)
    | second(ordered_pair(X,Y)) = Y )).

cnf(first_component_is_small,axiom,
    ( ~ ordered_pair_predicate(X)
    | little_set(first(X)) )).

cnf(second_component_is_small,axiom,
    ( ~ ordered_pair_predicate(X)
    | little_set(second(X)) )).

cnf(property_of_singleton_sets,axiom,
    ( ~ little_set(X)
    | member(X,singleton_set(X)) )).

cnf(ordered_pairs_are_small1,axiom,
    ( little_set(ordered_pair(X,Y)) )).

cnf(ordered_pairs_are_small2,axiom,
    ( ~ ordered_pair_predicate(X)
    | little_set(X) )).

cnf(containment_is_transitive,axiom,
    ( ~ subset(X,Y)
    | ~ subset(Y,Z)
    | subset(X,Z) )).

cnf(image_and_apply1,axiom,
    ( subset(apply(Xf,Y),sigma(image(singleton_set(Y),Xf))) )).

cnf(image_and_apply2,axiom,
    ( subset(image(singleton_set(Y),Xf),apply(Xf,Y)) )).

cnf(function_values_are_small,axiom,
    ( ~ function(Y)
    | little_set(apply(Y,X)) )).

cnf(composition_is_a_relation,axiom,
    ( relation(compose(Y,X)) )).

cnf(range_of_composition,axiom,
    ( subset(range_of(compose(Y,X)),range_of(Y)) )).

cnf(domain_of_composition,axiom,
    ( ~ subset(range_of(X),domain_of(Y))
    | domain_of(X) = domain_of(compose(Y,X)) )).

cnf(composition_is_a_function,axiom,
    ( ~ function(X)
    | ~ function(Y)
    | function(compose(Y,X)) )).

cnf(maps_for_composition,axiom,
    ( ~ maps(Xf,U,V)
    | ~ maps(Xg,V,W)
    | maps(compose(Xg,Xf),U,W) )).

cnf(apply_for_functions1,axiom,
    ( ~ little_set(X)
    | ~ little_set(Y)
    | ~ function(Xf)
    | ~ member(ordered_pair(X,Y),Xf)
    | apply(Xf,X) = Y )).

cnf(apply_for_functions2,axiom,
    ( ~ function(Xf)
    | ~ member(X,domain_of(Xf))
    | apply(Xf,X) != Y
    | member(ordered_pair(X,Y),Xf) )).

cnf(apply_for_functions3,axiom,
    ( ~ maps(Xf,Xd,Xr)
    | ~ member(X,Xd)
    | member(apply(Xf,X),Xr) )).

cnf(apply_for_composition1,axiom,
    ( ~ function(Xf)
    | ~ member(X,domain_of(Xf))
    | subset(apply(Xg,apply(Xf,X)),apply(compose(Xg,Xf),X)) )).

cnf(apply_for_composition2,axiom,
    ( ~ function(Xf)
    | subset(apply(compose(Xg,Xf),X),apply(Xg,apply(Xf,X))) )).

cnf(apply_for_composition3,axiom,
    ( ~ function(Xf)
    | ~ member(X,domain_of(Xf))
    | apply(Xg,apply(Xf,X)) = apply(compose(Xg,Xf),X) )).

cnf(ordered_pair_in_cross_product,axiom,
    ( ~ member(X,Xs1)
    | ~ member(Y,Xs2)
    | member(ordered_pair(X,Y),cross_product(Xs1,Xs2)) )).

cnf(one_homomorphism,hypothesis,
    ( homomorphism(f60,f62,f63,f64,f65) )).

cnf(another_homomorphism,hypothesis,
    ( homomorphism(f61,f64,f65,f66,f67) )).

cnf(prove_composition_is_a_homomorphism,negated_conjecture,
    ( ~ homomorphism(compose(f60,f61),f62,f63,f66,f67) )).

%------------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Axioms&File=LCL004-0.ax
static const std::string cnf_test_predicates = R"***(
%------------------------------------------------------------------------------
% File     : LCL004-0 : TPTP v7.2.0. Released v2.3.0.
% Domain   : Logic Calculi (Propositional)
% Axioms   : Propositional logic deduction
% Version  : [WR27] axioms.
% English  :

% Refs     : [WR27]  Whitehead & Russell (1927), Principia Mathematica
% Source   : [WR27]
% Names    :

% Status   : Satisfiable
% Syntax   : Number of clauses    :    8 (   0 non-Horn;   6 unit;   2 RR)
%            Number of atoms      :   11 (   1 equality)
%            Maximal clause size  :    3 (   1 average)
%            Number of predicates :    3 (   0 propositional; 1-2 arity)
%            Number of functors   :    3 (   0 constant; 1-2 arity)
%            Number of variables  :   16 (   1 singleton)
%            Maximal term depth   :    4 (   2 average)
% SPC      : 

% Comments : This axiomatization follows [WR27], allowing full detachment
%            but no chaining (which is a dependant theorem). Compare with
%            LCL003-0.ax.
%------------------------------------------------------------------------------
cnf(axiom_1_2,axiom,
    ( axiom(implies(or(A,A),A)) )).

cnf(axiom_1_3,axiom,
    ( axiom(implies(A,or(B,A))) )).

cnf(axiom_1_4,axiom,
    ( axiom(implies(or(A,B),or(B,A))) )).

cnf(axiom_1_5,axiom,
    ( axiom(implies(or(A,or(B,C)),or(B,or(A,C)))) )).

cnf(axiom_1_6,axiom,
    ( axiom(implies(implies(A,B),implies(or(C,A),or(C,B)))) )).

cnf(implies_definition,axiom,
    ( implies(X,Y) = or(not(X),Y) )).

cnf(rule_1,axiom,
    ( theorem(X)
    | ~ axiom(X) )).

cnf(rule_2,axiom,
    ( theorem(X)
    | ~ theorem(implies(Y,X))
    | ~ theorem(Y) )).

% input_clause(rule_3,axiom,
%     [++theorem(implies(X,Z)),
%      --theorem(implies(X,Y)),
%      --theorem(implies(Y,Z))]).
%------------------------------------------------------------------------------
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

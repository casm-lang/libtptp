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

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=AGT&File=AGT027^2.p
static const std::string thf_test_basics =
    R"***(%------------------------------------------------------------------------------
% File     : AGT027^2 : TPTP v7.2.0. Released v5.2.0.
% Domain   : Agents
% Problem  : Two different degrees of belief
% Version  : [Ben11] axioms : Reduced > Complete.
% English  :

% Refs     : [Ben11] Benzmueller (2011), Email to Geoff Sutcliffe
%          : [Ben11] Benzmueller (2011), Combining and Automating Classical
% Source   : [Ben11]
% Names    : Ex_10_1_KI4s [Ben11]

% Status   : Theorem
% Rating   : 0.78 v7.2.0, 0.75 v7.1.0, 0.88 v7.0.0, 0.86 v6.4.0, 0.83 v6.3.0, 0.80 v6.2.0, 0.71 v6.1.0, 0.57 v6.0.0, 0.86 v5.5.0, 0.83 v5.4.0, 0.80 v5.3.0, 1.00 v5.2.0
% Syntax   : Number of formulae    :   81 (   0 unit;  40 type;  31 defn)
%            Number of atoms       :  320 (  36 equality; 148 variable)
%            Maximal formula depth :   11 (   6 average)
%            Number of connectives :  211 (   4   ~;   4   |;   8   &; 187   @)
%                                         (   0 <=>;   8  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of type conns  :  185 ( 185   >;   0   *;   0   +;   0  <<)
%            Number of symbols     :   44 (  40   :;   0   =)
%            Number of variables   :   93 (   3 sgn;  29   !;   6   ?;  58   ^)
%                                         (  93   :;   0  !>;   0  ?*)
%                                         (   0  @-;   0  @+)
% SPC      : TH0_THM_EQU_NAR

% Comments : 
%------------------------------------------------------------------------------
%----Include embedding of quantified multimodal logic in simple type theory
include('Axioms/LCL013^0.ax').
%------------------------------------------------------------------------------
thf(a1,type,(
    a1: $i > $i > $o )).

thf(a2,type,(
    a2: $i > $i > $o )).

thf(a,type,(
    a: mu )).

thf(tom,type,(
    tom: mu )).

thf(p,type,(
    p: mu > $i > $o )).

thf(q,type,(
    q: mu > $i > $o )).

thf(r,type,(
    r: mu > $i > $o )).

thf(s,type,(
    s: mu > $i > $o )).

thf(axiom_a1,axiom,
    ( mvalid
    @ ( mforall_ind
      @ ^ [X: mu] :
          ( mbox @ a2 @ ( mimplies @ ( mdia @ a2 @ ( q @ X ) ) @ ( p @ X ) ) ) ) )).

thf(axiom_a2,axiom,
    ( mvalid
    @ ( mforall_ind
      @ ^ [X: mu] :
          ( mbox @ a1 @ ( mimplies @ ( mand @ ( r @ X ) @ ( s @ X ) ) @ ( q @ X ) ) ) ) )).

thf(axiom_a3,axiom,
    ( mvalid
    @ ( mforall_ind
      @ ^ [X: mu] :
          ( mbox @ a1 @ ( mimplies @ ( s @ X ) @ ( mbox @ a1 @ ( r @ X ) ) ) ) ) )).

thf(axiom_a4,axiom,
    ( mvalid @ ( mdia @ a1 @ ( s @ a ) ) )).

thf(axiom_I_for_a2_a1,axiom,
    ( mvalid
    @ ( mforall_prop
      @ ^ [Phi: $i > $o] :
          ( mimplies @ ( mbox @ a2 @ Phi ) @ ( mbox @ a1 @ Phi ) ) ) )).

thf(axiom_4s_for_a1_a1,axiom,
    ( mvalid
    @ ( mforall_prop
      @ ^ [Phi: $i > $o] :
          ( mimplies @ ( mbox @ a1 @ Phi ) @ ( mbox @ a1 @ ( mbox @ a1 @ Phi ) ) ) ) )).

thf(axiom_4s_for_a1_a2,axiom,
    ( mvalid
    @ ( mforall_prop
      @ ^ [Phi: $i > $o] :
          ( mimplies @ ( mbox @ a1 @ Phi ) @ ( mbox @ a2 @ ( mbox @ a1 @ Phi ) ) ) ) )).

thf(axiom_4s_for_a2_a1,axiom,
    ( mvalid
    @ ( mforall_prop
      @ ^ [Phi: $i > $o] :
          ( mimplies @ ( mbox @ a2 @ Phi ) @ ( mbox @ a1 @ ( mbox @ a2 @ Phi ) ) ) ) )).

thf(axiom_4s_for_a2_a2,axiom,
    ( mvalid
    @ ( mforall_prop
      @ ^ [Phi: $i > $o] :
          ( mimplies @ ( mbox @ a2 @ Phi ) @ ( mbox @ a2 @ ( mbox @ a2 @ Phi ) ) ) ) )).

thf(conj,conjecture,
    ( mvalid
    @ ( mexists_ind
      @ ^ [X: mu] :
          ( mbox @ a1 @ ( p @ X ) ) ) )).

%------------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=GRA&File=GRA045^2.p
static const std::string thf_test_depth =
    R"***(%------------------------------------------------------------------------------
% File     : GRA045^2 : TPTP v7.2.0. Released v3.6.0.
% Domain   : Graph Theory
% Problem  : R(5,9) <= 256
% Version  : Especial.
% English  :

% Refs     : [Rad06] Radziszowski (2006), Small Ramsey Numbers
%          : [Bro08] Brown (2008), Email to G. Sutcliffe
% Source   : [Bro08]
% Names    :

% Status   : Open
% Rating   : 1.00 v3.7.0
% Syntax   : Number of formulae    :    1 (   0 unit;   0 type;   0 defn)
%            Number of atoms       :  328 (   0 equality; 328 variable)
%            Maximal formula depth :  131 ( 131 average)
%            Number of connectives :  443 ( 116   ~;   1   |; 136   &; 188   @)
%                                         (   0 <=>;   2  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of type conns  :  104 ( 104   >;   0   *;   0   +;   0  <<)
%            Number of symbols     :    1 (   0   :;   0   =)
%            Number of variables   :   29 (   0 sgn;   3   !;  26   ?;   0   ^)
%                                         (  29   :;   0  !>;   0  ?*)
%                                         (   0  @-;   0  @+)
% SPC      : TH0_OPN_NEQ_NAR

% Comments : If a type alpha has exactly n elements, then we can prove
%            R(k,l) > n by finding a graph (symmetric binary relation) on type
%            alpha with no k-cliques and no l-independent sets. Likewise, we
%            can prove R(k,l) <= n by proving every graph (symmetric binary
%            relation) on alpha must have a k-clique or l-independent set.
%            There is one type with 4 elements: o > o. There are two types
%            with 16 elements: o > o > o and (o > o) > o. There are two types
%            with 256 elements: o > o > o > o and o > (o > o) > o.  This means
%            we always have two formulations of R(k,l) >/<= 16 and two
%            formulations of R(k,l) >/<= 256.
%          : 
%------------------------------------------------------------------------------
thf(ramsey_u_5_9_256a,conjecture,(
    ! [G: ( $o > ( $o > $o ) > $o ) > ( $o > ( $o > $o ) > $o ) > $o] :
      ( ! [Xx: $o > ( $o > $o ) > $o,Xy: $o > ( $o > $o ) > $o] :
          ( ( G @ Xx @ Xy )
         => ( G @ Xy @ Xx ) )
     => ( ? [Xx0: $o > ( $o > $o ) > $o,Xx1: $o > ( $o > $o ) > $o,Xx2: $o > ( $o > $o ) > $o,Xx3: $o > ( $o > $o ) > $o,Xx4: $o > ( $o > $o ) > $o,Xp0: ( $o > ( $o > $o ) > $o ) > $o,Xp1: ( $o > ( $o > $o ) > $o ) > $o,Xp2: ( $o > ( $o > $o ) > $o ) > $o,Xp3: ( $o > ( $o > $o ) > $o ) > $o] :
            ( ( Xp0 @ Xx0 )
            & ~ ( Xp0 @ Xx1 )
            & ~ ( Xp0 @ Xx2 )
            & ~ ( Xp0 @ Xx3 )
            & ~ ( Xp0 @ Xx4 )
            & ~ ( Xp1 @ Xx0 )
            & ( Xp1 @ Xx1 )
            & ~ ( Xp1 @ Xx2 )
            & ~ ( Xp1 @ Xx3 )
            & ~ ( Xp1 @ Xx4 )
            & ~ ( Xp2 @ Xx0 )
            & ~ ( Xp2 @ Xx1 )
            & ( Xp2 @ Xx2 )
            & ~ ( Xp2 @ Xx3 )
            & ~ ( Xp2 @ Xx4 )
            & ~ ( Xp3 @ Xx0 )
            & ~ ( Xp3 @ Xx1 )
            & ~ ( Xp3 @ Xx2 )
            & ( Xp3 @ Xx3 )
            & ~ ( Xp3 @ Xx4 )
            & ( G @ Xx1 @ Xx0 )
            & ( G @ Xx2 @ Xx0 )
            & ( G @ Xx2 @ Xx1 )
            & ( G @ Xx3 @ Xx0 )
            & ( G @ Xx3 @ Xx1 )
            & ( G @ Xx3 @ Xx2 )
            & ( G @ Xx4 @ Xx0 )
            & ( G @ Xx4 @ Xx1 )
            & ( G @ Xx4 @ Xx2 )
            & ( G @ Xx4 @ Xx3 ) )
        | ? [Xx0: $o > ( $o > $o ) > $o,Xx1: $o > ( $o > $o ) > $o,Xx2: $o > ( $o > $o ) > $o,Xx3: $o > ( $o > $o ) > $o,Xx4: $o > ( $o > $o ) > $o,Xx5: $o > ( $o > $o ) > $o,Xx6: $o > ( $o > $o ) > $o,Xx7: $o > ( $o > $o ) > $o,Xx8: $o > ( $o > $o ) > $o,Xp0: ( $o > ( $o > $o ) > $o ) > $o,Xp1: ( $o > ( $o > $o ) > $o ) > $o,Xp2: ( $o > ( $o > $o ) > $o ) > $o,Xp3: ( $o > ( $o > $o ) > $o ) > $o,Xp4: ( $o > ( $o > $o ) > $o ) > $o,Xp5: ( $o > ( $o > $o ) > $o ) > $o,Xp6: ( $o > ( $o > $o ) > $o ) > $o,Xp7: ( $o > ( $o > $o ) > $o ) > $o] :
            ( ( Xp0 @ Xx0 )
            & ~ ( Xp0 @ Xx1 )
            & ~ ( Xp0 @ Xx2 )
            & ~ ( Xp0 @ Xx3 )
            & ~ ( Xp0 @ Xx4 )
            & ~ ( Xp0 @ Xx5 )
            & ~ ( Xp0 @ Xx6 )
            & ~ ( Xp0 @ Xx7 )
            & ~ ( Xp0 @ Xx8 )
            & ~ ( Xp1 @ Xx0 )
            & ( Xp1 @ Xx1 )
            & ~ ( Xp1 @ Xx2 )
            & ~ ( Xp1 @ Xx3 )
            & ~ ( Xp1 @ Xx4 )
            & ~ ( Xp1 @ Xx5 )
            & ~ ( Xp1 @ Xx6 )
            & ~ ( Xp1 @ Xx7 )
            & ~ ( Xp1 @ Xx8 )
            & ~ ( Xp2 @ Xx0 )
            & ~ ( Xp2 @ Xx1 )
            & ( Xp2 @ Xx2 )
            & ~ ( Xp2 @ Xx3 )
            & ~ ( Xp2 @ Xx4 )
            & ~ ( Xp2 @ Xx5 )
            & ~ ( Xp2 @ Xx6 )
            & ~ ( Xp2 @ Xx7 )
            & ~ ( Xp2 @ Xx8 )
            & ~ ( Xp3 @ Xx0 )
            & ~ ( Xp3 @ Xx1 )
            & ~ ( Xp3 @ Xx2 )
            & ( Xp3 @ Xx3 )
            & ~ ( Xp3 @ Xx4 )
            & ~ ( Xp3 @ Xx5 )
            & ~ ( Xp3 @ Xx6 )
            & ~ ( Xp3 @ Xx7 )
            & ~ ( Xp3 @ Xx8 )
            & ~ ( Xp4 @ Xx0 )
            & ~ ( Xp4 @ Xx1 )
            & ~ ( Xp4 @ Xx2 )
            & ~ ( Xp4 @ Xx3 )
            & ( Xp4 @ Xx4 )
            & ~ ( Xp4 @ Xx5 )
            & ~ ( Xp4 @ Xx6 )
            & ~ ( Xp4 @ Xx7 )
            & ~ ( Xp4 @ Xx8 )
            & ~ ( Xp5 @ Xx0 )
            & ~ ( Xp5 @ Xx1 )
            & ~ ( Xp5 @ Xx2 )
            & ~ ( Xp5 @ Xx3 )
            & ~ ( Xp5 @ Xx4 )
            & ( Xp5 @ Xx5 )
            & ~ ( Xp5 @ Xx6 )
            & ~ ( Xp5 @ Xx7 )
            & ~ ( Xp5 @ Xx8 )
            & ~ ( Xp6 @ Xx0 )
            & ~ ( Xp6 @ Xx1 )
            & ~ ( Xp6 @ Xx2 )
            & ~ ( Xp6 @ Xx3 )
            & ~ ( Xp6 @ Xx4 )
            & ~ ( Xp6 @ Xx5 )
            & ( Xp6 @ Xx6 )
            & ~ ( Xp6 @ Xx7 )
            & ~ ( Xp6 @ Xx8 )
            & ~ ( Xp7 @ Xx0 )
            & ~ ( Xp7 @ Xx1 )
            & ~ ( Xp7 @ Xx2 )
            & ~ ( Xp7 @ Xx3 )
            & ~ ( Xp7 @ Xx4 )
            & ~ ( Xp7 @ Xx5 )
            & ~ ( Xp7 @ Xx6 )
            & ( Xp7 @ Xx7 )
            & ~ ( Xp7 @ Xx8 )
            & ~ ( G @ Xx1 @ Xx0 )
            & ~ ( G @ Xx2 @ Xx0 )
            & ~ ( G @ Xx2 @ Xx1 )
            & ~ ( G @ Xx3 @ Xx0 )
            & ~ ( G @ Xx3 @ Xx1 )
            & ~ ( G @ Xx3 @ Xx2 )
            & ~ ( G @ Xx4 @ Xx0 )
            & ~ ( G @ Xx4 @ Xx1 )
            & ~ ( G @ Xx4 @ Xx2 )
            & ~ ( G @ Xx4 @ Xx3 )
            & ~ ( G @ Xx5 @ Xx0 )
            & ~ ( G @ Xx5 @ Xx1 )
            & ~ ( G @ Xx5 @ Xx2 )
            & ~ ( G @ Xx5 @ Xx3 )
            & ~ ( G @ Xx5 @ Xx4 )
            & ~ ( G @ Xx6 @ Xx0 )
            & ~ ( G @ Xx6 @ Xx1 )
            & ~ ( G @ Xx6 @ Xx2 )
            & ~ ( G @ Xx6 @ Xx3 )
            & ~ ( G @ Xx6 @ Xx4 )
            & ~ ( G @ Xx6 @ Xx5 )
            & ~ ( G @ Xx7 @ Xx0 )
            & ~ ( G @ Xx7 @ Xx1 )
            & ~ ( G @ Xx7 @ Xx2 )
            & ~ ( G @ Xx7 @ Xx3 )
            & ~ ( G @ Xx7 @ Xx4 )
            & ~ ( G @ Xx7 @ Xx5 )
            & ~ ( G @ Xx7 @ Xx6 )
            & ~ ( G @ Xx8 @ Xx0 )
            & ~ ( G @ Xx8 @ Xx1 )
            & ~ ( G @ Xx8 @ Xx2 )
            & ~ ( G @ Xx8 @ Xx3 )
            & ~ ( G @ Xx8 @ Xx4 )
            & ~ ( G @ Xx8 @ Xx5 )
            & ~ ( G @ Xx8 @ Xx6 )
            & ~ ( G @ Xx8 @ Xx7 ) ) ) ) )).

%------------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=ANA&File=ANA070^1.p
static const std::string thf_test_th1 =
    R"***(%------------------------------------------------------------------------------
% File     : ANA070^1 : TPTP v7.2.0. Released v7.0.0.
% Domain   : Analysis
% Problem  : REAL_SUP_LE_FINITE
% Version  : Especial.
% English  :

% Refs     : [Kal16] Kalisyk (2016), Email to Geoff Sutcliffe
% Source   : [Kal16]
% Names    : REAL_SUP_LE_FINITE_.p [Kal16]

% Status   : Theorem
% Rating   : 0.00 v7.1.0
% Syntax   : Number of formulae    :    9 (   0 unit;   6 type;   0 defn)
%            Number of atoms       :   48 (   3 equality;  22 variable)
%            Maximal formula depth :   10 (   6 average)
%            Number of connectives :   41 (   2   ~;   0   |;   4   &;  30   @)
%                                         (   0 <=>;   5  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of type conns  :   12 (  12   >;   0   *;   0   +;   0  <<)
%            Number of symbols     :    8 (   6   :;   0   =;   0  @=)
%                                         (   0  !!;   0  ??;   0 @@+;   0 @@-)
%            Number of variables   :   11 (   0 sgn;   8   !;   0   ?;   0   ^)
%                                         (  11   :;   3  !>;   0  ?*)
%                                         (   0  @-;   0  @+)
% SPC      : TH1_THM_EQU_NAR

% Comments : Exported from core HOL Light.
%------------------------------------------------------------------------------
thf('thf_type_type/realax/real',type,(
    'type/realax/real': $tType )).

thf('thf_const_const/sets/sup',type,(
    'const/sets/sup': ( 'type/realax/real' > $o ) > 'type/realax/real' )).

thf('thf_const_const/sets/IN',type,(
    'const/sets/IN': 
      !>[A: $tType] :
        ( A > ( A > $o ) > $o ) )).

thf('thf_const_const/sets/FINITE',type,(
    'const/sets/FINITE': 
      !>[A: $tType] :
        ( ( A > $o ) > $o ) )).

thf('thf_const_const/sets/EMPTY',type,(
    'const/sets/EMPTY': 
      !>[A: $tType] :
        ( A > $o ) )).

thf('thf_const_const/realax/real_le',type,(
    'const/realax/real_le': 'type/realax/real' > 'type/realax/real' > $o )).

thf('thm/realax/REAL_LE_TRANS_',axiom,(
    ! [A: 'type/realax/real',A0: 'type/realax/real',A1: 'type/realax/real'] :
      ( ( ( 'const/realax/real_le' @ A @ A0 )
        & ( 'const/realax/real_le' @ A0 @ A1 ) )
     => ( 'const/realax/real_le' @ A @ A1 ) ) )).

thf('thm/sets/SUP_FINITE_',axiom,(
    ! [A: 'type/realax/real' > $o] :
      ( ( ( 'const/sets/FINITE' @ 'type/realax/real' @ A )
        & ( A
         != ( 'const/sets/EMPTY' @ 'type/realax/real' ) ) )
     => ( ( 'const/sets/IN' @ 'type/realax/real' @ ( 'const/sets/sup' @ A ) @ A )
        & ! [A0: 'type/realax/real'] :
            ( ( 'const/sets/IN' @ 'type/realax/real' @ A0 @ A )
           => ( 'const/realax/real_le' @ A0 @ ( 'const/sets/sup' @ A ) ) ) ) ) )).

thf('thm/sets/REAL_SUP_LE_FINITE_',conjecture,(
    ! [A: 'type/realax/real' > $o,A0: 'type/realax/real'] :
      ( ( ( 'const/sets/FINITE' @ 'type/realax/real' @ A )
        & ( A
         != ( 'const/sets/EMPTY' @ 'type/realax/real' ) ) )
     => ( ( 'const/realax/real_le' @ ( 'const/sets/sup' @ A ) @ A0 )
        = ( ! [A1: 'type/realax/real'] :
              ( ( 'const/sets/IN' @ 'type/realax/real' @ A1 @ A )
             => ( 'const/realax/real_le' @ A1 @ A0 ) ) ) ) ) )).

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

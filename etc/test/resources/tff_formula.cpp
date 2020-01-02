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

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=COM&File=COM003_1.p
static const std::string tff_test_basic =
    R"***(%--------------------------------------------------------------------------
% File     : COM003_1 : TPTP v7.2.0. Released v5.0.0.
% Domain   : Computing Theory
% Problem  : The halting problem is undecidable
% Version  : [Bur87b] axioms.
% English  :

% Refs     : [Bur87a] Burkholder (1987), The Halting Problem
%          : [Bur87b] Burkholder (1987), A 76th Automated Theorem Proving Pr
% Source   : [TPTP]
% Names    : 

% Status   : Theorem
% Rating   : 0.00 v6.0.0, 0.33 v5.5.0, 0.00 v5.3.0, 0.33 v5.2.0, 0.67 v5.1.0, 1.00 v5.0.0
% Syntax   : Number of formulae    :   17 (   1 unit;  12 type)
%            Number of atoms       :   33 (   0 equality)
%            Maximal formula depth :   10 (   4 average)
%            Number of connectives :   35 (   7   ~;   0   |;  14   &)
%                                         (   0 <=>;  14  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of type conns  :   12 (   6   >;   6   *;   0   +;   0  <<)
%            Number of predicates  :   18 (  14 propositional; 0-3 arity)
%            Number of functors    :    4 (   2 constant; 0-1 arity)
%            Number of variables   :   22 (   0 sgn;  15   !;   7   ?)
%                                         (  22   :;   0  !>;   0  ?*)
%            Maximal term depth    :    2 (   1 average)
% SPC      : TF0_THM_NEQ_NAR

% Comments :
%--------------------------------------------------------------------------
tff(program_type,type,(
    program: $tType )).

tff(algorithm_type,type,(
    algorithm: $tType )).

tff(input_type,type,(
    input: $tType )).

tff(output_type,type,(
    output: $tType )).

tff(bad_type,type,(
    bad: output )).

tff(good_type,type,(
    good: output )).

tff(decides_type,type,(
    decides: ( algorithm * program * input ) > $o )).

tff(halts2_type,type,(
    halts2: ( program * input ) > $o )).

tff(halts3_type,type,(
    halts3: ( program * program * input ) > $o )).

tff(outputs_type,type,(
    outputs: ( program * output ) > $o )).

tff(algorithm_of_type,type,(
    algorithm_of: program > algorithm )).

tff(as_input_type,type,(
    as_input: program > input )).

tff(p1,axiom,
    ( ? [X: algorithm] :
      ! [Y: program,Z: input] : decides(X,Y,Z)
   => ? [W: program] :
      ! [Y: program,Z: input] : decides(algorithm_of(W),Y,Z) )).

tff(p2,axiom,(
    ! [W: program,Y: program,Z: input] :
      ( decides(algorithm_of(W),Y,Z)
     => ! [Y: program,Z: input] :
          ( ( halts2(Y,Z)
           => ( halts3(W,Y,Z)
              & outputs(W,good) ) )
          & ( ~ halts2(Y,Z)
           => ( halts3(W,Y,Z)
              & outputs(W,bad) ) ) ) ) )).

tff(p3,axiom,
    ( ? [W: program] :
      ! [Y: program] :
        ( ( halts2(Y,as_input(Y))
         => ( halts3(W,Y,as_input(Y))
            & outputs(W,good) ) )
        & ( ~ halts2(Y,as_input(Y))
         => ( halts3(W,Y,as_input(Y))
            & outputs(W,bad) ) ) )
   => ? [V: program] :
      ! [Y: program] :
        ( ( halts2(Y,as_input(Y))
         => ( halts2(V,as_input(Y))
            & outputs(V,good) ) )
        & ( ~ halts2(Y,as_input(Y))
         => ( halts2(V,as_input(Y))
            & outputs(V,bad) ) ) ) )).

tff(p4,axiom,
    ( ? [V: program] :
      ! [Y: program] :
        ( ( halts2(Y,as_input(Y))
         => ( halts2(V,as_input(Y))
            & outputs(V,good) ) )
        & ( ~ halts2(Y,as_input(Y))
         => ( halts2(V,as_input(Y))
            & outputs(V,bad) ) ) )
   => ? [U: program] :
      ! [Y: program] :
        ( ( halts2(Y,as_input(Y))
         => ~ halts2(U,as_input(Y)) )
        & ( ~ halts2(Y,as_input(Y))
         => ( halts2(U,as_input(Y))
            & outputs(U,bad) ) ) ) )).

tff(prove_this,conjecture,(
    ~ ? [X1: algorithm] :
      ! [Y1: program,Z1: input] : decides(X1,Y1,Z1) )).

%--------------------------------------------------------------------------
)***";

// http://www.tptp.org/cgi-bin/SeeTPTP?Category=Problems&Domain=SWW&File=SWW516_5.p
static const std::string tff_test_tf1 =
    R"***(%------------------------------------------------------------------------------
% File     : SWW516_5 : TPTP v7.2.0. Released v6.0.0.
% Domain   : Software Verification
% Problem  : Hoare's Logic with Procedures line 253
% Version  : Especial.
% English  : 

% Refs     : [BN10]  Boehme & Nipkow (2010), Sledgehammer: Judgement Day
%          : [Bla13] Blanchette (2011), Email to Geoff Sutcliffe
% Source   : [Bla13]
% Names    : hoare_253 [Bla13]

% Status   : Unknown
% Rating   : 1.00 v6.4.0
% Syntax   : Number of formulae    :  142 (  64 unit;  41 type)
%            Number of atoms       :  181 (  89 equality)
%            Maximal formula depth :   13 (   6 average)
%            Number of connectives :  139 (  59   ~;   3   |;  13   &)
%                                         (  10 <=>;  54  =>;   0  <=;   0 <~>)
%                                         (   0  ~|;   0  ~&)
%            Number of type conns  :   68 (  25   >;  43   *;   0   +;   0  <<)
%            Number of predicates  :   57 (  46 propositional; 0-4 arity)
%            Number of functors    :   33 (  14 constant; 0-10 arity)
%            Number of variables   :  482 (   2 sgn; 462   !;   2   ?)
%                                         ( 482   :;  18  !>;   0  ?*)
%            Maximal term depth    :   10 (   2 average)
% SPC      : TF1_UNK_EQU_NAR

% Comments : This file was generated by Isabelle (most likely Sledgehammer)
%            2011-12-13 16:18:44
%------------------------------------------------------------------------------
%----Should-be-implicit typings (10)
tff(ty_t_a,type,(
    a: $tType )).

tff(ty_tc_Com_Ocom,type,(
    com: $tType )).

tff(ty_tc_Com_Oloc,type,(
    loc: $tType )).

tff(ty_tc_Com_Opname,type,(
    pname: $tType )).

tff(ty_tc_Com_Ostate,type,(
    state: $tType )).

tff(ty_tc_Com_Ovname,type,(
    vname: $tType )).

tff(ty_tc_HOL_Obool,type,(
    bool: $tType )).

tff(ty_tc_Hoare__Mirabelle__vtrypsmcwp_Otriple,type,(
    hoare_28830079triple: $tType > $tType )).

tff(ty_tc_Nat_Onat,type,(
    nat: $tType )).

tff(ty_tc_fun,type,(
    fun: ( $tType * $tType ) > $tType )).

%----Explicit typings (31)
tff(sy_cl_Rings_Osemiring__1,type,(
    semiring_1: 
      !>[A2: $tType] : $o )).

tff(sy_c_Com_OWT,type,(
    wt: com > $o )).

tff(sy_c_Com_Ocom_OAss,type,(
    ass: ( vname * fun(state,nat) ) > com )).

tff(sy_c_Com_Ocom_OCond,type,(
    cond: ( fun(state,bool) * com * com ) > com )).

tff(sy_c_Com_Ocom_OLocal,type,(
    local: ( loc * fun(state,nat) * com ) > com )).

tff(sy_c_Com_Ocom_OSKIP,type,(
    skip: com )).

tff(sy_c_Com_Ocom_OSemi,type,(
    semi: ( com * com ) > com )).

tff(sy_c_Com_Ocom_OWhile,type,(
    while: ( fun(state,bool) * com ) > com )).

tff(sy_c_Com_Ocom_Ocom__case,type,(
    com_case: 
      !>[T3: $tType] :
        ( ( T3 * fun(vname,fun(fun(state,nat),T3)) * fun(loc,fun(fun(state,nat),fun(com,T3))) * fun(com,fun(com,T3)) * fun(fun(state,bool),fun(com,fun(com,T3))) * fun(fun(state,bool),fun(com,T3)) * fun(pname,T3) * fun(vname,fun(pname,fun(fun(state,nat),T3))) * com ) > T3 ) )).

tff(sy_c_Com_Ocom_Ocom__rec,type,(
    com_rec: 
      !>[T3: $tType] :
        ( ( T3 * fun(vname,fun(fun(state,nat),T3)) * fun(loc,fun(fun(state,nat),fun(com,fun(T3,T3)))) * fun(com,fun(com,fun(T3,fun(T3,T3)))) * fun(fun(state,bool),fun(com,fun(com,fun(T3,fun(T3,T3))))) * fun(fun(state,bool),fun(com,fun(T3,T3))) * fun(pname,T3) * fun(vname,fun(pname,fun(fun(state,nat),T3))) * com ) > T3 ) )).

tff(sy_c_Groups_Ozero__class_Ozero,type,(
    zero_zero: 
      !>[A2: $tType] : A2 )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Ohoare__valids,type,(
    hoare_592965047valids: 
      !>[A2: $tType] :
        ( ( fun(hoare_28830079triple(A2),bool) * fun(hoare_28830079triple(A2),bool) ) > $o ) )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Otriple_Otriple,type,(
    hoare_1841697145triple: 
      !>[A2: $tType] :
        ( ( fun(A2,fun(state,bool)) * com * fun(A2,fun(state,bool)) ) > hoare_28830079triple(A2) ) )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Otriple_Otriple__case,type,(
    hoare_376461865e_case: 
      !>[A2: $tType,T3: $tType] :
        ( ( fun(fun(A2,fun(state,bool)),fun(com,fun(fun(A2,fun(state,bool)),T3))) * hoare_28830079triple(A2) ) > T3 ) )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Otriple_Otriple__rec,type,(
    hoare_678420151le_rec: 
      !>[A2: $tType,T3: $tType] :
        ( ( fun(fun(A2,fun(state,bool)),fun(com,fun(fun(A2,fun(state,bool)),T3))) * hoare_28830079triple(A2) ) > T3 ) )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Otriple_Otriple__size,type,(
    hoare_47506394e_size: 
      !>[A2: $tType] :
        ( ( fun(A2,nat) * hoare_28830079triple(A2) ) > nat ) )).

tff(sy_c_Hoare__Mirabelle__vtrypsmcwp_Otriple__valid,type,(
    hoare_1633586161_valid: 
      !>[A2: $tType] :
        ( ( nat * hoare_28830079triple(A2) ) > $o ) )).

tff(sy_c_Nat_OSuc,type,(
    suc: nat > nat )).

tff(sy_c_Nat_Onat_Onat__case,type,(
    nat_case: 
      !>[T3: $tType] :
        ( ( T3 * fun(nat,T3) * nat ) > T3 ) )).

tff(sy_c_Nat_Onat_Onat__rec,type,(
    nat_rec: 
      !>[T3: $tType] :
        ( ( T3 * fun(nat,fun(T3,T3)) * nat ) > T3 ) )).

tff(sy_c_Nat_Osemiring__1__class_Oof__nat__aux,type,(
    semiri532925092at_aux: 
      !>[A2: $tType] :
        ( ( fun(A2,A2) * nat * A2 ) > A2 ) )).

tff(sy_c_Natural_Oevaln,type,(
    evaln: ( com * state * nat * state ) > $o )).

tff(sy_c_aa,type,(
    aa: 
      !>[A2: $tType,B: $tType] :
        ( ( fun(A2,B) * A2 ) > B ) )).

tff(sy_c_fFalse,type,(
    fFalse: bool )).

tff(sy_c_fTrue,type,(
    fTrue: bool )).

tff(sy_c_member,type,(
    member: 
      !>[A2: $tType] :
        ( ( A2 * fun(A2,bool) ) > $o ) )).

tff(sy_c_pp,type,(
    pp: bool > $o )).

tff(sy_v_G,type,(
    g: fun(hoare_28830079triple(a),bool) )).

tff(sy_v_P,type,(
    p: ( a * state ) > $o )).

tff(sy_v_b,type,(
    b: fun(state,bool) )).

tff(sy_v_c,type,(
    c: com )).

%----Relevant facts (96)
tff(fact_0_evaln_OWhileFalse,axiom,(
    ! [N2: nat,Ca: com,S4: state,Ba: fun(state,bool)] :
      ( ~ pp(aa(state,bool,Ba,S4))
     => evaln(while(Ba,Ca),S4,N2,S4) ) )).

tff(fact_1_evaln_OWhileTrue,axiom,(
    ! [S22: state,S11: state,N2: nat,Ca: com,S01: state,Ba: fun(state,bool)] :
      ( pp(aa(state,bool,Ba,S01))
     => ( evaln(Ca,S01,N2,S11)
       => ( evaln(while(Ba,Ca),S11,N2,S22)
         => evaln(while(Ba,Ca),S01,N2,S22) ) ) ) )).

tff(fact_2_com_Osimps_I5_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool),Com: com,Fun: fun(state,bool)] :
      ( while(Fun,Com) = while(Fun3,Com3)
    <=> ( Fun = Fun3
        & Com = Com3 ) ) )).

tff(fact_3_evaln__WHILE__case,axiom,(
    ! [T: state,N2: nat,S4: state,Ca: com,Ba: fun(state,bool)] :
      ( evaln(while(Ba,Ca),S4,N2,T)
     => ( ( T = S4
         => pp(aa(state,bool,Ba,S4)) )
       => ~ ( pp(aa(state,bool,Ba,S4))
           => ! [S12: state] :
                ( evaln(Ca,S4,N2,S12)
               => ~ evaln(while(Ba,Ca),S12,N2,T) ) ) ) ) )).

tff(fact_4_triple__valid__def2,axiom,(
    ! [B: $tType,Q: fun(B,fun(state,bool)),Ca: com,Pa: fun(B,fun(state,bool)),N2: nat] :
      ( hoare_1633586161_valid(B,N2,hoare_1841697145triple(B,Pa,Ca,Q))
    <=> ! [Z2: B,S7: state] :
          ( pp(aa(state,bool,aa(B,fun(state,bool),Pa,Z2),S7))
         => ! [S8: state] :
              ( evaln(Ca,S7,N2,S8)
             => pp(aa(state,bool,aa(B,fun(state,bool),Q,Z2),S8)) ) ) ) )).

tff(fact_5_evaln__max2,axiom,(
    ! [T2: state,N21: nat,S21: state,C21: com,T11: state,N11: nat,S13: state,C1: com] :
      ( evaln(C1,S13,N11,T11)
     => ( evaln(C21,S21,N21,T2)
       => ? [N: nat] :
            ( evaln(C1,S13,N,T11)
            & evaln(C21,S21,N,T2) ) ) ) )).

tff(fact_6_triple__valid__Suc,axiom,(
    ! [A2: $tType,T1: hoare_28830079triple(A2),N3: nat] :
      ( hoare_1633586161_valid(A2,suc(N3),T1)
     => hoare_1633586161_valid(A2,N3,T1) ) )).

tff(fact_7_hoare__valids__def,axiom,(
    ! [B: $tType,Ts: fun(hoare_28830079triple(B),bool),Ga: fun(hoare_28830079triple(B),bool)] :
      ( hoare_592965047valids(B,Ga,Ts)
    <=> ! [N4: nat] :
          ( ! [X5: hoare_28830079triple(B)] :
              ( member(hoare_28830079triple(B),X5,Ga)
             => hoare_1633586161_valid(B,N4,X5) )
         => ! [X5: hoare_28830079triple(B)] :
              ( member(hoare_28830079triple(B),X5,Ts)
             => hoare_1633586161_valid(B,N4,X5) ) ) ) )).

tff(fact_8_com_Osimps_I69_J,axiom,(
    ! [B: $tType,Com: com,Fun: fun(state,bool),F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,while(Fun,Com)) = aa(com,B,aa(fun(state,bool),fun(com,B),F6,Fun),Com) )).

tff(fact_9_evaln_OSkip,axiom,(
    ! [N3: nat,S5: state] : evaln(skip,S5,N3,S5) )).

tff(fact_10_evaln__elim__cases_I1_J,axiom,(
    ! [T1: state,N3: nat,S5: state] :
      ( evaln(skip,S5,N3,T1)
     => T1 = S5 ) )).

tff(fact_11_evaln_OSemi,axiom,(
    ! [S21: state,C1: com,S13: state,N3: nat,S0: state,C0: com] :
      ( evaln(C0,S0,N3,S13)
     => ( evaln(C1,S13,N3,S21)
       => evaln(semi(C0,C1),S0,N3,S21) ) ) )).

tff(fact_12_triple_Oinject,axiom,(
    ! [B: $tType,Fun22: fun(B,fun(state,bool)),Com3: com,Fun12: fun(B,fun(state,bool)),Fun2: fun(B,fun(state,bool)),Com: com,Fun1: fun(B,fun(state,bool))] :
      ( hoare_1841697145triple(B,Fun1,Com,Fun2) = hoare_1841697145triple(B,Fun12,Com3,Fun22)
    <=> ( Fun1 = Fun12
        & Com = Com3
        & Fun2 = Fun22 ) ) )).

tff(fact_13_com_Osimps_I3_J,axiom,(
    ! [Com21: com,Com11: com,Com2: com,Com1: com] :
      ( semi(Com1,Com2) = semi(Com11,Com21)
    <=> ( Com1 = Com11
        & Com2 = Com21 ) ) )).

tff(fact_14_com_Osimps_I12_J,axiom,(
    ! [Com22: com,Com12: com] : skip != semi(Com12,Com22) )).

tff(fact_15_com_Osimps_I13_J,axiom,(
    ! [Com22: com,Com12: com] : semi(Com12,Com22) != skip )).

tff(fact_16_com_Osimps_I64_J,axiom,(
    ! [B: $tType,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,skip) = F1 )).

tff(fact_17_com_Osimps_I67_J,axiom,(
    ! [B: $tType,Com2: com,Com1: com,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,semi(Com1,Com2)) = aa(com,B,aa(com,fun(com,B),F4,Com1),Com2) )).

tff(fact_18_triples__valid__Suc,axiom,(
    ! [B: $tType,N2: nat,Ts: fun(hoare_28830079triple(B),bool)] :
      ( ! [X1: hoare_28830079triple(B)] :
          ( member(hoare_28830079triple(B),X1,Ts)
         => hoare_1633586161_valid(B,suc(N2),X1) )
     => ! [X: hoare_28830079triple(B)] :
          ( member(hoare_28830079triple(B),X,Ts)
         => hoare_1633586161_valid(B,N2,X) ) ) )).

tff(fact_19_evaln__Suc,axiom,(
    ! [S6: state,N3: nat,S5: state,C3: com] :
      ( evaln(C3,S5,N3,S6)
     => evaln(C3,S5,suc(N3),S6) ) )).

tff(fact_20_com_Osimps_I47_J,axiom,(
    ! [Com2: com,Com1: com,Com3: com,Fun3: fun(state,bool)] : while(Fun3,Com3) != semi(Com1,Com2) )).

tff(fact_21_com_Osimps_I46_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool),Com2: com,Com1: com] : semi(Com1,Com2) != while(Fun3,Com3) )).

tff(fact_22_com_Osimps_I17_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool)] : while(Fun3,Com3) != skip )).

tff(fact_23_com_Osimps_I16_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool)] : skip != while(Fun3,Com3) )).

tff(fact_24_evaln__elim__cases_I4_J,axiom,(
    ! [T1: state,N3: nat,S5: state,C21: com,C1: com] :
      ( evaln(semi(C1,C21),S5,N3,T1)
     => ~ ! [S12: state] :
            ( evaln(C1,S5,N3,S12)
           => ~ evaln(C21,S12,N3,T1) ) ) )).

tff(fact_25_nat_Oinject,axiom,(
    ! [Nat3: nat,Nat2: nat] :
      ( suc(Nat2) = suc(Nat3)
    <=> Nat2 = Nat3 ) )).

tff(fact_26_triple_Orecs,axiom,(
    ! [B: $tType,C: $tType,Fun2: fun(C,fun(state,bool)),Com: com,Fun1: fun(C,fun(state,bool)),F1: fun(fun(C,fun(state,bool)),fun(com,fun(fun(C,fun(state,bool)),B)))] : hoare_678420151le_rec(C,B,F1,hoare_1841697145triple(C,Fun1,Com,Fun2)) = aa(fun(C,fun(state,bool)),B,aa(com,fun(fun(C,fun(state,bool)),B),aa(fun(C,fun(state,bool)),fun(com,fun(fun(C,fun(state,bool)),B)),F1,Fun1),Com),Fun2) )).

tff(fact_27_triple_Osimps_I2_J,axiom,(
    ! [B: $tType,C: $tType,Fun2: fun(C,fun(state,bool)),Com: com,Fun1: fun(C,fun(state,bool)),F1: fun(fun(C,fun(state,bool)),fun(com,fun(fun(C,fun(state,bool)),B)))] : hoare_376461865e_case(C,B,F1,hoare_1841697145triple(C,Fun1,Com,Fun2)) = aa(fun(C,fun(state,bool)),B,aa(com,fun(fun(C,fun(state,bool)),B),aa(fun(C,fun(state,bool)),fun(com,fun(fun(C,fun(state,bool)),B)),F1,Fun1),Com),Fun2) )).

tff(fact_28_triple_Oexhaust,axiom,(
    ! [B: $tType,Y2: hoare_28830079triple(B)] :
      ~ ! [Fun11: fun(B,fun(state,bool)),Com4: com,Fun21: fun(B,fun(state,bool))] : Y2 != hoare_1841697145triple(B,Fun11,Com4,Fun21) )).

tff(fact_29_n__not__Suc__n,axiom,(
    ! [N3: nat] : N3 != suc(N3) )).

tff(fact_30_Suc__n__not__n,axiom,(
    ! [N3: nat] : suc(N3) != N3 )).

tff(fact_31_Suc__inject,axiom,(
    ! [Y1: nat,X4: nat] :
      ( suc(X4) = suc(Y1)
     => X4 = Y1 ) )).

tff(fact_32_of__nat__aux_Osimps_I2_J,axiom,(
    ! [B: $tType] :
      ( semiring_1(B)
     => ! [I: B,N2: nat,Inc: fun(B,B)] : semiri532925092at_aux(B,Inc,suc(N2),I) = semiri532925092at_aux(B,Inc,N2,aa(B,B,Inc,I)) ) )).

tff(fact_33_nat__case__Suc,axiom,(
    ! [B: $tType,Nat2: nat,F2: fun(nat,B),F1: B] : nat_case(B,F1,F2,suc(Nat2)) = aa(nat,B,F2,Nat2) )).

tff(fact_34_WTs__elim__cases_I4_J,axiom,(
    ! [C21: com,C1: com] :
      ( wt(semi(C1,C21))
     => ~ ( wt(C1)
         => ~ wt(C21) ) ) )).

tff(fact_35_evaln_OIfFalse,axiom,(
    ! [C01: com,S11: state,N2: nat,C11: com,S4: state,Ba: fun(state,bool)] :
      ( ~ pp(aa(state,bool,Ba,S4))
     => ( evaln(C11,S4,N2,S11)
       => evaln(cond(Ba,C01,C11),S4,N2,S11) ) ) )).

tff(fact_36_evaln_OIfTrue,axiom,(
    ! [C11: com,S11: state,N2: nat,C01: com,S4: state,Ba: fun(state,bool)] :
      ( pp(aa(state,bool,Ba,S4))
     => ( evaln(C01,S4,N2,S11)
       => evaln(cond(Ba,C01,C11),S4,N2,S11) ) ) )).

tff(fact_37_com_Osimps_I4_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool),Com2: com,Com1: com,Fun: fun(state,bool)] :
      ( cond(Fun,Com1,Com2) = cond(Fun3,Com11,Com21)
    <=> ( Fun = Fun3
        & Com1 = Com11
        & Com2 = Com21 ) ) )).

tff(fact_38_evaln__elim__cases_I5_J,axiom,(
    ! [T: state,N2: nat,S4: state,C2: com,C11: com,Ba: fun(state,bool)] :
      ( evaln(cond(Ba,C11,C2),S4,N2,T)
     => ( ( pp(aa(state,bool,Ba,S4))
         => ~ evaln(C11,S4,N2,T) )
       => ~ ( ~ pp(aa(state,bool,Ba,S4))
           => ~ evaln(C2,S4,N2,T) ) ) ) )).

tff(fact_39_WTs__elim__cases_I6_J,axiom,(
    ! [Ca: com,Ba: fun(state,bool)] :
      ( wt(while(Ba,Ca))
     => wt(Ca) ) )).

tff(fact_40_WTs__elim__cases_I5_J,axiom,(
    ! [C2: com,C11: com,Ba: fun(state,bool)] :
      ( wt(cond(Ba,C11,C2))
     => ~ ( wt(C11)
         => ~ wt(C2) ) ) )).

tff(fact_41_WT_OIf,axiom,(
    ! [Ba: fun(state,bool),C11: com,C01: com] :
      ( wt(C01)
     => ( wt(C11)
       => wt(cond(Ba,C01,C11)) ) ) )).

tff(fact_42_While,axiom,(
    ! [Ba: fun(state,bool),Ca: com] :
      ( wt(Ca)
     => wt(while(Ba,Ca)) ) )).

tff(fact_43_WT_OSemi,axiom,(
    ! [C1: com,C0: com] :
      ( wt(C0)
     => ( wt(C1)
       => wt(semi(C0,C1)) ) ) )).

tff(fact_44_com_Osimps_I52_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool),Com2: com,Com1: com,Fun: fun(state,bool)] : cond(Fun,Com1,Com2) != while(Fun3,Com3) )).

tff(fact_45_com_Osimps_I53_J,axiom,(
    ! [Com2: com,Com1: com,Fun: fun(state,bool),Com3: com,Fun3: fun(state,bool)] : while(Fun3,Com3) != cond(Fun,Com1,Com2) )).

tff(fact_46_WT_OSkip,axiom,(
    wt(skip) )).

tff(fact_47_com_Osimps_I44_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool),Com2: com,Com1: com] : semi(Com1,Com2) != cond(Fun3,Com11,Com21) )).

tff(fact_48_com_Osimps_I45_J,axiom,(
    ! [Com2: com,Com1: com,Com21: com,Com11: com,Fun3: fun(state,bool)] : cond(Fun3,Com11,Com21) != semi(Com1,Com2) )).

tff(fact_49_com_Osimps_I14_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool)] : skip != cond(Fun3,Com11,Com21) )).

tff(fact_50_com_Osimps_I15_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool)] : cond(Fun3,Com11,Com21) != skip )).

tff(fact_51_com_Osimps_I68_J,axiom,(
    ! [B: $tType,Com2: com,Com1: com,Fun: fun(state,bool),F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,cond(Fun,Com1,Com2)) = aa(com,B,aa(com,fun(com,B),aa(fun(state,bool),fun(com,fun(com,B)),F5,Fun),Com1),Com2) )).

tff(fact_52_nat__rec__Suc,axiom,(
    ! [B: $tType,Nat2: nat,F2: fun(nat,fun(B,B)),F1: B] : nat_rec(B,F1,F2,suc(Nat2)) = aa(B,B,aa(nat,fun(B,B),F2,Nat2),nat_rec(B,F1,F2,Nat2)) )).

tff(fact_53_WTs__elim__cases_I3_J,axiom,(
    ! [Ca: com,A: fun(state,nat),Y: loc] :
      ( wt(local(Y,A,Ca))
     => wt(Ca) ) )).

tff(fact_54_com_Orecs_I1_J,axiom,(
    ! [B: $tType,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,skip) = F1 )).

tff(fact_55_of__nat__aux_Osimps_I1_J,axiom,(
    ! [B: $tType] :
      ( semiring_1(B)
     => ! [I: B,Inc: fun(B,B)] : semiri532925092at_aux(B,Inc,zero_zero(nat),I) = I ) )).

tff(fact_56_com_Osimps_I1_J,axiom,(
    ! [Fun3: fun(state,nat),Vname1: vname,Fun: fun(state,nat),Vname: vname] :
      ( ass(Vname,Fun) = ass(Vname1,Fun3)
    <=> ( Vname = Vname1
        & Fun = Fun3 ) ) )).

tff(fact_57_com_Osimps_I2_J,axiom,(
    ! [Com3: com,Fun3: fun(state,nat),Loc1: loc,Com: com,Fun: fun(state,nat),Loc: loc] :
      ( local(Loc,Fun,Com) = local(Loc1,Fun3,Com3)
    <=> ( Loc = Loc1
        & Fun = Fun3
        & Com = Com3 ) ) )).

tff(fact_58_com_Osimps_I22_J,axiom,(
    ! [Com3: com,Fun3: fun(state,nat),Loc1: loc,Fun: fun(state,nat),Vname: vname] : ass(Vname,Fun) != local(Loc1,Fun3,Com3) )).

tff(fact_59_com_Osimps_I23_J,axiom,(
    ! [Fun: fun(state,nat),Vname: vname,Com3: com,Fun3: fun(state,nat),Loc1: loc] : local(Loc1,Fun3,Com3) != ass(Vname,Fun) )).

tff(fact_60_com_Orecs_I2_J,axiom,(
    ! [B: $tType,Fun: fun(state,nat),Vname: vname,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,ass(Vname,Fun)) = aa(fun(state,nat),B,aa(vname,fun(fun(state,nat),B),F2,Vname),Fun) )).

tff(fact_61_com_Orecs_I3_J,axiom,(
    ! [B: $tType,Com: com,Fun: fun(state,nat),Loc: loc,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,local(Loc,Fun,Com)) = aa(B,B,aa(com,fun(B,B),aa(fun(state,nat),fun(com,fun(B,B)),aa(loc,fun(fun(state,nat),fun(com,fun(B,B))),F3,Loc),Fun),Com),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com)) )).

tff(fact_62_nat__rec__0,axiom,(
    ! [B: $tType,F2: fun(nat,fun(B,B)),F1: B] : nat_rec(B,F1,F2,zero_zero(nat)) = F1 )).

tff(fact_63_Suc__neq__Zero,axiom,(
    ! [M: nat] : suc(M) != zero_zero(nat) )).

tff(fact_64_Zero__neq__Suc,axiom,(
    ! [M: nat] : zero_zero(nat) != suc(M) )).

tff(fact_65_nat_Osimps_I3_J,axiom,(
    ! [Nat1: nat] : suc(Nat1) != zero_zero(nat) )).

tff(fact_66_Suc__not__Zero,axiom,(
    ! [M: nat] : suc(M) != zero_zero(nat) )).

tff(fact_67_nat_Osimps_I2_J,axiom,(
    ! [Nat: nat] : zero_zero(nat) != suc(Nat) )).

tff(fact_68_Zero__not__Suc,axiom,(
    ! [M: nat] : zero_zero(nat) != suc(M) )).

tff(fact_69_nat__case__0,axiom,(
    ! [B: $tType,F2: fun(nat,B),F1: B] : nat_case(B,F1,F2,zero_zero(nat)) = F1 )).

tff(fact_70_WT_OAssign,axiom,(
    ! [A: fun(state,nat),X3: vname] : wt(ass(X3,A)) )).

tff(fact_71_ext,axiom,(
    ! [C: $tType,B: $tType,G: fun(B,C),F: fun(B,C)] :
      ( ! [X1: B] : aa(B,C,F,X1) = aa(B,C,G,X1)
     => F = G ) )).

tff(fact_72_mem__def,axiom,(
    ! [B: $tType,A1: fun(B,bool),X2: B] :
      ( member(B,X2,A1)
    <=> pp(aa(B,bool,A1,X2)) ) )).

tff(fact_73_WT_OLocal,axiom,(
    ! [A: fun(state,nat),Y: loc,Ca: com] :
      ( wt(Ca)
     => wt(local(Y,A,Ca)) ) )).

tff(fact_74_com_Osimps_I28_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool),Fun: fun(state,nat),Vname: vname] : ass(Vname,Fun) != while(Fun3,Com3) )).

tff(fact_75_com_Osimps_I29_J,axiom,(
    ! [Fun: fun(state,nat),Vname: vname,Com3: com,Fun3: fun(state,bool)] : while(Fun3,Com3) != ass(Vname,Fun) )).

tff(fact_76_com_Osimps_I39_J,axiom,(
    ! [Com: com,Fun: fun(state,nat),Loc: loc,Com3: com,Fun3: fun(state,bool)] : while(Fun3,Com3) != local(Loc,Fun,Com) )).

tff(fact_77_com_Osimps_I38_J,axiom,(
    ! [Com3: com,Fun3: fun(state,bool),Com: com,Fun: fun(state,nat),Loc: loc] : local(Loc,Fun,Com) != while(Fun3,Com3) )).

tff(fact_78_com_Osimps_I26_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool),Fun: fun(state,nat),Vname: vname] : ass(Vname,Fun) != cond(Fun3,Com11,Com21) )).

tff(fact_79_com_Osimps_I27_J,axiom,(
    ! [Fun: fun(state,nat),Vname: vname,Com21: com,Com11: com,Fun3: fun(state,bool)] : cond(Fun3,Com11,Com21) != ass(Vname,Fun) )).

tff(fact_80_com_Osimps_I37_J,axiom,(
    ! [Com: com,Fun: fun(state,nat),Loc: loc,Com21: com,Com11: com,Fun3: fun(state,bool)] : cond(Fun3,Com11,Com21) != local(Loc,Fun,Com) )).

tff(fact_81_com_Osimps_I36_J,axiom,(
    ! [Com21: com,Com11: com,Fun3: fun(state,bool),Com: com,Fun: fun(state,nat),Loc: loc] : local(Loc,Fun,Com) != cond(Fun3,Com11,Com21) )).

tff(fact_82_com_Osimps_I34_J,axiom,(
    ! [Com21: com,Com11: com,Com: com,Fun: fun(state,nat),Loc: loc] : local(Loc,Fun,Com) != semi(Com11,Com21) )).

tff(fact_83_com_Osimps_I35_J,axiom,(
    ! [Com: com,Fun: fun(state,nat),Loc: loc,Com21: com,Com11: com] : semi(Com11,Com21) != local(Loc,Fun,Com) )).

tff(fact_84_com_Osimps_I25_J,axiom,(
    ! [Fun: fun(state,nat),Vname: vname,Com21: com,Com11: com] : semi(Com11,Com21) != ass(Vname,Fun) )).

tff(fact_85_com_Osimps_I24_J,axiom,(
    ! [Com21: com,Com11: com,Fun: fun(state,nat),Vname: vname] : ass(Vname,Fun) != semi(Com11,Com21) )).

tff(fact_86_com_Osimps_I11_J,axiom,(
    ! [Com3: com,Fun3: fun(state,nat),Loc1: loc] : local(Loc1,Fun3,Com3) != skip )).

tff(fact_87_com_Osimps_I9_J,axiom,(
    ! [Fun3: fun(state,nat),Vname1: vname] : ass(Vname1,Fun3) != skip )).

tff(fact_88_com_Osimps_I10_J,axiom,(
    ! [Com3: com,Fun3: fun(state,nat),Loc1: loc] : skip != local(Loc1,Fun3,Com3) )).

tff(fact_89_com_Osimps_I8_J,axiom,(
    ! [Fun3: fun(state,nat),Vname1: vname] : skip != ass(Vname1,Fun3) )).

tff(fact_90_com_Osimps_I66_J,axiom,(
    ! [B: $tType,Com: com,Fun: fun(state,nat),Loc: loc,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,local(Loc,Fun,Com)) = aa(com,B,aa(fun(state,nat),fun(com,B),aa(loc,fun(fun(state,nat),fun(com,B)),F3,Loc),Fun),Com) )).

tff(fact_91_com_Osimps_I65_J,axiom,(
    ! [B: $tType,Fun: fun(state,nat),Vname: vname,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,B)),F5: fun(fun(state,bool),fun(com,fun(com,B))),F4: fun(com,fun(com,B)),F3: fun(loc,fun(fun(state,nat),fun(com,B))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_case(B,F1,F2,F3,F4,F5,F6,F7,F8,ass(Vname,Fun)) = aa(fun(state,nat),B,aa(vname,fun(fun(state,nat),B),F2,Vname),Fun) )).

tff(fact_92_com_Orecs_I6_J,axiom,(
    ! [B: $tType,Com: com,Fun: fun(state,bool),F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,while(Fun,Com)) = aa(B,B,aa(com,fun(B,B),aa(fun(state,bool),fun(com,fun(B,B)),F6,Fun),Com),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com)) )).

tff(fact_93_com_Orecs_I5_J,axiom,(
    ! [B: $tType,Com2: com,Com1: com,Fun: fun(state,bool),F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,cond(Fun,Com1,Com2)) = aa(B,B,aa(B,fun(B,B),aa(com,fun(B,fun(B,B)),aa(com,fun(com,fun(B,fun(B,B))),aa(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B)))),F5,Fun),Com1),Com2),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com1)),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com2)) )).

tff(fact_94_com_Orecs_I4_J,axiom,(
    ! [B: $tType,Com2: com,Com1: com,F8: fun(vname,fun(pname,fun(fun(state,nat),B))),F7: fun(pname,B),F6: fun(fun(state,bool),fun(com,fun(B,B))),F5: fun(fun(state,bool),fun(com,fun(com,fun(B,fun(B,B))))),F4: fun(com,fun(com,fun(B,fun(B,B)))),F3: fun(loc,fun(fun(state,nat),fun(com,fun(B,B)))),F2: fun(vname,fun(fun(state,nat),B)),F1: B] : com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,semi(Com1,Com2)) = aa(B,B,aa(B,fun(B,B),aa(com,fun(B,fun(B,B)),aa(com,fun(com,fun(B,fun(B,B))),F4,Com1),Com2),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com1)),com_rec(B,F1,F2,F3,F4,F5,F6,F7,F8,Com2)) )).

tff(fact_95_triple_Osize_I1_J,axiom,(
    ! [B: $tType,Fun2: fun(B,fun(state,bool)),Com: com,Fun1: fun(B,fun(state,bool)),Fa: fun(B,nat)] : hoare_47506394e_size(B,Fa,hoare_1841697145triple(B,Fun1,Com,Fun2)) = zero_zero(nat) )).

%----Arities (1)
tff(arity_Nat_Onat___Rings_Osemiring__1,axiom,(
    semiring_1(nat) )).

%----Helper facts (2)
tff(help_pp_1_1_U,axiom,(
    ~ pp(fFalse) )).

tff(help_pp_2_1_U,axiom,(
    pp(fTrue) )).

%----Conjectures (2)
tff(conj_0,hypothesis,(
    ! [N1: nat] :
      ( ! [X1: hoare_28830079triple(a)] :
          ( member(hoare_28830079triple(a),X1,g)
         => hoare_1633586161_valid(a,N1,X1) )
     => ! [Z1: a,S2: state] :
          ( ( p(Z1,S2)
            & pp(aa(state,bool,b,S2)) )
         => ! [S3: state] :
              ( evaln(c,S2,N1,S3)
             => p(Z1,S3) ) ) ) )).

tff(conj_1,conjecture,(
    ! [N: nat] :
      ( ? [X: hoare_28830079triple(a)] :
          ( member(hoare_28830079triple(a),X,g)
          & ~ hoare_1633586161_valid(a,N,X) )
      | ! [Z: a,S: state] :
          ( ~ p(Z,S)
          | ! [S1: state] :
              ( ~ evaln(while(b,c),S,N,S1)
              | ( p(Z,S1)
                & ~ pp(aa(state,bool,b,S1)) ) ) ) ) )).

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

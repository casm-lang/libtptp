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

%skeleton "lalr1.cc"
%require "3.0"
//%debug

%defines
%define api.namespace {libtptp}
%define parser_class_name {Parser}

%define api.token.constructor
%define api.value.type variant
%define api.location.type {SourceLocation}

%define parse.assert
%define parse.trace
%define parse.error verbose

%locations

%code requires
{
    namespace libtptp
    {
        class Lexer;
        // class Logger;
        class SourceLocation;
    }

    #include <libtptp/Specification>
    #include <libtptp/Token>

    #include "../../src/SourceLocation.h"

    using namespace libtptp;

    #define YY_NULLPTR nullptr
}

// %parse-param { Logger& m_log }
%parse-param { Lexer& m_lexer }
%parse-param { Specification& m_specification }

%code
{
    // #include <libtptp/ ... >

    //#include "../../src/SourceLocation.h"
    #include "../../src/Lexer.h"
    #include "../../src/various/GrammarToken.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

    // static Lexer helper functions shall be located here 
}


%token
END       0 "end of file"
{{grammartoken}}

%token <std::string> INTEGER     "integer"
%token <std::string> REAL        "real"
%token <std::string> RATIONAL    "rational"
%token <std::string> DQUOTED     "double_quoted"
%token <std::string> LOWER_WORD  "lower_word"
%token <std::string> UPPER_WORD  "upper_word"
%token <std::string> IDENTIFIER  "identifier"
%token <std::string> SINGLE_QUOTED "single_quoted"

%type <Specification::Ptr> Specification

// %type <Identifier::Ptr> Identifier

// definitions
// %type <Atom::Ptr> Atom

%start Specification

// precedence information shall be located here
// %precedence OPERATOR

%%


Specification
: Inputs
  {
      //m_specification.setInputs( $1 );
  }
;

Inputs
: Inputs Input
  {
    //auto inputs = $1;
    //inputs->add($2);
    //$$ = inputs;
  }
| Input
  {
    //auto inputs = make< Nodes >( @$ );
    //inputs->add( $1 );
    //$$ = inputs;
  }
;

/*
Input 
: Identifier 
  {
  }
;
*/

Input
: AnnotatedFormula 
  {
      //$$ = $1;
  }
/* TODO
| include
  {
      //$$ = $1;
  }
*/
;

AnnotatedFormula
/*
: ThfAnnotated
  {
    $$ = $1
  }
| TffAnnotated
  {
    $$ = $1
  }
| TcfAnnotated
  {
    $$ = $1
  }
| FofAnnotated
  {
    $$ = $1
  }
| CnfAnnotated
  {
    $$ = $1
  }
| TpiAnnotated
  {
    $$ = $1
  }
;
*/
: FormulaKeyword LPAREN Name COMMA FormulaRole COMMA FormulaSpecification RPAREN DOT
  {
    //auto formula = $1;
    //formula->set ...
  }

FormulaKeyword
: TPI
  {
  }
| THF
  {
  }
| TFF
  {
  }
| TCF
  {
  }
| FOF
  {
    //$$ = libtptp::make< FirstOrderFormula >( @$ );
  }
| CNF
  {
  }
; 

FormulaSpecification 
: Formula COMMA Annotations
  {
    //auto formula = $1;
    //formula->setAnnotations($3);
    //$$ = formula;
  }
| Formula
  {
    //$$ = $1;
  }
;

Annotations
: GeneralTerm
  {
    //source
  }
| GeneralTerm COMMA GeneralList
  {
    //source, optionalInfo
  }
;

Formula
: ThfFormula
  {
  }
;

ThfFormula
: ThfLogicFormula
  {
  }
| ThfAtomTyping
  {
  }
| ThfSubtype
  {
  }
| ThfSequent
  {
  }
;

ThfLogicFormula
: ThfUnitaryFormula
  {
  }
| ThfUnaryFormula
  {
  }
| ThfBinaryFormula
  {
  }
| ThfDefinedInfix
  {
  }
;

ThfBinaryFormula
: ThfBinaryNonassoc
  {
  }
| ThfBinaryAssoc
  {
  }
| ThfBinaryType
  {
  }
;

ThfBinaryNonassoc
: ThfUnitFormula NonassocConnective ThfUnitFormula
  {
  }
;

ThfBinaryAssoc
: ThfOrFormula
  {
  }
| ThfAndFormula
  {
  }
| ThfApplyFormula
  {
  }
;

ThfOrFormula
: ThfUnitFormula VLINE ThfUnitFormula
  {
  }
| ThfOrFormula VLINE ThfUnitFormula
  {
  }
;

ThfAndFormula
: ThfUnitFormula AND ThfUnitFormula
  {
  }
| ThfAndFormula AND ThfUnitFormula
  {
  }
;

ThfApplyFormula
: ThfUnitFormula AT ThfUnitFormula
  {
  }
| ThfApplyFormula AT ThfUnitFormula
  {
  }
;

ThfUnitFormula
: ThfUnitaryFormula
  {
  }
| ThfUnaryFormula
  {
  }
| ThfDefinedInfix
  {
  }
;

ThfPreunitFormula
: ThfUnitaryFormula
  {
  }
| ThfPrefixUnary
  {
  }
;

ThfUnitaryFormula
: ThfQuantifiedFormula
  {
  }
| ThfAtomicFormula
  {
  }
| Variable
  {
  }
| LPAREN ThfLogicFormula RPAREN
  {
  }
;

ThfQuantifiedFormula
: ThfQuantification ThfUnitFormula
  {
  }
;

ThfQuantification
: ThfQuantifier LSQPAREN ThfVariableList RSQPAREN COLON
  {
  }
;

ThfVariableList
: ThfTypedVariable
  {
  }
| ThfVariableList COMMA ThfTypedVariable
  {
  }
;

ThfTypedVariable
: Variable COLON ThfTopLevelType
  {
  }
;

ThfUnaryFormula
: ThfPrefixUnary
  {
  }
| ThfInfixUnary
  {
  }
;

ThfPrefixUnary
: ThfUnaryConnective ThfPreunitFormula
  {
  }
;

ThfInfixUnary
: ThfUnitaryTerm InfixInequality ThfUnitaryTerm
  {
  }
;

ThfAtomicFormula
: ThfPlainAtomic
  {
  }
| ThfDefinedAtomic
  {
  }
| ThfSystemAtomic
  {
  }
| ThfFofFunction
  {
  }
;

ThfPlainAtomic
: Constant
  {
  }
| ThfTuple
  {
  }
;

ThfDefinedAtomic
: DefinedConstant
  {
  }
| ThfConditional
  {
  }
| ThfLet
  {
  }
| LPAREN ThfConnTerm RPAREN
  {
  }
| DefinedTerm
  {
  }
;

ThfDefinedInfix
: ThfUnitaryTerm DefinedInfixPred ThfUnitaryTerm
  {
  }
;

ThfSystemAtomic
: SystemConstant
  {
  }
;

ThfFofFunction
: Functor LPAREN ThfArguments RPAREN
  {
  }
| DefinedFunctor LPAREN ThfArguments RPAREN
  {
  }
| SystemFunctor LPAREN ThfArguments RPAREN
  {
  }
;

ThfConditional
: DOLLAR ITE LPAREN ThfLogicFormula COMMA ThfLogicFormula COMMA ThfLogicFormula RPAREN
  {
  }
;

ThfLet
: DOLLAR LET LPAREN ThfLetTypes COMMA ThfLetDefns COMMA ThfFormula RPAREN
  {
  }
;

ThfLetTypes
: ThfAtomTyping
  {
  }
| LSQPAREN ThfAtomTypingList RSQPAREN
  {
  }
;

ThfAtomTypingList
: ThfAtomTyping
  {
  }
| ThfAtomTypingList COMMA ThfAtomTyping
  {
  }
;

ThfLetDefns
: ThfLetDefn
  {
  }
| LSQPAREN ThfLetDefnList RSQPAREN
  {
  }
;

ThfLetDefn
: ThfLogicFormula Assignment ThfLogicFormula
  {
  }
;

ThfLetDefnList
: ThfLetDefn
  {
  }
| ThfLetDefnList COMMA ThfLetDefn
  {
  }
;

ThfUnitaryTerm
: ThfAtomicFormula
  {
  }
| Variable
  {
  }
| LPAREN ThfLogicFormula RPAREN
  {
  }
;

ThfTuple
: LSQPAREN RSQPAREN
  {
  }
| LSQPAREN ThfFormulaList RSQPAREN
  {
  }
;

ThfFormulaList
: ThfLogicFormula
  {
  }
| ThfFormulaList COMMA ThfLogicFormula 
  {
  }
;

ThfConnTerm
: NonassocConnective
  {
  }
| AssocConnective
  {
  }
| InfixEquality
  {
  }
| ThfUnaryConnective
  {
  }
;

ThfArguments
: ThfFormulaList
  {
  }
;

ThfAtomTyping
: UntypedAtom COLON ThfTopLevelType
  {
  }
| LPAREN ThfAtomTyping RPAREN
  {
  }
;

ThfTopLevelType
: ThfUnitaryType
  {
  }
| ThfMappingType
  {
  }
| ThfApplyType
  {
  }
;

ThfUnitaryType
: ThfUnitaryFormula
  {
  }
;

ThfApplyType
: ThfApplyFormula
  {
  }
;

ThfBinaryType
: ThfMappingType
  {
  }
| ThfXprodType
  {
  }
| ThfUnionType
  {
  }
;

ThfMappingType
: ThfUnitaryType GREATER ThfUnitaryType
  {
  }
| ThfUnitaryType GREATER ThfMappingType
  {
  }
;

ThfXprodType
: ThfUnitaryType STAR ThfUnitaryType
  {
  }
| ThfXprodType STAR ThfUnitaryType
  {
  }
;

ThfUnionType
: ThfUnitaryType PLUS ThfUnitaryType
  {
  }
| ThfUnionType PLUS ThfUnitaryType
  {
  }
;

ThfSubtype
: UntypedAtom SUBTYPESIGN Atom
  {
  }
;

ThfSequent
: ThfTuple GENTZENARROW ThfTuple
  {
  }
| LPAREN ThfSequent RPAREN
  {
  }
;

/* TFF */
TffFormula
: TffLogicFormula
  {
  }
| TffAtomTyping
  {
  }
| TffSubtype
  {
  }
| TfxSequent
  {
  }
;

TffLogicFormula
: TffUnitaryFormula
  {
  }
| TffUnaryFormula
  {
  }
| TffBinaryFormula
  {
  }
| TffDefinedInfix
  {
  }
;

TffBinaryFormula
: TffBinaryNonassoc
  {
  }
| TffBinaryAssoc
  {
  }
;

TffBinaryNonassoc
: TffUnitFormula NonassocConnective TffUnitFormula
  {
  }
;

TffBinaryAssoc
: TffOrFormula
  {
  }
| TffAndFormula
  {
  }
;

TffOrFormula
: TffUnitFormula VLINE TffUnitFormula
  {
  }
| TffOrFormula VLINE TffUnitFormula
  {
  }
;

TffAndFormula
: TffUnitFormula AND TffUnitFormula
  {
  }
| TffAndFormula AND TffUnitFormula
  {
  }
;

TffUnitFormula
: TffUnitaryFormula
  {
  }
| TffUnaryFormula
  {
  }
| TffDefinedInfix
  {
  }
;

TffPreunitFormula
: TffUnitaryFormula
  {
  }
| TffPrefixUnary
  {
  }
;

TffUnitaryFormula
: TffQuantifiedFormula
  {
  }
| TffAtomicFormula
  {
  }
| TfxUnitaryFormula
  {
  }
| LPAREN TffLogicFormula RPAREN
  {
  }
;

TfxUnitaryFormula
: Variable
  {
  }
;

TffQuantifiedFormula
: FofQuantifier LSQPAREN TffVariableList RSQPAREN COLON TffUnitFormula
  {
  }
;

TffVariableList
: TffVariable
  {
  }
| TffVariableList COMMA TffVariable
  {
  }
;

TffVariable
: TffTypedVariable
  {
  }
| Variable
  {
  }
;

TffTypedVariable
: Variable COLON TffAtomicType
  {
  }
;

TffUnaryFormula
: TffPrefixUnary
  {
  }
| TffInfixUnary
  {
  }
;

TffPrefixUnary
: UnaryConnective TffPreunitFormula
  {
  }
;

TffInfixUnary
: TffUnitaryTerm InfixInequality TffUnitaryTerm
  {
  }
;

TffAtomicFormula
: TffPlainAtomic
  {
  }
| TffDefinedAtomic
  {
  }
| TffSystemAtomic
  {
  }
;

TffPlainAtomic
: Constant
  {
  }
| Functor LPAREN TffArguments RPAREN
  {
  }
;

TffDefinedAtomic
: TffDefinedPlain
  {
  }
;

TffDefinedPlain
: DefinedConstant
  {
  }
| DefinedFunctor LPAREN TffArguments RPAREN
  {
  }
| TfxConditional
  {
  }
| TfxLet
  {
  }
;

TffDefinedInfix
: TffUnitaryTerm DefinedInfixPred TffUnitaryTerm
  {
  }
;

TffSystemAtomic
: SystemConstant
  {
  }
| SystemFunctor LPAREN TffArguments RPAREN
  {
  }
;

TfxConditional
: DOLLAR ITE LPAREN TffLogicFormula COMMA TffTerm COMMA TffTerm RPAREN
  {
  }
;

TfxLet
: DOLLAR LET LPAREN TfxLetTypes COMMA TfxLetDefns COMMA TffTerm RPAREN
  {
  }
;

TfxLetTypes
: TffAtomTyping
  {
  }
| LSQPAREN TffAtomTypingList RSQPAREN
  {
  }
;

TffAtomTypingList
: TffAtomTyping
  {
  }
| TffAtomTypingList COMMA TffAtomTyping
  {
  }
;

TfxLetDefns
: TfxLetDefn
  {
  }
| LSQPAREN TfxLetDefnList RSQPAREN
  {
  }
;

TfxLetDefn
: TfxLetLhs Assignment TffTerm
  {
  }
;

TfxLetLhs
: TffPlainAtomic
  {
  }
| TfxTuple
  {
  }
;

TfxLetDefnList
: TfxLetDefn
  {
  }
| TfxLetDefnList COMMA TfxLetDefn
  {
  }
;

TffTerm
: TffLogicFormula
  {
  }
| DefinedTerm
  {
  }
| TfxTuple
  {
  }
;

TffUnitaryTerm
: TffAtomicFormula
  {
  }
| DefinedTerm
  {
  }
| TfxTuple
  {
  }
| Variable
  {
  }
| LPAREN TffLogicFormula RPAREN
  {
  }
;

TfxTuple
: LSQPAREN RSQPAREN
  {
  }
| LSQPAREN TffArguments RSQPAREN
  {
  }
;

TffArguments
: TffTerm
  {
  }
| TffArguments COMMA TffTerm 
  {
  }
;

TffAtomTyping
: UntypedAtom COLON TffTopLevelType
  {
  }
| LPAREN TffAtomTyping RPAREN
  {
  }
;

TffTopLevelType
: TffAtomicType
  {
  }
| TffMappingType
  {
  }
| Tf1QuantifiedType
  {
  }
| LPAREN TffTopLevelType RPAREN
  {
  }
;

Tf1QuantifiedType
: EXCLAMATION LSQPAREN TffVariableList RSQPAREN COLON TffMonotype
  {
  }
;

TffMonotype
: TffAtomicType
  {
  }
| LPAREN TffMappingType RPAREN
  {
  }
;

TffUnitaryType
: TffAtomicType
  {
  }
| LPAREN TffXprodType RPAREN
  {
  }
;

TffAtomicType
: TypeConstant
  {
  }
| DefinedType
  {
  }
| TypeFunctor LPAREN TffTypeArguments RPAREN
  {
  }
| Variable
  {
  }
| TfxTupleType
  {
  }
;

TffTypeArguments
: TffAtomicType
  {
  }
| TffTypeArguments COMMA TffAtomicType
  {
  }
;

TffMappingType
: TffUnitaryType GREATER TffAtomicType
  {
  }
;

TffXprodType
: TffUnitaryType STAR TffAtomicType
  {
  }
| TffXprodType STAR TffAtomicType
  {
  }
;

TfxTupleType
: LSQPAREN TffTypeList RSQPAREN
  {
  }
;

TffTypeList
: TffTopLevelType
  {
  }
| TffTypeList COMMA TffTopLevelType
  {
  }
;

TffSubtype
: UntypedAtom SUBTYPESIGN Atom
  {
  }
;

TfxSequent
: TfxTuple GENTZENARROW TfxTuple
  {
  }
| LPAREN TfxSequent RPAREN
  {
  }
;

/* TCF */
TcfFormula
: TcfLogicFormula
  {
  }
| TffAtomTyping
  {
  }
;

TcfLogicFormula
: TcfQuantifiedFormula
  {
  }
| CnfFormula
  {
  }
;

TcfQuantifiedFormula
: EXCLAMATION LSQPAREN TffVariableList RSQPAREN COLON CnfFormula
  {
  }
;

/* FoF */

FofFormula
: FofLogicFormula
  {
  }
| FofSequent
  {
  }
;

FofLogicFormula
: FofBinaryFormula
  {
  }
| FofUnaryFormula
  {
  }
| FofUnitaryFormula
  {
  }
;

FofBinaryFormula
: FofBinaryNonassoc
  {
  }
| FofBinaryAssoc
  {
  }
;

FofBinaryNonassoc
: FofUnitFormula NonassocConnective FofUnitFormula
  {
  }
;

FofBinaryAssoc
: FofOrFormula
  {
  }
| FofAndFormula
  {
  }
;

FofOrFormula
: FofUnitFormula VLINE FofUnitFormula
  {
  }
| FofOrFormula VLINE FofUnitFormula
  {
  }
;

FofAndFormula
: FofUnitFormula AND FofUnitFormula
  {
  }
| FofAndFormula AND FofUnitFormula
  {
  }
;

FofUnaryFormula
: UnaryConnective FofUnitFormula
  {
  }
| FofInfixUnary
  {
  }
;

FofInfixUnary
: FofTerm InfixInequality FofTerm
  {
  }
;

FofUnitFormula
: FofUnitaryFormula
  {
  }
| FofUnaryFormula
  {
  }
;

FofUnitaryFormula
: FofQuantifiedFormula
  {
  }
| FofAtomicFormula
  {
  }
| LPAREN FofLogicFormula RPAREN
  {
  }
;

FofQuantifiedFormula
: FofQuantifier LSQPAREN FofVariableList RSQPAREN COLON FofUnitFormula
  {
  }
;

FofVariableList
: Variable
  {
  }
| FofVariableList COMMA Variable
  {
  }
;

FofAtomicFormula
: FofPlainAtomicFormula
  {
  }
| FofDefinedAtomicFormula
  {
  }
| FofSystemAtomicFormula
  {
  }
;

FofPlainAtomicFormula
: FofPlainTerm
  {
  }
;

FofDefinedAtomicFormula
: FofDefinedPlainFormula
  {
  }
| FofDefinedInfixFormula
  {
  }
;

FofDefinedPlainFormula
: FofDefinedPlainTerm
  {
  }
;

FofDefinedInfixFormula
: FofTerm DefinedInfixPred FofTerm
  {
  }
;

FofSystemAtomicFormula
: FofSystemTerm
  {
  }
;

FofPlainTerm
: Constant
  {
  }
| Functor LPAREN FofArguments RPAREN
  {
  }
;

FofDefinedTerm
: DefinedTerm
  {
  }
| FofDefinedAtomicTerm
  {
  }
;

FofDefinedAtomicTerm
: FofDefinedPlainTerm
  {
  }
;

FofDefinedPlainTerm
: DefinedConstant
  {
  }
| DefinedFunctor LPAREN FofArguments RPAREN
  {
  }
;

FofSystemTerm
: SystemConstant
  {
  }
| SystemFunctor LPAREN FofArguments RPAREN
  {
  }
;

FofArguments
: FofTerm
  {
  }
| FofArguments COMMA FofTerm
  {
  }
;

FofTerm
: FofFunctionTerm
  {
  }
| Variable
  {
  }
;

FofFunctionTerm
: FofPlainTerm
  {
  }
| FofDefinedTerm
  {
  }
| FofSystemTerm
  {
  }
;

FofSequent
: FofFormulaTuple GENTZENARROW FofFormulaTuple
  {
  }
| LPAREN FofSequent RPAREN
  {
  }
;

FofFormulaTuple
: LCURPAREN RCURPAREN
  {
  }
| LCURPAREN FofFormulaTupleList RCURPAREN
  {
  }
;

FofFormulaTupleList
: FofLogicFormula
  {
  }
| FofFormulaTupleList COMMA FofLogicFormula
  {
  }
;

CnfFormula
: Disjunction
  {
  }
| LPAREN Disjunction RPAREN
  {
  }
;

Disjunction
: Literal
  {
  }
| Disjunction Vline Literal
  {
  }
;

Literal
: FofAtomicFormula
  {
  }
| TILDE FofAtomicFormula
  {
  }
| FofInfixUnary
  {
  }
;

ThfQuantifier
: FofQuantifier
  {
  }
| Th0Quantifier
  {
  }
| Th1Quantifier
  {
  }
;

Th1Quantifier
: EXCLAMATION
  {
  }
| QUESTIONMARK STAR
  {
  }
;

Th0Quantifier
: CARET
  {
  }
| AT PLUS
  {
  }
| AT MINUS
  {
  }
;

ThfUnaryConnective
: UnaryConnective
  {
  }
| Th1UnaryConnective
  {
  }
;

Th1UnaryConnective
: DOUBLEEXCLAMATION
  {
  }
| DOUBLEQUESTIONMARK
  {
  }
| DOUBLEAT PlUS
  {
  }
| DOUBLEAT MINUS
  {
  }
| AT EQUAL
  {
  }
;

FofQuantifier
: EXCLAMATION
  {
  }
| QUESTIONMARK
  {
  }
;

Name
: AtomicWord
  {
    //$$ = $1;
  }
| IntegerLiteral
  {
    //$$ = $1;
  }
;

FormulaRole
: LowerWordLiteral
  {
    // $$ = libtptp::make< FormulaRole >( @$, $1 );
  }
;

GeneralTerm
: GeneralData
  {
  }
| GeneralData COLON GeneralTerm
  {
  }
| GeneralList
  {
  }
;

GeneralData
: AtomicWord
  {
  }
| GeneralFunction
  {
  }
| Variable
  {
  }
| Number
  {
  }
| DistinctObjectLiteral
  {
  }
| FormulaData
  {
  }
;

GeneralFunction
: AtomicWord LPAREN GeneralTerms RPAREN
  {
  }
;

GeneralTerms
: GeneralTerm 
  {
  }
| GeneralTerms COMMA GeneralTerm
  {
    //auto terms = $1;
    //terms->add($3);
    //$$ = terms;
  }
;

FormulaData
: DOLLAR FormulaDataKeyword LPAREN Formula RPAREN
  {
  }
;

GeneralList
: LSQPAREN RSQPAREN
  {
  }
| LSQPAREN GeneralTerms RSQPAREN
  {
  }
;

FormulaDataKeyword
: THF
  {
  }
| TFF
  {
  }
| FOF
  {
  }
| CNF
  {
  }
| FOT
  {
  }
;

Identifier
: IDENTIFIER
  {
      // $$ = libtptp::make< Identifier >( @$, $1 );
  }
;

AtomicWord
: LowerWordLiteral
  {
  }
| SingleQuotedLiteral
  {
  }
;

Number
: IntegerLiteral
  {
    //$$ = $1;
  }
| RealLiteral
  {
    //$$ = $1;
  }
| RationalLiteral
  {
    //$$ = $1;
  }
;

IntegerLiteral
: INTEGER
  {
      // ...
  }
;

RealLiteral
: REAL
  {
      // ...
  }
;
RationalLiteral
: RATIONAL
  {
      // ...
  }
;

Variable
: UPPER_WORD
  {
    // ...
  }
;

DistinctObjectLiteral
: DQUOTED
  {
  }
;

LowerWordLiteral
: LOWER_WORD
  {
    //
  }
;

SingleQuotedLiteral
: SINGLE_QUOTED
  {
  }
;

%%

void Parser::error( const SourceLocation& location, const std::string& message )
{
    // m_log.error( {location}, message, Code::SyntaxError );
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
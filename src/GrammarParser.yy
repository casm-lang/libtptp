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
        class Logger;
        class SourceLocation;
    }

	//TODO: @moosbruggerj remove temporary includes
	#include <libtptp/General>
	#include <libtptp/Term>
	#include <libtptp/Atom>


    #include <libtptp/Specification>
    #include <libtptp/Token>

	#include <libtptp/Logger>

    #include "../../src/SourceLocation.h"

    using namespace libtptp;

	//to prevent
	//error: too many arguments provided to function-like macro invocation
	//because YY_RVREF macro consumes ',' in std::pair definition and interprets it as parameter separator
	//@see: https://stackoverflow.com/a/38030161
	using UnaryConnective_t = std::pair<Token::Ptr, UnaryLogic::Connective>;
	using BinaryConnective_t = std::pair<Token::Ptr, BinaryLogic::Connective>;
	using QuantifiedQuantifier_t = std::pair<Tokens::Ptr, QuantifiedLogic::Quantifier>;
	using InfixConnective_t = std::pair<Token::Ptr, InfixLogic::Connective>;

    #define YY_NULLPTR nullptr
}

%parse-param { Logger& m_log }
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

	static const auto uToken = std::make_shared<Token>(Grammar::Token::UNRESOLVED );
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

%type <Identifier::Ptr> FileName Name Functor Constant DefinedFunctor DefinedConstant SystemFunctor SystemConstant
//%type <Identifiers::Ptr> FormulaSelection
%type <Nodes::Ptr> NameList
%type <ListLiteral::Ptr> FormulaSelection

// definitions
%type <IncludeDefinition::Ptr> IncludeDefinition
%type <FormulaDefinition::Ptr> AnnotatedFormula FofAnnotated
%type <Definition::Ptr> Definition
%type <Definitions::Ptr> Definitions

%type <Annotation::Ptr> Annotations

%type <FormulaRole::Ptr> FormulaRole
//%type <Token::Ptr> FormulaKeyword
//%type <Formula::Ptr> FormulaSpecification
%type <BinaryLogic::Ptr> FofAndFormula FofOrFormula FofBinaryAssoc FofBinaryNonassoc FofBinaryFormula
%type <Logic::Ptr> FofUnaryFormula
%type <QuantifiedLogic::Ptr> FofQuantifiedFormula
%type <InfixLogic::Ptr> FofInfixUnary FofDefinedInfixFormula
%type <SequentLogic::Ptr> FofSequent
%type <Logic::Ptr> FofLogicFormula FofUnitFormula FofUnitaryFormula FofAtomicFormula FofDefinedAtomicFormula CnfFormula Literal Disjunction
%type <Logics::Ptr> FofFormulaTupleList
%type <LogicTuple::Ptr> FofFormulaTuple

//TODO: @moosbruggerj maybe change signature
%type <Term::Ptr> FofTerm FofPlainAtomicFormula FofDefinedPlainFormula FofSystemAtomicFormula
%type <Terms::Ptr> FofArguments

%type <Atom::Ptr> FofFunctionTerm FofSystemTerm FofDefinedPlainTerm FofDefinedAtomicTerm FofDefinedTerm FofPlainTerm
%type <DefinedAtom::Ptr> DefinedTerm
%type <VariableTerm::Ptr> Variable

%type <FirstOrderFormula::Ptr> FofFormula

%type <StringLiteral::Ptr> SingleQuotedLiteral LowerWordLiteral DistinctObjectLiteral AtomicWord DollarWordLiteral DollarDollarWordLiteral AtomicDefinedWord AtomicSystemWord 

%type <IntegerLiteral::Ptr> IntegerLiteral
%type <RationalLiteral::Ptr> RationalLiteral
%type <RealLiteral::Ptr> RealLiteral
%type <ValueLiteral::Ptr> Number
// %type <Atom::Ptr> Atom

%type <GeneralTerm::Ptr> GeneralTerm
%type <GeneralData::Ptr> GeneralData
%type <GeneralList::Ptr> GeneralList
%type <GeneralFunction::Ptr> GeneralFunction
%type <Nodes::Ptr> GeneralTerms FofVariableList

%type <UnaryConnective_t> UnaryConnective
%type <BinaryConnective_t> AssocConnective NonassocConnective
%type <QuantifiedQuantifier_t> FofQuantifier
%type <InfixConnective_t> InfixInequality DefinedInfixPred InfixEquality
%start Specification

// precedence information shall be located here
// %precedence OPERATOR

%%


Specification
: Definitions
  {
      m_specification.setDefinitions( $1 );
  }
;

Definitions
: Definitions Definition
  {
    const auto definitions = $1;
    definitions->add($2);
    $$ = definitions;
  }
| Definition
  {
    const auto definitions = make< Definitions >( @$ );
    definitions->add( $1 );
    $$ = definitions;
  }
;


Definition
: AnnotatedFormula  /*FormulaDefinition*/
  {
      $$ = $1;
  }
| IncludeDefinition
  {
      $$ = $1;
  }
;

AnnotatedFormula
: ThfAnnotated
  {
    //$$ = $1
  }
| TffAnnotated
  {
    //$$ = $1
  }
| TcfAnnotated
  {
    //$$ = $1
  }
| FofAnnotated
  {
    //$$ = $1
  }
| CnfAnnotated
  {
    //$$ = $1
  }
| TpiAnnotated
  {
    //$$ = $1
  }
;
/*
: FormulaKeyword LPAREN Name COMMA FormulaRole COMMA FormulaSpecification RPAREN DOT
  {
	$$ = libtptp::make< FormulaDefinition >(@$, uToken, $2, $3, $4, $5, $6, formula, $8, $9);
	//$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
    //auto formula = $1;
    //formula->set ...
  }
*/

ThfAnnotated
: THF LPAREN Name COMMA FormulaRole COMMA ThfFormula RPAREN DOT
  {
  }
| THF LPAREN Name COMMA FormulaRole COMMA ThfFormula COMMA Annotations RPAREN DOT
  {
  }
;
TffAnnotated
: TFF LPAREN Name COMMA FormulaRole COMMA TffFormula RPAREN DOT
  {
  }
| TFF LPAREN Name COMMA FormulaRole COMMA TffFormula COMMA Annotations RPAREN DOT
  {
  }
;
TcfAnnotated
: TCF LPAREN Name COMMA FormulaRole COMMA TcfFormula RPAREN DOT
  {
  }
| TCF LPAREN Name COMMA FormulaRole COMMA TcfFormula COMMA Annotations RPAREN DOT
  {
  }
;
FofAnnotated
: FOF LPAREN Name COMMA FormulaRole COMMA FofFormula RPAREN DOT
  {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(@$);
	auto formula = libtptp::make< FirstOrderFormula >(@$, logic);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| FOF LPAREN Name COMMA FormulaRole COMMA FofFormula COMMA Annotations RPAREN DOT
  {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(@$);
	auto formula = libtptp::make< FirstOrderFormula >(@$, logic);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
  }
;
CnfAnnotated
: CNF LPAREN Name COMMA FormulaRole COMMA CnfFormula RPAREN DOT
  {
  }
| CNF LPAREN Name COMMA FormulaRole COMMA CnfFormula COMMA Annotations RPAREN DOT
  {
  }
;
TpiAnnotated
:TPI LPAREN Name COMMA FormulaRole COMMA TpiFormula RPAREN DOT
  {
  }
| TPI LPAREN Name COMMA FormulaRole COMMA TpiFormula COMMA Annotations RPAREN DOT
  {
  }
;
/*
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
*/
/*
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
*/

Annotations
: GeneralTerm
  {
	$$ = libtptp::make< Annotation >(@$, $1);
    //source
  }
| GeneralTerm COMMA GeneralList
  {
    //source, optionalInfo
	$$ = libtptp::make< Annotation >(@$, $1, $2, $3);
  }
;
/*
Formula
: TpiFormula 
  {
  }
| ThfFormula
  {
  }
| TffFormula
  {
  }
| TcfFormula
  {
  }
| FofFormula
  {
  }
| CnfFormula
  {
  }
;
*/

TpiFormula
: FofFormula
  {
	//$$ = $1;
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
: ThfLogicFormula ASSIGNMENT ThfLogicFormula
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
: TfxLetLhs ASSIGNMENT TffTerm
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
	$$ = libtptp::make< FirstOrderFormula >(@$, $1);
  }
| FofSequent
  {
	$$ = libtptp::make< FirstOrderFormula >(@$, $1);
  }
;

FofLogicFormula
: FofBinaryFormula
  {
	$$ = $1;
  }
| FofUnaryFormula
  {
	$$ = $1;
  }
| FofUnitaryFormula
  {
	$$ = $1;
  }
;

FofBinaryFormula
: FofBinaryNonassoc
  {
	$$ = $1;
  }
| FofBinaryAssoc
  {
	$$ = $1;
  }
;

FofBinaryNonassoc
: FofUnitFormula NonassocConnective FofUnitFormula
  {
	$$ = libtptp::make< BinaryLogic >(@$, $1, $2, $3);
  }
;

FofBinaryAssoc
: FofOrFormula
  {
	$$ = $1;
  }
| FofAndFormula
  {
	$$ = $1;
  }
;

FofOrFormula
: FofUnitFormula VLINE FofUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| FofOrFormula VLINE FofUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

FofAndFormula
: FofUnitFormula AND FofUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| FofAndFormula AND FofUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

FofUnaryFormula
: UnaryConnective FofUnitFormula
  {
	$$ = libtptp::make< UnaryLogic >(@$, $1, $2);
  }
| FofInfixUnary
  {
	$$ = $1;
  }
;

FofInfixUnary
: FofTerm InfixInequality FofTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

FofUnitFormula
: FofUnitaryFormula
  {
	$$ = $1;
  }
| FofUnaryFormula
  {
	$$ = $1;
  }
;

FofUnitaryFormula
: FofQuantifiedFormula
  {
	$$ = $1;
  }
| FofAtomicFormula
  {
	$$ = $1;
  }
| LPAREN FofLogicFormula RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

FofQuantifiedFormula
: FofQuantifier LSQPAREN FofVariableList RSQPAREN COLON FofUnitFormula
  {
	auto variables = libtptp::make< ListLiteral >(@$, $2, $3, $4);
	$$ = libtptp::make< QuantifiedLogic >(@$, $1, variables, $5, $6);
  }
;

FofVariableList
: Variable
  {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< Nodes >(@$);
	variables->add($1);
	$$ = variables;
  }
| FofVariableList COMMA Variable
  {
	//TODO: @moosbruggerj use comma token
	auto variables = $1;
	variables->add($3);
	$$ = variables;
  }
;

FofAtomicFormula
: FofPlainAtomicFormula
  {
	$$ = $1;
  }
| FofDefinedAtomicFormula
  {
	$$ = $1;
  }
| FofSystemAtomicFormula
  {
	$$ = $1;
  }
;

FofPlainAtomicFormula
: FofPlainTerm
  {
	$$ = $1;
  }
;

FofDefinedAtomicFormula
: FofDefinedPlainFormula
  {
	$$ = $1;
  }
| FofDefinedInfixFormula
  {
	$$ = $1;
  }
;

FofDefinedPlainFormula
: FofDefinedPlainTerm
  {
	$$ = $1;
  }
;

FofDefinedInfixFormula
: FofTerm DefinedInfixPred FofTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

FofSystemAtomicFormula
: FofSystemTerm
  {
	$$ = $1;
  }
;

FofPlainTerm
: Constant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::PLAIN);
  }
| Functor LPAREN FofArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::PLAIN);
  }
;

FofDefinedTerm
: DefinedTerm
  {
	$$ = $1;
  }
| FofDefinedAtomicTerm
  {
	$$ = $1;
  }
;

FofDefinedAtomicTerm
: FofDefinedPlainTerm
  {
	$$ = $1;
  }
;

FofDefinedPlainTerm
: DefinedConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::DEFINED);
  }
| DefinedFunctor LPAREN FofArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::DEFINED);
  }
;

FofSystemTerm
: SystemConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::SYSTEM);
  }
| SystemFunctor LPAREN FofArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::SYSTEM);
  }
;

FofArguments
: FofTerm
  {
	auto terms = libtptp::make< Terms >(@$);
	terms->add($1);
	$$ = terms;
  }
| FofArguments COMMA FofTerm
  {
	//TODO: @moosbruggerj use comma token
	auto terms = $1;
	terms->add($3);
	$$ = terms;
  }
;

FofTerm
: FofFunctionTerm
  {
	$$ = $1;
  }
| Variable
  {
	$$ = $1;
  }
;

FofFunctionTerm
: FofPlainTerm
  {
	$$ = $1;
  }
| FofDefinedTerm
  {
	$$ = $1;
  }
| FofSystemTerm
  {
	$$ = $1;
  }
;

FofSequent
: FofFormulaTuple GENTZENARROW FofFormulaTuple
  {
	$$ = libtptp::make< SequentLogic >(@$, $1, $2, $3);
  }
| LPAREN FofSequent RPAREN
  {
	auto sequent = $2;
	sequent->setLeftDelimiter($1);
	sequent->setRightDelimiter($3);
  }
;

FofFormulaTuple
: LCURPAREN RCURPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2);
  }
| LCURPAREN FofFormulaTupleList RCURPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2, $3);
  }
;

FofFormulaTupleList
: FofLogicFormula
  {
	auto list = libtptp::make< Logics >(@$);
	list->add($1);
	$$ = list;
  }
| FofFormulaTupleList COMMA FofLogicFormula
  {
	//TODO: @moosbruggerj use comma token
	auto list = $1;
	list->add($3);
	$$ = list;
  }
;

CnfFormula
: Disjunction
  {
	$$ = $1;
  }
| LPAREN Disjunction RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

Disjunction
: Literal
  {
	$$ = $1;
  }
| Disjunction VLINE Literal
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

Literal
: FofAtomicFormula
  {
	$$ = $1;
  }
| TILDE FofAtomicFormula
  {
	auto op = std::make_pair($1, UnaryLogic::Connective::NEGATION);
	$$ = libtptp::make< UnaryLogic >(@$, op, $2);
  }
| FofInfixUnary
  {
	$$ = $1;
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
: EXCLAMATION GREATER
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
| DOUBLEAT PLUS
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
	auto tokens = libtptp::make< Tokens >(@$);
	tokens->add($1);
	$$ = std::make_pair(tokens, QuantifiedLogic::Quantifier::UNIVERSAL);
  }
| QUESTIONMARK
  {
	auto tokens = libtptp::make< Tokens >(@$);
	tokens->add($1);
	$$ = std::make_pair(tokens, QuantifiedLogic::Quantifier::UNIVERSAL);
  }
;

/* GENERAL */

NonassocConnective
: EQUALITY
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::EQUIVALENCE);
  }
| IMPLICATION
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::IMPLICATION);
  }
| RIMPLICATION
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
| INEQUALITY
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::NON_EQUIVALENCE);
  }
| NOR
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
| NAND
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
;

AssocConnective
: VLINE
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::DISJUNCTION);
  }
| AND
  {
	$$ = std::make_pair($1, BinaryLogic::Connective::CONJUNCTION);
  }
;

UnaryConnective
: TILDE
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::NEGATION);
  }
;

TypeConstant
: TypeFunctor
  {
  }
;

TypeFunctor
: AtomicWord
  {
  }
;

DefinedType
: AtomicDefinedWord
  {
  }
;

Atom
: UntypedAtom
  {
  }
| DefinedConstant
  {
  }
;

UntypedAtom
: Constant
  {
  }
| SystemConstant
  {
  }
;

DefinedInfixPred
: InfixEquality
  {
	$$ = $1;
  }
;

InfixEquality
: EQUAL
  {
	$$ = std::make_pair($1, InfixLogic::Connective::EQUALITY);
  }
;

InfixInequality
: INFIXINEQUALITY
  {
//EXCLAMATION EQUAL
	$$ = std::make_pair($1, InfixLogic::Connective::INEQUALITY);
  }
;

Constant
: Functor
  {
	$$ = $1;
  }
;

Functor
: AtomicWord
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

SystemConstant
: SystemFunctor
  {
	$$ = $1;
  }
;

SystemFunctor
: AtomicSystemWord
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

DefinedConstant
: DefinedFunctor
  {
	$$ = $1;
  }
;

DefinedFunctor
: AtomicDefinedWord
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

DefinedTerm
: Number
  {
	$$ = libtptp::make< DefinedAtom >(@$, $1);
  }
| DistinctObjectLiteral
  {
	$$ = libtptp::make< DefinedAtom >(@$, $1);
  }
;

NameList
: Name
  {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< Nodes >(@$);
	list->add($1);
	$$ = list;
  }
| NameList COMMA Name
  {
	//TODO: @moosbruggerj add delimiter
	const auto list = $1;
	const auto name = $3;
	//name->prefix().add($2); //setDelimiter
	list->add(name);
	$$ = list;
  }
;

Name
: AtomicWord
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
| IntegerLiteral
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

FormulaRole
: LowerWordLiteral
  {
    $$ = libtptp::make< FormulaRole >( @$, $1 );
  }
;

GeneralTerm
: GeneralData
  {
	$$ = $1;
  }
| GeneralData COLON GeneralTerm
  {
	$$ = libtptp::make< GeneralAggregator >(@$, $1, $2, $3);
  }
| GeneralList
  {
	$$ = $1;
  }
;

GeneralData
: AtomicWord
  {
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
| GeneralFunction
  {
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
| Variable
  {
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
| Number
  {
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
| DistinctObjectLiteral
  {
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
| FormulaData
  {
	//$$ = libtptp::make< GeneralData >(@$, $1);
	//TODO: @moosbruggerj remove wrong token
	$$ = libtptp::make< GeneralData >(@$, uToken);
  }
;

GeneralFunction
: AtomicWord LPAREN GeneralTerms RPAREN
  {
	auto name = libtptp::make< Identifier >(@1, $1);
	$$ = libtptp::make< GeneralFunction >(@$, name, $2, $3, $4);
  }
;

GeneralTerms
: GeneralTerm 
  {
	auto list = libtptp::make< Nodes >(@$);
	list->add($1);
	$$ = list;
  }
| GeneralTerms COMMA GeneralTerm
  {
	//TODO: @moosbruggerj use comma
	
    auto terms = $1;
    terms->add($3);
    $$ = terms;
  }
;

/*
FormulaData
: DOLLAR FormulaDataKeyword LPAREN Formula RPAREN
  {
  }
;
*/

FormulaData
: DOLLAR THF LPAREN ThfFormula RPAREN
  {
  }
| DOLLAR TFF LPAREN TffFormula RPAREN
  {
  }
| DOLLAR FOF LPAREN FofFormula RPAREN
  {
  }
| DOLLAR CNF LPAREN CnfFormula RPAREN
  {
  }
| DOLLAR FOT LPAREN FofTerm RPAREN
  {
  }
;

GeneralList
: LSQPAREN RSQPAREN
  {
	auto list = libtptp::make< ListLiteral >(@$, $1, $2);
	$$ = libtptp::make< GeneralList >(@$, list);
  }
| LSQPAREN GeneralTerms RSQPAREN
  {
	auto list = libtptp::make< ListLiteral >(@$, $1, $2, $3);
	$$ = libtptp::make< GeneralList >(@$, list);
  }
;


IncludeDefinition
: INCLUDE LPAREN FileName RPAREN DOT
  {
	const auto formulaSelection = libtptp::make< ListLiteral >(@5, uToken, uToken);
	$$ = libtptp::make< IncludeDefinition >(@$, $1, $2, $3, uToken, formulaSelection, $4, $5);
  }
| INCLUDE LPAREN FileName COMMA FormulaSelection RPAREN DOT
  {
	$$ = libtptp::make< IncludeDefinition >(@$, $1, $2, $3, $4, $5, $6, $7);
  }
;

FormulaSelection 
: LSQPAREN NameList RSQPAREN
  {
	auto list = libtptp::make< ListLiteral >(@$, $1, $2, $3);
	$$ = list;
  }
;

/*
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
*/

AtomicWord
: LowerWordLiteral
  {
	$$ = $1;
  }
| SingleQuotedLiteral
  {
	$$ = $1;
  }
;

AtomicDefinedWord
: DollarWordLiteral
  {
	$$ = $1;
  }
;

AtomicSystemWord
: DollarDollarWordLiteral
  {
	$$ = $1;
  }
;

Number
: IntegerLiteral
  {
    $$ = $1;
  }
| RealLiteral
  {
    $$ = $1;
  }
| RationalLiteral
  {
    $$ = $1;
  }
;

FileName
: SingleQuotedLiteral
  {
	$$ = libtptp::make<Identifier>(@$, $1);
  }
;

IntegerLiteral
: INTEGER
  {
	$$ = libtptp::make< IntegerLiteral >(@1, $1);
  }
;

RealLiteral
: REAL
  {
	$$ = libtptp::make< RealLiteral >(@$, $1);
  }
;
RationalLiteral
: RATIONAL
  {
	$$ = libtptp::make< RationalLiteral >(@$, $1);
  }
;

Variable
: UPPER_WORD
  {
	auto literal = libtptp::make< StringLiteral >(@$, $1);
	auto identifier = libtptp::make< Identifier >(@$, literal);
	$$ = libtptp::make< VariableTerm >(@$, identifier);
  }
;

DistinctObjectLiteral
: DQUOTED
  {
	$$ = libtptp::make< StringLiteral >(@$, $1);
  }
;

LowerWordLiteral
: LOWER_WORD
  {
	$$ = libtptp::make< StringLiteral >(@$, $1);
  }
;

SingleQuotedLiteral
: SINGLE_QUOTED
  {
	$$ = libtptp::make< StringLiteral >(@$, $1);
  }
;

DollarWordLiteral
: DOLLAR LOWER_WORD
  {
	$$ = libtptp::make< StringLiteral >(@$, $1, $2);
  }
;

DollarDollarWordLiteral
: DOLLAR DOLLAR LOWER_WORD
  {
	$$ = libtptp::make< StringLiteral >(@$, $1, $2, $3);
  }
;

%%

void Parser::error( const SourceLocation& location, const std::string& message )
{
    m_log.error( { location }, message ); //, Code::SyntaxError );
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

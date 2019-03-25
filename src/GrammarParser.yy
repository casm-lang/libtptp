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
	using QuantifiedQuantifier_t = std::pair<Token::Ptr, QuantifiedLogic::Quantifier>;
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

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = TokenBuilder::UNRESOLVED();
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

%type <FormulaDefinition::Ptr> AnnotatedFormula ThfAnnotated TffAnnotated TcfAnnotated FofAnnotated CnfAnnotated TpiAnnotated

%type <Identifier::Ptr> FileName Name Functor Constant DefinedFunctor DefinedConstant SystemFunctor SystemConstant TypeConstant TypeFunctor DefinedType Atom UntypedAtom
%type <ListNodeElements::Ptr> NameList
%type <ListLiteral::Ptr> FormulaSelection

// definitions
%type <IncludeDefinition::Ptr> IncludeDefinition
%type <Definition::Ptr> Definition
%type <Definitions::Ptr> Definitions

%type <Annotation::Ptr> Annotations

%type <Role::Ptr> FormulaRole
%type <FormulaData::Ptr> FormulaData
%type <BinaryLogic::Ptr> FofAndFormula FofOrFormula FofBinaryAssoc FofBinaryNonassoc FofBinaryFormula
%type <Logic::Ptr> FofUnaryFormula
%type <QuantifiedLogic::Ptr> FofQuantifiedFormula
%type <InfixLogic::Ptr> FofInfixUnary FofDefinedInfixFormula
%type <SequentLogic::Ptr> FofSequent
%type <Logic::Ptr> FofLogicFormula FofUnitFormula FofUnitaryFormula FofAtomicFormula FofDefinedAtomicFormula CnfFormula Literal Disjunction
%type <ListLogicElements::Ptr> FofFormulaTupleList FofArguments
%type <LogicTuple::Ptr> FofFormulaTuple

%type <Term::Ptr> FofTerm FofPlainAtomicFormula FofDefinedPlainFormula FofSystemAtomicFormula

%type <Atom::Ptr> FofFunctionTerm FofSystemTerm FofDefinedPlainTerm FofDefinedAtomicTerm FofDefinedTerm FofPlainTerm
%type <DefinedAtom::Ptr> DefinedTerm
%type <VariableTerm::Ptr> Variable

%type <Logic::Ptr> FofFormula TpiFormula

%type <Identifier::Ptr> SingleQuotedLiteral LowerWordLiteral AtomicWord DollarWordLiteral DollarDollarWordLiteral AtomicDefinedWord AtomicSystemWord 
%type <DistinctObjectLiteral::Ptr> DistinctObjectLiteral
%type <IntegerLiteral::Ptr> IntegerLiteral
%type <RationalLiteral::Ptr> RationalLiteral
%type <RealLiteral::Ptr> RealLiteral
%type <ValueLiteral::Ptr> Number
// %type <Atom::Ptr> Atom

%type <GeneralTerm::Ptr> GeneralTerm
%type <GeneralData::Ptr> GeneralData
%type <GeneralList::Ptr> GeneralList
%type <GeneralFunction::Ptr> GeneralFunction
%type <ListNodeElements::Ptr> GeneralTerms FofVariableList

%type <UnaryConnective_t> UnaryConnective
%type <BinaryConnective_t> AssocConnective NonassocConnective
%type <QuantifiedQuantifier_t> FofQuantifier
%type <InfixConnective_t> InfixInequality DefinedInfixPred InfixEquality

//Tff
%type <Logic::Ptr> TffFormula TffLogicFormula TffUnitFormula TffPreunitFormula TffUnitaryFormula TffUnaryFormula TfxLetDefns TfxLetLhs TffTerm TffUnitaryTerm
%type <BinaryLogic::Ptr> TffBinaryFormula TffBinaryNonassoc TffBinaryAssoc TffOrFormula TffAndFormula
%type <VariableTerm::Ptr> TfxUnitaryFormula TffVariable TffTypedVariable
%type <QuantifiedLogic::Ptr> TffQuantifiedFormula
%type <UnaryLogic::Ptr> TffPrefixUnary
%type <InfixLogic::Ptr> TffInfixUnary TffDefinedInfix
%type <LogicTuple::Ptr> TfxTuple
%type <SequentLogic::Ptr> TfxSequent
%type <ListLogicElements::Ptr> TfxLetDefnList TffArguments TffTypeArguments

%type <Term::Ptr> TffAtomicFormula TffDefinedAtomic TffDefinedPlain
%type <ConditionalTerm::Ptr> TfxConditional
%type <DefinitionTerm::Ptr> TfxLet

%type <Atom::Ptr> TffPlainAtomic TffSystemAtomic
%type <DefinitionAtom::Ptr> TfxLetDefn

%type <Type::Ptr> TfxLetTypes TffTopLevelType TffMonotype TffUnitaryType
%type <TypedAtom::Ptr> TffAtomTyping
%type <QuantifiedType::Ptr> Tf1QuantifiedType
%type <AtomType::Ptr> TffAtomicType
%type <BinaryType::Ptr> TffMappingType TffXprodType
%type <TupleType::Ptr> TfxTupleType
%type <SubType::Ptr> TffSubtype
%type <ListTypeElements::Ptr> TffAtomTypingList TffTypeList

%type <ListNodeElements::Ptr> TffVariableList

//THF
%type <Logic::Ptr> ThfFormula ThfLogicFormula  ThfBinaryFormula ThfUnitFormula ThfPreunitFormula ThfUnitaryFormula ThfUnaryFormula ThfAtomicFormula ThfPlainAtomic ThfLetDefns ThfUnitaryTerm
%type <BinaryLogic::Ptr> ThfBinaryNonassoc ThfBinaryAssoc ThfOrFormula ThfAndFormula ThfApplyFormula
%type <QuantifiedLogic::Ptr> ThfQuantifiedFormula
%type <UnaryLogic::Ptr> ThfPrefixUnary
%type <InfixLogic::Ptr> ThfInfixUnary ThfDefinedInfix
%type <LogicTuple::Ptr> ThfTuple
%type <SequentLogic::Ptr> ThfSequent
%type <ListLogicElements::Ptr> ThfLetDefnList ThfFormulaList ThfArguments

%type <Term::Ptr> ThfDefinedAtomic
%type <VariableTerm::Ptr> ThfTypedVariable
%type <ConditionalTerm::Ptr> ThfConditional
%type <DefinitionTerm::Ptr> ThfLet

%type <ConstantAtom::Ptr> ThfSystemAtomic
%type <FunctorAtom::Ptr> ThfFofFunction
%type <DefinitionAtom::Ptr> ThfLetDefn
%type <ConnectiveAtom::Ptr> ThfConnTerm
%type <TypedAtom::Ptr> ThfAtomTyping

%type <Type::Ptr> ThfLetTypes ThfTopLevelType
%type <AtomType::Ptr> ThfUnitaryType ThfApplyType
%type <BinaryType::Ptr> ThfBinaryType ThfMappingType ThfXprodType ThfUnionType
%type <SubType::Ptr> ThfSubtype
%type <ListTypeElements::Ptr> ThfAtomTypingList

%type <ListNodeElements::Ptr> ThfVariableList

%type <UnaryConnective_t> ThfUnaryConnective Th1UnaryConnective
%type <QuantifiedQuantifier_t> Th0Quantifier Th1Quantifier ThfQuantifier

//TCF
%type <Logic::Ptr> TcfFormula TcfLogicFormula
%type <QuantifiedLogic::Ptr> TcfQuantifiedFormula

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
    $$ = $1;
  }
| TffAnnotated
  {
    $$ = $1;
  }
| TcfAnnotated
  {
    $$ = $1;
  }
| FofAnnotated
  {
    $$ = $1;
  }
| CnfAnnotated
  {
    $$ = $1;
  }
| TpiAnnotated
  {
    $$ = $1;
  }
;

ThfAnnotated
: THF LPAREN Name COMMA FormulaRole COMMA ThfFormula RPAREN DOT
  {
	auto formula = libtptp::make< TypedHigherOrderFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| THF LPAREN Name COMMA FormulaRole COMMA ThfFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< TypedHigherOrderFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

TffAnnotated
: TFF LPAREN Name COMMA FormulaRole COMMA TffFormula RPAREN DOT
  {
	auto formula = libtptp::make< TypedFirstOrderFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| TFF LPAREN Name COMMA FormulaRole COMMA TffFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< TypedFirstOrderFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

TcfAnnotated
: TCF LPAREN Name COMMA FormulaRole COMMA TcfFormula RPAREN DOT
  {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| TCF LPAREN Name COMMA FormulaRole COMMA TcfFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

FofAnnotated
: FOF LPAREN Name COMMA FormulaRole COMMA FofFormula RPAREN DOT
  {
	auto formula = libtptp::make< FirstOrderFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| FOF LPAREN Name COMMA FormulaRole COMMA FofFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< FirstOrderFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

CnfAnnotated
: CNF LPAREN Name COMMA FormulaRole COMMA CnfFormula RPAREN DOT
  {
	auto formula = libtptp::make< ClauseNormalFormFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| CNF LPAREN Name COMMA FormulaRole COMMA CnfFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< ClauseNormalFormFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

TpiAnnotated
: TPI LPAREN Name COMMA FormulaRole COMMA TpiFormula RPAREN DOT
  {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(@7, $7);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $8, $9);
  }
| TPI LPAREN Name COMMA FormulaRole COMMA TpiFormula COMMA Annotations RPAREN DOT
  {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(@7, $7);
	auto annotation = $9;
	annotation->setDelimiter($8);
	formula->setAnnotations(annotation);
	$$ = libtptp::make< FormulaDefinition >(@$, $1, $2, $3, $4, $5, $6, formula, $10, $11);
  }
;

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

TpiFormula
: FofFormula
  {
	$$ = $1;
  }
;

ThfFormula
: ThfLogicFormula
  {
	$$ = $1;
  }
| ThfAtomTyping
  {
	$$ = $1;
  }
| ThfSubtype
  {
	$$ = $1;
  }
| ThfSequent
  {
	$$ = $1;
  }
;

ThfLogicFormula
: ThfUnitaryFormula
  {
	$$ = $1;
  }
| ThfUnaryFormula
  {
	$$ = $1;
  }
| ThfBinaryFormula
  {
	$$ = $1;
  }
| ThfDefinedInfix
  {
	$$ = $1;
  }
;

ThfBinaryFormula
: ThfBinaryNonassoc
  {
	$$ = $1;
  }
| ThfBinaryAssoc
  {
	$$ = $1;
  }
| ThfBinaryType
  {
	$$ = $1;
  }
;

ThfBinaryNonassoc
: ThfUnitFormula NonassocConnective ThfUnitFormula
  {
	$$ = libtptp::make< BinaryLogic >(@$, $1, $2, $3);
  }
;

ThfBinaryAssoc
: ThfOrFormula
  {
	$$ = $1;
  }
| ThfAndFormula
  {
	$$ = $1;
  }
| ThfApplyFormula
  {
	$$ = $1;
  }
;

ThfOrFormula
: ThfUnitFormula VLINE ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| ThfOrFormula VLINE ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

ThfAndFormula
: ThfUnitFormula AND ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| ThfAndFormula AND ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

ThfApplyFormula
: ThfUnitFormula AT ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::APPLY);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| ThfApplyFormula AT ThfUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::APPLY);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

ThfUnitFormula
: ThfUnitaryFormula
  {
	$$ = $1;
  }
| ThfUnaryFormula
  {
	$$ = $1;
  }
| ThfDefinedInfix
  {
	$$ = $1;
  }
;

ThfPreunitFormula
: ThfUnitaryFormula
  {
	$$ = $1;
  }
| ThfPrefixUnary
  {
	$$ = $1;
  }
;

ThfUnitaryFormula
: ThfQuantifiedFormula
  {
	$$ = $1;
  }
| ThfAtomicFormula
  {
	$$ = $1;
  }
| Variable
  {
	$$ = $1;
  }
| LPAREN ThfLogicFormula RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

ThfQuantifiedFormula
: ThfQuantifier LSQPAREN ThfVariableList RSQPAREN COLON ThfUnitFormula
  {
	auto variables = libtptp::make< ListLiteral >(@$, $2, $3, $4);
	$$ = libtptp::make< QuantifiedLogic >(@$, $1, variables, $5, $6);
  }
;

ThfVariableList
: ThfTypedVariable
  {
	auto list = libtptp::make< ListNodeElements >(@$);
	list->add($1);
	$$ = list;
  }
| ThfVariableList COMMA ThfTypedVariable
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

ThfTypedVariable
: Variable COLON ThfTopLevelType
  {
	auto var = $1;
	var->setColon($2);
	Type::Ptr type = $3;
	var->setType(type);
  }
;

ThfUnaryFormula
: ThfPrefixUnary
  {
	$$ = $1;
  }
| ThfInfixUnary
  {
	$$ = $1;
  }
;

ThfPrefixUnary
: ThfUnaryConnective ThfPreunitFormula
  {
	$$ = libtptp::make< UnaryLogic >(@$, $1, $2);
  }
;

ThfInfixUnary
: ThfUnitaryTerm InfixInequality ThfUnitaryTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

ThfAtomicFormula
: ThfPlainAtomic
  {
	$$ = $1;
  }
| ThfDefinedAtomic
  {
	$$ = $1;
  }
| ThfSystemAtomic
  {
	$$ = $1;
  }
| ThfFofFunction
  {
	$$ = $1;
  }
;

ThfPlainAtomic
: Constant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::PLAIN);
  }
| ThfTuple
  {
	$$ = $1;
  }
;

ThfDefinedAtomic
: DefinedConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::DEFINED);
  }
| ThfConditional
  {
	$$ = $1;
  }
| ThfLet
  {
	$$ = $1;
  }
| LPAREN ThfConnTerm RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
| DefinedTerm
  {
	$$ = $1;
  }
;

ThfDefinedInfix
: ThfUnitaryTerm DefinedInfixPred ThfUnitaryTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

ThfSystemAtomic
: SystemConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::SYSTEM);
  }
;

ThfFofFunction
: Functor LPAREN ThfArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::PLAIN);
  }
| DefinedFunctor LPAREN ThfArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::DEFINED);
  }
| SystemFunctor LPAREN ThfArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::SYSTEM);
  }
;

ThfConditional
: DOLLAR ITE LPAREN ThfLogicFormula COMMA ThfLogicFormula COMMA ThfLogicFormula RPAREN
  {
	$$ = libtptp::make< ConditionalTerm >(@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
  }
;

ThfLet
: DOLLAR LET LPAREN ThfLetTypes COMMA ThfLetDefns COMMA ThfFormula RPAREN
  {
	$$ = libtptp::make< DefinitionTerm >(@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
  }
;

ThfLetTypes
: ThfAtomTyping
  {
	$$ = $1;
  }
| LSQPAREN ThfAtomTypingList RSQPAREN
  {
	$$ = libtptp::make< TupleType >(@$, $1, $2, $3);
  }
;

ThfAtomTypingList
: ThfAtomTyping
  {
	auto list = libtptp::make< ListTypeElements >(@$);
	list->add($1);
	$$ = list;
  }
| ThfAtomTypingList COMMA ThfAtomTyping
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

ThfLetDefns
: ThfLetDefn
  {
	$$ = $1;
  }
| LSQPAREN ThfLetDefnList RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2, $3);
  }
;

ThfLetDefn
: ThfLogicFormula ASSIGNMENT ThfLogicFormula
  {
	$$ = libtptp::make< DefinitionAtom >(@$, $1, $2, $3);
  }
;

ThfLetDefnList
: ThfLetDefn
  {
	//could be of type DefinitionAtoms, but Logics is expected
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| ThfLetDefnList COMMA ThfLetDefn
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

ThfUnitaryTerm
: ThfAtomicFormula
  {
	$$ = $1;
  }
| Variable
  {
	$$ = $1;
  }
| LPAREN ThfLogicFormula RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

ThfTuple
: LSQPAREN RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2);
  }
| LSQPAREN ThfFormulaList RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2, $3);
  }
;

ThfFormulaList
: ThfLogicFormula
  {
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| ThfFormulaList COMMA ThfLogicFormula 
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

ThfConnTerm
: NonassocConnective
  {
	auto pair = $1;
	$$ = libtptp::make< ConnectiveAtom >(@$, pair.first);
  }
| AssocConnective
  {
	auto pair = $1;
	$$ = libtptp::make< ConnectiveAtom >(@$, pair.first);
  }
| InfixEquality
  {
	auto pair = $1;
	$$ = libtptp::make< ConnectiveAtom >(@$, pair.first);
  }
| ThfUnaryConnective
  {
	auto pair = $1;
	$$ = libtptp::make< ConnectiveAtom >(@$, pair.first);
  }
;

ThfArguments
: ThfFormulaList
  {
	$$ = $1;
  }
;

ThfAtomTyping
: UntypedAtom COLON ThfTopLevelType
  {
	$$ = libtptp::make< TypedAtom >(@$, $1, $2, $3);
  }
| LPAREN ThfAtomTyping RPAREN
  {
	auto type = $2;
	type->setLeftDelimiter($1);
	type->setRightDelimiter($3);
	$$ = type;
  }
;

ThfTopLevelType
: ThfUnitaryType
  {
	$$ = $1;
  }
| ThfMappingType
  {
	$$ = $1;
  }
| ThfApplyType
  {
	$$ = $1;
  }
;

ThfUnitaryType
: ThfUnitaryFormula
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
;

ThfApplyType
: ThfApplyFormula
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
;

ThfBinaryType
: ThfMappingType
  {
	$$ = $1;
  }
| ThfXprodType
  {
	$$ = $1;
  }
| ThfUnionType
  {
	$$ = $1;
  }
;

//right associative
ThfMappingType
: ThfUnitaryType GREATER ThfUnitaryType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::MAPPING);
  }
| ThfUnitaryType GREATER ThfMappingType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::MAPPING);
  }
;

//left associative
ThfXprodType
: ThfUnitaryType STAR ThfUnitaryType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::XPROD);
  }
| ThfXprodType STAR ThfUnitaryType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::XPROD);
  }
;

//left associative
ThfUnionType
: ThfUnitaryType PLUS ThfUnitaryType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::UNION);
  }
| ThfUnionType PLUS ThfUnitaryType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::UNION);
  }
;

ThfSubtype
: UntypedAtom SUBTYPESIGN Atom
  {
	$$ = libtptp::make< SubType >(@$, $1, $2, $3);
  }
;

ThfSequent
: ThfTuple GENTZENARROW ThfTuple
  {
	$$ = libtptp::make< SequentLogic >(@$, $1, $2, $3);
  }
| LPAREN ThfSequent RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

/* TFF */
TffFormula
: TffLogicFormula
  {
	$$ = $1;
  }
| TffAtomTyping
  {
	$$ = $1;
  }
| TffSubtype
  {
	$$ = $1;
  }
| TfxSequent
  {
	$$ = $1;
  }
;

TffLogicFormula
: TffUnitaryFormula
  {
	$$ = $1;
  }
| TffUnaryFormula
  {
	$$ = $1;
  }
| TffBinaryFormula
  {
	$$ = $1;
  }
| TffDefinedInfix
  {
	$$ = $1;
  }
;

TffBinaryFormula
: TffBinaryNonassoc
  {
	$$ = $1;
  }
| TffBinaryAssoc
  {
	$$ = $1;
  }
;

TffBinaryNonassoc
: TffUnitFormula NonassocConnective TffUnitFormula
  {
	$$ = libtptp::make< BinaryLogic >(@$, $1, $2, $3);
  }
;

TffBinaryAssoc
: TffOrFormula
  {
	$$ = $1;
  }
| TffAndFormula
  {
	$$ = $1;
  }
;

TffOrFormula
: TffUnitFormula VLINE TffUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| TffOrFormula VLINE TffUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::DISJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

TffAndFormula
: TffUnitFormula AND TffUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
| TffAndFormula AND TffUnitFormula
  {
	auto op = std::make_pair($2, BinaryLogic::Connective::CONJUNCTION);
	$$ = libtptp::make< BinaryLogic >(@$, $1, op, $3);
  }
;

TffUnitFormula
: TffUnitaryFormula
  {
	$$ = $1;
  }
| TffUnaryFormula
  {
	$$ = $1;
  }
| TffDefinedInfix
  {
	$$ = $1;
  }
;

TffPreunitFormula
: TffUnitaryFormula
  {
	$$ = $1;
  }
| TffPrefixUnary
  {
	$$ = $1;
  }
;

TffUnitaryFormula
: TffQuantifiedFormula
  {
	$$ = $1;
  }
| TffAtomicFormula
  {
	$$ = $1;
  }
| TfxUnitaryFormula
  {
	$$ = $1;
  }
| LPAREN TffLogicFormula RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

TfxUnitaryFormula
: Variable
  {
	$$ = $1;
  }
;

TffQuantifiedFormula
: FofQuantifier LSQPAREN TffVariableList RSQPAREN COLON TffUnitFormula
  {
	auto list = libtptp::make< ListLiteral >(@3, $2, $3, $4);
	$$ = libtptp::make< QuantifiedLogic >(@$, $1, list, $5, $6);
  }
;

TffVariableList
: TffVariable
  {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< ListNodeElements >(@$);
	list->add($1);
	$$ = list;
  }
| TffVariableList COMMA TffVariable
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TffVariable
: TffTypedVariable
  {
	$$ = $1;
  }
| Variable
  {
	$$ = $1;
  }
;

TffTypedVariable
: Variable COLON TffAtomicType
  {
	auto variable = $1;
	variable->setColon($2);
	Type::Ptr type = $3; //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	$$ = variable;
  }
;

TffUnaryFormula
: TffPrefixUnary
  {
	$$ = $1;
  }
| TffInfixUnary
  {
	$$ = $1;
  }
;

TffPrefixUnary
: UnaryConnective TffPreunitFormula
  {
	$$ = libtptp::make< UnaryLogic >(@$, $1, $2);
  }
;

TffInfixUnary
: TffUnitaryTerm InfixInequality TffUnitaryTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

TffAtomicFormula
: TffPlainAtomic
  {
	$$ = $1;
  }
| TffDefinedAtomic
  {
	$$ = $1;
  }
| TffSystemAtomic
  {
	$$ = $1;
  }
;

TffPlainAtomic
: Constant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::PLAIN);
  }
| Functor LPAREN TffArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::PLAIN);
  }
;

TffDefinedAtomic
: TffDefinedPlain
  {
	$$ = $1;
  }
;

TffDefinedPlain
: DefinedConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::DEFINED);
  }
| DefinedFunctor LPAREN TffArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::DEFINED);
  }
| TfxConditional
  {
	$$ = $1;
  }
| TfxLet
  {
	$$ = $1;
  }
;

TffDefinedInfix
: TffUnitaryTerm DefinedInfixPred TffUnitaryTerm
  {
	$$ = libtptp::make< InfixLogic >(@$, $1, $2, $3);
  }
;

TffSystemAtomic
: SystemConstant
  {
	$$ = libtptp::make< ConstantAtom >(@$, $1, Atom::Kind::SYSTEM);
  }
| SystemFunctor LPAREN TffArguments RPAREN
  {
	$$ = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::SYSTEM);
  }
;

TfxConditional
: DOLLAR ITE LPAREN TffLogicFormula COMMA TffTerm COMMA TffTerm RPAREN
  {
	$$ = libtptp::make< ConditionalTerm >(@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
  }
;

TfxLet
: DOLLAR LET LPAREN TfxLetTypes COMMA TfxLetDefns COMMA TffTerm RPAREN
  {
	$$ = libtptp::make< DefinitionTerm >(@$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
  }
;

TfxLetTypes
: TffAtomTyping
  {
	$$ = $1;
  }
| LSQPAREN TffAtomTypingList RSQPAREN
  {
	$$ = libtptp::make< TupleType >(@$, $1, $2, $3);
  }
;

TffAtomTypingList
: TffAtomTyping
  {
	auto list = libtptp::make< ListTypeElements >(@$);
	list->add($1);
	$$ = list;
  }
| TffAtomTypingList COMMA TffAtomTyping
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TfxLetDefns
: TfxLetDefn
  {
	$$ = $1;
  }
| LSQPAREN TfxLetDefnList RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2, $3);
  }
;

TfxLetDefn
: TfxLetLhs ASSIGNMENT TffTerm
  {
	$$ = libtptp::make< DefinitionAtom >(@$, $1, $2, $3);
  }
;

TfxLetLhs
: TffPlainAtomic
  {
	$$ = $1;
  }
| TfxTuple
  {
	$$ = $1;
  }
;

TfxLetDefnList
: TfxLetDefn
  {
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| TfxLetDefnList COMMA TfxLetDefn
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TffTerm
: TffLogicFormula
  {
	$$ = $1;
  }
| DefinedTerm
  {
	$$ = $1;
  }
| TfxTuple
  {
	$$ = $1;
  }
;

TffUnitaryTerm
: TffAtomicFormula
  {
	$$ = $1;
  }
| DefinedTerm
  {
	$$ = $1;
  }
| TfxTuple
  {
	$$ = $1;
  }
| Variable
  {
	$$ = $1;
  }
| LPAREN TffLogicFormula RPAREN
  {
	auto logic = $2;
	logic->setLeftDelimiter($1);
	logic->setRightDelimiter($3);
	$$ = logic;
  }
;

TfxTuple
: LSQPAREN RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2);
  }
| LSQPAREN TffArguments RSQPAREN
  {
	$$ = libtptp::make< LogicTuple >(@$, $1, $2, $3);
  }
;

TffArguments
: TffTerm
  {
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| TffArguments COMMA TffTerm 
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TffAtomTyping
: UntypedAtom COLON TffTopLevelType
  {
	$$ = libtptp::make< TypedAtom >(@$, $1, $2, $3);
  }
| LPAREN TffAtomTyping RPAREN
  {
	auto type = $2;
	type->setLeftDelimiter($1);
	type->setRightDelimiter($3);
	$$ = type;
  }
;

TffTopLevelType
: TffAtomicType
  {
	$$ = $1;
  }
| TffMappingType
  {
	$$ = $1;
  }
| Tf1QuantifiedType
  {
	$$ = $1;
  }
| LPAREN TffTopLevelType RPAREN
  {
	auto type = $2;
	type->setLeftDelimiter($1);
	type->setRightDelimiter($3);
	$$ = type;
  }
;

Tf1QuantifiedType
: EXCLAMATIONGREATER LSQPAREN TffVariableList RSQPAREN COLON TffMonotype
  {
	$$ = libtptp::make< QuantifiedType >(@$, $1, $2, $3, $4, $5, $6);
  }
;

TffMonotype
: TffAtomicType
  {
	$$ = $1;
  }
| LPAREN TffMappingType RPAREN
  {
	auto type = $2;
	type->setLeftDelimiter($1);
	type->setRightDelimiter($3);
	$$ = type;
  }
;

TffUnitaryType
: TffAtomicType
  {
	$$ = $1;
  }
| LPAREN TffXprodType RPAREN
  {
	auto type = $2;
	type->setLeftDelimiter($1);
	type->setRightDelimiter($3);
	$$ = type;
  }
;

TffAtomicType
: TypeConstant
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
| DefinedType
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
| TypeFunctor LPAREN TffTypeArguments RPAREN
  {
	auto functor = libtptp::make< FunctorAtom >(@$, $1, $2, $3, $4, Atom::Kind::TYPE);
	$$ = libtptp::make< AtomType >(@$, functor);
  }
| Variable
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
| TfxTupleType
  {
	$$ = libtptp::make< AtomType >(@$, $1);
  }
;

TffTypeArguments
: TffAtomicType
  {
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| TffTypeArguments COMMA TffAtomicType
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TffMappingType
: TffUnitaryType GREATER TffAtomicType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::MAPPING);
  }
;

TffXprodType
: TffUnitaryType STAR TffAtomicType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::XPROD);
  }
| TffXprodType STAR TffAtomicType
  {
	$$ = libtptp::make< BinaryType >(@$, $1, $2, $3, BinaryType::Kind::XPROD);
  }
;

TfxTupleType
: LSQPAREN TffTypeList RSQPAREN
  {
	$$ = libtptp::make< TupleType >(@$, $1, $2, $3);
  }
;

TffTypeList
: TffTopLevelType
  {
	auto list = libtptp::make< ListTypeElements >(@$);
	list->add($1);
	$$ = list;
  }
| TffTypeList COMMA TffTopLevelType
  {
	auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

TffSubtype
: UntypedAtom SUBTYPESIGN Atom
  {
	$$ = libtptp::make< SubType >(@$, $1, $2, $3);
  }
;

TfxSequent
: TfxTuple GENTZENARROW TfxTuple
  {
	$$ = libtptp::make< SequentLogic >(@$, $1, $2, $3);
  }
| LPAREN TfxSequent RPAREN
  {
	auto sequent = $2;
	sequent->setLeftDelimiter($1);
	sequent->setRightDelimiter($3);
	$$ = sequent;
  }
;

/* TCF */
TcfFormula
: TcfLogicFormula
  {
	$$ = $1;
  }
| TffAtomTyping
  {
	$$ = $1;
  }
;

TcfLogicFormula
: TcfQuantifiedFormula
  {
	$$ = $1;
  }
| CnfFormula
  {
	$$ = $1;
  }
;

TcfQuantifiedFormula
: EXCLAMATION LSQPAREN TffVariableList RSQPAREN COLON CnfFormula
  {
	auto op = std::make_pair($1, QuantifiedLogic::Quantifier::UNIVERSAL);
	auto list = libtptp::make< ListLiteral >(@$, $2, $3, $4);
	$$ = libtptp::make< QuantifiedLogic >(@$, op, list, $5, $6);
  }
;

/* FoF */

FofFormula
: FofLogicFormula
  {
	$$ = $1;
  }
| FofSequent
  {
	$$ = $1;
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
	auto variables = libtptp::make< ListNodeElements >(@$);
	variables->add($1);
	$$ = variables;
  }
| FofVariableList COMMA Variable
  {
	auto variables = $1;
	variables->add($2, $3);
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
	auto terms = libtptp::make< ListLogicElements >(@$);
	terms->add($1);
	$$ = terms;
  }
| FofArguments COMMA FofTerm
  {
	auto terms = $1;
	terms->add($2, $3);
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
	auto list = libtptp::make< ListLogicElements >(@$);
	list->add($1);
	$$ = list;
  }
| FofFormulaTupleList COMMA FofLogicFormula
  {
	auto list = $1;
	list->add($2, $3);
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
	$$ = $1;
  }
| Th0Quantifier
  {
	$$ = $1;
  }
| Th1Quantifier
  {
	$$ = $1;
  }
;

Th1Quantifier
: EXCLAMATIONGREATER
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
| QUESTIONMARKSTAR
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
;

Th0Quantifier
: CARET
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::CARET);
  }
| ATPLUS
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::ATPLUS);
  }
| ATMINUS
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::ATMINUS);
  }
;

ThfUnaryConnective
: UnaryConnective
  {
	$$ = $1;
  }
| Th1UnaryConnective
  {
	$$ = $1;
  }
;

Th1UnaryConnective
: DOUBLEEXCLAMATION
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
| DOUBLEQUESTIONMARK
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
| DOUBLEATPLUS
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
| DOUBLEATMINUS
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
| ATEQUAL
  {
	$$ = std::make_pair($1, UnaryLogic::Connective::EQUALITY);
  }
;

FofQuantifier
: EXCLAMATION
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::UNIVERSAL);
  }
| QUESTIONMARK
  {
	$$ = std::make_pair($1, QuantifiedLogic::Quantifier::UNIVERSAL);
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
	$$ = $1;
  }
;

TypeFunctor
: AtomicWord
  {
	$$ = $1;
  }
;

DefinedType
: AtomicDefinedWord
  {
	$$ = $1;
  }
;

Atom
: UntypedAtom
  {
	$$ = $1;
  }
| DefinedConstant
  {
	$$ = $1;
  }
;

UntypedAtom
: Constant
  {
	$$ = $1;
  }
| SystemConstant
  {
	$$ = $1;
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
	$$ = $1;
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
	$$ = $1;
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
	$$ = $1;
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
	const auto list = libtptp::make< ListNodeElements >(@$);
	list->add($1);
	$$ = list;
  }
| NameList COMMA Name
  {
	const auto list = $1;
	list->add($2, $3);
	$$ = list;
  }
;

Name
: AtomicWord
  {
	$$ = $1;
  }
| INTEGER
  {
	$$ = libtptp::make< Identifier >(@$, $1, Identifier::Kind::NUMBER);
  }
;

FormulaRole
: LowerWordLiteral
  {
    $$ = libtptp::make< Role >( @$, $1 );
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
	$$ = libtptp::make< GeneralData >(@$, $1);
  }
;

GeneralFunction
: AtomicWord LPAREN GeneralTerms RPAREN
  {
	$$ = libtptp::make< GeneralFunction >(@$, $1, $2, $3, $4);
  }
;

GeneralTerms
: GeneralTerm 
  {
	auto list = libtptp::make< ListNodeElements >(@$);
	list->add($1);
	$$ = list;
  }
| GeneralTerms COMMA GeneralTerm
  {
    auto terms = $1;
    terms->add($2, $3);
    $$ = terms;
  }
;

FormulaData
: DOLLAR THF LPAREN ThfFormula RPAREN
  {
	$$ = libtptp::make< FormulaData >(@$, $1, $2, $3, $4, $5);
  }
| DOLLAR TFF LPAREN TffFormula RPAREN
  {
	$$ = libtptp::make< FormulaData >(@$, $1, $2, $3, $4, $5);
  }
| DOLLAR FOF LPAREN FofFormula RPAREN
  {
	$$ = libtptp::make< FormulaData >(@$, $1, $2, $3, $4, $5);
  }
| DOLLAR CNF LPAREN CnfFormula RPAREN
  {
	$$ = libtptp::make< FormulaData >(@$, $1, $2, $3, $4, $5);
  }
| DOLLAR FOT LPAREN FofTerm RPAREN
  {
	$$ = libtptp::make< FormulaData >(@$, $1, $2, $3, $4, $5);
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
	$$ = $1;
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
	auto identifier = libtptp::make< Identifier >(@$, $1);
	$$ = libtptp::make< VariableTerm >(@$, identifier);
  }
;

DistinctObjectLiteral
: DQUOTED
  {
	$$ = libtptp::make< DistinctObjectLiteral >(@$, $1);
  }
;

LowerWordLiteral
: LOWER_WORD
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

SingleQuotedLiteral
: SINGLE_QUOTED
  {
	$$ = libtptp::make< Identifier >(@$, $1);
  }
;

DollarWordLiteral
: DOLLAR LOWER_WORD
  {
	$$ = libtptp::make< Identifier >(@$, $1, $2);
  }
;

DollarDollarWordLiteral
: DOLLARDOLLAR LOWER_WORD
  {
	$$ = libtptp::make< Identifier >(@$, $1, $2);
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

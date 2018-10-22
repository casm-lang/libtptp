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
| DUMMY DUMMY DUMMY Identifier IntegerLiteral
  {
      // m_specification.set ... ( $1 );
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
: Identifier
  {
    //TODO: wrong rule
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
| GeneralTerm COMMA GeneralTerms
  {
    //auto terms = $3;
    //terms->add($1);
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

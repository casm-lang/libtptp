%{
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

#include <libtptp/Logger>
#include <libtptp/Token>

using namespace libtptp;

#undef YY_DECL
#define YY_DECL Parser::symbol_type Lexer::nextToken()

#define yyterminate() return( Parser::make_END(m_loc) )

// Code run each time a pattern is matched.
#define YY_USER_ACTION m_loc.columns( yyleng );

// Code run each time a token is matched, see GrammarToken.hpp.
#define YY_TOKEN_ACTION( TOKEN ) \
    return Parser::make_##TOKEN( libtptp::make< Token >( m_loc, Grammar::Token:: TOKEN ), m_loc );

%}

%option c++
%option yyclass="Lexer"
%option prefix="libtptp_"
%option noyywrap
%option nodefault
%option nounput
%option noinput
%option batch
/* %option debug */

%x LCOMMENT
%x COMMENT
%x DQUOTED
%x SQUOTED

%%
%{
    // Code run each time yylex is called.
    m_loc.step();
%}

[+-]?[0-9]*((\.[0-9]+([eE][-+]?[0-9]+)?)|([eE][-+]?[0-9]+)) {
	//real: make eiter the dot or the exponent mandatory, both are possible
	//below shortened rule, which doesn't enforce eiter a dot or exponent to be present,
	//therefore it collides with the integer rule
	//[+-]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
	return Parser::make_REAL( yytext, m_loc );
}

[+-]?[0-9]*\/[1-9][0-9]* {
	//rational
	return Parser::make_RATIONAL( yytext, m_loc);
}

[+-]?[0-9]+ {
    return Parser::make_INTEGER( yytext, m_loc );
}

{{grammartoken}}

[a-z][a-zA-Z0-9_]* {
	return Parser::make_LOWER_WORD( yytext, m_loc );
}

[A-Z][a-zA-Z0-9_]* {
	return Parser::make_UPPER_WORD( yytext, m_loc );
}

[a-zA-Z_][a-zA-Z0-9\_]* {
    return Parser::make_IDENTIFIER( yytext, m_loc );
}

[\x20]+ { // space
    m_loc.step();
}

[\r]+ { // carriage return
    m_loc.step();
}

[\t]+ { // tabulator
    m_loc.step();
}

[\n]+ { // newline
    m_loc.lines( yyleng );
    m_loc.step();
}

"%" { // single-line comments
    m_strbuf.clear();
    m_strbuf.append( yytext );
    BEGIN( LCOMMENT );
}
<LCOMMENT>. {
    m_strbuf.append( yytext );
}
<LCOMMENT>\n {
    unput( *yytext );
    m_loc.columns( -1 );
    m_loc.step();
    BEGIN( INITIAL );
}
<LCOMMENT><<EOF>> {
    BEGIN( INITIAL );
}

"/*" { // multi-line comments
    m_strbuf.clear();
    m_strbuf.append( yytext );
    BEGIN( COMMENT );
}
<COMMENT>"*/" {
    m_strbuf.append( yytext );
    m_loc.step();
    BEGIN( INITIAL );
}
<COMMENT>\n {
    m_strbuf.append( yytext );
    m_loc.lines( 1 );
}
<COMMENT>([^*\n]|\r)+|. {
    m_strbuf.append( yytext );
}
<COMMENT><<EOF>> {
    m_log.error( { m_loc }, "multiline comment not terminated" );
    BEGIN( INITIAL );
    yyterminate();
}

\' { // Single quoted strings
    m_strbuf.clear();
    BEGIN( SQUOTED );
}
<SQUOTED>[^\\'\n]* { /* eat all tokens */
    m_strbuf.append( yytext );
}
<SQUOTED>\n {
    m_loc.lines( 1 );
}
<SQUOTED>\\n {
    m_strbuf.append( "\n" );
}
<SQUOTED>\\t {
    m_strbuf.append( "\t" );
}
<SQUOTED>\\['\\] {
    m_strbuf.append( yytext + 1 );
}
<SQUOTED>\\. {
    m_log.error( { m_loc }, "unrecognized escape sequence" );
}
<SQUOTED><<EOF>> {
    m_log.error( { m_loc }, "string not terminated" );
    BEGIN( INITIAL );
    yyterminate();
}
<SQUOTED>\' {
    BEGIN( INITIAL );
    return Parser::make_SINGLE_QUOTED( m_strbuf, m_loc );
}

\" { // strings
    m_strbuf.clear();
    BEGIN( DQUOTED );
}
<DQUOTED>[\40-\41\43-\133\135-\176]* { /* eat all tokens from space to ~, except " and \ */
    m_strbuf.append( yytext );
}
<DQUOTED>\n {
	//double quoted string must not contain newlines
    m_loc.lines( 1 );
    m_log.error( { m_loc }, "string not terminated" );
    BEGIN( INITIAL );
    yyterminate();
}
<DQUOTED>\\["\\] {
    m_strbuf.append( yytext + 1 );
}
<DQUOTED>\\. {
    m_log.error( { m_loc }, "unrecognized escape sequence" );
}
<DQUOTED><<EOF>> {
    m_log.error( { m_loc }, "string not terminated" );
    BEGIN( INITIAL );
    yyterminate();
}
<DQUOTED>\" {
    BEGIN( INITIAL );
    return Parser::make_DQUOTED( m_strbuf, m_loc );
}

. {
    m_log.error( { m_loc }, "unrecognized character `" + std::string( yytext ) + "`" );
    m_loc.step();
}

%%

//  
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//  

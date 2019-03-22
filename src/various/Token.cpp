//
//  Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
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

#include "Token.h"
#include <cassert>

using namespace libtptp;

namespace libtptp
{
    namespace Grammar
    {
        static std::string tokenAsString( const Token token )
        {
            switch( token )
            {
                case /*  0 */ Token::UNRESOLVED:
                {
                    return "$unresolved$";
                }
                case /*  1 */ Token::TPI:
                {
                    return "tpi";
                }
                case /*  2 */ Token::THF:
                {
                    return "thf";
                }
                case /*  3 */ Token::TFF:
                {
                    return "tff";
                }
                case /*  4 */ Token::TCF:
                {
                    return "tcf";
                }
                case /*  5 */ Token::FOF:
                {
                    return "fof";
                }
                case /*  6 */ Token::CNF:
                {
                    return "cnf";
                }
                case /*  7 */ Token::FOT:
                {
                    return "fot";
                }
                case /*  8 */ Token::ITE:
                {
                    return "ite";
                }
                case /*  9 */ Token::LET:
                {
                    return "let";
                }
                case /* 10 */ Token::AT:
                {
                    return "@";
                }
                case /* 11 */ Token::AND:
                {
                    return "&";
                }
                case /* 12 */ Token::DOLLAR:
                {
                    return "$";
                }
                case /* 13 */ Token::COLON:
                {
                    return ":";
                }
                case /* 14 */ Token::COMMA:
                {
                    return ",";
                }
                case /* 15 */ Token::DOT:
                {
                    return ".";
                }
                case /* 16 */ Token::PLUS:
                {
                    return "+";
                }
                case /* 17 */ Token::EQUAL:
                {
                    return "=";
                }
                case /* 18 */ Token::INFIXINEQUALITY:
                {
                    return "!=";
                }
                case /* 19 */ Token::LPAREN:
                {
                    return "(";
                }
                case /* 20 */ Token::RPAREN:
                {
                    return ")";
                }
                case /* 21 */ Token::LSQPAREN:
                {
                    return "[";
                }
                case /* 22 */ Token::RSQPAREN:
                {
                    return "]";
                }
                case /* 23 */ Token::LCURPAREN:
                {
                    return "{";
                }
                case /* 24 */ Token::RCURPAREN:
                {
                    return "}";
                }
                case /* 25 */ Token::VLINE:
                {
                    return "|";
                }
                case /* 26 */ Token::STAR:
                {
                    return "*";
                }
                case /* 27 */ Token::GREATER:
                {
                    return ">";
                }
                case /* 28 */ Token::EXCLAMATION:
                {
                    return "!";
                }
                case /* 29 */ Token::TILDE:
                {
                    return "~";
                }
                case /* 30 */ Token::QUESTIONMARK:
                {
                    return "?";
                }
                case /* 31 */ Token::ATMINUS:
                {
                    return "@-";
                }
                case /* 32 */ Token::ATPLUS:
                {
                    return "@+";
                }
                case /* 33 */ Token::CARET:
                {
                    return "^";
                }
                case /* 34 */ Token::DOUBLEEXCLAMATION:
                {
                    return "!!";
                }
                case /* 35 */ Token::DOUBLEQUESTIONMARK:
                {
                    return "??";
                }
                case /* 36 */ Token::DOUBLEATPLUS:
                {
                    return "@@+";
                }
                case /* 37 */ Token::DOUBLEATMINUS:
                {
                    return "@@-";
                }
                case /* 38 */ Token::ATEQUAL:
                {
                    return "@=";
                }
                case /* 39 */ Token::EXCLAMATIONGREATER:
                {
                    return "!>";
                }
                case /* 40 */ Token::QUESTIONMARKSTAR:
                {
                    return "?*";
                }
                case /* 41 */ Token::EQUALITY:
                {
                    return "<=>";
                }
                case /* 42 */ Token::IMPLICATION:
                {
                    return "=>";
                }
                case /* 43 */ Token::RIMPLICATION:
                {
                    return "<=";
                }
                case /* 44 */ Token::INEQUALITY:
                {
                    return "<~>";
                }
                case /* 45 */ Token::NOR:
                {
                    return "~|";
                }
                case /* 46 */ Token::NAND:
                {
                    return "~&";
                }
                case /* 47 */ Token::ASSIGNMENT:
                {
                    return ":=";
                }
                case /* 48 */ Token::GENTZENARROW:
                {
                    return "-->";
                }
                case /* 49 */ Token::SUBTYPESIGN:
                {
                    return "<<";
                }
                case /* 50 */ Token::INCLUDE:
                {
                    return "include";
                }
            }
            assert( !"internal error" );
            return std::string();
        }
    }
}

//
//
// Token
//

Token::Token( const libtptp::Grammar::Token token )
: Node( Node::ID::TOKEN )
, m_token( token )
{
}

libtptp::Grammar::Token Token::token( void ) const
{
    return m_token;
}

std::string Token::tokenString( void ) const
{
    return libtptp::Grammar::tokenAsString( m_token );
}

void Token::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& TokenBuilder::UNRESOLVED( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::UNRESOLVED );
    return instance;
}

const Token::Ptr& TokenBuilder::TPI( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::TPI );
    return instance;
}

const Token::Ptr& TokenBuilder::THF( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::THF );
    return instance;
}

const Token::Ptr& TokenBuilder::TFF( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::TFF );
    return instance;
}

const Token::Ptr& TokenBuilder::TCF( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::TCF );
    return instance;
}

const Token::Ptr& TokenBuilder::FOF( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::FOF );
    return instance;
}

const Token::Ptr& TokenBuilder::CNF( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::CNF );
    return instance;
}

const Token::Ptr& TokenBuilder::FOT( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::FOT );
    return instance;
}

const Token::Ptr& TokenBuilder::ITE( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::ITE );
    return instance;
}

const Token::Ptr& TokenBuilder::LET( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::LET );
    return instance;
}

const Token::Ptr& TokenBuilder::AT( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::AT );
    return instance;
}

const Token::Ptr& TokenBuilder::AND( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::AND );
    return instance;
}

const Token::Ptr& TokenBuilder::DOLLAR( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOLLAR );
    return instance;
}

const Token::Ptr& TokenBuilder::COLON( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::COLON );
    return instance;
}

const Token::Ptr& TokenBuilder::COMMA( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::COMMA );
    return instance;
}

const Token::Ptr& TokenBuilder::DOT( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOT );
    return instance;
}

const Token::Ptr& TokenBuilder::PLUS( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::PLUS );
    return instance;
}

const Token::Ptr& TokenBuilder::EQUAL( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::EQUAL );
    return instance;
}

const Token::Ptr& TokenBuilder::INFIXINEQUALITY( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::INFIXINEQUALITY );
    return instance;
}

const Token::Ptr& TokenBuilder::LPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::LPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::RPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::RPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::LSQPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::LSQPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::RSQPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::RSQPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::LCURPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::LCURPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::RCURPAREN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::RCURPAREN );
    return instance;
}

const Token::Ptr& TokenBuilder::VLINE( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::VLINE );
    return instance;
}

const Token::Ptr& TokenBuilder::STAR( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::STAR );
    return instance;
}

const Token::Ptr& TokenBuilder::GREATER( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::GREATER );
    return instance;
}

const Token::Ptr& TokenBuilder::EXCLAMATION( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::EXCLAMATION );
    return instance;
}

const Token::Ptr& TokenBuilder::TILDE( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::TILDE );
    return instance;
}

const Token::Ptr& TokenBuilder::QUESTIONMARK( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::QUESTIONMARK );
    return instance;
}

const Token::Ptr& TokenBuilder::ATMINUS( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::ATMINUS );
    return instance;
}

const Token::Ptr& TokenBuilder::ATPLUS( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::ATPLUS );
    return instance;
}

const Token::Ptr& TokenBuilder::CARET( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::CARET );
    return instance;
}

const Token::Ptr& TokenBuilder::DOUBLEEXCLAMATION( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOUBLEEXCLAMATION );
    return instance;
}

const Token::Ptr& TokenBuilder::DOUBLEQUESTIONMARK( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOUBLEQUESTIONMARK );
    return instance;
}

const Token::Ptr& TokenBuilder::DOUBLEATPLUS( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOUBLEATPLUS );
    return instance;
}

const Token::Ptr& TokenBuilder::DOUBLEATMINUS( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::DOUBLEATMINUS );
    return instance;
}

const Token::Ptr& TokenBuilder::ATEQUAL( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::ATEQUAL );
    return instance;
}

const Token::Ptr& TokenBuilder::EXCLAMATIONGREATER( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::EXCLAMATIONGREATER );
    return instance;
}

const Token::Ptr& TokenBuilder::QUESTIONMARKSTAR( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::QUESTIONMARKSTAR );
    return instance;
}

const Token::Ptr& TokenBuilder::EQUALITY( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::EQUALITY );
    return instance;
}

const Token::Ptr& TokenBuilder::IMPLICATION( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::IMPLICATION );
    return instance;
}

const Token::Ptr& TokenBuilder::RIMPLICATION( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::RIMPLICATION );
    return instance;
}

const Token::Ptr& TokenBuilder::INEQUALITY( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::INEQUALITY );
    return instance;
}

const Token::Ptr& TokenBuilder::NOR( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::NOR );
    return instance;
}

const Token::Ptr& TokenBuilder::NAND( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::NAND );
    return instance;
}

const Token::Ptr& TokenBuilder::ASSIGNMENT( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::ASSIGNMENT );
    return instance;
}

const Token::Ptr& TokenBuilder::GENTZENARROW( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::GENTZENARROW );
    return instance;
}

const Token::Ptr& TokenBuilder::SUBTYPESIGN( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::SUBTYPESIGN );
    return instance;
}

const Token::Ptr& TokenBuilder::INCLUDE( void )
{
    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::INCLUDE );
    return instance;
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

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

#ifndef _LIBTPTP_GRAMMAR_TOKEN_H_
#define _LIBTPTP_GRAMMAR_TOKEN_H_

#include <libtptp/TPTP>

#include <cassert>

namespace libtptp
{
    namespace Grammar
    {
        enum class Token : u8
        {
            /*  0 */ UNRESOLVED,
            /*  1 */ TPI,
            /*  2 */ THF,
            /*  3 */ TFF,
            /*  4 */ TCF,
            /*  5 */ FOF,
            /*  6 */ CNF,
            /*  7 */ FOT,
            /*  8 */ ITE,
            /*  9 */ LET,
            /* 10 */ AT,
            /* 11 */ AND,
            /* 12 */ DOLLAR,
            /* 13 */ COLON,
            /* 14 */ COMMA,
            /* 15 */ DOT,
            /* 16 */ PLUS,
            /* 17 */ MINUS,
            /* 18 */ EQUAL,
            /* 19 */ LPAREN,
            /* 20 */ RPAREN,
            /* 21 */ LSQPAREN,
            /* 22 */ RSQPAREN,
            /* 23 */ LCURPAREN,
            /* 24 */ RCURPAREN,
            /* 25 */ VLINE,
            /* 26 */ STAR,
            /* 27 */ GREATER,
            /* 28 */ LESS,
            /* 29 */ EXCLAMATION,
            /* 30 */ TILDE,
            /* 31 */ QUESTIONMARK,
            /* 32 */ CARET,
            /* 33 */ DOUBLEEXCLAMATION,
            /* 34 */ DOUBLEQUESTIONMARK,
            /* 35 */ DOUBLEAT,
            /* 36 */ EQUALITY,
            /* 37 */ IMPLICATION,
            /* 38 */ RIMPLICATION,
            /* 39 */ INEQUALITY,
            /* 40 */ NOR,
            /* 41 */ NAND,
            /* 42 */ ASSIGNMENT,
            /* 43 */ GENTZENARROW,
            /* 44 */ SUBTYPESIGN,
            /* 45 */ INCLUDE,
        };
        
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
                case /* 17 */ Token::MINUS:
                {
                    return "-";
                }
                case /* 18 */ Token::EQUAL:
                {
                    return "=";
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
                case /* 28 */ Token::LESS:
                {
                    return "<";
                }
                case /* 29 */ Token::EXCLAMATION:
                {
                    return "!";
                }
                case /* 30 */ Token::TILDE:
                {
                    return "~";
                }
                case /* 31 */ Token::QUESTIONMARK:
                {
                    return "?";
                }
                case /* 32 */ Token::CARET:
                {
                    return "^";
                }
                case /* 33 */ Token::DOUBLEEXCLAMATION:
                {
                    return "!!";
                }
                case /* 34 */ Token::DOUBLEQUESTIONMARK:
                {
                    return "??";
                }
                case /* 35 */ Token::DOUBLEAT:
                {
                    return "@@";
                }
                case /* 36 */ Token::EQUALITY:
                {
                    return "<=>";
                }
                case /* 37 */ Token::IMPLICATION:
                {
                    return "=>";
                }
                case /* 38 */ Token::RIMPLICATION:
                {
                    return "<=";
                }
                case /* 39 */ Token::INEQUALITY:
                {
                    return "<~>";
                }
                case /* 40 */ Token::NOR:
                {
                    return "~|";
                }
                case /* 41 */ Token::NAND:
                {
                    return "~&";
                }
                case /* 42 */ Token::ASSIGNMENT:
                {
                    return ":=";
                }
                case /* 43 */ Token::GENTZENARROW:
                {
                    return "-->";
                }
                case /* 44 */ Token::SUBTYPESIGN:
                {
                    return "<<";
                }
                case /* 45 */ Token::INCLUDE:
                {
                    return "include";
                }
            }
            assert( !"internal error" );
            return std::string();
        }
    };
}

#endif  // _LIBTPTP_GRAMMAR_TOKEN_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

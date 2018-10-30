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
            /*  1 */ DUMMY,
            /*  2 */ TPI,
            /*  3 */ THF,
            /*  4 */ TFF,
            /*  5 */ TCF,
            /*  6 */ FOF,
            /*  7 */ CNF,
            /*  8 */ FOT,
            /*  9 */ DOLLAR,
            /* 10 */ COLON,
            /* 11 */ COMMA,
            /* 12 */ DOT,
            /* 13 */ PLUS,
            /* 14 */ MINUS,
            /* 15 */ EQUAL,
            /* 16 */ LPAREN,
            /* 17 */ RPAREN,
            /* 18 */ LSQPAREN,
            /* 19 */ RSQPAREN,
            /* 20 */ LCURPAREN,
            /* 21 */ RCURPAREN,
        };
        
        static std::string tokenAsString( const Token token )
        {
            switch( token )
            {
                case /*  0 */ Token::UNRESOLVED:
                {
                    return "$unresolved$";
                }
                case /*  1 */ Token::DUMMY:
                {
                    return "dummy";
                }
                case /*  2 */ Token::TPI:
                {
                    return "tpi";
                }
                case /*  3 */ Token::THF:
                {
                    return "thf";
                }
                case /*  4 */ Token::TFF:
                {
                    return "tff";
                }
                case /*  5 */ Token::TCF:
                {
                    return "tcf";
                }
                case /*  6 */ Token::FOF:
                {
                    return "fof";
                }
                case /*  7 */ Token::CNF:
                {
                    return "cnf";
                }
                case /*  8 */ Token::FOT:
                {
                    return "fot";
                }
                case /*  9 */ Token::DOLLAR:
                {
                    return "$";
                }
                case /* 10 */ Token::COLON:
                {
                    return ":";
                }
                case /* 11 */ Token::COMMA:
                {
                    return ",";
                }
                case /* 12 */ Token::DOT:
                {
                    return ".";
                }
                case /* 13 */ Token::PLUS:
                {
                    return "+";
                }
                case /* 14 */ Token::MINUS:
                {
                    return "-";
                }
                case /* 15 */ Token::EQUAL:
                {
                    return "=";
                }
                case /* 16 */ Token::LPAREN:
                {
                    return "(";
                }
                case /* 17 */ Token::RPAREN:
                {
                    return ")";
                }
                case /* 18 */ Token::LSQPAREN:
                {
                    return "[";
                }
                case /* 19 */ Token::RSQPAREN:
                {
                    return "]";
                }
                case /* 20 */ Token::LCURPAREN:
                {
                    return "{";
                }
                case /* 21 */ Token::RCURPAREN:
                {
                    return "}";
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
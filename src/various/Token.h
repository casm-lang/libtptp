//
//  Copyright (C) 2017-2023 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//  <https://github.com/casm-lang/libtptp/graphs/contributors>
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

#ifndef _LIBTPTP_TOKEN_H_
#define _LIBTPTP_TOKEN_H_

#include <libtptp/Node>

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
            /* 13 */ DOLLARDOLLAR,
            /* 14 */ COLON,
            /* 15 */ COMMA,
            /* 16 */ DOT,
            /* 17 */ PLUS,
            /* 18 */ EQUAL,
            /* 19 */ INFIXINEQUALITY,
            /* 20 */ LPAREN,
            /* 21 */ RPAREN,
            /* 22 */ LSQPAREN,
            /* 23 */ RSQPAREN,
            /* 24 */ LCURPAREN,
            /* 25 */ RCURPAREN,
            /* 26 */ VLINE,
            /* 27 */ STAR,
            /* 28 */ GREATER,
            /* 29 */ EXCLAMATION,
            /* 30 */ TILDE,
            /* 31 */ QUESTIONMARK,
            /* 32 */ ATMINUS,
            /* 33 */ ATPLUS,
            /* 34 */ CARET,
            /* 35 */ DOUBLEEXCLAMATION,
            /* 36 */ DOUBLEQUESTIONMARK,
            /* 37 */ DOUBLEATPLUS,
            /* 38 */ DOUBLEATMINUS,
            /* 39 */ ATEQUAL,
            /* 40 */ EXCLAMATIONGREATER,
            /* 41 */ QUESTIONMARKSTAR,
            /* 42 */ EQUALITY,
            /* 43 */ IMPLICATION,
            /* 44 */ RIMPLICATION,
            /* 45 */ INEQUALITY,
            /* 46 */ NOR,
            /* 47 */ NAND,
            /* 48 */ ASSIGNMENT,
            /* 49 */ GENTZENARROW,
            /* 50 */ SUBTYPESIGN,
            /* 51 */ INCLUDE,
        };
    }

    class Token final : public Node
    {
      public:
        using Ptr = std::shared_ptr< Token >;

        Token( const libtptp::Grammar::Token token );

        libtptp::Grammar::Token token( void ) const;

        std::string tokenString( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        libtptp::Grammar::Token m_token;
    };

    using Tokens = NodeList< Token >;

    class TokenBuilder final
    {
      public:
        explicit TokenBuilder() = delete;

        static const Token::Ptr& UNRESOLVED( void );
        static const Token::Ptr& TPI( void );
        static const Token::Ptr& THF( void );
        static const Token::Ptr& TFF( void );
        static const Token::Ptr& TCF( void );
        static const Token::Ptr& FOF( void );
        static const Token::Ptr& CNF( void );
        static const Token::Ptr& FOT( void );
        static const Token::Ptr& ITE( void );
        static const Token::Ptr& LET( void );
        static const Token::Ptr& AT( void );
        static const Token::Ptr& AND( void );
        static const Token::Ptr& DOLLAR( void );
        static const Token::Ptr& DOLLARDOLLAR( void );
        static const Token::Ptr& COLON( void );
        static const Token::Ptr& COMMA( void );
        static const Token::Ptr& DOT( void );
        static const Token::Ptr& PLUS( void );
        static const Token::Ptr& EQUAL( void );
        static const Token::Ptr& INFIXINEQUALITY( void );
        static const Token::Ptr& LPAREN( void );
        static const Token::Ptr& RPAREN( void );
        static const Token::Ptr& LSQPAREN( void );
        static const Token::Ptr& RSQPAREN( void );
        static const Token::Ptr& LCURPAREN( void );
        static const Token::Ptr& RCURPAREN( void );
        static const Token::Ptr& VLINE( void );
        static const Token::Ptr& STAR( void );
        static const Token::Ptr& GREATER( void );
        static const Token::Ptr& EXCLAMATION( void );
        static const Token::Ptr& TILDE( void );
        static const Token::Ptr& QUESTIONMARK( void );
        static const Token::Ptr& ATMINUS( void );
        static const Token::Ptr& ATPLUS( void );
        static const Token::Ptr& CARET( void );
        static const Token::Ptr& DOUBLEEXCLAMATION( void );
        static const Token::Ptr& DOUBLEQUESTIONMARK( void );
        static const Token::Ptr& DOUBLEATPLUS( void );
        static const Token::Ptr& DOUBLEATMINUS( void );
        static const Token::Ptr& ATEQUAL( void );
        static const Token::Ptr& EXCLAMATIONGREATER( void );
        static const Token::Ptr& QUESTIONMARKSTAR( void );
        static const Token::Ptr& EQUALITY( void );
        static const Token::Ptr& IMPLICATION( void );
        static const Token::Ptr& RIMPLICATION( void );
        static const Token::Ptr& INEQUALITY( void );
        static const Token::Ptr& NOR( void );
        static const Token::Ptr& NAND( void );
        static const Token::Ptr& ASSIGNMENT( void );
        static const Token::Ptr& GENTZENARROW( void );
        static const Token::Ptr& SUBTYPESIGN( void );
        static const Token::Ptr& INCLUDE( void );
    };

}

#endif  // _LIBTPTP_TOKEN_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

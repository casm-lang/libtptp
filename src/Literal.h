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

#ifndef _LIBTPTP_LITERAL_H_
#define _LIBTPTP_LITERAL_H_

#include <various/GrammarToken.h>
#include <cassert>
#include <libstdhl/Type>
#include <libstdhl/data/type/Data>
#include <libstdhl/data/type/Decimal>
#include <libstdhl/data/type/Integer>
#include <libstdhl/data/type/Rational>
#include <libstdhl/data/type/String>
#include <libtptp/Node>
#include <libtptp/Token>

namespace libtptp
{
    class Literal : public Node
    {
      public:
        using Ptr = std::shared_ptr< Literal >;

        explicit Literal( const Node::ID id );

      private:
    };

    using Literals = NodeList< Literal >;

    class ValueLiteral : public Literal
    {
      public:
        using Ptr = std::shared_ptr< ValueLiteral >;

        explicit ValueLiteral( const Node::ID id, libstdhl::Type::Data value );

        const libstdhl::Type::Data& value( void ) const;

      private:
        libstdhl::Type::Data m_value;
    };

    using ValueLiterals = NodeList< ValueLiteral >;

    class IntegerLiteral final : public ValueLiteral
    {
      public:
        using Ptr = std::shared_ptr< IntegerLiteral >;

        explicit IntegerLiteral( const std::string& integer );

        void accept( Visitor& visitor ) override final;

      private:
    };

    using IntegerLiterals = NodeList< IntegerLiteral >;

    class RationalLiteral final : public ValueLiteral
    {
      public:
        using Ptr = std::shared_ptr< RationalLiteral >;

        explicit RationalLiteral( const std::string& rational );

        void accept( Visitor& visitor ) override final;

      private:
    };

    using RationalLiterals = NodeList< RationalLiteral >;

    class RealLiteral final : public ValueLiteral
    {
      public:
        using Ptr = std::shared_ptr< RealLiteral >;

        explicit RealLiteral( const std::string& real );

        void accept( Visitor& visitor ) override final;

      private:
    };

    using RealLiterals = NodeList< RealLiteral >;

    class StringLiteral final : public ValueLiteral
    {
      public:
        enum class Kind
        {
            SINGLE_QUOTED,
            DOUBLE_QUOTED,
            NOT_QUOTED
        };
        using Ptr = std::shared_ptr< StringLiteral >;

        explicit StringLiteral( const std::string& string );

        explicit StringLiteral( const Token::Ptr& definedModifier, const std::string& string );
        explicit StringLiteral(
            const Token::Ptr& systemModifier,
            const Token::Ptr& definedModifier,
            const std::string& string );

        const Token::Ptr systemModifier( void ) const;

        const Token::Ptr definedModifier( void ) const;

        void accept( Visitor& visitor ) override final;

        const Kind& kind( void ) const;

        const std::string kindName( void ) const;

      private:
        const Token::Ptr m_systemModifier;
        const Token::Ptr m_definedModifier;
        Kind m_kind;
    };

    using StringLiterals = NodeList< StringLiteral >;

    class ListLiteral final : public Literal
    {
      public:
        enum class Kind
        {

        };
        using Ptr = std::shared_ptr< ListLiteral >;
        explicit ListLiteral( const Token::Ptr& leftBraceToken, const Token::Ptr& rightBraceToken );
        explicit ListLiteral(
            const Token::Ptr& leftBraceToken,
            const Nodes::Ptr& elements,
            const Token::Ptr& rightBraceToken );

        const Nodes::Ptr& elements( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_leftBraceToken;
        const Nodes::Ptr m_elements;
        const Token::Ptr m_rightBraceToken;
    };

}

#endif  // _LIBTPTP_LITERAL_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
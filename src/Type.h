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
#ifndef _LIBTPTP_TYPE_H_
#define _LIBTPTP_TYPE_H_

#include <libtptp/Atom>

namespace libtptp
{
    class Type : public Atom
    {
      public:
        using Ptr = std::shared_ptr< Type >;

        explicit Type( const Node::ID id );

      private:
    };

    using Types = NodeList< Type >;

    class AtomType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< AtomType >;

        explicit AtomType( const Node::Ptr& atom );

        void accept( Visitor& visitor ) override final;

        const Node::Ptr& atom( void ) const;

      private:
        const Node::Ptr m_atom;
    };

    using AtomTypes = NodeList< AtomType >;

    class BinaryType final : public Type
    {
      public:
        enum class Kind
        {
            MAPPING,
            XPROD,
            UNION,
        };
        using Ptr = std::shared_ptr< BinaryType >;

        explicit BinaryType(
            const Type::Ptr& left,
            const Token::Ptr& connectiveToken,
            const Type::Ptr& right,
            const Kind kind );

        void accept( Visitor& visitor ) override final;

        const Type::Ptr& left( void ) const;
        const Token::Ptr& connectiveToken( void ) const;
        const Type::Ptr& right( void ) const;
        const Kind& kind( void ) const;

      private:
        const Type::Ptr m_left;
        const Token::Ptr m_connectiveToken;
        const Type::Ptr m_right;
        const Kind m_kind;
    };

    using BinaryTypes = NodeList< BinaryType >;

    class TypedAtom final : public Type
    {
      public:
        using Ptr = std::shared_ptr< TypedAtom >;

        explicit TypedAtom(
            const Identifier::Ptr& atom, const Token::Ptr& colon, const Type::Ptr& type );

        void accept( Visitor& visitor ) override final;

        const Type::Ptr& type( void ) const;
        const Token::Ptr& colon( void ) const;
        const Identifier::Ptr& atom( void ) const;

      private:
        const Identifier::Ptr m_atom;
        const Token::Ptr m_colon;
        const Type::Ptr& m_type;
    };

    using TypedAtoms = NodeList< TypedAtom >;

    class TupleType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< TupleType >;

        explicit TupleType(
            const Token::Ptr& leftBraceToken,
            const Types::Ptr& tuples,
            const Token::Ptr& rightBraceToken );

        void accept( Visitor& visitor ) override final;

        const Token::Ptr& leftBraceToken( void ) const;
        const Types::Ptr& tuples( void ) const;
        const Token::Ptr& rightBraceToken( void ) const;

      private:
        const Token::Ptr m_leftBraceToken;
        const Types::Ptr m_tuples;
        const Token::Ptr m_rightBraceToken;
    };

    using TupleTypes = NodeList< TupleType >;

    class QuantifiedType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< QuantifiedType >;

        explicit QuantifiedType(
            const Token::Ptr& quantifierToken,
            const Token::Ptr& leftParen,
            const Nodes::Ptr& variables,
            const Token::Ptr& rightParen,
            const Token::Ptr& colon,
            const Type::Ptr& type );

        void accept( Visitor& visitor ) override final;

        const Token::Ptr& quantifierToken( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const Nodes::Ptr& variables( void ) const;
        const Token::Ptr& rightParen( void ) const;
        const Token::Ptr& colon( void ) const;
        const Type::Ptr& type( void ) const;

      private:
        const Token::Ptr m_quantifierToken;
        const Token::Ptr m_leftParen;
        const Nodes::Ptr m_variables;
        const Token::Ptr m_rightParen;
        const Token::Ptr m_colon;
        const Type::Ptr m_type;
    };

    using QuantifiedTypes = NodeList< QuantifiedType >;

    class SubType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< SubType >;

        explicit SubType(
            const Identifier::Ptr& lhs, const Token::Ptr& subtypesign, const Identifier::Ptr& rhs );

        void accept( Visitor& visitor ) override final;

        const Identifier::Ptr& lhs( void ) const;
        const Token::Ptr& subtypesign( void ) const;
        const Identifier::Ptr& rhs( void ) const;

      private:
        const Identifier::Ptr m_lhs;
        const Token::Ptr m_subtypesign;
        const Identifier::Ptr m_rhs;
    };

    using SubTypes = NodeList< SubType >;

} /* libtptp */

#endif  //_LIBTPTP_TYPE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

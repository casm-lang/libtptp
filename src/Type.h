//
//  Copyright (C) 2017-2024 CASM Organization <https://casm-lang.org>
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
    };

    using Types = NodeList< Type >;

    template < builderFunction func = TokenBuilder::COMMA >
    using ListTypeElements = ListElements< Type, func >;

    class ApplyType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< ApplyType >;

        explicit ApplyType( const Node::Ptr& atom );

        const Node::Ptr& atom( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Node::Ptr m_atom;
    };

    using ApplyTypes = NodeList< ApplyType >;

    class NamedType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< NamedType >;

        explicit NamedType( const Identifier::Ptr& name );
        explicit NamedType( const std::string& name );

        const Identifier::Ptr& name( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_name;
    };

    using NamedTypes = NodeList< NamedType >;

    class FunctorType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< FunctorType >;

        explicit FunctorType(
            const Identifier::Ptr& name,
            const Token::Ptr& leftParen,
            const ListTypeElements<>::Ptr& arguments,
            const Token::Ptr& rightParen );
        explicit FunctorType(
            const Identifier::Ptr& name, const ListTypeElements<>::Ptr& arguments );
        explicit FunctorType( const std::string& name, const ListTypeElements<>::Ptr& arguments );
        explicit FunctorType(
            const std::string& name, const std::initializer_list< Type::Ptr >& arguments );

        const Identifier::Ptr& name( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const ListTypeElements<>::Ptr& arguments( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_name;
        const Token::Ptr m_leftParen;
        const ListTypeElements<>::Ptr m_arguments;
        const Token::Ptr m_rightParen;
    };

    using FunctorTypes = NodeList< FunctorType >;

    class BinaryType final : public Type
    {
      public:
        enum class Kind
        {
            MAPPING,
            UNION,
        };

        using Ptr = std::shared_ptr< BinaryType >;

        explicit BinaryType(
            const Type::Ptr& left,
            const Token::Ptr& connectiveToken,
            const Type::Ptr& right,
            const Kind kind );

        explicit BinaryType( const Type::Ptr& left, const Type::Ptr& right, const Kind kind );

        const Type::Ptr& left( void ) const;
        const Token::Ptr& connectiveToken( void ) const;
        const Type::Ptr& right( void ) const;
        Kind kind( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Type::Ptr m_left;
        const Token::Ptr m_connectiveToken;
        const Type::Ptr m_right;
        const Kind m_kind;
    };

    using BinaryTypes = NodeList< BinaryType >;

    class RelationType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< RelationType >;

        explicit RelationType( const ListTypeElements< TokenBuilder::STAR >::Ptr& elements );
        explicit RelationType( const std::initializer_list< Type::Ptr >& elements );

        const ListTypeElements< TokenBuilder::STAR >::Ptr& elements( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const ListTypeElements< TokenBuilder::STAR >::Ptr m_elements;
    };

    using RelationTypes = NodeList< RelationType >;

    class TupleType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< TupleType >;

        explicit TupleType(
            const Token::Ptr& leftBraceToken,
            const ListTypeElements<>::Ptr& tuples,
            const Token::Ptr& rightBraceToken );

        explicit TupleType( const ListTypeElements<>::Ptr& tuples );
        explicit TupleType( const std::initializer_list< Type::Ptr >& tuples );

        const Token::Ptr& leftBraceToken( void ) const;
        const ListTypeElements<>::Ptr& tuples( void ) const;
        const Token::Ptr& rightBraceToken( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_leftBraceToken;
        const ListTypeElements<>::Ptr m_tuples;
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
            const ListVariableElements::Ptr& variables,
            const Token::Ptr& rightParen,
            const Token::Ptr& colon,
            const Type::Ptr& type );

        explicit QuantifiedType(
            const ListVariableElements::Ptr& variables, const Type::Ptr& type );
        explicit QuantifiedType(
            const std::initializer_list< VariableTerm::Ptr >& variables, const Type::Ptr& type );

        const Token::Ptr& quantifierToken( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const ListVariableElements::Ptr& variables( void ) const;
        const Token::Ptr& rightParen( void ) const;
        const Token::Ptr& colon( void ) const;
        const Type::Ptr& type( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_quantifierToken;
        const Token::Ptr m_leftParen;
        const ListVariableElements::Ptr m_variables;
        const Token::Ptr m_rightParen;
        const Token::Ptr m_colon;
        const Type::Ptr m_type;
    };

    using QuantifiedTypes = NodeList< QuantifiedType >;

    class VariableType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< VariableType >;

        explicit VariableType( const VariableTerm::Ptr& variable );

        const VariableTerm::Ptr& variable( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const VariableTerm::Ptr m_variable;
    };

    using VariableTypes = NodeList< VariableType >;

    class SubType final : public Type
    {
      public:
        using Ptr = std::shared_ptr< SubType >;

        explicit SubType(
            const Identifier::Ptr& leftAtom,
            const Token::Ptr& subTypeSign,
            const Identifier::Ptr& rightAtom );

        explicit SubType( const Identifier::Ptr& leftAtom, const Identifier::Ptr& rightAtom );
        explicit SubType( const std::string& leftAtom, const std::string& rightAtom );

        const Identifier::Ptr& leftAtom( void ) const;
        const Token::Ptr& subTypeSign( void ) const;
        const Identifier::Ptr& rightAtom( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_leftAtom;
        const Token::Ptr m_subTypeSign;
        const Identifier::Ptr m_rightAtom;
    };

    using SubTypes = NodeList< SubType >;

}

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

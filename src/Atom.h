//
//  Copyright (C) 2017-2021 CASM Organization <https://casm-lang.org>
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

#ifndef _LIBTPTP_ATOM_H_
#define _LIBTPTP_ATOM_H_

#include <libtptp/Term>

/**
   @brief    TODO

   TODO
*/

namespace libtptp
{
    /**
       @extends TPTP
    */
    class Atom : public Term
    {
      public:
        enum class Kind
        {
            PLAIN,
            DEFINED,
            SYSTEM,
        };

        using Ptr = std::shared_ptr< Atom >;

        Atom( const Node::ID id );
    };

    using Atoms = NodeList< Atom >;

    // <number> ::= <integer> | <rational> | <real>
    // class NumberAtom final : public Atom

    // <distinct_object> ::- <double_quote><do_char>*<double_quote>
    // class DistinctObjectAtom final : public Atom

    class FunctorAtom final : public Atom
    {
      public:
        // <fof_plain_term>          ::= <constant>
        //                             | <functor>(<fof_arguments>)
        // <fof_defined_term>        ::= <defined_term>
        //                             | <fof_defined_atomic_term>
        // <fof_defined_atomic_term> ::= <fof_defined_plain_term>
        // <fof_defined_plain_term>  ::= <defined_constant>
        //                             | <defined_functor>(<fof_arguments>)
        // <fof_system_term>         ::= <system_constant>
        //                             | <system_functor>(<fof_arguments>)

        using Ptr = std::shared_ptr< FunctorAtom >;

        FunctorAtom(
            const Identifier::Ptr& name,
            const Token::Ptr& leftParen,
            const ListLogicElements::Ptr& arguments,
            const Token::Ptr& rightParen,
            const Kind kind );

        FunctorAtom(
            const Identifier::Ptr& name, const ListLogicElements::Ptr& arguments, const Kind kind );
        FunctorAtom(
            const std::string& name, const ListLogicElements::Ptr& arguments, const Kind kind );

        FunctorAtom(
            const std::string& name,
            const std::initializer_list< Logic::Ptr >& arguments,
            const Kind kind );

        const Identifier::Ptr& name( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const ListLogicElements::Ptr& arguments( void ) const;
        const Token::Ptr& rightParen( void ) const;
        const Kind kind( void ) const;

      private:
        const Identifier::Ptr m_name;
        const Token::Ptr m_leftParen;
        const ListLogicElements::Ptr m_arguments;
        const Token::Ptr m_rightParen;
        const Kind m_kind;

      public:
        void accept( Visitor& visitor ) override;
    };

    class ConstantAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< ConstantAtom >;

        explicit ConstantAtom( const Identifier::Ptr& constant, const Kind kind );
        explicit ConstantAtom( const std::string& constant, const Kind kind );

        const Identifier::Ptr& constant( void ) const;
        const Kind kind( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_constant;
        const Kind m_kind;
    };

    using ConstantAtoms = NodeList< ConstantAtom >;

    class DefinedAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< DefinedAtom >;

        explicit DefinedAtom( const Literal::Ptr& literal );
        explicit DefinedAtom( const std::string& literal );
        explicit DefinedAtom( int literal );

        const Literal::Ptr& literal( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Literal::Ptr m_literal;
    };

    using DefinedAtoms = NodeList< DefinedAtom >;

    class DefinitionAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< DefinitionAtom >;

        explicit DefinitionAtom(
            const Logic::Ptr& lhs, const Token::Ptr& assignment, const Logic::Ptr& rhs );

        explicit DefinitionAtom( const Logic::Ptr& lhs, const Logic::Ptr& rhs );

        const Logic::Ptr& lhs( void ) const;
        const Token::Ptr& assignment( void ) const;
        const Logic::Ptr& rhs( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Logic::Ptr m_lhs;
        const Token::Ptr m_assignment;
        const Logic::Ptr m_rhs;
    };

    using DefinitionAtoms = NodeList< DefinitionAtom >;

    class ConnectiveAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< ConnectiveAtom >;

        explicit ConnectiveAtom( Token::Ptr& connective );

        void accept( Visitor& visitor ) override final;

        const Token::Ptr& connective( void );

      private:
        Token::Ptr m_connective;
    };

    using ConnectiveAtoms = NodeList< ConnectiveAtom >;

    class Type;

    class TypeAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< TypeAtom >;

        explicit TypeAtom(
            const Identifier::Ptr& atom,
            const Token::Ptr& colon,
            const std::shared_ptr< Type >& type );
        explicit TypeAtom( const Identifier::Ptr& atom, const std::shared_ptr< Type >& type );
        explicit TypeAtom( const std::string& atom, const std::shared_ptr< Type >& type );

        const std::shared_ptr< Type >& type( void ) const;
        const Token::Ptr& colon( void ) const;
        const Identifier::Ptr& atom( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_atom;
        const Token::Ptr m_colon;
        const std::shared_ptr< Type > m_type;
    };

    using TypeAtoms = NodeList< TypeAtom >;

    using ListAtomElements = ListElements< Atom >;

    class TupleAtom final : public Atom
    {
      public:
        using Ptr = std::shared_ptr< TupleAtom >;

        explicit TupleAtom(
            const Token::Ptr& leftParen,
            const ListAtomElements::Ptr& atoms,
            const Token::Ptr& rightParen );
        explicit TupleAtom( const ListAtomElements::Ptr& atoms );
        explicit TupleAtom( const std::initializer_list< Atom::Ptr >& atoms );

        const Token::Ptr& leftParen( void ) const;
        const ListAtomElements::Ptr& atoms( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_leftParen;
        const ListAtomElements::Ptr m_atoms;
        const Token::Ptr m_rightParen;
    };

    using TupleAtoms = NodeList< TupleAtom >;

}

#endif  // _LIBTPTP_ATOM_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

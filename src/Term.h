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

#ifndef _LIBTPTP_TERM_H_
#define _LIBTPTP_TERM_H_

#include <libstdhl/Optional>
#include <libtptp/Logic>

/**
   @brief    TODO

   TODO
*/

namespace libtptp
{
    /**
       @extends TPTP
    */
    class Term : public Logic
    {
      public:
        using Ptr = std::shared_ptr< Term >;

        Term( const Node::ID id );
    };

    using Terms = NodeList< Term >;

    class Type;

    // <variable> ::= <upper_word>
    class VariableTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< VariableTerm >;

        VariableTerm( const Identifier::Ptr& name );
        VariableTerm( const std::string& name );
        VariableTerm( const Identifier::Ptr& name, const std::shared_ptr< Type >& type );
        VariableTerm( const std::string& name, const std::shared_ptr< Type >& type );

        const Identifier::Ptr& name( void ) const;

        const libstdhl::Optional< Token::Ptr >& colon( void );
        const libstdhl::Optional< std::shared_ptr< Type > >& type( void );
        void setColon( const Token::Ptr& colon );
        void setType( const std::shared_ptr< Type >& type );

        void accept( Visitor& visitor ) override;

      private:
        const Identifier::Ptr m_name;
        libstdhl::Optional< Token::Ptr > m_colon;
        libstdhl::Optional< std::shared_ptr< Type > > m_type;
    };

    using VariableTerms = NodeList< VariableTerm >;
    using ListVariableElements = ListElements< VariableTerm >;

    // <tff_conditional_term> ::=
    // $ite_t(<tff_logic_formula>,<fof_term>,<fof_term>)
    // <fof_conditional_term> ::=
    // $ite_t(<fof_logic_formula>,<fof_term>,<fof_term>)
    class ConditionalTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< ConditionalTerm >;

        explicit ConditionalTerm(
            const Token::Ptr& dollar,
            const Token::Ptr& ite,
            const Token::Ptr& leftParen,
            const Logic::Ptr& condition,
            const Token::Ptr& commaLeft,
            const Logic::Ptr& leftTerm,
            const Token::Ptr& commaRight,
            const Logic::Ptr& rightTerm,
            const Token::Ptr& rightParen );

        explicit ConditionalTerm(
            const Logic::Ptr& condition, const Logic::Ptr& leftTerm, const Logic::Ptr& rightTerm );

        const Token::Ptr& dollar( void ) const;
        const Token::Ptr& ite( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const Logic::Ptr& condition( void ) const;
        const Token::Ptr& commaLeft( void ) const;
        const Logic::Ptr& leftTerm( void ) const;
        const Token::Ptr& commaRight( void ) const;
        const Logic::Ptr& rightTerm( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_dollar;
        const Token::Ptr m_ite;
        const Token::Ptr m_leftParen;
        const Logic::Ptr m_condition;
        const Token::Ptr m_commaLeft;
        const Logic::Ptr m_leftTerm;
        const Token::Ptr m_commaRight;
        const Logic::Ptr m_rightTerm;
        const Token::Ptr m_rightParen;
    };

    using ConditionalTerms = NodeList< ConditionalTerm >;

    class Atom;
    class DefinitionTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< DefinitionTerm >;

        explicit DefinitionTerm(
            const Token::Ptr& dollar,
            const Token::Ptr& let,
            const Token::Ptr& leftParen,
            const std::shared_ptr< Atom >& types,
            const Token::Ptr& commaLeft,
            const std::shared_ptr< Atom >& definitions,
            const Token::Ptr& commaRight,
            const Logic::Ptr& term,
            const Token::Ptr& rightParen );

        explicit DefinitionTerm(
            const std::shared_ptr< Atom >& types,
            const std::shared_ptr< Atom >& definitions,
            const Logic::Ptr& term );

        const Token::Ptr& dollar( void ) const;
        const Token::Ptr& let( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const std::shared_ptr< Atom >& types( void ) const;
        const Token::Ptr& commaLeft( void ) const;
        const std::shared_ptr< Atom >& definitions( void ) const;
        const Token::Ptr& commaRight( void ) const;
        const Logic::Ptr& term( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_dollar;
        const Token::Ptr m_let;
        const Token::Ptr m_leftParen;
        const std::shared_ptr< Atom > m_types;
        const Token::Ptr m_commaLeft;
        const std::shared_ptr< Atom > m_definitions;
        const Token::Ptr m_commaRight;
        const Logic::Ptr m_term;
        const Token::Ptr m_rightParen;
    };

    using DefinitionTerms = NodeList< DefinitionTerm >;

}

#endif  // _LIBTPTP_TERM_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

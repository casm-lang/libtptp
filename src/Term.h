//
//  Copyright (c) 2017 CASM Organization https://casm-lang.org
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                https://github.com/casm-lang/libtptp
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

    class Atom;

    // <fof_function_term> ::= <fof_plain_term> | <fof_defined_term> |
    // <fof_system_term>
    class FunctionTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< FunctionTerm >;

        FunctionTerm( const std::shared_ptr< Atom >& atom );

        const std::shared_ptr< Atom >& atom( void ) const;

      private:
        const std::shared_ptr< Atom > m_atom;

      public:
        void accept( Visitor& visitor ) override;
    };

    // <variable> ::= <upper_word>
    class VariableTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< VariableTerm >;

        VariableTerm( const Identifier::Ptr& name );

        const Identifier::Ptr& name( void ) const;

      private:
        const Identifier::Ptr m_name;

      public:
        void accept( Visitor& visitor ) override;
    };

    // <tff_conditional_term> ::=
    // $ite_t(<tff_logic_formula>,<fof_term>,<fof_term>)
    // <fof_conditional_term> ::=
    // $ite_t(<fof_logic_formula>,<fof_term>,<fof_term>)
    class ConditionalTerm final : public Term
    {
      public:
        using Ptr = std::shared_ptr< ConditionalTerm >;

        ConditionalTerm( const Logic::Ptr& condition,
            const Term::Ptr& left,
            const Term::Ptr& right );

        const Logic::Ptr& condition( void ) const;

        const Term::Ptr& left( void ) const;

        const Term::Ptr& right( void ) const;

      private:
        const Logic::Ptr m_condition;
        const Term::Ptr m_left;
        const Term::Ptr m_right;

      public:
        void accept( Visitor& visitor ) override;
    };
}

#endif // _LIBTPTP_TERM_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

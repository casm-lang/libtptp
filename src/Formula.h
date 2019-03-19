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

#ifndef _LIBTPTP_FORMULA_H_
#define _LIBTPTP_FORMULA_H_

#include <libstdhl/Optional>
#include <libtptp/General>
#include <libtptp/Logic>
#include <libtptp/Node>

/**
   @brief    TODO

   TODO
*/

namespace libtptp
{
    /**
       @extends TPTP
    */
    class Formula : public Node
    {
      public:
        using Ptr = std::shared_ptr< Formula >;

        Formula( const Node::ID id, const Logic::Ptr& logic );

        const Logic::Ptr& logic( void ) const;
        const libstdhl::Optional< Annotation::Ptr >& annotations( void ) const;
        void setAnnotations( const Annotation::Ptr& annotations );

      private:
        const Logic::Ptr m_logic;
        libstdhl::Optional< Annotation::Ptr > m_annotations;
    };

    using Formulas = NodeList< Formula >;

    class Logic;

    // <fof_formula>          ::= <fof_logic_formula>  | <fof_sequent>
    // <fof_logic_formula>    ::= <fof_binary_formula> | <fof_unitary_formula>
    class FirstOrderFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< FirstOrderFormula >;

        FirstOrderFormula( const Logic::Ptr& logic );

      public:
        void accept( Visitor& visitor ) override;
    };

    class TypedFirstOrderFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< TypedFirstOrderFormula >;

        TypedFirstOrderFormula( const Logic::Ptr& logic );

      public:
        void accept( Visitor& visitor ) override;
    };

    class TypedHigherOrderFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< TypedHigherOrderFormula >;

        explicit TypedHigherOrderFormula( const Logic::Ptr& logic );

        void accept( Visitor& visitor ) override final;
    };

    class TPTPProcessInstructionFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< TPTPProcessInstructionFormula >;

        explicit TPTPProcessInstructionFormula( const Logic::Ptr& logic );

        void accept( Visitor& visitor ) override final;
    };

    class ClauseNormalFormFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< ClauseNormalFormFormula >;

        explicit ClauseNormalFormFormula( const Logic::Ptr& logic );

        void accept( Visitor& visitor ) override final;
    };

    class TheoryComputableFunctionalsFormula final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< TheoryComputableFunctionalsFormula >;

        explicit TheoryComputableFunctionalsFormula( const Logic::Ptr& logic );

        void accept( Visitor& visitor ) override final;
    };

    class FormulaData final : public Formula
    {
      public:
        using Ptr = std::shared_ptr< FormulaData >;

        explicit FormulaData(
            const Token::Ptr& dollar,
            const Token::Ptr& formulaType,
            const Token::Ptr& leftParen,
            const Logic::Ptr& formula,
            const Token::Ptr& rightParen );

        const Token::Ptr& dollar( void ) const;
        const Token::Ptr& formulaType( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_dollar;
        const Token::Ptr m_formulaType;
        const Token::Ptr m_leftParen;
        const Token::Ptr m_rightParen;
    };

    using FormulaDatas = NodeList< FormulaData >;

}

#endif  // _LIBTPTP_FORMULA_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

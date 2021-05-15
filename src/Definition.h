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

#ifndef _LIBTPTP_DEFINITION_H_
#define _LIBTPTP_DEFINITION_H_

#include <libtptp/Formula>
#include <libtptp/General>
#include <libtptp/Identifier>
#include <libtptp/Node>
#include <libtptp/Role>
#include <libtptp/Token>

/**
   @brief    TODO

   TODO
*/

namespace libtptp
{
    /**
       @extends TPTP
    */
    class Definition : public Node
    {
      public:
        using Ptr = std::shared_ptr< Definition >;

        Definition( const Node::ID id );
    };

    using Definitions = NodeList< Definition >;

    class IncludeDefinition final : public Definition
    {
      public:
        using Ptr = std::shared_ptr< IncludeDefinition >;

        IncludeDefinition(
            const Token::Ptr& includeToken,
            const Token::Ptr& leftParenToken,
            const Identifier::Ptr& filename,
            const Token::Ptr& commaToken,
            const ListLiteral::Ptr& formulaSelection,
            const Token::Ptr& rightParenToken,
            const Token::Ptr& dotToken );

        IncludeDefinition(
            const Identifier::Ptr& filename, const ListLiteral::Ptr& formulaSelection );
        IncludeDefinition( const std::string& filename, const ListLiteral::Ptr& formulaSelection );

        const Token::Ptr& includeToken( void ) const;
        const Token::Ptr& leftParenToken( void ) const;
        const Identifier::Ptr& filename( void ) const;
        const Token::Ptr& commaToken( void ) const;
        const ListLiteral::Ptr& formulaSelection( void ) const;
        const Token::Ptr& rightParenToken( void ) const;
        const Token::Ptr& dotToken( void ) const;

        void accept( Visitor& visitor ) override;

      private:
        const Token::Ptr m_includeToken;
        const Token::Ptr m_leftParenToken;
        const Identifier::Ptr m_filename;
        const Token::Ptr m_commaToken;
        const ListLiteral::Ptr m_formulaSelection;
        const Token::Ptr m_rightParenToken;
        const Token::Ptr m_dotToken;
    };

    class FormulaDefinition final : public Definition
    {
      public:
        using Ptr = std::shared_ptr< FormulaDefinition >;

        explicit FormulaDefinition(
            const Token::Ptr& keyword,
            const Token::Ptr& leftParen,
            const Identifier::Ptr& name,
            const Token::Ptr& commaRole,
            const Role::Ptr& role,
            const Token::Ptr& commaFormula,
            const Formula::Ptr& formula,
            const Token::Ptr& rightParen,
            const Token::Ptr& dot );

        explicit FormulaDefinition(
            const Identifier::Ptr& name, const Role::Ptr& role, const Formula::Ptr& formula );
        explicit FormulaDefinition(
            const std::string& name, const Role::Ptr& role, const Formula::Ptr& formula );

        const Token::Ptr& keyword( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const Identifier::Ptr& name( void ) const;
        const Token::Ptr& commaRole( void ) const;
        const Role::Ptr& role( void ) const;
        const Token::Ptr& commaFormula( void ) const;
        const Formula::Ptr& formula( void ) const;
        const Token::Ptr& rightParen( void ) const;
        const Token::Ptr& dot( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Token::Ptr m_keyword;
        const Token::Ptr m_leftParen;
        const Identifier::Ptr m_name;
        const Token::Ptr m_commaRole;
        const Role::Ptr m_role;
        const Token::Ptr m_commaFormula;
        const Formula::Ptr m_formula;
        const Token::Ptr m_rightParen;
        const Token::Ptr m_dot;
    };

    using FormulaDefinitions = NodeList< FormulaDefinition >;

}

#endif  // _LIBTPTP_DEFINITION_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

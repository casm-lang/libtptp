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

#include "Definition.h"

using namespace libtptp;

//
//
// Definition
//

Definition::Definition( const ID id )
: Node( id )
{
}

//
//
// Include Definition
//
IncludeDefinition::IncludeDefinition(
    const Token::Ptr& includeToken,
    const Token::Ptr& leftParenToken,
    const Identifier::Ptr& filename,
    const Token::Ptr& commaToken,
    const ListLiteral::Ptr& formulaSelection,
    const Token::Ptr& rightParenToken,
    const Token::Ptr& dotToken )
: Definition( ID::INCLUDE_DEFINITION )
, m_includeToken( includeToken )
, m_leftParenToken( leftParenToken )
, m_filename( filename )
, m_commaToken( commaToken )
, m_formulaSelection( formulaSelection )
, m_rightParenToken( rightParenToken )
, m_dotToken( dotToken )
{
}

IncludeDefinition::IncludeDefinition(
    const Identifier::Ptr& filename, const ListLiteral::Ptr& formulaSelection )
: IncludeDefinition(
      TokenBuilder::INCLUDE(),
      TokenBuilder::LPAREN(),
      filename,
      TokenBuilder::COMMA(),
      formulaSelection,
      TokenBuilder::RPAREN(),
      TokenBuilder::DOT() )
{
}

IncludeDefinition::IncludeDefinition(
    const std::string& filename, const ListLiteral::Ptr& formulaSelection )
: IncludeDefinition( std::make_shared< Identifier >( filename ), formulaSelection )
{
}

const Token::Ptr& IncludeDefinition::includeToken( void ) const
{
    return m_includeToken;
}
const Token::Ptr& IncludeDefinition::leftParenToken( void ) const
{
    return m_leftParenToken;
}
const Identifier::Ptr& IncludeDefinition::filename( void ) const
{
    return m_filename;
}
const Token::Ptr& IncludeDefinition::commaToken( void ) const
{
    return m_commaToken;
}
const ListLiteral::Ptr& IncludeDefinition::formulaSelection( void ) const
{
    return m_formulaSelection;
}
const Token::Ptr& IncludeDefinition::rightParenToken( void ) const
{
    return m_rightParenToken;
}
const Token::Ptr& IncludeDefinition::dotToken( void ) const
{
    return m_dotToken;
}

void IncludeDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr keywordFromFormula( const Formula::Ptr& formula );

FormulaDefinition::FormulaDefinition(
    const Token::Ptr& keyword,
    const Token::Ptr& leftParen,
    const Identifier::Ptr& name,
    const Token::Ptr& commaRole,
    const Role::Ptr& role,
    const Token::Ptr& commaFormula,
    const Formula::Ptr& formula,
    const Token::Ptr& rightParen,
    const Token::Ptr& dot )
: Definition( Node::ID::FORMULA_DEFINITION )
, m_keyword( keyword )
, m_leftParen( leftParen )
, m_name( name )
, m_commaRole( commaRole )
, m_role( role )
, m_commaFormula( commaFormula )
, m_formula( formula )
, m_rightParen( rightParen )
, m_dot( dot )
{
}

FormulaDefinition::FormulaDefinition(
    const Identifier::Ptr& name, const Role::Ptr& role, const Formula::Ptr& formula )
: FormulaDefinition(
      keywordFromFormula( formula ),
      TokenBuilder::LPAREN(),
      name,
      TokenBuilder::COMMA(),
      role,
      TokenBuilder::COMMA(),
      formula,
      TokenBuilder::RPAREN(),
      TokenBuilder::DOT() )
{
}

FormulaDefinition::FormulaDefinition(
    const std::string& name, const Role::Ptr& role, const Formula::Ptr& formula )
: FormulaDefinition( std::make_shared< Identifier >( name ), role, formula )
{
}

const Token::Ptr& FormulaDefinition::keyword( void ) const
{
    return m_keyword;
}

const Token::Ptr& FormulaDefinition::leftParen( void ) const
{
    return m_leftParen;
}

const Identifier::Ptr& FormulaDefinition::name( void ) const
{
    return m_name;
}

const Token::Ptr& FormulaDefinition::commaRole( void ) const
{
    return m_commaRole;
}

const Role::Ptr& FormulaDefinition::role( void ) const
{
    return m_role;
}

const Token::Ptr& FormulaDefinition::commaFormula( void ) const
{
    return m_commaFormula;
}

const Formula::Ptr& FormulaDefinition::formula( void ) const
{
    return m_formula;
}

const Token::Ptr& FormulaDefinition::rightParen( void ) const
{
    return m_rightParen;
}

const Token::Ptr& FormulaDefinition::dot( void ) const
{
    return m_dot;
}

void FormulaDefinition::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr keywordFromFormula( const Formula::Ptr& formula )
{
    switch( formula->id() )
    {
        case Node::ID::FOF_FORMULA:
        {
            return TokenBuilder::FOF();
        }
        case Node::ID::TFF_FORMULA:
        {
            return TokenBuilder::TFF();
        }
        case Node::ID::THF_FORMULA:
        {
            return TokenBuilder::THF();
        }
        case Node::ID::TPI_FORMULA:
        {
            return TokenBuilder::TPI();
        }
        case Node::ID::CNF_FORMULA:
        {
            return TokenBuilder::CNF();
        }
        case Node::ID::TCF_FORMULA:
        {
            return TokenBuilder::TCF();
        }
        default:
            break;
    }
    assert( !"invalid formula id" );
}
//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

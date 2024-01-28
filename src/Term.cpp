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

#include "Term.h"

#include "Atom.h"
#include "Type.h"

using namespace libtptp;

//
// Term
//

Term::Term( const ID id )
: Logic( id )
{
}

//
// VariableTerm
//

VariableTerm::VariableTerm( const Identifier::Ptr& name )
: Term( Node::ID::VARIABLE_TERM )
, m_name( name )
, m_colon()
, m_type()
{
}

VariableTerm::VariableTerm( const std::string& name )
: VariableTerm( std::make_shared< Identifier >( name ) )
{
}

VariableTerm::VariableTerm( const Identifier::Ptr& name, const std::shared_ptr< Type >& type )
: Term( Node::ID::VARIABLE_TERM )
, m_name( name )
, m_colon( TokenBuilder::COLON() )
, m_type( type )
{
}

VariableTerm::VariableTerm( const std::string& name, const std::shared_ptr< Type >& type )
: VariableTerm( std::make_shared< Identifier >( name ), type )
{
}

const Identifier::Ptr& VariableTerm::name( void ) const
{
    return m_name;
}

const libstdhl::Optional< Token::Ptr >& VariableTerm::colon( void )
{
    return m_colon;
}

const libstdhl::Optional< Type::Ptr >& VariableTerm::type( void )
{
    return m_type;
}

void VariableTerm::setColon( const Token::Ptr& colon )
{
    m_colon = colon;
}

void VariableTerm::setType( const Type::Ptr& type )
{
    m_type = type;
}

void VariableTerm::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// ConditionalTerm
//

ConditionalTerm::ConditionalTerm(
    const Token::Ptr& dollar,
    const Token::Ptr& ite,
    const Token::Ptr& leftParen,
    const Logic::Ptr& condition,
    const Token::Ptr& commaLeft,
    const Logic::Ptr& leftTerm,
    const Token::Ptr& commaRight,
    const Logic::Ptr& rightTerm,
    const Token::Ptr& rightParen )
: Term( Node::ID::CONDITIONAL_TERM )
, m_dollar( dollar )
, m_ite( ite )
, m_leftParen( leftParen )
, m_condition( condition )
, m_commaLeft( commaLeft )
, m_leftTerm( leftTerm )
, m_commaRight( commaRight )
, m_rightTerm( rightTerm )
, m_rightParen( rightParen )
{
}

ConditionalTerm::ConditionalTerm(
    const Logic::Ptr& condition, const Logic::Ptr& leftTerm, const Logic::Ptr& rightTerm )
: ConditionalTerm(
      TokenBuilder::DOLLAR(),
      TokenBuilder::ITE(),
      TokenBuilder::LPAREN(),
      condition,
      TokenBuilder::COMMA(),
      leftTerm,
      TokenBuilder::COMMA(),
      rightTerm,
      TokenBuilder::RPAREN() )
{
}

const Token::Ptr& ConditionalTerm::dollar( void ) const
{
    return m_dollar;
}

const Token::Ptr& ConditionalTerm::ite( void ) const
{
    return m_ite;
}

const Token::Ptr& ConditionalTerm::leftParen( void ) const
{
    return m_leftParen;
}

const Logic::Ptr& ConditionalTerm::condition( void ) const
{
    return m_condition;
}

const Token::Ptr& ConditionalTerm::commaLeft( void ) const
{
    return m_commaLeft;
}

const Logic::Ptr& ConditionalTerm::leftTerm( void ) const
{
    return m_leftTerm;
}

const Token::Ptr& ConditionalTerm::commaRight( void ) const
{
    return m_commaRight;
}

const Logic::Ptr& ConditionalTerm::rightTerm( void ) const
{
    return m_rightTerm;
}

const Token::Ptr& ConditionalTerm::rightParen( void ) const
{
    return m_rightParen;
}

void ConditionalTerm::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

DefinitionTerm::DefinitionTerm(
    const Token::Ptr& dollar,
    const Token::Ptr& let,
    const Token::Ptr& leftParen,
    const Atom::Ptr& types,
    const Token::Ptr& commaLeft,
    const Atom::Ptr& definitions,
    const Token::Ptr& commaRight,
    const Logic::Ptr& term,
    const Token::Ptr& rightParen )
: Term( Node::ID::DEFINITION_TERM )
, m_dollar( dollar )
, m_let( let )
, m_leftParen( leftParen )
, m_types( types )
, m_commaLeft( commaLeft )
, m_definitions( definitions )
, m_commaRight( commaRight )
, m_term( term )
, m_rightParen( rightParen )
{
}

DefinitionTerm::DefinitionTerm(
    const Atom::Ptr& types, const Atom::Ptr& definitions, const Logic::Ptr& term )
: DefinitionTerm(
      TokenBuilder::DOLLAR(),
      TokenBuilder::LET(),
      TokenBuilder::LPAREN(),
      types,
      TokenBuilder::COMMA(),
      definitions,
      TokenBuilder::COMMA(),
      term,
      TokenBuilder::RPAREN() )
{
}

const Token::Ptr& DefinitionTerm::dollar( void ) const
{
    return m_dollar;
}

const Token::Ptr& DefinitionTerm::let( void ) const
{
    return m_let;
}

const Token::Ptr& DefinitionTerm::leftParen( void ) const
{
    return m_leftParen;
}

const Atom::Ptr& DefinitionTerm::types( void ) const
{
    return m_types;
}

const Token::Ptr& DefinitionTerm::commaLeft( void ) const
{
    return m_commaLeft;
}

const Atom::Ptr& DefinitionTerm::definitions( void ) const
{
    return m_definitions;
}

const Token::Ptr& DefinitionTerm::commaRight( void ) const
{
    return m_commaRight;
}

const Logic::Ptr& DefinitionTerm::term( void ) const
{
    return m_term;
}

const Token::Ptr& DefinitionTerm::rightParen( void ) const
{
    return m_rightParen;
}

void DefinitionTerm::accept( Visitor& visitor )
{
    visitor.visit( *this );
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

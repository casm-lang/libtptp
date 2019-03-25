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

#include "Atom.h"

using namespace libtptp;

//
// Atom
//

Atom::Atom( const ID id )
: Term( id )
{
}

//
// FunctorAtom
//

FunctorAtom::FunctorAtom(
    const Identifier::Ptr& name,
    const Token::Ptr& leftParen,
    const ListLogicElements::Ptr& arguments,
    const Token::Ptr& rightParen,
    const Kind kind )
: Atom( Node::ID::FUNCTOR_ATOM )
, m_name( name )
, m_leftParen( leftParen )
, m_arguments( arguments )
, m_rightParen( rightParen )
, m_kind( kind )
{
}

FunctorAtom::FunctorAtom(
    const Identifier::Ptr& name, const ListLogicElements::Ptr& arguments, const Kind kind )
: FunctorAtom( name, TokenBuilder::LPAREN(), arguments, TokenBuilder::RPAREN(), kind )
{
}

const Identifier::Ptr& FunctorAtom::name( void ) const
{
    return m_name;
}

const Token::Ptr& FunctorAtom::leftParen( void ) const
{
    return m_leftParen;
}

const ListLogicElements::Ptr& FunctorAtom::arguments( void ) const
{
    return m_arguments;
}

const Token::Ptr& FunctorAtom::rightParen( void ) const
{
    return m_rightParen;
}

const FunctorAtom::Kind FunctorAtom::kind( void ) const
{
    return m_kind;
}

void FunctorAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

ConstantAtom::ConstantAtom( const Identifier::Ptr& constant, const Kind kind )
: Atom( Node::ID::CONSTANT_ATOM )
, m_constant( constant )
, m_kind( kind )
{
}

const Identifier::Ptr& ConstantAtom::constant( void ) const
{
    return m_constant;
}

const ConstantAtom::Kind ConstantAtom::kind( void ) const
{
    return m_kind;
}

void ConstantAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

DefinedAtom::DefinedAtom( const Literal::Ptr& literal )
: Atom( Node::ID::DEFINED_ATOM )
, m_literal( literal )
{
}

const Literal::Ptr& DefinedAtom::literal( void ) const
{
    return m_literal;
}

void DefinedAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

DefinitionAtom::DefinitionAtom(
    const Logic::Ptr& lhs, const Token::Ptr& assignment, const Logic::Ptr& rhs )
: Atom( Node::ID::DEFINITION_ATOM )
, m_lhs( lhs )
, m_assignment( assignment )
, m_rhs( rhs )
{
}

DefinitionAtom::DefinitionAtom( const Logic::Ptr& lhs, const Logic::Ptr& rhs )
: DefinitionAtom( lhs, TokenBuilder::ASSIGNMENT(), rhs )
{
}

const Logic::Ptr& DefinitionAtom::lhs( void ) const
{
    return m_lhs;
}

const Token::Ptr& DefinitionAtom::assignment( void ) const
{
    return m_assignment;
}

const Logic::Ptr& DefinitionAtom::rhs( void ) const
{
    return m_rhs;
}

void DefinitionAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

ConnectiveAtom::ConnectiveAtom( Token::Ptr& connective )
: Atom( Node::ID::CONNECTIVE_ATOM )
, m_connective( connective )
{
}

void ConnectiveAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& ConnectiveAtom::connective( void )
{
    return m_connective;
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

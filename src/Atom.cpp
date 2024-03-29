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

#include "Atom.h"
#include <initializer_list>
#include <libtptp/Literal>
#include <libtptp/Type>

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

FunctorAtom::FunctorAtom(
    const std::string& name, const ListLogicElements::Ptr& arguments, const Kind kind )
: FunctorAtom( std::make_shared< Identifier >( name ), arguments, kind )
{
}

FunctorAtom::FunctorAtom(
    const std::string& name, const std::initializer_list< Logic::Ptr >& arguments, const Kind kind )
: FunctorAtom( name, std::make_shared< ListLogicElements >( arguments ), kind )
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

FunctorAtom::Ptr FunctorAtom::less( const Logic::Ptr& lhs, const Logic::Ptr& rhs )
{
    return std::make_shared< FunctorAtom >(
        "$less", std::initializer_list< Logic::Ptr >{ lhs, rhs }, Kind::DEFINED );
}

FunctorAtom::Ptr FunctorAtom::less_eq( const Logic::Ptr& lhs, const Logic::Ptr& rhs )
{
    return std::make_shared< FunctorAtom >(
        "$lesseq", std::initializer_list< Logic::Ptr >{ lhs, rhs }, Kind::DEFINED );
}

FunctorAtom::Ptr FunctorAtom::greater( const Logic::Ptr& lhs, const Logic::Ptr& rhs )
{
    return std::make_shared< FunctorAtom >(
        "$greater", std::initializer_list< Logic::Ptr >{ lhs, rhs }, Kind::DEFINED );
}

FunctorAtom::Ptr FunctorAtom::greater_eq( const Logic::Ptr& lhs, const Logic::Ptr& rhs )
{
    return std::make_shared< FunctorAtom >(
        "$greatereq", std::initializer_list< Logic::Ptr >{ lhs, rhs }, Kind::DEFINED );
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

ConstantAtom::ConstantAtom( const std::string& constant, const Kind kind )
: ConstantAtom( std::make_shared< Identifier >( constant ), kind )
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

DefinedAtom::DefinedAtom( const std::string& literal )
: DefinedAtom( std::make_shared< DistinctObjectLiteral >( literal ) )
{
}

DefinedAtom::DefinedAtom( int literal )
: DefinedAtom( std::make_shared< IntegerLiteral >( literal ) )
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
// TypeAtom
//

TypeAtom::TypeAtom( const Identifier::Ptr& atom, const Token::Ptr& colon, const Type::Ptr& type )
: Atom( Node::ID::TYPE_ATOM )
, m_atom( atom )
, m_colon( colon )
, m_type( type )
{
}

TypeAtom::TypeAtom( const std::string& atom, const std::shared_ptr< Type >& type )
: TypeAtom( std::make_shared< Identifier >( atom ), type )
{
}

TypeAtom::TypeAtom( const Identifier::Ptr& atom, const Type::Ptr& type )
: TypeAtom( atom, TokenBuilder::COLON(), type )
{
}

const Type::Ptr& TypeAtom::type( void ) const
{
    return m_type;
}

const Token::Ptr& TypeAtom::colon( void ) const
{
    return m_colon;
}

const Identifier::Ptr& TypeAtom::atom( void ) const
{
    return m_atom;
}

void TypeAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// TupleAtom
//

TupleAtom::TupleAtom(
    const Token::Ptr& leftParen, const ListAtomElements::Ptr& atoms, const Token::Ptr& rightParen )
: Atom( Node::ID::TUPLE_ATOM )
, m_leftParen( leftParen )
, m_atoms( atoms )
, m_rightParen( rightParen )
{
}

TupleAtom::TupleAtom( const ListAtomElements::Ptr& atoms )
: TupleAtom( TokenBuilder::LSQPAREN(), atoms, TokenBuilder::RSQPAREN() )
{
}

TupleAtom::TupleAtom( const std::initializer_list< Atom::Ptr >& atoms )
: TupleAtom( std::make_shared< ListAtomElements >( atoms ) )
{
}

const Token::Ptr& TupleAtom::leftParen( void ) const
{
    return m_leftParen;
}

const ListAtomElements::Ptr& TupleAtom::atoms( void ) const
{
    return m_atoms;
}

const Token::Ptr& TupleAtom::rightParen( void ) const
{
    return m_rightParen;
}

void TupleAtom::accept( Visitor& visitor )
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

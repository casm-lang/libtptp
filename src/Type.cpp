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
#include "Type.h"

using namespace libtptp;

Type::Type( const ID id )
: Atom( id )
{
}

AtomType::AtomType( const Node::Ptr& atom )
: Type( Node::ID::ATOM_TYPE )
, m_atom( atom )
{
}

void AtomType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Node::Ptr& AtomType::atom( void ) const
{
    return m_atom;
}

//
// Binary Type
//

BinaryType::BinaryType(
    const Type::Ptr& left,
    const Token::Ptr& connectiveToken,
    const Type::Ptr& right,
    const Kind kind )
: Type( Node::ID::BINARY_TYPE )
, m_left( left )
, m_connectiveToken( connectiveToken )
, m_right( right )
, m_kind( kind )
{
}

void BinaryType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Type::Ptr& BinaryType::left( void ) const
{
    return m_left;
}

const Token::Ptr& BinaryType::connectiveToken( void ) const
{
    return m_connectiveToken;
}

const Type::Ptr& BinaryType::right( void ) const
{
    return m_right;
}

const BinaryType::Kind& BinaryType::kind( void ) const
{
    return m_kind;
}

//
// TypedAtom
//

TypedAtom::TypedAtom( const Identifier::Ptr& atom, const Token::Ptr& colon, const Type::Ptr& type )
: Type( Node::ID::TYPED_ATOM )
, m_atom( atom )
, m_colon( colon )
, m_type( type )
{
}

void TypedAtom::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Type::Ptr& TypedAtom::type( void ) const
{
    return m_type;
}

const Token::Ptr& TypedAtom::colon( void ) const
{
    return m_colon;
}

const Identifier::Ptr& TypedAtom::atom( void ) const
{
    return m_atom;
}

//
// TupleType
//

TupleType::TupleType(
    const Token::Ptr& leftBraceToken, const Types::Ptr& tuples, const Token::Ptr& rightBraceToken )
: Type( Node::ID::TUPLE_TYPE )
, m_leftBraceToken( leftBraceToken )
, m_tuples( tuples )
, m_rightBraceToken( rightBraceToken )
{
}

void TupleType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& TupleType::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}

const Types::Ptr& TupleType::tuples( void ) const
{
    return m_tuples;
}

const Token::Ptr& TupleType::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

//
// QuantifiedType
//

QuantifiedType::QuantifiedType(
    const Token::Ptr& quantifierToken,
    const Token::Ptr& leftParen,
    const Nodes::Ptr& variables,
    const Token::Ptr& rightParen,
    const Token::Ptr& colon,
    const Type::Ptr& type )
: Type( Node::ID::QUANTIFIED_TYPE )
, m_quantifierToken( quantifierToken )
, m_leftParen( leftParen )
, m_variables( variables )
, m_rightParen( rightParen )
, m_colon( colon )
, m_type( type )
{
}

void QuantifiedType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& QuantifiedType::quantifierToken( void ) const
{
    return m_quantifierToken;
}

const Token::Ptr& QuantifiedType::leftParen( void ) const
{
    return m_leftParen;
}

const Nodes::Ptr& QuantifiedType::variables( void ) const
{
    return m_variables;
}

const Token::Ptr& QuantifiedType::rightParen( void ) const
{
    return m_rightParen;
}

const Token::Ptr& QuantifiedType::colon( void ) const
{
    return m_colon;
}

const Type::Ptr& QuantifiedType::type( void ) const
{
    return m_type;
}

//
// SubType
//

SubType::SubType(
    const Identifier::Ptr& lhs, const Token::Ptr& subtypesign, const Identifier::Ptr& rhs )
: Type( Node::ID::SUB_TYPE )
, m_lhs( lhs )
, m_subtypesign( subtypesign )
, m_rhs( rhs )
{
}

void SubType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Identifier::Ptr& SubType::lhs( void ) const
{
    return m_lhs;
}

const Token::Ptr& SubType::subtypesign( void ) const
{
    return m_subtypesign;
}

const Identifier::Ptr& SubType::rhs( void ) const
{
    return m_rhs;
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

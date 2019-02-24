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

#include "Literal.h"

using namespace libtptp;

static const auto uToken = std::make_shared< Token >( Grammar::Token::UNRESOLVED );

Literal::Literal( const Node::ID id )
: Node( id )
{
}

ValueLiteral::ValueLiteral( const Node::ID id, libstdhl::Type::Data value )
: Literal( id )
, m_value( value )
{
}

const libstdhl::Type::Data& ValueLiteral::value( void ) const
{
    return m_value;
}

IntegerLiteral::IntegerLiteral( const std::string& integer )
: ValueLiteral( Node::ID::INTEGER_LITERAL, libstdhl::Type::createInteger( integer ) )
{
}

void IntegerLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

RationalLiteral::RationalLiteral( const std::string& rational )
: ValueLiteral( Node::ID::RATIONAL_LITERAL, libstdhl::Type::createRational( rational ) )
{
}

void RationalLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

RealLiteral::RealLiteral( const std::string& real )
: ValueLiteral( Node::ID::REAL_LITERAL, libstdhl::Type::createDecimal( real ) )
{
}

void RealLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

StringLiteral::StringLiteral( const std::string& string )
: StringLiteral( uToken, uToken, string )
{
}
StringLiteral::StringLiteral( const Token::Ptr& definedModifier, const std::string& string )
: StringLiteral( uToken, definedModifier, string )
{
}

StringLiteral::StringLiteral(
    const Token::Ptr& systemModifier, const Token::Ptr& definedModifier, const std::string& string )
: ValueLiteral( Node::ID::STRING_LITERAL, libstdhl::Type::createString( string ) )
, m_systemModifier( systemModifier )
, m_definedModifier( definedModifier )
{
    switch( string[ 0 ] )
    {
        case '"':
        {
            m_kind = Kind::DOUBLE_QUOTED;
            break;
        }
        case '\'':
        {
            m_kind = Kind::SINGLE_QUOTED;
            break;
        }
        default:
        {
            m_kind = Kind::NOT_QUOTED;
            break;
        }
    }
}

const Token::Ptr StringLiteral::systemModifier( void ) const
{
    return m_systemModifier;
}

const Token::Ptr StringLiteral::definedModifier( void ) const
{
    return m_definedModifier;
}

void StringLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const StringLiteral::Kind& StringLiteral::kind( void ) const
{
    return m_kind;
}

const std::string StringLiteral::kindName( void ) const
{
    switch( m_kind )
    {
        case StringLiteral::Kind::NOT_QUOTED:
            return "not quoted";
        case StringLiteral::Kind::DOUBLE_QUOTED:
            return "double qouted";
        case StringLiteral::Kind::SINGLE_QUOTED:
            return "single quoted";
    };
    assert( !"impossible StringLiteral Kind" );
    return std::string();
}

ListLiteral::ListLiteral( const Token::Ptr& leftBraceToken, const Token::Ptr& rightBraceToken )
: ListLiteral( leftBraceToken, std::make_shared< Nodes >(), rightBraceToken )
{
}

ListLiteral::ListLiteral(
    const Token::Ptr& leftBraceToken,
    const Nodes::Ptr& elements,
    const Token::Ptr& rightBraceToken )
: Literal( Node::ID::LIST_LITERAL )
, m_leftBraceToken( leftBraceToken )
, m_elements( elements )
, m_rightBraceToken( rightBraceToken )
{
}

const Token::Ptr& ListLiteral::leftBraceToken() const
{
    return m_leftBraceToken;
}

const Nodes::Ptr& ListLiteral::elements( void ) const
{
    return m_elements;
}

const Token::Ptr& ListLiteral::rightBraceToken() const
{
    return m_rightBraceToken;
}

void ListLiteral::accept( Visitor& visitor )
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

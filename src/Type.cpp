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
#include "Type.h"

using namespace libtptp;

Type::Type( const ID id )
: Atom( id )
{
}

ApplyType::ApplyType( const Node::Ptr& atom )
: Type( Node::ID::APPLY_TYPE )
, m_atom( atom )
{
}

const Node::Ptr& ApplyType::atom( void ) const
{
    return m_atom;
}

void ApplyType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

NamedType::NamedType( const Identifier::Ptr& name )
: Type( ID::NAMED_TYPE )
, m_name( name )
{
}

NamedType::NamedType( const std::string& name )
: NamedType( std::make_shared< Identifier >( name ) )
{
}

const Identifier::Ptr& NamedType::name( void ) const
{
    return m_name;
}

void NamedType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

FunctorType::FunctorType(
    const Identifier::Ptr& name,
    const Token::Ptr& leftParen,
    const ListTypeElements<>::Ptr& arguments,
    const Token::Ptr& rightParen )
: Type( ID::FUNCTOR_TYPE )
, m_name( name )
, m_leftParen( leftParen )
, m_arguments( arguments )
, m_rightParen( rightParen )
{
}

FunctorType::FunctorType( const Identifier::Ptr& name, const ListTypeElements<>::Ptr& arguments )
: FunctorType( name, TokenBuilder::LPAREN(), arguments, TokenBuilder::RPAREN() )
{
}

FunctorType::FunctorType( const std::string& name, const ListTypeElements<>::Ptr& arguments )
: FunctorType( std::make_shared< Identifier >( name ), arguments )
{
}

FunctorType::FunctorType(
    const std::string& name, const std::initializer_list< Type::Ptr >& arguments )
: FunctorType( name, std::make_shared< ListTypeElements<> >( arguments ) )
{
}

const Identifier::Ptr& FunctorType::name( void ) const
{
    return m_name;
}

const Token::Ptr& FunctorType::leftParen( void ) const
{
    return m_leftParen;
}

const ListTypeElements<>::Ptr& FunctorType::arguments( void ) const
{
    return m_arguments;
}

const Token::Ptr& FunctorType::rightParen( void ) const
{
    return m_rightParen;
}

void FunctorType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// Binary Type
//

const Token::Ptr connectiveTokenFromKind( BinaryType::Kind kind );

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

BinaryType::BinaryType( const Type::Ptr& left, const Type::Ptr& right, const Kind kind )
: BinaryType( left, connectiveTokenFromKind( kind ), right, kind )
{
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

BinaryType::Kind BinaryType::kind( void ) const
{
    return m_kind;
}

void BinaryType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr connectiveTokenFromKind( BinaryType::Kind kind )
{
    switch( kind )
    {
        case BinaryType::Kind::MAPPING:
        {
            return TokenBuilder::GREATER();
        }
        case BinaryType::Kind::UNION:
        {
            return TokenBuilder::PLUS();
        }
    }
}

RelationType::RelationType( const ListTypeElements< TokenBuilder::STAR >::Ptr& elements )
: Type( ID::RELATION_TYPE )
, m_elements( elements )
{
    this->setLeftDelimiter( TokenBuilder::LPAREN() );
    this->setRightDelimiter( TokenBuilder::RPAREN() );
}

RelationType::RelationType( const std::initializer_list< Type::Ptr >& elements )
: RelationType( std::make_shared< ListTypeElements< TokenBuilder::STAR > >( elements ) )
{
}

const ListTypeElements< TokenBuilder::STAR >::Ptr& RelationType::elements( void ) const
{
    return m_elements;
}

void RelationType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// TupleType
//

TupleType::TupleType(
    const Token::Ptr& leftBraceToken,
    const ListTypeElements<>::Ptr& tuples,
    const Token::Ptr& rightBraceToken )
: Type( Node::ID::TUPLE_TYPE )
, m_leftBraceToken( leftBraceToken )
, m_tuples( tuples )
, m_rightBraceToken( rightBraceToken )
{
}

TupleType::TupleType( const ListTypeElements<>::Ptr& tuples )
: TupleType( TokenBuilder::LSQPAREN(), tuples, TokenBuilder::RSQPAREN() )
{
}

TupleType::TupleType( const std::initializer_list< Type::Ptr >& tuples )
: TupleType( std::make_shared< ListTypeElements<> >( tuples ) )
{
}

const Token::Ptr& TupleType::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}

const ListTypeElements<>::Ptr& TupleType::tuples( void ) const
{
    return m_tuples;
}

const Token::Ptr& TupleType::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

void TupleType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// QuantifiedType
//

QuantifiedType::QuantifiedType(
    const Token::Ptr& quantifierToken,
    const Token::Ptr& leftParen,
    const ListVariableElements::Ptr& variables,
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

QuantifiedType::QuantifiedType( const ListVariableElements::Ptr& variables, const Type::Ptr& type )
: QuantifiedType(
      TokenBuilder::EXCLAMATIONGREATER(),
      TokenBuilder::LSQPAREN(),
      variables,
      TokenBuilder::RSQPAREN(),
      TokenBuilder::COLON(),
      type )
{
}

QuantifiedType::QuantifiedType(
    const std::initializer_list< VariableTerm::Ptr >& variables, const Type::Ptr& type )
: QuantifiedType( std::make_shared< ListVariableElements >( variables ), type )
{
}

const Token::Ptr& QuantifiedType::quantifierToken( void ) const
{
    return m_quantifierToken;
}

const Token::Ptr& QuantifiedType::leftParen( void ) const
{
    return m_leftParen;
}

const ListVariableElements::Ptr& QuantifiedType::variables( void ) const
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

void QuantifiedType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// SubType
//

SubType::SubType(
    const Identifier::Ptr& leftAtom,
    const Token::Ptr& subtypesign,
    const Identifier::Ptr& rightAtom )
: Type( Node::ID::SUB_TYPE )
, m_leftAtom( leftAtom )
, m_subTypeSign( subtypesign )
, m_rightAtom( rightAtom )
{
}

SubType::SubType( const Identifier::Ptr& leftAtom, const Identifier::Ptr& rightAtom )
: SubType( leftAtom, TokenBuilder::SUBTYPESIGN(), rightAtom )
{
}

SubType::SubType( const std::string& leftAtom, const std::string& rightAtom )
: SubType( std::make_shared< Identifier >( leftAtom ), std::make_shared< Identifier >( rightAtom ) )
{
}

void SubType::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Identifier::Ptr& SubType::leftAtom( void ) const
{
    return m_leftAtom;
}

const Token::Ptr& SubType::subTypeSign( void ) const
{
    return m_subTypeSign;
}

const Identifier::Ptr& SubType::rightAtom( void ) const
{
    return m_rightAtom;
}

VariableType::VariableType( const VariableTerm::Ptr& variable )
: Type( ID::VARIABLE_TYPE )
, m_variable( variable )
{
}

const VariableTerm::Ptr& VariableType::variable( void ) const
{
    return m_variable;
}

void VariableType::accept( Visitor& visitor )
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

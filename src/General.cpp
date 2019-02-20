//
//  Copyright (C) 2017-2018 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
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

#include "General.h"
#include "various/GrammarToken.h"
using namespace libtptp;

static const auto uToken = std::make_shared< Token >( Grammar::Token::UNRESOLVED );

GeneralTerm::GeneralTerm( const Node::ID id )
: Node( id )
{
}

GeneralData::GeneralData( const Node::Ptr& data )
: GeneralTerm( Node::ID::GENERAL_DATA )
, m_data( data )
{
}

void GeneralData::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Node::Ptr& GeneralData::data( void ) const
{
    return m_data;
}

GeneralList::GeneralList( const ListLiteral::Ptr& list )
: GeneralTerm( Node::ID::GENERAL_LIST )
, m_list( list )
{
}

void GeneralList::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const ListLiteral::Ptr& GeneralList::list( void ) const
{
    return m_list;
}

GeneralAggregator::GeneralAggregator(
    const GeneralData::Ptr& data, const Token::Ptr& colon, const GeneralTerm::Ptr& term )
: GeneralTerm( Node::ID::GENERAL_AGGREGATOR )
, m_data( data )
, m_colon( colon )
, m_term( term )
{
}

void GeneralAggregator::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const GeneralData::Ptr& GeneralAggregator::data( void ) const
{
    return m_data;
}
const Token::Ptr& GeneralAggregator::colon( void ) const
{
    return m_colon;
}
const GeneralTerm::Ptr& GeneralAggregator::term( void ) const
{
    return m_term;
}

GeneralFunction::GeneralFunction(
    const Identifier::Ptr& name,
    const Token::Ptr& leftParen,
    const Nodes::Ptr& arguments,
    const Token::Ptr& rightParen )
: GeneralTerm( Node::ID::GENERAL_FUNCTION )
, m_name( name )
, m_leftParen( leftParen )
, m_arguments( arguments )
, m_rightParen( rightParen )
{
}

void GeneralFunction::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Identifier::Ptr& GeneralFunction::name( void ) const
{
    return m_name;
}
const Token::Ptr& GeneralFunction::leftParen( void ) const
{
    return m_leftParen;
}
const Nodes::Ptr& GeneralFunction::arguments( void ) const
{
    return m_arguments;
}
const Token::Ptr& GeneralFunction::rightParen( void ) const
{
    return m_rightParen;
}

Annotation::Annotation(
    const GeneralTerm::Ptr& source, const Token::Ptr& comma, const GeneralList::Ptr& usefulInfo )
: Node( Node::ID::ANNOTATION )
, m_delimiter( uToken )
, m_source( source )
, m_comma( comma )
, m_usefulInfo( usefulInfo )
{
}

Annotation::Annotation( const GeneralTerm::Ptr& source )
: Node( Node::ID::ANNOTATION )
, m_delimiter()
, m_source( source )
, m_comma( uToken )
, m_usefulInfo()
{
}

void Annotation::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const GeneralTerm::Ptr& Annotation::source( void ) const
{
    return m_source;
}
const libstdhl::Optional< const GeneralList::Ptr >& Annotation::usefulInfo( void ) const
{
    return m_usefulInfo;
}
const Token::Ptr& Annotation::comma() const
{
    return m_comma;
}

void Annotation::setDelimiter( const Token::Ptr& delimiter )
{
    m_delimiter = delimiter;
}

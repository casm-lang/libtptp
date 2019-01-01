//
//  Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
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
//

#include "Logic.h"

using namespace libtptp;

//
// Logic
//

Logic::Logic( const ID id )
: Node( id )
{
}

//
// UnaryLogic
//

UnaryLogic::UnaryLogic( const Logic::Ptr& logic, const UnaryLogic::Connective connective )
: Logic( Node::ID::UNARY_LOGIC )
, m_logic( logic )
, m_connective( connective )
{
}

const Logic::Ptr& UnaryLogic::logic( void ) const
{
    return m_logic;
}

const UnaryLogic::Connective UnaryLogic::connective( void ) const
{
    return m_connective;
}

std::string UnaryLogic::connectiveToken( void ) const
{
    switch( connective() )
    {
        case UnaryLogic::Connective::NEGATION:
        {
            return "~";
        }
    }
}

std::string UnaryLogic::connectiveDescription( void ) const
{
    switch( connective() )
    {
        case UnaryLogic::Connective::NEGATION:
        {
            return "negation";
        }
    }
}

void UnaryLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// BinaryLogic
//

BinaryLogic::BinaryLogic(
    const Logic::Ptr& left, const Logic::Ptr& right, const BinaryLogic::Connective connective )
: Logic( Node::ID::BINARY_LOGIC )
, m_left( left )
, m_right( right )
, m_connective( connective )
, m_associative(
      connective == BinaryLogic::Connective::DISJUNCTION or
      connective == BinaryLogic::Connective::CONJUNCTION )
{
}

const Logic::Ptr& BinaryLogic::left( void ) const
{
    return m_left;
}

const Logic::Ptr& BinaryLogic::right( void ) const
{
    return m_right;
}

const BinaryLogic::Connective BinaryLogic::connective( void ) const
{
    return m_connective;
}

std::string BinaryLogic::connectiveToken( void ) const
{
    switch( connective() )
    {
        case BinaryLogic::Connective::DISJUNCTION:
        {
            return "|";
        }
        case BinaryLogic::Connective::CONJUNCTION:
        {
            return "&";
        }
        case BinaryLogic::Connective::EQUIVALENCE:
        {
            return "<=>";
        }
        case BinaryLogic::Connective::NON_EQUIVALENCE:
        {
            return "<~>";
        }
        case BinaryLogic::Connective::IMPLICATION:
        {
            return "=>";
        }
        case BinaryLogic::Connective::REVERSE_IMPLICATION:
        {
            return "<=";
        }
        case BinaryLogic::Connective::NEGATED_DISJUNCTION:
        {
            return "~|";
        }
        case BinaryLogic::Connective::NEGATED_CONJUNCTION:
        {
            return "~&";
        }
    }
}

std::string BinaryLogic::connectiveDescription( void ) const
{
    switch( connective() )
    {
        case BinaryLogic::Connective::DISJUNCTION:
        {
            return "disjunction";
        }
        case BinaryLogic::Connective::CONJUNCTION:
        {
            return "conjunction";
        }
        case BinaryLogic::Connective::EQUIVALENCE:
        {
            return "equivalence";
        }
        case BinaryLogic::Connective::NON_EQUIVALENCE:
        {
            return "non-equivalence";
        }
        case BinaryLogic::Connective::IMPLICATION:
        {
            return "implication";
        }
        case BinaryLogic::Connective::REVERSE_IMPLICATION:
        {
            return "reverse implication";
        }
        case BinaryLogic::Connective::NEGATED_DISJUNCTION:
        {
            return "negated disjunction";
        }
        case BinaryLogic::Connective::NEGATED_CONJUNCTION:
        {
            return "negated conjunction";
        }
    }
}

u1 BinaryLogic::associative( void ) const
{
    return m_associative;
}

void BinaryLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// QuantifiedLogic
//

QuantifiedLogic::QuantifiedLogic(
    const Logic::Ptr& logic,
    const Identifiers::Ptr& variables,
    const QuantifiedLogic::Connective connective )
: Logic( Node::ID::QUANTIFIED_LOGIC )
, m_logic( logic )
, m_variables( variables )
, m_connective( connective )
{
}

const Logic::Ptr& QuantifiedLogic::logic( void ) const
{
    return m_logic;
}

const Identifiers::Ptr& QuantifiedLogic::variables( void ) const
{
    return m_variables;
}

const QuantifiedLogic::Connective QuantifiedLogic::connective( void ) const
{
    return m_connective;
}

std::string QuantifiedLogic::connectiveToken( void ) const
{
    switch( connective() )
    {
        case QuantifiedLogic::Connective::UNIVERSAL:
        {
            return "!";
        }
        case QuantifiedLogic::Connective::EXISTENTIAL:
        {
            return "?";
        }
    }
}

std::string QuantifiedLogic::connectiveDescription( void ) const
{
    switch( connective() )
    {
        case QuantifiedLogic::Connective::UNIVERSAL:
        {
            return "universal";
        }
        case QuantifiedLogic::Connective::EXISTENTIAL:
        {
            return "existential";
        }
    }
}

void QuantifiedLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// SequentLogic
//

SequentLogic::SequentLogic( const Logics::Ptr& left, const Logics::Ptr& right )
: Logic( Node::ID::SEQUENT_LOGIC )
, m_left( left )
, m_right( right )
{
}

const Logics::Ptr& SequentLogic::left( void ) const
{
    return m_left;
}

const Logics::Ptr& SequentLogic::right( void ) const
{
    return m_right;
}

std::string SequentLogic::connectiveToken( void ) const
{
    return "-->";  // gentzen arrow
}

std::string SequentLogic::connectiveDescription( void ) const
{
    return "sequent";
}

void SequentLogic::accept( Visitor& visitor )
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

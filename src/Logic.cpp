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

#include "Logic.h"
#include "Term.h"

using namespace libtptp;

//
// Logic
//

Logic::Logic( const ID id )
: Node( id )
, m_leftDelimiter( TokenBuilder::UNRESOLVED() )
, m_rightDelimiter( TokenBuilder::UNRESOLVED() )
{
}

const Token::Ptr& Logic::leftDelimiter( void ) const
{
    return m_leftDelimiter;
}
const Token::Ptr& Logic::rightDelimiter( void ) const
{
    return m_rightDelimiter;
}
void Logic::setLeftDelimiter( const Token::Ptr& leftDelimiter )
{
    m_leftDelimiter = leftDelimiter;
}
void Logic::setRightDelimiter( const Token::Ptr& rightDelimiter )
{
    m_rightDelimiter = rightDelimiter;
}

//
// UnaryLogic
//

UnaryLogic::UnaryLogic(
    const std::pair< const Token::Ptr&, const Connective > connective, const Logic::Ptr& logic )
: Logic( Node::ID::UNARY_LOGIC )
, m_connectiveToken( connective.first )
, m_logic( logic )
, m_connective( connective.second )
{
}

UnaryLogic::UnaryLogic( const Connective connective, const Logic::Ptr& logic )
: UnaryLogic( std::make_pair( connectiveTokenFromConnective( connective ), connective ), logic )
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

const Token::Ptr& UnaryLogic::connectiveToken( void ) const
{
    return m_connectiveToken;
}

std::string UnaryLogic::connectiveDescription( void ) const
{
    switch( connective() )
    {
        case UnaryLogic::Connective::NEGATION:
        {
            return "negation";
        }
        case UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION:
        {
            return "universal quantification";
        }
        case UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION:
        {
            return "existential quantification";
        }
        case UnaryLogic::Connective::INDEFINITE_DESCRIPTION:
        {
            return "indefinite description";
        }
        case UnaryLogic::Connective::DEFINITE_DESCRIPTION:
        {
            return "definite description";
        }
        case UnaryLogic::Connective::EQUALITY:
        {
            return "equality";
        }
    }
}

void UnaryLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& UnaryLogic::connectiveTokenFromConnective( Connective connective ) const
{
    switch( connective )
    {
        case Connective::NEGATION:
        {
            return TokenBuilder::TILDE();
        }
        case Connective::UNIVERSAL_QUANTIFICATION:
        {
            return TokenBuilder::DOUBLEEXCLAMATION();
        }
        case Connective::EXISTENTIAL_QUANTIFICATION:
        {
            return TokenBuilder::DOUBLEQUESTIONMARK();
        }
        case Connective::INDEFINITE_DESCRIPTION:
        {
            return TokenBuilder::DOUBLEATPLUS();
        }
        case Connective::DEFINITE_DESCRIPTION:
        {
            return TokenBuilder::DOUBLEATMINUS();
        }
        case Connective::EQUALITY:
        {
            return TokenBuilder::ATEQUAL();
        }
    }
}

//
// BinaryLogic
//

BinaryLogic::BinaryLogic(
    const Logic::Ptr& left,
    const std::pair< const Token::Ptr&, Connective > connective,
    const Logic::Ptr& right )
: Logic( Node::ID::BINARY_LOGIC )
, m_left( left )
, m_right( right )
, m_connectiveToken( connective.first )
, m_connective( connective.second )
, m_associative(
      m_connective == BinaryLogic::Connective::DISJUNCTION or
      m_connective == BinaryLogic::Connective::CONJUNCTION )
{
}

BinaryLogic::BinaryLogic(
    const Logic::Ptr& left, const Connective connective, const Logic::Ptr& right )
: BinaryLogic(
      left, std::make_pair( connectiveTokenFromConnective( connective ), connective ), right )
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

const Token::Ptr& BinaryLogic::connectiveToken( void ) const
{
    return m_connectiveToken;
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
        case BinaryLogic::Connective::APPLY:
        {
            return "apply";
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

const Token::Ptr& BinaryLogic::connectiveTokenFromConnective( Connective connective ) const
{
    switch( connective )
    {
        case Connective::DISJUNCTION:
        {
            return TokenBuilder::VLINE();
        }
        case Connective::CONJUNCTION:
        {
            return TokenBuilder::AND();
        }
        case Connective::EQUIVALENCE:
        {
            return TokenBuilder::EQUALITY();
        }
        case Connective::NON_EQUIVALENCE:
        {
            return TokenBuilder::INEQUALITY();
        }
        case Connective::IMPLICATION:
        {
            return TokenBuilder::IMPLICATION();
        }
        case Connective::REVERSE_IMPLICATION:
        {
            return TokenBuilder::RIMPLICATION();
        }
        case Connective::NEGATED_DISJUNCTION:
        {
            return TokenBuilder::NOR();
        }
        case Connective::NEGATED_CONJUNCTION:
        {
            return TokenBuilder::NAND();
        }
        case Connective::APPLY:
        {
            return TokenBuilder::AT();
        }
    }
}

//
// QuantifiedLogic
//

QuantifiedLogic::QuantifiedLogic(
    const std::pair< const Token::Ptr&, const Quantifier > quantifier,
    const ListLiteral::Ptr& variables,
    const Token::Ptr& colon,
    const Logic::Ptr& logic )
: Logic( Node::ID::QUANTIFIED_LOGIC )
, m_quantifierToken( quantifier.first )
, m_variables( variables )
, m_colon( colon )
, m_logic( logic )
, m_quantifier( quantifier.second )
{
}

QuantifiedLogic::QuantifiedLogic(
    const Quantifier quantifier, const ListLiteral::Ptr& variables, const Logic::Ptr& logic )
: QuantifiedLogic(
      std::make_pair( quantifierTokenFromQuantifier( quantifier ), quantifier ),
      variables,
      TokenBuilder::COLON(),
      logic )
{
}

const Token::Ptr& QuantifiedLogic::quantifierToken( void ) const
{
    return m_quantifierToken;
}

const ListLiteral::Ptr& QuantifiedLogic::variables( void ) const
{
    return m_variables;
}

const Token::Ptr& QuantifiedLogic::colon( void ) const
{
    return m_colon;
}

const Logic::Ptr& QuantifiedLogic::logic( void ) const
{
    return m_logic;
}

const QuantifiedLogic::Quantifier QuantifiedLogic::quantifier( void ) const
{
    return m_quantifier;
}

std::string QuantifiedLogic::quantifierDescription( void ) const
{
    switch( quantifier() )
    {
        case QuantifiedLogic::Quantifier::UNIVERSAL:
        {
            return "universal";
        }
        case QuantifiedLogic::Quantifier::EXISTENTIAL:
        {
            return "existential";
        }
        case QuantifiedLogic::Quantifier::EXCLAMATIONGREATER:
        {
            return "exclamation greater";
        }
        case QuantifiedLogic::Quantifier::QUESTIONMARKSTAR:
        {
            return "questionmark star";
        }
        case QuantifiedLogic::Quantifier::CARET:
        {
            return "caret";
        }
        case QuantifiedLogic::Quantifier::ATPLUS:
        {
            return "at plus";
        }
        case QuantifiedLogic::Quantifier::ATMINUS:
        {
            return "at minus";
        }
    }
}

void QuantifiedLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& QuantifiedLogic::quantifierTokenFromQuantifier( Quantifier quantifier ) const
{
    switch( quantifier )
    {
        case Quantifier::UNIVERSAL:
        {
            return TokenBuilder::EXCLAMATION();
        }
        case Quantifier::EXISTENTIAL:
        {
            return TokenBuilder::QUESTIONMARK();
        }
        case Quantifier::EXCLAMATIONGREATER:
        {
            return TokenBuilder::EXCLAMATIONGREATER();
        }
        case Quantifier::QUESTIONMARKSTAR:
        {
            return TokenBuilder::QUESTIONMARKSTAR();
        }
        case Quantifier::CARET:
        {
            return TokenBuilder::CARET();
        }
        case Quantifier::ATPLUS:
        {
            return TokenBuilder::ATPLUS();
        }
        case Quantifier::ATMINUS:
        {
            return TokenBuilder::ATMINUS();
        }
    }
}

InfixLogic::InfixLogic(
    const Logic::Ptr& lhs,
    const std::pair< const Token::Ptr&, const Connective > connective,
    const Logic::Ptr& rhs )
: Logic( Node::ID::INFIX_LOGIC )
, m_lhs( lhs )
, m_connectiveToken( connective.first )
, m_rhs( rhs )
, m_connective( connective.second )
{
}

InfixLogic::InfixLogic( const Logic::Ptr& lhs, const Connective connective, const Logic::Ptr& rhs )
: InfixLogic( lhs, std::make_pair( connectiveTokenFromConnective( connective ), connective ), rhs )
{
}

const Logic::Ptr& InfixLogic::lhs( void ) const
{
    return m_lhs;
}
const Token::Ptr& InfixLogic::connectiveToken( void ) const
{
    return m_connectiveToken;
}
const Logic::Ptr& InfixLogic::rhs( void ) const
{
    return m_rhs;
}

void InfixLogic::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& InfixLogic::connectiveTokenFromConnective( Connective connective ) const
{
    switch( connective )
    {
        case Connective::INEQUALITY:
        {
            return TokenBuilder::INFIXINEQUALITY();
        }
        case Connective::EQUALITY:
        {
            return TokenBuilder::EQUAL();
        }
    }
}

LogicTuple::LogicTuple(
    const Token::Ptr& leftBraceToken, const Logics::Ptr& tuples, const Token::Ptr& rightBraceToken )
: Logic( Node::ID::LOGIC_TUPLE )
, m_leftBraceToken( leftBraceToken )
, m_tuples( tuples )
, m_rightBraceToken( rightBraceToken )
{
}
LogicTuple::LogicTuple( const Token::Ptr& leftBraceToken, const Token::Ptr& rightBraceToken )
: LogicTuple( leftBraceToken, std::make_shared< Logics >(), rightBraceToken )
{
}

LogicTuple::LogicTuple( const Context& context, const Logics::Ptr& tuples )
: LogicTuple( bracesFromContext( context ).first, tuples, bracesFromContext( context ).second )
{
}

LogicTuple::LogicTuple( const Context& context )
: LogicTuple( bracesFromContext( context ).first, bracesFromContext( context ).second )
{
}

const Token::Ptr& LogicTuple::leftBraceToken( void ) const
{
    return m_leftBraceToken;
}
const Logics::Ptr& LogicTuple::tuples( void ) const
{
    return m_tuples;
}
const Token::Ptr& LogicTuple::rightBraceToken( void ) const
{
    return m_rightBraceToken;
}

void LogicTuple::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const std::pair< Token::Ptr, Token::Ptr > LogicTuple::bracesFromContext(
    const Context& context ) const
{
    if( context.flags().isSet( Context::FormulaFlag::FOF ) )
    {
        return std::make_pair( TokenBuilder::LCURPAREN(), TokenBuilder::RCURPAREN() );
    }
    return std::make_pair( TokenBuilder::LSQPAREN(), TokenBuilder::RSQPAREN() );
}
//
// SequentLogic
//

SequentLogic::SequentLogic(
    const LogicTuple::Ptr& left, const Token::Ptr& connectiveToken, const LogicTuple::Ptr& right )
: Logic( Node::ID::SEQUENT_LOGIC )
, m_left( left )
, m_connectiveToken( connectiveToken )
, m_right( right )
{
}

SequentLogic::SequentLogic( const LogicTuple::Ptr& left, const LogicTuple::Ptr& right )
: SequentLogic( left, TokenBuilder::GENTZENARROW(), right )
{
}

const LogicTuple::Ptr& SequentLogic::left( void ) const
{
    return m_left;
}

const LogicTuple::Ptr& SequentLogic::right( void ) const
{
    return m_right;
}

const Token::Ptr& SequentLogic::connectiveToken( void ) const
{
    return m_connectiveToken;  // gentzen arrow
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

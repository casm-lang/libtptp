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

#include "Formula.h"

#include "Logic.h"

using namespace libtptp;

//
// Formula
//

Formula::Formula( const ID id, const Logic::Ptr& logic )
: Node( id )
, m_logic( logic )
{
}

const Logic::Ptr& Formula::logic( void ) const
{
    return m_logic;
}

const libstdhl::Optional< Annotation::Ptr >& Formula::annotations( void ) const
{
    return m_annotations;
}

void Formula::setAnnotations( Annotation::Ptr& annotations )
{
    m_annotations = annotations;
}

u1 Formula::isFOF( void ) const
{
    return id() == Node::ID::FOF_FORMULA;
}

u1 Formula::isTFF( void ) const
{
    return id() == Node::ID::TFF_FORMULA;
}

//
// FirstOrderFormula
//

FirstOrderFormula::FirstOrderFormula( const Logic::Ptr& logic )
: Formula( Node::ID::FOF_FORMULA, logic )
{
}

void FirstOrderFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// TypedFirstOrderFormula
//

TypedFirstOrderFormula::TypedFirstOrderFormula( const Logic::Ptr& logic )
: Formula( Node::ID::TFF_FORMULA, logic )
{
}

void TypedFirstOrderFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

TypedHigherOrderFormula::TypedHigherOrderFormula( const Logic::Ptr& logic )
: Formula( Node::ID::THF_FORMULA, logic )
{
}

void TypedHigherOrderFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

TPTPProcessInstructionFormula::TPTPProcessInstructionFormula( const Logic::Ptr& logic )
: Formula( Node::ID::TPI_FORMULA, logic )
{
}

void TPTPProcessInstructionFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

ClauseNormalFormFormula::ClauseNormalFormFormula( const Logic::Ptr& logic )
: Formula( Node::ID::CNF_FORMULA, logic )
{
}

void ClauseNormalFormFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

TheoryComputableFunctionalsFormula::TheoryComputableFunctionalsFormula( const Logic::Ptr& logic )
: Formula( Node::ID::TCF_FORMULA, logic )
{
}

void TheoryComputableFunctionalsFormula::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

FormulaData::FormulaData(
    const Token::Ptr& dollar,
    const Token::Ptr& formulaType,
    const Token::Ptr& leftParen,
    const Logic::Ptr& formula,
    const Token::Ptr& rightParen )
: Formula( Node::ID::FORMULA_DATA, formula )
, m_dollar( dollar )
, m_formulaType( formulaType )
, m_leftParen( leftParen )
, m_rightParen( rightParen )
{
}

void FormulaData::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const Token::Ptr& FormulaData::dollar( void ) const
{
    return m_dollar;
}

const Token::Ptr& FormulaData::formulaType( void ) const
{
    return m_formulaType;
}

const Token::Ptr& FormulaData::leftParen( void ) const
{
    return m_leftParen;
}

const Token::Ptr& FormulaData::rightParen( void ) const
{
    return m_rightParen;
}

//
// FormulaRole
//

FormulaRole::FormulaRole( const StringLiteral::Ptr& word )
: Node( Node::ID::FORMULA_ROLE )
{
}

void FormulaRole::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const StringLiteral::Ptr& FormulaRole::word( void ) const
{
    return m_word;
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

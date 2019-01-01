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

#include "Term.h"

#include "Atom.h"

using namespace libtptp;

//
// Term
//

Term::Term( const ID id )
: Logic( id )
{
}

//
// FunctionTerm
//

FunctionTerm::FunctionTerm( const Atom::Ptr& atom )
: Term( Node::ID::FUNCTION_TERM )
, m_atom( atom )
{
}

const Atom::Ptr& FunctionTerm::atom( void ) const
{
    return m_atom;
}

void FunctionTerm::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// VariableTerm
//

VariableTerm::VariableTerm( const Identifier::Ptr& name )
: Term( Node::ID::VARIABLE_TERM )
, m_name( name )
{
}

const Identifier::Ptr& VariableTerm::name( void ) const
{
    return m_name;
}

void VariableTerm::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

//
// ConditionalTerm
//

ConditionalTerm::ConditionalTerm(
    const Logic::Ptr& condition, const Term::Ptr& left, const Term::Ptr& right )
: Term( Node::ID::CONDITIONAL_TERM )
, m_condition( condition )
, m_left( left )
, m_right( right )
{
}

const Logic::Ptr& ConditionalTerm::condition( void ) const
{
    return m_condition;
}

const Term::Ptr& ConditionalTerm::left( void ) const
{
    return m_left;
}

const Term::Ptr& ConditionalTerm::right( void ) const
{
    return m_right;
}

void ConditionalTerm::accept( Visitor& visitor )
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

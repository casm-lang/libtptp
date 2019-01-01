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

#include "Record.h"

using namespace libtptp;

//
// Record
//

Record::Record( const Identifier::Ptr& name, const Role role, const Formula::Ptr& formula )
: Node( Node::ID::RECORD )
, m_name( name )
, m_role( role )
, m_formula( formula )
{
}

const Identifier::Ptr& Record::name( void ) const
{
    return m_name;
}

const Role Record::role( void ) const
{
    return m_role;
}

std::string Record::roleDescription( void ) const
{
    switch( role() )
    {
        case Role::AXIOM:
        {
            return "axiom";
        }
        case Role::HYPOTHESIS:
        {
            return "hypothesis";
        }
        case Role::DEFINITION:
        {
            return "definition";
        }
        case Role::ASSUMPTION:
        {
            return "assumption";
        }
        case Role::LEMMA:
        {
            return "lemma";
        }
        case Role::THEOREM:
        {
            return "theorem";
        }
        case Role::CONJECTURE:
        {
            return "conjecture";
        }
        case Role::NEGATED_CONJECTURE:
        {
            return "negated_conjecture";
        }
        case Role::PLAIN:
        {
            return "plain";
        }
        case Role::TYPE:
        {
            return "type";
        }
        case Role::UNKNOWN:
        {
            return "unknown";
        }
    }
}

const Formula::Ptr& Record::formula( void ) const
{
    return m_formula;
}

void Record::accept( Visitor& visitor )
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

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
//

#include "Node.h"

#include "Record.h"

#include <cassert>

using namespace libtptp;

Node::Node( Node::ID id )
: m_id( id )
{
}

Node::ID Node::id( void ) const
{
    return m_id;
}

void Node::setSourceLocation( const SourceLocation& sourceLocation )
{
    m_sourceLocation = sourceLocation;
}

const SourceLocation& Node::sourceLocation( void ) const
{
    return m_sourceLocation;
}

std::string Node::description( void ) const
{
    switch( m_id )
    {
        // generic
        case ID::NODE_LIST:
        {
            return "node list";
        }
        case ID::IDENTIFIER:
        {
            return "identifier";
        }
        case ID::TRACE:
        {
            return "trace";
        }
        case ID::RECORD:
        {
            auto record = static_cast< const Record* >( this );
            if( record->formula()->isFOF() )
            {
                return "fof";
            }
            else if( record->formula()->isTFF() )
            {
                return "tff";
            }
            else
            {
                assert( not"invalid formula record found" );
            }
        }

        // formulae
        case ID::FOF_FORMULA:
        {
            return "fof_formula";
        }
        case ID::TFF_FORMULA:
        {
            return "tff_formula";
        }

        // logics
        case ID::UNITARY_LOGIC:
        {
            return "unitary logic";
        }
        case ID::UNARY_LOGIC:
        {
            return "unary logic";
        }
        case ID::BINARY_LOGIC:
        {
            return "binary logic";
        }
        case ID::QUANTIFIED_LOGIC:
        {
            return "quantified logic";
        }
        case ID::SEQUENT_LOGIC:
        {
            return "sequent logic";
        }

        // terms
        case ID::FUNCTION_TERM:
        {
            return "function term";
        }
        case ID::VARIABLE_TERM:
        {
            return "variable term";
        }
        case ID::CONDITIONAL_TERM:
        {
            return "conditional term";
        }

        // atoms
        case ID::FUNCTOR_ATOM:
        {
            return "functor atom";
        }

        // token
        case ID::TOKEN:
        {
            return "token";
        }
    }

    assert( !" internal error! " );
    return std::string();
}

Identifier::Identifier( const std::string& name )
: Node( Node::ID::IDENTIFIER )
, m_name( name )
{
}

const std::string& Identifier::name( void ) const
{
    return m_name;
}

void Identifier::accept( Visitor& visitor )
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

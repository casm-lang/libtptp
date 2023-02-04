//
//  Copyright (C) 2017-2023 CASM Organization <https://casm-lang.org>
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

#include "Node.h"

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

void Node::setSourceLocation( const libstdhl::SourceLocation& sourceLocation )
{
    m_sourceLocation = sourceLocation;
}

const libstdhl::SourceLocation& Node::sourceLocation( void ) const
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
        case ID::SPECIFICATION:
        {
            return "specification";
        }

        // definition
        case ID::INCLUDE_DEFINITION:
        {
            return "include";
        }
        case ID::FORMULA_DEFINITION:
        {
            return "formula definition";
        }
        // formulae
        case ID::FOF_FORMULA:
        {
            return "fof formula";
        }
        case ID::TFF_FORMULA:
        {
            return "tff formula";
        }
        case ID::THF_FORMULA:
        {
            return "thf formula";
        }
        case ID::TPI_FORMULA:
        {
            return "tpi formula";
        }
        case ID::CNF_FORMULA:
        {
            return "cnf formula";
        }
        case ID::TCF_FORMULA:
        {
            return "rcf formula";
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
        case ID::INFIX_LOGIC:
        {
            return "infix logic";
        }
        case ID::LOGIC_TUPLE:
        {
            return "logic tuple";
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
        case ID::DEFINITION_TERM:
        {
            return "definition term";
        }
        case ID::CONNECTIVE_ATOM:
        {
            return "connective atom";
        }

        // atoms
        case ID::FUNCTOR_ATOM:
        {
            return "functor atom";
        }
        case ID::CONSTANT_ATOM:
        {
            return "constant atom";
        }
        case ID::DEFINED_ATOM:
        {
            return "defined atom";
        }
        case ID::DEFINITION_ATOM:
        {
            return "definition atom";
        }
        case ID::TYPE_ATOM:
        {
            return "typed atom";
        }
        case ID::TUPLE_ATOM:
        {
            return "tuple atom";
        }

        // token
        case ID::TOKEN:
        {
            return "token";
        }
        case ID::LIST_ELEMENT:
        {
            return "list element";
        }

        // literals
        case ID::INTEGER_LITERAL:
        {
            return "integer literal";
        }
        case ID::RATIONAL_LITERAL:
        {
            return "rational literal";
        }
        case ID::REAL_LITERAL:
        {
            return "real literal";
        }
        case ID::DISTINCT_OBJECT_LITERAL:
        {
            return "distinct object literal";
        }
        case ID::LIST_LITERAL:
        {
            return "list literal";
        }

        case ID::FORMULA_ROLE:
        {
            return "formula role";
        }
        case ID::FORMULA_DATA:
        {
            return "formula data";
        }

        case ID::GENERAL_DATA:
        {
            return "general data";
        }
        case ID::GENERAL_LIST:
        {
            return "general list";
        }
        case ID::GENERAL_AGGREGATOR:
        {
            return "general aggregator";
        }
        case ID::GENERAL_FUNCTION:
        {
            return "general function";
        }
        case ID::ANNOTATION:
        {
            return "annotation";
        }
        case ID::APPLY_TYPE:
        {
            return "apply type";
        }
        case ID::NAMED_TYPE:
        {
            return "named type";
        }
        case ID::FUNCTOR_TYPE:
        {
            return "functor type";
        }
        case ID::SUB_TYPE:
        {
            return "sub type";
        }
        case ID::QUANTIFIED_TYPE:
        {
            return "quantified type";
        }
        case ID::TUPLE_TYPE:
        {
            return "tuple type";
        }
        case ID::BINARY_TYPE:
        {
            return "binary type";
        }
        case ID::RELATION_TYPE:
        {
            return "relation type";
        }
        case ID::VARIABLE_TYPE:
        {
            return "variable type";
        }
    }

    assert( !" internal error! " );
    return std::string();
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

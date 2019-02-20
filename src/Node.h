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

#ifndef _LIBTPTP_NODE_H_
#define _LIBTPTP_NODE_H_

#include <libstdhl/List>
#include <libtptp/SourceLocation>
#include <libtptp/Visitor>

namespace libtptp
{
    /**
       @extends TPTP
     */

    class Node : public std::enable_shared_from_this< Node >
    {
      public:
        enum class ID
        {
            // generic
            NODE_LIST,
            IDENTIFIER,
            TRACE,
            RECORD,
            // Definition
            INCLUDE_DEFINITION,
            FORMULA_DEFINITION,

            // formulae
            FOF_FORMULA,
            TFF_FORMULA,

            // logics
            UNITARY_LOGIC,
            UNARY_LOGIC,
            BINARY_LOGIC,
            QUANTIFIED_LOGIC,
            SEQUENT_LOGIC,
            INFIX_LOGIC,
            LOGIC_TUPLE,

            // terms
            FUNCTION_TERM,
            VARIABLE_TERM,
            CONDITIONAL_TERM,
            DEFINITION_TERM,
            CONNECTIVE_ATOM,

            // atoms
            FUNCTOR_ATOM,
            CONSTANT_ATOM,
            DEFINED_ATOM,
            DEFINITION_ATOM,

            // other
            TOKEN,

            // literals
            INTEGER_LITERAL,
            RATIONAL_LITERAL,
            REAL_LITERAL,
            STRING_LITERAL,
            LIST_LITERAL,

            FORMULA_ROLE,

            // general
            GENERAL_DATA,
            GENERAL_LIST,
            GENERAL_AGGREGATOR,
            GENERAL_FUNCTION,
            ANNOTATION,

            // types
            ATOM_TYPE,
            SUB_TYPE,
            QUANTIFIED_TYPE,
            TUPLE_TYPE,
            TYPED_ATOM,
            BINARY_TYPE,
        };

      public:
        using Ptr = std::shared_ptr< Node >;

        explicit Node( ID id );

        virtual ~Node() = default;

        ID id( void ) const;

        // void addAnnotation( const Annotation annotation );

        // Annotations annotations( void ) const;

        // void addComment( const Comment annotation );

        // Comments comments( void ) const;

        void setSourceLocation( const SourceLocation& sourceLocation );
        const SourceLocation& sourceLocation( void ) const;

        void setPrefix( const libstdhl::List< Node >& prefix );
        libstdhl::List< Node >& prefix( void );

        void setSuffix( const libstdhl::List< Node >& suffix );
        libstdhl::List< Node >& suffix( void );

        /**
           @return A short description about the node type.
         */
        virtual std::string description( void ) const final;

        template < typename T >
        typename T::Ptr ptr( void )
        {
            return std::static_pointer_cast< T >( shared_from_this() );
        }

        virtual void accept( Visitor& visitor ) = 0;

      private:
        const ID m_id;
        SourceLocation m_sourceLocation;
        libstdhl::List< Node > m_prefix;
        libstdhl::List< Node > m_suffix;
    };

    template < typename T >
    class NodeList final
    : public Node
    , public libstdhl::List< T >
    {
      public:
        using Ptr = std::shared_ptr< NodeList >;

        explicit NodeList( void )
        : Node( Node::ID::NODE_LIST )
        {
        }

        void accept( Visitor& visitor ) override final
        {
            for( auto& node : *this )
            {
                node->accept( visitor );
            }
        }
    };

    using Nodes = NodeList< Node >;

    template < typename T, typename... Args >
    typename T::Ptr make( const SourceLocation& sourceLocation, Args&&... args )
    {
        auto node = std::make_shared< T >( std::forward< Args >( args )... );
        node->setSourceLocation( sourceLocation );
        return node;
    }
}

#endif  // _LIBTPTP_NODE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

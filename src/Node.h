//
//  Copyright (c) 2017 CASM Organization
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                https://github.com/casm-lang/libtptp
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
            // records
            TFF_RECORD,
            FOF_RECORD,

            // formulae
            TFF_FORMULA,
            FOF_FORMULA,

            // expressions
            // TODO

            // other
            TRACE,
            NODE_LIST,
            IDENTIFIER,
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
    };

    template < typename T >
    class NodeList final : public Node, public libstdhl::List< T >
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

    class Identifier final : public Node
    {
      public:
        using Ptr = std::shared_ptr< Identifier >;

        explicit Identifier( const std::string& name );

        const std::string& name( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        std::string m_name;
    };

    using Identifiers = NodeList< Identifier >;
}

#endif // _LIBTPTP_NODE_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

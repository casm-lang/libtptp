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

#ifndef _LIBTPTP_HELPER_H_
#define _LIBTPTP_HELPER_H_

#include <functional>
#include <libtptp/Node>
#include <libtptp/Token>

namespace libtptp
{
    template < class T >
    class ListElement final : public Node
    {
      public:
        using Ptr = std::shared_ptr< ListElement< T > >;

        explicit ListElement( const Token::Ptr& delimiter, const typename T::Ptr& element )
        : Node( Node::ID::LIST_ELEMENT )
        , m_delimiter( delimiter )
        , m_element( element )
        {
        }

        const Token::Ptr& delimiter( void ) const
        {
            return m_delimiter;
        }

        const typename T::Ptr& element( void ) const
        {
            return m_element;
        }

        void accept( Visitor& visitor ) override final
        {
            delimiter()->accept( visitor );
            element()->accept( visitor );
        }

      private:
        const Token::Ptr m_delimiter;
        const typename T::Ptr m_element;
    };

    using builderFunction = const Token::Ptr&( void );
    template < class T, builderFunction delimiterConstructor = TokenBuilder::COMMA >
    class ListElements final : public NodeList< ListElement< T > >
    {
      public:
        using Ptr = std::shared_ptr< ListElements< T, delimiterConstructor > >;

        explicit ListElements( void )
        : NodeList< ListElement< T > >()
        {
        }

        ListElements( const std::initializer_list< typename T::Ptr > list )
        : NodeList< ListElement< T > >()
        {
            for( auto& el : list )
            {
                add( el );
            }
        }

        explicit ListElements( const std::initializer_list< typename ListElement< T >::Ptr > list )
        : NodeList< ListElement< T > >()
        {
            for( auto& el : list )
            {
                NodeList< ListElement< T > >::add( el );
            }
        }

        template < builderFunction U >
        ListElements( const ListElements< T, U >& other )
        : NodeList< ListElement< T > >( other )
        {
        }

        void add( const Token::Ptr& delimiter, const typename T::Ptr& element )
        {
            NodeList< ListElement< T > >::add(
                std::make_shared< ListElement< T > >( delimiter, element ) );
        }
        void add( const typename T::Ptr& element )
        {
            if( this->size() == 0 )
            {
                NodeList< ListElement< T > >::add(
                    std::make_shared< ListElement< T > >( TokenBuilder::UNRESOLVED(), element ) );
            }
            else
            {
                NodeList< ListElement< T > >::add(
                    std::make_shared< ListElement< T > >( delimiterConstructor(), element ) );
            }
        }

        template < builderFunction U >
        operator ListElements< T, U >( void ) const
        {
            return static_cast< ListElements< T, U > >( *this );
        }

        template < builderFunction U >
        operator const ListElements< T, U >( void ) const
        {
            return static_cast< const ListElements< T, U > >( *this );
        }
    };

    using ListNodeElements = ListElements< Node >;

}
#endif  // _LIBTPTP_HELPER_H_

//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

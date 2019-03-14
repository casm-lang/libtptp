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

#ifndef _LIBTPTP_GENERAL_H_
#define _LIBTPTP_GENERAL_H_

#include <libstdhl/Optional>
#include <libtptp/Identifier>
#include <libtptp/Literal>
#include <libtptp/Token>

namespace libtptp
{
    class GeneralTerm : public Node
    {
      public:
        using Ptr = std::shared_ptr< GeneralTerm >;

        explicit GeneralTerm( const Node::ID id );
    };

    using GeneralTerms = NodeList< GeneralTerm >;

    class GeneralData final : public GeneralTerm
    {
      public:
        using Ptr = std::shared_ptr< GeneralData >;

        explicit GeneralData( const Node::Ptr& data );

        const Node::Ptr& data( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Node::Ptr m_data;
    };

    using GeneralDatas = NodeList< GeneralData >;

    class GeneralList final : public GeneralTerm
    {
      public:
        using Ptr = std::shared_ptr< GeneralList >;

        explicit GeneralList( const ListLiteral::Ptr& list );

        const ListLiteral::Ptr& list( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const ListLiteral::Ptr m_list;
    };

    using GeneralLists = NodeList< GeneralList >;

    class GeneralAggregator final : public GeneralTerm
    {
      public:
        using Ptr = std::shared_ptr< GeneralAggregator >;

        explicit GeneralAggregator(
            const GeneralData::Ptr& data, const Token::Ptr& colon, const GeneralTerm::Ptr& term );

        const GeneralData::Ptr& data( void ) const;
        const Token::Ptr& colon( void ) const;
        const GeneralTerm::Ptr& term( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const GeneralData::Ptr m_data;
        const Token::Ptr m_colon;
        const GeneralTerm::Ptr m_term;
    };

    using GeneralAggregators = NodeList< GeneralAggregator >;

    class GeneralFunction final : public GeneralTerm
    {
      public:
        using Ptr = std::shared_ptr< GeneralFunction >;

        explicit GeneralFunction(
            const Identifier::Ptr& name,
            const Token::Ptr& leftParen,
            const Nodes::Ptr& arguments,
            const Token::Ptr& rightParen );

        const Identifier::Ptr& name( void ) const;
        const Token::Ptr& leftParen( void ) const;
        const Nodes::Ptr& arguments( void ) const;
        const Token::Ptr& rightParen( void ) const;

        void accept( Visitor& visitor ) override final;

      private:
        const Identifier::Ptr m_name;
        const Token::Ptr m_leftParen;
        const Nodes::Ptr m_arguments;
        const Token::Ptr m_rightParen;
    };

    using GeneralFunctions = NodeList< GeneralFunction >;

    class Annotation final : public Node
    {
      public:
        using Ptr = std::shared_ptr< Annotation >;

        explicit Annotation(
            const GeneralTerm::Ptr& source,
            const Token::Ptr& comma,
            const GeneralList::Ptr& usefulInfo );
        explicit Annotation( const GeneralTerm::Ptr& source );

        const GeneralTerm::Ptr& source( void ) const;
        const libstdhl::Optional< const GeneralList::Ptr >& usefulInfo( void ) const;
        const Token::Ptr& comma( void ) const;
        void setDelimiter( const Token::Ptr& delimiter );

        void accept( Visitor& visitor ) override final;

      private:
        Token::Ptr m_delimiter;
        const GeneralTerm::Ptr m_source;
        const Token::Ptr m_comma;
        libstdhl::Optional< const GeneralList::Ptr > m_usefulInfo;
    };

    using Annotations = NodeList< Annotation >;

}

#endif  // _LIBTPTP_GENERAL_H

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

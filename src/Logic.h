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

#ifndef _LIBTPTP_LOGIC_H_
#define _LIBTPTP_LOGIC_H_

#include <libtptp/Identifier>
#include <libtptp/Node>

/**
   @brief    TODO

   TODO
*/

namespace libtptp
{
    /**
       @extends TPTP
    */
    class Term;
    class Logic : public Node
    {
      public:
        using Ptr = std::shared_ptr< Logic >;

        Logic( const Node::ID id );
        const Token::Ptr& leftDelimiter( void ) const;
        const Token::Ptr& rightDelimiter( void ) const;

        void setLeftDelimiter( const Token::Ptr& leftDelimiter );
        void setRightDelimiter( const Token::Ptr& rightDelimiter );

      private:
        Token::Ptr m_leftDelimiter;
        Token::Ptr m_rightDelimiter;
    };

    using Logics = NodeList< Logic >;

    class UnitaryLogic final : public Logic
    {
      public:
        using Ptr = std::shared_ptr< UnitaryLogic >;

        UnitaryLogic( void );

        // private:

      public:
        void accept( Visitor& visitor ) override;
    };

    class UnaryLogic final : public Logic
    {
      public:
        enum class Connective
        {
            NEGATION,  //!< ~ (not)

            // TH1
            UNIVERSAL_QUANTIFICATION,    //!!
            EXISTENTIAL_QUANTIFICATION,  //??
            INDEFINITE_DESCRIPTION,      //@@+
            DEFINITE_DESCRIPTION,        //@@-
            EQUALITY,                    //@=
        };

        using Ptr = std::shared_ptr< UnaryLogic >;

        UnaryLogic(
            const std::pair< const Token::Ptr&, const Connective > connective,
            const Logic::Ptr& logic );

        const Logic::Ptr& logic( void ) const;

        const Connective connective( void ) const;

        const Token::Ptr& connectiveToken( void ) const;

        std::string connectiveDescription( void ) const;

      private:
        const Token::Ptr m_connectiveToken;
        const Logic::Ptr m_logic;
        const Connective m_connective;

      public:
        void accept( Visitor& visitor ) override;
    };

    class BinaryLogic final : public Logic
    {
      public:
        enum class Connective
        {
            DISJUNCTION,          //!< associative | (or)
            CONJUNCTION,          //!< associative & (and)
            EQUIVALENCE,          //!< non-associative <=>
            NON_EQUIVALENCE,      //!< non-associative <~> (xor)
            IMPLICATION,          //!< non-associative =>
            REVERSE_IMPLICATION,  //!< non-associative <=
            NEGATED_DISJUNCTION,  //!< non-associative ~| (nor)
            NEGATED_CONJUNCTION,  //!< non-associative ~& (nand)
            APPLY,                //!< associative @ (at)
        };

        using Ptr = std::shared_ptr< BinaryLogic >;

        BinaryLogic(
            const Logic::Ptr& left,
            const std::pair< const Token::Ptr&, Connective > connective,
            const Logic::Ptr& right );

        const Logic::Ptr& left( void ) const;

        const Logic::Ptr& right( void ) const;

        const Connective connective( void ) const;

        const Token::Ptr& connectiveToken( void ) const;

        std::string connectiveDescription( void ) const;

        u1 associative( void ) const;

      private:
        const Logic::Ptr m_left;
        const Logic::Ptr m_right;
        const Token::Ptr m_connectiveToken;
        const Connective m_connective;
        const u1 m_associative;

      public:
        void accept( Visitor& visitor ) override;
    };

    class QuantifiedLogic final : public Logic
    {
      public:
        enum class Quantifier
        {
            UNIVERSAL,    //!< !
            EXISTENTIAL,  //!< ?

            // TODO: change to useful names
            EXCLAMATIONGREATER,  // !>
            QUESTIONMARKSTAR,    // ?*
            CARET,               // ^
            ATPLUS,              // @+
            ATMINUS,             // @-
        };

        using Ptr = std::shared_ptr< QuantifiedLogic >;

        QuantifiedLogic(
            const std::pair< const Token::Ptr&, const Quantifier > quantifier,
            const ListLiteral::Ptr& variables,
            const Token::Ptr& colon,
            const Logic::Ptr& logic );

        const Token::Ptr& quantifierToken( void ) const;
        const ListLiteral::Ptr& variables( void ) const;
        const Token::Ptr& colon( void ) const;
        const Logic::Ptr& logic( void ) const;
        const Quantifier quantifier( void ) const;

        std::string quantifierDescription( void ) const;

      private:
        const Token::Ptr m_quantifierToken;
        const ListLiteral::Ptr m_variables;
        const Token::Ptr m_colon;
        const Logic::Ptr m_logic;
        const Quantifier m_quantifier;

      public:
        void accept( Visitor& visitor ) override;
    };

    class InfixLogic final : public Logic
    {
      public:
        enum class Connective
        {
            INEQUALITY,  // !=
            EQUALITY,    // =
        };
        using Ptr = std::shared_ptr< InfixLogic >;

        explicit InfixLogic(
            const Logic::Ptr& lhs,
            const std::pair< const Token::Ptr&, const Connective > connective,
            const Logic::Ptr& rhs );

        void accept( Visitor& visitor ) override final;

        const Logic::Ptr& lhs( void ) const;
        const Token::Ptr& connectiveToken( void ) const;
        const Logic::Ptr& rhs( void ) const;

      private:
        const Logic::Ptr m_lhs;
        const Token::Ptr m_connectiveToken;
        const Logic::Ptr m_rhs;
        const Connective m_connective;
    };

    using InfixLogics = NodeList< InfixLogic >;

    class LogicTuple final : public Logic
    {
      public:
        using Ptr = std::shared_ptr< LogicTuple >;

        explicit LogicTuple(
            const Token::Ptr& leftBraceToken,
            const Logics::Ptr& tuples,
            const Token::Ptr& rightBraceToken );
        explicit LogicTuple( const Token::Ptr& leftBraceToken, const Token::Ptr& rightBraceToken );

        void accept( Visitor& visitor ) override final;

        const Token::Ptr& leftBraceToken( void ) const;
        const Logics::Ptr& tuples( void ) const;
        const Token::Ptr& rightBraceToken( void ) const;

      private:
        const Token::Ptr m_leftBraceToken;
        const Logics::Ptr m_tuples;
        const Token::Ptr m_rightBraceToken;
    };

    using LogicTuples = NodeList< LogicTuple >;

    class SequentLogic final : public Logic
    {
      public:
        using Ptr = std::shared_ptr< SequentLogic >;

        SequentLogic(
            const LogicTuple::Ptr& left,
            const Token::Ptr& connectiveToken,
            const LogicTuple::Ptr& right );

        const LogicTuple::Ptr& left( void ) const;

        const LogicTuple::Ptr& right( void ) const;

        const Token::Ptr& connectiveToken( void ) const;

        std::string connectiveDescription( void ) const;

      private:
        const LogicTuple::Ptr m_left;
        const Token::Ptr m_connectiveToken;
        const LogicTuple::Ptr m_right;

      public:
        void accept( Visitor& visitor ) override;
    };

}

#endif  // _LIBTPTP_LOGIC_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

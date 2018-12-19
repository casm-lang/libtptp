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

#ifndef _LIBTPTP_VISITOR_H_
#define _LIBTPTP_VISITOR_H_

#include <libtptp/TPTP>

#include <functional>

namespace libtptp
{
    class Node;
    class Trace;
    class Record;

    class FirstOrderFormula;
    class TypedFirstOrderFormula;

    class UnaryLogic;
    class BinaryLogic;
    class QuantifiedLogic;
    class SequentLogic;

    class FunctionTerm;
    class VariableTerm;
    class ConditionalTerm;

    class FunctorAtom;

    class Identifier;

    class StringLiteral;
    class IntegerLiteral;

    enum Traversal : u8
    {
        PREORDER = 0,
        POSTORDER
    };

    /**
       @extends TPTP
    */
    class Visitor
    {
      public:
        virtual ~Visitor( void ) = default;

        virtual void visit( Trace& node ) = 0;
        virtual void visit( Record& node ) = 0;

        virtual void visit( FirstOrderFormula& node ) = 0;
        virtual void visit( TypedFirstOrderFormula& node ) = 0;

        virtual void visit( UnaryLogic& node ) = 0;
        virtual void visit( BinaryLogic& node ) = 0;
        virtual void visit( QuantifiedLogic& node ) = 0;
        virtual void visit( SequentLogic& node ) = 0;

        virtual void visit( FunctionTerm& node ) = 0;
        virtual void visit( VariableTerm& node ) = 0;
        virtual void visit( ConditionalTerm& node ) = 0;

        virtual void visit( FunctorAtom& node ) = 0;

        virtual void visit( Identifier& node ) = 0;

        virtual void visit( StringLiteral& node ) = 0;
        virtual void visit( IntegerLiteral& node ) = 0;
    };

    class RecursiveVisitor : public Visitor
    {
      public:
        void visit( Trace& node ) override;
        void visit( Record& node ) override;

        void visit( FirstOrderFormula& node ) override;
        void visit( TypedFirstOrderFormula& node ) override;

        void visit( UnaryLogic& node ) override;
        void visit( BinaryLogic& node ) override;
        void visit( QuantifiedLogic& node ) override;
        void visit( SequentLogic& node ) override;

        void visit( FunctionTerm& node ) override;
        void visit( VariableTerm& node ) override;
        void visit( ConditionalTerm& node ) override;

        void visit( FunctorAtom& node ) override;

        void visit( Identifier& node ) override;

        void visit( StringLiteral& node ) override;
        void visit( IntegerLiteral& node ) override;
    };

    class TraversalVisitor : public Visitor
    {
      public:
        TraversalVisitor( const Traversal order, std::function< void( Node& ) > callback );

        Traversal order( void ) const;

        std::function< void( Node& ) > callback( void ) const;

      private:
        Traversal m_order;

        std::function< void( Node& ) > m_callback;

      public:
        void visit( Trace& node ) override;
        void visit( Record& node ) override;

        void visit( FirstOrderFormula& node ) override;
        void visit( TypedFirstOrderFormula& node ) override;

        void visit( UnaryLogic& node ) override;
        void visit( BinaryLogic& node ) override;
        void visit( QuantifiedLogic& node ) override;
        void visit( SequentLogic& node ) override;

        void visit( FunctionTerm& node ) override;
        void visit( VariableTerm& node ) override;
        void visit( ConditionalTerm& node ) override;

        void visit( FunctorAtom& node ) override;

        void visit( Identifier& node ) override;

        void visit( StringLiteral& node ) override;
        void visit( IntegerLiteral& node ) override;
    };
}

#endif  // _LIBTPTP_VISITOR_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//

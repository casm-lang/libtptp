//
//  Copyright (C) 2017-2021 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Jakob Moosbrugger
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
    class Specification;

    class FirstOrderFormula;
    class TypedFirstOrderFormula;
    class TypedHigherOrderFormula;
    class TPTPProcessInstructionFormula;
    class ClauseNormalFormFormula;
    class TheoryComputableFunctionalsFormula;
    class FormulaData;

    class Role;

    class UnaryLogic;
    class BinaryLogic;
    class QuantifiedLogic;
    class InfixLogic;
    class LogicTuple;
    class SequentLogic;

    class VariableTerm;
    class ConditionalTerm;
    class DefinitionTerm;

    class FunctorAtom;
    class ConstantAtom;
    class DefinedAtom;
    class DefinitionAtom;
    class ConnectiveAtom;

    class AtomType;
    class BinaryType;
    class TypedAtom;
    class TupleType;
    class QuantifiedType;
    class SubType;

    class Identifier;

    class IntegerLiteral;
    class RationalLiteral;
    class RealLiteral;
    class DistinctObjectLiteral;
    class ListLiteral;

    class Token;

    class IncludeDefinition;
    class FormulaDefinition;

    class GeneralData;
    class GeneralList;
    class GeneralAggregator;
    class GeneralFunction;
    class Annotation;

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

        virtual void visit( Specification& node ) = 0;

        virtual void visit( FirstOrderFormula& node ) = 0;
        virtual void visit( TypedFirstOrderFormula& node ) = 0;
        virtual void visit( TypedHigherOrderFormula& node ) = 0;
        virtual void visit( TPTPProcessInstructionFormula& node ) = 0;
        virtual void visit( ClauseNormalFormFormula& node ) = 0;
        virtual void visit( TheoryComputableFunctionalsFormula& node ) = 0;
        virtual void visit( FormulaData& node ) = 0;

        virtual void visit( Role& node ) = 0;

        virtual void visit( UnaryLogic& node ) = 0;
        virtual void visit( BinaryLogic& node ) = 0;
        virtual void visit( QuantifiedLogic& node ) = 0;
        virtual void visit( InfixLogic& node ) = 0;
        virtual void visit( LogicTuple& node ) = 0;
        virtual void visit( SequentLogic& node ) = 0;

        virtual void visit( VariableTerm& node ) = 0;
        virtual void visit( ConditionalTerm& node ) = 0;
        virtual void visit( DefinitionTerm& node ) = 0;

        virtual void visit( FunctorAtom& node ) = 0;
        virtual void visit( ConstantAtom& node ) = 0;
        virtual void visit( DefinedAtom& node ) = 0;
        virtual void visit( DefinitionAtom& node ) = 0;
        virtual void visit( ConnectiveAtom& node ) = 0;

        virtual void visit( AtomType& node ) = 0;
        virtual void visit( BinaryType& node ) = 0;
        virtual void visit( TypedAtom& node ) = 0;
        virtual void visit( TupleType& node ) = 0;
        virtual void visit( QuantifiedType& node ) = 0;
        virtual void visit( SubType& node ) = 0;

        virtual void visit( Identifier& node ) = 0;

        virtual void visit( IntegerLiteral& node ) = 0;
        virtual void visit( RationalLiteral& node ) = 0;
        virtual void visit( RealLiteral& node ) = 0;
        virtual void visit( DistinctObjectLiteral& node ) = 0;
        virtual void visit( ListLiteral& node ) = 0;

        virtual void visit( Token& node ) = 0;

        virtual void visit( IncludeDefinition& node ) = 0;
        virtual void visit( FormulaDefinition& node ) = 0;

        virtual void visit( GeneralData& node ) = 0;
        virtual void visit( GeneralList& node ) = 0;
        virtual void visit( GeneralAggregator& node ) = 0;
        virtual void visit( GeneralFunction& node ) = 0;
        virtual void visit( Annotation& node ) = 0;
    };

    class RecursiveVisitor : public Visitor
    {
      public:
        void visit( Specification& node ) override;

        void visit( FirstOrderFormula& node ) override;
        void visit( TypedFirstOrderFormula& node ) override;
        void visit( TypedHigherOrderFormula& node ) override;
        void visit( TPTPProcessInstructionFormula& node ) override;
        void visit( ClauseNormalFormFormula& node ) override;
        void visit( TheoryComputableFunctionalsFormula& node ) override;
        void visit( FormulaData& node ) override;

        void visit( Role& node ) override;

        void visit( UnaryLogic& node ) override;
        void visit( BinaryLogic& node ) override;
        void visit( QuantifiedLogic& node ) override;
        void visit( InfixLogic& node ) override;
        void visit( LogicTuple& node ) override;
        void visit( SequentLogic& node ) override;

        void visit( VariableTerm& node ) override;
        void visit( ConditionalTerm& node ) override;
        void visit( DefinitionTerm& node ) override;

        void visit( FunctorAtom& node ) override;
        void visit( ConstantAtom& node ) override;
        void visit( DefinedAtom& node ) override;
        void visit( DefinitionAtom& node ) override;
        void visit( ConnectiveAtom& node ) override;

        void visit( AtomType& node ) override;
        void visit( BinaryType& node ) override;
        void visit( TypedAtom& node ) override;
        void visit( TupleType& node ) override;
        void visit( QuantifiedType& node ) override;
        void visit( SubType& node ) override;

        void visit( Identifier& node ) override;

        void visit( IntegerLiteral& node ) override;
        void visit( RationalLiteral& node ) override;
        void visit( RealLiteral& node ) override;
        void visit( DistinctObjectLiteral& node ) override;
        void visit( ListLiteral& node ) override;

        void visit( Token& node ) override;

        void visit( IncludeDefinition& node ) override;
        void visit( FormulaDefinition& node ) override;

        void visit( GeneralData& node ) override;
        void visit( GeneralList& node ) override;
        void visit( GeneralAggregator& node ) override;
        void visit( GeneralFunction& node ) override;
        void visit( Annotation& node ) override;
    };

    class TraversalVisitor : public RecursiveVisitor
    {
      public:
        TraversalVisitor( const Traversal order, std::function< void( Node& ) > callback );

        Traversal order( void ) const;

        std::function< void( Node& ) > callback( void ) const;

      private:
        Traversal m_order;

        std::function< void( Node& ) > m_callback;

        template < class T >
        void handle( T& node );

      public:
        void visit( Specification& node ) override;

        void visit( FirstOrderFormula& node ) override;
        void visit( TypedFirstOrderFormula& node ) override;
        void visit( TypedHigherOrderFormula& node ) override;
        void visit( TPTPProcessInstructionFormula& node ) override;
        void visit( ClauseNormalFormFormula& node ) override;
        void visit( TheoryComputableFunctionalsFormula& node ) override;
        void visit( FormulaData& node ) override;
        void visit( Role& node ) override;

        void visit( UnaryLogic& node ) override;
        void visit( BinaryLogic& node ) override;
        void visit( QuantifiedLogic& node ) override;
        void visit( InfixLogic& node ) override;
        void visit( LogicTuple& node ) override;
        void visit( SequentLogic& node ) override;

        void visit( VariableTerm& node ) override;
        void visit( ConditionalTerm& node ) override;
        void visit( DefinitionTerm& node ) override;

        void visit( FunctorAtom& node ) override;
        void visit( ConstantAtom& node ) override;
        void visit( DefinedAtom& node ) override;
        void visit( DefinitionAtom& node ) override;
        void visit( ConnectiveAtom& node ) override;

        void visit( AtomType& node ) override;
        void visit( BinaryType& node ) override;
        void visit( TypedAtom& node ) override;
        void visit( TupleType& node ) override;
        void visit( QuantifiedType& node ) override;
        void visit( SubType& node ) override;

        void visit( Identifier& node ) override;

        void visit( IntegerLiteral& node ) override;
        void visit( RationalLiteral& node ) override;
        void visit( RealLiteral& node ) override;
        void visit( DistinctObjectLiteral& node ) override;
        void visit( ListLiteral& node ) override;

        void visit( Token& node ) override;

        void visit( IncludeDefinition& node ) override;
        void visit( FormulaDefinition& node ) override;

        void visit( GeneralData& node ) override;
        void visit( GeneralList& node ) override;
        void visit( GeneralAggregator& node ) override;
        void visit( GeneralFunction& node ) override;
        void visit( Annotation& node ) override;
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

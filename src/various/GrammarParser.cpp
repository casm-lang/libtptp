// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "GrammarParser.tab.h"


// Unqualified %code blocks.
#line 91 "../../obj/src/GrammarParser.yy"

    #include "../../src/Lexer.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = TokenBuilder::UNRESOLVED();
    // static Lexer helper functions shall be located here 

#line 58 "GrammarParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 48 "../../obj/src/GrammarParser.yy"
namespace libtptp {
#line 151 "GrammarParser.cpp"

  /// Build a parser object.
  Parser::Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      m_log (m_log_yyarg),
      m_lexer (m_lexer_yyarg),
      m_specification (m_specification_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.YY_MOVE_OR_COPY< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.YY_MOVE_OR_COPY< ApplyType::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfLetTypes
      case 102: // ThfLetDefns
      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 146: // TfxLetTypes
      case 148: // TfxLetDefns
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.YY_MOVE_OR_COPY< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfBinaryNonassoc: // ThfBinaryNonassoc
      case symbol_kind::S_ThfBinaryAssoc: // ThfBinaryAssoc
      case symbol_kind::S_ThfOrFormula: // ThfOrFormula
      case symbol_kind::S_ThfAndFormula: // ThfAndFormula
      case symbol_kind::S_ThfApplyFormula: // ThfApplyFormula
      case symbol_kind::S_TffBinaryFormula: // TffBinaryFormula
      case symbol_kind::S_TffBinaryNonassoc: // TffBinaryNonassoc
      case symbol_kind::S_TffBinaryAssoc: // TffBinaryAssoc
      case symbol_kind::S_TffOrFormula: // TffOrFormula
      case symbol_kind::S_TffAndFormula: // TffAndFormula
      case symbol_kind::S_FofBinaryFormula: // FofBinaryFormula
      case symbol_kind::S_FofBinaryNonassoc: // FofBinaryNonassoc
      case symbol_kind::S_FofBinaryAssoc: // FofBinaryAssoc
      case symbol_kind::S_FofOrFormula: // FofOrFormula
      case symbol_kind::S_FofAndFormula: // FofAndFormula
        value.YY_MOVE_OR_COPY< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
=======
      case 115: // ThfMappingType
      case 117: // ThfUnionType
      case 163: // TffMappingType
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.YY_MOVE_OR_COPY< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.YY_MOVE_OR_COPY< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.YY_MOVE_OR_COPY< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.YY_MOVE_OR_COPY< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.YY_MOVE_OR_COPY< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definition: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.YY_MOVE_OR_COPY< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.YY_MOVE_OR_COPY< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.YY_MOVE_OR_COPY< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.YY_MOVE_OR_COPY< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.YY_MOVE_OR_COPY< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TypeConstant: // TypeConstant
      case symbol_kind::S_TypeFunctor: // TypeFunctor
      case symbol_kind::S_DefinedType: // DefinedType
      case symbol_kind::S_Atom: // Atom
      case symbol_kind::S_UntypedAtom: // UntypedAtom
      case symbol_kind::S_Constant: // Constant
      case symbol_kind::S_Functor: // Functor
      case symbol_kind::S_SystemConstant: // SystemConstant
      case symbol_kind::S_SystemFunctor: // SystemFunctor
      case symbol_kind::S_DefinedConstant: // DefinedConstant
      case symbol_kind::S_DefinedFunctor: // DefinedFunctor
      case symbol_kind::S_Name: // Name
      case symbol_kind::S_AtomicWord: // AtomicWord
      case symbol_kind::S_AtomicDefinedWord: // AtomicDefinedWord
      case symbol_kind::S_AtomicSystemWord: // AtomicSystemWord
      case symbol_kind::S_FileName: // FileName
      case symbol_kind::S_LowerWordLiteral: // LowerWordLiteral
      case symbol_kind::S_SingleQuotedLiteral: // SingleQuotedLiteral
      case symbol_kind::S_DollarWordLiteral: // DollarWordLiteral
      case symbol_kind::S_DollarDollarWordLiteral: // DollarDollarWordLiteral
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.YY_MOVE_OR_COPY< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.YY_MOVE_OR_COPY< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.YY_MOVE_OR_COPY< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.YY_MOVE_OR_COPY< ListTypeElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TpiFormula: // TpiFormula
      case symbol_kind::S_ThfFormula: // ThfFormula
      case symbol_kind::S_ThfLogicFormula: // ThfLogicFormula
      case symbol_kind::S_ThfBinaryFormula: // ThfBinaryFormula
      case symbol_kind::S_ThfUnitFormula: // ThfUnitFormula
      case symbol_kind::S_ThfPreunitFormula: // ThfPreunitFormula
      case symbol_kind::S_ThfUnitaryFormula: // ThfUnitaryFormula
      case symbol_kind::S_ThfUnaryFormula: // ThfUnaryFormula
      case symbol_kind::S_ThfAtomicFormula: // ThfAtomicFormula
      case symbol_kind::S_ThfPlainAtomic: // ThfPlainAtomic
      case symbol_kind::S_ThfLetDefns: // ThfLetDefns
      case symbol_kind::S_ThfUnitaryTerm: // ThfUnitaryTerm
      case symbol_kind::S_TffFormula: // TffFormula
      case symbol_kind::S_TffLogicFormula: // TffLogicFormula
      case symbol_kind::S_TffUnitFormula: // TffUnitFormula
      case symbol_kind::S_TffPreunitFormula: // TffPreunitFormula
      case symbol_kind::S_TffUnitaryFormula: // TffUnitaryFormula
      case symbol_kind::S_TffUnaryFormula: // TffUnaryFormula
      case symbol_kind::S_TfxLetDefns: // TfxLetDefns
      case symbol_kind::S_TfxLetLhs: // TfxLetLhs
      case symbol_kind::S_TffTerm: // TffTerm
      case symbol_kind::S_TffUnitaryTerm: // TffUnitaryTerm
      case symbol_kind::S_TcfFormula: // TcfFormula
      case symbol_kind::S_TcfLogicFormula: // TcfLogicFormula
      case symbol_kind::S_FofFormula: // FofFormula
      case symbol_kind::S_FofLogicFormula: // FofLogicFormula
      case symbol_kind::S_FofUnaryFormula: // FofUnaryFormula
      case symbol_kind::S_FofUnitFormula: // FofUnitFormula
      case symbol_kind::S_FofUnitaryFormula: // FofUnitaryFormula
      case symbol_kind::S_FofAtomicFormula: // FofAtomicFormula
      case symbol_kind::S_FofDefinedAtomicFormula: // FofDefinedAtomicFormula
      case symbol_kind::S_CnfFormula: // CnfFormula
      case symbol_kind::S_Disjunction: // Disjunction
      case symbol_kind::S_Literal: // Literal
=======
      case 101: // ThfAtomTypingList
      case 104: // ThfLetDefnList
      case 147: // TffAtomTypingList
      case 151: // TfxLetDefnList
        value.YY_MOVE_OR_COPY< ListAtomElements::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.YY_MOVE_OR_COPY< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.YY_MOVE_OR_COPY< ListTypeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.YY_MOVE_OR_COPY< ListVariableElements::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // TpiFormula
      case 75: // ThfFormula
      case 76: // ThfLogicFormula
      case 77: // ThfBinaryFormula
      case 83: // ThfUnitFormula
      case 84: // ThfPreunitFormula
      case 85: // ThfUnitaryFormula
      case 89: // ThfUnaryFormula
      case 92: // ThfAtomicFormula
      case 93: // ThfPlainAtomic
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 150: // TfxLetLhs
      case 152: // TffTerm
      case 153: // TffUnitaryTerm
      case 169: // TcfFormula
      case 170: // TcfLogicFormula
      case 172: // FofFormula
      case 173: // FofLogicFormula
      case 179: // FofUnaryFormula
      case 181: // FofUnitFormula
      case 182: // FofUnitaryFormula
      case 185: // FofAtomicFormula
      case 187: // FofDefinedAtomicFormula
      case 202: // CnfFormula
      case 203: // Disjunction
      case 204: // Literal
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.YY_MOVE_OR_COPY< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.YY_MOVE_OR_COPY< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.YY_MOVE_OR_COPY< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.YY_MOVE_OR_COPY< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.YY_MOVE_OR_COPY< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.YY_MOVE_OR_COPY< RelationType::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.YY_MOVE_OR_COPY< Role::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Specification: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.YY_MOVE_OR_COPY< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.YY_MOVE_OR_COPY< Term::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPI: // "tpi"
      case symbol_kind::S_THF: // "thf"
      case symbol_kind::S_TFF: // "tff"
      case symbol_kind::S_TCF: // "tcf"
      case symbol_kind::S_FOF: // "fof"
      case symbol_kind::S_CNF: // "cnf"
      case symbol_kind::S_FOT: // "fot"
      case symbol_kind::S_ITE: // "ite"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_AT: // "@"
      case symbol_kind::S_AND: // "&"
      case symbol_kind::S_DOLLAR: // "$"
      case symbol_kind::S_DOLLARDOLLAR: // "$$"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_INFIXINEQUALITY: // "!="
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LSQPAREN: // "["
      case symbol_kind::S_RSQPAREN: // "]"
      case symbol_kind::S_LCURPAREN: // "{"
      case symbol_kind::S_RCURPAREN: // "}"
      case symbol_kind::S_VLINE: // "|"
      case symbol_kind::S_STAR: // "*"
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_EXCLAMATION: // "!"
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_QUESTIONMARK: // "?"
      case symbol_kind::S_ATMINUS: // "@-"
      case symbol_kind::S_ATPLUS: // "@+"
      case symbol_kind::S_CARET: // "^"
      case symbol_kind::S_DOUBLEEXCLAMATION: // "!!"
      case symbol_kind::S_DOUBLEQUESTIONMARK: // "??"
      case symbol_kind::S_DOUBLEATPLUS: // "@@+"
      case symbol_kind::S_DOUBLEATMINUS: // "@@-"
      case symbol_kind::S_ATEQUAL: // "@="
      case symbol_kind::S_EXCLAMATIONGREATER: // "!>"
      case symbol_kind::S_QUESTIONMARKSTAR: // "?*"
      case symbol_kind::S_EQUALITY: // "<=>"
      case symbol_kind::S_IMPLICATION: // "=>"
      case symbol_kind::S_RIMPLICATION: // "<="
      case symbol_kind::S_INEQUALITY: // "<~>"
      case symbol_kind::S_NOR: // "~|"
      case symbol_kind::S_NAND: // "~&"
      case symbol_kind::S_ASSIGNMENT: // ":="
      case symbol_kind::S_GENTZENARROW: // "-->"
      case symbol_kind::S_SUBTYPESIGN: // "<<"
      case symbol_kind::S_INCLUDE: // "include"
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.YY_MOVE_OR_COPY< TupleType::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypedAtom::Ptr > (YY_MOVE (that.value));
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypeAtom::Ptr > (YY_MOVE (that.value));
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.YY_MOVE_OR_COPY< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.YY_MOVE_OR_COPY< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.YY_MOVE_OR_COPY< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.move< ApplyType::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfLetTypes
      case 102: // ThfLetDefns
      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 146: // TfxLetTypes
      case 148: // TfxLetDefns
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfBinaryNonassoc: // ThfBinaryNonassoc
      case symbol_kind::S_ThfBinaryAssoc: // ThfBinaryAssoc
      case symbol_kind::S_ThfOrFormula: // ThfOrFormula
      case symbol_kind::S_ThfAndFormula: // ThfAndFormula
      case symbol_kind::S_ThfApplyFormula: // ThfApplyFormula
      case symbol_kind::S_TffBinaryFormula: // TffBinaryFormula
      case symbol_kind::S_TffBinaryNonassoc: // TffBinaryNonassoc
      case symbol_kind::S_TffBinaryAssoc: // TffBinaryAssoc
      case symbol_kind::S_TffOrFormula: // TffOrFormula
      case symbol_kind::S_TffAndFormula: // TffAndFormula
      case symbol_kind::S_FofBinaryFormula: // FofBinaryFormula
      case symbol_kind::S_FofBinaryNonassoc: // FofBinaryNonassoc
      case symbol_kind::S_FofBinaryAssoc: // FofBinaryAssoc
      case symbol_kind::S_FofOrFormula: // FofOrFormula
      case symbol_kind::S_FofAndFormula: // FofAndFormula
        value.move< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
=======
      case 115: // ThfMappingType
      case 117: // ThfUnionType
      case 163: // TffMappingType
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definition: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.move< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TypeConstant: // TypeConstant
      case symbol_kind::S_TypeFunctor: // TypeFunctor
      case symbol_kind::S_DefinedType: // DefinedType
      case symbol_kind::S_Atom: // Atom
      case symbol_kind::S_UntypedAtom: // UntypedAtom
      case symbol_kind::S_Constant: // Constant
      case symbol_kind::S_Functor: // Functor
      case symbol_kind::S_SystemConstant: // SystemConstant
      case symbol_kind::S_SystemFunctor: // SystemFunctor
      case symbol_kind::S_DefinedConstant: // DefinedConstant
      case symbol_kind::S_DefinedFunctor: // DefinedFunctor
      case symbol_kind::S_Name: // Name
      case symbol_kind::S_AtomicWord: // AtomicWord
      case symbol_kind::S_AtomicDefinedWord: // AtomicDefinedWord
      case symbol_kind::S_AtomicSystemWord: // AtomicSystemWord
      case symbol_kind::S_FileName: // FileName
      case symbol_kind::S_LowerWordLiteral: // LowerWordLiteral
      case symbol_kind::S_SingleQuotedLiteral: // SingleQuotedLiteral
      case symbol_kind::S_DollarWordLiteral: // DollarWordLiteral
      case symbol_kind::S_DollarDollarWordLiteral: // DollarDollarWordLiteral
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.move< ListTypeElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TpiFormula: // TpiFormula
      case symbol_kind::S_ThfFormula: // ThfFormula
      case symbol_kind::S_ThfLogicFormula: // ThfLogicFormula
      case symbol_kind::S_ThfBinaryFormula: // ThfBinaryFormula
      case symbol_kind::S_ThfUnitFormula: // ThfUnitFormula
      case symbol_kind::S_ThfPreunitFormula: // ThfPreunitFormula
      case symbol_kind::S_ThfUnitaryFormula: // ThfUnitaryFormula
      case symbol_kind::S_ThfUnaryFormula: // ThfUnaryFormula
      case symbol_kind::S_ThfAtomicFormula: // ThfAtomicFormula
      case symbol_kind::S_ThfPlainAtomic: // ThfPlainAtomic
      case symbol_kind::S_ThfLetDefns: // ThfLetDefns
      case symbol_kind::S_ThfUnitaryTerm: // ThfUnitaryTerm
      case symbol_kind::S_TffFormula: // TffFormula
      case symbol_kind::S_TffLogicFormula: // TffLogicFormula
      case symbol_kind::S_TffUnitFormula: // TffUnitFormula
      case symbol_kind::S_TffPreunitFormula: // TffPreunitFormula
      case symbol_kind::S_TffUnitaryFormula: // TffUnitaryFormula
      case symbol_kind::S_TffUnaryFormula: // TffUnaryFormula
      case symbol_kind::S_TfxLetDefns: // TfxLetDefns
      case symbol_kind::S_TfxLetLhs: // TfxLetLhs
      case symbol_kind::S_TffTerm: // TffTerm
      case symbol_kind::S_TffUnitaryTerm: // TffUnitaryTerm
      case symbol_kind::S_TcfFormula: // TcfFormula
      case symbol_kind::S_TcfLogicFormula: // TcfLogicFormula
      case symbol_kind::S_FofFormula: // FofFormula
      case symbol_kind::S_FofLogicFormula: // FofLogicFormula
      case symbol_kind::S_FofUnaryFormula: // FofUnaryFormula
      case symbol_kind::S_FofUnitFormula: // FofUnitFormula
      case symbol_kind::S_FofUnitaryFormula: // FofUnitaryFormula
      case symbol_kind::S_FofAtomicFormula: // FofAtomicFormula
      case symbol_kind::S_FofDefinedAtomicFormula: // FofDefinedAtomicFormula
      case symbol_kind::S_CnfFormula: // CnfFormula
      case symbol_kind::S_Disjunction: // Disjunction
      case symbol_kind::S_Literal: // Literal
=======
      case 101: // ThfAtomTypingList
      case 104: // ThfLetDefnList
      case 147: // TffAtomTypingList
      case 151: // TfxLetDefnList
        value.move< ListAtomElements::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.move< ListVariableElements::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // TpiFormula
      case 75: // ThfFormula
      case 76: // ThfLogicFormula
      case 77: // ThfBinaryFormula
      case 83: // ThfUnitFormula
      case 84: // ThfPreunitFormula
      case 85: // ThfUnitaryFormula
      case 89: // ThfUnaryFormula
      case 92: // ThfAtomicFormula
      case 93: // ThfPlainAtomic
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 150: // TfxLetLhs
      case 152: // TffTerm
      case 153: // TffUnitaryTerm
      case 169: // TcfFormula
      case 170: // TcfLogicFormula
      case 172: // FofFormula
      case 173: // FofLogicFormula
      case 179: // FofUnaryFormula
      case 181: // FofUnitFormula
      case 182: // FofUnitaryFormula
      case 185: // FofAtomicFormula
      case 187: // FofDefinedAtomicFormula
      case 202: // CnfFormula
      case 203: // Disjunction
      case 204: // Literal
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.move< RelationType::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< Role::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Specification: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.move< Term::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPI: // "tpi"
      case symbol_kind::S_THF: // "thf"
      case symbol_kind::S_TFF: // "tff"
      case symbol_kind::S_TCF: // "tcf"
      case symbol_kind::S_FOF: // "fof"
      case symbol_kind::S_CNF: // "cnf"
      case symbol_kind::S_FOT: // "fot"
      case symbol_kind::S_ITE: // "ite"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_AT: // "@"
      case symbol_kind::S_AND: // "&"
      case symbol_kind::S_DOLLAR: // "$"
      case symbol_kind::S_DOLLARDOLLAR: // "$$"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_INFIXINEQUALITY: // "!="
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LSQPAREN: // "["
      case symbol_kind::S_RSQPAREN: // "]"
      case symbol_kind::S_LCURPAREN: // "{"
      case symbol_kind::S_RCURPAREN: // "}"
      case symbol_kind::S_VLINE: // "|"
      case symbol_kind::S_STAR: // "*"
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_EXCLAMATION: // "!"
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_QUESTIONMARK: // "?"
      case symbol_kind::S_ATMINUS: // "@-"
      case symbol_kind::S_ATPLUS: // "@+"
      case symbol_kind::S_CARET: // "^"
      case symbol_kind::S_DOUBLEEXCLAMATION: // "!!"
      case symbol_kind::S_DOUBLEQUESTIONMARK: // "??"
      case symbol_kind::S_DOUBLEATPLUS: // "@@+"
      case symbol_kind::S_DOUBLEATMINUS: // "@@-"
      case symbol_kind::S_ATEQUAL: // "@="
      case symbol_kind::S_EXCLAMATIONGREATER: // "!>"
      case symbol_kind::S_QUESTIONMARKSTAR: // "?*"
      case symbol_kind::S_EQUALITY: // "<=>"
      case symbol_kind::S_IMPLICATION: // "=>"
      case symbol_kind::S_RIMPLICATION: // "<="
      case symbol_kind::S_INEQUALITY: // "<~>"
      case symbol_kind::S_NOR: // "~|"
      case symbol_kind::S_NAND: // "~&"
      case symbol_kind::S_ASSIGNMENT: // ":="
      case symbol_kind::S_GENTZENARROW: // "-->"
      case symbol_kind::S_SUBTYPESIGN: // "<<"
      case symbol_kind::S_INCLUDE: // "include"
        value.move< Token::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (that.value));
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.move< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypeAtom::Ptr > (YY_MOVE (that.value));
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.copy< Annotation::Ptr > (that.value);
        break;

      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        value.copy< Atom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.copy< AtomType::Ptr > (that.value);
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
        value.copy< BinaryConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfBinaryNonassoc: // ThfBinaryNonassoc
      case symbol_kind::S_ThfBinaryAssoc: // ThfBinaryAssoc
      case symbol_kind::S_ThfOrFormula: // ThfOrFormula
      case symbol_kind::S_ThfAndFormula: // ThfAndFormula
      case symbol_kind::S_ThfApplyFormula: // ThfApplyFormula
      case symbol_kind::S_TffBinaryFormula: // TffBinaryFormula
      case symbol_kind::S_TffBinaryNonassoc: // TffBinaryNonassoc
      case symbol_kind::S_TffBinaryAssoc: // TffBinaryAssoc
      case symbol_kind::S_TffOrFormula: // TffOrFormula
      case symbol_kind::S_TffAndFormula: // TffAndFormula
      case symbol_kind::S_FofBinaryFormula: // FofBinaryFormula
      case symbol_kind::S_FofBinaryNonassoc: // FofBinaryNonassoc
      case symbol_kind::S_FofBinaryAssoc: // FofBinaryAssoc
      case symbol_kind::S_FofOrFormula: // FofOrFormula
      case symbol_kind::S_FofAndFormula: // FofAndFormula
        value.copy< BinaryLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
        value.copy< BinaryType::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.copy< ConditionalTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.copy< ConnectiveAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.copy< ConstantAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.copy< DefinedAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_Definition: // Definition
        value.copy< Definition::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.copy< DefinitionAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.copy< DefinitionTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.copy< Definitions::Ptr > (that.value);
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.copy< DistinctObjectLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.copy< FormulaData::Ptr > (that.value);
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.copy< FormulaDefinition::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.copy< FunctorAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.copy< GeneralData::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.copy< GeneralFunction::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.copy< GeneralList::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.copy< GeneralTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_TypeConstant: // TypeConstant
      case symbol_kind::S_TypeFunctor: // TypeFunctor
      case symbol_kind::S_DefinedType: // DefinedType
      case symbol_kind::S_Atom: // Atom
      case symbol_kind::S_UntypedAtom: // UntypedAtom
      case symbol_kind::S_Constant: // Constant
      case symbol_kind::S_Functor: // Functor
      case symbol_kind::S_SystemConstant: // SystemConstant
      case symbol_kind::S_SystemFunctor: // SystemFunctor
      case symbol_kind::S_DefinedConstant: // DefinedConstant
      case symbol_kind::S_DefinedFunctor: // DefinedFunctor
      case symbol_kind::S_Name: // Name
      case symbol_kind::S_AtomicWord: // AtomicWord
      case symbol_kind::S_AtomicDefinedWord: // AtomicDefinedWord
      case symbol_kind::S_AtomicSystemWord: // AtomicSystemWord
      case symbol_kind::S_FileName: // FileName
      case symbol_kind::S_LowerWordLiteral: // LowerWordLiteral
      case symbol_kind::S_SingleQuotedLiteral: // SingleQuotedLiteral
      case symbol_kind::S_DollarWordLiteral: // DollarWordLiteral
      case symbol_kind::S_DollarDollarWordLiteral: // DollarDollarWordLiteral
        value.copy< Identifier::Ptr > (that.value);
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.copy< IncludeDefinition::Ptr > (that.value);
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.copy< InfixConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.copy< InfixLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.copy< IntegerLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.copy< ListLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.copy< ListLogicElements::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.copy< ListNodeElements::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.copy< ListTypeElements::Ptr > (that.value);
        break;

      case symbol_kind::S_TpiFormula: // TpiFormula
      case symbol_kind::S_ThfFormula: // ThfFormula
      case symbol_kind::S_ThfLogicFormula: // ThfLogicFormula
      case symbol_kind::S_ThfBinaryFormula: // ThfBinaryFormula
      case symbol_kind::S_ThfUnitFormula: // ThfUnitFormula
      case symbol_kind::S_ThfPreunitFormula: // ThfPreunitFormula
      case symbol_kind::S_ThfUnitaryFormula: // ThfUnitaryFormula
      case symbol_kind::S_ThfUnaryFormula: // ThfUnaryFormula
      case symbol_kind::S_ThfAtomicFormula: // ThfAtomicFormula
      case symbol_kind::S_ThfPlainAtomic: // ThfPlainAtomic
      case symbol_kind::S_ThfLetDefns: // ThfLetDefns
      case symbol_kind::S_ThfUnitaryTerm: // ThfUnitaryTerm
      case symbol_kind::S_TffFormula: // TffFormula
      case symbol_kind::S_TffLogicFormula: // TffLogicFormula
      case symbol_kind::S_TffUnitFormula: // TffUnitFormula
      case symbol_kind::S_TffPreunitFormula: // TffPreunitFormula
      case symbol_kind::S_TffUnitaryFormula: // TffUnitaryFormula
      case symbol_kind::S_TffUnaryFormula: // TffUnaryFormula
      case symbol_kind::S_TfxLetDefns: // TfxLetDefns
      case symbol_kind::S_TfxLetLhs: // TfxLetLhs
      case symbol_kind::S_TffTerm: // TffTerm
      case symbol_kind::S_TffUnitaryTerm: // TffUnitaryTerm
      case symbol_kind::S_TcfFormula: // TcfFormula
      case symbol_kind::S_TcfLogicFormula: // TcfLogicFormula
      case symbol_kind::S_FofFormula: // FofFormula
      case symbol_kind::S_FofLogicFormula: // FofLogicFormula
      case symbol_kind::S_FofUnaryFormula: // FofUnaryFormula
      case symbol_kind::S_FofUnitFormula: // FofUnitFormula
      case symbol_kind::S_FofUnitaryFormula: // FofUnitaryFormula
      case symbol_kind::S_FofAtomicFormula: // FofAtomicFormula
      case symbol_kind::S_FofDefinedAtomicFormula: // FofDefinedAtomicFormula
      case symbol_kind::S_CnfFormula: // CnfFormula
      case symbol_kind::S_Disjunction: // Disjunction
      case symbol_kind::S_Literal: // Literal
        value.copy< Logic::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.copy< LogicTuple::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.copy< QuantifiedLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.copy< QuantifiedQuantifier_t > (that.value);
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.copy< QuantifiedType::Ptr > (that.value);
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.copy< RationalLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.copy< RealLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_FormulaRole: // FormulaRole
        value.copy< Role::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.copy< SequentLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_Specification: // Specification
        value.copy< Specification::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.copy< SubType::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.copy< Term::Ptr > (that.value);
        break;

      case symbol_kind::S_TPI: // "tpi"
      case symbol_kind::S_THF: // "thf"
      case symbol_kind::S_TFF: // "tff"
      case symbol_kind::S_TCF: // "tcf"
      case symbol_kind::S_FOF: // "fof"
      case symbol_kind::S_CNF: // "cnf"
      case symbol_kind::S_FOT: // "fot"
      case symbol_kind::S_ITE: // "ite"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_AT: // "@"
      case symbol_kind::S_AND: // "&"
      case symbol_kind::S_DOLLAR: // "$"
      case symbol_kind::S_DOLLARDOLLAR: // "$$"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_INFIXINEQUALITY: // "!="
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LSQPAREN: // "["
      case symbol_kind::S_RSQPAREN: // "]"
      case symbol_kind::S_LCURPAREN: // "{"
      case symbol_kind::S_RCURPAREN: // "}"
      case symbol_kind::S_VLINE: // "|"
      case symbol_kind::S_STAR: // "*"
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_EXCLAMATION: // "!"
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_QUESTIONMARK: // "?"
      case symbol_kind::S_ATMINUS: // "@-"
      case symbol_kind::S_ATPLUS: // "@+"
      case symbol_kind::S_CARET: // "^"
      case symbol_kind::S_DOUBLEEXCLAMATION: // "!!"
      case symbol_kind::S_DOUBLEQUESTIONMARK: // "??"
      case symbol_kind::S_DOUBLEATPLUS: // "@@+"
      case symbol_kind::S_DOUBLEATMINUS: // "@@-"
      case symbol_kind::S_ATEQUAL: // "@="
      case symbol_kind::S_EXCLAMATIONGREATER: // "!>"
      case symbol_kind::S_QUESTIONMARKSTAR: // "?*"
      case symbol_kind::S_EQUALITY: // "<=>"
      case symbol_kind::S_IMPLICATION: // "=>"
      case symbol_kind::S_RIMPLICATION: // "<="
      case symbol_kind::S_INEQUALITY: // "<~>"
      case symbol_kind::S_NOR: // "~|"
      case symbol_kind::S_NAND: // "~&"
      case symbol_kind::S_ASSIGNMENT: // ":="
      case symbol_kind::S_GENTZENARROW: // "-->"
      case symbol_kind::S_SUBTYPESIGN: // "<<"
      case symbol_kind::S_INCLUDE: // "include"
        value.copy< Token::Ptr > (that.value);
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.copy< TupleType::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.copy< Type::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.copy< TypedAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.copy< UnaryConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.copy< UnaryLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_Number: // Number
        value.copy< ValueLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.copy< VariableTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.move< Annotation::Ptr > (that.value);
        break;

<<<<<<< HEAD
      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        value.move< Atom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.move< AtomType::Ptr > (that.value);
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.move< ApplyType::Ptr > (that.value);
        break;

      case 100: // ThfLetTypes
      case 102: // ThfLetDefns
      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 146: // TfxLetTypes
      case 148: // TfxLetDefns
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (that.value);
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< BinaryConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfBinaryNonassoc: // ThfBinaryNonassoc
      case symbol_kind::S_ThfBinaryAssoc: // ThfBinaryAssoc
      case symbol_kind::S_ThfOrFormula: // ThfOrFormula
      case symbol_kind::S_ThfAndFormula: // ThfAndFormula
      case symbol_kind::S_ThfApplyFormula: // ThfApplyFormula
      case symbol_kind::S_TffBinaryFormula: // TffBinaryFormula
      case symbol_kind::S_TffBinaryNonassoc: // TffBinaryNonassoc
      case symbol_kind::S_TffBinaryAssoc: // TffBinaryAssoc
      case symbol_kind::S_TffOrFormula: // TffOrFormula
      case symbol_kind::S_TffAndFormula: // TffAndFormula
      case symbol_kind::S_FofBinaryFormula: // FofBinaryFormula
      case symbol_kind::S_FofBinaryNonassoc: // FofBinaryNonassoc
      case symbol_kind::S_FofBinaryAssoc: // FofBinaryAssoc
      case symbol_kind::S_FofOrFormula: // FofOrFormula
      case symbol_kind::S_FofAndFormula: // FofAndFormula
        value.move< BinaryLogic::Ptr > (that.value);
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
=======
      case 115: // ThfMappingType
      case 117: // ThfUnionType
      case 163: // TffMappingType
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< BinaryType::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.move< ConditionalTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.move< DefinedAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_Definition: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.move< DefinitionTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.move< FormulaData::Ptr > (that.value);
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.move< GeneralData::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.move< GeneralFunction::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.move< GeneralList::Ptr > (that.value);
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.move< GeneralTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_TypeConstant: // TypeConstant
      case symbol_kind::S_TypeFunctor: // TypeFunctor
      case symbol_kind::S_DefinedType: // DefinedType
      case symbol_kind::S_Atom: // Atom
      case symbol_kind::S_UntypedAtom: // UntypedAtom
      case symbol_kind::S_Constant: // Constant
      case symbol_kind::S_Functor: // Functor
      case symbol_kind::S_SystemConstant: // SystemConstant
      case symbol_kind::S_SystemFunctor: // SystemFunctor
      case symbol_kind::S_DefinedConstant: // DefinedConstant
      case symbol_kind::S_DefinedFunctor: // DefinedFunctor
      case symbol_kind::S_Name: // Name
      case symbol_kind::S_AtomicWord: // AtomicWord
      case symbol_kind::S_AtomicDefinedWord: // AtomicDefinedWord
      case symbol_kind::S_AtomicSystemWord: // AtomicSystemWord
      case symbol_kind::S_FileName: // FileName
      case symbol_kind::S_LowerWordLiteral: // LowerWordLiteral
      case symbol_kind::S_SingleQuotedLiteral: // SingleQuotedLiteral
      case symbol_kind::S_DollarWordLiteral: // DollarWordLiteral
      case symbol_kind::S_DollarDollarWordLiteral: // DollarDollarWordLiteral
        value.move< Identifier::Ptr > (that.value);
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (that.value);
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.move< InfixConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (that.value);
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.move< ListNodeElements::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.move< ListTypeElements::Ptr > (that.value);
        break;

      case symbol_kind::S_TpiFormula: // TpiFormula
      case symbol_kind::S_ThfFormula: // ThfFormula
      case symbol_kind::S_ThfLogicFormula: // ThfLogicFormula
      case symbol_kind::S_ThfBinaryFormula: // ThfBinaryFormula
      case symbol_kind::S_ThfUnitFormula: // ThfUnitFormula
      case symbol_kind::S_ThfPreunitFormula: // ThfPreunitFormula
      case symbol_kind::S_ThfUnitaryFormula: // ThfUnitaryFormula
      case symbol_kind::S_ThfUnaryFormula: // ThfUnaryFormula
      case symbol_kind::S_ThfAtomicFormula: // ThfAtomicFormula
      case symbol_kind::S_ThfPlainAtomic: // ThfPlainAtomic
      case symbol_kind::S_ThfLetDefns: // ThfLetDefns
      case symbol_kind::S_ThfUnitaryTerm: // ThfUnitaryTerm
      case symbol_kind::S_TffFormula: // TffFormula
      case symbol_kind::S_TffLogicFormula: // TffLogicFormula
      case symbol_kind::S_TffUnitFormula: // TffUnitFormula
      case symbol_kind::S_TffPreunitFormula: // TffPreunitFormula
      case symbol_kind::S_TffUnitaryFormula: // TffUnitaryFormula
      case symbol_kind::S_TffUnaryFormula: // TffUnaryFormula
      case symbol_kind::S_TfxLetDefns: // TfxLetDefns
      case symbol_kind::S_TfxLetLhs: // TfxLetLhs
      case symbol_kind::S_TffTerm: // TffTerm
      case symbol_kind::S_TffUnitaryTerm: // TffUnitaryTerm
      case symbol_kind::S_TcfFormula: // TcfFormula
      case symbol_kind::S_TcfLogicFormula: // TcfLogicFormula
      case symbol_kind::S_FofFormula: // FofFormula
      case symbol_kind::S_FofLogicFormula: // FofLogicFormula
      case symbol_kind::S_FofUnaryFormula: // FofUnaryFormula
      case symbol_kind::S_FofUnitFormula: // FofUnitFormula
      case symbol_kind::S_FofUnitaryFormula: // FofUnitaryFormula
      case symbol_kind::S_FofAtomicFormula: // FofAtomicFormula
      case symbol_kind::S_FofDefinedAtomicFormula: // FofDefinedAtomicFormula
      case symbol_kind::S_CnfFormula: // CnfFormula
      case symbol_kind::S_Disjunction: // Disjunction
      case symbol_kind::S_Literal: // Literal
=======
      case 101: // ThfAtomTypingList
      case 104: // ThfLetDefnList
      case 147: // TffAtomTypingList
      case 151: // TfxLetDefnList
        value.move< ListAtomElements::Ptr > (that.value);
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (that.value);
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (that.value);
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (that.value);
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.move< ListVariableElements::Ptr > (that.value);
        break;

      case 74: // TpiFormula
      case 75: // ThfFormula
      case 76: // ThfLogicFormula
      case 77: // ThfBinaryFormula
      case 83: // ThfUnitFormula
      case 84: // ThfPreunitFormula
      case 85: // ThfUnitaryFormula
      case 89: // ThfUnaryFormula
      case 92: // ThfAtomicFormula
      case 93: // ThfPlainAtomic
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 150: // TfxLetLhs
      case 152: // TffTerm
      case 153: // TffUnitaryTerm
      case 169: // TcfFormula
      case 170: // TcfLogicFormula
      case 172: // FofFormula
      case 173: // FofLogicFormula
      case 179: // FofUnaryFormula
      case 181: // FofUnitFormula
      case 182: // FofUnitaryFormula
      case 185: // FofAtomicFormula
      case 187: // FofDefinedAtomicFormula
      case 202: // CnfFormula
      case 203: // Disjunction
      case 204: // Literal
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< Logic::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (that.value);
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (that.value);
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.move< RationalLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.move< RealLiteral::Ptr > (that.value);
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.move< RelationType::Ptr > (that.value);
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< Role::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.move< SequentLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_Specification: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.move< SubType::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.move< Term::Ptr > (that.value);
        break;

      case symbol_kind::S_TPI: // "tpi"
      case symbol_kind::S_THF: // "thf"
      case symbol_kind::S_TFF: // "tff"
      case symbol_kind::S_TCF: // "tcf"
      case symbol_kind::S_FOF: // "fof"
      case symbol_kind::S_CNF: // "cnf"
      case symbol_kind::S_FOT: // "fot"
      case symbol_kind::S_ITE: // "ite"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_AT: // "@"
      case symbol_kind::S_AND: // "&"
      case symbol_kind::S_DOLLAR: // "$"
      case symbol_kind::S_DOLLARDOLLAR: // "$$"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_INFIXINEQUALITY: // "!="
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LSQPAREN: // "["
      case symbol_kind::S_RSQPAREN: // "]"
      case symbol_kind::S_LCURPAREN: // "{"
      case symbol_kind::S_RCURPAREN: // "}"
      case symbol_kind::S_VLINE: // "|"
      case symbol_kind::S_STAR: // "*"
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_EXCLAMATION: // "!"
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_QUESTIONMARK: // "?"
      case symbol_kind::S_ATMINUS: // "@-"
      case symbol_kind::S_ATPLUS: // "@+"
      case symbol_kind::S_CARET: // "^"
      case symbol_kind::S_DOUBLEEXCLAMATION: // "!!"
      case symbol_kind::S_DOUBLEQUESTIONMARK: // "??"
      case symbol_kind::S_DOUBLEATPLUS: // "@@+"
      case symbol_kind::S_DOUBLEATMINUS: // "@@-"
      case symbol_kind::S_ATEQUAL: // "@="
      case symbol_kind::S_EXCLAMATIONGREATER: // "!>"
      case symbol_kind::S_QUESTIONMARKSTAR: // "?*"
      case symbol_kind::S_EQUALITY: // "<=>"
      case symbol_kind::S_IMPLICATION: // "=>"
      case symbol_kind::S_RIMPLICATION: // "<="
      case symbol_kind::S_INEQUALITY: // "<~>"
      case symbol_kind::S_NOR: // "~|"
      case symbol_kind::S_NAND: // "~&"
      case symbol_kind::S_ASSIGNMENT: // ":="
      case symbol_kind::S_GENTZENARROW: // "-->"
      case symbol_kind::S_SUBTYPESIGN: // "<<"
      case symbol_kind::S_INCLUDE: // "include"
        value.move< Token::Ptr > (that.value);
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.move< TupleType::Ptr > (that.value);
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.move< Type::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.move< TypedAtom::Ptr > (that.value);
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.move< Type::Ptr > (that.value);
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypeAtom::Ptr > (that.value);
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.move< UnaryConnective_t > (that.value);
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (that.value);
        break;

      case symbol_kind::S_Number: // Number
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.move< VariableTerm::Ptr > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Annotations: // Annotations
        yylhs.value.emplace< Annotation::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        yylhs.value.emplace< Atom::Ptr > ();
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        yylhs.value.emplace< AtomType::Ptr > ();
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        yylhs.value.emplace< ApplyType::Ptr > ();
        break;

      case 100: // ThfLetTypes
      case 102: // ThfLetDefns
      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 146: // TfxLetTypes
      case 148: // TfxLetDefns
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        yylhs.value.emplace< Atom::Ptr > ();
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        yylhs.value.emplace< BinaryConnective_t > ();
        break;

      case symbol_kind::S_ThfBinaryNonassoc: // ThfBinaryNonassoc
      case symbol_kind::S_ThfBinaryAssoc: // ThfBinaryAssoc
      case symbol_kind::S_ThfOrFormula: // ThfOrFormula
      case symbol_kind::S_ThfAndFormula: // ThfAndFormula
      case symbol_kind::S_ThfApplyFormula: // ThfApplyFormula
      case symbol_kind::S_TffBinaryFormula: // TffBinaryFormula
      case symbol_kind::S_TffBinaryNonassoc: // TffBinaryNonassoc
      case symbol_kind::S_TffBinaryAssoc: // TffBinaryAssoc
      case symbol_kind::S_TffOrFormula: // TffOrFormula
      case symbol_kind::S_TffAndFormula: // TffAndFormula
      case symbol_kind::S_FofBinaryFormula: // FofBinaryFormula
      case symbol_kind::S_FofBinaryNonassoc: // FofBinaryNonassoc
      case symbol_kind::S_FofBinaryAssoc: // FofBinaryAssoc
      case symbol_kind::S_FofOrFormula: // FofOrFormula
      case symbol_kind::S_FofAndFormula: // FofAndFormula
        yylhs.value.emplace< BinaryLogic::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
=======
      case 115: // ThfMappingType
      case 117: // ThfUnionType
      case 163: // TffMappingType
>>>>>>> 508276a (GrammarParser: commmit built files)
        yylhs.value.emplace< BinaryType::Ptr > ();
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        yylhs.value.emplace< ConditionalTerm::Ptr > ();
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        yylhs.value.emplace< ConnectiveAtom::Ptr > ();
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        yylhs.value.emplace< ConstantAtom::Ptr > ();
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        yylhs.value.emplace< DefinedAtom::Ptr > ();
        break;

      case symbol_kind::S_Definition: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        yylhs.value.emplace< DefinitionAtom::Ptr > ();
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        yylhs.value.emplace< DefinitionTerm::Ptr > ();
        break;

      case symbol_kind::S_Definitions: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        yylhs.value.emplace< DistinctObjectLiteral::Ptr > ();
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        yylhs.value.emplace< FormulaData::Ptr > ();
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        yylhs.value.emplace< FunctorAtom::Ptr > ();
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        yylhs.value.emplace< GeneralData::Ptr > ();
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        yylhs.value.emplace< GeneralFunction::Ptr > ();
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        yylhs.value.emplace< GeneralList::Ptr > ();
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        yylhs.value.emplace< GeneralTerm::Ptr > ();
        break;

      case symbol_kind::S_TypeConstant: // TypeConstant
      case symbol_kind::S_TypeFunctor: // TypeFunctor
      case symbol_kind::S_DefinedType: // DefinedType
      case symbol_kind::S_Atom: // Atom
      case symbol_kind::S_UntypedAtom: // UntypedAtom
      case symbol_kind::S_Constant: // Constant
      case symbol_kind::S_Functor: // Functor
      case symbol_kind::S_SystemConstant: // SystemConstant
      case symbol_kind::S_SystemFunctor: // SystemFunctor
      case symbol_kind::S_DefinedConstant: // DefinedConstant
      case symbol_kind::S_DefinedFunctor: // DefinedFunctor
      case symbol_kind::S_Name: // Name
      case symbol_kind::S_AtomicWord: // AtomicWord
      case symbol_kind::S_AtomicDefinedWord: // AtomicDefinedWord
      case symbol_kind::S_AtomicSystemWord: // AtomicSystemWord
      case symbol_kind::S_FileName: // FileName
      case symbol_kind::S_LowerWordLiteral: // LowerWordLiteral
      case symbol_kind::S_SingleQuotedLiteral: // SingleQuotedLiteral
      case symbol_kind::S_DollarWordLiteral: // DollarWordLiteral
      case symbol_kind::S_DollarDollarWordLiteral: // DollarDollarWordLiteral
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        yylhs.value.emplace< IncludeDefinition::Ptr > ();
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        yylhs.value.emplace< InfixConnective_t > ();
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        yylhs.value.emplace< InfixLogic::Ptr > ();
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        yylhs.value.emplace< IntegerLiteral::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        yylhs.value.emplace< ListLogicElements::Ptr > ();
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        yylhs.value.emplace< ListNodeElements::Ptr > ();
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        yylhs.value.emplace< ListTypeElements::Ptr > ();
        break;

      case symbol_kind::S_TpiFormula: // TpiFormula
      case symbol_kind::S_ThfFormula: // ThfFormula
      case symbol_kind::S_ThfLogicFormula: // ThfLogicFormula
      case symbol_kind::S_ThfBinaryFormula: // ThfBinaryFormula
      case symbol_kind::S_ThfUnitFormula: // ThfUnitFormula
      case symbol_kind::S_ThfPreunitFormula: // ThfPreunitFormula
      case symbol_kind::S_ThfUnitaryFormula: // ThfUnitaryFormula
      case symbol_kind::S_ThfUnaryFormula: // ThfUnaryFormula
      case symbol_kind::S_ThfAtomicFormula: // ThfAtomicFormula
      case symbol_kind::S_ThfPlainAtomic: // ThfPlainAtomic
      case symbol_kind::S_ThfLetDefns: // ThfLetDefns
      case symbol_kind::S_ThfUnitaryTerm: // ThfUnitaryTerm
      case symbol_kind::S_TffFormula: // TffFormula
      case symbol_kind::S_TffLogicFormula: // TffLogicFormula
      case symbol_kind::S_TffUnitFormula: // TffUnitFormula
      case symbol_kind::S_TffPreunitFormula: // TffPreunitFormula
      case symbol_kind::S_TffUnitaryFormula: // TffUnitaryFormula
      case symbol_kind::S_TffUnaryFormula: // TffUnaryFormula
      case symbol_kind::S_TfxLetDefns: // TfxLetDefns
      case symbol_kind::S_TfxLetLhs: // TfxLetLhs
      case symbol_kind::S_TffTerm: // TffTerm
      case symbol_kind::S_TffUnitaryTerm: // TffUnitaryTerm
      case symbol_kind::S_TcfFormula: // TcfFormula
      case symbol_kind::S_TcfLogicFormula: // TcfLogicFormula
      case symbol_kind::S_FofFormula: // FofFormula
      case symbol_kind::S_FofLogicFormula: // FofLogicFormula
      case symbol_kind::S_FofUnaryFormula: // FofUnaryFormula
      case symbol_kind::S_FofUnitFormula: // FofUnitFormula
      case symbol_kind::S_FofUnitaryFormula: // FofUnitaryFormula
      case symbol_kind::S_FofAtomicFormula: // FofAtomicFormula
      case symbol_kind::S_FofDefinedAtomicFormula: // FofDefinedAtomicFormula
      case symbol_kind::S_CnfFormula: // CnfFormula
      case symbol_kind::S_Disjunction: // Disjunction
      case symbol_kind::S_Literal: // Literal
=======
      case 101: // ThfAtomTypingList
      case 104: // ThfLetDefnList
      case 147: // TffAtomTypingList
      case 151: // TfxLetDefnList
        yylhs.value.emplace< ListAtomElements::Ptr > ();
        break;

      case 239: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        yylhs.value.emplace< ListLogicElements::Ptr > ();
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        yylhs.value.emplace< ListNodeElements::Ptr > ();
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        yylhs.value.emplace< ListTypeElements::Ptr > ();
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        yylhs.value.emplace< ListVariableElements::Ptr > ();
        break;

      case 74: // TpiFormula
      case 75: // ThfFormula
      case 76: // ThfLogicFormula
      case 77: // ThfBinaryFormula
      case 83: // ThfUnitFormula
      case 84: // ThfPreunitFormula
      case 85: // ThfUnitaryFormula
      case 89: // ThfUnaryFormula
      case 92: // ThfAtomicFormula
      case 93: // ThfPlainAtomic
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 150: // TfxLetLhs
      case 152: // TffTerm
      case 153: // TffUnitaryTerm
      case 169: // TcfFormula
      case 170: // TcfLogicFormula
      case 172: // FofFormula
      case 173: // FofLogicFormula
      case 179: // FofUnaryFormula
      case 181: // FofUnitFormula
      case 182: // FofUnitaryFormula
      case 185: // FofAtomicFormula
      case 187: // FofDefinedAtomicFormula
      case 202: // CnfFormula
      case 203: // Disjunction
      case 204: // Literal
>>>>>>> 508276a (GrammarParser: commmit built files)
        yylhs.value.emplace< Logic::Ptr > ();
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        yylhs.value.emplace< LogicTuple::Ptr > ();
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        yylhs.value.emplace< QuantifiedLogic::Ptr > ();
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        yylhs.value.emplace< QuantifiedQuantifier_t > ();
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        yylhs.value.emplace< QuantifiedType::Ptr > ();
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        yylhs.value.emplace< RationalLiteral::Ptr > ();
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        yylhs.value.emplace< RealLiteral::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        yylhs.value.emplace< RelationType::Ptr > ();
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        yylhs.value.emplace< Role::Ptr > ();
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        yylhs.value.emplace< SequentLogic::Ptr > ();
        break;

      case symbol_kind::S_Specification: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        yylhs.value.emplace< SubType::Ptr > ();
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        yylhs.value.emplace< Term::Ptr > ();
        break;

      case symbol_kind::S_TPI: // "tpi"
      case symbol_kind::S_THF: // "thf"
      case symbol_kind::S_TFF: // "tff"
      case symbol_kind::S_TCF: // "tcf"
      case symbol_kind::S_FOF: // "fof"
      case symbol_kind::S_CNF: // "cnf"
      case symbol_kind::S_FOT: // "fot"
      case symbol_kind::S_ITE: // "ite"
      case symbol_kind::S_LET: // "let"
      case symbol_kind::S_AT: // "@"
      case symbol_kind::S_AND: // "&"
      case symbol_kind::S_DOLLAR: // "$"
      case symbol_kind::S_DOLLARDOLLAR: // "$$"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_INFIXINEQUALITY: // "!="
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LSQPAREN: // "["
      case symbol_kind::S_RSQPAREN: // "]"
      case symbol_kind::S_LCURPAREN: // "{"
      case symbol_kind::S_RCURPAREN: // "}"
      case symbol_kind::S_VLINE: // "|"
      case symbol_kind::S_STAR: // "*"
      case symbol_kind::S_GREATER: // ">"
      case symbol_kind::S_EXCLAMATION: // "!"
      case symbol_kind::S_TILDE: // "~"
      case symbol_kind::S_QUESTIONMARK: // "?"
      case symbol_kind::S_ATMINUS: // "@-"
      case symbol_kind::S_ATPLUS: // "@+"
      case symbol_kind::S_CARET: // "^"
      case symbol_kind::S_DOUBLEEXCLAMATION: // "!!"
      case symbol_kind::S_DOUBLEQUESTIONMARK: // "??"
      case symbol_kind::S_DOUBLEATPLUS: // "@@+"
      case symbol_kind::S_DOUBLEATMINUS: // "@@-"
      case symbol_kind::S_ATEQUAL: // "@="
      case symbol_kind::S_EXCLAMATIONGREATER: // "!>"
      case symbol_kind::S_QUESTIONMARKSTAR: // "?*"
      case symbol_kind::S_EQUALITY: // "<=>"
      case symbol_kind::S_IMPLICATION: // "=>"
      case symbol_kind::S_RIMPLICATION: // "<="
      case symbol_kind::S_INEQUALITY: // "<~>"
      case symbol_kind::S_NOR: // "~|"
      case symbol_kind::S_NAND: // "~&"
      case symbol_kind::S_ASSIGNMENT: // ":="
      case symbol_kind::S_GENTZENARROW: // "-->"
      case symbol_kind::S_SUBTYPESIGN: // "<<"
      case symbol_kind::S_INCLUDE: // "include"
        yylhs.value.emplace< Token::Ptr > ();
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        yylhs.value.emplace< TupleType::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        yylhs.value.emplace< Type::Ptr > ();
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        yylhs.value.emplace< TypedAtom::Ptr > ();
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        yylhs.value.emplace< Type::Ptr > ();
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        yylhs.value.emplace< TypeAtom::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        yylhs.value.emplace< UnaryConnective_t > ();
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        yylhs.value.emplace< UnaryLogic::Ptr > ();
        break;

      case symbol_kind::S_Number: // Number
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        yylhs.value.emplace< VariableTerm::Ptr > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
<<<<<<< HEAD
  case 2: // Specification: Definitions
#line 346 "../../obj/src/GrammarParser.yy"
  {
      m_specification.setDefinitions( yystack_[0].value.as < Definitions::Ptr > () );
  }
#line 2579 "GrammarParser.cpp"
    break;

  case 3: // Definitions: Definitions Definition
#line 353 "../../obj/src/GrammarParser.yy"
  {
=======
  case 2:
#line 349 "../../obj/src/GrammarParser.yy"
    {
      m_specification.setDefinitions( yystack_[0].value.as < Definitions::Ptr > () );
  }
#line 2224 "GrammarParser.cpp"
    break;

  case 3:
#line 356 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
    const auto definitions = yystack_[1].value.as < Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as < Definition::Ptr > ());
    yylhs.value.as < Definitions::Ptr > () = definitions;
  }
<<<<<<< HEAD
#line 2589 "GrammarParser.cpp"
    break;

  case 4: // Definitions: Definition
#line 359 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2234 "GrammarParser.cpp"
    break;

  case 4:
#line 362 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as < Definition::Ptr > () );
    yylhs.value.as < Definitions::Ptr > () = definitions;
  }
<<<<<<< HEAD
#line 2599 "GrammarParser.cpp"
    break;

  case 5: // Definition: AnnotatedFormula
#line 369 "../../obj/src/GrammarParser.yy"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2607 "GrammarParser.cpp"
    break;

  case 6: // Definition: IncludeDefinition
#line 373 "../../obj/src/GrammarParser.yy"
  {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < IncludeDefinition::Ptr > ();
  }
#line 2615 "GrammarParser.cpp"
    break;

  case 7: // AnnotatedFormula: ThfAnnotated
#line 380 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2623 "GrammarParser.cpp"
    break;

  case 8: // AnnotatedFormula: TffAnnotated
#line 384 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2631 "GrammarParser.cpp"
    break;

  case 9: // AnnotatedFormula: TcfAnnotated
#line 388 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2639 "GrammarParser.cpp"
    break;

  case 10: // AnnotatedFormula: FofAnnotated
#line 392 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2647 "GrammarParser.cpp"
    break;

  case 11: // AnnotatedFormula: CnfAnnotated
#line 396 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2655 "GrammarParser.cpp"
    break;

  case 12: // AnnotatedFormula: TpiAnnotated
#line 400 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2663 "GrammarParser.cpp"
    break;

  case 13: // ThfAnnotated: "thf" "(" Name "," FormulaRole "," ThfFormula ")" "."
#line 407 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2672 "GrammarParser.cpp"
    break;

  case 14: // ThfAnnotated: "thf" "(" Name "," FormulaRole "," ThfFormula "," Annotations ")" "."
#line 412 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2244 "GrammarParser.cpp"
    break;

  case 5:
#line 372 "../../obj/src/GrammarParser.yy"
    {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2252 "GrammarParser.cpp"
    break;

  case 6:
#line 376 "../../obj/src/GrammarParser.yy"
    {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < IncludeDefinition::Ptr > ();
  }
#line 2260 "GrammarParser.cpp"
    break;

  case 7:
#line 383 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2268 "GrammarParser.cpp"
    break;

  case 8:
#line 387 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2276 "GrammarParser.cpp"
    break;

  case 9:
#line 391 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2284 "GrammarParser.cpp"
    break;

  case 10:
#line 395 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2292 "GrammarParser.cpp"
    break;

  case 11:
#line 399 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2300 "GrammarParser.cpp"
    break;

  case 12:
#line 403 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2308 "GrammarParser.cpp"
    break;

  case 13:
#line 410 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2317 "GrammarParser.cpp"
    break;

  case 14:
#line 415 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2684 "GrammarParser.cpp"
    break;

  case 15: // TffAnnotated: "tff" "(" Name "," FormulaRole "," TffFormula ")" "."
#line 423 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2693 "GrammarParser.cpp"
    break;

  case 16: // TffAnnotated: "tff" "(" Name "," FormulaRole "," TffFormula "," Annotations ")" "."
#line 428 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2329 "GrammarParser.cpp"
    break;

  case 15:
#line 426 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2338 "GrammarParser.cpp"
    break;

  case 16:
#line 431 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2705 "GrammarParser.cpp"
    break;

  case 17: // TcfAnnotated: "tcf" "(" Name "," FormulaRole "," TcfFormula ")" "."
#line 439 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2714 "GrammarParser.cpp"
    break;

  case 18: // TcfAnnotated: "tcf" "(" Name "," FormulaRole "," TcfFormula "," Annotations ")" "."
#line 444 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2350 "GrammarParser.cpp"
    break;

  case 17:
#line 442 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2359 "GrammarParser.cpp"
    break;

  case 18:
#line 447 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2726 "GrammarParser.cpp"
    break;

  case 19: // FofAnnotated: "fof" "(" Name "," FormulaRole "," FofFormula ")" "."
#line 455 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2735 "GrammarParser.cpp"
    break;

  case 20: // FofAnnotated: "fof" "(" Name "," FormulaRole "," FofFormula "," Annotations ")" "."
#line 460 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2371 "GrammarParser.cpp"
    break;

  case 19:
#line 458 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2380 "GrammarParser.cpp"
    break;

  case 20:
#line 463 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2747 "GrammarParser.cpp"
    break;

  case 21: // CnfAnnotated: "cnf" "(" Name "," FormulaRole "," CnfFormula ")" "."
#line 471 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2756 "GrammarParser.cpp"
    break;

  case 22: // CnfAnnotated: "cnf" "(" Name "," FormulaRole "," CnfFormula "," Annotations ")" "."
#line 476 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2392 "GrammarParser.cpp"
    break;

  case 21:
#line 474 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2401 "GrammarParser.cpp"
    break;

  case 22:
#line 479 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2768 "GrammarParser.cpp"
    break;

  case 23: // TpiAnnotated: "tpi" "(" Name "," FormulaRole "," TpiFormula ")" "."
#line 487 "../../obj/src/GrammarParser.yy"
  {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2777 "GrammarParser.cpp"
    break;

  case 24: // TpiAnnotated: "tpi" "(" Name "," FormulaRole "," TpiFormula "," Annotations ")" "."
#line 492 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2413 "GrammarParser.cpp"
    break;

  case 23:
#line 490 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2422 "GrammarParser.cpp"
    break;

  case 24:
#line 495 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 2789 "GrammarParser.cpp"
    break;

  case 25: // Annotations: GeneralTerm
#line 503 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as < GeneralTerm::Ptr > ());
    //source
  }
#line 2798 "GrammarParser.cpp"
    break;

  case 26: // Annotations: GeneralTerm "," GeneralList
#line 508 "../../obj/src/GrammarParser.yy"
  {
    //source, optionalInfo
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as < GeneralTerm::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralList::Ptr > ());
  }
#line 2807 "GrammarParser.cpp"
    break;

  case 27: // TpiFormula: FofFormula
#line 516 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2815 "GrammarParser.cpp"
    break;

  case 28: // ThfFormula: ThfLogicFormula
#line 523 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2823 "GrammarParser.cpp"
    break;

  case 29: // ThfFormula: ThfAtomTyping
#line 527 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 2831 "GrammarParser.cpp"
    break;

  case 30: // ThfFormula: ThfSubtype
#line 531 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 2839 "GrammarParser.cpp"
    break;

  case 31: // ThfFormula: ThfSequent
#line 535 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 2847 "GrammarParser.cpp"
    break;

  case 32: // ThfLogicFormula: ThfUnitaryFormula
#line 542 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2855 "GrammarParser.cpp"
    break;

  case 33: // ThfLogicFormula: ThfUnaryFormula
#line 546 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2863 "GrammarParser.cpp"
    break;

  case 34: // ThfLogicFormula: ThfBinaryFormula
#line 550 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2871 "GrammarParser.cpp"
    break;

  case 35: // ThfLogicFormula: ThfDefinedInfix
#line 554 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2879 "GrammarParser.cpp"
    break;

  case 36: // ThfBinaryFormula: ThfBinaryNonassoc
#line 561 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2887 "GrammarParser.cpp"
    break;

  case 37: // ThfBinaryFormula: ThfBinaryAssoc
#line 565 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2895 "GrammarParser.cpp"
    break;

  case 38: // ThfBinaryFormula: ThfBinaryType
#line 569 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 2903 "GrammarParser.cpp"
    break;

  case 39: // ThfBinaryNonassoc: ThfUnitFormula NonassocConnective ThfUnitFormula
#line 576 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2911 "GrammarParser.cpp"
    break;

  case 40: // ThfBinaryAssoc: ThfOrFormula
#line 583 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2919 "GrammarParser.cpp"
    break;

  case 41: // ThfBinaryAssoc: ThfAndFormula
#line 587 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2927 "GrammarParser.cpp"
    break;

  case 42: // ThfBinaryAssoc: ThfApplyFormula
#line 591 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2935 "GrammarParser.cpp"
    break;

  case 43: // ThfOrFormula: ThfUnitFormula "|" ThfUnitFormula
#line 598 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2944 "GrammarParser.cpp"
    break;

  case 44: // ThfOrFormula: ThfOrFormula "|" ThfUnitFormula
#line 603 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2953 "GrammarParser.cpp"
    break;

  case 45: // ThfAndFormula: ThfUnitFormula "&" ThfUnitFormula
#line 611 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2962 "GrammarParser.cpp"
    break;

  case 46: // ThfAndFormula: ThfAndFormula "&" ThfUnitFormula
#line 616 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2971 "GrammarParser.cpp"
    break;

  case 47: // ThfApplyFormula: ThfUnitFormula "@" ThfUnitFormula
#line 624 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2980 "GrammarParser.cpp"
    break;

  case 48: // ThfApplyFormula: ThfApplyFormula "@" ThfUnitFormula
#line 629 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2989 "GrammarParser.cpp"
    break;

  case 49: // ThfUnitFormula: ThfUnitaryFormula
#line 637 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2997 "GrammarParser.cpp"
    break;

  case 50: // ThfUnitFormula: ThfUnaryFormula
#line 641 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3005 "GrammarParser.cpp"
    break;

  case 51: // ThfUnitFormula: ThfDefinedInfix
#line 645 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3013 "GrammarParser.cpp"
    break;

  case 52: // ThfPreunitFormula: ThfUnitaryFormula
#line 652 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3021 "GrammarParser.cpp"
    break;

  case 53: // ThfPreunitFormula: ThfPrefixUnary
#line 656 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3029 "GrammarParser.cpp"
    break;

  case 54: // ThfUnitaryFormula: ThfQuantifiedFormula
#line 663 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 3037 "GrammarParser.cpp"
    break;

  case 55: // ThfUnitaryFormula: ThfAtomicFormula
#line 667 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3045 "GrammarParser.cpp"
    break;

  case 56: // ThfUnitaryFormula: Variable
#line 671 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3053 "GrammarParser.cpp"
    break;

  case 57: // ThfUnitaryFormula: "(" ThfLogicFormula ")"
#line 675 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2434 "GrammarParser.cpp"
    break;

  case 25:
#line 506 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as < GeneralTerm::Ptr > ());
    //source
  }
#line 2443 "GrammarParser.cpp"
    break;

  case 26:
#line 511 "../../obj/src/GrammarParser.yy"
    {
    //source, optionalInfo
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as < GeneralTerm::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralList::Ptr > ());
  }
#line 2452 "GrammarParser.cpp"
    break;

  case 27:
#line 519 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2460 "GrammarParser.cpp"
    break;

  case 28:
#line 526 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2468 "GrammarParser.cpp"
    break;

  case 29:
#line 530 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypeAtom::Ptr > ();
  }
#line 2476 "GrammarParser.cpp"
    break;

  case 30:
#line 534 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 2484 "GrammarParser.cpp"
    break;

  case 31:
#line 538 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 2492 "GrammarParser.cpp"
    break;

  case 32:
#line 545 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2500 "GrammarParser.cpp"
    break;

  case 33:
#line 549 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2508 "GrammarParser.cpp"
    break;

  case 34:
#line 553 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2516 "GrammarParser.cpp"
    break;

  case 35:
#line 557 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2524 "GrammarParser.cpp"
    break;

  case 36:
#line 564 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2532 "GrammarParser.cpp"
    break;

  case 37:
#line 568 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2540 "GrammarParser.cpp"
    break;

  case 38:
#line 572 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Type::Ptr > ();
  }
#line 2548 "GrammarParser.cpp"
    break;

  case 39:
#line 579 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2556 "GrammarParser.cpp"
    break;

  case 40:
#line 586 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2564 "GrammarParser.cpp"
    break;

  case 41:
#line 590 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2572 "GrammarParser.cpp"
    break;

  case 42:
#line 594 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2580 "GrammarParser.cpp"
    break;

  case 43:
#line 601 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2589 "GrammarParser.cpp"
    break;

  case 44:
#line 606 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2598 "GrammarParser.cpp"
    break;

  case 45:
#line 614 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2607 "GrammarParser.cpp"
    break;

  case 46:
#line 619 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2616 "GrammarParser.cpp"
    break;

  case 47:
#line 627 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2625 "GrammarParser.cpp"
    break;

  case 48:
#line 632 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2634 "GrammarParser.cpp"
    break;

  case 49:
#line 640 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2642 "GrammarParser.cpp"
    break;

  case 50:
#line 644 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2650 "GrammarParser.cpp"
    break;

  case 51:
#line 648 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2658 "GrammarParser.cpp"
    break;

  case 52:
#line 655 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2666 "GrammarParser.cpp"
    break;

  case 53:
#line 659 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 2674 "GrammarParser.cpp"
    break;

  case 54:
#line 666 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 2682 "GrammarParser.cpp"
    break;

  case 55:
#line 670 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2690 "GrammarParser.cpp"
    break;

  case 56:
#line 674 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 2698 "GrammarParser.cpp"
    break;

  case 57:
#line 678 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 3064 "GrammarParser.cpp"
    break;

  case 58: // ThfQuantifiedFormula: ThfQuantifier "[" ThfVariableList "]" ":" ThfUnitFormula
#line 685 "../../obj/src/GrammarParser.yy"
  {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), variables, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3073 "GrammarParser.cpp"
    break;

  case 59: // ThfVariableList: ThfTypedVariable
#line 693 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
=======
#line 2709 "GrammarParser.cpp"
    break;

  case 58:
#line 688 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListVariableElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2717 "GrammarParser.cpp"
    break;

  case 59:
#line 695 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListVariableElements >(yylhs.location);
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3083 "GrammarParser.cpp"
    break;

  case 60: // ThfVariableList: ThfVariableList "," ThfTypedVariable
#line 699 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
=======
#line 2727 "GrammarParser.cpp"
    break;

  case 60:
#line 701 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListVariableElements::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3093 "GrammarParser.cpp"
    break;

  case 61: // ThfTypedVariable: Variable ":" ThfTopLevelType
#line 708 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2737 "GrammarParser.cpp"
    break;

  case 61:
#line 710 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto var = yystack_[2].value.as < VariableTerm::Ptr > ();
	var->setColon(yystack_[1].value.as < Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as < Type::Ptr > ();
	var->setType(type);
  }
<<<<<<< HEAD
#line 3104 "GrammarParser.cpp"
    break;

  case 62: // ThfUnaryFormula: ThfPrefixUnary
#line 718 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3112 "GrammarParser.cpp"
    break;

  case 63: // ThfUnaryFormula: ThfInfixUnary
#line 722 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3120 "GrammarParser.cpp"
    break;

  case 64: // ThfPrefixUnary: ThfUnaryConnective ThfPreunitFormula
#line 729 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3128 "GrammarParser.cpp"
    break;

  case 65: // ThfInfixUnary: ThfUnitaryTerm InfixInequality ThfUnitaryTerm
#line 736 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3136 "GrammarParser.cpp"
    break;

  case 66: // ThfAtomicFormula: ThfPlainAtomic
#line 743 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3144 "GrammarParser.cpp"
    break;

  case 67: // ThfAtomicFormula: ThfDefinedAtomic
#line 747 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3152 "GrammarParser.cpp"
    break;

  case 68: // ThfAtomicFormula: ThfSystemAtomic
#line 751 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < ConstantAtom::Ptr > ();
  }
#line 3160 "GrammarParser.cpp"
    break;

  case 69: // ThfAtomicFormula: ThfFofFunction
#line 755 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < FunctorAtom::Ptr > ();
  }
#line 3168 "GrammarParser.cpp"
    break;

  case 70: // ThfPlainAtomic: Constant
#line 762 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3176 "GrammarParser.cpp"
    break;

  case 71: // ThfPlainAtomic: ThfTuple
#line 766 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3184 "GrammarParser.cpp"
    break;

  case 72: // ThfDefinedAtomic: DefinedConstant
#line 773 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3192 "GrammarParser.cpp"
    break;

  case 73: // ThfDefinedAtomic: ThfConditional
#line 777 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 3200 "GrammarParser.cpp"
    break;

  case 74: // ThfDefinedAtomic: ThfLet
#line 781 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 3208 "GrammarParser.cpp"
    break;

  case 75: // ThfDefinedAtomic: "(" ThfConnTerm ")"
#line 785 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2748 "GrammarParser.cpp"
    break;

  case 62:
#line 720 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 2756 "GrammarParser.cpp"
    break;

  case 63:
#line 724 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2764 "GrammarParser.cpp"
    break;

  case 64:
#line 731 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2772 "GrammarParser.cpp"
    break;

  case 65:
#line 738 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2780 "GrammarParser.cpp"
    break;

  case 66:
#line 745 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2788 "GrammarParser.cpp"
    break;

  case 67:
#line 749 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 2796 "GrammarParser.cpp"
    break;

  case 68:
#line 753 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < ConstantAtom::Ptr > ();
  }
#line 2804 "GrammarParser.cpp"
    break;

  case 69:
#line 757 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < FunctorAtom::Ptr > ();
  }
#line 2812 "GrammarParser.cpp"
    break;

  case 70:
#line 764 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2820 "GrammarParser.cpp"
    break;

  case 71:
#line 768 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 2828 "GrammarParser.cpp"
    break;

  case 72:
#line 775 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2836 "GrammarParser.cpp"
    break;

  case 73:
#line 779 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 2844 "GrammarParser.cpp"
    break;

  case 74:
#line 783 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 2852 "GrammarParser.cpp"
    break;

  case 75:
#line 787 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < ConnectiveAtom::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Term::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 3219 "GrammarParser.cpp"
    break;

  case 76: // ThfDefinedAtomic: DefinedTerm
#line 792 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 3227 "GrammarParser.cpp"
    break;

  case 77: // ThfDefinedInfix: ThfUnitaryTerm DefinedInfixPred ThfUnitaryTerm
#line 799 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3235 "GrammarParser.cpp"
    break;

  case 78: // ThfSystemAtomic: SystemConstant
#line 806 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < ConstantAtom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3243 "GrammarParser.cpp"
    break;

  case 79: // ThfFofFunction: Functor "(" ThfArguments ")"
#line 813 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3251 "GrammarParser.cpp"
    break;

  case 80: // ThfFofFunction: DefinedFunctor "(" ThfArguments ")"
#line 817 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3259 "GrammarParser.cpp"
    break;

  case 81: // ThfFofFunction: SystemFunctor "(" ThfArguments ")"
#line 821 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3267 "GrammarParser.cpp"
    break;

  case 82: // ThfConditional: "$" "ite" "(" ThfLogicFormula "," ThfLogicFormula "," ThfLogicFormula ")"
#line 828 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3275 "GrammarParser.cpp"
    break;

  case 83: // ThfLet: "$" "let" "(" ThfLetTypes "," ThfLetDefns "," ThfFormula ")"
#line 835 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Type::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3283 "GrammarParser.cpp"
    break;

  case 84: // ThfLetTypes: ThfAtomTyping
#line 842 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 3291 "GrammarParser.cpp"
    break;

  case 85: // ThfLetTypes: "[" ThfAtomTypingList "]"
#line 846 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3299 "GrammarParser.cpp"
    break;

  case 86: // ThfAtomTypingList: ThfAtomTyping
#line 853 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 3309 "GrammarParser.cpp"
    break;

  case 87: // ThfAtomTypingList: ThfAtomTypingList "," ThfAtomTyping
#line 859 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 3319 "GrammarParser.cpp"
    break;

  case 88: // ThfLetDefns: ThfLetDefn
#line 868 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 3327 "GrammarParser.cpp"
    break;

  case 89: // ThfLetDefns: "[" ThfLetDefnList "]"
#line 872 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3335 "GrammarParser.cpp"
    break;

  case 90: // ThfLetDefn: ThfLogicFormula ":=" ThfLogicFormula
#line 879 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3343 "GrammarParser.cpp"
    break;

  case 91: // ThfLetDefnList: ThfLetDefn
#line 886 "../../obj/src/GrammarParser.yy"
  {
=======
#line 2863 "GrammarParser.cpp"
    break;

  case 76:
#line 794 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 2871 "GrammarParser.cpp"
    break;

  case 77:
#line 801 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2879 "GrammarParser.cpp"
    break;

  case 78:
#line 808 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConstantAtom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2887 "GrammarParser.cpp"
    break;

  case 79:
#line 815 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2895 "GrammarParser.cpp"
    break;

  case 80:
#line 819 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2903 "GrammarParser.cpp"
    break;

  case 81:
#line 823 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2911 "GrammarParser.cpp"
    break;

  case 82:
#line 830 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2919 "GrammarParser.cpp"
    break;

  case 83:
#line 837 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Atom::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Atom::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2927 "GrammarParser.cpp"
    break;

  case 84:
#line 844 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < TypeAtom::Ptr > ();
  }
#line 2935 "GrammarParser.cpp"
    break;

  case 85:
#line 848 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< TupleAtom >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListAtomElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2943 "GrammarParser.cpp"
    break;

  case 86:
#line 855 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListAtomElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypeAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
#line 2953 "GrammarParser.cpp"
    break;

  case 87:
#line 861 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListAtomElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypeAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
#line 2963 "GrammarParser.cpp"
    break;

  case 88:
#line 870 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 2971 "GrammarParser.cpp"
    break;

  case 89:
#line 874 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< TupleAtom >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListAtomElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2979 "GrammarParser.cpp"
    break;

  case 90:
#line 881 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2987 "GrammarParser.cpp"
    break;

  case 91:
#line 888 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	//could be of type DefinitionAtoms, but Logics is expected
	auto list = libtptp::make< ListAtomElements >(yylhs.location);
	list->add(yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3354 "GrammarParser.cpp"
    break;

  case 92: // ThfLetDefnList: ThfLetDefnList "," ThfLetDefn
#line 893 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
=======
#line 2998 "GrammarParser.cpp"
    break;

  case 92:
#line 895 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListAtomElements::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3364 "GrammarParser.cpp"
    break;

  case 93: // ThfUnitaryTerm: ThfAtomicFormula
#line 902 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3372 "GrammarParser.cpp"
    break;

  case 94: // ThfUnitaryTerm: Variable
#line 906 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3380 "GrammarParser.cpp"
    break;

  case 95: // ThfUnitaryTerm: "(" ThfLogicFormula ")"
#line 910 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3008 "GrammarParser.cpp"
    break;

  case 93:
#line 904 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3016 "GrammarParser.cpp"
    break;

  case 94:
#line 908 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3024 "GrammarParser.cpp"
    break;

  case 95:
#line 912 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 3391 "GrammarParser.cpp"
    break;

  case 96: // ThfTuple: "[" "]"
#line 920 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3399 "GrammarParser.cpp"
    break;

  case 97: // ThfTuple: "[" ThfFormulaList "]"
#line 924 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3407 "GrammarParser.cpp"
    break;

  case 98: // ThfFormulaList: ThfLogicFormula
#line 931 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3035 "GrammarParser.cpp"
    break;

  case 96:
#line 922 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3043 "GrammarParser.cpp"
    break;

  case 97:
#line 926 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3051 "GrammarParser.cpp"
    break;

  case 98:
#line 933 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3417 "GrammarParser.cpp"
    break;

  case 99: // ThfFormulaList: ThfFormulaList "," ThfLogicFormula
#line 937 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3061 "GrammarParser.cpp"
    break;

  case 99:
#line 939 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3427 "GrammarParser.cpp"
    break;

  case 100: // ThfConnTerm: NonassocConnective
#line 946 "../../obj/src/GrammarParser.yy"
  {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3436 "GrammarParser.cpp"
    break;

  case 101: // ThfConnTerm: AssocConnective
#line 951 "../../obj/src/GrammarParser.yy"
  {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3445 "GrammarParser.cpp"
    break;

  case 102: // ThfConnTerm: InfixEquality
#line 956 "../../obj/src/GrammarParser.yy"
  {
	auto pair = yystack_[0].value.as < InfixConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3454 "GrammarParser.cpp"
    break;

  case 103: // ThfConnTerm: ThfUnaryConnective
#line 961 "../../obj/src/GrammarParser.yy"
  {
	auto pair = yystack_[0].value.as < UnaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3463 "GrammarParser.cpp"
    break;

  case 104: // ThfArguments: ThfFormulaList
#line 969 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < ListLogicElements::Ptr > () = yystack_[0].value.as < ListLogicElements::Ptr > ();
  }
#line 3471 "GrammarParser.cpp"
    break;

  case 105: // ThfAtomTyping: UntypedAtom ":" ThfTopLevelType
#line 976 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3479 "GrammarParser.cpp"
    break;

  case 106: // ThfAtomTyping: "(" ThfAtomTyping ")"
#line 980 "../../obj/src/GrammarParser.yy"
  {
	auto type = yystack_[1].value.as < TypedAtom::Ptr > ();
=======
#line 3071 "GrammarParser.cpp"
    break;

  case 100:
#line 948 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3080 "GrammarParser.cpp"
    break;

  case 101:
#line 953 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3089 "GrammarParser.cpp"
    break;

  case 102:
#line 958 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < InfixConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3098 "GrammarParser.cpp"
    break;

  case 103:
#line 963 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < UnaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3107 "GrammarParser.cpp"
    break;

  case 104:
#line 971 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ListLogicElements::Ptr > () = yystack_[0].value.as < ListLogicElements::Ptr > ();
  }
#line 3115 "GrammarParser.cpp"
    break;

  case 105:
#line 978 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TypeAtom::Ptr > () = libtptp::make< TypeAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3123 "GrammarParser.cpp"
    break;

  case 106:
#line 982 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < TypeAtom::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < TypeAtom::Ptr > () = type;
  }
<<<<<<< HEAD
#line 3490 "GrammarParser.cpp"
    break;

  case 107: // ThfTopLevelType: ThfUnitaryType
#line 990 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3498 "GrammarParser.cpp"
    break;

  case 108: // ThfTopLevelType: ThfMappingType
#line 994 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3506 "GrammarParser.cpp"
    break;

  case 109: // ThfTopLevelType: ThfApplyType
#line 998 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3514 "GrammarParser.cpp"
    break;

  case 110: // ThfUnitaryType: ThfUnitaryFormula
#line 1005 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3522 "GrammarParser.cpp"
    break;

  case 111: // ThfApplyType: ThfApplyFormula
#line 1012 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < BinaryLogic::Ptr > ());
  }
#line 3530 "GrammarParser.cpp"
    break;

  case 112: // ThfBinaryType: ThfMappingType
#line 1019 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3538 "GrammarParser.cpp"
    break;

  case 113: // ThfBinaryType: ThfXprodType
#line 1023 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3546 "GrammarParser.cpp"
    break;

  case 114: // ThfBinaryType: ThfUnionType
#line 1027 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3554 "GrammarParser.cpp"
    break;

  case 115: // ThfMappingType: ThfUnitaryType ">" ThfUnitaryType
#line 1035 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3562 "GrammarParser.cpp"
    break;

  case 116: // ThfMappingType: ThfUnitaryType ">" ThfMappingType
#line 1039 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < BinaryType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3570 "GrammarParser.cpp"
    break;

  case 117: // ThfXprodType: ThfUnitaryType "*" ThfUnitaryType
#line 1047 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3578 "GrammarParser.cpp"
    break;

  case 118: // ThfXprodType: ThfXprodType "*" ThfUnitaryType
#line 1051 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3586 "GrammarParser.cpp"
    break;

  case 119: // ThfUnionType: ThfUnitaryType "+" ThfUnitaryType
#line 1059 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3594 "GrammarParser.cpp"
    break;

  case 120: // ThfUnionType: ThfUnionType "+" ThfUnitaryType
#line 1063 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3602 "GrammarParser.cpp"
    break;

  case 121: // ThfSubtype: UntypedAtom "<<" Atom
#line 1070 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 3610 "GrammarParser.cpp"
    break;

  case 122: // ThfSequent: ThfTuple "-->" ThfTuple
#line 1077 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 3618 "GrammarParser.cpp"
    break;

  case 123: // ThfSequent: "(" ThfSequent ")"
#line 1081 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3134 "GrammarParser.cpp"
    break;

  case 107:
#line 992 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < ApplyType::Ptr > ();
  }
#line 3142 "GrammarParser.cpp"
    break;

  case 108:
#line 996 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3150 "GrammarParser.cpp"
    break;

  case 109:
#line 1000 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < ApplyType::Ptr > ();
  }
#line 3158 "GrammarParser.cpp"
    break;

  case 110:
#line 1008 "../../obj/src/GrammarParser.yy"
    {
	//TODO: @moosbruggerj implement
	//$$ = libtptp::make< AtomType >(@$, $1);
  }
#line 3167 "GrammarParser.cpp"
    break;

  case 111:
#line 1017 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ApplyType::Ptr > () = libtptp::make< ApplyType >(yylhs.location, yystack_[0].value.as < BinaryLogic::Ptr > ());
  }
#line 3175 "GrammarParser.cpp"
    break;

  case 112:
#line 1024 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3183 "GrammarParser.cpp"
    break;

  case 113:
#line 1028 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < RelationType::Ptr > ();
  }
#line 3191 "GrammarParser.cpp"
    break;

  case 114:
#line 1032 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3199 "GrammarParser.cpp"
    break;

  case 115:
#line 1040 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < ApplyType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < ApplyType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3207 "GrammarParser.cpp"
    break;

  case 116:
#line 1044 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < ApplyType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < BinaryType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3215 "GrammarParser.cpp"
    break;

  case 117:
#line 1052 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[2].value.as < ApplyType::Ptr > ());
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < ApplyType::Ptr > ());
	yylhs.value.as < RelationType::Ptr > () = libtptp::make< RelationType >(yylhs.location, list);
  }
#line 3226 "GrammarParser.cpp"
    break;

  case 118:
#line 1059 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[2].value.as < RelationType::Ptr > ();
	type->elements()->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < ApplyType::Ptr > ());
	yylhs.value.as < RelationType::Ptr > () = type;
  }
#line 3236 "GrammarParser.cpp"
    break;

  case 119:
#line 1069 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < ApplyType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < ApplyType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3244 "GrammarParser.cpp"
    break;

  case 120:
#line 1073 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < ApplyType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3252 "GrammarParser.cpp"
    break;

  case 121:
#line 1080 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 3260 "GrammarParser.cpp"
    break;

  case 122:
#line 1087 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 3268 "GrammarParser.cpp"
    break;

  case 123:
#line 1091 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < SequentLogic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < SequentLogic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 3629 "GrammarParser.cpp"
    break;

  case 124: // TffFormula: TffLogicFormula
#line 1092 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3637 "GrammarParser.cpp"
    break;

  case 125: // TffFormula: TffAtomTyping
#line 1096 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 3645 "GrammarParser.cpp"
    break;

  case 126: // TffFormula: TffSubtype
#line 1100 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 3653 "GrammarParser.cpp"
    break;

  case 127: // TffFormula: TfxSequent
#line 1104 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 3661 "GrammarParser.cpp"
    break;

  case 128: // TffLogicFormula: TffUnitaryFormula
#line 1111 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3669 "GrammarParser.cpp"
    break;

  case 129: // TffLogicFormula: TffUnaryFormula
#line 1115 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3677 "GrammarParser.cpp"
    break;

  case 130: // TffLogicFormula: TffBinaryFormula
#line 1119 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3685 "GrammarParser.cpp"
    break;

  case 131: // TffLogicFormula: TffDefinedInfix
#line 1123 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3693 "GrammarParser.cpp"
    break;

  case 132: // TffBinaryFormula: TffBinaryNonassoc
#line 1130 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3701 "GrammarParser.cpp"
    break;

  case 133: // TffBinaryFormula: TffBinaryAssoc
#line 1134 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3709 "GrammarParser.cpp"
    break;

  case 134: // TffBinaryNonassoc: TffUnitFormula NonassocConnective TffUnitFormula
#line 1141 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3717 "GrammarParser.cpp"
    break;

  case 135: // TffBinaryAssoc: TffOrFormula
#line 1148 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3725 "GrammarParser.cpp"
    break;

  case 136: // TffBinaryAssoc: TffAndFormula
#line 1152 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3733 "GrammarParser.cpp"
    break;

  case 137: // TffOrFormula: TffUnitFormula "|" TffUnitFormula
#line 1159 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3742 "GrammarParser.cpp"
    break;

  case 138: // TffOrFormula: TffOrFormula "|" TffUnitFormula
#line 1164 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3751 "GrammarParser.cpp"
    break;

  case 139: // TffAndFormula: TffUnitFormula "&" TffUnitFormula
#line 1172 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3760 "GrammarParser.cpp"
    break;

  case 140: // TffAndFormula: TffAndFormula "&" TffUnitFormula
#line 1177 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3769 "GrammarParser.cpp"
    break;

  case 141: // TffUnitFormula: TffUnitaryFormula
#line 1185 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3777 "GrammarParser.cpp"
    break;

  case 142: // TffUnitFormula: TffUnaryFormula
#line 1189 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3785 "GrammarParser.cpp"
    break;

  case 143: // TffUnitFormula: TffDefinedInfix
#line 1193 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3793 "GrammarParser.cpp"
    break;

  case 144: // TffPreunitFormula: TffUnitaryFormula
#line 1200 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3801 "GrammarParser.cpp"
    break;

  case 145: // TffPreunitFormula: TffPrefixUnary
#line 1204 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3809 "GrammarParser.cpp"
    break;

  case 146: // TffUnitaryFormula: TffQuantifiedFormula
#line 1211 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 3817 "GrammarParser.cpp"
    break;

  case 147: // TffUnitaryFormula: TffAtomicFormula
#line 1215 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3825 "GrammarParser.cpp"
    break;

  case 148: // TffUnitaryFormula: TfxUnitaryFormula
#line 1219 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3833 "GrammarParser.cpp"
    break;

  case 149: // TffUnitaryFormula: "(" TffLogicFormula ")"
#line 1223 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3279 "GrammarParser.cpp"
    break;

  case 124:
#line 1102 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3287 "GrammarParser.cpp"
    break;

  case 125:
#line 1106 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypeAtom::Ptr > ();
  }
#line 3295 "GrammarParser.cpp"
    break;

  case 126:
#line 1110 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 3303 "GrammarParser.cpp"
    break;

  case 127:
#line 1114 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 3311 "GrammarParser.cpp"
    break;

  case 128:
#line 1121 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3319 "GrammarParser.cpp"
    break;

  case 129:
#line 1125 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3327 "GrammarParser.cpp"
    break;

  case 130:
#line 1129 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3335 "GrammarParser.cpp"
    break;

  case 131:
#line 1133 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3343 "GrammarParser.cpp"
    break;

  case 132:
#line 1140 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3351 "GrammarParser.cpp"
    break;

  case 133:
#line 1144 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3359 "GrammarParser.cpp"
    break;

  case 134:
#line 1151 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3367 "GrammarParser.cpp"
    break;

  case 135:
#line 1158 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3375 "GrammarParser.cpp"
    break;

  case 136:
#line 1162 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3383 "GrammarParser.cpp"
    break;

  case 137:
#line 1169 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3392 "GrammarParser.cpp"
    break;

  case 138:
#line 1174 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3401 "GrammarParser.cpp"
    break;

  case 139:
#line 1182 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3410 "GrammarParser.cpp"
    break;

  case 140:
#line 1187 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3419 "GrammarParser.cpp"
    break;

  case 141:
#line 1195 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3427 "GrammarParser.cpp"
    break;

  case 142:
#line 1199 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3435 "GrammarParser.cpp"
    break;

  case 143:
#line 1203 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3443 "GrammarParser.cpp"
    break;

  case 144:
#line 1210 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3451 "GrammarParser.cpp"
    break;

  case 145:
#line 1214 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3459 "GrammarParser.cpp"
    break;

  case 146:
#line 1221 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 3467 "GrammarParser.cpp"
    break;

  case 147:
#line 1225 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3475 "GrammarParser.cpp"
    break;

  case 148:
#line 1229 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3483 "GrammarParser.cpp"
    break;

  case 149:
#line 1233 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 3844 "GrammarParser.cpp"
    break;

  case 150: // TfxUnitaryFormula: Variable
#line 1233 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3852 "GrammarParser.cpp"
    break;

  case 151: // TffQuantifiedFormula: FofQuantifier "[" TffVariableList "]" ":" TffUnitFormula
#line 1240 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLiteral >(yystack_[3].location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), list, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3861 "GrammarParser.cpp"
    break;

  case 152: // TffVariableList: TffVariable
#line 1248 "../../obj/src/GrammarParser.yy"
  {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
=======
#line 3494 "GrammarParser.cpp"
    break;

  case 150:
#line 1243 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3502 "GrammarParser.cpp"
    break;

  case 151:
#line 1250 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListVariableElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3510 "GrammarParser.cpp"
    break;

  case 152:
#line 1257 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListVariableElements >(yylhs.location);
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3872 "GrammarParser.cpp"
    break;

  case 153: // TffVariableList: TffVariableList "," TffVariable
#line 1255 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
=======
#line 3520 "GrammarParser.cpp"
    break;

  case 153:
#line 1263 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListVariableElements::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 3882 "GrammarParser.cpp"
    break;

  case 154: // TffVariable: TffTypedVariable
#line 1264 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3890 "GrammarParser.cpp"
    break;

  case 155: // TffVariable: Variable
#line 1268 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3898 "GrammarParser.cpp"
    break;

  case 156: // TffTypedVariable: Variable ":" TffAtomicType
#line 1275 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3530 "GrammarParser.cpp"
    break;

  case 154:
#line 1272 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3538 "GrammarParser.cpp"
    break;

  case 155:
#line 1276 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3546 "GrammarParser.cpp"
    break;

  case 156:
#line 1283 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto variable = yystack_[2].value.as < VariableTerm::Ptr > ();
	variable->setColon(yystack_[1].value.as < Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as < Type::Ptr > (); //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	yylhs.value.as < VariableTerm::Ptr > () = variable;
  }
<<<<<<< HEAD
#line 3910 "GrammarParser.cpp"
    break;

  case 157: // TffUnaryFormula: TffPrefixUnary
#line 1286 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3918 "GrammarParser.cpp"
    break;

  case 158: // TffUnaryFormula: TffInfixUnary
#line 1290 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3926 "GrammarParser.cpp"
    break;

  case 159: // TffPrefixUnary: UnaryConnective TffPreunitFormula
#line 1297 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3934 "GrammarParser.cpp"
    break;

  case 160: // TffInfixUnary: TffUnitaryTerm InfixInequality TffUnitaryTerm
#line 1304 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3942 "GrammarParser.cpp"
    break;

  case 161: // TffAtomicFormula: TffPlainAtomic
#line 1311 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3950 "GrammarParser.cpp"
    break;

  case 162: // TffAtomicFormula: TffDefinedAtomic
#line 1315 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3958 "GrammarParser.cpp"
    break;

  case 163: // TffAtomicFormula: TffSystemAtomic
#line 1319 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3966 "GrammarParser.cpp"
    break;

  case 164: // TffPlainAtomic: Constant
#line 1326 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3974 "GrammarParser.cpp"
    break;

  case 165: // TffPlainAtomic: Functor "(" TffArguments ")"
#line 1330 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3982 "GrammarParser.cpp"
    break;

  case 166: // TffDefinedAtomic: TffDefinedPlain
#line 1337 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3990 "GrammarParser.cpp"
    break;

  case 167: // TffDefinedPlain: DefinedConstant
#line 1344 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3998 "GrammarParser.cpp"
    break;

  case 168: // TffDefinedPlain: DefinedFunctor "(" TffArguments ")"
#line 1348 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4006 "GrammarParser.cpp"
    break;

  case 169: // TffDefinedPlain: TfxConditional
#line 1352 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 4014 "GrammarParser.cpp"
    break;

  case 170: // TffDefinedPlain: TfxLet
#line 1356 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 4022 "GrammarParser.cpp"
    break;

  case 171: // TffDefinedInfix: TffUnitaryTerm DefinedInfixPred TffUnitaryTerm
#line 1363 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4030 "GrammarParser.cpp"
    break;

  case 172: // TffSystemAtomic: SystemConstant
#line 1370 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4038 "GrammarParser.cpp"
    break;

  case 173: // TffSystemAtomic: SystemFunctor "(" TffArguments ")"
#line 1374 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4046 "GrammarParser.cpp"
    break;

  case 174: // TfxConditional: "$" "ite" "(" TffLogicFormula "," TffTerm "," TffTerm ")"
#line 1381 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4054 "GrammarParser.cpp"
    break;

  case 175: // TfxLet: "$" "let" "(" TfxLetTypes "," TfxLetDefns "," TffTerm ")"
#line 1388 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Type::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4062 "GrammarParser.cpp"
    break;

  case 176: // TfxLetTypes: TffAtomTyping
#line 1395 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 4070 "GrammarParser.cpp"
    break;

  case 177: // TfxLetTypes: "[" TffAtomTypingList "]"
#line 1399 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4078 "GrammarParser.cpp"
    break;

  case 178: // TffAtomTypingList: TffAtomTyping
#line 1406 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4088 "GrammarParser.cpp"
    break;

  case 179: // TffAtomTypingList: TffAtomTypingList "," TffAtomTyping
#line 1412 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4098 "GrammarParser.cpp"
    break;

  case 180: // TfxLetDefns: TfxLetDefn
#line 1421 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 4106 "GrammarParser.cpp"
    break;

  case 181: // TfxLetDefns: "[" TfxLetDefnList "]"
#line 1425 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4114 "GrammarParser.cpp"
    break;

  case 182: // TfxLetDefn: TfxLetLhs ":=" TffTerm
#line 1432 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4122 "GrammarParser.cpp"
    break;

  case 183: // TfxLetLhs: TffPlainAtomic
#line 1439 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4130 "GrammarParser.cpp"
    break;

  case 184: // TfxLetLhs: TfxTuple
#line 1443 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 4138 "GrammarParser.cpp"
    break;

  case 185: // TfxLetDefnList: TfxLetDefn
#line 1450 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
=======
#line 3558 "GrammarParser.cpp"
    break;

  case 157:
#line 1294 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3566 "GrammarParser.cpp"
    break;

  case 158:
#line 1298 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3574 "GrammarParser.cpp"
    break;

  case 159:
#line 1305 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3582 "GrammarParser.cpp"
    break;

  case 160:
#line 1312 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3590 "GrammarParser.cpp"
    break;

  case 161:
#line 1319 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3598 "GrammarParser.cpp"
    break;

  case 162:
#line 1323 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3606 "GrammarParser.cpp"
    break;

  case 163:
#line 1327 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3614 "GrammarParser.cpp"
    break;

  case 164:
#line 1334 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3622 "GrammarParser.cpp"
    break;

  case 165:
#line 1338 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3630 "GrammarParser.cpp"
    break;

  case 166:
#line 1345 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3638 "GrammarParser.cpp"
    break;

  case 167:
#line 1352 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3646 "GrammarParser.cpp"
    break;

  case 168:
#line 1356 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3654 "GrammarParser.cpp"
    break;

  case 169:
#line 1360 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 3662 "GrammarParser.cpp"
    break;

  case 170:
#line 1364 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 3670 "GrammarParser.cpp"
    break;

  case 171:
#line 1371 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3678 "GrammarParser.cpp"
    break;

  case 172:
#line 1378 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3686 "GrammarParser.cpp"
    break;

  case 173:
#line 1382 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3694 "GrammarParser.cpp"
    break;

  case 174:
#line 1389 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3702 "GrammarParser.cpp"
    break;

  case 175:
#line 1396 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Atom::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Atom::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3710 "GrammarParser.cpp"
    break;

  case 176:
#line 1403 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < TypeAtom::Ptr > ();
  }
#line 3718 "GrammarParser.cpp"
    break;

  case 177:
#line 1407 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< TupleAtom >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListAtomElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3726 "GrammarParser.cpp"
    break;

  case 178:
#line 1414 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListAtomElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypeAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
#line 3736 "GrammarParser.cpp"
    break;

  case 179:
#line 1420 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListAtomElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypeAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
#line 3746 "GrammarParser.cpp"
    break;

  case 180:
#line 1429 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 3754 "GrammarParser.cpp"
    break;

  case 181:
#line 1433 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< TupleAtom >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListAtomElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3762 "GrammarParser.cpp"
    break;

  case 182:
#line 1440 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3770 "GrammarParser.cpp"
    break;

  case 183:
#line 1447 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3778 "GrammarParser.cpp"
    break;

  case 184:
#line 1451 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3786 "GrammarParser.cpp"
    break;

  case 185:
#line 1458 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListAtomElements >(yylhs.location);
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4148 "GrammarParser.cpp"
    break;

  case 186: // TfxLetDefnList: TfxLetDefnList "," TfxLetDefn
#line 1456 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
=======
#line 3796 "GrammarParser.cpp"
    break;

  case 186:
#line 1464 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListAtomElements::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListAtomElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4158 "GrammarParser.cpp"
    break;

  case 187: // TffTerm: TffLogicFormula
#line 1465 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4166 "GrammarParser.cpp"
    break;

  case 188: // TffTerm: DefinedTerm
#line 1469 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 4174 "GrammarParser.cpp"
    break;

  case 189: // TffTerm: TfxTuple
#line 1473 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 4182 "GrammarParser.cpp"
    break;

  case 190: // TffUnitaryTerm: TffAtomicFormula
#line 1480 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4190 "GrammarParser.cpp"
    break;

  case 191: // TffUnitaryTerm: DefinedTerm
#line 1484 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 4198 "GrammarParser.cpp"
    break;

  case 192: // TffUnitaryTerm: TfxTuple
#line 1488 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 4206 "GrammarParser.cpp"
    break;

  case 193: // TffUnitaryTerm: Variable
#line 1492 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 4214 "GrammarParser.cpp"
    break;

  case 194: // TffUnitaryTerm: "(" TffLogicFormula ")"
#line 1496 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3806 "GrammarParser.cpp"
    break;

  case 187:
#line 1473 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3814 "GrammarParser.cpp"
    break;

  case 188:
#line 1477 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 3822 "GrammarParser.cpp"
    break;

  case 189:
#line 1481 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3830 "GrammarParser.cpp"
    break;

  case 190:
#line 1488 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3838 "GrammarParser.cpp"
    break;

  case 191:
#line 1492 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 3846 "GrammarParser.cpp"
    break;

  case 192:
#line 1496 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3854 "GrammarParser.cpp"
    break;

  case 193:
#line 1500 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3862 "GrammarParser.cpp"
    break;

  case 194:
#line 1504 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 4225 "GrammarParser.cpp"
    break;

  case 195: // TfxTuple: "[" "]"
#line 1506 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4233 "GrammarParser.cpp"
    break;

  case 196: // TfxTuple: "[" TffArguments "]"
#line 1510 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4241 "GrammarParser.cpp"
    break;

  case 197: // TffArguments: TffTerm
#line 1517 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3873 "GrammarParser.cpp"
    break;

  case 195:
#line 1514 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3881 "GrammarParser.cpp"
    break;

  case 196:
#line 1518 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3889 "GrammarParser.cpp"
    break;

  case 197:
#line 1525 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4251 "GrammarParser.cpp"
    break;

  case 198: // TffArguments: TffArguments "," TffTerm
#line 1523 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3899 "GrammarParser.cpp"
    break;

  case 198:
#line 1531 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4261 "GrammarParser.cpp"
    break;

  case 199: // TffAtomTyping: UntypedAtom ":" TffTopLevelType
#line 1532 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 4269 "GrammarParser.cpp"
    break;

  case 200: // TffAtomTyping: "(" TffAtomTyping ")"
#line 1536 "../../obj/src/GrammarParser.yy"
  {
	auto type = yystack_[1].value.as < TypedAtom::Ptr > ();
=======
#line 3909 "GrammarParser.cpp"
    break;

  case 199:
#line 1540 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TypeAtom::Ptr > () = libtptp::make< TypeAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3917 "GrammarParser.cpp"
    break;

  case 200:
#line 1544 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < TypeAtom::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < TypeAtom::Ptr > () = type;
  }
<<<<<<< HEAD
#line 4280 "GrammarParser.cpp"
    break;

  case 201: // TffTopLevelType: TffAtomicType
#line 1546 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 4288 "GrammarParser.cpp"
    break;

  case 202: // TffTopLevelType: TffMappingType
#line 1550 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 4296 "GrammarParser.cpp"
    break;

  case 203: // TffTopLevelType: Tf1QuantifiedType
#line 1554 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < QuantifiedType::Ptr > ();
  }
#line 4304 "GrammarParser.cpp"
    break;

  case 204: // TffTopLevelType: "(" TffTopLevelType ")"
#line 1558 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3928 "GrammarParser.cpp"
    break;

  case 201:
#line 1554 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < Type::Ptr > ();
  }
#line 3936 "GrammarParser.cpp"
    break;

  case 202:
#line 1558 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3944 "GrammarParser.cpp"
    break;

  case 203:
#line 1562 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < QuantifiedType::Ptr > ();
  }
#line 3952 "GrammarParser.cpp"
    break;

  case 204:
#line 1566 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto type = yystack_[1].value.as < Type::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
<<<<<<< HEAD
#line 4315 "GrammarParser.cpp"
    break;

  case 205: // Tf1QuantifiedType: "!>" "[" TffVariableList "]" ":" TffMonotype
#line 1568 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 4323 "GrammarParser.cpp"
    break;

  case 206: // TffMonotype: TffAtomicType
#line 1575 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 4331 "GrammarParser.cpp"
    break;

  case 207: // TffMonotype: "(" TffMappingType ")"
#line 1579 "../../obj/src/GrammarParser.yy"
  {
=======
#line 3963 "GrammarParser.cpp"
    break;

  case 205:
#line 1576 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListVariableElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3971 "GrammarParser.cpp"
    break;

  case 206:
#line 1583 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < Type::Ptr > ();
  }
#line 3979 "GrammarParser.cpp"
    break;

  case 207:
#line 1587 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto type = yystack_[1].value.as < BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
<<<<<<< HEAD
#line 4342 "GrammarParser.cpp"
    break;

  case 208: // TffUnitaryType: TffAtomicType
#line 1589 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 4350 "GrammarParser.cpp"
    break;

  case 209: // TffUnitaryType: "(" TffXprodType ")"
#line 1593 "../../obj/src/GrammarParser.yy"
  {
	auto type = yystack_[1].value.as < BinaryType::Ptr > ();
=======
#line 3990 "GrammarParser.cpp"
    break;

  case 208:
#line 1597 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < Type::Ptr > ();
  }
#line 3998 "GrammarParser.cpp"
    break;

  case 209:
#line 1601 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < RelationType::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
<<<<<<< HEAD
#line 4361 "GrammarParser.cpp"
    break;

  case 210: // TffAtomicType: TypeConstant
#line 1603 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4369 "GrammarParser.cpp"
    break;

  case 211: // TffAtomicType: DefinedType
#line 1607 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4377 "GrammarParser.cpp"
    break;

  case 212: // TffAtomicType: TypeFunctor "(" TffTypeArguments ")"
#line 1611 "../../obj/src/GrammarParser.yy"
  {
	auto functor = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::TYPE);
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, functor);
  }
#line 4386 "GrammarParser.cpp"
    break;

  case 213: // TffAtomicType: Variable
#line 1616 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 4394 "GrammarParser.cpp"
    break;

  case 214: // TffAtomicType: TfxTupleType
#line 1620 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < TupleType::Ptr > ());
  }
#line 4402 "GrammarParser.cpp"
    break;

  case 215: // TffTypeArguments: TffAtomicType
#line 1627 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < AtomType::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4412 "GrammarParser.cpp"
    break;

  case 216: // TffTypeArguments: TffTypeArguments "," TffAtomicType
#line 1633 "../../obj/src/GrammarParser.yy"
  {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4422 "GrammarParser.cpp"
    break;

  case 217: // TffMappingType: TffUnitaryType ">" TffAtomicType
#line 1642 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < Type::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 4430 "GrammarParser.cpp"
    break;

  case 218: // TffXprodType: TffUnitaryType "*" TffAtomicType
#line 1649 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < Type::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4438 "GrammarParser.cpp"
    break;

  case 219: // TffXprodType: TffXprodType "*" TffAtomicType
#line 1653 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4446 "GrammarParser.cpp"
    break;

  case 220: // TfxTupleType: "[" TffTypeList "]"
#line 1660 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4454 "GrammarParser.cpp"
    break;

  case 221: // TffTypeList: TffTopLevelType
#line 1667 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4009 "GrammarParser.cpp"
    break;

  case 210:
#line 1611 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< NamedType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4017 "GrammarParser.cpp"
    break;

  case 211:
#line 1615 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< NamedType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4025 "GrammarParser.cpp"
    break;

  case 212:
#line 1619 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< FunctorType >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4033 "GrammarParser.cpp"
    break;

  case 213:
#line 1623 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< VariableType >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 4041 "GrammarParser.cpp"
    break;

  case 214:
#line 1627 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < TupleType::Ptr > ();
  }
#line 4049 "GrammarParser.cpp"
    break;

  case 215:
#line 1634 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4059 "GrammarParser.cpp"
    break;

  case 216:
#line 1640 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4069 "GrammarParser.cpp"
    break;

  case 217:
#line 1649 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < Type::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 4077 "GrammarParser.cpp"
    break;

  case 218:
#line 1656 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[2].value.as < Type::Ptr > ());
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < RelationType::Ptr > () = libtptp::make< RelationType >(yylhs.location, list);
  }
#line 4088 "GrammarParser.cpp"
    break;

  case 219:
#line 1663 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[2].value.as < RelationType::Ptr > ();
	type->elements()->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < RelationType::Ptr > () = type;
  }
#line 4098 "GrammarParser.cpp"
    break;

  case 220:
#line 1672 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4106 "GrammarParser.cpp"
    break;

  case 221:
#line 1679 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4464 "GrammarParser.cpp"
    break;

  case 222: // TffTypeList: TffTypeList "," TffTopLevelType
#line 1673 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4116 "GrammarParser.cpp"
    break;

  case 222:
#line 1685 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 4474 "GrammarParser.cpp"
    break;

  case 223: // TffSubtype: UntypedAtom "<<" Atom
#line 1682 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4482 "GrammarParser.cpp"
    break;

  case 224: // TfxSequent: TfxTuple "-->" TfxTuple
#line 1689 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4490 "GrammarParser.cpp"
    break;

  case 225: // TfxSequent: "(" TfxSequent ")"
#line 1693 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4126 "GrammarParser.cpp"
    break;

  case 223:
#line 1694 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4134 "GrammarParser.cpp"
    break;

  case 224:
#line 1701 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4142 "GrammarParser.cpp"
    break;

  case 225:
#line 1705 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto sequent = yystack_[1].value.as < SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < SequentLogic::Ptr > () = sequent;
  }
<<<<<<< HEAD
#line 4501 "GrammarParser.cpp"
    break;

  case 226: // TcfFormula: TcfLogicFormula
#line 1704 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4509 "GrammarParser.cpp"
    break;

  case 227: // TcfFormula: TffAtomTyping
#line 1708 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 4517 "GrammarParser.cpp"
    break;

  case 228: // TcfLogicFormula: TcfQuantifiedFormula
#line 1715 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4525 "GrammarParser.cpp"
    break;

  case 229: // TcfLogicFormula: CnfFormula
#line 1719 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4533 "GrammarParser.cpp"
    break;

  case 230: // TcfQuantifiedFormula: "!" "[" TffVariableList "]" ":" CnfFormula
#line 1726 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4153 "GrammarParser.cpp"
    break;

  case 226:
#line 1716 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4161 "GrammarParser.cpp"
    break;

  case 227:
#line 1720 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypeAtom::Ptr > ();
  }
#line 4169 "GrammarParser.cpp"
    break;

  case 228:
#line 1727 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4177 "GrammarParser.cpp"
    break;

  case 229:
#line 1731 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4185 "GrammarParser.cpp"
    break;

  case 230:
#line 1738 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto op = std::make_pair(yystack_[5].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, op, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListVariableElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
<<<<<<< HEAD
#line 4543 "GrammarParser.cpp"
    break;

  case 231: // FofFormula: FofLogicFormula
#line 1737 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4551 "GrammarParser.cpp"
    break;

  case 232: // FofFormula: FofSequent
#line 1741 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 4559 "GrammarParser.cpp"
    break;

  case 233: // FofLogicFormula: FofBinaryFormula
#line 1748 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4567 "GrammarParser.cpp"
    break;

  case 234: // FofLogicFormula: FofUnaryFormula
#line 1752 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4575 "GrammarParser.cpp"
    break;

  case 235: // FofLogicFormula: FofUnitaryFormula
#line 1756 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4583 "GrammarParser.cpp"
    break;

  case 236: // FofBinaryFormula: FofBinaryNonassoc
#line 1763 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4591 "GrammarParser.cpp"
    break;

  case 237: // FofBinaryFormula: FofBinaryAssoc
#line 1767 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4599 "GrammarParser.cpp"
    break;

  case 238: // FofBinaryNonassoc: FofUnitFormula NonassocConnective FofUnitFormula
#line 1774 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4607 "GrammarParser.cpp"
    break;

  case 239: // FofBinaryAssoc: FofOrFormula
#line 1781 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4615 "GrammarParser.cpp"
    break;

  case 240: // FofBinaryAssoc: FofAndFormula
#line 1785 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4623 "GrammarParser.cpp"
    break;

  case 241: // FofOrFormula: FofUnitFormula "|" FofUnitFormula
#line 1792 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4632 "GrammarParser.cpp"
    break;

  case 242: // FofOrFormula: FofOrFormula "|" FofUnitFormula
#line 1797 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4641 "GrammarParser.cpp"
    break;

  case 243: // FofAndFormula: FofUnitFormula "&" FofUnitFormula
#line 1805 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4650 "GrammarParser.cpp"
    break;

  case 244: // FofAndFormula: FofAndFormula "&" FofUnitFormula
#line 1810 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4659 "GrammarParser.cpp"
    break;

  case 245: // FofUnaryFormula: UnaryConnective FofUnitFormula
#line 1818 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4667 "GrammarParser.cpp"
    break;

  case 246: // FofUnaryFormula: FofInfixUnary
#line 1822 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4675 "GrammarParser.cpp"
    break;

  case 247: // FofInfixUnary: FofTerm InfixInequality FofTerm
#line 1829 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4683 "GrammarParser.cpp"
    break;

  case 248: // FofUnitFormula: FofUnitaryFormula
#line 1836 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4691 "GrammarParser.cpp"
    break;

  case 249: // FofUnitFormula: FofUnaryFormula
#line 1840 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4699 "GrammarParser.cpp"
    break;

  case 250: // FofUnitaryFormula: FofQuantifiedFormula
#line 1847 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4707 "GrammarParser.cpp"
    break;

  case 251: // FofUnitaryFormula: FofAtomicFormula
#line 1851 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4715 "GrammarParser.cpp"
    break;

  case 252: // FofUnitaryFormula: "(" FofLogicFormula ")"
#line 1855 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4194 "GrammarParser.cpp"
    break;

  case 231:
#line 1748 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4202 "GrammarParser.cpp"
    break;

  case 232:
#line 1752 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 4210 "GrammarParser.cpp"
    break;

  case 233:
#line 1759 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4218 "GrammarParser.cpp"
    break;

  case 234:
#line 1763 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4226 "GrammarParser.cpp"
    break;

  case 235:
#line 1767 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4234 "GrammarParser.cpp"
    break;

  case 236:
#line 1774 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4242 "GrammarParser.cpp"
    break;

  case 237:
#line 1778 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4250 "GrammarParser.cpp"
    break;

  case 238:
#line 1785 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4258 "GrammarParser.cpp"
    break;

  case 239:
#line 1792 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4266 "GrammarParser.cpp"
    break;

  case 240:
#line 1796 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4274 "GrammarParser.cpp"
    break;

  case 241:
#line 1803 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4283 "GrammarParser.cpp"
    break;

  case 242:
#line 1808 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4292 "GrammarParser.cpp"
    break;

  case 243:
#line 1816 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4301 "GrammarParser.cpp"
    break;

  case 244:
#line 1821 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4310 "GrammarParser.cpp"
    break;

  case 245:
#line 1829 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4318 "GrammarParser.cpp"
    break;

  case 246:
#line 1833 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4326 "GrammarParser.cpp"
    break;

  case 247:
#line 1840 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4334 "GrammarParser.cpp"
    break;

  case 248:
#line 1847 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4342 "GrammarParser.cpp"
    break;

  case 249:
#line 1851 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4350 "GrammarParser.cpp"
    break;

  case 250:
#line 1858 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4358 "GrammarParser.cpp"
    break;

  case 251:
#line 1862 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4366 "GrammarParser.cpp"
    break;

  case 252:
#line 1866 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 4726 "GrammarParser.cpp"
    break;

  case 253: // FofQuantifiedFormula: FofQuantifier "[" FofVariableList "]" ":" FofUnitFormula
#line 1865 "../../obj/src/GrammarParser.yy"
  {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), variables, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4735 "GrammarParser.cpp"
    break;

  case 254: // FofVariableList: Variable
#line 1873 "../../obj/src/GrammarParser.yy"
  {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< ListNodeElements >(yylhs.location);
=======
#line 4377 "GrammarParser.cpp"
    break;

  case 253:
#line 1876 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListVariableElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4385 "GrammarParser.cpp"
    break;

  case 254:
#line 1883 "../../obj/src/GrammarParser.yy"
    {
	auto variables = libtptp::make< ListVariableElements >(yylhs.location);
>>>>>>> 508276a (GrammarParser: commmit built files)
	variables->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = variables;
  }
<<<<<<< HEAD
#line 4746 "GrammarParser.cpp"
    break;

  case 255: // FofVariableList: FofVariableList "," Variable
#line 1880 "../../obj/src/GrammarParser.yy"
  {
	auto variables = yystack_[2].value.as < ListNodeElements::Ptr > ();
=======
#line 4395 "GrammarParser.cpp"
    break;

  case 255:
#line 1889 "../../obj/src/GrammarParser.yy"
    {
	auto variables = yystack_[2].value.as < ListVariableElements::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
	variables->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListVariableElements::Ptr > () = variables;
  }
<<<<<<< HEAD
#line 4756 "GrammarParser.cpp"
    break;

  case 256: // FofAtomicFormula: FofPlainAtomicFormula
#line 1889 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4764 "GrammarParser.cpp"
    break;

  case 257: // FofAtomicFormula: FofDefinedAtomicFormula
#line 1893 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4772 "GrammarParser.cpp"
    break;

  case 258: // FofAtomicFormula: FofSystemAtomicFormula
#line 1897 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4780 "GrammarParser.cpp"
    break;

  case 259: // FofPlainAtomicFormula: FofPlainTerm
#line 1904 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4788 "GrammarParser.cpp"
    break;

  case 260: // FofDefinedAtomicFormula: FofDefinedPlainFormula
#line 1911 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4796 "GrammarParser.cpp"
    break;

  case 261: // FofDefinedAtomicFormula: FofDefinedInfixFormula
#line 1915 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4804 "GrammarParser.cpp"
    break;

  case 262: // FofDefinedPlainFormula: FofDefinedPlainTerm
#line 1922 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4812 "GrammarParser.cpp"
    break;

  case 263: // FofDefinedInfixFormula: FofTerm DefinedInfixPred FofTerm
#line 1929 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4820 "GrammarParser.cpp"
    break;

  case 264: // FofSystemAtomicFormula: FofSystemTerm
#line 1936 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4828 "GrammarParser.cpp"
    break;

  case 265: // FofPlainTerm: Constant
#line 1943 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4836 "GrammarParser.cpp"
    break;

  case 266: // FofPlainTerm: Functor "(" FofArguments ")"
#line 1947 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4844 "GrammarParser.cpp"
    break;

  case 267: // FofDefinedTerm: DefinedTerm
#line 1954 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 4852 "GrammarParser.cpp"
    break;

  case 268: // FofDefinedTerm: FofDefinedAtomicTerm
#line 1958 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4860 "GrammarParser.cpp"
    break;

  case 269: // FofDefinedAtomicTerm: FofDefinedPlainTerm
#line 1965 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4868 "GrammarParser.cpp"
    break;

  case 270: // FofDefinedPlainTerm: DefinedConstant
#line 1972 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4876 "GrammarParser.cpp"
    break;

  case 271: // FofDefinedPlainTerm: DefinedFunctor "(" FofArguments ")"
#line 1976 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4884 "GrammarParser.cpp"
    break;

  case 272: // FofSystemTerm: SystemConstant
#line 1983 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4892 "GrammarParser.cpp"
    break;

  case 273: // FofSystemTerm: SystemFunctor "(" FofArguments ")"
#line 1987 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4900 "GrammarParser.cpp"
    break;

  case 274: // FofArguments: FofTerm
#line 1994 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4405 "GrammarParser.cpp"
    break;

  case 256:
#line 1898 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4413 "GrammarParser.cpp"
    break;

  case 257:
#line 1902 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4421 "GrammarParser.cpp"
    break;

  case 258:
#line 1906 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4429 "GrammarParser.cpp"
    break;

  case 259:
#line 1913 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4437 "GrammarParser.cpp"
    break;

  case 260:
#line 1920 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4445 "GrammarParser.cpp"
    break;

  case 261:
#line 1924 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4453 "GrammarParser.cpp"
    break;

  case 262:
#line 1931 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4461 "GrammarParser.cpp"
    break;

  case 263:
#line 1938 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4469 "GrammarParser.cpp"
    break;

  case 264:
#line 1945 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4477 "GrammarParser.cpp"
    break;

  case 265:
#line 1952 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4485 "GrammarParser.cpp"
    break;

  case 266:
#line 1956 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4493 "GrammarParser.cpp"
    break;

  case 267:
#line 1963 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 4501 "GrammarParser.cpp"
    break;

  case 268:
#line 1967 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4509 "GrammarParser.cpp"
    break;

  case 269:
#line 1974 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4517 "GrammarParser.cpp"
    break;

  case 270:
#line 1981 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4525 "GrammarParser.cpp"
    break;

  case 271:
#line 1985 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4533 "GrammarParser.cpp"
    break;

  case 272:
#line 1992 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4541 "GrammarParser.cpp"
    break;

  case 273:
#line 1996 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4549 "GrammarParser.cpp"
    break;

  case 274:
#line 2003 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto terms = libtptp::make< ListLogicElements >(yylhs.location);
	terms->add(yystack_[0].value.as < Term::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = terms;
  }
<<<<<<< HEAD
#line 4910 "GrammarParser.cpp"
    break;

  case 275: // FofArguments: FofArguments "," FofTerm
#line 2000 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4559 "GrammarParser.cpp"
    break;

  case 275:
#line 2009 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto terms = yystack_[2].value.as < ListLogicElements::Ptr > ();
	terms->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Term::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = terms;
  }
<<<<<<< HEAD
#line 4920 "GrammarParser.cpp"
    break;

  case 276: // FofTerm: FofFunctionTerm
#line 2009 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4928 "GrammarParser.cpp"
    break;

  case 277: // FofTerm: Variable
#line 2013 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 4936 "GrammarParser.cpp"
    break;

  case 278: // FofFunctionTerm: FofPlainTerm
#line 2020 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4944 "GrammarParser.cpp"
    break;

  case 279: // FofFunctionTerm: FofDefinedTerm
#line 2024 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4952 "GrammarParser.cpp"
    break;

  case 280: // FofFunctionTerm: FofSystemTerm
#line 2028 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4960 "GrammarParser.cpp"
    break;

  case 281: // FofSequent: FofFormulaTuple "-->" FofFormulaTuple
#line 2035 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4968 "GrammarParser.cpp"
    break;

  case 282: // FofSequent: "(" FofSequent ")"
#line 2039 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4569 "GrammarParser.cpp"
    break;

  case 276:
#line 2018 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4577 "GrammarParser.cpp"
    break;

  case 277:
#line 2022 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 4585 "GrammarParser.cpp"
    break;

  case 278:
#line 2029 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4593 "GrammarParser.cpp"
    break;

  case 279:
#line 2033 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4601 "GrammarParser.cpp"
    break;

  case 280:
#line 2037 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4609 "GrammarParser.cpp"
    break;

  case 281:
#line 2044 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4617 "GrammarParser.cpp"
    break;

  case 282:
#line 2048 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto sequent = yystack_[1].value.as < SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
  }
<<<<<<< HEAD
#line 4978 "GrammarParser.cpp"
    break;

  case 283: // FofFormulaTuple: "{" "}"
#line 2048 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4986 "GrammarParser.cpp"
    break;

  case 284: // FofFormulaTuple: "{" FofFormulaTupleList "}"
#line 2052 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4994 "GrammarParser.cpp"
    break;

  case 285: // FofFormulaTupleList: FofLogicFormula
#line 2059 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4627 "GrammarParser.cpp"
    break;

  case 283:
#line 2057 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4635 "GrammarParser.cpp"
    break;

  case 284:
#line 2061 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4643 "GrammarParser.cpp"
    break;

  case 285:
#line 2068 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 5004 "GrammarParser.cpp"
    break;

  case 286: // FofFormulaTupleList: FofFormulaTupleList "," FofLogicFormula
#line 2065 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4653 "GrammarParser.cpp"
    break;

  case 286:
#line 2074 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 5014 "GrammarParser.cpp"
    break;

  case 287: // CnfFormula: Disjunction
#line 2074 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 5022 "GrammarParser.cpp"
    break;

  case 288: // CnfFormula: "(" Disjunction ")"
#line 2078 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4663 "GrammarParser.cpp"
    break;

  case 287:
#line 2083 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4671 "GrammarParser.cpp"
    break;

  case 288:
#line 2087 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
<<<<<<< HEAD
#line 5033 "GrammarParser.cpp"
    break;

  case 289: // Disjunction: Literal
#line 2088 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 5041 "GrammarParser.cpp"
    break;

  case 290: // Disjunction: Disjunction "|" Literal
#line 2092 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 5050 "GrammarParser.cpp"
    break;

  case 291: // Literal: FofAtomicFormula
#line 2100 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 5058 "GrammarParser.cpp"
    break;

  case 292: // Literal: "~" FofAtomicFormula
#line 2104 "../../obj/src/GrammarParser.yy"
  {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 5067 "GrammarParser.cpp"
    break;

  case 293: // Literal: FofInfixUnary
#line 2109 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 5075 "GrammarParser.cpp"
    break;

  case 294: // ThfQuantifier: FofQuantifier
#line 2116 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 5083 "GrammarParser.cpp"
    break;

  case 295: // ThfQuantifier: Th0Quantifier
#line 2120 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 5091 "GrammarParser.cpp"
    break;

  case 296: // ThfQuantifier: Th1Quantifier
#line 2124 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 5099 "GrammarParser.cpp"
    break;

  case 297: // Th1Quantifier: "!>"
#line 2131 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
#line 5107 "GrammarParser.cpp"
    break;

  case 298: // Th1Quantifier: "?*"
#line 2135 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
#line 5115 "GrammarParser.cpp"
    break;

  case 299: // Th0Quantifier: "^"
#line 2142 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::CARET);
  }
#line 5123 "GrammarParser.cpp"
    break;

  case 300: // Th0Quantifier: "@+"
#line 2146 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATPLUS);
  }
#line 5131 "GrammarParser.cpp"
    break;

  case 301: // Th0Quantifier: "@-"
#line 2150 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATMINUS);
  }
#line 5139 "GrammarParser.cpp"
    break;

  case 302: // ThfUnaryConnective: UnaryConnective
#line 2157 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 5147 "GrammarParser.cpp"
    break;

  case 303: // ThfUnaryConnective: Th1UnaryConnective
#line 2161 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 5155 "GrammarParser.cpp"
    break;

  case 304: // Th1UnaryConnective: "!!"
#line 2168 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
#line 5163 "GrammarParser.cpp"
    break;

  case 305: // Th1UnaryConnective: "??"
#line 2172 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
#line 5171 "GrammarParser.cpp"
    break;

  case 306: // Th1UnaryConnective: "@@+"
#line 2176 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
#line 5179 "GrammarParser.cpp"
    break;

  case 307: // Th1UnaryConnective: "@@-"
#line 2180 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
#line 5187 "GrammarParser.cpp"
    break;

  case 308: // Th1UnaryConnective: "@="
#line 2184 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EQUALITY);
  }
#line 5195 "GrammarParser.cpp"
    break;

  case 309: // FofQuantifier: "!"
#line 2191 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 5203 "GrammarParser.cpp"
    break;

  case 310: // FofQuantifier: "?"
#line 2195 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 5211 "GrammarParser.cpp"
    break;

  case 311: // NonassocConnective: "<=>"
#line 2204 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 5219 "GrammarParser.cpp"
    break;

  case 312: // NonassocConnective: "=>"
#line 2208 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 5227 "GrammarParser.cpp"
    break;

  case 313: // NonassocConnective: "<="
#line 2212 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 5235 "GrammarParser.cpp"
    break;

  case 314: // NonassocConnective: "<~>"
#line 2216 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 5243 "GrammarParser.cpp"
    break;

  case 315: // NonassocConnective: "~|"
#line 2220 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 5251 "GrammarParser.cpp"
    break;

  case 316: // NonassocConnective: "~&"
#line 2224 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 5259 "GrammarParser.cpp"
    break;

  case 317: // AssocConnective: "|"
#line 2231 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 5267 "GrammarParser.cpp"
    break;

  case 318: // AssocConnective: "&"
#line 2235 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 5275 "GrammarParser.cpp"
    break;

  case 319: // UnaryConnective: "~"
#line 2242 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 5283 "GrammarParser.cpp"
    break;

  case 320: // TypeConstant: TypeFunctor
#line 2249 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5291 "GrammarParser.cpp"
    break;

  case 321: // TypeFunctor: AtomicWord
#line 2256 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5299 "GrammarParser.cpp"
    break;

  case 322: // DefinedType: AtomicDefinedWord
#line 2263 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5307 "GrammarParser.cpp"
    break;

  case 323: // Atom: UntypedAtom
#line 2270 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5315 "GrammarParser.cpp"
    break;

  case 324: // Atom: DefinedConstant
#line 2274 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5323 "GrammarParser.cpp"
    break;

  case 325: // UntypedAtom: Constant
#line 2281 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5331 "GrammarParser.cpp"
    break;

  case 326: // UntypedAtom: SystemConstant
#line 2285 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5339 "GrammarParser.cpp"
    break;

  case 327: // DefinedInfixPred: InfixEquality
#line 2292 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixConnective_t > () = yystack_[0].value.as < InfixConnective_t > ();
  }
#line 5347 "GrammarParser.cpp"
    break;

  case 328: // InfixEquality: "="
#line 2299 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 5355 "GrammarParser.cpp"
    break;

  case 329: // InfixInequality: "!="
#line 2306 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 5363 "GrammarParser.cpp"
    break;

  case 330: // Constant: Functor
#line 2313 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5371 "GrammarParser.cpp"
    break;

  case 331: // Functor: AtomicWord
#line 2320 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5379 "GrammarParser.cpp"
    break;

  case 332: // SystemConstant: SystemFunctor
#line 2327 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5387 "GrammarParser.cpp"
    break;

  case 333: // SystemFunctor: AtomicSystemWord
#line 2334 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5395 "GrammarParser.cpp"
    break;

  case 334: // DefinedConstant: DefinedFunctor
#line 2341 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5403 "GrammarParser.cpp"
    break;

  case 335: // DefinedFunctor: AtomicDefinedWord
#line 2348 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5411 "GrammarParser.cpp"
    break;

  case 336: // DefinedTerm: Number
#line 2355 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5419 "GrammarParser.cpp"
    break;

  case 337: // DefinedTerm: DistinctObjectLiteral
#line 2359 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5427 "GrammarParser.cpp"
    break;

  case 338: // NameList: Name
#line 2366 "../../obj/src/GrammarParser.yy"
  {
=======
#line 4682 "GrammarParser.cpp"
    break;

  case 289:
#line 2097 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4690 "GrammarParser.cpp"
    break;

  case 290:
#line 2101 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4699 "GrammarParser.cpp"
    break;

  case 291:
#line 2109 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4707 "GrammarParser.cpp"
    break;

  case 292:
#line 2113 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4716 "GrammarParser.cpp"
    break;

  case 293:
#line 2118 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4724 "GrammarParser.cpp"
    break;

  case 294:
#line 2125 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4732 "GrammarParser.cpp"
    break;

  case 295:
#line 2129 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4740 "GrammarParser.cpp"
    break;

  case 296:
#line 2133 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4748 "GrammarParser.cpp"
    break;

  case 297:
#line 2140 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
#line 4756 "GrammarParser.cpp"
    break;

  case 298:
#line 2144 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
#line 4764 "GrammarParser.cpp"
    break;

  case 299:
#line 2151 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::CARET);
  }
#line 4772 "GrammarParser.cpp"
    break;

  case 300:
#line 2155 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATPLUS);
  }
#line 4780 "GrammarParser.cpp"
    break;

  case 301:
#line 2159 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATMINUS);
  }
#line 4788 "GrammarParser.cpp"
    break;

  case 302:
#line 2166 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 4796 "GrammarParser.cpp"
    break;

  case 303:
#line 2170 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 4804 "GrammarParser.cpp"
    break;

  case 304:
#line 2177 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
#line 4812 "GrammarParser.cpp"
    break;

  case 305:
#line 2181 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
#line 4820 "GrammarParser.cpp"
    break;

  case 306:
#line 2185 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
#line 4828 "GrammarParser.cpp"
    break;

  case 307:
#line 2189 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
#line 4836 "GrammarParser.cpp"
    break;

  case 308:
#line 2193 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EQUALITY);
  }
#line 4844 "GrammarParser.cpp"
    break;

  case 309:
#line 2200 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4852 "GrammarParser.cpp"
    break;

  case 310:
#line 2204 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4860 "GrammarParser.cpp"
    break;

  case 311:
#line 2213 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 4868 "GrammarParser.cpp"
    break;

  case 312:
#line 2217 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 4876 "GrammarParser.cpp"
    break;

  case 313:
#line 2221 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 4884 "GrammarParser.cpp"
    break;

  case 314:
#line 2225 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 4892 "GrammarParser.cpp"
    break;

  case 315:
#line 2229 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 4900 "GrammarParser.cpp"
    break;

  case 316:
#line 2233 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 4908 "GrammarParser.cpp"
    break;

  case 317:
#line 2240 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 4916 "GrammarParser.cpp"
    break;

  case 318:
#line 2244 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 4924 "GrammarParser.cpp"
    break;

  case 319:
#line 2251 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 4932 "GrammarParser.cpp"
    break;

  case 320:
#line 2258 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4940 "GrammarParser.cpp"
    break;

  case 321:
#line 2265 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4948 "GrammarParser.cpp"
    break;

  case 322:
#line 2272 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4956 "GrammarParser.cpp"
    break;

  case 323:
#line 2279 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4964 "GrammarParser.cpp"
    break;

  case 324:
#line 2283 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4972 "GrammarParser.cpp"
    break;

  case 325:
#line 2290 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4980 "GrammarParser.cpp"
    break;

  case 326:
#line 2294 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4988 "GrammarParser.cpp"
    break;

  case 327:
#line 2301 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = yystack_[0].value.as < InfixConnective_t > ();
  }
#line 4996 "GrammarParser.cpp"
    break;

  case 328:
#line 2308 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 5004 "GrammarParser.cpp"
    break;

  case 329:
#line 2315 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 5012 "GrammarParser.cpp"
    break;

  case 330:
#line 2322 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5020 "GrammarParser.cpp"
    break;

  case 331:
#line 2329 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5028 "GrammarParser.cpp"
    break;

  case 332:
#line 2336 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5036 "GrammarParser.cpp"
    break;

  case 333:
#line 2343 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5044 "GrammarParser.cpp"
    break;

  case 334:
#line 2350 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5052 "GrammarParser.cpp"
    break;

  case 335:
#line 2357 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5060 "GrammarParser.cpp"
    break;

  case 336:
#line 2364 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5068 "GrammarParser.cpp"
    break;

  case 337:
#line 2368 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5076 "GrammarParser.cpp"
    break;

  case 338:
#line 2375 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < Identifier::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 5439 "GrammarParser.cpp"
    break;

  case 339: // NameList: NameList "," Name
#line 2374 "../../obj/src/GrammarParser.yy"
  {
=======
#line 5088 "GrammarParser.cpp"
    break;

  case 339:
#line 2383 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	const auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 5449 "GrammarParser.cpp"
    break;

  case 340: // Name: AtomicWord
#line 2383 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5457 "GrammarParser.cpp"
    break;

  case 341: // Name: "integer"
#line 2387 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > (), Identifier::Kind::NUMBER);
  }
#line 5465 "GrammarParser.cpp"
    break;

  case 342: // FormulaRole: LowerWordLiteral
#line 2394 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < Role::Ptr > () = libtptp::make< Role >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 5473 "GrammarParser.cpp"
    break;

  case 343: // GeneralTerm: GeneralData
#line 2401 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralData::Ptr > ();
  }
#line 5481 "GrammarParser.cpp"
    break;

  case 344: // GeneralTerm: GeneralData ":" GeneralTerm
#line 2405 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as < GeneralData::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralTerm::Ptr > ());
  }
#line 5489 "GrammarParser.cpp"
    break;

  case 345: // GeneralTerm: GeneralList
#line 2409 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralList::Ptr > ();
  }
#line 5497 "GrammarParser.cpp"
    break;

  case 346: // GeneralData: AtomicWord
#line 2416 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 5505 "GrammarParser.cpp"
    break;

  case 347: // GeneralData: GeneralFunction
#line 2420 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < GeneralFunction::Ptr > ());
  }
#line 5513 "GrammarParser.cpp"
    break;

  case 348: // GeneralData: Variable
#line 2424 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 5521 "GrammarParser.cpp"
    break;

  case 349: // GeneralData: Number
#line 2428 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5529 "GrammarParser.cpp"
    break;

  case 350: // GeneralData: DistinctObjectLiteral
#line 2432 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5537 "GrammarParser.cpp"
    break;

  case 351: // GeneralData: FormulaData
#line 2436 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < FormulaData::Ptr > ());
  }
#line 5545 "GrammarParser.cpp"
    break;

  case 352: // GeneralFunction: AtomicWord "(" GeneralTerms ")"
#line 2443 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5553 "GrammarParser.cpp"
    break;

  case 353: // GeneralTerms: GeneralTerm
#line 2450 "../../obj/src/GrammarParser.yy"
  {
=======
#line 5098 "GrammarParser.cpp"
    break;

  case 340:
#line 2392 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5106 "GrammarParser.cpp"
    break;

  case 341:
#line 2396 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > (), Identifier::Kind::NUMBER);
  }
#line 5114 "GrammarParser.cpp"
    break;

  case 342:
#line 2403 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < Role::Ptr > () = libtptp::make< Role >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 5122 "GrammarParser.cpp"
    break;

  case 343:
#line 2410 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralData::Ptr > ();
  }
#line 5130 "GrammarParser.cpp"
    break;

  case 344:
#line 2414 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as < GeneralData::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralTerm::Ptr > ());
  }
#line 5138 "GrammarParser.cpp"
    break;

  case 345:
#line 2418 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralList::Ptr > ();
  }
#line 5146 "GrammarParser.cpp"
    break;

  case 346:
#line 2425 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 5154 "GrammarParser.cpp"
    break;

  case 347:
#line 2429 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < GeneralFunction::Ptr > ());
  }
#line 5162 "GrammarParser.cpp"
    break;

  case 348:
#line 2433 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 5170 "GrammarParser.cpp"
    break;

  case 349:
#line 2437 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5178 "GrammarParser.cpp"
    break;

  case 350:
#line 2441 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5186 "GrammarParser.cpp"
    break;

  case 351:
#line 2445 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < FormulaData::Ptr > ());
  }
#line 5194 "GrammarParser.cpp"
    break;

  case 352:
#line 2452 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5202 "GrammarParser.cpp"
    break;

  case 353:
#line 2459 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < GeneralTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
<<<<<<< HEAD
#line 5563 "GrammarParser.cpp"
    break;

  case 354: // GeneralTerms: GeneralTerms "," GeneralTerm
#line 2456 "../../obj/src/GrammarParser.yy"
  {
=======
#line 5212 "GrammarParser.cpp"
    break;

  case 354:
#line 2465 "../../obj/src/GrammarParser.yy"
    {
>>>>>>> 508276a (GrammarParser: commmit built files)
    auto terms = yystack_[2].value.as < ListNodeElements::Ptr > ();
    terms->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralTerm::Ptr > ());
    yylhs.value.as < ListNodeElements::Ptr > () = terms;
  }
<<<<<<< HEAD
#line 5573 "GrammarParser.cpp"
    break;

  case 355: // FormulaData: "$" "thf" "(" ThfFormula ")"
#line 2465 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5581 "GrammarParser.cpp"
    break;

  case 356: // FormulaData: "$" "tff" "(" TffFormula ")"
#line 2469 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5589 "GrammarParser.cpp"
    break;

  case 357: // FormulaData: "$" "fof" "(" FofFormula ")"
#line 2473 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5597 "GrammarParser.cpp"
    break;

  case 358: // FormulaData: "$" "cnf" "(" CnfFormula ")"
#line 2477 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5605 "GrammarParser.cpp"
    break;

  case 359: // FormulaData: "$" "fot" "(" FofTerm ")"
#line 2481 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Term::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5613 "GrammarParser.cpp"
    break;

  case 360: // GeneralList: "[" "]"
#line 2488 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5622 "GrammarParser.cpp"
    break;

  case 361: // GeneralList: "[" GeneralTerms "]"
#line 2493 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5631 "GrammarParser.cpp"
    break;

  case 362: // IncludeDefinition: "include" "(" FileName ")" "."
#line 2502 "../../obj/src/GrammarParser.yy"
  {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5640 "GrammarParser.cpp"
    break;

  case 363: // IncludeDefinition: "include" "(" FileName "," FormulaSelection ")" "."
#line 2507 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < ListLiteral::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5648 "GrammarParser.cpp"
    break;

  case 364: // FormulaSelection: "[" NameList "]"
#line 2514 "../../obj/src/GrammarParser.yy"
  {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < ListLiteral::Ptr > () = list;
  }
#line 5657 "GrammarParser.cpp"
    break;

  case 365: // AtomicWord: LowerWordLiteral
#line 2522 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5665 "GrammarParser.cpp"
    break;

  case 366: // AtomicWord: SingleQuotedLiteral
#line 2526 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5673 "GrammarParser.cpp"
    break;

  case 367: // AtomicDefinedWord: DollarWordLiteral
#line 2533 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5681 "GrammarParser.cpp"
    break;

  case 368: // AtomicSystemWord: DollarDollarWordLiteral
#line 2540 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5689 "GrammarParser.cpp"
    break;

  case 369: // Number: IntegerLiteral
#line 2547 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < IntegerLiteral::Ptr > ();
  }
#line 5697 "GrammarParser.cpp"
    break;

  case 370: // Number: RealLiteral
#line 2551 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RealLiteral::Ptr > ();
  }
#line 5705 "GrammarParser.cpp"
    break;

  case 371: // Number: RationalLiteral
#line 2555 "../../obj/src/GrammarParser.yy"
  {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RationalLiteral::Ptr > ();
  }
#line 5713 "GrammarParser.cpp"
    break;

  case 372: // FileName: SingleQuotedLiteral
#line 2562 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5721 "GrammarParser.cpp"
    break;

  case 373: // IntegerLiteral: "integer"
#line 2569 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as < std::string > ());
  }
#line 5729 "GrammarParser.cpp"
    break;

  case 374: // RealLiteral: "real"
#line 2576 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5737 "GrammarParser.cpp"
    break;

  case 375: // RationalLiteral: "rational"
#line 2582 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5745 "GrammarParser.cpp"
    break;

  case 376: // Variable: "upper_word"
#line 2589 "../../obj/src/GrammarParser.yy"
  {
	auto identifier = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
	yylhs.value.as < VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 5754 "GrammarParser.cpp"
    break;

  case 377: // DistinctObjectLiteral: "double_quoted"
#line 2597 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < DistinctObjectLiteral::Ptr > () = libtptp::make< DistinctObjectLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5762 "GrammarParser.cpp"
    break;

  case 378: // LowerWordLiteral: "lower_word"
#line 2604 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5770 "GrammarParser.cpp"
    break;

  case 379: // SingleQuotedLiteral: "single_quoted"
#line 2611 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5778 "GrammarParser.cpp"
    break;

  case 380: // DollarWordLiteral: "$" "lower_word"
#line 2618 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5786 "GrammarParser.cpp"
    break;

  case 381: // DollarDollarWordLiteral: "$$" "lower_word"
#line 2625 "../../obj/src/GrammarParser.yy"
  {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5794 "GrammarParser.cpp"
    break;


#line 5798 "GrammarParser.cpp"
=======
#line 5222 "GrammarParser.cpp"
    break;

  case 355:
#line 2474 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5230 "GrammarParser.cpp"
    break;

  case 356:
#line 2478 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5238 "GrammarParser.cpp"
    break;

  case 357:
#line 2482 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5246 "GrammarParser.cpp"
    break;

  case 358:
#line 2486 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5254 "GrammarParser.cpp"
    break;

  case 359:
#line 2490 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Term::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5262 "GrammarParser.cpp"
    break;

  case 360:
#line 2497 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5271 "GrammarParser.cpp"
    break;

  case 361:
#line 2502 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5280 "GrammarParser.cpp"
    break;

  case 362:
#line 2511 "../../obj/src/GrammarParser.yy"
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5289 "GrammarParser.cpp"
    break;

  case 363:
#line 2516 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < ListLiteral::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5297 "GrammarParser.cpp"
    break;

  case 364:
#line 2523 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < ListLiteral::Ptr > () = list;
  }
#line 5306 "GrammarParser.cpp"
    break;

  case 365:
#line 2531 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5314 "GrammarParser.cpp"
    break;

  case 366:
#line 2535 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5322 "GrammarParser.cpp"
    break;

  case 367:
#line 2542 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5330 "GrammarParser.cpp"
    break;

  case 368:
#line 2549 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5338 "GrammarParser.cpp"
    break;

  case 369:
#line 2556 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < IntegerLiteral::Ptr > ();
  }
#line 5346 "GrammarParser.cpp"
    break;

  case 370:
#line 2560 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RealLiteral::Ptr > ();
  }
#line 5354 "GrammarParser.cpp"
    break;

  case 371:
#line 2564 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RationalLiteral::Ptr > ();
  }
#line 5362 "GrammarParser.cpp"
    break;

  case 372:
#line 2571 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5370 "GrammarParser.cpp"
    break;

  case 373:
#line 2578 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as < std::string > ());
  }
#line 5378 "GrammarParser.cpp"
    break;

  case 374:
#line 2585 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5386 "GrammarParser.cpp"
    break;

  case 375:
#line 2591 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5394 "GrammarParser.cpp"
    break;

  case 376:
#line 2598 "../../obj/src/GrammarParser.yy"
    {
	auto identifier = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
	yylhs.value.as < VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 5403 "GrammarParser.cpp"
    break;

  case 377:
#line 2606 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DistinctObjectLiteral::Ptr > () = libtptp::make< DistinctObjectLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5411 "GrammarParser.cpp"
    break;

  case 378:
#line 2613 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5419 "GrammarParser.cpp"
    break;

  case 379:
#line 2620 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5427 "GrammarParser.cpp"
    break;

  case 380:
#line 2627 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5435 "GrammarParser.cpp"
    break;

  case 381:
#line 2634 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5443 "GrammarParser.cpp"
    break;


#line 5447 "GrammarParser.cpp"
>>>>>>> 508276a (GrammarParser: commmit built files)

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Parser::yypact_ninf_ = -585;

  const short Parser::yytable_ninf_ = -327;

  const short
  Parser::yypact_[] =
  {
     489,    37,   129,   147,   162,   164,   185,   199,   274,   489,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,   385,
     385,   385,   385,   385,   385,   227,  -585,  -585,  -585,  -585,
    -585,   275,  -585,  -585,  -585,   291,   302,   316,   338,   347,
      38,  -585,   308,   308,   308,   308,   308,   308,   373,   350,
     396,  -585,   398,   410,   465,   487,   491,   385,   418,  -585,
     817,  1425,  1979,  2319,   817,  1005,   211,  -585,   452,   455,
     458,   817,  1883,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,   225,  -585,  -585,  -585,  -585,  -585,   530,   557,   289,
    -585,  1311,   344,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
     107,  -585,  -585,   110,   424,   439,  -585,  -585,   529,   585,
    2125,  -585,   574,  -585,   577,  -585,   593,  -585,  -585,  -585,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,   130,
    1122,   933,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,  -585,   314,  -585,  -585,  -585,  -585,   591,   611,   610,
     772,  1099,  -585,   212,  -585,  -585,   514,  -585,  -585,   415,
    -585,  -585,  -585,  -585,   439,   579,  -585,   204,  -585,  -585,
     599,   613,  -585,  -585,   633,  -585,  -585,  1705,  -585,  -585,
    -585,   118,   175,   644,   180,   650,  -585,   658,  -585,   564,
     215,  1979,   830,   441,  -585,  -585,  -585,  -585,   642,   676,
    1358,   367,  -585,  -585,   383,  -585,  -585,   619,  -585,  -585,
    -585,   401,  -585,  -585,  -585,   439,   640,  -585,  -585,  -585,
     673,   902,   229,   175,   685,   180,   691,  -585,   694,  -585,
     622,  1261,   696,   995,  -585,   498,  -585,  -585,  -585,  -585,
    -585,   699,  -585,   713,   723,   735,   515,  1176,   522,   385,
    -585,  -585,  -585,  -585,   729,   730,  2125,  -585,  -585,   125,
    1356,   737,  2125,  2125,  2125,  2125,  -585,  -585,  -585,  -585,
    -585,  -585,  2125,  -585,  -585,   995,  -585,   995,   741,   718,
    -585,  -585,  -585,   995,   995,   995,   756,   757,  -585,  -585,
     740,   758,   765,   766,  1705,  -585,  -585,   777,  -585,  2546,
    -585,  -585,  -585,   259,  -585,  -585,  1356,   776,  1821,  1821,
    1821,  1821,  1821,  1821,  1821,   679,   679,   771,   768,   768,
     768,   768,   768,   718,  2546,  -585,  -585,  -585,  -585,  -585,
    1821,    74,  1821,  1821,  1821,   775,   783,   785,   789,   790,
    2238,  -585,  -585,  -585,   624,   292,  -585,  -585,   629,  1356,
     780,  2238,  2238,  2238,  2238,  2238,  1053,  1053,   782,   718,
    2238,  -585,  -585,  -585,  -585,  -585,   637,    74,  2238,  2238,
    2238,   188,    29,   718,  -585,   794,  1356,   797,  1176,  1356,
     810,  1356,   815,  -585,  -585,  -585,  2125,  -585,   609,  1340,
     811,   818,   820,  -585,  -585,  -585,   819,  -585,  -585,  -585,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,  -585,   331,  -585,   537,  -585,   539,   544,  1821,   507,
     648,  -585,  -585,  -585,  1821,  -585,   823,  -585,  -585,  -585,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  2546,  -585,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,   836,  -585,  -585,
    -585,   356,  -585,   824,   845,   610,   835,   841,  -585,   836,
    -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
     852,   857,   858,   860,  2238,   704,   657,  -585,  -585,  -585,
    2238,  -585,   867,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,  -585,  2238,  -585,  -585,  -585,  -585,  -585,   360,  -585,
    -585,   876,   872,   637,   637,   873,  -585,  -585,   869,   322,
    -585,  -585,  -585,   878,  -585,  -585,  -585,  -585,  -585,   556,
     572,   575,  -585,   363,   880,  -585,  -585,   881,  -585,   884,
    -585,  -585,   879,   890,   891,   892,   893,  -585,  -585,   386,
     901,   896,  1356,  1356,   718,   906,   995,  -585,  -585,  -585,
     908,   189,   189,   909,  -585,  -585,   910,   904,   718,   916,
    1821,  -585,  -585,  -585,  -585,   920,   188,   921,  -585,  -585,
     922,   923,   718,   927,   372,  -585,   936,   670,   571,  -585,
     403,   718,   372,   372,  -585,  -585,  -585,   929,   944,   960,
     961,  1425,  1979,   817,  1005,   995,  1356,  -585,  -585,  -585,
    -585,   580,  -585,  2125,  -585,  1821,   446,  -585,  2416,  -585,
    -585,  -585,  1821,  -585,  2238,   466,  -585,     7,  -585,  -585,
    -585,  2238,  -585,  -585,   372,  -585,   372,   637,  -585,   481,
    -585,  -585,   587,  1005,  -585,  -585,  -585,   957,   972,   973,
     982,   985,  -585,  -585,  -585,  1001,   189,  -585,   933,   889,
    1011,  -585,  -585,  1012,   188,  -585,   830,  -585,  1013,  -585,
     962,  -585,  -585,  -585,  -585,  -585,  1006,   372,  -585,  -585,
    -585,  -585,  -585,  -585,  -585,  1821,  -585,   889,  -585,   482,
    1821,  1425,  2238,  -585,   981,  -585,   484,   315,  2238,  2238,
    1187,  -585,  1010,  1821,  -585,  -585,  1015,  1016,   262,  -585,
    1017,  -585,  1193,  -585,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,  1193,  -585,  1018,  1014,  -585
  };

  const short
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     5,     7,     8,     9,    10,    11,    12,     6,     0,
       0,     0,     0,     0,     0,     0,     1,     3,   341,   378,
     379,     0,   340,   365,   366,     0,     0,     0,     0,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   342,     0,     0,     0,     0,     0,     0,     0,   362,
       0,     0,     0,     0,     0,     0,     0,   338,     0,     0,
       0,     0,     0,   309,   319,   310,   373,   374,   375,   377,
     376,     0,    27,   231,   233,   236,   237,   239,   240,   249,
     246,     0,   248,   250,   251,   256,   257,   260,   261,   258,
     259,   279,   268,   262,   264,     0,   276,   232,     0,     0,
       0,   265,   330,   272,   332,   270,   334,   267,   331,   335,
     333,   336,   369,   370,   371,   277,   337,   367,   368,     0,
       0,     0,   301,   300,   299,   304,   305,   306,   307,   308,
     297,   298,     0,    28,    34,    36,    37,    40,    41,    42,
       0,    49,    54,    50,    62,    63,    55,    66,    67,    51,
      68,    69,    73,    74,     0,    71,    29,     0,    38,   112,
     113,   114,    30,    31,     0,   296,   295,     0,   303,   294,
     302,     0,    70,   330,    78,   332,    72,   334,    76,    56,
       0,     0,     0,     0,   124,   130,   132,   133,   135,   136,
       0,   141,   148,   146,   142,   157,   158,   147,   161,   162,
     166,   143,   163,   169,   170,     0,   192,   125,   126,   127,
       0,     0,     0,   164,   330,   172,   332,   167,   334,   191,
     150,     0,     0,     0,   227,     0,   226,   228,   293,   291,
     229,   287,   289,     0,   265,   272,     0,     0,     0,     0,
     364,   363,   380,   381,     0,     0,     0,   283,   285,     0,
       0,     0,     0,     0,     0,     0,   311,   312,   313,   314,
     315,   316,     0,   328,   329,     0,   327,     0,     0,     0,
     249,   245,   248,     0,     0,     0,     0,     0,   318,   317,
       0,     0,     0,     0,   103,   100,   101,     0,   102,     0,
      96,    98,    71,     0,    70,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    52,    53,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   195,   187,   197,   189,     0,   164,   172,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   144,   145,   147,   150,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,   339,   252,   282,     0,   284,     0,     0,
       0,    25,   343,   347,   351,   345,   346,   349,   348,   350,
      23,   242,   244,   243,   241,   238,   278,   269,   280,   263,
     247,   281,     0,   254,     0,   274,     0,     0,     0,     0,
      57,    75,   106,   123,     0,    97,     0,    13,    44,    49,
      50,    51,    46,    48,    47,    45,    43,    39,     0,    93,
      77,    94,    65,   122,   110,   119,   117,   115,   116,   118,
     120,     0,    59,     0,     0,   111,     0,   110,   105,   107,
     109,   108,   121,   323,   325,   330,   326,   332,   324,   334,
     104,     0,     0,     0,     0,     0,   149,   200,   225,   192,
       0,   196,     0,    15,   138,   141,   142,   143,   140,   139,
     137,   134,     0,   190,   171,   193,   160,   224,     0,   152,
     154,   155,     0,     0,     0,     0,   199,   203,     0,   201,
     202,   214,   210,   320,   211,   321,   322,   213,   223,     0,
       0,     0,   288,     0,     0,    17,   290,     0,    19,     0,
      21,   286,     0,     0,     0,     0,     0,   360,   353,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   273,   271,
       0,     0,     0,     0,    84,    99,     0,     0,     0,     0,
       0,    57,    79,    81,    80,     0,     0,     0,   176,   198,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   221,
       0,     0,     0,     0,   165,   173,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,    24,    26,
     344,     0,   255,     0,   275,     0,     0,    86,     0,    14,
      95,    60,     0,    61,     0,     0,   178,     0,    16,   194,
     153,     0,   156,   204,     0,   209,     0,     0,   220,     0,
     217,   215,     0,     0,    18,    20,    22,     0,     0,     0,
       0,     0,   354,   352,   253,     0,     0,    85,     0,     0,
       0,    88,    58,     0,     0,   177,     0,   183,     0,   180,
       0,   184,   151,   218,   219,   222,     0,     0,   212,   230,
     355,   356,   357,   358,   359,     0,    87,    98,    91,     0,
       0,     0,     0,   179,   161,   185,     0,   189,     0,     0,
       0,   216,     0,     0,    89,    90,     0,     0,     0,   181,
       0,   182,     0,   205,   206,    82,    92,    83,   174,   186,
     175,     0,   208,     0,     0,   207
  };

  const short
  Parser::yypgoto_[] =
  {
    -585,  -585,  -585,  1025,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,    23,  -585,  -555,   -17,  -585,  -585,  -585,  -585,  -585,
    -280,  -214,  -585,  -165,  -585,  -585,   477,  -207,  -126,  -585,
     366,  -585,  -585,   461,  -585,  -585,  -585,  -585,  -585,  -585,
    -585,  -578,  -585,   389,   -45,  -123,  -585,   391,  -116,   485,
    -238,  -585,  -585,  -277,  -585,  -585,  -585,   912,   456,    -2,
    -585,  -585,  -585,  -585,  -585,  -243,  -585,  -179,  -585,  -585,
    -343,   475,  -585,  -234,   837,  -585,  -198,  -531,  -585,  -585,
    -135,  -585,  -585,  -585,  -585,  -585,  -585,  -584,  -585,  -585,
    -272,   375,    98,   111,   -52,  -437,  -585,  -585,  -468,   140,
    -585,   355,  -585,  -585,  -585,  -585,   883,  -585,  -585,  -585,
     -44,   -43,  -585,  -585,  -585,  -585,  -585,  -101,   -46,   -85,
     -70,  -585,  -585,   -50,  -585,  -585,  -585,  -585,  -585,  -251,
    -585,  -585,  -236,  -221,   464,  -206,  -585,   998,   792,  -585,
     -47,  -173,   698,  -585,  -585,  -585,   -93,  -585,   834,     0,
    -585,  2059,  -585,  -585,  -585,   714,   -40,   -91,   -84,   -77,
     390,   646,  1022,  1278,  1534,  1715,  1887,  -585,   453,   813,
    -344,  -585,  -585,   546,  -585,   550,  -585,  -585,   -19,  -233,
    -585,  -167,  -585,  -585,  -585,  -585,   -55,    33,   907,  1055,
    -585,  -585
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   390,    81,   142,   301,   144,   145,   146,   147,   148,
     149,   150,   325,   151,   152,   451,   452,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   553,   606,
     650,   651,   679,   164,   302,   470,   291,   471,   166,   458,
     167,   460,   168,   169,   170,   171,   172,   173,   193,   342,
     195,   196,   197,   198,   199,   200,   361,   201,   202,   203,
     498,   499,   500,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   567,   615,   658,   659,   660,   686,
     343,   215,   479,   345,   338,   506,   507,   703,   508,   509,
     632,   510,   578,   511,   580,   218,   219,   235,   236,   237,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   412,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   414,   105,   106,   107,   108,   259,
     240,   241,   242,   174,   175,   176,   177,   178,   179,   295,
     296,   180,   512,   513,   514,   462,   243,   275,   276,   277,
     304,   183,   305,   185,   186,   187,   188,    66,    31,    50,
     391,   392,   393,   539,   394,   395,    18,    58,   118,   119,
     120,   121,    40,   122,   123,   124,   125,   126,    33,    34,
     127,   128
  };

  const short
  Parser::yytable_[] =
  {
      32,    32,    32,    32,    32,    32,   189,   230,   303,   280,
     217,   234,   326,   239,   292,   239,   165,   238,   248,   238,
     246,   181,   222,   364,   406,   281,   406,   375,   254,   258,
     523,   656,   406,   406,   406,   577,   637,   294,    32,   407,
     282,   407,   362,   448,   143,   538,   298,   407,   407,   407,
     455,   327,   522,   461,   408,    48,   408,   378,   372,    19,
     194,    49,   408,   408,   408,    29,   576,   579,    30,   409,
     678,   410,   685,   315,   372,   189,   189,   415,   415,   415,
     445,   446,   447,   449,   450,   165,   657,   316,    69,    70,
     297,   272,   459,   397,   428,   432,   433,   434,   435,   436,
     437,   430,   430,   430,   430,   430,   430,   430,   484,   488,
     489,   490,   491,   290,   709,   706,   456,   486,   486,   486,
     486,   486,   329,   430,   356,   684,   696,  -278,  -278,   326,
    -269,  -269,    29,   516,   330,    30,   230,   230,   357,   397,
     286,   287,   386,   429,   429,   429,   429,   429,   429,   429,
     314,    20,   387,   444,   444,   444,   444,   444,   493,   493,
     216,   280,   280,   280,   280,   457,   365,   657,   327,    21,
     331,   280,   485,   485,   485,   485,   485,   401,   402,   403,
     404,   239,   397,   374,    22,   238,    23,   405,   252,   337,
     665,  -325,   282,   282,   282,   282,  -326,   239,   600,   538,
     355,   238,   282,    70,    70,   398,   294,    24,   569,   397,
     371,   551,   397,   254,   397,   298,   487,   487,   487,   487,
     487,    25,   397,   318,   413,   335,   336,  -325,   249,   -33,
      32,   294,  -326,   319,   320,   -33,   250,   -33,   629,   329,
     298,   396,   260,   714,   189,   366,    29,    29,   261,    30,
      30,   398,   642,   189,   189,   189,   189,   189,   189,   189,
     441,   441,   -33,   329,   329,   329,   329,   329,   453,   189,
     516,   516,   443,   252,    26,   189,   424,   189,   189,   189,
     455,   367,   290,   461,   425,   230,   192,   396,    30,   216,
     344,   463,    42,   399,   398,   406,   230,   230,   230,   230,
     230,   495,   495,   554,   501,   230,  -234,   454,    43,   480,
     407,   517,  -234,   230,   230,   230,  -234,   481,   501,    44,
      29,   398,   459,    30,   398,   408,   398,   463,   239,   426,
     396,   306,   238,    45,   398,  -192,  -192,   307,   337,   399,
     604,   516,   653,   531,   406,   294,   456,   515,   544,   516,
     516,  -208,  -208,   430,   298,    46,   545,   396,   502,   407,
     396,  -235,   396,   189,    47,  -184,    29,  -235,    59,   189,
     396,  -235,   482,   558,   408,   397,   397,   572,   662,   297,
     572,   559,   399,   189,  -128,   573,    69,   486,   587,   641,
    -128,   516,  -128,   516,   516,   457,   504,    57,   652,   524,
    -129,   550,   527,   596,   529,   430,  -129,   555,  -129,   399,
     697,   597,   399,    60,   399,    61,   700,   701,  -131,   230,
     627,   557,   399,   568,  -131,   230,  -131,    62,   628,   397,
      29,    80,   -35,    30,   516,   292,   607,   230,   -35,    28,
     -35,    68,   485,    29,  -280,  -280,    30,   429,   517,   517,
     111,   182,   223,   244,   111,   111,   497,   516,   349,   273,
     274,   111,   111,   646,   350,   -35,   344,   344,   344,   516,
     251,   647,   565,    35,    36,    37,    38,    39,   516,   519,
     520,   521,    63,   654,   515,   515,   487,   398,   398,   602,
     571,   655,     1,     2,     3,     4,     5,     6,   572,   693,
     111,   698,   280,   453,    64,   189,   666,   694,    65,   699,
      67,   297,   297,   252,   616,   376,   253,   501,   644,   517,
     182,   377,    70,   396,   396,   303,   501,   517,   517,   551,
     676,   552,   379,   282,   -93,   -93,   189,   230,   380,   381,
     217,   398,     7,   328,   239,   382,   165,   640,   238,   639,
     189,   181,   222,   189,   546,   515,   546,   189,   262,   230,
     547,   546,   548,   515,   515,    29,   230,   549,    30,   517,
     263,   517,   517,   480,   143,   399,   399,   396,   344,   584,
     278,   223,   346,   239,   -94,   -94,   669,   238,   645,   480,
     194,   649,   480,   189,   625,   585,   283,   596,   586,   284,
     626,   230,   683,   643,   667,   515,   297,   515,   515,   279,
     668,   346,   517,   532,   533,   285,   534,   535,   536,   308,
     189,   244,   310,   111,   309,   189,   189,   230,   321,   399,
     317,   677,   322,   230,   230,   517,   165,   111,   189,  -190,
    -190,   181,  -193,  -193,  -192,  -192,   111,   517,   515,  -191,
    -191,    69,   111,   111,   111,   111,   517,   323,   692,   503,
     328,   504,   111,   695,   143,   111,   332,   111,   -95,   -95,
     351,   515,   333,   111,   111,   111,   649,  -194,  -194,   505,
     334,   439,   439,   515,   328,   328,   328,   328,   328,   352,
     216,   358,   515,   129,    70,    29,    80,   359,    30,   624,
     582,   438,   383,   131,   440,   442,   112,   368,   224,   112,
     112,   112,   344,   369,   622,   661,   370,   112,   112,    70,
     373,   464,   630,   631,   472,   473,   371,   378,   566,   366,
     346,   494,   496,    76,    77,    78,    79,    29,    80,  -325,
      30,   346,   346,   346,   346,   346,   346,   346,   416,   417,
     346,  -326,   384,   385,   687,   400,   112,   464,   346,   346,
     346,   464,    29,   420,   663,    30,   664,    72,   111,   431,
     431,   431,   431,   431,   431,   431,   111,    80,   418,   419,
     344,   421,   129,    70,   311,   312,   344,   344,   422,   423,
     324,   431,   131,   330,   427,   131,   661,   474,   483,    73,
     313,    75,   132,   133,   134,   475,   192,   691,   476,   464,
     140,   141,   477,   478,   273,   525,   266,   267,   268,   269,
     270,   271,    76,    77,    78,    79,    29,    80,   528,    30,
     704,    69,    70,   530,   540,   541,   542,   224,   224,    71,
     560,   543,   712,    72,   190,    70,   556,   311,    73,    74,
      75,   712,   340,   -49,   192,   341,    52,    53,    54,    55,
      56,    73,    74,    75,   346,   464,   320,   224,   561,   424,
     346,    76,    77,    78,    79,    29,    80,   112,    30,   112,
     562,   563,   346,   564,    76,    77,    78,    79,    29,    80,
     570,    30,   574,   112,   109,   575,   220,   581,   109,   582,
     583,   591,   112,   588,   589,   109,   109,   590,   112,   112,
     112,   112,   592,   593,   594,   595,   190,    70,   112,   598,
     389,   112,   603,   112,   360,   605,   608,   610,   609,   112,
     112,   112,   612,    73,    74,    75,   111,   614,   617,   680,
     618,   464,   464,   621,   109,   633,   619,   129,    70,    51,
      51,    51,    51,    51,    51,   299,   464,   131,   300,   623,
      29,    80,   634,    30,    73,    74,    75,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   465,   635,   636,
     670,   182,   223,   111,   111,   111,   224,    76,    77,    78,
      79,    29,    80,   111,    30,   671,   672,   224,   224,   224,
     224,   224,   224,   224,   346,   673,   224,   346,   674,    69,
      70,   346,   689,   465,   224,   224,   224,   465,   675,    69,
      70,   431,   690,   111,   112,   220,   220,   247,   681,   682,
     688,  -183,   112,   705,    27,   611,   464,   233,   707,   708,
     710,   715,   293,   624,   464,   613,   346,   620,   638,    76,
      77,    78,    79,    29,    80,   220,    30,   713,   363,    76,
      77,    78,    79,    29,    80,   465,    30,   190,    70,   255,
     411,   182,   346,   431,   339,   492,   526,   192,   346,   346,
      41,   518,   113,   184,   225,   245,   113,   113,   346,   601,
     109,   599,     0,   113,   113,     0,   109,   109,   109,   109,
       0,     0,     0,     0,     0,     0,   109,    76,    77,    78,
      79,    29,    80,     0,    30,     0,   -32,     0,  -110,     0,
     224,   465,   -32,     0,   -32,     0,   224,     0,  -110,  -110,
       0,     0,   113,     0,     0,   288,   129,    70,   224,     0,
       0,     0,   273,     0,   130,     0,   131,     0,     0,   -32,
     289,     0,   184,    73,    74,    75,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   266,   267,   268,   269,
     270,   271,     0,     0,   220,     0,    76,    77,    78,    79,
      29,    80,     0,    30,     0,   220,   220,   220,   220,   220,
      69,    70,   112,     0,   220,     0,     0,   465,   465,     0,
       0,    69,   220,   220,   220,     0,     0,    69,   233,   702,
       0,   504,   465,   225,   347,   711,     0,   504,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    29,    80,     0,    30,   224,   112,
     112,   112,     0,   347,     0,    29,    80,     0,    30,   112,
       0,    29,    80,   245,    30,   113,     0,     0,     0,     0,
     224,     0,     0,   224,     0,     0,     0,   224,     0,   113,
       0,     0,     0,     0,     0,    69,    70,     0,   113,   112,
       0,     0,     0,   371,   113,   113,   113,   113,     0,     0,
       0,     0,   465,   233,   113,     0,     0,   113,     0,   113,
     465,     0,   224,     0,     0,   113,   113,   113,   220,     0,
       0,     0,     0,     0,   220,    76,    77,    78,    79,    29,
      80,     0,    30,     0,   264,     0,   220,     0,   224,     0,
       0,     0,     0,     0,   224,   224,     0,     0,   114,   265,
     226,   114,   114,   114,   224,     0,     0,     0,     0,   114,
     114,     0,     0,   466,   388,   266,   267,   268,   269,   270,
     271,     0,   347,     0,   389,   537,     0,     0,     0,     0,
     388,   353,     0,   347,   347,   347,   347,   347,   347,   347,
     389,     0,   347,     0,     0,     0,   354,     0,   114,   466,
     347,   347,   347,   466,    76,    77,    78,    79,    29,    80,
     113,    30,   266,   267,   268,   269,   270,   271,   113,     0,
      76,    77,    78,    79,    29,    80,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,   129,
      70,   466,     0,     0,     0,     0,     0,   130,   220,   131,
       0,     0,     0,     0,     0,   220,    73,    74,    75,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   226,
     226,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    29,    80,     0,    30,     0,     0,     0,
     220,     0,     0,     0,     0,     0,   347,   466,     0,   226,
       0,     0,   347,     0,     0,     0,     0,     0,     0,   114,
       0,   114,     0,     0,   347,     0,   220,     0,     0,     0,
       0,     0,   220,   220,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     0,     0,     0,
     114,   114,   114,   114,     0,     0,     0,     0,     0,     0,
     114,     0,     0,   114,     0,   114,     0,     0,     0,     0,
       0,   114,   114,   114,     0,     0,     0,     0,   113,     0,
       0,     0,     0,   466,   466,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,     0,
       0,     0,     0,     0,   115,     0,   227,   115,   115,   115,
       0,     0,     0,     0,     0,   115,   115,     0,     0,   467,
       0,     0,     0,   184,   225,   113,   113,   113,   226,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,   226,
     226,   226,   226,   226,   226,   226,   347,     0,   226,     0,
       0,     0,     0,   347,   115,   467,   226,   226,   226,   467,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     0,   466,     0,
       0,     0,     0,     0,     0,     0,   466,     0,   347,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   467,     0,     0,
       0,     0,     0,   184,   347,     0,     0,     0,     0,     0,
     347,   347,     0,     0,     0,     0,     0,     0,     0,   129,
      70,     0,     0,     0,     0,   227,   227,   324,     0,   131,
       0,     0,     0,     0,     0,     0,    73,    74,    75,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,   226,   467,     0,   227,     0,     0,   226,    76,
      77,    78,    79,    29,    80,   115,    30,   115,     0,     0,
     226,     0,     0,     0,     0,   116,     0,   228,   116,   116,
     116,   115,     0,     0,     0,     0,   116,   116,     0,     0,
     115,     0,     0,     0,     0,     0,   115,   115,   115,   115,
       0,     0,     0,     0,     0,     0,   115,     0,     0,   115,
       0,   115,     0,     0,     0,     0,     0,   115,   115,   115,
       0,     0,     0,     0,   114,   116,     0,     0,     0,   467,
     467,     0,     0,     0,     0,   129,    70,     0,     0,     0,
       0,     0,     0,   299,   467,   131,     0,     0,     0,     0,
       0,     0,    73,    74,    75,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   468,     0,     0,     0,     0,
     226,   114,   114,   114,   227,    76,    77,    78,    79,    29,
      80,   114,    30,     0,     0,   227,   227,   227,   227,   227,
     227,   227,   226,     0,   227,     0,     0,    69,    70,   226,
       0,   468,   227,   227,   227,   256,   228,   228,     0,     0,
     257,   114,   115,     0,    73,    74,    75,     0,     0,     0,
     115,     0,     0,     0,   467,     0,     0,     0,     0,     0,
       0,     0,   467,     0,   226,     0,   228,    76,    77,    78,
      79,    29,    80,     0,    30,     0,   116,   117,   116,   229,
     117,   117,   117,     0,     0,     0,     0,     0,   117,   117,
     226,     0,   116,     0,     0,     0,   226,   226,     0,     0,
       0,   116,     0,     0,     0,     0,     0,   116,   116,   116,
     116,     0,     0,     0,     0,     0,     0,   116,     0,     0,
     116,     0,   116,   190,    70,     0,     0,   117,   116,   116,
     116,   191,     0,   192,     0,     0,     0,     0,   227,     0,
      73,    74,    75,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    29,    80,     0,
      30,     0,     0,     0,     0,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   228,   228,   228,
     228,   228,   228,     0,     0,   228,     0,     0,   229,   348,
     115,     0,   469,   228,   228,   228,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   110,
     117,   221,     0,   110,     0,     0,   227,   115,   115,   115,
     110,   110,     0,     0,   117,     0,     0,   115,     0,    69,
      70,     0,     0,   117,     0,     0,     0,   256,   227,   117,
     117,   117,   117,     0,     0,   227,    73,    74,    75,   117,
       0,     0,   117,     0,   117,     0,     0,   115,     0,   110,
     117,   117,   117,     0,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    29,    80,     0,    30,     0,     0,   228,
     227,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,   227,   227,     0,     0,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   229,   229,
     229,   229,   229,   229,   229,     0,     0,   229,     0,     0,
     221,   221,   190,    70,     0,   348,   348,   348,     0,     0,
     340,   116,   192,     0,     0,   117,     0,     0,     0,    73,
      74,    75,     0,   117,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    29,    80,     0,    30,
       0,     0,     0,     0,     0,     0,     0,   228,   116,   116,
     116,     0,     0,     0,     0,   110,     0,     0,   116,     0,
       0,   110,   110,   110,   110,     0,     0,     0,     0,   228,
       0,   110,     0,    69,    70,     0,   228,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,   116,     0,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,   348,     0,     0,
       0,   228,     0,    76,    77,    78,    79,    29,    80,   229,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,   221,
       0,     0,     0,   228,   228,     0,     0,     0,     0,     0,
     221,   221,   221,   221,   221,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,   221,   221,   221,
     129,    70,     0,   117,     0,     0,     0,     0,   299,     0,
     648,     0,     0,     0,     0,   110,     0,    73,    74,    75,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    29,    80,     0,    30,     0,   229,
     117,   117,   117,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,   221,
       0,     0,     0,   348,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,   288,
     129,    70,     0,     0,     0,     0,   273,     0,   299,   348,
     131,     0,     0,     0,   289,   348,   348,    73,    74,    75,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     266,   267,   268,   269,   270,   271,     0,     0,     0,     0,
      76,    77,    78,    79,    29,    80,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,   221,   221
  };

  const short
  Parser::yycheck_[] =
  {
      19,    20,    21,    22,    23,    24,    61,    62,   131,   110,
      62,    63,   177,    63,   130,    65,    61,    63,    65,    65,
      64,    61,    62,   221,   275,   110,   277,   233,    71,    72,
     373,    24,   283,   284,   285,   503,   591,   130,    57,   275,
     110,   277,   221,   320,    61,   389,   130,   283,   284,   285,
     330,   177,    23,   330,   275,    17,   277,    28,   231,    22,
      62,    23,   283,   284,   285,    58,   503,   504,    61,   275,
     648,   277,   656,   164,   247,   130,   131,   283,   284,   285,
     318,   319,   320,   321,   322,   130,   617,   164,    14,    15,
     130,    91,   330,   260,   308,   309,   310,   311,   312,   313,
     314,   308,   309,   310,   311,   312,   313,   314,   351,   352,
     353,   354,   355,   130,   698,   693,   330,   351,   352,   353,
     354,   355,   177,   330,   215,   656,   681,    20,    21,   294,
      20,    21,    58,   366,    16,    61,   191,   192,   215,   306,
      10,    11,    17,   308,   309,   310,   311,   312,   313,   314,
     150,    22,    27,   318,   319,   320,   321,   322,   356,   357,
      62,   262,   263,   264,   265,   330,   221,   698,   294,    22,
      52,   272,   351,   352,   353,   354,   355,   262,   263,   264,
     265,   231,   349,   233,    22,   231,    22,   272,    58,   191,
     627,    16,   262,   263,   264,   265,    16,   247,   542,   543,
     200,   247,   272,    15,    15,   260,   299,    22,   480,   376,
      22,    22,   379,   256,   381,   299,   351,   352,   353,   354,
     355,    22,   389,    19,   279,    10,    11,    52,    17,    17,
     249,   324,    52,    29,    30,    23,    25,    25,   581,   294,
     324,   260,    17,   711,   299,    16,    58,    58,    23,    61,
      61,   306,   596,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    50,   318,   319,   320,   321,   322,   323,   324,
     503,   504,   317,    58,     0,   330,    17,   332,   333,   334,
     560,    52,   299,   560,    25,   340,    24,   306,    61,   191,
     192,   331,    17,   260,   349,   546,   351,   352,   353,   354,
     355,   356,   357,   419,   359,   360,    17,   324,    17,    17,
     546,   366,    23,   368,   369,   370,    27,    25,   373,    17,
      58,   376,   560,    61,   379,   546,   381,   367,   378,   306,
     349,    17,   378,    17,   389,    20,    21,    23,   340,   306,
     546,   574,   614,   386,   595,   438,   560,   366,    17,   582,
     583,    29,    30,   560,   438,    17,    25,   376,   360,   595,
     379,    17,   381,   418,    17,    50,    58,    23,    18,   424,
     389,    27,   349,    17,   595,   542,   543,    17,   621,   419,
      17,    25,   349,   438,    17,    25,    14,   621,    25,   595,
      23,   624,    25,   626,   627,   560,    24,    24,   612,   376,
      17,   418,   379,    17,   381,   612,    23,   424,    25,   376,
     682,    25,   379,    17,   381,    17,   688,   689,    17,   474,
      17,   438,   389,   475,    23,   480,    25,    17,    25,   596,
      58,    59,    17,    61,   667,   551,   552,   492,    23,    54,
      25,    23,   621,    58,    20,    21,    61,   612,   503,   504,
      60,    61,    62,    63,    64,    65,   358,   690,    17,    20,
      21,    71,    72,    17,    23,    50,   368,   369,   370,   702,
      18,    25,   474,    20,    21,    22,    23,    24,   711,   368,
     369,   370,    17,    17,   503,   504,   621,   542,   543,   544,
     492,    25,     3,     4,     5,     6,     7,     8,    17,    17,
     110,    17,   603,   558,    17,   560,    25,    25,    17,    25,
      57,   551,   552,    58,   566,    17,    58,   572,   603,   574,
     130,    23,    15,   542,   543,   648,   581,   582,   583,    22,
     646,    24,    17,   603,    20,    21,   591,   592,    23,    17,
     592,   596,    53,   177,   594,    23,   591,   594,   594,   593,
     605,   591,   592,   608,    17,   574,    17,   612,    28,   614,
      23,    17,    23,   582,   583,    58,   621,    23,    61,   624,
      13,   626,   627,    17,   591,   542,   543,   596,   480,    23,
      51,   191,   192,   633,    20,    21,   633,   633,   605,    17,
     592,   608,    17,   648,    23,    23,    22,    17,    23,    22,
      29,   656,   654,    23,    17,   624,   646,   626,   627,    24,
      23,   221,   667,     4,     5,    22,     7,     8,     9,    28,
     675,   231,    12,   233,    13,   680,   681,   682,    29,   596,
      51,   648,    19,   688,   689,   690,   681,   247,   693,    20,
      21,   681,    20,    21,    20,    21,   256,   702,   667,    20,
      21,    14,   262,   263,   264,   265,   711,    24,   675,    22,
     294,    24,   272,   680,   681,   275,    22,   277,    20,    21,
      28,   690,    22,   283,   284,   285,   693,    20,    21,    42,
      22,   315,   316,   702,   318,   319,   320,   321,   322,    13,
     592,    51,   711,    14,    15,    58,    59,    24,    61,    29,
      30,    22,   249,    24,   315,   316,    60,    22,    62,    63,
      64,    65,   614,    22,   574,   617,    22,    71,    72,    15,
      24,   331,   582,   583,   333,   334,    22,    28,    24,    16,
     340,   356,   357,    54,    55,    56,    57,    58,    59,    16,
      61,   351,   352,   353,   354,   355,   356,   357,   284,   285,
     360,    16,    23,    23,   656,    18,   110,   367,   368,   369,
     370,   371,    58,    23,   624,    61,   626,    26,   378,   308,
     309,   310,   311,   312,   313,   314,   386,    59,    22,    22,
     682,    23,    14,    15,    12,    13,   688,   689,    23,    23,
      22,   330,    24,    16,    18,    24,   698,    22,    18,    31,
      28,    33,    34,    35,    36,    22,    24,   667,    23,   419,
      42,    43,    23,    23,    20,    18,    44,    45,    46,    47,
      48,    49,    54,    55,    56,    57,    58,    59,    18,    61,
     690,    14,    15,    18,    23,    17,    16,   191,   192,    22,
      16,    22,   702,    26,    14,    15,    23,    12,    31,    32,
      33,   711,    22,    12,    24,    25,    43,    44,    45,    46,
      47,    31,    32,    33,   474,   475,    30,   221,    23,    17,
     480,    54,    55,    56,    57,    58,    59,   231,    61,   233,
      23,    23,   492,    23,    54,    55,    56,    57,    58,    59,
      23,    61,    16,   247,    60,    23,    62,    24,    64,    30,
      22,    22,   256,    23,    23,    71,    72,    23,   262,   263,
     264,   265,    22,    22,    22,    22,    14,    15,   272,    18,
      24,   275,    16,   277,    22,    17,    17,    23,    18,   283,
     284,   285,    16,    31,    32,    33,   546,    17,    17,    50,
      18,   551,   552,    16,   110,    16,    23,    14,    15,    42,
      43,    44,    45,    46,    47,    22,   566,    24,    25,    23,
      58,    59,    18,    61,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   331,    18,    18,
      23,   591,   592,   593,   594,   595,   340,    54,    55,    56,
      57,    58,    59,   603,    61,    23,    23,   351,   352,   353,
     354,   355,   356,   357,   614,    23,   360,   617,    23,    14,
      15,   621,    50,   367,   368,   369,   370,   371,    17,    14,
      15,   560,    16,   633,   378,   191,   192,    22,    17,    17,
      17,    50,   386,    23,     9,   558,   646,    32,    23,    23,
      23,    23,   130,    29,   654,   560,   656,   572,   592,    54,
      55,    56,    57,    58,    59,   221,    61,   702,   221,    54,
      55,    56,    57,    58,    59,   419,    61,    14,    15,    71,
     278,   681,   682,   612,   191,    22,   378,    24,   688,   689,
      25,   367,    60,    61,    62,    63,    64,    65,   698,   543,
     256,   541,    -1,    71,    72,    -1,   262,   263,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,   272,    54,    55,    56,
      57,    58,    59,    -1,    61,    -1,    17,    -1,    19,    -1,
     474,   475,    23,    -1,    25,    -1,   480,    -1,    29,    30,
      -1,    -1,   110,    -1,    -1,    13,    14,    15,   492,    -1,
      -1,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,    50,
      28,    -1,   130,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,   340,    -1,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,   351,   352,   353,   354,   355,
      14,    15,   546,    -1,   360,    -1,    -1,   551,   552,    -1,
      -1,    14,   368,   369,   370,    -1,    -1,    14,    32,    22,
      -1,    24,   566,   191,   192,    22,    -1,    24,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,   592,   593,
     594,   595,    -1,   221,    -1,    58,    59,    -1,    61,   603,
      -1,    58,    59,   231,    61,   233,    -1,    -1,    -1,    -1,
     614,    -1,    -1,   617,    -1,    -1,    -1,   621,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,   256,   633,
      -1,    -1,    -1,    22,   262,   263,   264,   265,    -1,    -1,
      -1,    -1,   646,    32,   272,    -1,    -1,   275,    -1,   277,
     654,    -1,   656,    -1,    -1,   283,   284,   285,   474,    -1,
      -1,    -1,    -1,    -1,   480,    54,    55,    56,    57,    58,
      59,    -1,    61,    -1,    13,    -1,   492,    -1,   682,    -1,
      -1,    -1,    -1,    -1,   688,   689,    -1,    -1,    60,    28,
      62,    63,    64,    65,   698,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,   331,    14,    44,    45,    46,    47,    48,
      49,    -1,   340,    -1,    24,    25,    -1,    -1,    -1,    -1,
      14,    13,    -1,   351,   352,   353,   354,   355,   356,   357,
      24,    -1,   360,    -1,    -1,    -1,    28,    -1,   110,   367,
     368,   369,   370,   371,    54,    55,    56,    57,    58,    59,
     378,    61,    44,    45,    46,    47,    48,    49,   386,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   592,   593,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    14,
      15,   419,    -1,    -1,    -1,    -1,    -1,    22,   614,    24,
      -1,    -1,    -1,    -1,    -1,   621,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    -1,    -1,
     656,    -1,    -1,    -1,    -1,    -1,   474,   475,    -1,   221,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,   233,    -1,    -1,   492,    -1,   682,    -1,    -1,    -1,
      -1,    -1,   688,   689,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
     262,   263,   264,   265,    -1,    -1,    -1,    -1,    -1,    -1,
     272,    -1,    -1,   275,    -1,   277,    -1,    -1,    -1,    -1,
      -1,   283,   284,   285,    -1,    -1,    -1,    -1,   546,    -1,
      -1,    -1,    -1,   551,   552,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   566,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,   331,
      -1,    -1,    -1,   591,   592,   593,   594,   595,   340,    -1,
      -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,   351,
     352,   353,   354,   355,   356,   357,   614,    -1,   360,    -1,
      -1,    -1,    -1,   621,   110,   367,   368,   369,   370,   371,
      -1,    -1,    -1,    -1,    -1,   633,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   654,    -1,   656,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,
      -1,    -1,    -1,   681,   682,    -1,    -1,    -1,    -1,    -1,
     688,   689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,   191,   192,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,   474,   475,    -1,   221,    -1,    -1,   480,    54,
      55,    56,    57,    58,    59,   231,    61,   233,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,    64,
      65,   247,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,   262,   263,   264,   265,
      -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,   275,
      -1,   277,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,
      -1,    -1,    -1,    -1,   546,   110,    -1,    -1,    -1,   551,
     552,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,   566,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   331,    -1,    -1,    -1,    -1,
     592,   593,   594,   595,   340,    54,    55,    56,    57,    58,
      59,   603,    61,    -1,    -1,   351,   352,   353,   354,   355,
     356,   357,   614,    -1,   360,    -1,    -1,    14,    15,   621,
      -1,   367,   368,   369,   370,    22,   191,   192,    -1,    -1,
      27,   633,   378,    -1,    31,    32,    33,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   654,    -1,   656,    -1,   221,    54,    55,    56,
      57,    58,    59,    -1,    61,    -1,   231,    60,   233,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,
     682,    -1,   247,    -1,    -1,    -1,   688,   689,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   263,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,
     275,    -1,   277,    14,    15,    -1,    -1,   110,   283,   284,
     285,    22,    -1,    24,    -1,    -1,    -1,    -1,   474,    -1,
      31,    32,    33,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,   352,   353,   354,
     355,   356,   357,    -1,    -1,   360,    -1,    -1,   191,   192,
     546,    -1,   367,   368,   369,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    60,
     233,    62,    -1,    64,    -1,    -1,   592,   593,   594,   595,
      71,    72,    -1,    -1,   247,    -1,    -1,   603,    -1,    14,
      15,    -1,    -1,   256,    -1,    -1,    -1,    22,   614,   262,
     263,   264,   265,    -1,    -1,   621,    31,    32,    33,   272,
      -1,    -1,   275,    -1,   277,    -1,    -1,   633,    -1,   110,
     283,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    -1,   474,
     656,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   682,    -1,    -1,    -1,
      -1,    -1,   688,   689,    -1,    -1,    -1,   340,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,   352,
     353,   354,   355,   356,   357,    -1,    -1,   360,    -1,    -1,
     191,   192,    14,    15,    -1,   368,   369,   370,    -1,    -1,
      22,   546,    24,    -1,    -1,   378,    -1,    -1,    -1,    31,
      32,    33,    -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,   593,   594,
     595,    -1,    -1,    -1,    -1,   256,    -1,    -1,   603,    -1,
      -1,   262,   263,   264,   265,    -1,    -1,    -1,    -1,   614,
      -1,   272,    -1,    14,    15,    -1,   621,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,   633,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,   656,    -1,    54,    55,    56,    57,    58,    59,   492,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   682,    -1,   340,
      -1,    -1,    -1,   688,   689,    -1,    -1,    -1,    -1,    -1,
     351,   352,   353,   354,   355,    -1,    -1,    -1,    -1,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,   369,   370,
      14,    15,    -1,   546,    -1,    -1,    -1,    -1,    22,    -1,
      24,    -1,    -1,    -1,    -1,   386,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,   592,
     593,   594,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    22,   682,
      24,    -1,    -1,    -1,    28,   688,   689,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   682,    -1,    -1,    -1,    -1,    -1,   688,   689
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    53,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,   238,    22,
      22,    22,    22,    22,    22,    22,     0,    65,    54,    58,
      61,   230,   240,   250,   251,   230,   230,   230,   230,   230,
     244,   251,    17,    17,    17,    17,    17,    17,    17,    23,
     231,   250,   231,   231,   231,   231,   231,    24,   239,    18,
      17,    17,    17,    17,    17,    17,   229,   230,    23,    14,
      15,    22,    26,    31,    32,    33,    54,    55,    56,    57,
      59,    74,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   197,   198,   199,   200,   210,
     213,   222,   223,   224,   225,   226,   227,   228,   240,   241,
     242,   243,   245,   246,   247,   248,   249,   252,   253,    14,
      22,    24,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    85,    86,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   105,   106,   110,   112,   114,   115,
     116,   117,   118,   119,   205,   206,   207,   208,   209,   210,
     213,   218,   222,   223,   224,   225,   226,   227,   228,   248,
      14,    22,    24,   120,   121,   122,   123,   124,   125,   126,
     127,   129,   130,   131,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   153,   154,   156,   167,   168,
     210,   213,   218,   222,   223,   224,   225,   226,   227,   228,
     248,    22,    31,    32,   156,   169,   170,   171,   180,   185,
     202,   203,   204,   218,   222,   224,   172,    22,   202,    17,
      25,    18,    58,    58,   173,   199,    22,    27,   173,   201,
      17,    23,    28,    13,    13,    28,    44,    45,    46,    47,
      48,    49,   211,    20,    21,   219,   220,   221,    51,    24,
     179,   181,   182,    22,    22,    22,    10,    11,    13,    28,
      76,   108,   110,   119,   208,   211,   212,   218,   220,    22,
      25,    76,   106,   107,   222,   224,    17,    23,    28,    13,
      12,    12,    13,    28,   211,   219,   221,    51,    19,    29,
      30,    29,    19,    24,    22,    84,    85,    90,    92,   248,
      16,    52,    22,    22,    22,    10,    11,   121,   156,   168,
      22,    25,   121,   152,   154,   155,   222,   224,   228,    17,
      23,    28,    13,    13,    28,   211,   219,   221,    51,    24,
      22,   128,   129,   136,   138,   248,    16,    52,    22,    22,
      22,    22,   203,    24,   185,   197,    17,    23,    28,    17,
      23,    17,    23,   230,    23,    23,    17,    27,    14,    24,
      73,   232,   233,   234,   236,   237,   240,   243,   248,   249,
      18,   181,   181,   181,   181,   181,   191,   194,   195,   197,
     197,   200,   184,   248,   196,   197,   196,   196,    22,    22,
      23,    23,    23,    23,    17,    25,    73,    18,    83,    85,
      89,    95,    83,    83,    83,    83,    83,    83,    22,    92,
     105,   248,   105,   106,    85,   112,   112,   112,   115,   112,
     112,    87,    88,   248,    76,    82,    83,    85,   111,   112,
     113,   115,   217,   218,   222,   223,   224,   225,   226,   227,
     107,   109,   109,   109,    22,    22,    23,    23,    23,   154,
      17,    25,    73,    18,   127,   129,   135,   142,   127,   127,
     127,   127,    22,   138,   153,   248,   153,   154,   132,   133,
     134,   248,   121,    22,    24,    42,   157,   158,   160,   161,
     163,   165,   214,   215,   216,   240,   241,   248,   217,   155,
     155,   155,    23,   132,    73,    18,   204,    73,    18,    73,
      18,   173,     4,     5,     7,     8,     9,    25,   232,   235,
      23,    17,    16,    22,    17,    25,    17,    23,    23,    23,
      76,    22,    24,   100,   110,    76,    23,    76,    17,    25,
      16,    23,    23,    23,    23,   121,    24,   146,   156,   152,
      23,   121,    17,    25,    16,    23,   157,   160,   164,   157,
     166,    24,    30,    22,    23,    23,    23,    25,    23,    23,
      23,    22,    22,    22,    22,    22,    17,    25,    18,   237,
     232,   235,   248,    16,   197,    17,   101,   110,    17,    18,
      23,    88,    16,   111,    17,   147,   156,    17,    18,    23,
     133,    16,   161,    23,    29,    23,    29,    17,    25,   132,
     161,   161,   162,    16,    18,    18,    18,    75,   120,   172,
     202,   197,   232,    23,   181,    76,    17,    25,    24,    76,
     102,   103,    83,   152,    17,    25,    24,   139,   148,   149,
     150,   154,   127,   161,   161,   157,    25,    17,    23,   202,
      23,    23,    23,    23,    23,    17,   110,    76,   103,   104,
      50,    17,    17,   156,   139,   149,   151,   154,    17,    50,
      16,   161,    76,    17,    25,    76,    75,   152,    17,    25,
     152,   152,    22,   159,   161,    23,   103,    23,    23,   149,
      23,    22,   161,   163,   160,    23
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    75,    75,
      75,    75,    76,    76,    76,    76,    77,    77,    77,    78,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    87,
      87,    88,    89,    89,    90,    91,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    95,    96,    97,
      97,    97,    98,    99,   100,   100,   101,   101,   102,   102,
     103,   104,   104,   105,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   110,   110,   111,   111,   111,
     112,   113,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   119,   119,   120,   120,   120,   120,   121,   121,
     121,   121,   122,   122,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   129,   129,
     130,   131,   132,   132,   133,   133,   134,   135,   135,   136,
     137,   138,   138,   138,   139,   139,   140,   141,   141,   141,
     141,   142,   143,   143,   144,   145,   146,   146,   147,   147,
     148,   148,   149,   150,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   157,   157,   157,   157,   158,   159,   159,   160,   160,
     161,   161,   161,   161,   161,   162,   162,   163,   164,   164,
     165,   166,   166,   167,   168,   168,   169,   169,   170,   170,
     171,   172,   172,   173,   173,   173,   174,   174,   175,   176,
     176,   177,   177,   178,   178,   179,   179,   180,   181,   181,
     182,   182,   182,   183,   184,   184,   185,   185,   185,   186,
     187,   187,   188,   189,   190,   191,   191,   192,   192,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     198,   199,   199,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   204,   205,   205,   205,   206,   206,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   210,
     210,   211,   211,   211,   211,   211,   211,   212,   212,   213,
     214,   215,   216,   217,   217,   218,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   228,   229,   229,
     230,   230,   231,   232,   232,   232,   233,   233,   233,   233,
     233,   233,   234,   235,   235,   236,   236,   236,   236,   236,
     237,   237,   238,   238,   239,   240,   240,   241,   242,   243,
     243,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,    11,     9,    11,     9,    11,     9,
      11,     9,    11,     9,    11,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     1,
       3,     3,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     4,
       4,     4,     9,     9,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     1,     3,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     6,     1,     3,     1,     1,     3,     1,     1,     2,
       3,     1,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     3,     1,     4,     9,     9,     1,     3,     1,     3,
       1,     3,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     3,     3,
       3,     1,     1,     1,     3,     6,     1,     3,     1,     3,
       1,     1,     4,     1,     1,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       6,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     3,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     1,     1,     1,
       1,     4,     1,     4,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     5,     5,     5,     5,     5,
       2,     3,     5,     7,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"tpi\"", "\"thf\"",
  "\"tff\"", "\"tcf\"", "\"fof\"", "\"cnf\"", "\"fot\"", "\"ite\"",
  "\"let\"", "\"@\"", "\"&\"", "\"$\"", "\"$$\"", "\":\"", "\",\"",
  "\".\"", "\"+\"", "\"=\"", "\"!=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "\"|\"", "\"*\"", "\">\"", "\"!\"", "\"~\"", "\"?\"",
  "\"@-\"", "\"@+\"", "\"^\"", "\"!!\"", "\"??\"", "\"@@+\"", "\"@@-\"",
  "\"@=\"", "\"!>\"", "\"?*\"", "\"<=>\"", "\"=>\"", "\"<=\"", "\"<~>\"",
  "\"~|\"", "\"~&\"", "\":=\"", "\"-->\"", "\"<<\"", "\"include\"",
  "\"integer\"", "\"real\"", "\"rational\"", "\"double_quoted\"",
  "\"lower_word\"", "\"upper_word\"", "\"identifier\"",
  "\"single_quoted\"", "$accept", "Specification", "Definitions",
  "Definition", "AnnotatedFormula", "ThfAnnotated", "TffAnnotated",
  "TcfAnnotated", "FofAnnotated", "CnfAnnotated", "TpiAnnotated",
  "Annotations", "TpiFormula", "ThfFormula", "ThfLogicFormula",
  "ThfBinaryFormula", "ThfBinaryNonassoc", "ThfBinaryAssoc",
  "ThfOrFormula", "ThfAndFormula", "ThfApplyFormula", "ThfUnitFormula",
  "ThfPreunitFormula", "ThfUnitaryFormula", "ThfQuantifiedFormula",
  "ThfVariableList", "ThfTypedVariable", "ThfUnaryFormula",
  "ThfPrefixUnary", "ThfInfixUnary", "ThfAtomicFormula", "ThfPlainAtomic",
  "ThfDefinedAtomic", "ThfDefinedInfix", "ThfSystemAtomic",
  "ThfFofFunction", "ThfConditional", "ThfLet", "ThfLetTypes",
  "ThfAtomTypingList", "ThfLetDefns", "ThfLetDefn", "ThfLetDefnList",
  "ThfUnitaryTerm", "ThfTuple", "ThfFormulaList", "ThfConnTerm",
  "ThfArguments", "ThfAtomTyping", "ThfTopLevelType", "ThfUnitaryType",
  "ThfApplyType", "ThfBinaryType", "ThfMappingType", "ThfXprodType",
  "ThfUnionType", "ThfSubtype", "ThfSequent", "TffFormula",
  "TffLogicFormula", "TffBinaryFormula", "TffBinaryNonassoc",
  "TffBinaryAssoc", "TffOrFormula", "TffAndFormula", "TffUnitFormula",
  "TffPreunitFormula", "TffUnitaryFormula", "TfxUnitaryFormula",
  "TffQuantifiedFormula", "TffVariableList", "TffVariable",
  "TffTypedVariable", "TffUnaryFormula", "TffPrefixUnary", "TffInfixUnary",
  "TffAtomicFormula", "TffPlainAtomic", "TffDefinedAtomic",
  "TffDefinedPlain", "TffDefinedInfix", "TffSystemAtomic",
  "TfxConditional", "TfxLet", "TfxLetTypes", "TffAtomTypingList",
  "TfxLetDefns", "TfxLetDefn", "TfxLetLhs", "TfxLetDefnList", "TffTerm",
  "TffUnitaryTerm", "TfxTuple", "TffArguments", "TffAtomTyping",
  "TffTopLevelType", "Tf1QuantifiedType", "TffMonotype", "TffUnitaryType",
  "TffAtomicType", "TffTypeArguments", "TffMappingType", "TffXprodType",
  "TfxTupleType", "TffTypeList", "TffSubtype", "TfxSequent", "TcfFormula",
  "TcfLogicFormula", "TcfQuantifiedFormula", "FofFormula",
  "FofLogicFormula", "FofBinaryFormula", "FofBinaryNonassoc",
  "FofBinaryAssoc", "FofOrFormula", "FofAndFormula", "FofUnaryFormula",
  "FofInfixUnary", "FofUnitFormula", "FofUnitaryFormula",
  "FofQuantifiedFormula", "FofVariableList", "FofAtomicFormula",
  "FofPlainAtomicFormula", "FofDefinedAtomicFormula",
  "FofDefinedPlainFormula", "FofDefinedInfixFormula",
  "FofSystemAtomicFormula", "FofPlainTerm", "FofDefinedTerm",
  "FofDefinedAtomicTerm", "FofDefinedPlainTerm", "FofSystemTerm",
  "FofArguments", "FofTerm", "FofFunctionTerm", "FofSequent",
  "FofFormulaTuple", "FofFormulaTupleList", "CnfFormula", "Disjunction",
  "Literal", "ThfQuantifier", "Th1Quantifier", "Th0Quantifier",
  "ThfUnaryConnective", "Th1UnaryConnective", "FofQuantifier",
  "NonassocConnective", "AssocConnective", "UnaryConnective",
  "TypeConstant", "TypeFunctor", "DefinedType", "Atom", "UntypedAtom",
  "DefinedInfixPred", "InfixEquality", "InfixInequality", "Constant",
  "Functor", "SystemConstant", "SystemFunctor", "DefinedConstant",
  "DefinedFunctor", "DefinedTerm", "NameList", "Name", "FormulaRole",
  "GeneralTerm", "GeneralData", "GeneralFunction", "GeneralTerms",
  "FormulaData", "GeneralList", "IncludeDefinition", "FormulaSelection",
  "AtomicWord", "AtomicDefinedWord", "AtomicSystemWord", "Number",
  "FileName", "IntegerLiteral", "RealLiteral", "RationalLiteral",
  "Variable", "DistinctObjectLiteral", "LowerWordLiteral",
  "SingleQuotedLiteral", "DollarWordLiteral", "DollarDollarWordLiteral", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
<<<<<<< HEAD
       0,   345,   345,   352,   358,   368,   372,   379,   383,   387,
     391,   395,   399,   406,   411,   422,   427,   438,   443,   454,
     459,   470,   475,   486,   491,   502,   507,   515,   522,   526,
     530,   534,   541,   545,   549,   553,   560,   564,   568,   575,
     582,   586,   590,   597,   602,   610,   615,   623,   628,   636,
     640,   644,   651,   655,   662,   666,   670,   674,   684,   692,
     698,   707,   717,   721,   728,   735,   742,   746,   750,   754,
     761,   765,   772,   776,   780,   784,   791,   798,   805,   812,
     816,   820,   827,   834,   841,   845,   852,   858,   867,   871,
     878,   885,   892,   901,   905,   909,   919,   923,   930,   936,
     945,   950,   955,   960,   968,   975,   979,   989,   993,   997,
    1004,  1011,  1018,  1022,  1026,  1034,  1038,  1046,  1050,  1058,
    1062,  1069,  1076,  1080,  1091,  1095,  1099,  1103,  1110,  1114,
    1118,  1122,  1129,  1133,  1140,  1147,  1151,  1158,  1163,  1171,
    1176,  1184,  1188,  1192,  1199,  1203,  1210,  1214,  1218,  1222,
    1232,  1239,  1247,  1254,  1263,  1267,  1274,  1285,  1289,  1296,
    1303,  1310,  1314,  1318,  1325,  1329,  1336,  1343,  1347,  1351,
    1355,  1362,  1369,  1373,  1380,  1387,  1394,  1398,  1405,  1411,
    1420,  1424,  1431,  1438,  1442,  1449,  1455,  1464,  1468,  1472,
    1479,  1483,  1487,  1491,  1495,  1505,  1509,  1516,  1522,  1531,
    1535,  1545,  1549,  1553,  1557,  1567,  1574,  1578,  1588,  1592,
    1602,  1606,  1610,  1615,  1619,  1626,  1632,  1641,  1648,  1652,
    1659,  1666,  1672,  1681,  1688,  1692,  1703,  1707,  1714,  1718,
    1725,  1736,  1740,  1747,  1751,  1755,  1762,  1766,  1773,  1780,
    1784,  1791,  1796,  1804,  1809,  1817,  1821,  1828,  1835,  1839,
    1846,  1850,  1854,  1864,  1872,  1879,  1888,  1892,  1896,  1903,
    1910,  1914,  1921,  1928,  1935,  1942,  1946,  1953,  1957,  1964,
    1971,  1975,  1982,  1986,  1993,  1999,  2008,  2012,  2019,  2023,
    2027,  2034,  2038,  2047,  2051,  2058,  2064,  2073,  2077,  2087,
    2091,  2099,  2103,  2108,  2115,  2119,  2123,  2130,  2134,  2141,
    2145,  2149,  2156,  2160,  2167,  2171,  2175,  2179,  2183,  2190,
    2194,  2203,  2207,  2211,  2215,  2219,  2223,  2230,  2234,  2241,
    2248,  2255,  2262,  2269,  2273,  2280,  2284,  2291,  2298,  2305,
    2312,  2319,  2326,  2333,  2340,  2347,  2354,  2358,  2365,  2373,
    2382,  2386,  2393,  2400,  2404,  2408,  2415,  2419,  2423,  2427,
    2431,  2435,  2442,  2449,  2455,  2464,  2468,  2472,  2476,  2480,
    2487,  2492,  2501,  2506,  2513,  2521,  2525,  2532,  2539,  2546,
    2550,  2554,  2561,  2568,  2575,  2581,  2588,  2596,  2603,  2610,
    2617,  2624
=======
       0,   348,   348,   355,   361,   371,   375,   382,   386,   390,
     394,   398,   402,   409,   414,   425,   430,   441,   446,   457,
     462,   473,   478,   489,   494,   505,   510,   518,   525,   529,
     533,   537,   544,   548,   552,   556,   563,   567,   571,   578,
     585,   589,   593,   600,   605,   613,   618,   626,   631,   639,
     643,   647,   654,   658,   665,   669,   673,   677,   687,   694,
     700,   709,   719,   723,   730,   737,   744,   748,   752,   756,
     763,   767,   774,   778,   782,   786,   793,   800,   807,   814,
     818,   822,   829,   836,   843,   847,   854,   860,   869,   873,
     880,   887,   894,   903,   907,   911,   921,   925,   932,   938,
     947,   952,   957,   962,   970,   977,   981,   991,   995,   999,
    1007,  1016,  1023,  1027,  1031,  1039,  1043,  1051,  1058,  1068,
    1072,  1079,  1086,  1090,  1101,  1105,  1109,  1113,  1120,  1124,
    1128,  1132,  1139,  1143,  1150,  1157,  1161,  1168,  1173,  1181,
    1186,  1194,  1198,  1202,  1209,  1213,  1220,  1224,  1228,  1232,
    1242,  1249,  1256,  1262,  1271,  1275,  1282,  1293,  1297,  1304,
    1311,  1318,  1322,  1326,  1333,  1337,  1344,  1351,  1355,  1359,
    1363,  1370,  1377,  1381,  1388,  1395,  1402,  1406,  1413,  1419,
    1428,  1432,  1439,  1446,  1450,  1457,  1463,  1472,  1476,  1480,
    1487,  1491,  1495,  1499,  1503,  1513,  1517,  1524,  1530,  1539,
    1543,  1553,  1557,  1561,  1565,  1575,  1582,  1586,  1596,  1600,
    1610,  1614,  1618,  1622,  1626,  1633,  1639,  1648,  1655,  1662,
    1671,  1678,  1684,  1693,  1700,  1704,  1715,  1719,  1726,  1730,
    1737,  1747,  1751,  1758,  1762,  1766,  1773,  1777,  1784,  1791,
    1795,  1802,  1807,  1815,  1820,  1828,  1832,  1839,  1846,  1850,
    1857,  1861,  1865,  1875,  1882,  1888,  1897,  1901,  1905,  1912,
    1919,  1923,  1930,  1937,  1944,  1951,  1955,  1962,  1966,  1973,
    1980,  1984,  1991,  1995,  2002,  2008,  2017,  2021,  2028,  2032,
    2036,  2043,  2047,  2056,  2060,  2067,  2073,  2082,  2086,  2096,
    2100,  2108,  2112,  2117,  2124,  2128,  2132,  2139,  2143,  2150,
    2154,  2158,  2165,  2169,  2176,  2180,  2184,  2188,  2192,  2199,
    2203,  2212,  2216,  2220,  2224,  2228,  2232,  2239,  2243,  2250,
    2257,  2264,  2271,  2278,  2282,  2289,  2293,  2300,  2307,  2314,
    2321,  2328,  2335,  2342,  2349,  2356,  2363,  2367,  2374,  2382,
    2391,  2395,  2402,  2409,  2413,  2417,  2424,  2428,  2432,  2436,
    2440,  2444,  2451,  2458,  2464,  2473,  2477,  2481,  2485,  2489,
    2496,  2501,  2510,  2515,  2522,  2530,  2534,  2541,  2548,  2555,
    2559,  2563,  2570,  2577,  2584,  2590,  2597,  2605,  2612,  2619,
    2626,  2633
>>>>>>> 508276a (GrammarParser: commmit built files)
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 48 "../../obj/src/GrammarParser.yy"
} // libtptp
<<<<<<< HEAD
#line 7229 "GrammarParser.cpp"

#line 2630 "../../obj/src/GrammarParser.yy"
=======
#line 6800 "GrammarParser.cpp"

#line 2639 "../../obj/src/GrammarParser.yy"
>>>>>>> 508276a (GrammarParser: commmit built files)


void Parser::error( const SourceLocation& location, const std::string& message )
{
    m_log.error( { location }, message ); //, Code::SyntaxError );
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

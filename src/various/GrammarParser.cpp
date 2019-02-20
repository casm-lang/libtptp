// A Bison parser, made by GNU Bison 3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "GrammarParser.tab.h"


// Unqualified %code blocks.
#line 102 "../../obj/src/GrammarParser.yy" // lalr1.cc:437

    // #include <libtptp/ ... >

    //#include "../../src/SourceLocation.h"
    #include "../../src/Lexer.h"
    #include "../../src/various/GrammarToken.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = std::make_shared<Token>(Grammar::Token::UNRESOLVED );
    // static Lexer helper functions shall be located here 

#line 61 "GrammarParser.cpp" // lalr1.cc:437


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
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      yystack_print_ ();                \
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

#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:512
namespace libtptp {
#line 156 "GrammarParser.cpp" // lalr1.cc:512

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
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  Parser::Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      m_log (m_log_yyarg),
      m_lexer (m_lexer_yyarg),
      m_specification (m_specification_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 72: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 138: // TffPlainAtomic
      case 142: // TffSystemAtomic
      case 190: // FofPlainTerm
      case 191: // FofDefinedTerm
      case 192: // FofDefinedAtomicTerm
      case 193: // FofDefinedPlainTerm
      case 194: // FofSystemTerm
      case 197: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 111: // ThfUnitaryType
      case 112: // ThfApplyType
      case 160: // TffAtomicType
        value.YY_MOVE_OR_COPY< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 210: // NonassocConnective
      case 211: // AssocConnective
        value.YY_MOVE_OR_COPY< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 77: // ThfBinaryNonassoc
      case 78: // ThfBinaryAssoc
      case 79: // ThfOrFormula
      case 80: // ThfAndFormula
      case 81: // ThfApplyFormula
      case 121: // TffBinaryFormula
      case 122: // TffBinaryNonassoc
      case 123: // TffBinaryAssoc
      case 124: // TffOrFormula
      case 125: // TffAndFormula
      case 173: // FofBinaryFormula
      case 174: // FofBinaryNonassoc
      case 175: // FofBinaryAssoc
      case 176: // FofOrFormula
      case 177: // FofAndFormula
        value.YY_MOVE_OR_COPY< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // ThfBinaryType
      case 114: // ThfMappingType
      case 115: // ThfXprodType
      case 116: // ThfUnionType
      case 162: // TffMappingType
      case 163: // TffXprodType
        value.YY_MOVE_OR_COPY< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // ThfConditional
      case 143: // TfxConditional
        value.YY_MOVE_OR_COPY< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // ThfConnTerm
        value.YY_MOVE_OR_COPY< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 95: // ThfSystemAtomic
        value.YY_MOVE_OR_COPY< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 227: // DefinedTerm
        value.YY_MOVE_OR_COPY< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // ThfLetDefn
      case 148: // TfxLetDefn
        value.YY_MOVE_OR_COPY< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // ThfLet
      case 144: // TfxLet
        value.YY_MOVE_OR_COPY< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 63: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // TpiFormula
      case 171: // FofFormula
        value.YY_MOVE_OR_COPY< FirstOrderFormula::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // AnnotatedFormula
      case 69: // FofAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 230: // FormulaRole
        value.YY_MOVE_OR_COPY< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 96: // ThfFofFunction
        value.YY_MOVE_OR_COPY< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 213: // TypeConstant
      case 214: // TypeFunctor
      case 215: // DefinedType
      case 216: // Atom
      case 217: // UntypedAtom
      case 221: // Constant
      case 222: // Functor
      case 223: // SystemConstant
      case 224: // SystemFunctor
      case 225: // DefinedConstant
      case 226: // DefinedFunctor
      case 229: // Name
      case 243: // FileName
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 218: // DefinedInfixPred
      case 219: // InfixEquality
      case 220: // InfixInequality
        value.YY_MOVE_OR_COPY< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 90: // ThfInfixUnary
      case 94: // ThfDefinedInfix
      case 136: // TffInfixUnary
      case 141: // TffDefinedInfix
      case 179: // FofInfixUnary
      case 188: // FofDefinedInfixFormula
        value.YY_MOVE_OR_COPY< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 244: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // ThfFormula
      case 75: // ThfLogicFormula
      case 76: // ThfBinaryFormula
      case 82: // ThfUnitFormula
      case 83: // ThfPreunitFormula
      case 84: // ThfUnitaryFormula
      case 88: // ThfUnaryFormula
      case 91: // ThfAtomicFormula
      case 92: // ThfPlainAtomic
      case 101: // ThfLetDefns
      case 104: // ThfUnitaryTerm
      case 119: // TffFormula
      case 120: // TffLogicFormula
      case 126: // TffUnitFormula
      case 127: // TffPreunitFormula
      case 128: // TffUnitaryFormula
      case 134: // TffUnaryFormula
      case 147: // TfxLetDefns
      case 149: // TfxLetLhs
      case 151: // TffTerm
      case 152: // TffUnitaryTerm
      case 172: // FofLogicFormula
      case 178: // FofUnaryFormula
      case 180: // FofUnitFormula
      case 181: // FofUnitaryFormula
      case 184: // FofAtomicFormula
      case 186: // FofDefinedAtomicFormula
      case 201: // CnfFormula
      case 202: // Disjunction
      case 203: // Literal
        value.YY_MOVE_OR_COPY< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 105: // ThfTuple
      case 153: // TfxTuple
      case 199: // FofFormulaTuple
        value.YY_MOVE_OR_COPY< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // ThfLetDefnList
      case 106: // ThfFormulaList
      case 108: // ThfArguments
      case 150: // TfxLetDefnList
      case 154: // TffArguments
      case 161: // TffTypeArguments
      case 195: // FofArguments
      case 200: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< Logics::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // ThfVariableList
      case 131: // TffVariableList
      case 183: // FofVariableList
      case 228: // NameList
      case 234: // GeneralTerms
        value.YY_MOVE_OR_COPY< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // ThfQuantifiedFormula
      case 130: // TffQuantifiedFormula
      case 182: // FofQuantifiedFormula
        value.YY_MOVE_OR_COPY< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 204: // ThfQuantifier
      case 205: // Th1Quantifier
      case 206: // Th0Quantifier
      case 209: // FofQuantifier
        value.YY_MOVE_OR_COPY< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 157: // Tf1QuantifiedType
        value.YY_MOVE_OR_COPY< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 246: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 245: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 248: // DistinctObjectLiteral
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
        value.YY_MOVE_OR_COPY< StringLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // ThfSubtype
      case 166: // TffSubtype
        value.YY_MOVE_OR_COPY< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // ThfDefinedAtomic
      case 137: // TffAtomicFormula
      case 139: // TffDefinedAtomic
      case 140: // TffDefinedPlain
      case 185: // FofPlainAtomicFormula
      case 187: // FofDefinedPlainFormula
      case 189: // FofSystemAtomicFormula
      case 196: // FofTerm
        value.YY_MOVE_OR_COPY< Term::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "tpi"
      case 4: // "thf"
      case 5: // "tff"
      case 6: // "tcf"
      case 7: // "fof"
      case 8: // "cnf"
      case 9: // "fot"
      case 10: // "ite"
      case 11: // "let"
      case 12: // "@"
      case 13: // "&"
      case 14: // "$"
      case 15: // ":"
      case 16: // ","
      case 17: // "."
      case 18: // "+"
      case 19: // "="
      case 20: // "!="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "!"
      case 31: // "~"
      case 32: // "?"
      case 33: // "@-"
      case 34: // "@+"
      case 35: // "^"
      case 36: // "!!"
      case 37: // "??"
      case 38: // "@@+"
      case 39: // "@@-"
      case 40: // "@="
      case 41: // "!>"
      case 42: // "?*"
      case 43: // "<=>"
      case 44: // "=>"
      case 45: // "<="
      case 46: // "<~>"
      case 47: // "~|"
      case 48: // "~&"
      case 49: // ":="
      case 50: // "-->"
      case 51: // "<<"
      case 52: // "include"
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 164: // TfxTupleType
        value.YY_MOVE_OR_COPY< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // ThfLetTypes
      case 110: // ThfTopLevelType
      case 145: // TfxLetTypes
      case 156: // TffTopLevelType
      case 158: // TffMonotype
      case 159: // TffUnitaryType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 109: // ThfAtomTyping
      case 155: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfAtomTypingList
      case 146: // TffAtomTypingList
      case 165: // TffTypeList
        value.YY_MOVE_OR_COPY< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 207: // ThfUnaryConnective
      case 208: // Th1UnaryConnective
      case 212: // UnaryConnective
        value.YY_MOVE_OR_COPY< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 89: // ThfPrefixUnary
      case 135: // TffPrefixUnary
        value.YY_MOVE_OR_COPY< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfTypedVariable
      case 129: // TfxUnitaryFormula
      case 132: // TffVariable
      case 133: // TffTypedVariable
      case 247: // Variable
        value.YY_MOVE_OR_COPY< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 53: // "integer"
      case 54: // "real"
      case 55: // "rational"
      case 56: // "double_quoted"
      case 57: // "lower_word"
      case 58: // "upper_word"
      case 59: // "identifier"
      case 60: // "single_quoted"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if defined __cplusplus && 201103L <= __cplusplus
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 72: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 138: // TffPlainAtomic
      case 142: // TffSystemAtomic
      case 190: // FofPlainTerm
      case 191: // FofDefinedTerm
      case 192: // FofDefinedAtomicTerm
      case 193: // FofDefinedPlainTerm
      case 194: // FofSystemTerm
      case 197: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 111: // ThfUnitaryType
      case 112: // ThfApplyType
      case 160: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 210: // NonassocConnective
      case 211: // AssocConnective
        value.move< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 77: // ThfBinaryNonassoc
      case 78: // ThfBinaryAssoc
      case 79: // ThfOrFormula
      case 80: // ThfAndFormula
      case 81: // ThfApplyFormula
      case 121: // TffBinaryFormula
      case 122: // TffBinaryNonassoc
      case 123: // TffBinaryAssoc
      case 124: // TffOrFormula
      case 125: // TffAndFormula
      case 173: // FofBinaryFormula
      case 174: // FofBinaryNonassoc
      case 175: // FofBinaryAssoc
      case 176: // FofOrFormula
      case 177: // FofAndFormula
        value.move< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 113: // ThfBinaryType
      case 114: // ThfMappingType
      case 115: // ThfXprodType
      case 116: // ThfUnionType
      case 162: // TffMappingType
      case 163: // TffXprodType
        value.move< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // ThfConditional
      case 143: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 95: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 227: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 102: // ThfLetDefn
      case 148: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // ThfLet
      case 144: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 63: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 73: // TpiFormula
      case 171: // FofFormula
        value.move< FirstOrderFormula::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // AnnotatedFormula
      case 69: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 230: // FormulaRole
        value.move< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 96: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 213: // TypeConstant
      case 214: // TypeFunctor
      case 215: // DefinedType
      case 216: // Atom
      case 217: // UntypedAtom
      case 221: // Constant
      case 222: // Functor
      case 223: // SystemConstant
      case 224: // SystemFunctor
      case 225: // DefinedConstant
      case 226: // DefinedFunctor
      case 229: // Name
      case 243: // FileName
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 218: // DefinedInfixPred
      case 219: // InfixEquality
      case 220: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 90: // ThfInfixUnary
      case 94: // ThfDefinedInfix
      case 136: // TffInfixUnary
      case 141: // TffDefinedInfix
      case 179: // FofInfixUnary
      case 188: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 244: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 74: // ThfFormula
      case 75: // ThfLogicFormula
      case 76: // ThfBinaryFormula
      case 82: // ThfUnitFormula
      case 83: // ThfPreunitFormula
      case 84: // ThfUnitaryFormula
      case 88: // ThfUnaryFormula
      case 91: // ThfAtomicFormula
      case 92: // ThfPlainAtomic
      case 101: // ThfLetDefns
      case 104: // ThfUnitaryTerm
      case 119: // TffFormula
      case 120: // TffLogicFormula
      case 126: // TffUnitFormula
      case 127: // TffPreunitFormula
      case 128: // TffUnitaryFormula
      case 134: // TffUnaryFormula
      case 147: // TfxLetDefns
      case 149: // TfxLetLhs
      case 151: // TffTerm
      case 152: // TffUnitaryTerm
      case 172: // FofLogicFormula
      case 178: // FofUnaryFormula
      case 180: // FofUnitFormula
      case 181: // FofUnitaryFormula
      case 184: // FofAtomicFormula
      case 186: // FofDefinedAtomicFormula
      case 201: // CnfFormula
      case 202: // Disjunction
      case 203: // Literal
        value.move< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 105: // ThfTuple
      case 153: // TfxTuple
      case 199: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // ThfLetDefnList
      case 106: // ThfFormulaList
      case 108: // ThfArguments
      case 150: // TfxLetDefnList
      case 154: // TffArguments
      case 161: // TffTypeArguments
      case 195: // FofArguments
      case 200: // FofFormulaTupleList
        value.move< Logics::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // ThfVariableList
      case 131: // TffVariableList
      case 183: // FofVariableList
      case 228: // NameList
      case 234: // GeneralTerms
        value.move< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 85: // ThfQuantifiedFormula
      case 130: // TffQuantifiedFormula
      case 182: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 204: // ThfQuantifier
      case 205: // Th1Quantifier
      case 206: // Th0Quantifier
      case 209: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 157: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 246: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 245: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 248: // DistinctObjectLiteral
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
        value.move< StringLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // ThfSubtype
      case 166: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 93: // ThfDefinedAtomic
      case 137: // TffAtomicFormula
      case 139: // TffDefinedAtomic
      case 140: // TffDefinedPlain
      case 185: // FofPlainAtomicFormula
      case 187: // FofDefinedPlainFormula
      case 189: // FofSystemAtomicFormula
      case 196: // FofTerm
        value.move< Term::Ptr > (YY_MOVE (that.value));
        break;

      case 3: // "tpi"
      case 4: // "thf"
      case 5: // "tff"
      case 6: // "tcf"
      case 7: // "fof"
      case 8: // "cnf"
      case 9: // "fot"
      case 10: // "ite"
      case 11: // "let"
      case 12: // "@"
      case 13: // "&"
      case 14: // "$"
      case 15: // ":"
      case 16: // ","
      case 17: // "."
      case 18: // "+"
      case 19: // "="
      case 20: // "!="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "!"
      case 31: // "~"
      case 32: // "?"
      case 33: // "@-"
      case 34: // "@+"
      case 35: // "^"
      case 36: // "!!"
      case 37: // "??"
      case 38: // "@@+"
      case 39: // "@@-"
      case 40: // "@="
      case 41: // "!>"
      case 42: // "?*"
      case 43: // "<=>"
      case 44: // "=>"
      case 45: // "<="
      case 46: // "<~>"
      case 47: // "~|"
      case 48: // "~&"
      case 49: // ":="
      case 50: // "-->"
      case 51: // "<<"
      case 52: // "include"
        value.move< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 164: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // ThfLetTypes
      case 110: // ThfTopLevelType
      case 145: // TfxLetTypes
      case 156: // TffTopLevelType
      case 158: // TffMonotype
      case 159: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 109: // ThfAtomTyping
      case 155: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfAtomTypingList
      case 146: // TffAtomTypingList
      case 165: // TffTypeList
        value.move< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 207: // ThfUnaryConnective
      case 208: // Th1UnaryConnective
      case 212: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 89: // ThfPrefixUnary
      case 135: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfTypedVariable
      case 129: // TfxUnitaryFormula
      case 132: // TffVariable
      case 133: // TffTypedVariable
      case 247: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 53: // "integer"
      case 54: // "real"
      case 55: // "rational"
      case 56: // "double_quoted"
      case 57: // "lower_word"
      case 58: // "upper_word"
      case 59: // "identifier"
      case 60: // "single_quoted"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if defined __cplusplus && __cplusplus < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 72: // Annotations
        value.move< Annotation::Ptr > (that.value);
        break;

      case 138: // TffPlainAtomic
      case 142: // TffSystemAtomic
      case 190: // FofPlainTerm
      case 191: // FofDefinedTerm
      case 192: // FofDefinedAtomicTerm
      case 193: // FofDefinedPlainTerm
      case 194: // FofSystemTerm
      case 197: // FofFunctionTerm
        value.move< Atom::Ptr > (that.value);
        break;

      case 111: // ThfUnitaryType
      case 112: // ThfApplyType
      case 160: // TffAtomicType
        value.move< AtomType::Ptr > (that.value);
        break;

      case 210: // NonassocConnective
      case 211: // AssocConnective
        value.move< BinaryConnective_t > (that.value);
        break;

      case 77: // ThfBinaryNonassoc
      case 78: // ThfBinaryAssoc
      case 79: // ThfOrFormula
      case 80: // ThfAndFormula
      case 81: // ThfApplyFormula
      case 121: // TffBinaryFormula
      case 122: // TffBinaryNonassoc
      case 123: // TffBinaryAssoc
      case 124: // TffOrFormula
      case 125: // TffAndFormula
      case 173: // FofBinaryFormula
      case 174: // FofBinaryNonassoc
      case 175: // FofBinaryAssoc
      case 176: // FofOrFormula
      case 177: // FofAndFormula
        value.move< BinaryLogic::Ptr > (that.value);
        break;

      case 113: // ThfBinaryType
      case 114: // ThfMappingType
      case 115: // ThfXprodType
      case 116: // ThfUnionType
      case 162: // TffMappingType
      case 163: // TffXprodType
        value.move< BinaryType::Ptr > (that.value);
        break;

      case 97: // ThfConditional
      case 143: // TfxConditional
        value.move< ConditionalTerm::Ptr > (that.value);
        break;

      case 107: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (that.value);
        break;

      case 95: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (that.value);
        break;

      case 227: // DefinedTerm
        value.move< DefinedAtom::Ptr > (that.value);
        break;

      case 64: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 102: // ThfLetDefn
      case 148: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (that.value);
        break;

      case 98: // ThfLet
      case 144: // TfxLet
        value.move< DefinitionTerm::Ptr > (that.value);
        break;

      case 63: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 73: // TpiFormula
      case 171: // FofFormula
        value.move< FirstOrderFormula::Ptr > (that.value);
        break;

      case 65: // AnnotatedFormula
      case 69: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
        break;

      case 230: // FormulaRole
        value.move< FormulaRole::Ptr > (that.value);
        break;

      case 96: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (that.value);
        break;

      case 232: // GeneralData
        value.move< GeneralData::Ptr > (that.value);
        break;

      case 233: // GeneralFunction
        value.move< GeneralFunction::Ptr > (that.value);
        break;

      case 236: // GeneralList
        value.move< GeneralList::Ptr > (that.value);
        break;

      case 231: // GeneralTerm
        value.move< GeneralTerm::Ptr > (that.value);
        break;

      case 213: // TypeConstant
      case 214: // TypeFunctor
      case 215: // DefinedType
      case 216: // Atom
      case 217: // UntypedAtom
      case 221: // Constant
      case 222: // Functor
      case 223: // SystemConstant
      case 224: // SystemFunctor
      case 225: // DefinedConstant
      case 226: // DefinedFunctor
      case 229: // Name
      case 243: // FileName
        value.move< Identifier::Ptr > (that.value);
        break;

      case 237: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (that.value);
        break;

      case 218: // DefinedInfixPred
      case 219: // InfixEquality
      case 220: // InfixInequality
        value.move< InfixConnective_t > (that.value);
        break;

      case 90: // ThfInfixUnary
      case 94: // ThfDefinedInfix
      case 136: // TffInfixUnary
      case 141: // TffDefinedInfix
      case 179: // FofInfixUnary
      case 188: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (that.value);
        break;

      case 244: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (that.value);
        break;

      case 238: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 74: // ThfFormula
      case 75: // ThfLogicFormula
      case 76: // ThfBinaryFormula
      case 82: // ThfUnitFormula
      case 83: // ThfPreunitFormula
      case 84: // ThfUnitaryFormula
      case 88: // ThfUnaryFormula
      case 91: // ThfAtomicFormula
      case 92: // ThfPlainAtomic
      case 101: // ThfLetDefns
      case 104: // ThfUnitaryTerm
      case 119: // TffFormula
      case 120: // TffLogicFormula
      case 126: // TffUnitFormula
      case 127: // TffPreunitFormula
      case 128: // TffUnitaryFormula
      case 134: // TffUnaryFormula
      case 147: // TfxLetDefns
      case 149: // TfxLetLhs
      case 151: // TffTerm
      case 152: // TffUnitaryTerm
      case 172: // FofLogicFormula
      case 178: // FofUnaryFormula
      case 180: // FofUnitFormula
      case 181: // FofUnitaryFormula
      case 184: // FofAtomicFormula
      case 186: // FofDefinedAtomicFormula
      case 201: // CnfFormula
      case 202: // Disjunction
      case 203: // Literal
        value.move< Logic::Ptr > (that.value);
        break;

      case 105: // ThfTuple
      case 153: // TfxTuple
      case 199: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (that.value);
        break;

      case 103: // ThfLetDefnList
      case 106: // ThfFormulaList
      case 108: // ThfArguments
      case 150: // TfxLetDefnList
      case 154: // TffArguments
      case 161: // TffTypeArguments
      case 195: // FofArguments
      case 200: // FofFormulaTupleList
        value.move< Logics::Ptr > (that.value);
        break;

      case 86: // ThfVariableList
      case 131: // TffVariableList
      case 183: // FofVariableList
      case 228: // NameList
      case 234: // GeneralTerms
        value.move< Nodes::Ptr > (that.value);
        break;

      case 85: // ThfQuantifiedFormula
      case 130: // TffQuantifiedFormula
      case 182: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (that.value);
        break;

      case 204: // ThfQuantifier
      case 205: // Th1Quantifier
      case 206: // Th0Quantifier
      case 209: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (that.value);
        break;

      case 157: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (that.value);
        break;

      case 246: // RationalLiteral
        value.move< RationalLiteral::Ptr > (that.value);
        break;

      case 245: // RealLiteral
        value.move< RealLiteral::Ptr > (that.value);
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.move< SequentLogic::Ptr > (that.value);
        break;

      case 62: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 248: // DistinctObjectLiteral
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
        value.move< StringLiteral::Ptr > (that.value);
        break;

      case 117: // ThfSubtype
      case 166: // TffSubtype
        value.move< SubType::Ptr > (that.value);
        break;

      case 93: // ThfDefinedAtomic
      case 137: // TffAtomicFormula
      case 139: // TffDefinedAtomic
      case 140: // TffDefinedPlain
      case 185: // FofPlainAtomicFormula
      case 187: // FofDefinedPlainFormula
      case 189: // FofSystemAtomicFormula
      case 196: // FofTerm
        value.move< Term::Ptr > (that.value);
        break;

      case 3: // "tpi"
      case 4: // "thf"
      case 5: // "tff"
      case 6: // "tcf"
      case 7: // "fof"
      case 8: // "cnf"
      case 9: // "fot"
      case 10: // "ite"
      case 11: // "let"
      case 12: // "@"
      case 13: // "&"
      case 14: // "$"
      case 15: // ":"
      case 16: // ","
      case 17: // "."
      case 18: // "+"
      case 19: // "="
      case 20: // "!="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "!"
      case 31: // "~"
      case 32: // "?"
      case 33: // "@-"
      case 34: // "@+"
      case 35: // "^"
      case 36: // "!!"
      case 37: // "??"
      case 38: // "@@+"
      case 39: // "@@-"
      case 40: // "@="
      case 41: // "!>"
      case 42: // "?*"
      case 43: // "<=>"
      case 44: // "=>"
      case 45: // "<="
      case 46: // "<~>"
      case 47: // "~|"
      case 48: // "~&"
      case 49: // ":="
      case 50: // "-->"
      case 51: // "<<"
      case 52: // "include"
        value.move< Token::Ptr > (that.value);
        break;

      case 164: // TfxTupleType
        value.move< TupleType::Ptr > (that.value);
        break;

      case 99: // ThfLetTypes
      case 110: // ThfTopLevelType
      case 145: // TfxLetTypes
      case 156: // TffTopLevelType
      case 158: // TffMonotype
      case 159: // TffUnitaryType
        value.move< Type::Ptr > (that.value);
        break;

      case 109: // ThfAtomTyping
      case 155: // TffAtomTyping
        value.move< TypedAtom::Ptr > (that.value);
        break;

      case 100: // ThfAtomTypingList
      case 146: // TffAtomTypingList
      case 165: // TffTypeList
        value.move< Types::Ptr > (that.value);
        break;

      case 207: // ThfUnaryConnective
      case 208: // Th1UnaryConnective
      case 212: // UnaryConnective
        value.move< UnaryConnective_t > (that.value);
        break;

      case 89: // ThfPrefixUnary
      case 135: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (that.value);
        break;

      case 242: // Number
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 87: // ThfTypedVariable
      case 129: // TfxUnitaryFormula
      case 132: // TffVariable
      case 133: // TffTypedVariable
      case 247: // Variable
        value.move< VariableTerm::Ptr > (that.value);
        break;

      case 53: // "integer"
      case 54: // "real"
      case 55: // "rational"
      case 56: // "double_quoted"
      case 57: // "lower_word"
      case 58: // "upper_word"
      case 59: // "identifier"
      case 60: // "single_quoted"
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
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
#if defined __cplusplus && 201103L <= __cplusplus
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
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
    // State.
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

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
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
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
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
      case 72: // Annotations
        yylhs.value.emplace< Annotation::Ptr > ();
        break;

      case 138: // TffPlainAtomic
      case 142: // TffSystemAtomic
      case 190: // FofPlainTerm
      case 191: // FofDefinedTerm
      case 192: // FofDefinedAtomicTerm
      case 193: // FofDefinedPlainTerm
      case 194: // FofSystemTerm
      case 197: // FofFunctionTerm
        yylhs.value.emplace< Atom::Ptr > ();
        break;

      case 111: // ThfUnitaryType
      case 112: // ThfApplyType
      case 160: // TffAtomicType
        yylhs.value.emplace< AtomType::Ptr > ();
        break;

      case 210: // NonassocConnective
      case 211: // AssocConnective
        yylhs.value.emplace< BinaryConnective_t > ();
        break;

      case 77: // ThfBinaryNonassoc
      case 78: // ThfBinaryAssoc
      case 79: // ThfOrFormula
      case 80: // ThfAndFormula
      case 81: // ThfApplyFormula
      case 121: // TffBinaryFormula
      case 122: // TffBinaryNonassoc
      case 123: // TffBinaryAssoc
      case 124: // TffOrFormula
      case 125: // TffAndFormula
      case 173: // FofBinaryFormula
      case 174: // FofBinaryNonassoc
      case 175: // FofBinaryAssoc
      case 176: // FofOrFormula
      case 177: // FofAndFormula
        yylhs.value.emplace< BinaryLogic::Ptr > ();
        break;

      case 113: // ThfBinaryType
      case 114: // ThfMappingType
      case 115: // ThfXprodType
      case 116: // ThfUnionType
      case 162: // TffMappingType
      case 163: // TffXprodType
        yylhs.value.emplace< BinaryType::Ptr > ();
        break;

      case 97: // ThfConditional
      case 143: // TfxConditional
        yylhs.value.emplace< ConditionalTerm::Ptr > ();
        break;

      case 107: // ThfConnTerm
        yylhs.value.emplace< ConnectiveAtom::Ptr > ();
        break;

      case 95: // ThfSystemAtomic
        yylhs.value.emplace< ConstantAtom::Ptr > ();
        break;

      case 227: // DefinedTerm
        yylhs.value.emplace< DefinedAtom::Ptr > ();
        break;

      case 64: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 102: // ThfLetDefn
      case 148: // TfxLetDefn
        yylhs.value.emplace< DefinitionAtom::Ptr > ();
        break;

      case 98: // ThfLet
      case 144: // TfxLet
        yylhs.value.emplace< DefinitionTerm::Ptr > ();
        break;

      case 63: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 73: // TpiFormula
      case 171: // FofFormula
        yylhs.value.emplace< FirstOrderFormula::Ptr > ();
        break;

      case 65: // AnnotatedFormula
      case 69: // FofAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
        break;

      case 230: // FormulaRole
        yylhs.value.emplace< FormulaRole::Ptr > ();
        break;

      case 96: // ThfFofFunction
        yylhs.value.emplace< FunctorAtom::Ptr > ();
        break;

      case 232: // GeneralData
        yylhs.value.emplace< GeneralData::Ptr > ();
        break;

      case 233: // GeneralFunction
        yylhs.value.emplace< GeneralFunction::Ptr > ();
        break;

      case 236: // GeneralList
        yylhs.value.emplace< GeneralList::Ptr > ();
        break;

      case 231: // GeneralTerm
        yylhs.value.emplace< GeneralTerm::Ptr > ();
        break;

      case 213: // TypeConstant
      case 214: // TypeFunctor
      case 215: // DefinedType
      case 216: // Atom
      case 217: // UntypedAtom
      case 221: // Constant
      case 222: // Functor
      case 223: // SystemConstant
      case 224: // SystemFunctor
      case 225: // DefinedConstant
      case 226: // DefinedFunctor
      case 229: // Name
      case 243: // FileName
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 237: // IncludeDefinition
        yylhs.value.emplace< IncludeDefinition::Ptr > ();
        break;

      case 218: // DefinedInfixPred
      case 219: // InfixEquality
      case 220: // InfixInequality
        yylhs.value.emplace< InfixConnective_t > ();
        break;

      case 90: // ThfInfixUnary
      case 94: // ThfDefinedInfix
      case 136: // TffInfixUnary
      case 141: // TffDefinedInfix
      case 179: // FofInfixUnary
      case 188: // FofDefinedInfixFormula
        yylhs.value.emplace< InfixLogic::Ptr > ();
        break;

      case 244: // IntegerLiteral
        yylhs.value.emplace< IntegerLiteral::Ptr > ();
        break;

      case 238: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 74: // ThfFormula
      case 75: // ThfLogicFormula
      case 76: // ThfBinaryFormula
      case 82: // ThfUnitFormula
      case 83: // ThfPreunitFormula
      case 84: // ThfUnitaryFormula
      case 88: // ThfUnaryFormula
      case 91: // ThfAtomicFormula
      case 92: // ThfPlainAtomic
      case 101: // ThfLetDefns
      case 104: // ThfUnitaryTerm
      case 119: // TffFormula
      case 120: // TffLogicFormula
      case 126: // TffUnitFormula
      case 127: // TffPreunitFormula
      case 128: // TffUnitaryFormula
      case 134: // TffUnaryFormula
      case 147: // TfxLetDefns
      case 149: // TfxLetLhs
      case 151: // TffTerm
      case 152: // TffUnitaryTerm
      case 172: // FofLogicFormula
      case 178: // FofUnaryFormula
      case 180: // FofUnitFormula
      case 181: // FofUnitaryFormula
      case 184: // FofAtomicFormula
      case 186: // FofDefinedAtomicFormula
      case 201: // CnfFormula
      case 202: // Disjunction
      case 203: // Literal
        yylhs.value.emplace< Logic::Ptr > ();
        break;

      case 105: // ThfTuple
      case 153: // TfxTuple
      case 199: // FofFormulaTuple
        yylhs.value.emplace< LogicTuple::Ptr > ();
        break;

      case 103: // ThfLetDefnList
      case 106: // ThfFormulaList
      case 108: // ThfArguments
      case 150: // TfxLetDefnList
      case 154: // TffArguments
      case 161: // TffTypeArguments
      case 195: // FofArguments
      case 200: // FofFormulaTupleList
        yylhs.value.emplace< Logics::Ptr > ();
        break;

      case 86: // ThfVariableList
      case 131: // TffVariableList
      case 183: // FofVariableList
      case 228: // NameList
      case 234: // GeneralTerms
        yylhs.value.emplace< Nodes::Ptr > ();
        break;

      case 85: // ThfQuantifiedFormula
      case 130: // TffQuantifiedFormula
      case 182: // FofQuantifiedFormula
        yylhs.value.emplace< QuantifiedLogic::Ptr > ();
        break;

      case 204: // ThfQuantifier
      case 205: // Th1Quantifier
      case 206: // Th0Quantifier
      case 209: // FofQuantifier
        yylhs.value.emplace< QuantifiedQuantifier_t > ();
        break;

      case 157: // Tf1QuantifiedType
        yylhs.value.emplace< QuantifiedType::Ptr > ();
        break;

      case 246: // RationalLiteral
        yylhs.value.emplace< RationalLiteral::Ptr > ();
        break;

      case 245: // RealLiteral
        yylhs.value.emplace< RealLiteral::Ptr > ();
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        yylhs.value.emplace< SequentLogic::Ptr > ();
        break;

      case 62: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 248: // DistinctObjectLiteral
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
        yylhs.value.emplace< StringLiteral::Ptr > ();
        break;

      case 117: // ThfSubtype
      case 166: // TffSubtype
        yylhs.value.emplace< SubType::Ptr > ();
        break;

      case 93: // ThfDefinedAtomic
      case 137: // TffAtomicFormula
      case 139: // TffDefinedAtomic
      case 140: // TffDefinedPlain
      case 185: // FofPlainAtomicFormula
      case 187: // FofDefinedPlainFormula
      case 189: // FofSystemAtomicFormula
      case 196: // FofTerm
        yylhs.value.emplace< Term::Ptr > ();
        break;

      case 3: // "tpi"
      case 4: // "thf"
      case 5: // "tff"
      case 6: // "tcf"
      case 7: // "fof"
      case 8: // "cnf"
      case 9: // "fot"
      case 10: // "ite"
      case 11: // "let"
      case 12: // "@"
      case 13: // "&"
      case 14: // "$"
      case 15: // ":"
      case 16: // ","
      case 17: // "."
      case 18: // "+"
      case 19: // "="
      case 20: // "!="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "!"
      case 31: // "~"
      case 32: // "?"
      case 33: // "@-"
      case 34: // "@+"
      case 35: // "^"
      case 36: // "!!"
      case 37: // "??"
      case 38: // "@@+"
      case 39: // "@@-"
      case 40: // "@="
      case 41: // "!>"
      case 42: // "?*"
      case 43: // "<=>"
      case 44: // "=>"
      case 45: // "<="
      case 46: // "<~>"
      case 47: // "~|"
      case 48: // "~&"
      case 49: // ":="
      case 50: // "-->"
      case 51: // "<<"
      case 52: // "include"
        yylhs.value.emplace< Token::Ptr > ();
        break;

      case 164: // TfxTupleType
        yylhs.value.emplace< TupleType::Ptr > ();
        break;

      case 99: // ThfLetTypes
      case 110: // ThfTopLevelType
      case 145: // TfxLetTypes
      case 156: // TffTopLevelType
      case 158: // TffMonotype
      case 159: // TffUnitaryType
        yylhs.value.emplace< Type::Ptr > ();
        break;

      case 109: // ThfAtomTyping
      case 155: // TffAtomTyping
        yylhs.value.emplace< TypedAtom::Ptr > ();
        break;

      case 100: // ThfAtomTypingList
      case 146: // TffAtomTypingList
      case 165: // TffTypeList
        yylhs.value.emplace< Types::Ptr > ();
        break;

      case 207: // ThfUnaryConnective
      case 208: // Th1UnaryConnective
      case 212: // UnaryConnective
        yylhs.value.emplace< UnaryConnective_t > ();
        break;

      case 89: // ThfPrefixUnary
      case 135: // TffPrefixUnary
        yylhs.value.emplace< UnaryLogic::Ptr > ();
        break;

      case 242: // Number
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 87: // ThfTypedVariable
      case 129: // TfxUnitaryFormula
      case 132: // TffVariable
      case 133: // TffTypedVariable
      case 247: // Variable
        yylhs.value.emplace< VariableTerm::Ptr > ();
        break;

      case 53: // "integer"
      case 54: // "real"
      case 55: // "rational"
      case 56: // "double_quoted"
      case 57: // "lower_word"
      case 58: // "upper_word"
      case 59: // "identifier"
      case 60: // "single_quoted"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
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
  case 2:
#line 357 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      m_specification.setDefinitions( yystack_[0].value.as< Definitions::Ptr > () );
  }
#line 2139 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 3:
#line 364 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = yystack_[1].value.as< Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as< Definition::Ptr > ());
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 2149 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 4:
#line 370 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as< Definition::Ptr > () );
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 2159 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 5:
#line 380 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2167 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 6:
#line 384 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< IncludeDefinition::Ptr > ();
  }
#line 2175 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 7:
#line 391 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2183 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 8:
#line 395 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2191 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 9:
#line 399 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2199 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 10:
#line 403 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2207 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 11:
#line 407 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2215 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 12:
#line 411 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 2223 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 13:
#line 427 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2230 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 14:
#line 430 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2237 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 15:
#line 435 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2244 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 16:
#line 438 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2251 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 17:
#line 443 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2258 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 18:
#line 446 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2265 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 19:
#line 451 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< FormulaRole::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2276 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 20:
#line 458 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< FormulaRole::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
  }
#line 2290 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 21:
#line 470 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2297 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 22:
#line 473 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2304 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 23:
#line 478 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2311 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 24:
#line 481 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2318 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 25:
#line 524 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as< GeneralTerm::Ptr > ());
    //source
  }
#line 2327 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 26:
#line 529 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source, optionalInfo
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as< GeneralTerm::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralList::Ptr > ());
  }
#line 2336 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 27:
#line 559 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = yystack_[0].value.as< FirstOrderFormula::Ptr > ();
  }
#line 2344 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 28:
#line 566 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2352 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 29:
#line 570 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 2360 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 30:
#line 574 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SubType::Ptr > ();
  }
#line 2368 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 31:
#line 578 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 2376 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 32:
#line 585 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2384 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 33:
#line 589 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2392 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 34:
#line 593 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2400 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 35:
#line 597 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2408 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 36:
#line 604 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2416 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 37:
#line 608 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2424 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 38:
#line 612 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 2432 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 39:
#line 619 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2440 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 40:
#line 626 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2448 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 41:
#line 630 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2456 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 42:
#line 634 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2464 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 43:
#line 641 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2473 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 44:
#line 646 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2482 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 45:
#line 654 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2491 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 46:
#line 659 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2500 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 47:
#line 667 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2509 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 48:
#line 672 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2518 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 49:
#line 680 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2526 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 50:
#line 684 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2534 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 51:
#line 688 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2542 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 52:
#line 695 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2550 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 53:
#line 699 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 2558 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 54:
#line 706 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 2566 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 55:
#line 710 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2574 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 56:
#line 714 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2582 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 57:
#line 718 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 2593 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 58:
#line 728 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), variables, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2602 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 59:
#line 736 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 2612 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 60:
#line 742 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 2623 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 61:
#line 752 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto var = yystack_[2].value.as< VariableTerm::Ptr > ();
	var->setColon(yystack_[1].value.as< Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as< Type::Ptr > ();
	var->setType(type);
  }
#line 2634 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 62:
#line 762 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 2642 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 63:
#line 766 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2650 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 64:
#line 773 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2658 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 65:
#line 780 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2666 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 66:
#line 787 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2674 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 67:
#line 791 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 2682 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 68:
#line 795 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< ConstantAtom::Ptr > ();
  }
#line 2690 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 69:
#line 799 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< FunctorAtom::Ptr > ();
  }
#line 2698 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 70:
#line 806 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2706 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 71:
#line 810 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 2714 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 72:
#line 817 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2722 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 73:
#line 821 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< ConditionalTerm::Ptr > ();
  }
#line 2730 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 74:
#line 825 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinitionTerm::Ptr > ();
  }
#line 2738 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 75:
#line 829 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< ConnectiveAtom::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Term::Ptr > () = logic;
  }
#line 2749 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 76:
#line 836 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 2757 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 77:
#line 843 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2765 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 78:
#line 850 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConstantAtom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2773 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 79:
#line 857 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2781 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 80:
#line 861 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2789 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 81:
#line 865 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2797 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 82:
#line 872 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Logic::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2805 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 83:
#line 879 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Type::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2813 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 84:
#line 886 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 2821 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 85:
#line 890 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2829 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 86:
#line 897 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 2839 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 87:
#line 903 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 2850 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 88:
#line 913 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinitionAtom::Ptr > ();
  }
#line 2858 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 89:
#line 917 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2866 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 90:
#line 924 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2874 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 91:
#line 931 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//could be of type DefinitionAtoms, but Logics is expected
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2885 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 92:
#line 938 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2896 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 93:
#line 948 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2904 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 94:
#line 952 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2912 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 95:
#line 956 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 2923 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 96:
#line 966 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2931 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 97:
#line 970 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2939 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 98:
#line 977 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2949 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 99:
#line 983 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2960 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 100:
#line 993 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< BinaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 2969 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 101:
#line 998 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< BinaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 2978 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 102:
#line 1003 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< InfixConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 2987 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 103:
#line 1008 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< UnaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 2996 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 104:
#line 1016 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logics::Ptr > () = yystack_[0].value.as< Logics::Ptr > ();
  }
#line 3004 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 105:
#line 1023 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3012 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 106:
#line 1027 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< TypedAtom::Ptr > () = type;
  }
#line 3023 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 107:
#line 1037 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3031 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 108:
#line 1041 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3039 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 109:
#line 1045 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3047 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 110:
#line 1052 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3055 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 111:
#line 1059 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< BinaryLogic::Ptr > ());
  }
#line 3063 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 112:
#line 1066 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3071 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 113:
#line 1070 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3079 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 114:
#line 1074 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3087 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 115:
#line 1082 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3095 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 116:
#line 1086 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< BinaryType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3103 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 117:
#line 1094 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3111 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 118:
#line 1098 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3119 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 119:
#line 1106 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3127 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 120:
#line 1110 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3135 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 121:
#line 1117 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3143 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 122:
#line 1124 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 3151 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 123:
#line 1128 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< SequentLogic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< SequentLogic::Ptr > () = logic;
  }
#line 3162 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 124:
#line 1139 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3170 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 125:
#line 1143 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 3178 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 126:
#line 1147 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SubType::Ptr > ();
  }
#line 3186 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 127:
#line 1151 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 3194 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 128:
#line 1158 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3202 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 129:
#line 1162 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3210 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 130:
#line 1166 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3218 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 131:
#line 1170 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3226 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 132:
#line 1177 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3234 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 133:
#line 1181 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3242 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 134:
#line 1188 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3250 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 135:
#line 1195 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3258 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 136:
#line 1199 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3266 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 137:
#line 1206 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3275 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 138:
#line 1211 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3284 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 139:
#line 1219 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3293 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 140:
#line 1224 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3302 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 141:
#line 1232 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3310 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 142:
#line 1236 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3318 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 143:
#line 1240 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3326 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 144:
#line 1247 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3334 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 145:
#line 1251 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 3342 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 146:
#line 1258 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 3350 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 147:
#line 1262 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3358 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 148:
#line 1266 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3366 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 149:
#line 1270 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3377 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 150:
#line 1280 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3385 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 151:
#line 1287 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yystack_[3].location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), list, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3394 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 152:
#line 1295 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3405 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 153:
#line 1302 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3416 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 154:
#line 1312 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3424 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 155:
#line 1316 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3432 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 156:
#line 1323 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variable = yystack_[2].value.as< VariableTerm::Ptr > ();
	variable->setColon(yystack_[1].value.as< Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as< AtomType::Ptr > (); //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	yylhs.value.as< VariableTerm::Ptr > () = variable;
  }
#line 3444 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 157:
#line 1334 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 3452 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 158:
#line 1338 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3460 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 159:
#line 1345 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3468 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 160:
#line 1352 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3476 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 161:
#line 1359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3484 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 162:
#line 1363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3492 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 163:
#line 1367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3500 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 164:
#line 1374 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3508 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 165:
#line 1378 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3516 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 166:
#line 1385 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3524 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 167:
#line 1392 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3532 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 168:
#line 1396 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3540 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 169:
#line 1400 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< ConditionalTerm::Ptr > ();
  }
#line 3548 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 170:
#line 1404 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinitionTerm::Ptr > ();
  }
#line 3556 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 171:
#line 1411 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3564 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 172:
#line 1418 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3572 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 173:
#line 1422 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3580 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 174:
#line 1429 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Logic::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3588 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 175:
#line 1436 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Type::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3596 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 176:
#line 1443 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 3604 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 177:
#line 1447 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3612 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 178:
#line 1454 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3622 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 179:
#line 1460 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3633 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 180:
#line 1470 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinitionAtom::Ptr > ();
  }
#line 3641 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 181:
#line 1474 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3649 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 182:
#line 1481 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3657 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 183:
#line 1488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3665 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 184:
#line 1492 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3673 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 185:
#line 1499 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3683 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 186:
#line 1505 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3694 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 187:
#line 1515 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3702 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 188:
#line 1519 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3710 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 189:
#line 1523 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3718 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 190:
#line 1530 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3726 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 191:
#line 1534 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3734 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 192:
#line 1538 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3742 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 193:
#line 1542 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3750 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 194:
#line 1546 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3761 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 195:
#line 1556 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3769 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 196:
#line 1560 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3777 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 197:
#line 1567 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3787 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 198:
#line 1573 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3798 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 199:
#line 1583 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3806 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 200:
#line 1587 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< TypedAtom::Ptr > () = type;
  }
#line 3817 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 201:
#line 1597 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3825 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 202:
#line 1601 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3833 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 203:
#line 1605 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< QuantifiedType::Ptr > ();
  }
#line 3841 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 204:
#line 1609 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< Type::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3852 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 205:
#line 1619 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3860 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 206:
#line 1626 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3868 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 207:
#line 1630 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3879 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 208:
#line 1640 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3887 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 209:
#line 1644 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3898 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 210:
#line 1654 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3906 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 211:
#line 1658 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3914 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 212:
#line 1662 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto functor = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::TYPE);
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, functor);
  }
#line 3923 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 213:
#line 1667 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 3931 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 214:
#line 1671 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< TupleType::Ptr > ());
  }
#line 3939 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 215:
#line 1678 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
  }
#line 3948 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 216:
#line 1683 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3959 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 217:
#line 1693 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3967 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 218:
#line 1700 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3975 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 219:
#line 1704 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3983 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 220:
#line 1711 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3991 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 221:
#line 1718 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 4001 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 222:
#line 1724 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 4012 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 223:
#line 1734 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 4020 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 224:
#line 1741 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 4028 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 225:
#line 1745 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< SequentLogic::Ptr > () = sequent;
  }
#line 4039 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 226:
#line 1756 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4046 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 227:
#line 1759 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4053 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 228:
#line 1765 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4060 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 229:
#line 1768 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4067 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 230:
#line 1774 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4074 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 231:
#line 1782 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = libtptp::make< FirstOrderFormula >(yylhs.location, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4082 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 232:
#line 1786 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = libtptp::make< FirstOrderFormula >(yylhs.location, yystack_[0].value.as< SequentLogic::Ptr > ());
  }
#line 4090 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 233:
#line 1793 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4098 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 234:
#line 1797 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4106 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 235:
#line 1801 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4114 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 236:
#line 1808 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4122 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 237:
#line 1812 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4130 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 238:
#line 1819 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4138 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 239:
#line 1826 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4146 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 240:
#line 1830 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4154 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 241:
#line 1837 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4163 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 242:
#line 1842 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4172 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 243:
#line 1850 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4181 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 244:
#line 1855 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4190 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 245:
#line 1863 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4198 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 246:
#line 1867 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4206 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 247:
#line 1874 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 4214 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 248:
#line 1881 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4222 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 249:
#line 1885 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4230 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 250:
#line 1892 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 4238 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 251:
#line 1896 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4246 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 252:
#line 1900 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 4257 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 253:
#line 1910 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), variables, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4266 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 254:
#line 1918 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< Nodes >(yylhs.location);
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 4277 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 255:
#line 1925 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto variables = yystack_[2].value.as< Nodes::Ptr > ();
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 4288 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 256:
#line 1935 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4296 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 257:
#line 1939 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4304 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 258:
#line 1943 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4312 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 259:
#line 1950 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4320 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 260:
#line 1957 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4328 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 261:
#line 1961 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4336 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 262:
#line 1968 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4344 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 263:
#line 1975 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 4352 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 264:
#line 1982 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4360 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 265:
#line 1989 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4368 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 266:
#line 1993 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4376 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 267:
#line 2000 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 4384 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 268:
#line 2004 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4392 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 269:
#line 2011 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4400 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 270:
#line 2018 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4408 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 271:
#line 2022 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4416 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 272:
#line 2029 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4424 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 273:
#line 2033 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4432 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 274:
#line 2040 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto terms = libtptp::make< Logics >(yylhs.location);
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4442 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 275:
#line 2046 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto terms = yystack_[2].value.as< Logics::Ptr > ();
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4453 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 276:
#line 2056 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4461 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 277:
#line 2060 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 4469 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 278:
#line 2067 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4477 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 279:
#line 2071 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4485 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 280:
#line 2075 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4493 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 281:
#line 2082 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 4501 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 282:
#line 2086 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
  }
#line 4511 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 283:
#line 2095 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4519 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 284:
#line 2099 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4527 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 285:
#line 2106 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4537 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 286:
#line 2112 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4548 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 287:
#line 2122 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4556 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 288:
#line 2126 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 4567 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 289:
#line 2136 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4575 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 290:
#line 2140 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4584 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 291:
#line 2148 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4592 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 292:
#line 2152 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4601 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 293:
#line 2157 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4609 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 294:
#line 2164 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4617 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 295:
#line 2168 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4625 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 296:
#line 2172 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4633 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 297:
#line 2179 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
#line 4641 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 298:
#line 2183 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
#line 4649 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 299:
#line 2190 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::CARET);
  }
#line 4657 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 300:
#line 2194 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::ATPLUS);
  }
#line 4665 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 301:
#line 2198 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::ATMINUS);
  }
#line 4673 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 302:
#line 2205 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = yystack_[0].value.as< UnaryConnective_t > ();
  }
#line 4681 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 303:
#line 2209 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = yystack_[0].value.as< UnaryConnective_t > ();
  }
#line 4689 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 304:
#line 2216 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
#line 4697 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 305:
#line 2220 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
#line 4705 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 306:
#line 2224 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
#line 4713 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 307:
#line 2228 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
#line 4721 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 308:
#line 2232 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::EQUALITY);
  }
#line 4729 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 309:
#line 2239 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4737 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 310:
#line 2243 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4745 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 311:
#line 2252 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 4753 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 312:
#line 2256 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 4761 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 313:
#line 2260 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 4769 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 314:
#line 2264 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 4777 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 315:
#line 2268 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 4785 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 316:
#line 2272 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 4793 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 317:
#line 2279 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 4801 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 318:
#line 2283 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 4809 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 319:
#line 2290 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 4817 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 320:
#line 2297 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4825 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 321:
#line 2304 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4833 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 322:
#line 2311 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4841 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 323:
#line 2318 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4849 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 324:
#line 2322 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4857 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 325:
#line 2329 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4865 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 326:
#line 2333 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4873 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 327:
#line 2340 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = yystack_[0].value.as< InfixConnective_t > ();
  }
#line 4881 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 328:
#line 2347 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 4889 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 329:
#line 2354 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
//EXCLAMATION EQUAL
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 4898 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 330:
#line 2362 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4906 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 331:
#line 2369 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4914 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 332:
#line 2376 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4922 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 333:
#line 2383 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4930 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 334:
#line 2390 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4938 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 335:
#line 2397 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4946 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 336:
#line 2404 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 4954 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 337:
#line 2408 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4962 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 338:
#line 2415 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< Identifier::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 4974 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 339:
#line 2423 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj add delimiter
	const auto list = yystack_[2].value.as< Nodes::Ptr > ();
	const auto name = yystack_[0].value.as< Identifier::Ptr > ();
	//name->prefix().add($2); //setDelimiter
	list->add(name);
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 4987 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 340:
#line 2435 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4995 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 341:
#line 2439 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< IntegerLiteral::Ptr > ());
  }
#line 5003 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 342:
#line 2446 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaRole::Ptr > () = libtptp::make< FormulaRole >( yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > () );
  }
#line 5011 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 343:
#line 2453 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralData::Ptr > ();
  }
#line 5019 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 344:
#line 2457 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as< GeneralData::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralTerm::Ptr > ());
  }
#line 5027 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 345:
#line 2461 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralList::Ptr > ();
  }
#line 5035 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 346:
#line 2468 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 5043 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 347:
#line 2472 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< GeneralFunction::Ptr > ());
  }
#line 5051 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 348:
#line 2476 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 5059 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 349:
#line 2480 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 5067 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 350:
#line 2484 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 5075 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 351:
#line 2488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//$$ = libtptp::make< GeneralData >(@$, $1);
	//TODO: @moosbruggerj remove wrong token
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, uToken);
  }
#line 5085 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 352:
#line 2497 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto name = libtptp::make< Identifier >(yystack_[3].location, yystack_[3].value.as< StringLiteral::Ptr > ());
	yylhs.value.as< GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, name, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5094 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 353:
#line 2505 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 5104 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 354:
#line 2511 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma
	
    auto terms = yystack_[2].value.as< Nodes::Ptr > ();
    terms->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
    yylhs.value.as< Nodes::Ptr > () = terms;
  }
#line 5116 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 355:
#line 2530 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 5123 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 356:
#line 2533 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 5130 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 357:
#line 2536 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 5137 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 358:
#line 2539 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 5144 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 359:
#line 2542 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 5151 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 360:
#line 2548 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5160 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 361:
#line 2553 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 362:
#line 2562 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5178 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 363:
#line 2567 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Identifier::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< ListLiteral::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5186 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 364:
#line 2574 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< ListLiteral::Ptr > () = list;
  }
#line 5195 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 365:
#line 2602 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 5203 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 366:
#line 2606 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 5211 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 367:
#line 2613 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 5219 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 368:
#line 2620 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 5227 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 369:
#line 2627 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< IntegerLiteral::Ptr > ();
  }
#line 5235 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 370:
#line 2631 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RealLiteral::Ptr > ();
  }
#line 5243 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 371:
#line 2635 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RationalLiteral::Ptr > ();
  }
#line 5251 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 372:
#line 2642 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make<Identifier>(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 5259 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 373:
#line 2649 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as< std::string > ());
  }
#line 5267 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 374:
#line 2656 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5275 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 375:
#line 2662 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5283 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 376:
#line 2669 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto literal = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
	auto identifier = libtptp::make< Identifier >(yylhs.location, literal);
	yylhs.value.as< VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 5293 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 377:
#line 2678 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5301 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 378:
#line 2685 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5309 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 379:
#line 2692 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5317 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 380:
#line 2699 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 5325 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 381:
#line 2706 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 5333 "GrammarParser.cpp" // lalr1.cc:906
    break;


#line 5337 "GrammarParser.cpp" // lalr1.cc:906
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
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

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Parser::yypact_ninf_ = -583;

  const short Parser::yytable_ninf_ = -327;

  const short
  Parser::yypact_[] =
  {
     424,    13,    26,    94,   119,   121,   142,   180,   213,   424,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,   173,
     173,   173,   173,   173,   173,   156,  -583,  -583,  -583,  -583,
    -583,   211,  -583,  -583,  -583,  -583,   258,   262,   273,   291,
     294,    47,  -583,   260,   260,   260,   260,   260,   260,   222,
     310,   344,  -583,   377,   379,   384,   407,   410,   173,   411,
    -583,  1041,  1168,  1263,  1428,  1041,  1783,   106,  -583,   418,
     125,  1041,  1367,  -583,  -583,  -583,  -583,  -583,  -583,  -583,
     188,  -583,  -583,  -583,  -583,  -583,   420,   449,   176,  -583,
    1256,   370,  -583,  -583,  -583,  -583,  -583,  -583,  -583,   118,
    -583,  -583,   358,   402,   462,  -583,  -583,   415,   444,  1380,
    -583,   489,  -583,   491,  -583,   494,  -583,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,   327,  2278,
     857,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,   195,  -583,  -583,  -583,  -583,   481,   504,   522,  1200,
    1117,  -583,   299,  -583,  -583,   474,  -583,  -583,   574,  -583,
    -583,  -583,  -583,   462,   482,  -583,   103,  -583,  -583,   531,
     560,  -583,  -583,   557,  -583,  -583,  1552,  -583,  -583,  -583,
     209,   221,   579,   228,   583,  -583,   597,  -583,   477,   362,
    1263,   911,   342,  -583,  -583,  -583,  -583,   568,   617,  1430,
     375,  -583,  -583,   500,  -583,  -583,   573,  -583,  -583,  -583,
     524,  -583,  -583,  -583,   462,   594,  -583,  -583,  -583,   610,
     771,   229,   221,   628,   228,   641,  -583,   656,  -583,   640,
    1834,   661,   945,  -583,   349,  -583,  -583,  -583,  -583,  -583,
     664,  -583,   636,   686,   688,   461,   799,   540,   173,  -583,
    -583,   654,  -583,   699,   701,  1380,  -583,  -583,    39,  1003,
     708,  1380,  1380,  1380,  1380,  -583,  -583,  -583,  -583,  -583,
    -583,  1380,  -583,  -583,   945,  -583,   945,   702,   680,  -583,
    -583,  -583,   945,   945,   945,   744,   749,  -583,  -583,   750,
     769,   777,   788,  1552,  -583,  -583,   793,  -583,  2644,  -583,
    -583,  -583,   277,  -583,  -583,  1003,   797,  1688,  1688,  1688,
    1688,  1688,  1688,  1688,   679,   679,   812,   763,   763,   763,
     763,   763,   680,  2644,  -583,  -583,  -583,  -583,  -583,  1688,
     136,  1688,  1688,  1688,   815,   817,   823,   825,   826,  1318,
    -583,  -583,  -583,   650,   323,  -583,  -583,   660,  1003,   832,
    1318,  1318,  1318,  1318,  1318,   786,   786,   827,   680,  1318,
    -583,  -583,  -583,  -583,  -583,  1028,   136,  1318,  1318,  1318,
     330,    29,   680,  -583,   839,  1003,   834,   799,  1003,   844,
    1003,   845,  -583,  -583,  -583,  -583,  1380,  -583,   759,  1095,
     841,   848,   850,  -583,  -583,  -583,   847,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,   364,  -583,   552,  -583,   581,   589,  1688,   669,
     662,  -583,  -583,  -583,  1688,  -583,   851,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  2644,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,   853,  -583,  -583,
    -583,   421,  -583,   859,   855,   522,   863,   867,  -583,   853,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,
     869,   861,   864,   878,  1318,   935,   677,  -583,  -583,  -583,
    1318,  -583,   879,  -583,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,  1318,  -583,  -583,  -583,  -583,  -583,   428,  -583,
    -583,   890,   885,   862,  1028,  1028,   893,  -583,  -583,   891,
     712,  -583,  -583,  -583,   900,  -583,  -583,  -583,  -583,  -583,
     598,   603,   624,   908,  -583,   463,   901,  -583,  -583,   902,
    -583,   904,  -583,  -583,   906,   907,   909,   910,   915,  -583,
    -583,   468,   916,   914,  1003,  1003,   680,   923,   945,  -583,
    -583,  -583,   913,   445,   445,   928,  -583,  -583,   922,   925,
     680,   933,  1688,  -583,  -583,  -583,  -583,   934,   330,   937,
    -583,  -583,   938,   932,   680,   942,   846,  -583,   939,   721,
     630,  -583,   483,   680,   846,   846,  -583,  -583,  -583,   947,
     946,   953,   955,  1168,  1263,  1041,  1783,   945,  1003,  -583,
    -583,  -583,  -583,   645,  -583,  1380,  -583,  1688,   487,  -583,
    2399,  -583,  -583,  -583,  1688,  -583,  1318,   519,  -583,   161,
    -583,  -583,  -583,  1318,  -583,  -583,   846,  -583,   846,  1028,
    -583,   520,  -583,  -583,   673,  1783,  -583,  -583,  -583,   957,
     958,   960,   968,   972,  -583,  -583,  -583,   980,   445,  -583,
     857,   961,   988,  -583,  -583,   990,   330,  -583,   911,  -583,
     993,  -583,   963,  -583,  -583,  -583,  -583,  -583,   998,   846,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  1688,  -583,   961,
    -583,   545,  1688,  1168,  1318,  -583,   965,  -583,   565,   286,
    1318,  1318,   227,  -583,   996,  1688,  -583,  -583,   997,  1006,
     163,  -583,  1007,  -583,   585,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,  -583,   585,  -583,  1008,   992,  -583
  };

  const unsigned short
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     5,     7,     8,     9,    10,    11,    12,     6,     0,
       0,     0,     0,     0,     0,     0,     1,     3,   373,   378,
     379,     0,   340,   341,   365,   366,     0,     0,     0,     0,
       0,     0,   372,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   342,     0,     0,     0,     0,     0,     0,     0,
     362,     0,     0,     0,     0,     0,     0,     0,   338,     0,
       0,     0,     0,   309,   319,   310,   374,   375,   377,   376,
       0,    27,   231,   233,   236,   237,   239,   240,   249,   246,
       0,   248,   250,   251,   256,   257,   260,   261,   258,   259,
     279,   268,   262,   264,     0,   276,   232,     0,     0,     0,
     265,   330,   272,   332,   270,   334,   267,   331,   335,   333,
     336,   369,   370,   371,   277,   337,   367,   368,     0,     0,
       0,   301,   300,   299,   304,   305,   306,   307,   308,   297,
     298,     0,    28,    34,    36,    37,    40,    41,    42,     0,
      49,    54,    50,    62,    63,    55,    66,    67,    51,    68,
      69,    73,    74,     0,    71,    29,     0,    38,   112,   113,
     114,    30,    31,     0,   296,   295,     0,   303,   294,   302,
       0,    70,   330,    78,   332,    72,   334,    76,    56,     0,
       0,     0,     0,   124,   130,   132,   133,   135,   136,     0,
     141,   148,   146,   142,   157,   158,   147,   161,   162,   166,
     143,   163,   169,   170,     0,   192,   125,   126,   127,     0,
       0,     0,   164,   330,   172,   332,   167,   334,   191,   150,
       0,     0,     0,   227,     0,   226,   228,   293,   291,   229,
     287,   289,     0,   265,   272,     0,     0,     0,     0,   364,
     363,     0,   380,     0,     0,     0,   283,   285,     0,     0,
       0,     0,     0,     0,     0,   311,   312,   313,   314,   315,
     316,     0,   328,   329,     0,   327,     0,     0,     0,   249,
     245,   248,     0,     0,     0,     0,     0,   318,   317,     0,
       0,     0,     0,   103,   100,   101,     0,   102,     0,    96,
      98,    71,     0,    70,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    52,    53,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   187,   197,   189,     0,   164,   172,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   144,   145,   147,   150,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
       0,     0,   339,   381,   252,   282,     0,   284,     0,     0,
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
     154,   155,     0,     0,     0,     0,     0,   199,   203,     0,
     201,   202,   214,   210,   320,   211,   321,   322,   213,   223,
       0,     0,     0,     0,   288,     0,     0,    17,   290,     0,
      19,     0,    21,   286,     0,     0,     0,     0,     0,   360,
     353,     0,     0,     0,     0,     0,     0,     0,     0,   266,
     273,   271,     0,     0,     0,     0,    84,    99,     0,     0,
       0,     0,     0,    57,    79,    81,    80,     0,     0,     0,
     176,   198,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   221,     0,     0,     0,     0,   165,   173,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   361,
      24,    26,   344,     0,   255,     0,   275,     0,     0,    86,
       0,    14,    95,    60,     0,    61,     0,     0,   178,     0,
      16,   194,   153,     0,   156,   204,     0,   209,     0,     0,
     220,     0,   217,   215,     0,     0,    18,    20,    22,     0,
       0,     0,     0,     0,   354,   352,   253,     0,     0,    85,
       0,     0,     0,    88,    58,     0,     0,   177,     0,   183,
       0,   180,     0,   184,   151,   218,   219,   222,     0,     0,
     212,   230,   355,   356,   357,   358,   359,     0,    87,    98,
      91,     0,     0,     0,     0,   179,   161,   185,     0,   189,
       0,     0,     0,   216,     0,     0,    89,    90,     0,     0,
       0,   181,     0,   182,     0,   205,   206,    82,    92,    83,
     174,   186,   175,     0,   208,     0,     0,   207
  };

  const short
  Parser::yypgoto_[] =
  {
    -583,  -583,  -583,  1022,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,   -23,  -583,  -550,    22,  -583,  -583,  -583,  -583,  -583,
    -291,  -220,  -583,  -164,  -583,  -583,   473,  -213,  -135,  -583,
     395,  -583,  -583,   162,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,  -533,  -583,   460,   -46,  -120,  -583,   455,  -115,   472,
    -193,  -583,  -583,  -293,  -583,  -583,  -583,   917,   442,   -31,
    -583,  -583,  -583,  -583,  -583,  -273,  -583,  -145,  -583,  -583,
    -351,   464,  -583,  -249,   819,  -583,  -187,  -582,  -583,  -583,
    -240,  -583,  -583,  -583,  -583,  -583,  -583,  -539,  -583,  -583,
    -456,   352,   218,    43,   -55,  -398,  -583,  -583,  -474,   102,
    -583,   343,  -583,  -583,  -583,  -583,   874,  -583,  -583,  -583,
     -54,   -43,  -583,  -583,  -583,  -583,  -583,   -91,   -47,   -86,
     -74,  -583,  -583,   -51,  -583,  -583,  -583,  -583,  -583,  -234,
    -583,  -583,  -230,  -216,   506,  -212,  -583,   981,   776,  -583,
     -44,  -185,   690,  -583,  -583,  -583,  -104,  -583,  2137,    -8,
    -583,  2287,  -583,  -583,  -583,   704,    23,  -106,   -98,   -40,
     392,   761,   912,  1281,  1432,  1759,  1903,  -583,   393,   735,
    -330,  -583,  -583,   509,  -583,   525,  -583,  -583,   -19,  -338,
    -583,   120,  -583,   383,  -583,  -583,   -56,   175,   709,  1040,
    -583,  -583
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   390,    80,   141,   300,   143,   144,   145,   146,   147,
     148,   149,   324,   150,   151,   451,   452,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   555,   608,
     652,   653,   681,   163,   301,   470,   290,   471,   165,   458,
     166,   460,   167,   168,   169,   170,   171,   172,   192,   341,
     194,   195,   196,   197,   198,   199,   360,   200,   201,   202,
     498,   499,   500,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   569,   617,   660,   661,   662,   688,
     342,   214,   479,   344,   337,   507,   508,   705,   509,   510,
     634,   511,   580,   512,   582,   217,   218,   234,   235,   236,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   412,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   414,   104,   105,   106,   107,   258,
     239,   240,   241,   173,   174,   175,   176,   177,   178,   294,
     295,   179,   513,   514,   515,   462,   242,   274,   275,   276,
     303,   182,   304,   184,   185,   186,   187,    67,    31,    51,
     391,   392,   393,   541,   394,   395,    18,    59,   117,   118,
     119,   120,    41,   121,   122,   123,   124,   125,    34,    35,
     126,   127
  };

  const short
  Parser::yytable_[] =
  {
      32,    32,    32,    32,    32,    32,   188,   229,   216,   233,
     302,   245,   325,   238,   291,   238,   164,   237,   279,   237,
     374,   525,   247,   280,   571,   293,   448,   517,   253,   257,
     579,   297,   193,   363,    19,   281,   461,   659,   455,    32,
     406,   326,   406,   639,   407,   371,   407,    20,   406,   406,
     406,   524,   407,   407,   407,   386,   377,   314,   408,   540,
     408,   371,   409,    49,   410,   387,   408,   408,   408,    50,
     415,   415,   415,   188,   188,   361,   686,   484,   488,   489,
     490,   491,   271,   164,   142,   180,   221,   428,   432,   433,
     434,   435,   436,   437,   430,   430,   430,   430,   430,   430,
     430,   486,   486,   486,   486,   486,   578,   581,   355,   456,
     487,   487,   487,   487,   487,    21,   430,   680,   659,   687,
     328,   317,   248,   315,   445,   446,   447,   449,   450,   325,
     249,   318,   319,   698,   229,   229,   459,  -278,  -278,   251,
      22,   313,    23,   429,   429,   429,   429,   429,   429,   429,
      70,   289,   296,   444,   444,   444,   444,   444,   326,   336,
     655,   711,   708,    24,   364,   457,   517,   517,   493,   493,
     279,   279,   279,   279,   356,   401,   402,   403,   404,   238,
     279,   373,   252,   237,   658,   405,   191,   281,   281,   281,
     281,   354,  -234,    29,   293,   238,    30,   281,  -234,   237,
     297,    25,  -234,   398,   259,   485,   485,   485,   485,   485,
     260,   305,   253,    26,   602,   540,    30,   306,    29,   293,
      29,    30,   413,    30,   329,   297,    28,    43,   699,    32,
      29,   667,   631,    30,   702,   703,  -325,   328,   517,   716,
     396,   503,   188,  -326,   365,    58,   517,   517,   704,   398,
     505,   188,   188,   188,   188,   188,   188,   188,   441,   441,
     330,   328,   328,   328,   328,   328,   453,   188,   644,   461,
     443,   455,  -325,   188,    44,   188,   188,   188,    45,  -326,
     366,   215,   426,   229,    29,    79,   396,    30,   517,    46,
     517,   517,   398,   424,   229,   229,   229,   229,   229,   495,
     495,   425,   501,   229,   556,  -192,  -192,    47,   336,   518,
      48,   229,   229,   229,   406,   -33,   501,    29,   407,   398,
     289,   -33,   398,   -33,   398,   482,   238,    60,   502,   396,
     237,   517,   408,   398,   293,  -184,   606,   285,   286,   480,
     297,   251,   456,   533,   523,   454,   516,   481,   -33,   430,
     664,   370,   526,   463,   517,   529,   396,   531,   348,   396,
      61,   396,   188,   406,   349,   375,   517,   407,   188,   459,
     396,   376,   334,   335,   486,   517,   251,  -269,  -269,   397,
     546,   408,   188,   487,   252,   643,  -235,    29,   547,   463,
      30,  -128,  -235,    62,   654,    63,  -235,  -128,   457,  -128,
      64,   430,    33,    33,    33,    33,    33,    33,   215,   343,
     520,   521,   522,    36,    37,    38,    39,    40,   229,   252,
     570,  -280,  -280,    65,   229,   397,    66,     1,     2,     3,
       4,     5,     6,    69,   399,   250,   229,   560,   291,   609,
     552,    33,   296,   567,   574,   561,   557,   261,   518,   518,
     429,    68,   575,   110,   181,   222,   243,   110,   110,   523,
     559,   573,   262,   110,   110,   277,   553,   278,   397,   431,
     431,   431,   431,   431,   431,   431,     7,   378,   485,   574,
     399,   272,   273,   379,   598,   516,   516,   589,   398,   398,
     604,   431,   599,   -93,   -93,   397,   -94,   -94,   397,   629,
     397,   110,    29,   648,   453,    30,   188,   630,   307,   397,
     282,   649,   283,   618,   279,   284,  -129,   308,   501,   646,
     518,   181,  -129,   399,  -129,   396,   396,   501,   518,   518,
     302,   281,   316,   678,   309,   656,   574,   188,   229,   216,
    -131,   641,   398,   657,   668,   238,  -131,   164,  -131,   237,
     399,   188,   642,   399,   188,   399,   380,   516,   188,   320,
     229,   695,   381,   193,   399,   516,   516,   229,   548,   696,
     518,   327,   518,   518,   549,   497,   296,   296,   321,   396,
     322,   700,   222,   345,   238,   343,   343,   343,   237,   701,
     -35,   671,  -190,  -190,   188,   350,   -35,   548,   -35,   503,
     331,   685,   229,   550,   332,   548,   713,   516,   505,   516,
     516,   551,   345,   518,   480,   142,   180,   221,   333,   480,
     586,   188,   243,   -35,   110,   587,   188,   188,   229,   647,
     351,    33,   651,   358,   229,   229,   518,   164,   110,   188,
     480,   382,    29,    79,   357,    30,   588,   110,   518,   367,
     516,   365,   627,   110,   110,   110,   110,   518,   628,  -193,
    -193,   598,   368,   110,   397,   397,   110,   645,   110,  -192,
    -192,   296,   679,   516,   110,   110,   110,   369,   624,  -191,
    -191,   -95,   -95,   523,   372,   516,   632,   633,   327,   669,
     553,   377,   554,   128,   516,   670,  -194,  -194,   343,   694,
     438,  -325,   130,  -326,   697,   142,   180,   494,   496,   439,
     439,   383,   327,   327,   327,   327,   327,   651,   397,   399,
     399,   384,   464,   385,   431,   400,    29,    72,   665,    30,
     666,   345,    28,    76,    77,    78,    29,    79,    79,    30,
    -208,  -208,   345,   345,   345,   345,   345,   345,   345,   626,
     584,   345,    52,    52,    52,    52,    52,    52,   464,   345,
     345,   345,   464,   534,   535,   418,   536,   537,   538,   110,
     419,   693,   420,   399,   440,   442,   431,   128,   110,    53,
      54,    55,    56,    57,   323,   189,   130,   472,   473,   416,
     417,   421,   359,    73,   706,    75,   131,   132,   133,   422,
     189,    73,    74,    75,   139,   140,   714,   492,   329,   191,
     423,   464,   215,    70,   427,   714,    28,    76,    77,    78,
      29,    79,   111,    30,   223,   111,   111,   111,    29,    79,
     232,    30,   111,   111,   343,   130,   474,   663,   475,    28,
      76,    77,    78,    29,    79,   476,    30,   477,   478,   483,
     191,   527,    28,    76,    77,    78,    29,    79,   272,    30,
     503,   530,   532,   542,   543,   544,   345,   464,   545,   505,
     111,   128,   345,   558,   562,   310,   689,   563,   298,   -49,
     130,   299,   319,   564,   345,   424,   565,    73,    74,    75,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     566,   572,   343,    29,    79,   576,    30,   577,   343,   343,
      28,    76,    77,    78,    29,    79,   583,    30,   663,   252,
     584,   585,   251,   590,   591,   189,   592,   593,   594,   607,
     595,   596,   339,   600,   191,   340,   597,   389,   605,   611,
     110,    73,    74,    75,   610,   464,   464,   612,   614,   523,
     616,   223,   223,   619,   621,   620,   370,   623,   568,    70,
     464,   625,   635,   636,    28,    76,    77,    78,    29,    79,
     637,    30,   638,   112,   183,   224,   244,   112,   112,   672,
     673,   223,   674,   112,   112,   181,   222,   110,   110,   110,
     675,   111,    29,   111,   676,    30,   677,   110,    28,    76,
      77,    78,    29,    79,   683,    30,   684,   111,   345,   690,
     682,   345,   691,   692,  -183,   345,   111,   388,   707,   709,
     626,   112,   111,   111,   111,   111,   389,   110,   710,   712,
     717,    27,   111,   613,   615,   111,   640,   111,   622,   362,
     464,   183,   503,   111,   111,   111,   292,   715,   464,   504,
     345,   505,   254,   411,   603,    70,    28,    76,    77,    78,
      29,    79,    71,    30,   338,    42,    72,   528,   601,   506,
     519,    73,    74,    75,     0,   181,   345,     0,     0,     0,
       0,     0,   345,   345,     0,    29,    79,     0,    30,     0,
       0,   465,   345,     0,    28,    76,    77,    78,    29,    79,
     223,    30,   224,   346,     0,     0,     0,     0,     0,   388,
       0,   223,   223,   223,   223,   223,   223,   223,   389,   539,
     223,     0,     0,     0,     0,     0,     0,   465,   223,   223,
     223,   465,   346,   -32,     0,  -110,     0,     0,   111,   -32,
       0,   -32,   244,     0,   112,  -110,  -110,   111,    28,    76,
      77,    78,    29,    79,     0,    30,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,   -32,   112,     0,     0,
       0,     0,     0,   112,   112,   112,   112,     0,     0,     0,
     465,     0,   128,   112,     0,     0,   112,     0,   112,   129,
       0,   130,     0,     0,   112,   112,   112,     0,    73,    74,
      75,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,   310,   311,     0,     0,     0,     0,     0,     0,
       0,    28,    76,    77,    78,    29,    79,   312,    30,     0,
       0,     0,     0,     0,     0,   223,   465,     0,     0,     0,
       0,   223,   466,   265,   266,   267,   268,   269,   270,     0,
       0,   346,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,   346,   346,   346,   346,   346,   346,   346,   263,
       0,   346,     0,     0,     0,     0,     0,   189,   466,   346,
     346,   346,   466,   264,   190,     0,   191,     0,     0,   112,
       0,     0,     0,    73,    74,    75,     0,     0,   112,   265,
     266,   267,   268,   269,   270,     0,     0,     0,     0,   111,
       0,     0,     0,     0,   465,   465,    28,    76,    77,    78,
      29,    79,     0,    30,     0,     0,     0,     0,     0,   465,
       0,   466,   189,     0,     0,     0,     0,     0,     0,   339,
       0,   191,   113,     0,   225,   113,   113,   113,    73,    74,
      75,     0,   113,   113,     0,   223,   111,   111,   111,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,    28,    76,    77,    78,    29,    79,   223,    30,     0,
     223,    70,     0,     0,   223,     0,   346,   466,   255,     0,
     113,     0,   346,   256,    70,     0,   111,    73,    74,    75,
       0,   255,     0,     0,   346,     0,     0,     0,     0,   465,
      73,    74,    75,     0,     0,     0,     0,   465,     0,   223,
      28,    76,    77,    78,    29,    79,     0,    30,     0,     0,
       0,     0,     0,    28,    76,    77,    78,    29,    79,     0,
      30,     0,    70,   352,     0,   223,     0,     0,     0,   230,
       0,   223,   223,     0,     0,     0,     0,   353,   231,   232,
     112,   223,     0,     0,     0,   466,   466,     0,     0,     0,
       0,   225,   225,   265,   266,   267,   268,   269,   270,     0,
     466,    28,    76,    77,    78,    29,    79,     0,    30,     0,
       0,     0,     0,   114,     0,   226,   114,   114,   114,     0,
       0,   225,     0,   114,   114,   183,   224,   112,   112,   112,
       0,   113,     0,   113,     0,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   346,     0,
       0,     0,     0,     0,     0,   346,   113,     0,     0,     0,
       0,   114,   113,   113,   113,   113,     0,   112,     0,     0,
       0,     0,   113,     0,     0,   113,     0,   113,     0,     0,
     466,     0,     0,   113,   113,   113,   128,     0,   466,     0,
     346,     0,     0,   323,     0,   130,     0,     0,     0,     0,
       0,     0,    73,    74,    75,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   183,   346,     0,     0,     0,
       0,     0,   346,   346,     0,    28,    76,    77,    78,    29,
      79,   467,    30,     0,     0,     0,     0,     0,     0,     0,
     225,     0,   226,   226,     0,     0,     0,     0,     0,     0,
       0,   225,   225,   225,   225,   225,   225,   225,     0,     0,
     225,     0,     0,     0,     0,     0,     0,   467,   225,   225,
     225,   467,   226,     0,     0,     0,     0,     0,   113,     0,
       0,     0,   114,     0,   114,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,   114,   114,   114,   114,     0,     0,     0,
     467,     0,   128,   114,     0,     0,   114,     0,   114,   298,
       0,   130,     0,     0,   114,   114,   114,     0,    73,    74,
      75,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    76,    77,    78,    29,    79,     0,    30,     0,
       0,     0,     0,     0,     0,   225,   467,     0,     0,     0,
       0,   225,   468,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   226,   226,   226,   226,   226,   226,     0,
       0,   226,     0,     0,     0,     0,     0,    70,   468,   226,
     226,   226,     0,     0,   246,     0,     0,     0,     0,   114,
       0,     0,     0,     0,   232,     0,     0,     0,   114,     0,
     115,     0,   227,   115,   115,   115,     0,     0,     0,   113,
     115,   115,     0,     0,   467,   467,    28,    76,    77,    78,
      29,    79,     0,    30,     0,     0,     0,     0,    70,   467,
       0,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,     0,     0,   115,     0,
       0,     0,     0,     0,     0,   225,   113,   113,   113,     0,
       0,     0,     0,     0,     0,     0,   113,    28,    76,    77,
      78,    29,    79,     0,    30,     0,     0,   225,     0,     0,
       0,     0,     0,     0,   225,     0,   226,     0,     0,     0,
       0,     0,   226,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,   226,     0,     0,     0,     0,   467,
       0,     0,     0,     0,     0,     0,     0,   467,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   225,   228,   116,   116,   116,
       0,   225,   225,     0,   116,   116,     0,     0,     0,   227,
     114,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,   116,     0,   115,     0,     0,     0,     0,     0,
     115,   115,   115,   115,     0,     0,   226,   114,   114,   114,
     115,     0,     0,   115,     0,   115,     0,   114,     0,     0,
       0,   115,   115,   115,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     226,     0,     0,   228,   347,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     227,   227,   227,   227,   227,   227,   226,     0,   227,     0,
       0,     0,   226,   226,     0,   469,   227,   227,   227,     0,
       0,     0,     0,   116,     0,   116,   115,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,     0,     0,   116,   116,   116,   116,     0,     0,
       0,     0,     0,     0,   116,     0,     0,   116,     0,   116,
       0,     0,     0,     0,     0,   116,   116,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
     219,     0,   108,     0,     0,     0,     0,     0,   108,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,   227,
       0,     0,   228,     0,     0,     0,   108,     0,     0,     0,
       0,   227,     0,   228,   228,   228,   228,   228,   228,   228,
       0,     0,   228,     0,     0,     0,     0,     0,     0,     0,
     347,   347,   347,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   287,   128,     0,     0,     0,     0,   272,     0,   129,
       0,   130,     0,     0,     0,   288,     0,   115,    73,    74,
      75,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   265,   266,   267,   268,   269,   270,   219,   219,     0,
       0,    28,    76,    77,    78,    29,    79,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
     220,     0,   109,   227,   115,   115,   115,   219,   109,   109,
       0,     0,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,   228,     0,     0,
       0,     0,   227,   347,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,   115,   228,   109,     0,   108,   108,
     108,   108,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,   128,     0,     0,     0,   227,     0,     0,
     298,     0,   650,     0,     0,     0,     0,     0,     0,    73,
      74,    75,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,   227,     0,     0,     0,     0,     0,   227,
     227,   116,    28,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   220,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   219,   219,
     219,   219,     0,     0,     0,     0,   219,   228,   116,   116,
     116,     0,     0,     0,   219,   219,   219,   220,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,     0,     0,   108,     0,     0,   228,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,   109,     0,     0,     0,     0,     0,   109,   109,
     109,   109,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,     0,
       0,     0,     0,   347,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,   220,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,   220,   220,   220,
     220,   220,     0,     0,     0,     0,   220,     0,     0,     0,
       0,     0,     0,     0,   220,   220,   220,   287,   128,     0,
       0,     0,     0,   272,     0,   298,     0,   130,     0,     0,
       0,   288,     0,   109,    73,    74,    75,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   265,   266,   267,
     268,   269,   270,     0,     0,     0,     0,    28,    76,    77,
      78,    29,    79,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,     0,     0,
     219,   220,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,     0,     0,     0,     0,     0,   219,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,   220,   220
  };

  const short
  Parser::yycheck_[] =
  {
      19,    20,    21,    22,    23,    24,    62,    63,    63,    64,
     130,    65,   176,    64,   129,    66,    62,    64,   109,    66,
     232,   372,    66,   109,   480,   129,   319,   365,    71,    72,
     504,   129,    63,   220,    21,   109,   329,   619,   329,    58,
     274,   176,   276,   593,   274,   230,   276,    21,   282,   283,
     284,    22,   282,   283,   284,    16,    27,   163,   274,   389,
     276,   246,   274,    16,   276,    26,   282,   283,   284,    22,
     282,   283,   284,   129,   130,   220,   658,   350,   351,   352,
     353,   354,    90,   129,    62,    62,    63,   307,   308,   309,
     310,   311,   312,   313,   307,   308,   309,   310,   311,   312,
     313,   350,   351,   352,   353,   354,   504,   505,   214,   329,
     350,   351,   352,   353,   354,    21,   329,   650,   700,   658,
     176,    18,    16,   163,   317,   318,   319,   320,   321,   293,
      24,    28,    29,   683,   190,   191,   329,    19,    20,    14,
      21,   149,    21,   307,   308,   309,   310,   311,   312,   313,
      14,   129,   129,   317,   318,   319,   320,   321,   293,   190,
     616,   700,   695,    21,   220,   329,   504,   505,   355,   356,
     261,   262,   263,   264,   214,   261,   262,   263,   264,   230,
     271,   232,    57,   230,    23,   271,    23,   261,   262,   263,
     264,   199,    16,    57,   298,   246,    60,   271,    22,   246,
     298,    21,    26,   259,    16,   350,   351,   352,   353,   354,
      22,    16,   255,     0,   544,   545,    60,    22,    57,   323,
      57,    60,   278,    60,    15,   323,    53,    16,   684,   248,
      57,   629,   583,    60,   690,   691,    15,   293,   576,   713,
     259,    14,   298,    15,    15,    23,   584,   585,    21,   305,
      23,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      51,   317,   318,   319,   320,   321,   322,   323,   598,   562,
     316,   562,    51,   329,    16,   331,   332,   333,    16,    51,
      51,    63,   305,   339,    57,    58,   305,    60,   626,    16,
     628,   629,   348,    16,   350,   351,   352,   353,   354,   355,
     356,    24,   358,   359,   419,    19,    20,    16,   339,   365,
      16,   367,   368,   369,   548,    16,   372,    57,   548,   375,
     298,    22,   378,    24,   380,   348,   377,    17,   359,   348,
     377,   669,   548,   389,   438,    49,   548,    10,    11,    16,
     438,    14,   562,   386,    14,   323,   365,    24,    49,   562,
     623,    21,   375,   330,   692,   378,   375,   380,    16,   378,
      16,   380,   418,   597,    22,    16,   704,   597,   424,   562,
     389,    22,    10,    11,   623,   713,    14,    19,    20,   259,
      16,   597,   438,   623,    57,   597,    16,    57,    24,   366,
      60,    16,    22,    16,   614,    16,    26,    22,   562,    24,
      16,   614,    19,    20,    21,    22,    23,    24,   190,   191,
     367,   368,   369,    20,    21,    22,    23,    24,   474,    57,
     475,    19,    20,    16,   480,   305,    16,     3,     4,     5,
       6,     7,     8,    22,   259,    17,   492,    16,   553,   554,
     418,    58,   419,   474,    16,    24,   424,    27,   504,   505,
     614,    58,    24,    61,    62,    63,    64,    65,    66,    14,
     438,   492,    13,    71,    72,    50,    21,    23,   348,   307,
     308,   309,   310,   311,   312,   313,    52,    16,   623,    16,
     305,    19,    20,    22,    16,   504,   505,    24,   544,   545,
     546,   329,    24,    19,    20,   375,    19,    20,   378,    16,
     380,   109,    57,    16,   560,    60,   562,    24,    27,   389,
      21,    24,    21,   568,   605,    21,    16,    13,   574,   605,
     576,   129,    22,   348,    24,   544,   545,   583,   584,   585,
     650,   605,    50,   648,    12,    16,    16,   593,   594,   594,
      16,   595,   598,    24,    24,   596,    22,   593,    24,   596,
     375,   607,   596,   378,   610,   380,    16,   576,   614,    28,
     616,    16,    22,   594,   389,   584,   585,   623,    16,    24,
     626,   176,   628,   629,    22,   357,   553,   554,    18,   598,
      23,    16,   190,   191,   635,   367,   368,   369,   635,    24,
      16,   635,    19,    20,   650,    27,    22,    16,    24,    14,
      21,   656,   658,    22,    21,    16,    21,   626,    23,   628,
     629,    22,   220,   669,    16,   593,   593,   594,    21,    16,
      22,   677,   230,    49,   232,    22,   682,   683,   684,   607,
      13,   248,   610,    23,   690,   691,   692,   683,   246,   695,
      16,   248,    57,    58,    50,    60,    22,   255,   704,    21,
     669,    15,    22,   261,   262,   263,   264,   713,    28,    19,
      20,    16,    21,   271,   544,   545,   274,    22,   276,    19,
      20,   648,   650,   692,   282,   283,   284,    21,   576,    19,
      20,    19,    20,    14,    23,   704,   584,   585,   293,    16,
      21,    27,    23,    14,   713,    22,    19,    20,   480,   677,
      21,    15,    23,    15,   682,   683,   683,   355,   356,   314,
     315,    57,   317,   318,   319,   320,   321,   695,   598,   544,
     545,    22,   330,    22,   562,    17,    57,    25,   626,    60,
     628,   339,    53,    54,    55,    56,    57,    58,    58,    60,
      28,    29,   350,   351,   352,   353,   354,   355,   356,    28,
      29,   359,    43,    44,    45,    46,    47,    48,   366,   367,
     368,   369,   370,     4,     5,    21,     7,     8,     9,   377,
      21,   669,    22,   598,   314,   315,   614,    14,   386,    44,
      45,    46,    47,    48,    21,    14,    23,   332,   333,   283,
     284,    22,    21,    30,   692,    32,    33,    34,    35,    22,
      14,    30,    31,    32,    41,    42,   704,    21,    15,    23,
      22,   419,   594,    14,    17,   713,    53,    54,    55,    56,
      57,    58,    61,    60,    63,    64,    65,    66,    57,    58,
      31,    60,    71,    72,   616,    23,    21,   619,    21,    53,
      54,    55,    56,    57,    58,    22,    60,    22,    22,    17,
      23,    17,    53,    54,    55,    56,    57,    58,    19,    60,
      14,    17,    17,    22,    16,    15,   474,   475,    21,    23,
     109,    14,   480,    22,    15,    12,   658,    22,    21,    12,
      23,    24,    29,    22,   492,    16,    22,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      22,    22,   684,    57,    58,    15,    60,    22,   690,   691,
      53,    54,    55,    56,    57,    58,    23,    60,   700,    57,
      29,    21,    14,    22,    22,    14,    22,    21,    21,    16,
      21,    21,    21,    17,    23,    24,    21,    23,    15,    17,
     548,    30,    31,    32,    16,   553,   554,    22,    15,    14,
      16,   190,   191,    16,    22,    17,    21,    15,    23,    14,
     568,    22,    15,    17,    53,    54,    55,    56,    57,    58,
      17,    60,    17,    61,    62,    63,    64,    65,    66,    22,
      22,   220,    22,    71,    72,   593,   594,   595,   596,   597,
      22,   230,    57,   232,    22,    60,    16,   605,    53,    54,
      55,    56,    57,    58,    16,    60,    16,   246,   616,    16,
      49,   619,    49,    15,    49,   623,   255,    14,    22,    22,
      28,   109,   261,   262,   263,   264,    23,   635,    22,    22,
      22,     9,   271,   560,   562,   274,   594,   276,   574,   220,
     648,   129,    14,   282,   283,   284,   129,   704,   656,    21,
     658,    23,    71,   277,   545,    14,    53,    54,    55,    56,
      57,    58,    21,    60,   190,    25,    25,   377,   543,    41,
     366,    30,    31,    32,    -1,   683,   684,    -1,    -1,    -1,
      -1,    -1,   690,   691,    -1,    57,    58,    -1,    60,    -1,
      -1,   330,   700,    -1,    53,    54,    55,    56,    57,    58,
     339,    60,   190,   191,    -1,    -1,    -1,    -1,    -1,    14,
      -1,   350,   351,   352,   353,   354,   355,   356,    23,    24,
     359,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,   368,
     369,   370,   220,    16,    -1,    18,    -1,    -1,   377,    22,
      -1,    24,   230,    -1,   232,    28,    29,   386,    53,    54,
      55,    56,    57,    58,    -1,    60,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,   255,    -1,    -1,
      -1,    -1,    -1,   261,   262,   263,   264,    -1,    -1,    -1,
     419,    -1,    14,   271,    -1,    -1,   274,    -1,   276,    21,
      -1,    23,    -1,    -1,   282,   283,   284,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    27,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   474,   475,    -1,    -1,    -1,
      -1,   480,   330,    43,    44,    45,    46,    47,    48,    -1,
      -1,   339,    -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,   351,   352,   353,   354,   355,   356,    13,
      -1,   359,    -1,    -1,    -1,    -1,    -1,    14,   366,   367,
     368,   369,   370,    27,    21,    -1,    23,    -1,    -1,   377,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,   386,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,   548,
      -1,    -1,    -1,    -1,   553,   554,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,   568,
      -1,   419,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    23,    61,    -1,    63,    64,    65,    66,    30,    31,
      32,    -1,    71,    72,    -1,   594,   595,   596,   597,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,   616,    60,    -1,
     619,    14,    -1,    -1,   623,    -1,   474,   475,    21,    -1,
     109,    -1,   480,    26,    14,    -1,   635,    30,    31,    32,
      -1,    21,    -1,    -1,   492,    -1,    -1,    -1,    -1,   648,
      30,    31,    32,    -1,    -1,    -1,    -1,   656,    -1,   658,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    14,    13,    -1,   684,    -1,    -1,    -1,    21,
      -1,   690,   691,    -1,    -1,    -1,    -1,    27,    30,    31,
     548,   700,    -1,    -1,    -1,   553,   554,    -1,    -1,    -1,
      -1,   190,   191,    43,    44,    45,    46,    47,    48,    -1,
     568,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    -1,
      -1,   220,    -1,    71,    72,   593,   594,   595,   596,   597,
      -1,   230,    -1,   232,    -1,    -1,    -1,   605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   616,    -1,
      -1,    -1,    -1,    -1,    -1,   623,   255,    -1,    -1,    -1,
      -1,   109,   261,   262,   263,   264,    -1,   635,    -1,    -1,
      -1,    -1,   271,    -1,    -1,   274,    -1,   276,    -1,    -1,
     648,    -1,    -1,   282,   283,   284,    14,    -1,   656,    -1,
     658,    -1,    -1,    21,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   683,   684,    -1,    -1,    -1,
      -1,    -1,   690,   691,    -1,    53,    54,    55,    56,    57,
      58,   330,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,   351,   352,   353,   354,   355,   356,    -1,    -1,
     359,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,   368,
     369,   370,   220,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,   230,    -1,   232,    -1,    -1,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,   261,   262,   263,   264,    -1,    -1,    -1,
     419,    -1,    14,   271,    -1,    -1,   274,    -1,   276,    21,
      -1,    23,    -1,    -1,   282,   283,   284,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   474,   475,    -1,    -1,    -1,
      -1,   480,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   339,    -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,   359,    -1,    -1,    -1,    -1,    -1,    14,   366,   367,
     368,   369,    -1,    -1,    21,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,   386,    -1,
      61,    -1,    63,    64,    65,    66,    -1,    -1,    -1,   548,
      71,    72,    -1,    -1,   553,   554,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    -1,    -1,    14,   568,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   594,   595,   596,   597,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   605,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,   616,    -1,    -1,
      -1,    -1,    -1,    -1,   623,    -1,   474,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   648,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,   658,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,   684,    63,    64,    65,    66,
      -1,   690,   691,    -1,    71,    72,    -1,    -1,    -1,   220,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,   255,    -1,    -1,    -1,    -1,    -1,
     261,   262,   263,   264,    -1,    -1,   594,   595,   596,   597,
     271,    -1,    -1,   274,    -1,   276,    -1,   605,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,   616,    -1,
      -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
     658,    -1,    -1,   190,   191,    -1,    -1,    -1,   339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
     351,   352,   353,   354,   355,   356,   684,    -1,   359,    -1,
      -1,    -1,   690,   691,    -1,   366,   367,   368,   369,    -1,
      -1,    -1,    -1,   230,    -1,   232,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,   262,   263,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,   274,    -1,   276,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,   339,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,   492,    -1,   350,   351,   352,   353,   354,   355,   356,
      -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     367,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,
      -1,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,
      -1,    23,    -1,    -1,    -1,    27,    -1,   548,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   190,   191,    -1,
      -1,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    -1,    65,   594,   595,   596,   597,   220,    71,    72,
      -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   616,    -1,   474,    -1,    -1,
      -1,    -1,   623,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    -1,   635,   492,   109,    -1,   261,   262,
     263,   264,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,   658,    -1,    -1,
      21,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,   684,    -1,    -1,    -1,    -1,    -1,   690,
     691,   548,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   339,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,   351,   352,
     353,   354,    -1,    -1,    -1,    -1,   359,   594,   595,   596,
     597,    -1,    -1,    -1,   367,   368,   369,   220,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   616,
      -1,    -1,    -1,   386,    -1,    -1,   623,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   262,
     263,   264,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,
      -1,   658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,
      -1,    -1,    -1,   690,   691,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,   351,   352,
     353,   354,    -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   367,   368,   369,    13,    14,    -1,
      -1,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,
      -1,    27,    -1,   386,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   594,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,
     623,   474,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   684,    -1,    -1,    -1,    -1,    -1,   690,   691,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   594,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,
     623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   684,    -1,    -1,    -1,    -1,    -1,   690,   691
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    52,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   237,    21,
      21,    21,    21,    21,    21,    21,     0,    64,    53,    57,
      60,   229,   239,   244,   249,   250,   229,   229,   229,   229,
     229,   243,   250,    16,    16,    16,    16,    16,    16,    16,
      22,   230,   249,   230,   230,   230,   230,   230,    23,   238,
      17,    16,    16,    16,    16,    16,    16,   228,   229,    22,
      14,    21,    25,    30,    31,    32,    54,    55,    56,    58,
      73,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   196,   197,   198,   199,   209,   212,
     221,   222,   223,   224,   225,   226,   227,   239,   240,   241,
     242,   244,   245,   246,   247,   248,   251,   252,    14,    21,
      23,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      84,    85,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   104,   105,   109,   111,   113,   114,   115,
     116,   117,   118,   204,   205,   206,   207,   208,   209,   212,
     217,   221,   222,   223,   224,   225,   226,   227,   247,    14,
      21,    23,   119,   120,   121,   122,   123,   124,   125,   126,
     128,   129,   130,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   152,   153,   155,   166,   167,   209,
     212,   217,   221,   222,   223,   224,   225,   226,   227,   247,
      21,    30,    31,   155,   168,   169,   170,   179,   184,   201,
     202,   203,   217,   221,   223,   171,    21,   201,    16,    24,
      17,    14,    57,   172,   198,    21,    26,   172,   200,    16,
      22,    27,    13,    13,    27,    43,    44,    45,    46,    47,
      48,   210,    19,    20,   218,   219,   220,    50,    23,   178,
     180,   181,    21,    21,    21,    10,    11,    13,    27,    75,
     107,   109,   118,   207,   210,   211,   217,   219,    21,    24,
      75,   105,   106,   221,   223,    16,    22,    27,    13,    12,
      12,    13,    27,   210,   218,   220,    50,    18,    28,    29,
      28,    18,    23,    21,    83,    84,    89,    91,   247,    15,
      51,    21,    21,    21,    10,    11,   120,   155,   167,    21,
      24,   120,   151,   153,   154,   221,   223,   227,    16,    22,
      27,    13,    13,    27,   210,   218,   220,    50,    23,    21,
     127,   128,   135,   137,   247,    15,    51,    21,    21,    21,
      21,   202,    23,   184,   196,    16,    22,    27,    16,    22,
      16,    22,   229,    57,    22,    22,    16,    26,    14,    23,
      72,   231,   232,   233,   235,   236,   239,   242,   247,   248,
      17,   180,   180,   180,   180,   180,   190,   193,   194,   196,
     196,   199,   183,   247,   195,   196,   195,   195,    21,    21,
      22,    22,    22,    22,    16,    24,    72,    17,    82,    84,
      88,    94,    82,    82,    82,    82,    82,    82,    21,    91,
     104,   247,   104,   105,    84,   111,   111,   111,   114,   111,
     111,    86,    87,   247,    75,    81,    82,    84,   110,   111,
     112,   114,   216,   217,   221,   222,   223,   224,   225,   226,
     106,   108,   108,   108,    21,    21,    22,    22,    22,   153,
      16,    24,    72,    17,   126,   128,   134,   141,   126,   126,
     126,   126,    21,   137,   152,   247,   152,   153,   131,   132,
     133,   247,   120,    14,    21,    23,    41,   156,   157,   159,
     160,   162,   164,   213,   214,   215,   239,   240,   247,   216,
     154,   154,   154,    14,    22,   131,    72,    17,   203,    72,
      17,    72,    17,   172,     4,     5,     7,     8,     9,    24,
     231,   234,    22,    16,    15,    21,    16,    24,    16,    22,
      22,    22,    75,    21,    23,    99,   109,    75,    22,    75,
      16,    24,    15,    22,    22,    22,    22,   120,    23,   145,
     155,   151,    22,   120,    16,    24,    15,    22,   156,   159,
     163,   156,   165,    23,    29,    21,    22,    22,    22,    24,
      22,    22,    22,    21,    21,    21,    21,    21,    16,    24,
      17,   236,   231,   234,   247,    15,   196,    16,   100,   109,
      16,    17,    22,    87,    15,   110,    16,   146,   155,    16,
      17,    22,   132,    15,   160,    22,    28,    22,    28,    16,
      24,   131,   160,   160,   161,    15,    17,    17,    17,    74,
     119,   171,   201,   196,   231,    22,   180,    75,    16,    24,
      23,    75,   101,   102,    82,   151,    16,    24,    23,   138,
     147,   148,   149,   153,   126,   160,   160,   156,    24,    16,
      22,   201,    22,    22,    22,    22,    22,    16,   109,    75,
     102,   103,    49,    16,    16,   155,   138,   148,   150,   153,
      16,    49,    15,   160,    75,    16,    24,    75,    74,   151,
      16,    24,   151,   151,    21,   158,   160,    22,   102,    22,
      22,   148,    22,    21,   160,   162,   159,    22
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    86,
      86,    87,    88,    88,    89,    90,    91,    91,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    94,    95,    96,
      96,    96,    97,    98,    99,    99,   100,   100,   101,   101,
     102,   103,   103,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   108,   109,   109,   110,   110,   110,
     111,   112,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   128,   128,   128,   128,
     129,   130,   131,   131,   132,   132,   133,   134,   134,   135,
     136,   137,   137,   137,   138,   138,   139,   140,   140,   140,
     140,   141,   142,   142,   143,   144,   145,   145,   146,   146,
     147,   147,   148,   149,   149,   150,   150,   151,   151,   151,
     152,   152,   152,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   156,   156,   157,   158,   158,   159,   159,
     160,   160,   160,   160,   160,   161,   161,   162,   163,   163,
     164,   165,   165,   166,   167,   167,   168,   168,   169,   169,
     170,   171,   171,   172,   172,   172,   173,   173,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   180,   180,
     181,   181,   181,   182,   183,   183,   184,   184,   184,   185,
     186,   186,   187,   188,   189,   190,   190,   191,   191,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   203,   204,   204,   204,   205,   205,   206,
     206,   206,   207,   207,   208,   208,   208,   208,   208,   209,
     209,   210,   210,   210,   210,   210,   210,   211,   211,   212,
     213,   214,   215,   216,   216,   217,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   227,   228,   228,
     229,   229,   230,   231,   231,   231,   232,   232,   232,   232,
     232,   232,   233,   234,   234,   235,   235,   235,   235,   235,
     236,   236,   237,   237,   238,   239,   239,   240,   241,   242,
     242,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252
  };

  const unsigned char
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
       2,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"tpi\"", "\"thf\"",
  "\"tff\"", "\"tcf\"", "\"fof\"", "\"cnf\"", "\"fot\"", "\"ite\"",
  "\"let\"", "\"@\"", "\"&\"", "\"$\"", "\":\"", "\",\"", "\".\"", "\"+\"",
  "\"=\"", "\"!=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"|\"", "\"*\"", "\">\"", "\"!\"", "\"~\"", "\"?\"", "\"@-\"", "\"@+\"",
  "\"^\"", "\"!!\"", "\"??\"", "\"@@+\"", "\"@@-\"", "\"@=\"", "\"!>\"",
  "\"?*\"", "\"<=>\"", "\"=>\"", "\"<=\"", "\"<~>\"", "\"~|\"", "\"~&\"",
  "\":=\"", "\"-->\"", "\"<<\"", "\"include\"", "\"integer\"", "\"real\"",
  "\"rational\"", "\"double_quoted\"", "\"lower_word\"", "\"upper_word\"",
  "\"identifier\"", "\"single_quoted\"", "$accept", "Specification",
  "Definitions", "Definition", "AnnotatedFormula", "ThfAnnotated",
  "TffAnnotated", "TcfAnnotated", "FofAnnotated", "CnfAnnotated",
  "TpiAnnotated", "Annotations", "TpiFormula", "ThfFormula",
  "ThfLogicFormula", "ThfBinaryFormula", "ThfBinaryNonassoc",
  "ThfBinaryAssoc", "ThfOrFormula", "ThfAndFormula", "ThfApplyFormula",
  "ThfUnitFormula", "ThfPreunitFormula", "ThfUnitaryFormula",
  "ThfQuantifiedFormula", "ThfVariableList", "ThfTypedVariable",
  "ThfUnaryFormula", "ThfPrefixUnary", "ThfInfixUnary", "ThfAtomicFormula",
  "ThfPlainAtomic", "ThfDefinedAtomic", "ThfDefinedInfix",
  "ThfSystemAtomic", "ThfFofFunction", "ThfConditional", "ThfLet",
  "ThfLetTypes", "ThfAtomTypingList", "ThfLetDefns", "ThfLetDefn",
  "ThfLetDefnList", "ThfUnitaryTerm", "ThfTuple", "ThfFormulaList",
  "ThfConnTerm", "ThfArguments", "ThfAtomTyping", "ThfTopLevelType",
  "ThfUnitaryType", "ThfApplyType", "ThfBinaryType", "ThfMappingType",
  "ThfXprodType", "ThfUnionType", "ThfSubtype", "ThfSequent", "TffFormula",
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

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   356,   356,   363,   369,   379,   383,   390,   394,   398,
     402,   406,   410,   426,   429,   434,   437,   442,   445,   450,
     457,   469,   472,   477,   480,   523,   528,   558,   565,   569,
     573,   577,   584,   588,   592,   596,   603,   607,   611,   618,
     625,   629,   633,   640,   645,   653,   658,   666,   671,   679,
     683,   687,   694,   698,   705,   709,   713,   717,   727,   735,
     741,   751,   761,   765,   772,   779,   786,   790,   794,   798,
     805,   809,   816,   820,   824,   828,   835,   842,   849,   856,
     860,   864,   871,   878,   885,   889,   896,   902,   912,   916,
     923,   930,   937,   947,   951,   955,   965,   969,   976,   982,
     992,   997,  1002,  1007,  1015,  1022,  1026,  1036,  1040,  1044,
    1051,  1058,  1065,  1069,  1073,  1081,  1085,  1093,  1097,  1105,
    1109,  1116,  1123,  1127,  1138,  1142,  1146,  1150,  1157,  1161,
    1165,  1169,  1176,  1180,  1187,  1194,  1198,  1205,  1210,  1218,
    1223,  1231,  1235,  1239,  1246,  1250,  1257,  1261,  1265,  1269,
    1279,  1286,  1294,  1301,  1311,  1315,  1322,  1333,  1337,  1344,
    1351,  1358,  1362,  1366,  1373,  1377,  1384,  1391,  1395,  1399,
    1403,  1410,  1417,  1421,  1428,  1435,  1442,  1446,  1453,  1459,
    1469,  1473,  1480,  1487,  1491,  1498,  1504,  1514,  1518,  1522,
    1529,  1533,  1537,  1541,  1545,  1555,  1559,  1566,  1572,  1582,
    1586,  1596,  1600,  1604,  1608,  1618,  1625,  1629,  1639,  1643,
    1653,  1657,  1661,  1666,  1670,  1677,  1682,  1692,  1699,  1703,
    1710,  1717,  1723,  1733,  1740,  1744,  1755,  1758,  1764,  1767,
    1773,  1781,  1785,  1792,  1796,  1800,  1807,  1811,  1818,  1825,
    1829,  1836,  1841,  1849,  1854,  1862,  1866,  1873,  1880,  1884,
    1891,  1895,  1899,  1909,  1917,  1924,  1934,  1938,  1942,  1949,
    1956,  1960,  1967,  1974,  1981,  1988,  1992,  1999,  2003,  2010,
    2017,  2021,  2028,  2032,  2039,  2045,  2055,  2059,  2066,  2070,
    2074,  2081,  2085,  2094,  2098,  2105,  2111,  2121,  2125,  2135,
    2139,  2147,  2151,  2156,  2163,  2167,  2171,  2178,  2182,  2189,
    2193,  2197,  2204,  2208,  2215,  2219,  2223,  2227,  2231,  2238,
    2242,  2251,  2255,  2259,  2263,  2267,  2271,  2278,  2282,  2289,
    2296,  2303,  2310,  2317,  2321,  2328,  2332,  2339,  2346,  2353,
    2361,  2368,  2375,  2382,  2389,  2396,  2403,  2407,  2414,  2422,
    2434,  2438,  2445,  2452,  2456,  2460,  2467,  2471,  2475,  2479,
    2483,  2487,  2496,  2504,  2510,  2529,  2532,  2535,  2538,  2541,
    2547,  2552,  2561,  2566,  2573,  2601,  2605,  2612,  2619,  2626,
    2630,  2634,  2641,  2648,  2655,  2661,  2668,  2677,  2684,  2691,
    2698,  2705
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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


#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:1217
} // libtptp
#line 6722 "GrammarParser.cpp" // lalr1.cc:1217
#line 2711 "../../obj/src/GrammarParser.yy" // lalr1.cc:1218


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

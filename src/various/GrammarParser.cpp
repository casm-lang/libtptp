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
#line 96 "../../obj/src/GrammarParser.yy" // lalr1.cc:437

    // #include <libtptp/ ... >

    //#include "../../src/SourceLocation.h"
    #include "../../src/Lexer.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = TokenBuilder::UNRESOLVED();
    // static Lexer helper functions shall be located here 

#line 60 "GrammarParser.cpp" // lalr1.cc:437


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
#line 155 "GrammarParser.cpp" // lalr1.cc:512

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

      case 248: // DistinctObjectLiteral
        value.YY_MOVE_OR_COPY< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // FormulaData
        value.YY_MOVE_OR_COPY< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // AnnotatedFormula
      case 66: // ThfAnnotated
      case 67: // TffAnnotated
      case 68: // TcfAnnotated
      case 69: // FofAnnotated
      case 70: // CnfAnnotated
      case 71: // TpiAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
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
      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 243: // FileName
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
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

      case 73: // TpiFormula
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
      case 168: // TcfFormula
      case 169: // TcfLogicFormula
      case 171: // FofFormula
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
      case 170: // TcfQuantifiedFormula
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

      case 230: // FormulaRole
        value.YY_MOVE_OR_COPY< Role::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
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

      case 248: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // FormulaData
        value.move< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // AnnotatedFormula
      case 66: // ThfAnnotated
      case 67: // TffAnnotated
      case 68: // TcfAnnotated
      case 69: // FofAnnotated
      case 70: // CnfAnnotated
      case 71: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
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
      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 243: // FileName
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
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

      case 73: // TpiFormula
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
      case 168: // TcfFormula
      case 169: // TcfLogicFormula
      case 171: // FofFormula
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
      case 170: // TcfQuantifiedFormula
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

      case 230: // FormulaRole
        value.move< Role::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
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

      case 248: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (that.value);
        break;

      case 235: // FormulaData
        value.move< FormulaData::Ptr > (that.value);
        break;

      case 65: // AnnotatedFormula
      case 66: // ThfAnnotated
      case 67: // TffAnnotated
      case 68: // TcfAnnotated
      case 69: // FofAnnotated
      case 70: // CnfAnnotated
      case 71: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
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
      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 243: // FileName
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
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

      case 73: // TpiFormula
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
      case 168: // TcfFormula
      case 169: // TcfLogicFormula
      case 171: // FofFormula
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
      case 170: // TcfQuantifiedFormula
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

      case 230: // FormulaRole
        value.move< Role::Ptr > (that.value);
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        value.move< SequentLogic::Ptr > (that.value);
        break;

      case 62: // Specification
        value.move< Specification::Ptr > (that.value);
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

      case 248: // DistinctObjectLiteral
        yylhs.value.emplace< DistinctObjectLiteral::Ptr > ();
        break;

      case 235: // FormulaData
        yylhs.value.emplace< FormulaData::Ptr > ();
        break;

      case 65: // AnnotatedFormula
      case 66: // ThfAnnotated
      case 67: // TffAnnotated
      case 68: // TcfAnnotated
      case 69: // FofAnnotated
      case 70: // CnfAnnotated
      case 71: // TpiAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
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
      case 239: // AtomicWord
      case 240: // AtomicDefinedWord
      case 241: // AtomicSystemWord
      case 243: // FileName
      case 249: // LowerWordLiteral
      case 250: // SingleQuotedLiteral
      case 251: // DollarWordLiteral
      case 252: // DollarDollarWordLiteral
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

      case 73: // TpiFormula
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
      case 168: // TcfFormula
      case 169: // TcfLogicFormula
      case 171: // FofFormula
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
      case 170: // TcfQuantifiedFormula
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

      case 230: // FormulaRole
        yylhs.value.emplace< Role::Ptr > ();
        break;

      case 118: // ThfSequent
      case 167: // TfxSequent
      case 198: // FofSequent
        yylhs.value.emplace< SequentLogic::Ptr > ();
        break;

      case 62: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
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
#line 352 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      m_specification.setDefinitions( yystack_[0].value.as< Definitions::Ptr > () );
  }
#line 2174 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 3:
#line 359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = yystack_[1].value.as< Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as< Definition::Ptr > ());
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 2184 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 4:
#line 365 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as< Definition::Ptr > () );
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 2194 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 5:
#line 375 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2202 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 6:
#line 379 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< IncludeDefinition::Ptr > ();
  }
#line 2210 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 7:
#line 386 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2218 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 8:
#line 390 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2226 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 9:
#line 394 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2234 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 10:
#line 398 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2242 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 11:
#line 402 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2250 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 12:
#line 406 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaDefinition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 2258 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 13:
#line 413 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2267 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 14:
#line 418 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2279 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 15:
#line 429 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2288 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 16:
#line 434 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2300 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 17:
#line 445 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2309 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 18:
#line 450 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2321 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 19:
#line 461 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2330 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 20:
#line 466 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2342 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 21:
#line 477 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2351 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 22:
#line 482 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2363 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 23:
#line 493 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[2].location, yystack_[2].value.as< Logic::Ptr > ());
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Role::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2372 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 24:
#line 498 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[4].location, yystack_[4].value.as< Logic::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Role::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2384 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 25:
#line 509 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as< GeneralTerm::Ptr > ());
    //source
  }
#line 2393 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 26:
#line 514 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source, optionalInfo
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as< GeneralTerm::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralList::Ptr > ());
  }
#line 2402 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 27:
#line 522 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2410 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 28:
#line 529 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2418 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 29:
#line 533 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 2426 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 30:
#line 537 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SubType::Ptr > ();
  }
#line 2434 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 31:
#line 541 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 2442 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 32:
#line 548 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2450 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 33:
#line 552 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2458 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 34:
#line 556 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2466 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 35:
#line 560 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2474 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 36:
#line 567 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2482 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 37:
#line 571 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2490 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 38:
#line 575 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 2498 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 39:
#line 582 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2506 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 40:
#line 589 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2514 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 41:
#line 593 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2522 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 42:
#line 597 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2530 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 43:
#line 604 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2539 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 44:
#line 609 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2548 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 45:
#line 617 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2557 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 46:
#line 622 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2566 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 47:
#line 630 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2575 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 48:
#line 635 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2584 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 49:
#line 643 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2592 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 50:
#line 647 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2600 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 51:
#line 651 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2608 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 52:
#line 658 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2616 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 53:
#line 662 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 2624 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 54:
#line 669 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 2632 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 55:
#line 673 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2640 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 56:
#line 677 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2648 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 57:
#line 681 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 2659 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 58:
#line 691 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), variables, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2668 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 59:
#line 699 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 2678 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 60:
#line 705 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 2689 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 61:
#line 715 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto var = yystack_[2].value.as< VariableTerm::Ptr > ();
	var->setColon(yystack_[1].value.as< Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as< Type::Ptr > ();
	var->setType(type);
  }
#line 2700 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 62:
#line 725 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 2708 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 63:
#line 729 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2716 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 64:
#line 736 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2724 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 65:
#line 743 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2732 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 66:
#line 750 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2740 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 67:
#line 754 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 2748 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 68:
#line 758 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< ConstantAtom::Ptr > ();
  }
#line 2756 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 69:
#line 762 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< FunctorAtom::Ptr > ();
  }
#line 2764 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 70:
#line 769 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2772 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 71:
#line 773 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 2780 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 72:
#line 780 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2788 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 73:
#line 784 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< ConditionalTerm::Ptr > ();
  }
#line 2796 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 74:
#line 788 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinitionTerm::Ptr > ();
  }
#line 2804 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 75:
#line 792 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< ConnectiveAtom::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Term::Ptr > () = logic;
  }
#line 2815 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 76:
#line 799 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 2823 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 77:
#line 806 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2831 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 78:
#line 813 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConstantAtom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2839 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 79:
#line 820 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2847 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 80:
#line 824 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2855 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 81:
#line 828 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2863 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 82:
#line 835 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Logic::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2871 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 83:
#line 842 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Type::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2879 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 84:
#line 849 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 2887 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 85:
#line 853 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2895 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 86:
#line 860 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 2905 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 87:
#line 866 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 2916 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 88:
#line 876 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinitionAtom::Ptr > ();
  }
#line 2924 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 89:
#line 880 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2932 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 90:
#line 887 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2940 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 91:
#line 894 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//could be of type DefinitionAtoms, but Logics is expected
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2951 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 92:
#line 901 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 2962 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 93:
#line 911 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2970 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 94:
#line 915 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2978 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 95:
#line 919 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 2989 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 96:
#line 929 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2997 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 97:
#line 933 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3005 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 98:
#line 940 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3015 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 99:
#line 946 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3026 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 100:
#line 956 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< BinaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3035 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 101:
#line 961 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< BinaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3044 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 102:
#line 966 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< InfixConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3053 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 103:
#line 971 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto pair = yystack_[0].value.as< UnaryConnective_t > ();
	yylhs.value.as< ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3062 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 104:
#line 979 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logics::Ptr > () = yystack_[0].value.as< Logics::Ptr > ();
  }
#line 3070 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 105:
#line 986 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3078 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 106:
#line 990 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< TypedAtom::Ptr > () = type;
  }
#line 3089 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 107:
#line 1000 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3097 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 108:
#line 1004 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3105 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 109:
#line 1008 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3113 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 110:
#line 1015 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3121 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 111:
#line 1022 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< BinaryLogic::Ptr > ());
  }
#line 3129 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 112:
#line 1029 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3137 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 113:
#line 1033 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3145 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 114:
#line 1037 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3153 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 115:
#line 1045 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3161 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 116:
#line 1049 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< BinaryType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 117:
#line 1057 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3177 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 118:
#line 1061 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3185 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 119:
#line 1069 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< AtomType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 120:
#line 1073 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3201 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 121:
#line 1080 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3209 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 122:
#line 1087 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 3217 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 123:
#line 1091 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< SequentLogic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< SequentLogic::Ptr > () = logic;
  }
#line 3228 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 124:
#line 1102 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3236 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 125:
#line 1106 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 3244 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 126:
#line 1110 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SubType::Ptr > ();
  }
#line 3252 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 127:
#line 1114 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 3260 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 128:
#line 1121 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3268 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 129:
#line 1125 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3276 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 130:
#line 1129 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3284 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 131:
#line 1133 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3292 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 132:
#line 1140 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3300 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 133:
#line 1144 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3308 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 134:
#line 1151 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3316 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 135:
#line 1158 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3324 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 136:
#line 1162 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3332 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 137:
#line 1169 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3341 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 138:
#line 1174 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3350 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 139:
#line 1182 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3359 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 140:
#line 1187 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3368 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 141:
#line 1195 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3376 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 142:
#line 1199 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3384 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 143:
#line 1203 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3392 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 144:
#line 1210 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3400 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 145:
#line 1214 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 3408 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 146:
#line 1221 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 3416 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 147:
#line 1225 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3424 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 148:
#line 1229 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3432 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 149:
#line 1233 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3443 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 150:
#line 1243 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3451 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 151:
#line 1250 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yystack_[3].location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), list, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3460 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 152:
#line 1258 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3471 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 153:
#line 1265 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3482 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 154:
#line 1275 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3490 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 155:
#line 1279 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3498 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 156:
#line 1286 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variable = yystack_[2].value.as< VariableTerm::Ptr > ();
	variable->setColon(yystack_[1].value.as< Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as< AtomType::Ptr > (); //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	yylhs.value.as< VariableTerm::Ptr > () = variable;
  }
#line 3510 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 157:
#line 1297 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 3518 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 158:
#line 1301 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3526 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 159:
#line 1308 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3534 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 160:
#line 1315 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3542 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 161:
#line 1322 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3550 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 162:
#line 1326 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3558 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 163:
#line 1330 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3566 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 164:
#line 1337 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3574 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 165:
#line 1341 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3582 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 166:
#line 1348 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3590 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 167:
#line 1355 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3598 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 168:
#line 1359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3606 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 169:
#line 1363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< ConditionalTerm::Ptr > ();
  }
#line 3614 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 170:
#line 1367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinitionTerm::Ptr > ();
  }
#line 3622 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 171:
#line 1374 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3630 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 172:
#line 1381 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3638 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 173:
#line 1385 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3646 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 174:
#line 1392 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Logic::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3654 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 175:
#line 1399 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Type::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3662 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 176:
#line 1406 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 3670 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 177:
#line 1410 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3678 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 178:
#line 1417 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3688 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 179:
#line 1423 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3699 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 180:
#line 1433 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinitionAtom::Ptr > ();
  }
#line 3707 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 181:
#line 1437 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3715 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 182:
#line 1444 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3723 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 183:
#line 1451 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3731 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 184:
#line 1455 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3739 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 185:
#line 1462 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3749 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 186:
#line 1468 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3760 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 187:
#line 1478 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3768 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 188:
#line 1482 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3776 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 189:
#line 1486 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3784 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 190:
#line 1493 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3792 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 191:
#line 1497 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3800 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 192:
#line 1501 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3808 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 193:
#line 1505 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3816 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 194:
#line 1509 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3827 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 195:
#line 1519 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3835 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 196:
#line 1523 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3843 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 197:
#line 1530 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3853 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 198:
#line 1536 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3864 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 199:
#line 1546 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3872 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 200:
#line 1550 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< TypedAtom::Ptr > () = type;
  }
#line 3883 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 201:
#line 1560 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3891 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 202:
#line 1564 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3899 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 203:
#line 1568 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< QuantifiedType::Ptr > ();
  }
#line 3907 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 204:
#line 1572 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< Type::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3918 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 205:
#line 1582 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3926 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 206:
#line 1589 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3934 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 207:
#line 1593 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3945 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 208:
#line 1603 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3953 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 209:
#line 1607 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3964 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 210:
#line 1617 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3972 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 211:
#line 1621 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3980 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 212:
#line 1625 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto functor = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::TYPE);
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, functor);
  }
#line 3989 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 213:
#line 1630 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 3997 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 214:
#line 1634 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< TupleType::Ptr > ());
  }
#line 4005 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 215:
#line 1641 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4015 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 216:
#line 1647 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4026 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 217:
#line 1657 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 4034 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 218:
#line 1664 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4042 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 219:
#line 1668 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4050 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 220:
#line 1675 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4058 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 221:
#line 1682 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 4068 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 222:
#line 1688 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 4079 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 223:
#line 1698 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 4087 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 224:
#line 1705 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 4095 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 225:
#line 1709 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< SequentLogic::Ptr > () = sequent;
  }
#line 4106 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 226:
#line 1720 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4114 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 227:
#line 1724 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 4122 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 228:
#line 1731 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 4130 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 229:
#line 1735 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4138 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 230:
#line 1742 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[5].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, op, list, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4148 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 231:
#line 1753 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4156 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 232:
#line 1757 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 4164 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 233:
#line 1764 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4172 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 234:
#line 1768 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4180 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 235:
#line 1772 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4188 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 236:
#line 1779 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4196 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 237:
#line 1783 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4204 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 238:
#line 1790 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4212 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 239:
#line 1797 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4220 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 240:
#line 1801 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 4228 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 241:
#line 1808 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4237 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 242:
#line 1813 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4246 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 243:
#line 1821 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4255 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 244:
#line 1826 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4264 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 245:
#line 1834 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4272 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 246:
#line 1838 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4280 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 247:
#line 1845 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 4288 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 248:
#line 1852 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4296 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 249:
#line 1856 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4304 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 250:
#line 1863 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 4312 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 251:
#line 1867 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4320 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 252:
#line 1871 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 4331 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 253:
#line 1881 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), variables, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4340 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 254:
#line 1889 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< Nodes >(yylhs.location);
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 4351 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 255:
#line 1896 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto variables = yystack_[2].value.as< Nodes::Ptr > ();
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 4362 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 256:
#line 1906 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4370 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 257:
#line 1910 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4378 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 258:
#line 1914 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4386 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 259:
#line 1921 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4394 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 260:
#line 1928 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 4402 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 261:
#line 1932 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4410 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 262:
#line 1939 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4418 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 263:
#line 1946 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 4426 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 264:
#line 1953 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4434 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 265:
#line 1960 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4442 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 266:
#line 1964 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4450 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 267:
#line 1971 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 4458 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 268:
#line 1975 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4466 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 269:
#line 1982 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4474 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 270:
#line 1989 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4482 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 271:
#line 1993 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4490 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 272:
#line 2000 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4498 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 273:
#line 2004 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4506 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 274:
#line 2011 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto terms = libtptp::make< Logics >(yylhs.location);
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4516 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 275:
#line 2017 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto terms = yystack_[2].value.as< Logics::Ptr > ();
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4527 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 276:
#line 2027 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4535 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 277:
#line 2031 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 4543 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 278:
#line 2038 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4551 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 279:
#line 2042 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4559 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 280:
#line 2046 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4567 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 281:
#line 2053 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 4575 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 282:
#line 2057 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
  }
#line 4585 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 283:
#line 2066 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4593 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 284:
#line 2070 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4601 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 285:
#line 2077 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4611 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 286:
#line 2083 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4622 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 287:
#line 2093 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4630 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 288:
#line 2097 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 4641 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 289:
#line 2107 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4649 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 290:
#line 2111 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4658 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 291:
#line 2119 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4666 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 292:
#line 2123 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4675 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 293:
#line 2128 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4683 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 294:
#line 2135 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4691 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 295:
#line 2139 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4699 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 296:
#line 2143 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = yystack_[0].value.as< QuantifiedQuantifier_t > ();
  }
#line 4707 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 297:
#line 2150 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
#line 4715 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 298:
#line 2154 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
#line 4723 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 299:
#line 2161 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::CARET);
  }
#line 4731 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 300:
#line 2165 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::ATPLUS);
  }
#line 4739 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 301:
#line 2169 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::ATMINUS);
  }
#line 4747 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 302:
#line 2176 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = yystack_[0].value.as< UnaryConnective_t > ();
  }
#line 4755 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 303:
#line 2180 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = yystack_[0].value.as< UnaryConnective_t > ();
  }
#line 4763 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 304:
#line 2187 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
#line 4771 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 305:
#line 2191 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
#line 4779 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 306:
#line 2195 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
#line 4787 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 307:
#line 2199 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
#line 4795 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 308:
#line 2203 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::EQUALITY);
  }
#line 4803 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 309:
#line 2210 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4811 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 310:
#line 2214 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4819 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 311:
#line 2223 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 4827 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 312:
#line 2227 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 4835 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 313:
#line 2231 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 4843 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 314:
#line 2235 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 4851 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 315:
#line 2239 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 4859 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 316:
#line 2243 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 4867 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 317:
#line 2250 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 4875 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 318:
#line 2254 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 4883 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 319:
#line 2261 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 4891 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 320:
#line 2268 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4899 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 321:
#line 2275 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4907 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 322:
#line 2282 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4915 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 323:
#line 2289 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4923 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 324:
#line 2293 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4931 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 325:
#line 2300 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4939 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 326:
#line 2304 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4947 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 327:
#line 2311 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = yystack_[0].value.as< InfixConnective_t > ();
  }
#line 4955 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 328:
#line 2318 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 4963 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 329:
#line 2325 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 4971 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 330:
#line 2332 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4979 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 331:
#line 2339 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4987 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 332:
#line 2346 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4995 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 333:
#line 2353 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5003 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 334:
#line 2360 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5011 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 335:
#line 2367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5019 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 336:
#line 2374 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 5027 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 337:
#line 2378 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< DistinctObjectLiteral::Ptr > ());
  }
#line 5035 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 338:
#line 2385 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< Identifier::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 5047 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 339:
#line 2393 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	const auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< Identifier::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 5058 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 340:
#line 2403 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5066 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 341:
#line 2407 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< std::string > (), Identifier::Kind::NUMBER);
  }
#line 5074 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 342:
#line 2414 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< Role::Ptr > () = libtptp::make< Role >( yylhs.location, yystack_[0].value.as< Identifier::Ptr > () );
  }
#line 5082 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 343:
#line 2421 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralData::Ptr > ();
  }
#line 5090 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 344:
#line 2425 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as< GeneralData::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralTerm::Ptr > ());
  }
#line 5098 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 345:
#line 2429 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralList::Ptr > ();
  }
#line 5106 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 346:
#line 2436 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//identifier
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 5115 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 347:
#line 2441 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< GeneralFunction::Ptr > ());
  }
#line 5123 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 348:
#line 2445 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 5131 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 349:
#line 2449 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 5139 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 350:
#line 2453 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< DistinctObjectLiteral::Ptr > ());
  }
#line 5147 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 351:
#line 2457 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< FormulaData::Ptr > ());
  }
#line 5155 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 352:
#line 2464 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5163 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 353:
#line 2471 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 5173 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 354:
#line 2477 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	
    auto terms = yystack_[2].value.as< Nodes::Ptr > ();
    terms->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
    yylhs.value.as< Nodes::Ptr > () = terms;
  }
#line 5185 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 355:
#line 2488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 356:
#line 2492 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5201 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 357:
#line 2496 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5209 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 358:
#line 2500 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5217 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 359:
#line 2504 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Term::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5225 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 360:
#line 2511 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5234 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 361:
#line 2516 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5243 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 362:
#line 2525 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5252 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 363:
#line 2530 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Identifier::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< ListLiteral::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 5260 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 364:
#line 2537 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< ListLiteral::Ptr > () = list;
  }
#line 5269 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 365:
#line 2545 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5277 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 366:
#line 2549 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5285 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 367:
#line 2556 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5293 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 368:
#line 2563 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5301 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 369:
#line 2570 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< IntegerLiteral::Ptr > ();
  }
#line 5309 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 370:
#line 2574 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RealLiteral::Ptr > ();
  }
#line 5317 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 371:
#line 2578 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RationalLiteral::Ptr > ();
  }
#line 5325 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 372:
#line 2585 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 5333 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 373:
#line 2592 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as< std::string > ());
  }
#line 5341 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 374:
#line 2599 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5349 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 375:
#line 2605 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5357 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 376:
#line 2612 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto identifier = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< std::string > ());
	yylhs.value.as< VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 5366 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 377:
#line 2620 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DistinctObjectLiteral::Ptr > () = libtptp::make< DistinctObjectLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5374 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 378:
#line 2627 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5382 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 379:
#line 2634 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 5390 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 380:
#line 2641 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 5398 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 381:
#line 2648 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 5406 "GrammarParser.cpp" // lalr1.cc:906
    break;


#line 5410 "GrammarParser.cpp" // lalr1.cc:906
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


  const short Parser::yypact_ninf_ = -600;

  const short Parser::yytable_ninf_ = -327;

  const short
  Parser::yypact_[] =
  {
     471,     3,    34,    95,   123,   143,   157,   162,   194,   471,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,   558,
     558,   558,   558,   558,   558,   139,  -600,  -600,  -600,  -600,
    -600,   190,  -600,  -600,  -600,   193,   209,   214,   216,   228,
     392,  -600,   184,   184,   184,   184,   184,   184,   249,   234,
     271,  -600,   276,   293,   300,   303,   305,   558,   308,  -600,
    1042,  1169,   788,   800,  1042,  1381,    44,  -600,   320,    63,
    1042,  1271,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,
     419,  -600,  -600,  -600,  -600,  -600,   326,   352,   289,  -600,
    1261,   389,  -600,  -600,  -600,  -600,  -600,  -600,  -600,    99,
    -600,  -600,   384,   525,   561,  -600,  -600,   328,   357,  1319,
    -600,   366,  -600,   403,  -600,   448,  -600,  -600,  -600,  -600,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,    76,  2491,
     858,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,
    -600,   444,  -600,  -600,  -600,  -600,   386,   432,   459,   911,
    1118,  -600,   169,  -600,  -600,   612,  -600,  -600,   186,  -600,
    -600,  -600,  -600,   561,   437,  -600,   208,  -600,  -600,   487,
     499,  -600,  -600,   501,  -600,  -600,  1553,  -600,  -600,  -600,
     130,   135,   526,   160,   528,  -600,   539,  -600,   614,   371,
     788,   912,   553,  -600,  -600,  -600,  -600,   543,   554,  1431,
     414,  -600,  -600,   424,  -600,  -600,   660,  -600,  -600,  -600,
     496,  -600,  -600,  -600,   561,   532,  -600,  -600,  -600,   571,
     451,   164,   135,   575,   160,   578,  -600,   580,  -600,   662,
    1429,   583,   740,  -600,   556,  -600,  -600,  -600,  -600,  -600,
     615,  -600,   648,   653,   678,   604,  1004,   608,   558,  -600,
    -600,   589,  -600,   675,   680,  1319,  -600,  -600,   111,  1096,
     688,  1319,  1319,  1319,  1319,  -600,  -600,  -600,  -600,  -600,
    -600,  1319,  -600,  -600,   740,  -600,   740,   717,   655,  -600,
    -600,  -600,   740,   740,   740,   730,   732,  -600,  -600,   747,
     752,   755,   759,  1553,  -600,  -600,   757,  -600,  2586,  -600,
    -600,  -600,   197,  -600,  -600,  1096,   771,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1159,  1159,   766,   750,   750,   750,
     750,   750,   655,  2586,  -600,  -600,  -600,  -600,  -600,  1689,
      40,  1689,  1689,  1689,   780,   794,   795,   801,   806,  1369,
    -600,  -600,  -600,   719,   259,  -600,  -600,   721,  1096,   799,
    1369,  1369,  1369,  1369,  1369,  1679,  1679,   811,   655,  1369,
    -600,  -600,  -600,  -600,  -600,   990,    40,  1369,  1369,  1369,
     372,   124,   655,  -600,   810,  1096,   820,  1004,  1096,   822,
    1096,   833,  -600,  -600,  -600,  -600,  1319,  -600,   897,   664,
     814,   835,   837,  -600,  -600,  -600,   838,  -600,  -600,  -600,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,
    -600,  -600,   278,  -600,   631,  -600,   644,   667,  1689,   480,
     738,  -600,  -600,  -600,  1689,  -600,   847,  -600,  -600,  -600,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  2586,  -600,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,   841,  -600,  -600,
    -600,   342,  -600,   859,   853,   459,   864,   866,  -600,   841,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,  -600,
     871,   885,   886,   895,  1369,   651,   746,  -600,  -600,  -600,
    1369,  -600,   898,  -600,  -600,  -600,  -600,  -600,  -600,  -600,
    -600,  -600,  1369,  -600,  -600,  -600,  -600,  -600,   410,  -600,
    -600,   865,   899,   868,   990,   990,   904,  -600,  -600,   893,
     199,  -600,  -600,  -600,   907,  -600,  -600,  -600,  -600,  -600,
     668,   684,   685,   915,  -600,   415,   908,  -600,  -600,   909,
    -600,   910,  -600,  -600,   916,   918,   919,   924,   927,  -600,
    -600,   428,   917,   926,  1096,  1096,   655,   935,   740,  -600,
    -600,  -600,   944,   584,   584,   946,  -600,  -600,   934,   941,
     655,   949,  1689,  -600,  -600,  -600,  -600,   955,   372,   963,
    -600,  -600,   964,   958,   655,   970,   638,  -600,   969,   363,
     263,  -600,   446,   655,   638,   638,  -600,  -600,  -600,   978,
     979,   980,   982,  1169,   788,  1042,  1381,   740,  1096,  -600,
    -600,  -600,  -600,   694,  -600,  1319,  -600,  1689,   464,  -600,
    2624,  -600,  -600,  -600,  1689,  -600,  1369,   482,  -600,    39,
    -600,  -600,  -600,  1369,  -600,  -600,   638,  -600,   638,   990,
    -600,   511,  -600,  -600,   734,  1381,  -600,  -600,  -600,   973,
     981,   983,   984,   985,  -600,  -600,  -600,   986,   584,  -600,
     858,   951,   994,  -600,  -600,   998,   372,  -600,   912,  -600,
     999,  -600,   952,  -600,  -600,  -600,  -600,  -600,  1005,   638,
    -600,  -600,  -600,  -600,  -600,  -600,  -600,  1689,  -600,   951,
    -600,   517,  1689,  1169,  1369,  -600,   972,  -600,   540,   269,
    1369,  1369,   826,  -600,   997,  1689,  -600,  -600,  1007,  1008,
      72,  -600,  1010,  -600,  1065,  -600,  -600,  -600,  -600,  -600,
    -600,  -600,  -600,  1065,  -600,  1012,  1009,  -600
  };

  const unsigned short
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     5,     7,     8,     9,    10,    11,    12,     6,     0,
       0,     0,     0,     0,     0,     0,     1,     3,   341,   378,
     379,     0,   340,   365,   366,     0,     0,     0,     0,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   342,     0,     0,     0,     0,     0,     0,     0,   362,
       0,     0,     0,     0,     0,     0,     0,   338,     0,     0,
       0,     0,   309,   319,   310,   373,   374,   375,   377,   376,
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
    -600,  -600,  -600,  1018,  -600,  -600,  -600,  -600,  -600,  -600,
    -600,    42,  -600,  -549,     9,  -600,  -600,  -600,  -600,  -600,
    -293,  -198,  -600,    31,  -600,  -600,   479,  -155,  -146,  -600,
     416,  -600,  -600,    89,  -600,  -600,  -600,  -600,  -600,  -600,
    -600,  -578,  -600,   185,   -45,  -118,  -600,   435,   -86,   478,
      55,  -600,  -600,  -301,  -600,  -600,  -600,   914,   458,   -31,
    -600,  -600,  -600,  -600,  -600,  -287,  -600,  -211,  -600,  -600,
    -349,   481,  -600,  -246,   834,  -600,  -183,  -570,  -600,  -600,
    -228,  -600,  -600,  -600,  -600,  -600,  -600,  -599,  -600,  -600,
    -411,   420,   219,   128,   -52,  -452,  -600,  -600,  -471,   -92,
    -600,   349,  -600,  -600,  -600,  -600,   875,  -600,  -600,  -600,
     -44,   -24,  -600,  -600,  -600,  -600,  -600,  -101,   -46,   -95,
     -74,  -600,  -600,   -50,  -600,  -600,  -600,  -600,  -600,  -242,
    -600,  -600,  -226,  -191,   503,  -203,  -600,   996,   791,  -600,
     -38,  -152,   692,  -600,  -600,  -600,  -103,  -600,  2099,   -51,
    -600,  2123,  -600,  -600,  -600,   704,   -40,  -138,   -84,  -112,
     393,   762,   913,  1282,  1433,  1733,  1884,  -600,   225,   682,
    -328,  -600,  -600,   530,  -600,   535,  -600,  -600,   -19,    86,
    -600,  -177,  -600,  -600,  -600,  -600,   -55,  -156,   819,  1046,
    -600,  -600
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
     303,   182,   304,   184,   185,   186,   187,    66,    31,    50,
     391,   392,   393,   541,   394,   395,    18,    58,   117,   118,
     119,   120,    40,   121,   122,   123,   124,   125,    33,    34,
     126,   127
  };

  const short
  Parser::yytable_[] =
  {
      32,    32,    32,    32,    32,    32,   188,   229,   279,   361,
     216,   233,   302,   238,   280,   238,   164,   237,   448,   237,
     245,   180,   221,   525,    19,   314,   293,   247,   461,   374,
     326,   193,   406,   579,   406,   281,   455,   363,    32,   271,
     406,   406,   406,   291,   639,   297,   253,   257,   407,   659,
     407,   315,   578,   581,    69,    20,   407,   407,   407,   687,
     248,   540,   658,   484,   488,   489,   490,   491,   249,   571,
     142,   409,   680,   410,   188,   188,   355,   251,   371,   415,
     415,   415,   397,   408,   164,   408,   285,   286,   686,   296,
     251,   408,   408,   408,   371,   191,    29,    29,   313,    30,
      30,   711,   356,   399,   486,   486,   486,   486,   486,   428,
     432,   433,   434,   435,   436,   437,    21,   708,  -278,  -278,
     252,   328,   487,   487,   487,   487,   487,   386,   397,    29,
     659,   456,    30,   252,   698,   229,   229,   387,   289,   485,
     485,   485,   485,   485,    22,   329,   524,   326,   354,   399,
    -325,   377,   430,   430,   430,   430,   430,   430,   430,   336,
     279,   279,   279,   279,    23,   364,   401,   402,   403,   404,
     279,   397,   493,   493,   430,  -326,   405,   667,    24,   365,
     238,   330,   373,    25,   237,   -33,  -325,   281,   281,   281,
     281,   -33,   399,   -33,    26,   293,   238,   281,   397,    30,
     237,   397,   -35,   397,   398,   655,    42,   325,   -35,    43,
     -35,  -326,   397,   424,   297,   366,   602,   540,   -33,   399,
     293,   425,   399,   413,   399,    44,   317,  -208,  -208,    32,
      45,   253,    46,   399,   631,   -35,   318,   319,   328,   297,
     396,    29,   716,   188,    47,    35,    36,    37,    38,    39,
     398,    59,   188,   188,   188,   188,   188,   188,   188,   441,
     441,   461,   328,   328,   328,   328,   328,   453,   188,   455,
     644,   443,    57,   699,   188,   480,   188,   188,   188,   702,
     703,   215,    67,   481,   229,   627,   396,    60,  -192,  -192,
     463,   628,    61,   398,   546,   229,   229,   229,   229,   229,
     495,   495,   547,   501,   229,  -234,   406,   289,   336,    62,
     518,  -234,   229,   229,   229,  -234,    63,   501,  -184,    64,
     398,    65,   407,   398,   325,   398,   463,   238,   502,   396,
      68,   237,   454,   556,   398,   293,   664,   250,   429,   429,
     429,   429,   429,   429,   429,   606,   516,   426,   444,   444,
     444,   444,   444,   261,   297,   406,   396,   408,   560,   396,
     457,   396,   533,   188,   456,   262,   561,   397,   397,   188,
     396,   407,   445,   446,   447,   449,   450,   486,   277,   296,
     278,   334,   335,   188,   459,   251,   523,   282,   399,   399,
     482,   626,   584,   370,   643,   487,   431,   431,   431,   431,
     431,   431,   431,  -269,  -269,  -235,   408,   430,    48,   215,
     343,  -235,   485,   307,    49,  -235,   654,   526,   431,   229,
     529,   397,   531,   570,   283,   229,   574,   552,   252,    29,
    -128,   574,    30,   557,   575,   259,  -128,   229,  -128,   589,
    -129,   260,   399,   567,   598,   308,  -129,   559,  -129,   518,
     518,   517,   599,   110,   181,   222,   243,   110,   110,   430,
     305,   573,   629,   110,   110,   189,   306,   291,   609,   284,
     630,   309,   359,   382,     1,     2,     3,     4,     5,     6,
     648,    72,    73,    74,   624,   516,   516,   316,   649,   398,
     398,   604,   632,   633,   523,   520,   521,   522,   656,   440,
     442,   553,   110,   554,   279,   453,   657,   188,    29,    79,
     646,    30,  -131,   296,   296,   320,   618,   321,  -131,   501,
    -131,   518,   181,     7,   322,   396,   396,   574,   501,   518,
     518,   281,   302,   695,   665,   668,   666,    29,   188,   229,
      30,   696,   216,   398,  -280,  -280,   238,   331,   164,   332,
     237,   641,   188,   180,   221,   188,   700,   516,   642,   188,
     333,   229,   678,   193,   701,   516,   516,   351,   229,   348,
     350,   518,   375,   518,   518,   349,   497,   693,   376,   396,
     272,   273,   357,   222,   345,   238,   343,   343,   343,   237,
     517,   517,   327,   457,   358,   188,   367,   671,   523,   368,
     706,   369,   142,   229,   685,   553,   372,   516,   296,   516,
     516,    28,   714,   345,   518,    29,   647,   459,    30,   651,
     378,   714,   188,   243,   380,   110,   379,   188,   188,   229,
     381,   -93,   -93,   -94,   -94,   229,   229,   518,   164,   110,
     188,    29,   377,   180,    30,   429,   383,   548,   110,   518,
     516,   431,   503,   549,   110,   110,   110,   110,   518,   679,
     548,   505,   517,   365,   110,   523,   550,   110,  -325,   110,
     517,   517,   370,   516,   568,   110,   110,   110,   388,  -190,
    -190,  -193,  -193,   548,   480,   516,   694,   389,   539,   551,
     586,   697,   142,  -326,   516,    29,    79,   384,    30,   343,
     480,   480,   385,   431,   651,   400,   587,   588,    29,   327,
     598,    30,   517,    79,   517,   517,   645,    75,    76,    77,
      78,    29,    79,   464,    30,    52,    53,    54,    55,    56,
     439,   439,   345,   327,   327,   327,   327,   327,  -192,  -192,
    -191,  -191,    71,   345,   345,   345,   345,   345,   345,   345,
     669,   418,   345,   419,    69,   517,   670,   -95,   -95,   464,
     345,   345,   345,   464,   128,  -194,  -194,   472,   473,   420,
     110,   323,   329,   130,   421,   494,   496,   422,   517,   110,
      72,   423,    74,   131,   132,   133,   416,   417,   427,   130,
     517,   139,   140,    75,    76,    77,    78,    29,    79,   517,
      30,   474,   189,    75,    76,    77,    78,    29,    79,   190,
      30,   191,   464,   215,    69,   475,   483,   476,    72,    73,
      74,   230,   111,   477,   223,   111,   111,   111,   478,   272,
     231,   232,   111,   111,   191,   343,   542,   527,   663,   530,
     503,    75,    76,    77,    78,    29,    79,   704,    30,   505,
     532,   543,   544,    75,    76,    77,    78,    29,    79,   545,
      30,    51,    51,    51,    51,    51,    51,   345,   464,   558,
     319,   111,   128,   345,   562,   563,   310,   689,   -49,   298,
     576,   130,   299,    29,    79,   345,    30,   424,    72,    73,
      74,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   534,   535,   343,   536,   537,   538,   564,   565,   343,
     343,    75,    76,    77,    78,    29,    79,   566,    30,   663,
     572,   577,   584,   310,   311,   252,   189,   583,   585,   251,
     590,   591,   592,   339,   600,   191,   340,   593,   312,   594,
     595,   110,    72,    73,    74,   596,   464,   464,   597,   389,
     605,   611,   223,   223,   265,   266,   267,   268,   269,   270,
     607,   464,   610,   612,   614,    75,    76,    77,    78,    29,
      79,   616,    30,   112,   183,   224,   244,   112,   112,   619,
     621,   620,   223,   112,   112,   623,   181,   222,   110,   110,
     110,   625,   111,   635,   111,   672,   636,   637,   110,   638,
     682,   691,   677,   673,   503,   674,   675,   676,   111,   345,
     683,   504,   345,   505,   684,   690,   345,   111,    69,   707,
     692,  -183,   112,   111,   111,   111,   111,    27,   110,   709,
     710,   506,   712,   111,   717,   232,   111,   626,   111,   613,
     615,   464,   183,   292,   111,   111,   111,    29,    79,   464,
      30,   345,   640,   715,   362,   622,    69,    75,    76,    77,
      78,    29,    79,    70,    30,   338,   254,    71,   411,   528,
     519,    41,    72,    73,    74,   603,   181,   345,   601,   503,
       0,     0,     0,   345,   345,     0,   713,     0,   505,     0,
       0,     0,   465,   345,     0,    75,    76,    77,    78,    29,
      79,   223,    30,   224,   346,     0,     0,     0,     0,     0,
     388,     0,   223,   223,   223,   223,   223,   223,   223,   389,
       0,   223,    29,    79,     0,    30,     0,     0,   465,   223,
     223,   223,   465,   346,   -32,     0,  -110,     0,     0,   111,
     -32,     0,   -32,   244,     0,   112,  -110,  -110,   111,    75,
      76,    77,    78,    29,    79,     0,    30,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   -32,   112,     0,
       0,     0,     0,   128,   112,   112,   112,   112,     0,     0,
     438,   465,   130,   128,   112,     0,     0,   112,     0,   112,
     129,     0,   130,     0,     0,   112,   112,   112,     0,    72,
      73,    74,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,     0,     0,     0,   223,   465,     0,     0,
       0,     0,   223,   466,     0,     0,     0,     0,     0,     0,
       0,     0,   346,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,   346,   346,   346,   346,   346,   346,   346,
       0,     0,   346,     0,   263,     0,     0,     0,     0,   466,
     346,   346,   346,   466,     0,    69,     0,     0,   264,     0,
     112,     0,   255,     0,     0,     0,     0,   256,     0,   112,
       0,    72,    73,    74,   265,   266,   267,   268,   269,   270,
     111,     0,     0,     0,     0,   465,   465,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    29,    79,
     465,    30,   466,    69,     0,     0,     0,     0,     0,     0,
     255,     0,   113,     0,   225,   113,   113,   113,     0,    72,
      73,    74,   113,   113,     0,     0,   223,   111,   111,   111,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
       0,     0,    75,    76,    77,    78,    29,    79,   223,    30,
       0,   223,     0,   189,     0,   223,     0,   346,   466,     0,
     339,   113,   191,   346,     0,    69,     0,   111,     0,    72,
      73,    74,   246,     0,     0,   346,     0,     0,     0,     0,
     465,     0,   232,     0,     0,     0,     0,     0,   465,     0,
     223,     0,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,     0,    75,    76,    77,    78,    29,    79,
       0,    30,     0,    69,   352,     0,   223,     0,     0,     0,
     370,     0,   223,   223,     0,     0,     0,     0,   353,     0,
     232,   112,   223,     0,     0,     0,   466,   466,     0,     0,
       0,     0,   225,   225,   265,   266,   267,   268,   269,   270,
       0,   466,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,   114,     0,   226,   114,   114,   114,     0,
       0,     0,   225,   114,   114,     0,   183,   224,   112,   112,
     112,     0,   113,     0,   113,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   346,
       0,     0,     0,     0,     0,     0,   346,   113,     0,     0,
       0,     0,   114,   113,   113,   113,   113,     0,   112,     0,
       0,     0,     0,   113,     0,     0,   113,     0,   113,     0,
       0,   466,     0,     0,   113,   113,   113,   128,     0,   466,
       0,   346,     0,     0,   323,     0,   130,     0,     0,     0,
       0,     0,     0,    72,    73,    74,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   183,   346,     0,     0,
       0,     0,     0,   346,   346,     0,    75,    76,    77,    78,
      29,    79,   467,    30,     0,     0,     0,     0,     0,     0,
       0,   225,     0,   226,   226,     0,     0,     0,     0,     0,
       0,     0,   225,   225,   225,   225,   225,   225,   225,     0,
       0,   225,     0,     0,     0,     0,     0,     0,   467,   225,
     225,   225,   467,   226,     0,     0,     0,     0,     0,   113,
       0,     0,     0,   114,     0,   114,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,   189,   114,   114,   114,   114,     0,     0,
     492,   467,   191,   128,   114,     0,     0,   114,     0,   114,
     298,     0,   130,     0,     0,   114,   114,   114,     0,    72,
      73,    74,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,    75,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,     0,     0,     0,   225,   467,     0,     0,
       0,     0,   225,   468,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   226,   226,   226,   226,   226,   226,
       0,     0,   226,   115,     0,   227,   115,   115,   115,   468,
     226,   226,   226,   115,   115,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,   467,   467,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
     467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   113,   113,   113,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,   225,     0,   226,     0,     0,
       0,     0,     0,   226,     0,     0,     0,   113,     0,     0,
       0,     0,     0,   227,   227,   226,     0,     0,     0,     0,
     467,     0,     0,     0,     0,     0,     0,     0,   467,     0,
     225,     0,     0,     0,   116,     0,   228,   116,   116,   116,
       0,     0,     0,   227,   116,   116,     0,     0,     0,     0,
       0,     0,     0,   115,     0,   115,   225,     0,     0,     0,
       0,     0,   225,   225,     0,     0,     0,     0,     0,   115,
       0,   114,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   116,   115,   115,   115,   115,     0,     0,
       0,     0,     0,     0,   115,     0,     0,   115,     0,   115,
       0,     0,     0,     0,     0,   115,   115,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   114,   114,
     114,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,     0,   114,     0,
       0,     0,   227,     0,   228,   347,     0,     0,     0,     0,
       0,     0,     0,   227,   227,   227,   227,   227,   227,   227,
       0,   226,   227,     0,     0,     0,     0,     0,     0,   469,
     227,   227,   227,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,   116,     0,   116,   226,     0,   115,
       0,     0,     0,   226,   226,     0,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,   116,   116,   116,   116,     0,
       0,     0,     0,     0,     0,   116,     0,     0,   116,   108,
     116,   219,     0,   108,     0,     0,   116,   116,   116,   108,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,   220,     0,   109,     0,     0,
       0,     0,     0,   109,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   108,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,     0,   227,     0,     0,     0,     0,
       0,     0,   109,     0,   228,   228,   228,   228,   228,   228,
     228,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,   347,   347,   347,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,   219,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   220,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,   227,   115,   115,
     115,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,   108,     0,   227,     0,   228,     0,
     108,   108,   108,   108,   347,     0,     0,     0,   115,     0,
     108,     0,     0,     0,     0,     0,   228,     0,   109,     0,
       0,     0,     0,     0,   109,   109,   109,   109,     0,     0,
       0,   227,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,     0,     0,
       0,     0,     0,   227,   227,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     219,   219,   219,   219,     0,     0,     0,     0,   219,     0,
       0,     0,   220,     0,     0,     0,   219,   219,   219,     0,
       0,     0,     0,   220,   220,   220,   220,   220,   228,   116,
     116,   116,   220,     0,     0,   108,     0,     0,     0,   116,
     220,   220,   220,     0,     0,     0,     0,     0,     0,     0,
     347,     0,     0,     0,   287,   128,     0,   228,     0,   109,
     272,     0,   129,     0,   130,     0,     0,     0,   288,   116,
       0,    72,    73,    74,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   265,   266,   267,   268,   269,   270,
       0,     0,   347,     0,    75,    76,    77,    78,    29,    79,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,     0,     0,   219,   347,   347,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,     0,     0,     0,     0,     0,   220,     0,   287,
     128,     0,     0,   220,     0,   272,     0,   298,     0,   130,
       0,     0,     0,   288,     0,   220,    72,    73,    74,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   265,
     266,   267,   268,   269,   270,     0,     0,     0,   128,    75,
      76,    77,    78,    29,    79,   298,    30,   650,     0,     0,
       0,     0,     0,     0,    72,    73,    74,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    29,    79,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,   220,   109,     0,
       0,     0,   219,     0,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,   220,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   219,     0,     0,     0,     0,     0,   219,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,     0,   220,   220
  };

  const short
  Parser::yycheck_[] =
  {
      19,    20,    21,    22,    23,    24,    61,    62,   109,   220,
      62,    63,   130,    63,   109,    65,    61,    63,   319,    65,
      64,    61,    62,   372,    21,   163,   129,    65,   329,   232,
     176,    62,   274,   504,   276,   109,   329,   220,    57,    90,
     282,   283,   284,   129,   593,   129,    70,    71,   274,   619,
     276,   163,   504,   505,    14,    21,   282,   283,   284,   658,
      16,   389,    23,   350,   351,   352,   353,   354,    24,   480,
      61,   274,   650,   276,   129,   130,   214,    14,   230,   282,
     283,   284,   259,   274,   129,   276,    10,    11,   658,   129,
      14,   282,   283,   284,   246,    23,    57,    57,   149,    60,
      60,   700,   214,   259,   350,   351,   352,   353,   354,   307,
     308,   309,   310,   311,   312,   313,    21,   695,    19,    20,
      57,   176,   350,   351,   352,   353,   354,    16,   305,    57,
     700,   329,    60,    57,   683,   190,   191,    26,   129,   350,
     351,   352,   353,   354,    21,    15,    22,   293,   199,   305,
      15,    27,   307,   308,   309,   310,   311,   312,   313,   190,
     261,   262,   263,   264,    21,   220,   261,   262,   263,   264,
     271,   348,   355,   356,   329,    15,   271,   629,    21,    15,
     230,    51,   232,    21,   230,    16,    51,   261,   262,   263,
     264,    22,   348,    24,     0,   298,   246,   271,   375,    60,
     246,   378,    16,   380,   259,   616,    16,   176,    22,    16,
      24,    51,   389,    16,   298,    51,   544,   545,    49,   375,
     323,    24,   378,   278,   380,    16,    18,    28,    29,   248,
      16,   255,    16,   389,   583,    49,    28,    29,   293,   323,
     259,    57,   713,   298,    16,    20,    21,    22,    23,    24,
     305,    17,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   562,   317,   318,   319,   320,   321,   322,   323,   562,
     598,   316,    23,   684,   329,    16,   331,   332,   333,   690,
     691,    62,    57,    24,   339,    22,   305,    16,    19,    20,
     330,    28,    16,   348,    16,   350,   351,   352,   353,   354,
     355,   356,    24,   358,   359,    16,   548,   298,   339,    16,
     365,    22,   367,   368,   369,    26,    16,   372,    49,    16,
     375,    16,   548,   378,   293,   380,   366,   377,   359,   348,
      22,   377,   323,   419,   389,   438,   623,    17,   307,   308,
     309,   310,   311,   312,   313,   548,   365,   305,   317,   318,
     319,   320,   321,    27,   438,   597,   375,   548,    16,   378,
     329,   380,   386,   418,   562,    13,    24,   544,   545,   424,
     389,   597,   317,   318,   319,   320,   321,   623,    50,   419,
      23,    10,    11,   438,   329,    14,    14,    21,   544,   545,
     348,    28,    29,    21,   597,   623,   307,   308,   309,   310,
     311,   312,   313,    19,    20,    16,   597,   562,    16,   190,
     191,    22,   623,    27,    22,    26,   614,   375,   329,   474,
     378,   598,   380,   475,    21,   480,    16,   418,    57,    57,
      16,    16,    60,   424,    24,    16,    22,   492,    24,    24,
      16,    22,   598,   474,    16,    13,    22,   438,    24,   504,
     505,   365,    24,    60,    61,    62,    63,    64,    65,   614,
      16,   492,    16,    70,    71,    14,    22,   553,   554,    21,
      24,    12,    21,   248,     3,     4,     5,     6,     7,     8,
      16,    30,    31,    32,   576,   504,   505,    50,    24,   544,
     545,   546,   584,   585,    14,   367,   368,   369,    16,   314,
     315,    21,   109,    23,   605,   560,    24,   562,    57,    58,
     605,    60,    16,   553,   554,    28,   568,    18,    22,   574,
      24,   576,   129,    52,    23,   544,   545,    16,   583,   584,
     585,   605,   650,    16,   626,    24,   628,    57,   593,   594,
      60,    24,   594,   598,    19,    20,   596,    21,   593,    21,
     596,   595,   607,   593,   594,   610,    16,   576,   596,   614,
      21,   616,   648,   594,    24,   584,   585,    13,   623,    16,
      27,   626,    16,   628,   629,    22,   357,   669,    22,   598,
      19,    20,    50,   190,   191,   635,   367,   368,   369,   635,
     504,   505,   176,   562,    23,   650,    21,   635,    14,    21,
     692,    21,   593,   658,   656,    21,    23,   626,   648,   628,
     629,    53,   704,   220,   669,    57,   607,   562,    60,   610,
      16,   713,   677,   230,    16,   232,    22,   682,   683,   684,
      22,    19,    20,    19,    20,   690,   691,   692,   683,   246,
     695,    57,    27,   683,    60,   614,    57,    16,   255,   704,
     669,   562,    14,    22,   261,   262,   263,   264,   713,   650,
      16,    23,   576,    15,   271,    14,    22,   274,    15,   276,
     584,   585,    21,   692,    23,   282,   283,   284,    14,    19,
      20,    19,    20,    16,    16,   704,   677,    23,    24,    22,
      22,   682,   683,    15,   713,    57,    58,    22,    60,   480,
      16,    16,    22,   614,   695,    17,    22,    22,    57,   293,
      16,    60,   626,    58,   628,   629,    22,    53,    54,    55,
      56,    57,    58,   330,    60,    43,    44,    45,    46,    47,
     314,   315,   339,   317,   318,   319,   320,   321,    19,    20,
      19,    20,    25,   350,   351,   352,   353,   354,   355,   356,
      16,    21,   359,    21,    14,   669,    22,    19,    20,   366,
     367,   368,   369,   370,    14,    19,    20,   332,   333,    22,
     377,    21,    15,    23,    22,   355,   356,    22,   692,   386,
      30,    22,    32,    33,    34,    35,   283,   284,    17,    23,
     704,    41,    42,    53,    54,    55,    56,    57,    58,   713,
      60,    21,    14,    53,    54,    55,    56,    57,    58,    21,
      60,    23,   419,   594,    14,    21,    17,    22,    30,    31,
      32,    21,    60,    22,    62,    63,    64,    65,    22,    19,
      30,    31,    70,    71,    23,   616,    22,    17,   619,    17,
      14,    53,    54,    55,    56,    57,    58,    21,    60,    23,
      17,    16,    15,    53,    54,    55,    56,    57,    58,    21,
      60,    42,    43,    44,    45,    46,    47,   474,   475,    22,
      29,   109,    14,   480,    15,    22,    12,   658,    12,    21,
      15,    23,    24,    57,    58,   492,    60,    16,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     4,     5,   684,     7,     8,     9,    22,    22,   690,
     691,    53,    54,    55,    56,    57,    58,    22,    60,   700,
      22,    22,    29,    12,    13,    57,    14,    23,    21,    14,
      22,    22,    22,    21,    17,    23,    24,    21,    27,    21,
      21,   548,    30,    31,    32,    21,   553,   554,    21,    23,
      15,    17,   190,   191,    43,    44,    45,    46,    47,    48,
      16,   568,    16,    22,    15,    53,    54,    55,    56,    57,
      58,    16,    60,    60,    61,    62,    63,    64,    65,    16,
      22,    17,   220,    70,    71,    15,   593,   594,   595,   596,
     597,    22,   230,    15,   232,    22,    17,    17,   605,    17,
      49,    49,    16,    22,    14,    22,    22,    22,   246,   616,
      16,    21,   619,    23,    16,    16,   623,   255,    14,    22,
      15,    49,   109,   261,   262,   263,   264,     9,   635,    22,
      22,    41,    22,   271,    22,    31,   274,    28,   276,   560,
     562,   648,   129,   129,   282,   283,   284,    57,    58,   656,
      60,   658,   594,   704,   220,   574,    14,    53,    54,    55,
      56,    57,    58,    21,    60,   190,    70,    25,   277,   377,
     366,    25,    30,    31,    32,   545,   683,   684,   543,    14,
      -1,    -1,    -1,   690,   691,    -1,    21,    -1,    23,    -1,
      -1,    -1,   330,   700,    -1,    53,    54,    55,    56,    57,
      58,   339,    60,   190,   191,    -1,    -1,    -1,    -1,    -1,
      14,    -1,   350,   351,   352,   353,   354,   355,   356,    23,
      -1,   359,    57,    58,    -1,    60,    -1,    -1,   366,   367,
     368,   369,   370,   220,    16,    -1,    18,    -1,    -1,   377,
      22,    -1,    24,   230,    -1,   232,    28,    29,   386,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,   255,    -1,
      -1,    -1,    -1,    14,   261,   262,   263,   264,    -1,    -1,
      21,   419,    23,    14,   271,    -1,    -1,   274,    -1,   276,
      21,    -1,    23,    -1,    -1,   282,   283,   284,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,   474,   475,    -1,    -1,
      -1,    -1,   480,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   339,    -1,   492,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   350,   351,   352,   353,   354,   355,   356,
      -1,    -1,   359,    -1,    13,    -1,    -1,    -1,    -1,   366,
     367,   368,   369,   370,    -1,    14,    -1,    -1,    27,    -1,
     377,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,   386,
      -1,    30,    31,    32,    43,    44,    45,    46,    47,    48,
     548,    -1,    -1,    -1,    -1,   553,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
     568,    60,   419,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    60,    -1,    62,    63,    64,    65,    -1,    30,
      31,    32,    70,    71,    -1,    -1,   594,   595,   596,   597,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,   616,    60,
      -1,   619,    -1,    14,    -1,   623,    -1,   474,   475,    -1,
      21,   109,    23,   480,    -1,    14,    -1,   635,    -1,    30,
      31,    32,    21,    -1,    -1,   492,    -1,    -1,    -1,    -1,
     648,    -1,    31,    -1,    -1,    -1,    -1,    -1,   656,    -1,
     658,    -1,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    14,    13,    -1,   684,    -1,    -1,    -1,
      21,    -1,   690,   691,    -1,    -1,    -1,    -1,    27,    -1,
      31,   548,   700,    -1,    -1,    -1,   553,   554,    -1,    -1,
      -1,    -1,   190,   191,    43,    44,    45,    46,    47,    48,
      -1,   568,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,   220,    70,    71,    -1,   593,   594,   595,   596,
     597,    -1,   230,    -1,   232,    -1,    -1,    -1,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   616,
      -1,    -1,    -1,    -1,    -1,    -1,   623,   255,    -1,    -1,
      -1,    -1,   109,   261,   262,   263,   264,    -1,   635,    -1,
      -1,    -1,    -1,   271,    -1,    -1,   274,    -1,   276,    -1,
      -1,   648,    -1,    -1,   282,   283,   284,    14,    -1,   656,
      -1,   658,    -1,    -1,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   683,   684,    -1,    -1,
      -1,    -1,    -1,   690,   691,    -1,    53,    54,    55,    56,
      57,    58,   330,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   339,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,
     368,   369,   370,   220,    -1,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,   230,    -1,   232,    -1,    -1,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    14,   261,   262,   263,   264,    -1,    -1,
      21,   419,    23,    14,   271,    -1,    -1,   274,    -1,   276,
      21,    -1,    23,    -1,    -1,   282,   283,   284,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,   474,   475,    -1,    -1,
      -1,    -1,   480,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   339,    -1,   492,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   350,   351,   352,   353,   354,   355,   356,
      -1,    -1,   359,    60,    -1,    62,    63,    64,    65,   366,
     367,   368,   369,    70,    71,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,   553,   554,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   594,   595,   596,   597,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   616,    -1,
      -1,    -1,    -1,    -1,    -1,   623,    -1,   474,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    -1,   635,    -1,    -1,
      -1,    -1,    -1,   190,   191,   492,    -1,    -1,    -1,    -1,
     648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,
     658,    -1,    -1,    -1,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,   220,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,   232,   684,    -1,    -1,    -1,
      -1,    -1,   690,   691,    -1,    -1,    -1,    -1,    -1,   246,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   109,   261,   262,   263,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,   274,    -1,   276,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,   595,   596,
     597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   616,
      -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,
      -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,   635,    -1,
      -1,    -1,   339,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   350,   351,   352,   353,   354,   355,   356,
      -1,   658,   359,    -1,    -1,    -1,    -1,    -1,    -1,   366,
     367,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,   230,    -1,   232,   684,    -1,   386,
      -1,    -1,    -1,   690,   691,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,   261,   262,   263,   264,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,   274,    60,
     276,    62,    -1,    64,    -1,    -1,   282,   283,   284,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   109,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   339,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,   350,   351,   352,   353,   354,   355,
     356,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   367,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,   595,   596,
     597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,   616,
      -1,    -1,    -1,    -1,   255,    -1,   623,    -1,   474,    -1,
     261,   262,   263,   264,   480,    -1,    -1,    -1,   635,    -1,
     271,    -1,    -1,    -1,    -1,    -1,   492,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,   262,   263,   264,    -1,    -1,
      -1,   658,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,
      -1,    -1,    -1,   690,   691,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,   339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
     351,   352,   353,   354,    -1,    -1,    -1,    -1,   359,    -1,
      -1,    -1,   339,    -1,    -1,    -1,   367,   368,   369,    -1,
      -1,    -1,    -1,   350,   351,   352,   353,   354,   594,   595,
     596,   597,   359,    -1,    -1,   386,    -1,    -1,    -1,   605,
     367,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     616,    -1,    -1,    -1,    13,    14,    -1,   623,    -1,   386,
      19,    -1,    21,    -1,    23,    -1,    -1,    -1,    27,   635,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,   658,    -1,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,
      -1,    -1,    -1,   474,   690,   691,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   492,    -1,    -1,    -1,    -1,    -1,   474,    -1,    13,
      14,    -1,    -1,   480,    -1,    19,    -1,    21,    -1,    23,
      -1,    -1,    -1,    27,    -1,   492,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    14,    53,
      54,    55,    56,    57,    58,    21,    60,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   594,   595,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   616,    -1,   594,   595,    -1,
      -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   616,
      -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   658,    -1,   684,    -1,    -1,    -1,    -1,    -1,   690,
     691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,
      -1,    -1,    -1,   690,   691
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    52,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   237,    21,
      21,    21,    21,    21,    21,    21,     0,    64,    53,    57,
      60,   229,   239,   249,   250,   229,   229,   229,   229,   229,
     243,   250,    16,    16,    16,    16,    16,    16,    16,    22,
     230,   249,   230,   230,   230,   230,   230,    23,   238,    17,
      16,    16,    16,    16,    16,    16,   228,   229,    22,    14,
      21,    25,    30,    31,    32,    53,    54,    55,    56,    58,
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
       0,   351,   351,   358,   364,   374,   378,   385,   389,   393,
     397,   401,   405,   412,   417,   428,   433,   444,   449,   460,
     465,   476,   481,   492,   497,   508,   513,   521,   528,   532,
     536,   540,   547,   551,   555,   559,   566,   570,   574,   581,
     588,   592,   596,   603,   608,   616,   621,   629,   634,   642,
     646,   650,   657,   661,   668,   672,   676,   680,   690,   698,
     704,   714,   724,   728,   735,   742,   749,   753,   757,   761,
     768,   772,   779,   783,   787,   791,   798,   805,   812,   819,
     823,   827,   834,   841,   848,   852,   859,   865,   875,   879,
     886,   893,   900,   910,   914,   918,   928,   932,   939,   945,
     955,   960,   965,   970,   978,   985,   989,   999,  1003,  1007,
    1014,  1021,  1028,  1032,  1036,  1044,  1048,  1056,  1060,  1068,
    1072,  1079,  1086,  1090,  1101,  1105,  1109,  1113,  1120,  1124,
    1128,  1132,  1139,  1143,  1150,  1157,  1161,  1168,  1173,  1181,
    1186,  1194,  1198,  1202,  1209,  1213,  1220,  1224,  1228,  1232,
    1242,  1249,  1257,  1264,  1274,  1278,  1285,  1296,  1300,  1307,
    1314,  1321,  1325,  1329,  1336,  1340,  1347,  1354,  1358,  1362,
    1366,  1373,  1380,  1384,  1391,  1398,  1405,  1409,  1416,  1422,
    1432,  1436,  1443,  1450,  1454,  1461,  1467,  1477,  1481,  1485,
    1492,  1496,  1500,  1504,  1508,  1518,  1522,  1529,  1535,  1545,
    1549,  1559,  1563,  1567,  1571,  1581,  1588,  1592,  1602,  1606,
    1616,  1620,  1624,  1629,  1633,  1640,  1646,  1656,  1663,  1667,
    1674,  1681,  1687,  1697,  1704,  1708,  1719,  1723,  1730,  1734,
    1741,  1752,  1756,  1763,  1767,  1771,  1778,  1782,  1789,  1796,
    1800,  1807,  1812,  1820,  1825,  1833,  1837,  1844,  1851,  1855,
    1862,  1866,  1870,  1880,  1888,  1895,  1905,  1909,  1913,  1920,
    1927,  1931,  1938,  1945,  1952,  1959,  1963,  1970,  1974,  1981,
    1988,  1992,  1999,  2003,  2010,  2016,  2026,  2030,  2037,  2041,
    2045,  2052,  2056,  2065,  2069,  2076,  2082,  2092,  2096,  2106,
    2110,  2118,  2122,  2127,  2134,  2138,  2142,  2149,  2153,  2160,
    2164,  2168,  2175,  2179,  2186,  2190,  2194,  2198,  2202,  2209,
    2213,  2222,  2226,  2230,  2234,  2238,  2242,  2249,  2253,  2260,
    2267,  2274,  2281,  2288,  2292,  2299,  2303,  2310,  2317,  2324,
    2331,  2338,  2345,  2352,  2359,  2366,  2373,  2377,  2384,  2392,
    2402,  2406,  2413,  2420,  2424,  2428,  2435,  2440,  2444,  2448,
    2452,  2456,  2463,  2470,  2476,  2487,  2491,  2495,  2499,  2503,
    2510,  2515,  2524,  2529,  2536,  2544,  2548,  2555,  2562,  2569,
    2573,  2577,  2584,  2591,  2598,  2604,  2611,  2619,  2626,  2633,
    2640,  2647
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
#line 6763 "GrammarParser.cpp" // lalr1.cc:1217
#line 2653 "../../obj/src/GrammarParser.yy" // lalr1.cc:1218


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

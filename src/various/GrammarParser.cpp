// A Bison parser, made by GNU Bison 3.4.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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
#line 90 "../../obj/src/GrammarParser.yy"

    #include "../../src/Lexer.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = TokenBuilder::UNRESOLVED();
    // static Lexer helper functions shall be located here 

#line 57 "GrammarParser.cpp"


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

#line 47 "../../obj/src/GrammarParser.yy"
namespace libtptp {
#line 149 "GrammarParser.cpp"


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

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
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

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
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
      case 73: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.YY_MOVE_OR_COPY< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.YY_MOVE_OR_COPY< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 78: // ThfBinaryNonassoc
      case 79: // ThfBinaryAssoc
      case 80: // ThfOrFormula
      case 81: // ThfAndFormula
      case 82: // ThfApplyFormula
      case 122: // TffBinaryFormula
      case 123: // TffBinaryNonassoc
      case 124: // TffBinaryAssoc
      case 125: // TffOrFormula
      case 126: // TffAndFormula
      case 174: // FofBinaryFormula
      case 175: // FofBinaryNonassoc
      case 176: // FofBinaryAssoc
      case 177: // FofOrFormula
      case 178: // FofAndFormula
        value.YY_MOVE_OR_COPY< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.YY_MOVE_OR_COPY< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.YY_MOVE_OR_COPY< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // ThfConnTerm
        value.YY_MOVE_OR_COPY< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 96: // ThfSystemAtomic
        value.YY_MOVE_OR_COPY< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // DefinedTerm
        value.YY_MOVE_OR_COPY< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.YY_MOVE_OR_COPY< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.YY_MOVE_OR_COPY< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 249: // DistinctObjectLiteral
        value.YY_MOVE_OR_COPY< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // FormulaData
        value.YY_MOVE_OR_COPY< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // ThfFofFunction
        value.YY_MOVE_OR_COPY< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 214: // TypeConstant
      case 215: // TypeFunctor
      case 216: // DefinedType
      case 217: // Atom
      case 218: // UntypedAtom
      case 222: // Constant
      case 223: // Functor
      case 224: // SystemConstant
      case 225: // SystemFunctor
      case 226: // DefinedConstant
      case 227: // DefinedFunctor
      case 230: // Name
      case 240: // AtomicWord
      case 241: // AtomicDefinedWord
      case 242: // AtomicSystemWord
      case 244: // FileName
      case 250: // LowerWordLiteral
      case 251: // SingleQuotedLiteral
      case 252: // DollarWordLiteral
      case 253: // DollarDollarWordLiteral
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.YY_MOVE_OR_COPY< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.YY_MOVE_OR_COPY< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 245: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.YY_MOVE_OR_COPY< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.YY_MOVE_OR_COPY< ListTypeElements::Ptr > (YY_MOVE (that.value));
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
      case 102: // ThfLetDefns
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 148: // TfxLetDefns
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
        value.YY_MOVE_OR_COPY< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.YY_MOVE_OR_COPY< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.YY_MOVE_OR_COPY< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.YY_MOVE_OR_COPY< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 158: // Tf1QuantifiedType
        value.YY_MOVE_OR_COPY< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 247: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 246: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
        value.YY_MOVE_OR_COPY< Role::Ptr > (YY_MOVE (that.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 63: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.YY_MOVE_OR_COPY< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
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
      case 15: // "$$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "="
      case 21: // "!="
      case 22: // "("
      case 23: // ")"
      case 24: // "["
      case 25: // "]"
      case 26: // "{"
      case 27: // "}"
      case 28: // "|"
      case 29: // "*"
      case 30: // ">"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "@-"
      case 35: // "@+"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@+"
      case 40: // "@@-"
      case 41: // "@="
      case 42: // "!>"
      case 43: // "?*"
      case 44: // "<=>"
      case 45: // "=>"
      case 46: // "<="
      case 47: // "<~>"
      case 48: // "~|"
      case 49: // "~&"
      case 50: // ":="
      case 51: // "-->"
      case 52: // "<<"
      case 53: // "include"
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 165: // TfxTupleType
        value.YY_MOVE_OR_COPY< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.YY_MOVE_OR_COPY< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.YY_MOVE_OR_COPY< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 243: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.YY_MOVE_OR_COPY< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
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
    switch (that.type_get ())
    {
      case 73: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.move< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 78: // ThfBinaryNonassoc
      case 79: // ThfBinaryAssoc
      case 80: // ThfOrFormula
      case 81: // ThfAndFormula
      case 82: // ThfApplyFormula
      case 122: // TffBinaryFormula
      case 123: // TffBinaryNonassoc
      case 124: // TffBinaryAssoc
      case 125: // TffOrFormula
      case 126: // TffAndFormula
      case 174: // FofBinaryFormula
      case 175: // FofBinaryNonassoc
      case 176: // FofBinaryAssoc
      case 177: // FofOrFormula
      case 178: // FofAndFormula
        value.move< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.move< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 96: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 249: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // FormulaData
        value.move< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 214: // TypeConstant
      case 215: // TypeFunctor
      case 216: // DefinedType
      case 217: // Atom
      case 218: // UntypedAtom
      case 222: // Constant
      case 223: // Functor
      case 224: // SystemConstant
      case 225: // SystemFunctor
      case 226: // DefinedConstant
      case 227: // DefinedFunctor
      case 230: // Name
      case 240: // AtomicWord
      case 241: // AtomicDefinedWord
      case 242: // AtomicSystemWord
      case 244: // FileName
      case 250: // LowerWordLiteral
      case 251: // SingleQuotedLiteral
      case 252: // DollarWordLiteral
      case 253: // DollarDollarWordLiteral
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 245: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (YY_MOVE (that.value));
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
      case 102: // ThfLetDefns
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 148: // TfxLetDefns
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
        value.move< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 158: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 247: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 246: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
        value.move< Role::Ptr > (YY_MOVE (that.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 63: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
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
      case 15: // "$$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "="
      case 21: // "!="
      case 22: // "("
      case 23: // ")"
      case 24: // "["
      case 25: // "]"
      case 26: // "{"
      case 27: // "}"
      case 28: // "|"
      case 29: // "*"
      case 30: // ">"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "@-"
      case 35: // "@+"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@+"
      case 40: // "@@-"
      case 41: // "@="
      case 42: // "!>"
      case 43: // "?*"
      case 44: // "<=>"
      case 45: // "=>"
      case 46: // "<="
      case 47: // "<~>"
      case 48: // "~|"
      case 49: // "~&"
      case 50: // ":="
      case 51: // "-->"
      case 52: // "<<"
      case 53: // "include"
        value.move< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 165: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 243: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 73: // Annotations
        value.move< Annotation::Ptr > (that.value);
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (that.value);
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.move< AtomType::Ptr > (that.value);
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.move< BinaryConnective_t > (that.value);
        break;

      case 78: // ThfBinaryNonassoc
      case 79: // ThfBinaryAssoc
      case 80: // ThfOrFormula
      case 81: // ThfAndFormula
      case 82: // ThfApplyFormula
      case 122: // TffBinaryFormula
      case 123: // TffBinaryNonassoc
      case 124: // TffBinaryAssoc
      case 125: // TffOrFormula
      case 126: // TffAndFormula
      case 174: // FofBinaryFormula
      case 175: // FofBinaryNonassoc
      case 176: // FofBinaryAssoc
      case 177: // FofOrFormula
      case 178: // FofAndFormula
        value.move< BinaryLogic::Ptr > (that.value);
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.move< BinaryType::Ptr > (that.value);
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.move< ConditionalTerm::Ptr > (that.value);
        break;

      case 108: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (that.value);
        break;

      case 96: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (that.value);
        break;

      case 228: // DefinedTerm
        value.move< DefinedAtom::Ptr > (that.value);
        break;

      case 65: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (that.value);
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.move< DefinitionTerm::Ptr > (that.value);
        break;

      case 64: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 249: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (that.value);
        break;

      case 236: // FormulaData
        value.move< FormulaData::Ptr > (that.value);
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
        break;

      case 97: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (that.value);
        break;

      case 233: // GeneralData
        value.move< GeneralData::Ptr > (that.value);
        break;

      case 234: // GeneralFunction
        value.move< GeneralFunction::Ptr > (that.value);
        break;

      case 237: // GeneralList
        value.move< GeneralList::Ptr > (that.value);
        break;

      case 232: // GeneralTerm
        value.move< GeneralTerm::Ptr > (that.value);
        break;

      case 214: // TypeConstant
      case 215: // TypeFunctor
      case 216: // DefinedType
      case 217: // Atom
      case 218: // UntypedAtom
      case 222: // Constant
      case 223: // Functor
      case 224: // SystemConstant
      case 225: // SystemFunctor
      case 226: // DefinedConstant
      case 227: // DefinedFunctor
      case 230: // Name
      case 240: // AtomicWord
      case 241: // AtomicDefinedWord
      case 242: // AtomicSystemWord
      case 244: // FileName
      case 250: // LowerWordLiteral
      case 251: // SingleQuotedLiteral
      case 252: // DollarWordLiteral
      case 253: // DollarDollarWordLiteral
        value.move< Identifier::Ptr > (that.value);
        break;

      case 238: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (that.value);
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.move< InfixConnective_t > (that.value);
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (that.value);
        break;

      case 245: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (that.value);
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (that.value);
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (that.value);
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (that.value);
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
      case 102: // ThfLetDefns
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 148: // TfxLetDefns
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
        value.move< Logic::Ptr > (that.value);
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (that.value);
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (that.value);
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (that.value);
        break;

      case 158: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (that.value);
        break;

      case 247: // RationalLiteral
        value.move< RationalLiteral::Ptr > (that.value);
        break;

      case 246: // RealLiteral
        value.move< RealLiteral::Ptr > (that.value);
        break;

      case 231: // FormulaRole
        value.move< Role::Ptr > (that.value);
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.move< SequentLogic::Ptr > (that.value);
        break;

      case 63: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.move< SubType::Ptr > (that.value);
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
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
      case 15: // "$$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "="
      case 21: // "!="
      case 22: // "("
      case 23: // ")"
      case 24: // "["
      case 25: // "]"
      case 26: // "{"
      case 27: // "}"
      case 28: // "|"
      case 29: // "*"
      case 30: // ">"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "@-"
      case 35: // "@+"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@+"
      case 40: // "@@-"
      case 41: // "@="
      case 42: // "!>"
      case 43: // "?*"
      case 44: // "<=>"
      case 45: // "=>"
      case 46: // "<="
      case 47: // "<~>"
      case 48: // "~|"
      case 49: // "~&"
      case 50: // ":="
      case 51: // "-->"
      case 52: // "<<"
      case 53: // "include"
        value.move< Token::Ptr > (that.value);
        break;

      case 165: // TfxTupleType
        value.move< TupleType::Ptr > (that.value);
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.move< Type::Ptr > (that.value);
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypedAtom::Ptr > (that.value);
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.move< UnaryConnective_t > (that.value);
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (that.value);
        break;

      case 243: // Number
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.move< VariableTerm::Ptr > (that.value);
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
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
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
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

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
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
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
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
      case 73: // Annotations
        yylhs.value.emplace< Annotation::Ptr > ();
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        yylhs.value.emplace< Atom::Ptr > ();
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        yylhs.value.emplace< AtomType::Ptr > ();
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        yylhs.value.emplace< BinaryConnective_t > ();
        break;

      case 78: // ThfBinaryNonassoc
      case 79: // ThfBinaryAssoc
      case 80: // ThfOrFormula
      case 81: // ThfAndFormula
      case 82: // ThfApplyFormula
      case 122: // TffBinaryFormula
      case 123: // TffBinaryNonassoc
      case 124: // TffBinaryAssoc
      case 125: // TffOrFormula
      case 126: // TffAndFormula
      case 174: // FofBinaryFormula
      case 175: // FofBinaryNonassoc
      case 176: // FofBinaryAssoc
      case 177: // FofOrFormula
      case 178: // FofAndFormula
        yylhs.value.emplace< BinaryLogic::Ptr > ();
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        yylhs.value.emplace< BinaryType::Ptr > ();
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        yylhs.value.emplace< ConditionalTerm::Ptr > ();
        break;

      case 108: // ThfConnTerm
        yylhs.value.emplace< ConnectiveAtom::Ptr > ();
        break;

      case 96: // ThfSystemAtomic
        yylhs.value.emplace< ConstantAtom::Ptr > ();
        break;

      case 228: // DefinedTerm
        yylhs.value.emplace< DefinedAtom::Ptr > ();
        break;

      case 65: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        yylhs.value.emplace< DefinitionAtom::Ptr > ();
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        yylhs.value.emplace< DefinitionTerm::Ptr > ();
        break;

      case 64: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 249: // DistinctObjectLiteral
        yylhs.value.emplace< DistinctObjectLiteral::Ptr > ();
        break;

      case 236: // FormulaData
        yylhs.value.emplace< FormulaData::Ptr > ();
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
        break;

      case 97: // ThfFofFunction
        yylhs.value.emplace< FunctorAtom::Ptr > ();
        break;

      case 233: // GeneralData
        yylhs.value.emplace< GeneralData::Ptr > ();
        break;

      case 234: // GeneralFunction
        yylhs.value.emplace< GeneralFunction::Ptr > ();
        break;

      case 237: // GeneralList
        yylhs.value.emplace< GeneralList::Ptr > ();
        break;

      case 232: // GeneralTerm
        yylhs.value.emplace< GeneralTerm::Ptr > ();
        break;

      case 214: // TypeConstant
      case 215: // TypeFunctor
      case 216: // DefinedType
      case 217: // Atom
      case 218: // UntypedAtom
      case 222: // Constant
      case 223: // Functor
      case 224: // SystemConstant
      case 225: // SystemFunctor
      case 226: // DefinedConstant
      case 227: // DefinedFunctor
      case 230: // Name
      case 240: // AtomicWord
      case 241: // AtomicDefinedWord
      case 242: // AtomicSystemWord
      case 244: // FileName
      case 250: // LowerWordLiteral
      case 251: // SingleQuotedLiteral
      case 252: // DollarWordLiteral
      case 253: // DollarDollarWordLiteral
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 238: // IncludeDefinition
        yylhs.value.emplace< IncludeDefinition::Ptr > ();
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        yylhs.value.emplace< InfixConnective_t > ();
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        yylhs.value.emplace< InfixLogic::Ptr > ();
        break;

      case 245: // IntegerLiteral
        yylhs.value.emplace< IntegerLiteral::Ptr > ();
        break;

      case 239: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        yylhs.value.emplace< ListLogicElements::Ptr > ();
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        yylhs.value.emplace< ListNodeElements::Ptr > ();
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        yylhs.value.emplace< ListTypeElements::Ptr > ();
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
      case 102: // ThfLetDefns
      case 105: // ThfUnitaryTerm
      case 120: // TffFormula
      case 121: // TffLogicFormula
      case 127: // TffUnitFormula
      case 128: // TffPreunitFormula
      case 129: // TffUnitaryFormula
      case 135: // TffUnaryFormula
      case 148: // TfxLetDefns
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
        yylhs.value.emplace< Logic::Ptr > ();
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        yylhs.value.emplace< LogicTuple::Ptr > ();
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        yylhs.value.emplace< QuantifiedLogic::Ptr > ();
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        yylhs.value.emplace< QuantifiedQuantifier_t > ();
        break;

      case 158: // Tf1QuantifiedType
        yylhs.value.emplace< QuantifiedType::Ptr > ();
        break;

      case 247: // RationalLiteral
        yylhs.value.emplace< RationalLiteral::Ptr > ();
        break;

      case 246: // RealLiteral
        yylhs.value.emplace< RealLiteral::Ptr > ();
        break;

      case 231: // FormulaRole
        yylhs.value.emplace< Role::Ptr > ();
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        yylhs.value.emplace< SequentLogic::Ptr > ();
        break;

      case 63: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        yylhs.value.emplace< SubType::Ptr > ();
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
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
      case 15: // "$$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "="
      case 21: // "!="
      case 22: // "("
      case 23: // ")"
      case 24: // "["
      case 25: // "]"
      case 26: // "{"
      case 27: // "}"
      case 28: // "|"
      case 29: // "*"
      case 30: // ">"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "@-"
      case 35: // "@+"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@+"
      case 40: // "@@-"
      case 41: // "@="
      case 42: // "!>"
      case 43: // "?*"
      case 44: // "<=>"
      case 45: // "=>"
      case 46: // "<="
      case 47: // "<~>"
      case 48: // "~|"
      case 49: // "~&"
      case 50: // ":="
      case 51: // "-->"
      case 52: // "<<"
      case 53: // "include"
        yylhs.value.emplace< Token::Ptr > ();
        break;

      case 165: // TfxTupleType
        yylhs.value.emplace< TupleType::Ptr > ();
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        yylhs.value.emplace< Type::Ptr > ();
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        yylhs.value.emplace< TypedAtom::Ptr > ();
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        yylhs.value.emplace< UnaryConnective_t > ();
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        yylhs.value.emplace< UnaryLogic::Ptr > ();
        break;

      case 243: // Number
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        yylhs.value.emplace< VariableTerm::Ptr > ();
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
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
  case 2:
#line 345 "../../obj/src/GrammarParser.yy"
    {
      m_specification.setDefinitions( yystack_[0].value.as < Definitions::Ptr > () );
  }
#line 2188 "GrammarParser.cpp"
    break;

  case 3:
#line 352 "../../obj/src/GrammarParser.yy"
    {
    const auto definitions = yystack_[1].value.as < Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as < Definition::Ptr > ());
    yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2198 "GrammarParser.cpp"
    break;

  case 4:
#line 358 "../../obj/src/GrammarParser.yy"
    {
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as < Definition::Ptr > () );
    yylhs.value.as < Definitions::Ptr > () = definitions;
  }
#line 2208 "GrammarParser.cpp"
    break;

  case 5:
#line 368 "../../obj/src/GrammarParser.yy"
    {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2216 "GrammarParser.cpp"
    break;

  case 6:
#line 372 "../../obj/src/GrammarParser.yy"
    {
      yylhs.value.as < Definition::Ptr > () = yystack_[0].value.as < IncludeDefinition::Ptr > ();
  }
#line 2224 "GrammarParser.cpp"
    break;

  case 7:
#line 379 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2232 "GrammarParser.cpp"
    break;

  case 8:
#line 383 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2240 "GrammarParser.cpp"
    break;

  case 9:
#line 387 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2248 "GrammarParser.cpp"
    break;

  case 10:
#line 391 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2256 "GrammarParser.cpp"
    break;

  case 11:
#line 395 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2264 "GrammarParser.cpp"
    break;

  case 12:
#line 399 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < FormulaDefinition::Ptr > () = yystack_[0].value.as < FormulaDefinition::Ptr > ();
  }
#line 2272 "GrammarParser.cpp"
    break;

  case 13:
#line 406 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2281 "GrammarParser.cpp"
    break;

  case 14:
#line 411 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedHigherOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2293 "GrammarParser.cpp"
    break;

  case 15:
#line 422 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2302 "GrammarParser.cpp"
    break;

  case 16:
#line 427 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TypedFirstOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2314 "GrammarParser.cpp"
    break;

  case 17:
#line 438 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2323 "GrammarParser.cpp"
    break;

  case 18:
#line 443 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TheoryComputableFunctionalsFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2335 "GrammarParser.cpp"
    break;

  case 19:
#line 454 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2344 "GrammarParser.cpp"
    break;

  case 20:
#line 459 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< FirstOrderFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2356 "GrammarParser.cpp"
    break;

  case 21:
#line 470 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2365 "GrammarParser.cpp"
    break;

  case 22:
#line 475 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< ClauseNormalFormFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2377 "GrammarParser.cpp"
    break;

  case 23:
#line 486 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[2].location, yystack_[2].value.as < Logic::Ptr > ());
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Identifier::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Role::Ptr > (), yystack_[3].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2386 "GrammarParser.cpp"
    break;

  case 24:
#line 491 "../../obj/src/GrammarParser.yy"
    {
	auto formula = libtptp::make< TPTPProcessInstructionFormula >(yystack_[4].location, yystack_[4].value.as < Logic::Ptr > ());
	auto annotation = yystack_[2].value.as < Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as < Token::Ptr > ());
	formula->setAnnotations(annotation);
	yylhs.value.as < FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as < Token::Ptr > (), yystack_[9].value.as < Token::Ptr > (), yystack_[8].value.as < Identifier::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Role::Ptr > (), yystack_[5].value.as < Token::Ptr > (), formula, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2398 "GrammarParser.cpp"
    break;

  case 25:
#line 502 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as < GeneralTerm::Ptr > ());
    //source
  }
#line 2407 "GrammarParser.cpp"
    break;

  case 26:
#line 507 "../../obj/src/GrammarParser.yy"
    {
    //source, optionalInfo
	yylhs.value.as < Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as < GeneralTerm::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralList::Ptr > ());
  }
#line 2416 "GrammarParser.cpp"
    break;

  case 27:
#line 515 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2424 "GrammarParser.cpp"
    break;

  case 28:
#line 522 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2432 "GrammarParser.cpp"
    break;

  case 29:
#line 526 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 2440 "GrammarParser.cpp"
    break;

  case 30:
#line 530 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 2448 "GrammarParser.cpp"
    break;

  case 31:
#line 534 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 2456 "GrammarParser.cpp"
    break;

  case 32:
#line 541 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2464 "GrammarParser.cpp"
    break;

  case 33:
#line 545 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2472 "GrammarParser.cpp"
    break;

  case 34:
#line 549 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2480 "GrammarParser.cpp"
    break;

  case 35:
#line 553 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2488 "GrammarParser.cpp"
    break;

  case 36:
#line 560 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2496 "GrammarParser.cpp"
    break;

  case 37:
#line 564 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2504 "GrammarParser.cpp"
    break;

  case 38:
#line 568 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 2512 "GrammarParser.cpp"
    break;

  case 39:
#line 575 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2520 "GrammarParser.cpp"
    break;

  case 40:
#line 582 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2528 "GrammarParser.cpp"
    break;

  case 41:
#line 586 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2536 "GrammarParser.cpp"
    break;

  case 42:
#line 590 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 2544 "GrammarParser.cpp"
    break;

  case 43:
#line 597 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2553 "GrammarParser.cpp"
    break;

  case 44:
#line 602 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2562 "GrammarParser.cpp"
    break;

  case 45:
#line 610 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2571 "GrammarParser.cpp"
    break;

  case 46:
#line 615 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2580 "GrammarParser.cpp"
    break;

  case 47:
#line 623 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2589 "GrammarParser.cpp"
    break;

  case 48:
#line 628 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::APPLY);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2598 "GrammarParser.cpp"
    break;

  case 49:
#line 636 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2606 "GrammarParser.cpp"
    break;

  case 50:
#line 640 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2614 "GrammarParser.cpp"
    break;

  case 51:
#line 644 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2622 "GrammarParser.cpp"
    break;

  case 52:
#line 651 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2630 "GrammarParser.cpp"
    break;

  case 53:
#line 655 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 2638 "GrammarParser.cpp"
    break;

  case 54:
#line 662 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 2646 "GrammarParser.cpp"
    break;

  case 55:
#line 666 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2654 "GrammarParser.cpp"
    break;

  case 56:
#line 670 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 2662 "GrammarParser.cpp"
    break;

  case 57:
#line 674 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 2673 "GrammarParser.cpp"
    break;

  case 58:
#line 684 "../../obj/src/GrammarParser.yy"
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), variables, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2682 "GrammarParser.cpp"
    break;

  case 59:
#line 692 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 2692 "GrammarParser.cpp"
    break;

  case 60:
#line 698 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 2702 "GrammarParser.cpp"
    break;

  case 61:
#line 707 "../../obj/src/GrammarParser.yy"
    {
	auto var = yystack_[2].value.as < VariableTerm::Ptr > ();
	var->setColon(yystack_[1].value.as < Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as < Type::Ptr > ();
	var->setType(type);
  }
#line 2713 "GrammarParser.cpp"
    break;

  case 62:
#line 717 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 2721 "GrammarParser.cpp"
    break;

  case 63:
#line 721 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 2729 "GrammarParser.cpp"
    break;

  case 64:
#line 728 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2737 "GrammarParser.cpp"
    break;

  case 65:
#line 735 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2745 "GrammarParser.cpp"
    break;

  case 66:
#line 742 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2753 "GrammarParser.cpp"
    break;

  case 67:
#line 746 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 2761 "GrammarParser.cpp"
    break;

  case 68:
#line 750 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < ConstantAtom::Ptr > ();
  }
#line 2769 "GrammarParser.cpp"
    break;

  case 69:
#line 754 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < FunctorAtom::Ptr > ();
  }
#line 2777 "GrammarParser.cpp"
    break;

  case 70:
#line 761 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2785 "GrammarParser.cpp"
    break;

  case 71:
#line 765 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 2793 "GrammarParser.cpp"
    break;

  case 72:
#line 772 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2801 "GrammarParser.cpp"
    break;

  case 73:
#line 776 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 2809 "GrammarParser.cpp"
    break;

  case 74:
#line 780 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 2817 "GrammarParser.cpp"
    break;

  case 75:
#line 784 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < ConnectiveAtom::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Term::Ptr > () = logic;
  }
#line 2828 "GrammarParser.cpp"
    break;

  case 76:
#line 791 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 2836 "GrammarParser.cpp"
    break;

  case 77:
#line 798 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2844 "GrammarParser.cpp"
    break;

  case 78:
#line 805 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConstantAtom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2852 "GrammarParser.cpp"
    break;

  case 79:
#line 812 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 2860 "GrammarParser.cpp"
    break;

  case 80:
#line 816 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 2868 "GrammarParser.cpp"
    break;

  case 81:
#line 820 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FunctorAtom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 2876 "GrammarParser.cpp"
    break;

  case 82:
#line 827 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2884 "GrammarParser.cpp"
    break;

  case 83:
#line 834 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Type::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2892 "GrammarParser.cpp"
    break;

  case 84:
#line 841 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 2900 "GrammarParser.cpp"
    break;

  case 85:
#line 845 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2908 "GrammarParser.cpp"
    break;

  case 86:
#line 852 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 2918 "GrammarParser.cpp"
    break;

  case 87:
#line 858 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 2928 "GrammarParser.cpp"
    break;

  case 88:
#line 867 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 2936 "GrammarParser.cpp"
    break;

  case 89:
#line 871 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 2944 "GrammarParser.cpp"
    break;

  case 90:
#line 878 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 2952 "GrammarParser.cpp"
    break;

  case 91:
#line 885 "../../obj/src/GrammarParser.yy"
    {
	//could be of type DefinitionAtoms, but Logics is expected
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 2963 "GrammarParser.cpp"
    break;

  case 92:
#line 892 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 2973 "GrammarParser.cpp"
    break;

  case 93:
#line 901 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 2981 "GrammarParser.cpp"
    break;

  case 94:
#line 905 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 2989 "GrammarParser.cpp"
    break;

  case 95:
#line 909 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 3000 "GrammarParser.cpp"
    break;

  case 96:
#line 919 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3008 "GrammarParser.cpp"
    break;

  case 97:
#line 923 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3016 "GrammarParser.cpp"
    break;

  case 98:
#line 930 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3026 "GrammarParser.cpp"
    break;

  case 99:
#line 936 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3036 "GrammarParser.cpp"
    break;

  case 100:
#line 945 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3045 "GrammarParser.cpp"
    break;

  case 101:
#line 950 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < BinaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3054 "GrammarParser.cpp"
    break;

  case 102:
#line 955 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < InfixConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3063 "GrammarParser.cpp"
    break;

  case 103:
#line 960 "../../obj/src/GrammarParser.yy"
    {
	auto pair = yystack_[0].value.as < UnaryConnective_t > ();
	yylhs.value.as < ConnectiveAtom::Ptr > () = libtptp::make< ConnectiveAtom >(yylhs.location, pair.first);
  }
#line 3072 "GrammarParser.cpp"
    break;

  case 104:
#line 968 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ListLogicElements::Ptr > () = yystack_[0].value.as < ListLogicElements::Ptr > ();
  }
#line 3080 "GrammarParser.cpp"
    break;

  case 105:
#line 975 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3088 "GrammarParser.cpp"
    break;

  case 106:
#line 979 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < TypedAtom::Ptr > () = type;
  }
#line 3099 "GrammarParser.cpp"
    break;

  case 107:
#line 989 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3107 "GrammarParser.cpp"
    break;

  case 108:
#line 993 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3115 "GrammarParser.cpp"
    break;

  case 109:
#line 997 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3123 "GrammarParser.cpp"
    break;

  case 110:
#line 1004 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3131 "GrammarParser.cpp"
    break;

  case 111:
#line 1011 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < BinaryLogic::Ptr > ());
  }
#line 3139 "GrammarParser.cpp"
    break;

  case 112:
#line 1018 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3147 "GrammarParser.cpp"
    break;

  case 113:
#line 1022 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3155 "GrammarParser.cpp"
    break;

  case 114:
#line 1026 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3163 "GrammarParser.cpp"
    break;

  case 115:
#line 1034 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3171 "GrammarParser.cpp"
    break;

  case 116:
#line 1038 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < BinaryType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3179 "GrammarParser.cpp"
    break;

  case 117:
#line 1046 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3187 "GrammarParser.cpp"
    break;

  case 118:
#line 1050 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3195 "GrammarParser.cpp"
    break;

  case 119:
#line 1058 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < AtomType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3203 "GrammarParser.cpp"
    break;

  case 120:
#line 1062 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::UNION);
  }
#line 3211 "GrammarParser.cpp"
    break;

  case 121:
#line 1069 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 3219 "GrammarParser.cpp"
    break;

  case 122:
#line 1076 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 3227 "GrammarParser.cpp"
    break;

  case 123:
#line 1080 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < SequentLogic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < SequentLogic::Ptr > () = logic;
  }
#line 3238 "GrammarParser.cpp"
    break;

  case 124:
#line 1091 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3246 "GrammarParser.cpp"
    break;

  case 125:
#line 1095 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 3254 "GrammarParser.cpp"
    break;

  case 126:
#line 1099 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SubType::Ptr > ();
  }
#line 3262 "GrammarParser.cpp"
    break;

  case 127:
#line 1103 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 3270 "GrammarParser.cpp"
    break;

  case 128:
#line 1110 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3278 "GrammarParser.cpp"
    break;

  case 129:
#line 1114 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3286 "GrammarParser.cpp"
    break;

  case 130:
#line 1118 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3294 "GrammarParser.cpp"
    break;

  case 131:
#line 1122 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3302 "GrammarParser.cpp"
    break;

  case 132:
#line 1129 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3310 "GrammarParser.cpp"
    break;

  case 133:
#line 1133 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3318 "GrammarParser.cpp"
    break;

  case 134:
#line 1140 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3326 "GrammarParser.cpp"
    break;

  case 135:
#line 1147 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3334 "GrammarParser.cpp"
    break;

  case 136:
#line 1151 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 3342 "GrammarParser.cpp"
    break;

  case 137:
#line 1158 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3351 "GrammarParser.cpp"
    break;

  case 138:
#line 1163 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3360 "GrammarParser.cpp"
    break;

  case 139:
#line 1171 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3369 "GrammarParser.cpp"
    break;

  case 140:
#line 1176 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3378 "GrammarParser.cpp"
    break;

  case 141:
#line 1184 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3386 "GrammarParser.cpp"
    break;

  case 142:
#line 1188 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3394 "GrammarParser.cpp"
    break;

  case 143:
#line 1192 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3402 "GrammarParser.cpp"
    break;

  case 144:
#line 1199 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3410 "GrammarParser.cpp"
    break;

  case 145:
#line 1203 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3418 "GrammarParser.cpp"
    break;

  case 146:
#line 1210 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 3426 "GrammarParser.cpp"
    break;

  case 147:
#line 1214 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3434 "GrammarParser.cpp"
    break;

  case 148:
#line 1218 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3442 "GrammarParser.cpp"
    break;

  case 149:
#line 1222 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 3453 "GrammarParser.cpp"
    break;

  case 150:
#line 1232 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3461 "GrammarParser.cpp"
    break;

  case 151:
#line 1239 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yystack_[3].location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), list, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3470 "GrammarParser.cpp"
    break;

  case 152:
#line 1247 "../../obj/src/GrammarParser.yy"
    {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 3481 "GrammarParser.cpp"
    break;

  case 153:
#line 1254 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 3491 "GrammarParser.cpp"
    break;

  case 154:
#line 1263 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3499 "GrammarParser.cpp"
    break;

  case 155:
#line 1267 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < VariableTerm::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3507 "GrammarParser.cpp"
    break;

  case 156:
#line 1274 "../../obj/src/GrammarParser.yy"
    {
	auto variable = yystack_[2].value.as < VariableTerm::Ptr > ();
	variable->setColon(yystack_[1].value.as < Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as < AtomType::Ptr > (); //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	yylhs.value.as < VariableTerm::Ptr > () = variable;
  }
#line 3519 "GrammarParser.cpp"
    break;

  case 157:
#line 1285 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < UnaryLogic::Ptr > ();
  }
#line 3527 "GrammarParser.cpp"
    break;

  case 158:
#line 1289 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 3535 "GrammarParser.cpp"
    break;

  case 159:
#line 1296 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3543 "GrammarParser.cpp"
    break;

  case 160:
#line 1303 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3551 "GrammarParser.cpp"
    break;

  case 161:
#line 1310 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3559 "GrammarParser.cpp"
    break;

  case 162:
#line 1314 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3567 "GrammarParser.cpp"
    break;

  case 163:
#line 1318 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3575 "GrammarParser.cpp"
    break;

  case 164:
#line 1325 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3583 "GrammarParser.cpp"
    break;

  case 165:
#line 1329 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3591 "GrammarParser.cpp"
    break;

  case 166:
#line 1336 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3599 "GrammarParser.cpp"
    break;

  case 167:
#line 1343 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3607 "GrammarParser.cpp"
    break;

  case 168:
#line 1347 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3615 "GrammarParser.cpp"
    break;

  case 169:
#line 1351 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < ConditionalTerm::Ptr > ();
  }
#line 3623 "GrammarParser.cpp"
    break;

  case 170:
#line 1355 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < DefinitionTerm::Ptr > ();
  }
#line 3631 "GrammarParser.cpp"
    break;

  case 171:
#line 1362 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3639 "GrammarParser.cpp"
    break;

  case 172:
#line 1369 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3647 "GrammarParser.cpp"
    break;

  case 173:
#line 1373 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3655 "GrammarParser.cpp"
    break;

  case 174:
#line 1380 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Logic::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3663 "GrammarParser.cpp"
    break;

  case 175:
#line 1387 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as < Token::Ptr > (), yystack_[7].value.as < Token::Ptr > (), yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Type::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Logic::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3671 "GrammarParser.cpp"
    break;

  case 176:
#line 1394 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 3679 "GrammarParser.cpp"
    break;

  case 177:
#line 1398 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3687 "GrammarParser.cpp"
    break;

  case 178:
#line 1405 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 3697 "GrammarParser.cpp"
    break;

  case 179:
#line 1411 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < TypedAtom::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 3707 "GrammarParser.cpp"
    break;

  case 180:
#line 1420 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinitionAtom::Ptr > ();
  }
#line 3715 "GrammarParser.cpp"
    break;

  case 181:
#line 1424 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3723 "GrammarParser.cpp"
    break;

  case 182:
#line 1431 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 3731 "GrammarParser.cpp"
    break;

  case 183:
#line 1438 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 3739 "GrammarParser.cpp"
    break;

  case 184:
#line 1442 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3747 "GrammarParser.cpp"
    break;

  case 185:
#line 1449 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3757 "GrammarParser.cpp"
    break;

  case 186:
#line 1455 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < DefinitionAtom::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3767 "GrammarParser.cpp"
    break;

  case 187:
#line 1464 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 3775 "GrammarParser.cpp"
    break;

  case 188:
#line 1468 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 3783 "GrammarParser.cpp"
    break;

  case 189:
#line 1472 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3791 "GrammarParser.cpp"
    break;

  case 190:
#line 1479 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 3799 "GrammarParser.cpp"
    break;

  case 191:
#line 1483 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 3807 "GrammarParser.cpp"
    break;

  case 192:
#line 1487 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < LogicTuple::Ptr > ();
  }
#line 3815 "GrammarParser.cpp"
    break;

  case 193:
#line 1491 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 3823 "GrammarParser.cpp"
    break;

  case 194:
#line 1495 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 3834 "GrammarParser.cpp"
    break;

  case 195:
#line 1505 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3842 "GrammarParser.cpp"
    break;

  case 196:
#line 1509 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 3850 "GrammarParser.cpp"
    break;

  case 197:
#line 1516 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3860 "GrammarParser.cpp"
    break;

  case 198:
#line 1522 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 3870 "GrammarParser.cpp"
    break;

  case 199:
#line 1531 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3878 "GrammarParser.cpp"
    break;

  case 200:
#line 1535 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < TypedAtom::Ptr > () = type;
  }
#line 3889 "GrammarParser.cpp"
    break;

  case 201:
#line 1545 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3897 "GrammarParser.cpp"
    break;

  case 202:
#line 1549 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < BinaryType::Ptr > ();
  }
#line 3905 "GrammarParser.cpp"
    break;

  case 203:
#line 1553 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < QuantifiedType::Ptr > ();
  }
#line 3913 "GrammarParser.cpp"
    break;

  case 204:
#line 1557 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < Type::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
#line 3924 "GrammarParser.cpp"
    break;

  case 205:
#line 1567 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
  }
#line 3932 "GrammarParser.cpp"
    break;

  case 206:
#line 1574 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3940 "GrammarParser.cpp"
    break;

  case 207:
#line 1578 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
#line 3951 "GrammarParser.cpp"
    break;

  case 208:
#line 1588 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Type::Ptr > () = yystack_[0].value.as < AtomType::Ptr > ();
  }
#line 3959 "GrammarParser.cpp"
    break;

  case 209:
#line 1592 "../../obj/src/GrammarParser.yy"
    {
	auto type = yystack_[1].value.as < BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Type::Ptr > () = type;
  }
#line 3970 "GrammarParser.cpp"
    break;

  case 210:
#line 1602 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 3978 "GrammarParser.cpp"
    break;

  case 211:
#line 1606 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 3986 "GrammarParser.cpp"
    break;

  case 212:
#line 1610 "../../obj/src/GrammarParser.yy"
    {
	auto functor = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::TYPE);
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, functor);
  }
#line 3995 "GrammarParser.cpp"
    break;

  case 213:
#line 1615 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 4003 "GrammarParser.cpp"
    break;

  case 214:
#line 1619 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as < TupleType::Ptr > ());
  }
#line 4011 "GrammarParser.cpp"
    break;

  case 215:
#line 1626 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < AtomType::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4021 "GrammarParser.cpp"
    break;

  case 216:
#line 1632 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4031 "GrammarParser.cpp"
    break;

  case 217:
#line 1641 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < Type::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 4039 "GrammarParser.cpp"
    break;

  case 218:
#line 1648 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < Type::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4047 "GrammarParser.cpp"
    break;

  case 219:
#line 1652 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as < BinaryType::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 4055 "GrammarParser.cpp"
    break;

  case 220:
#line 1659 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListTypeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4063 "GrammarParser.cpp"
    break;

  case 221:
#line 1666 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListTypeElements >(yylhs.location);
	list->add(yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4073 "GrammarParser.cpp"
    break;

  case 222:
#line 1672 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListTypeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Type::Ptr > ());
	yylhs.value.as < ListTypeElements::Ptr > () = list;
  }
#line 4083 "GrammarParser.cpp"
    break;

  case 223:
#line 1681 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as < Identifier::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 4091 "GrammarParser.cpp"
    break;

  case 224:
#line 1688 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4099 "GrammarParser.cpp"
    break;

  case 225:
#line 1692 "../../obj/src/GrammarParser.yy"
    {
	auto sequent = yystack_[1].value.as < SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < SequentLogic::Ptr > () = sequent;
  }
#line 4110 "GrammarParser.cpp"
    break;

  case 226:
#line 1703 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4118 "GrammarParser.cpp"
    break;

  case 227:
#line 1707 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < TypedAtom::Ptr > ();
  }
#line 4126 "GrammarParser.cpp"
    break;

  case 228:
#line 1714 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4134 "GrammarParser.cpp"
    break;

  case 229:
#line 1718 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4142 "GrammarParser.cpp"
    break;

  case 230:
#line 1725 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[5].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, op, list, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4152 "GrammarParser.cpp"
    break;

  case 231:
#line 1736 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4160 "GrammarParser.cpp"
    break;

  case 232:
#line 1740 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < SequentLogic::Ptr > ();
  }
#line 4168 "GrammarParser.cpp"
    break;

  case 233:
#line 1747 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4176 "GrammarParser.cpp"
    break;

  case 234:
#line 1751 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4184 "GrammarParser.cpp"
    break;

  case 235:
#line 1755 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4192 "GrammarParser.cpp"
    break;

  case 236:
#line 1762 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4200 "GrammarParser.cpp"
    break;

  case 237:
#line 1766 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4208 "GrammarParser.cpp"
    break;

  case 238:
#line 1773 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), yystack_[1].value.as < BinaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4216 "GrammarParser.cpp"
    break;

  case 239:
#line 1780 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4224 "GrammarParser.cpp"
    break;

  case 240:
#line 1784 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryLogic::Ptr > () = yystack_[0].value.as < BinaryLogic::Ptr > ();
  }
#line 4232 "GrammarParser.cpp"
    break;

  case 241:
#line 1791 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4241 "GrammarParser.cpp"
    break;

  case 242:
#line 1796 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4250 "GrammarParser.cpp"
    break;

  case 243:
#line 1804 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4259 "GrammarParser.cpp"
    break;

  case 244:
#line 1809 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as < BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < BinaryLogic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4268 "GrammarParser.cpp"
    break;

  case 245:
#line 1817 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as < UnaryConnective_t > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4276 "GrammarParser.cpp"
    break;

  case 246:
#line 1821 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4284 "GrammarParser.cpp"
    break;

  case 247:
#line 1828 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4292 "GrammarParser.cpp"
    break;

  case 248:
#line 1835 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4300 "GrammarParser.cpp"
    break;

  case 249:
#line 1839 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4308 "GrammarParser.cpp"
    break;

  case 250:
#line 1846 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < QuantifiedLogic::Ptr > ();
  }
#line 4316 "GrammarParser.cpp"
    break;

  case 251:
#line 1850 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4324 "GrammarParser.cpp"
    break;

  case 252:
#line 1854 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 4335 "GrammarParser.cpp"
    break;

  case 253:
#line 1864 "../../obj/src/GrammarParser.yy"
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < ListNodeElements::Ptr > (), yystack_[2].value.as < Token::Ptr > ());
	yylhs.value.as < QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as < QuantifiedQuantifier_t > (), variables, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4344 "GrammarParser.cpp"
    break;

  case 254:
#line 1872 "../../obj/src/GrammarParser.yy"
    {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< ListNodeElements >(yylhs.location);
	variables->add(yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = variables;
  }
#line 4355 "GrammarParser.cpp"
    break;

  case 255:
#line 1879 "../../obj/src/GrammarParser.yy"
    {
	auto variables = yystack_[2].value.as < ListNodeElements::Ptr > ();
	variables->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < VariableTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = variables;
  }
#line 4365 "GrammarParser.cpp"
    break;

  case 256:
#line 1888 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4373 "GrammarParser.cpp"
    break;

  case 257:
#line 1892 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4381 "GrammarParser.cpp"
    break;

  case 258:
#line 1896 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4389 "GrammarParser.cpp"
    break;

  case 259:
#line 1903 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4397 "GrammarParser.cpp"
    break;

  case 260:
#line 1910 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Term::Ptr > ();
  }
#line 4405 "GrammarParser.cpp"
    break;

  case 261:
#line 1914 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4413 "GrammarParser.cpp"
    break;

  case 262:
#line 1921 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4421 "GrammarParser.cpp"
    break;

  case 263:
#line 1928 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as < Term::Ptr > (), yystack_[1].value.as < InfixConnective_t > (), yystack_[0].value.as < Term::Ptr > ());
  }
#line 4429 "GrammarParser.cpp"
    break;

  case 264:
#line 1935 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4437 "GrammarParser.cpp"
    break;

  case 265:
#line 1942 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4445 "GrammarParser.cpp"
    break;

  case 266:
#line 1946 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 4453 "GrammarParser.cpp"
    break;

  case 267:
#line 1953 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < DefinedAtom::Ptr > ();
  }
#line 4461 "GrammarParser.cpp"
    break;

  case 268:
#line 1957 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4469 "GrammarParser.cpp"
    break;

  case 269:
#line 1964 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4477 "GrammarParser.cpp"
    break;

  case 270:
#line 1971 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4485 "GrammarParser.cpp"
    break;

  case 271:
#line 1975 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4493 "GrammarParser.cpp"
    break;

  case 272:
#line 1982 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4501 "GrammarParser.cpp"
    break;

  case 273:
#line 1986 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4509 "GrammarParser.cpp"
    break;

  case 274:
#line 1993 "../../obj/src/GrammarParser.yy"
    {
	auto terms = libtptp::make< ListLogicElements >(yylhs.location);
	terms->add(yystack_[0].value.as < Term::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = terms;
  }
#line 4519 "GrammarParser.cpp"
    break;

  case 275:
#line 1999 "../../obj/src/GrammarParser.yy"
    {
	auto terms = yystack_[2].value.as < ListLogicElements::Ptr > ();
	terms->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Term::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = terms;
  }
#line 4529 "GrammarParser.cpp"
    break;

  case 276:
#line 2008 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4537 "GrammarParser.cpp"
    break;

  case 277:
#line 2012 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Term::Ptr > () = yystack_[0].value.as < VariableTerm::Ptr > ();
  }
#line 4545 "GrammarParser.cpp"
    break;

  case 278:
#line 2019 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4553 "GrammarParser.cpp"
    break;

  case 279:
#line 2023 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4561 "GrammarParser.cpp"
    break;

  case 280:
#line 2027 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Atom::Ptr > () = yystack_[0].value.as < Atom::Ptr > ();
  }
#line 4569 "GrammarParser.cpp"
    break;

  case 281:
#line 2034 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as < LogicTuple::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < LogicTuple::Ptr > ());
  }
#line 4577 "GrammarParser.cpp"
    break;

  case 282:
#line 2038 "../../obj/src/GrammarParser.yy"
    {
	auto sequent = yystack_[1].value.as < SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
  }
#line 4587 "GrammarParser.cpp"
    break;

  case 283:
#line 2047 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4595 "GrammarParser.cpp"
    break;

  case 284:
#line 2051 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListLogicElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 4603 "GrammarParser.cpp"
    break;

  case 285:
#line 2058 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLogicElements >(yylhs.location);
	list->add(yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4613 "GrammarParser.cpp"
    break;

  case 286:
#line 2064 "../../obj/src/GrammarParser.yy"
    {
	auto list = yystack_[2].value.as < ListLogicElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Logic::Ptr > ());
	yylhs.value.as < ListLogicElements::Ptr > () = list;
  }
#line 4623 "GrammarParser.cpp"
    break;

  case 287:
#line 2073 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4631 "GrammarParser.cpp"
    break;

  case 288:
#line 2077 "../../obj/src/GrammarParser.yy"
    {
	auto logic = yystack_[1].value.as < Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as < Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < Logic::Ptr > () = logic;
  }
#line 4642 "GrammarParser.cpp"
    break;

  case 289:
#line 2087 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4650 "GrammarParser.cpp"
    break;

  case 290:
#line 2091 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as < Logic::Ptr > (), op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4659 "GrammarParser.cpp"
    break;

  case 291:
#line 2099 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < Logic::Ptr > ();
  }
#line 4667 "GrammarParser.cpp"
    break;

  case 292:
#line 2103 "../../obj/src/GrammarParser.yy"
    {
	auto op = std::make_pair(yystack_[1].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as < Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as < Logic::Ptr > ());
  }
#line 4676 "GrammarParser.cpp"
    break;

  case 293:
#line 2108 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Logic::Ptr > () = yystack_[0].value.as < InfixLogic::Ptr > ();
  }
#line 4684 "GrammarParser.cpp"
    break;

  case 294:
#line 2115 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4692 "GrammarParser.cpp"
    break;

  case 295:
#line 2119 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4700 "GrammarParser.cpp"
    break;

  case 296:
#line 2123 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = yystack_[0].value.as < QuantifiedQuantifier_t > ();
  }
#line 4708 "GrammarParser.cpp"
    break;

  case 297:
#line 2130 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::EXCLAMATIONGREATER);
  }
#line 4716 "GrammarParser.cpp"
    break;

  case 298:
#line 2134 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::QUESTIONMARKSTAR);
  }
#line 4724 "GrammarParser.cpp"
    break;

  case 299:
#line 2141 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::CARET);
  }
#line 4732 "GrammarParser.cpp"
    break;

  case 300:
#line 2145 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATPLUS);
  }
#line 4740 "GrammarParser.cpp"
    break;

  case 301:
#line 2149 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::ATMINUS);
  }
#line 4748 "GrammarParser.cpp"
    break;

  case 302:
#line 2156 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 4756 "GrammarParser.cpp"
    break;

  case 303:
#line 2160 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = yystack_[0].value.as < UnaryConnective_t > ();
  }
#line 4764 "GrammarParser.cpp"
    break;

  case 304:
#line 2167 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::UNIVERSAL_QUANTIFICATION);
  }
#line 4772 "GrammarParser.cpp"
    break;

  case 305:
#line 2171 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EXISTENTIAL_QUANTIFICATION);
  }
#line 4780 "GrammarParser.cpp"
    break;

  case 306:
#line 2175 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::INDEFINITE_DESCRIPTION);
  }
#line 4788 "GrammarParser.cpp"
    break;

  case 307:
#line 2179 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::DEFINITE_DESCRIPTION);
  }
#line 4796 "GrammarParser.cpp"
    break;

  case 308:
#line 2183 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::EQUALITY);
  }
#line 4804 "GrammarParser.cpp"
    break;

  case 309:
#line 2190 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4812 "GrammarParser.cpp"
    break;

  case 310:
#line 2194 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < QuantifiedQuantifier_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4820 "GrammarParser.cpp"
    break;

  case 311:
#line 2203 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 4828 "GrammarParser.cpp"
    break;

  case 312:
#line 2207 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 4836 "GrammarParser.cpp"
    break;

  case 313:
#line 2211 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 4844 "GrammarParser.cpp"
    break;

  case 314:
#line 2215 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 4852 "GrammarParser.cpp"
    break;

  case 315:
#line 2219 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 4860 "GrammarParser.cpp"
    break;

  case 316:
#line 2223 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 4868 "GrammarParser.cpp"
    break;

  case 317:
#line 2230 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 4876 "GrammarParser.cpp"
    break;

  case 318:
#line 2234 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < BinaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 4884 "GrammarParser.cpp"
    break;

  case 319:
#line 2241 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < UnaryConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 4892 "GrammarParser.cpp"
    break;

  case 320:
#line 2248 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4900 "GrammarParser.cpp"
    break;

  case 321:
#line 2255 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4908 "GrammarParser.cpp"
    break;

  case 322:
#line 2262 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4916 "GrammarParser.cpp"
    break;

  case 323:
#line 2269 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4924 "GrammarParser.cpp"
    break;

  case 324:
#line 2273 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4932 "GrammarParser.cpp"
    break;

  case 325:
#line 2280 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4940 "GrammarParser.cpp"
    break;

  case 326:
#line 2284 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4948 "GrammarParser.cpp"
    break;

  case 327:
#line 2291 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = yystack_[0].value.as < InfixConnective_t > ();
  }
#line 4956 "GrammarParser.cpp"
    break;

  case 328:
#line 2298 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 4964 "GrammarParser.cpp"
    break;

  case 329:
#line 2305 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < InfixConnective_t > () = std::make_pair(yystack_[0].value.as < Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 4972 "GrammarParser.cpp"
    break;

  case 330:
#line 2312 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4980 "GrammarParser.cpp"
    break;

  case 331:
#line 2319 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4988 "GrammarParser.cpp"
    break;

  case 332:
#line 2326 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 4996 "GrammarParser.cpp"
    break;

  case 333:
#line 2333 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5004 "GrammarParser.cpp"
    break;

  case 334:
#line 2340 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5012 "GrammarParser.cpp"
    break;

  case 335:
#line 2347 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5020 "GrammarParser.cpp"
    break;

  case 336:
#line 2354 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5028 "GrammarParser.cpp"
    break;

  case 337:
#line 2358 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5036 "GrammarParser.cpp"
    break;

  case 338:
#line 2365 "../../obj/src/GrammarParser.yy"
    {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < Identifier::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 5048 "GrammarParser.cpp"
    break;

  case 339:
#line 2373 "../../obj/src/GrammarParser.yy"
    {
	const auto list = yystack_[2].value.as < ListNodeElements::Ptr > ();
	list->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Identifier::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 5058 "GrammarParser.cpp"
    break;

  case 340:
#line 2382 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5066 "GrammarParser.cpp"
    break;

  case 341:
#line 2386 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > (), Identifier::Kind::NUMBER);
  }
#line 5074 "GrammarParser.cpp"
    break;

  case 342:
#line 2393 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < Role::Ptr > () = libtptp::make< Role >( yylhs.location, yystack_[0].value.as < Identifier::Ptr > () );
  }
#line 5082 "GrammarParser.cpp"
    break;

  case 343:
#line 2400 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralData::Ptr > ();
  }
#line 5090 "GrammarParser.cpp"
    break;

  case 344:
#line 2404 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as < GeneralData::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralTerm::Ptr > ());
  }
#line 5098 "GrammarParser.cpp"
    break;

  case 345:
#line 2408 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralTerm::Ptr > () = yystack_[0].value.as < GeneralList::Ptr > ();
  }
#line 5106 "GrammarParser.cpp"
    break;

  case 346:
#line 2415 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < Identifier::Ptr > ());
  }
#line 5114 "GrammarParser.cpp"
    break;

  case 347:
#line 2419 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < GeneralFunction::Ptr > ());
  }
#line 5122 "GrammarParser.cpp"
    break;

  case 348:
#line 2423 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < VariableTerm::Ptr > ());
  }
#line 5130 "GrammarParser.cpp"
    break;

  case 349:
#line 2427 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < ValueLiteral::Ptr > ());
  }
#line 5138 "GrammarParser.cpp"
    break;

  case 350:
#line 2431 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < DistinctObjectLiteral::Ptr > ());
  }
#line 5146 "GrammarParser.cpp"
    break;

  case 351:
#line 2435 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as < FormulaData::Ptr > ());
  }
#line 5154 "GrammarParser.cpp"
    break;

  case 352:
#line 2442 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, yystack_[3].value.as < Identifier::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5162 "GrammarParser.cpp"
    break;

  case 353:
#line 2449 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListNodeElements >(yylhs.location);
	list->add(yystack_[0].value.as < GeneralTerm::Ptr > ());
	yylhs.value.as < ListNodeElements::Ptr > () = list;
  }
#line 5172 "GrammarParser.cpp"
    break;

  case 354:
#line 2455 "../../obj/src/GrammarParser.yy"
    {
    auto terms = yystack_[2].value.as < ListNodeElements::Ptr > ();
    terms->add(yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < GeneralTerm::Ptr > ());
    yylhs.value.as < ListNodeElements::Ptr > () = terms;
  }
#line 5182 "GrammarParser.cpp"
    break;

  case 355:
#line 2464 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5190 "GrammarParser.cpp"
    break;

  case 356:
#line 2468 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5198 "GrammarParser.cpp"
    break;

  case 357:
#line 2472 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5206 "GrammarParser.cpp"
    break;

  case 358:
#line 2476 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Logic::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5214 "GrammarParser.cpp"
    break;

  case 359:
#line 2480 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < FormulaData::Ptr > () = libtptp::make< FormulaData >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < Term::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5222 "GrammarParser.cpp"
    break;

  case 360:
#line 2487 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5231 "GrammarParser.cpp"
    break;

  case 361:
#line 2492 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 5240 "GrammarParser.cpp"
    break;

  case 362:
#line 2501 "../../obj/src/GrammarParser.yy"
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as < Token::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5249 "GrammarParser.cpp"
    break;

  case 363:
#line 2506 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as < Token::Ptr > (), yystack_[5].value.as < Token::Ptr > (), yystack_[4].value.as < Identifier::Ptr > (), yystack_[3].value.as < Token::Ptr > (), yystack_[2].value.as < ListLiteral::Ptr > (), yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
  }
#line 5257 "GrammarParser.cpp"
    break;

  case 364:
#line 2513 "../../obj/src/GrammarParser.yy"
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as < Token::Ptr > (), yystack_[1].value.as < ListNodeElements::Ptr > (), yystack_[0].value.as < Token::Ptr > ());
	yylhs.value.as < ListLiteral::Ptr > () = list;
  }
#line 5266 "GrammarParser.cpp"
    break;

  case 365:
#line 2521 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5274 "GrammarParser.cpp"
    break;

  case 366:
#line 2525 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5282 "GrammarParser.cpp"
    break;

  case 367:
#line 2532 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5290 "GrammarParser.cpp"
    break;

  case 368:
#line 2539 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5298 "GrammarParser.cpp"
    break;

  case 369:
#line 2546 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < IntegerLiteral::Ptr > ();
  }
#line 5306 "GrammarParser.cpp"
    break;

  case 370:
#line 2550 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RealLiteral::Ptr > ();
  }
#line 5314 "GrammarParser.cpp"
    break;

  case 371:
#line 2554 "../../obj/src/GrammarParser.yy"
    {
    yylhs.value.as < ValueLiteral::Ptr > () = yystack_[0].value.as < RationalLiteral::Ptr > ();
  }
#line 5322 "GrammarParser.cpp"
    break;

  case 372:
#line 2561 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = yystack_[0].value.as < Identifier::Ptr > ();
  }
#line 5330 "GrammarParser.cpp"
    break;

  case 373:
#line 2568 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as < std::string > ());
  }
#line 5338 "GrammarParser.cpp"
    break;

  case 374:
#line 2575 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5346 "GrammarParser.cpp"
    break;

  case 375:
#line 2581 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5354 "GrammarParser.cpp"
    break;

  case 376:
#line 2588 "../../obj/src/GrammarParser.yy"
    {
	auto identifier = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
	yylhs.value.as < VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 5363 "GrammarParser.cpp"
    break;

  case 377:
#line 2596 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < DistinctObjectLiteral::Ptr > () = libtptp::make< DistinctObjectLiteral >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5371 "GrammarParser.cpp"
    break;

  case 378:
#line 2603 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5379 "GrammarParser.cpp"
    break;

  case 379:
#line 2610 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as < std::string > ());
  }
#line 5387 "GrammarParser.cpp"
    break;

  case 380:
#line 2617 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5395 "GrammarParser.cpp"
    break;

  case 381:
#line 2624 "../../obj/src/GrammarParser.yy"
    {
	yylhs.value.as < Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[1].value.as < Token::Ptr > (), yystack_[0].value.as < std::string > ());
  }
#line 5403 "GrammarParser.cpp"
    break;


#line 5407 "GrammarParser.cpp"

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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

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
       2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"tpi\"", "\"thf\"",
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

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   344,   344,   351,   357,   367,   371,   378,   382,   386,
     390,   394,   398,   405,   410,   421,   426,   437,   442,   453,
     458,   469,   474,   485,   490,   501,   506,   514,   521,   525,
     529,   533,   540,   544,   548,   552,   559,   563,   567,   574,
     581,   585,   589,   596,   601,   609,   614,   622,   627,   635,
     639,   643,   650,   654,   661,   665,   669,   673,   683,   691,
     697,   706,   716,   720,   727,   734,   741,   745,   749,   753,
     760,   764,   771,   775,   779,   783,   790,   797,   804,   811,
     815,   819,   826,   833,   840,   844,   851,   857,   866,   870,
     877,   884,   891,   900,   904,   908,   918,   922,   929,   935,
     944,   949,   954,   959,   967,   974,   978,   988,   992,   996,
    1003,  1010,  1017,  1021,  1025,  1033,  1037,  1045,  1049,  1057,
    1061,  1068,  1075,  1079,  1090,  1094,  1098,  1102,  1109,  1113,
    1117,  1121,  1128,  1132,  1139,  1146,  1150,  1157,  1162,  1170,
    1175,  1183,  1187,  1191,  1198,  1202,  1209,  1213,  1217,  1221,
    1231,  1238,  1246,  1253,  1262,  1266,  1273,  1284,  1288,  1295,
    1302,  1309,  1313,  1317,  1324,  1328,  1335,  1342,  1346,  1350,
    1354,  1361,  1368,  1372,  1379,  1386,  1393,  1397,  1404,  1410,
    1419,  1423,  1430,  1437,  1441,  1448,  1454,  1463,  1467,  1471,
    1478,  1482,  1486,  1490,  1494,  1504,  1508,  1515,  1521,  1530,
    1534,  1544,  1548,  1552,  1556,  1566,  1573,  1577,  1587,  1591,
    1601,  1605,  1609,  1614,  1618,  1625,  1631,  1640,  1647,  1651,
    1658,  1665,  1671,  1680,  1687,  1691,  1702,  1706,  1713,  1717,
    1724,  1735,  1739,  1746,  1750,  1754,  1761,  1765,  1772,  1779,
    1783,  1790,  1795,  1803,  1808,  1816,  1820,  1827,  1834,  1838,
    1845,  1849,  1853,  1863,  1871,  1878,  1887,  1891,  1895,  1902,
    1909,  1913,  1920,  1927,  1934,  1941,  1945,  1952,  1956,  1963,
    1970,  1974,  1981,  1985,  1992,  1998,  2007,  2011,  2018,  2022,
    2026,  2033,  2037,  2046,  2050,  2057,  2063,  2072,  2076,  2086,
    2090,  2098,  2102,  2107,  2114,  2118,  2122,  2129,  2133,  2140,
    2144,  2148,  2155,  2159,  2166,  2170,  2174,  2178,  2182,  2189,
    2193,  2202,  2206,  2210,  2214,  2218,  2222,  2229,  2233,  2240,
    2247,  2254,  2261,  2268,  2272,  2279,  2283,  2290,  2297,  2304,
    2311,  2318,  2325,  2332,  2339,  2346,  2353,  2357,  2364,  2372,
    2381,  2385,  2392,  2399,  2403,  2407,  2414,  2418,  2422,  2426,
    2430,  2434,  2441,  2448,  2454,  2463,  2467,  2471,  2475,  2479,
    2486,  2491,  2500,  2505,  2512,  2520,  2524,  2531,  2538,  2545,
    2549,  2553,  2560,  2567,  2574,  2580,  2587,  2595,  2602,  2609,
    2616,  2623
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


#line 47 "../../obj/src/GrammarParser.yy"
} // libtptp
#line 6760 "GrammarParser.cpp"

#line 2629 "../../obj/src/GrammarParser.yy"


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

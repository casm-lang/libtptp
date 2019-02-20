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
      case 69: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 136: // TffPlainAtomic
      case 140: // TffSystemAtomic
      case 188: // FofPlainTerm
      case 189: // FofDefinedTerm
      case 190: // FofDefinedAtomicTerm
      case 191: // FofDefinedPlainTerm
      case 192: // FofSystemTerm
      case 195: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 158: // TffAtomicType
        value.YY_MOVE_OR_COPY< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 208: // NonassocConnective
      case 209: // AssocConnective
        value.YY_MOVE_OR_COPY< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 119: // TffBinaryFormula
      case 120: // TffBinaryNonassoc
      case 121: // TffBinaryAssoc
      case 122: // TffOrFormula
      case 123: // TffAndFormula
      case 171: // FofBinaryFormula
      case 172: // FofBinaryNonassoc
      case 173: // FofBinaryAssoc
      case 174: // FofOrFormula
      case 175: // FofAndFormula
        value.YY_MOVE_OR_COPY< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 160: // TffMappingType
      case 161: // TffXprodType
        value.YY_MOVE_OR_COPY< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 141: // TfxConditional
        value.YY_MOVE_OR_COPY< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 225: // DefinedTerm
        value.YY_MOVE_OR_COPY< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 61: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 146: // TfxLetDefn
        value.YY_MOVE_OR_COPY< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 142: // TfxLet
        value.YY_MOVE_OR_COPY< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 70: // TpiFormula
      case 169: // FofFormula
        value.YY_MOVE_OR_COPY< FirstOrderFormula::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // AnnotatedFormula
      case 66: // FofAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // FormulaRole
        value.YY_MOVE_OR_COPY< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 230: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // TypeConstant
      case 212: // TypeFunctor
      case 213: // DefinedType
      case 214: // Atom
      case 215: // UntypedAtom
      case 219: // Constant
      case 220: // Functor
      case 221: // SystemConstant
      case 222: // SystemFunctor
      case 223: // DefinedConstant
      case 224: // DefinedFunctor
      case 227: // Name
      case 241: // FileName
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 216: // DefinedInfixPred
      case 217: // InfixEquality
      case 218: // InfixInequality
        value.YY_MOVE_OR_COPY< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 134: // TffInfixUnary
      case 139: // TffDefinedInfix
      case 177: // FofInfixUnary
      case 186: // FofDefinedInfixFormula
        value.YY_MOVE_OR_COPY< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // TffFormula
      case 118: // TffLogicFormula
      case 124: // TffUnitFormula
      case 125: // TffPreunitFormula
      case 126: // TffUnitaryFormula
      case 132: // TffUnaryFormula
      case 145: // TfxLetDefns
      case 147: // TfxLetLhs
      case 149: // TffTerm
      case 150: // TffUnitaryTerm
      case 170: // FofLogicFormula
      case 176: // FofUnaryFormula
      case 178: // FofUnitFormula
      case 179: // FofUnitaryFormula
      case 182: // FofAtomicFormula
      case 184: // FofDefinedAtomicFormula
      case 199: // CnfFormula
      case 200: // Disjunction
      case 201: // Literal
        value.YY_MOVE_OR_COPY< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 151: // TfxTuple
      case 197: // FofFormulaTuple
        value.YY_MOVE_OR_COPY< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 148: // TfxLetDefnList
      case 152: // TffArguments
      case 159: // TffTypeArguments
      case 193: // FofArguments
      case 198: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< Logics::Ptr > (YY_MOVE (that.value));
        break;

      case 129: // TffVariableList
      case 181: // FofVariableList
      case 226: // NameList
      case 232: // GeneralTerms
        value.YY_MOVE_OR_COPY< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 128: // TffQuantifiedFormula
      case 180: // FofQuantifiedFormula
        value.YY_MOVE_OR_COPY< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 207: // FofQuantifier
        value.YY_MOVE_OR_COPY< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 155: // Tf1QuantifiedType
        value.YY_MOVE_OR_COPY< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 244: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 243: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 165: // TfxSequent
      case 196: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // AtomicWord
      case 238: // AtomicDefinedWord
      case 239: // AtomicSystemWord
      case 246: // DistinctObjectLiteral
      case 247: // LowerWordLiteral
      case 248: // SingleQuotedLiteral
      case 249: // DollarWordLiteral
      case 250: // DollarDollarWordLiteral
        value.YY_MOVE_OR_COPY< StringLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 164: // TffSubtype
        value.YY_MOVE_OR_COPY< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 135: // TffAtomicFormula
      case 137: // TffDefinedAtomic
      case 138: // TffDefinedPlain
      case 183: // FofPlainAtomicFormula
      case 185: // FofDefinedPlainFormula
      case 187: // FofSystemAtomicFormula
      case 194: // FofTerm
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
      case 12: // "!>"
      case 13: // "@"
      case 14: // "&"
      case 15: // "$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "-"
      case 21: // "="
      case 22: // "!="
      case 23: // "("
      case 24: // ")"
      case 25: // "["
      case 26: // "]"
      case 27: // "{"
      case 28: // "}"
      case 29: // "|"
      case 30: // "*"
      case 31: // ">"
      case 32: // "<"
      case 33: // "!"
      case 34: // "~"
      case 35: // "?"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@"
      case 40: // "<=>"
      case 41: // "=>"
      case 42: // "<="
      case 43: // "<~>"
      case 44: // "~|"
      case 45: // "~&"
      case 46: // ":="
      case 47: // "-->"
      case 48: // "<<"
      case 49: // "include"
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 162: // TfxTupleType
        value.YY_MOVE_OR_COPY< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 143: // TfxLetTypes
      case 154: // TffTopLevelType
      case 156: // TffMonotype
      case 157: // TffUnitaryType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 153: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 144: // TffAtomTypingList
      case 163: // TffTypeList
        value.YY_MOVE_OR_COPY< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 210: // UnaryConnective
        value.YY_MOVE_OR_COPY< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 133: // TffPrefixUnary
        value.YY_MOVE_OR_COPY< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 240: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 127: // TfxUnitaryFormula
      case 130: // TffVariable
      case 131: // TffTypedVariable
      case 245: // Variable
        value.YY_MOVE_OR_COPY< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 50: // "integer"
      case 51: // "real"
      case 52: // "rational"
      case 53: // "double_quoted"
      case 54: // "lower_word"
      case 55: // "upper_word"
      case 56: // "identifier"
      case 57: // "single_quoted"
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
      case 69: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 136: // TffPlainAtomic
      case 140: // TffSystemAtomic
      case 188: // FofPlainTerm
      case 189: // FofDefinedTerm
      case 190: // FofDefinedAtomicTerm
      case 191: // FofDefinedPlainTerm
      case 192: // FofSystemTerm
      case 195: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 158: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 208: // NonassocConnective
      case 209: // AssocConnective
        value.move< BinaryConnective_t > (YY_MOVE (that.value));
        break;

      case 119: // TffBinaryFormula
      case 120: // TffBinaryNonassoc
      case 121: // TffBinaryAssoc
      case 122: // TffOrFormula
      case 123: // TffAndFormula
      case 171: // FofBinaryFormula
      case 172: // FofBinaryNonassoc
      case 173: // FofBinaryAssoc
      case 174: // FofOrFormula
      case 175: // FofAndFormula
        value.move< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 160: // TffMappingType
      case 161: // TffXprodType
        value.move< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 141: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 225: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 61: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 146: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 142: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 70: // TpiFormula
      case 169: // FofFormula
        value.move< FirstOrderFormula::Ptr > (YY_MOVE (that.value));
        break;

      case 62: // AnnotatedFormula
      case 66: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // FormulaRole
        value.move< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 230: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // TypeConstant
      case 212: // TypeFunctor
      case 213: // DefinedType
      case 214: // Atom
      case 215: // UntypedAtom
      case 219: // Constant
      case 220: // Functor
      case 221: // SystemConstant
      case 222: // SystemFunctor
      case 223: // DefinedConstant
      case 224: // DefinedFunctor
      case 227: // Name
      case 241: // FileName
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 216: // DefinedInfixPred
      case 217: // InfixEquality
      case 218: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 134: // TffInfixUnary
      case 139: // TffDefinedInfix
      case 177: // FofInfixUnary
      case 186: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 117: // TffFormula
      case 118: // TffLogicFormula
      case 124: // TffUnitFormula
      case 125: // TffPreunitFormula
      case 126: // TffUnitaryFormula
      case 132: // TffUnaryFormula
      case 145: // TfxLetDefns
      case 147: // TfxLetLhs
      case 149: // TffTerm
      case 150: // TffUnitaryTerm
      case 170: // FofLogicFormula
      case 176: // FofUnaryFormula
      case 178: // FofUnitFormula
      case 179: // FofUnitaryFormula
      case 182: // FofAtomicFormula
      case 184: // FofDefinedAtomicFormula
      case 199: // CnfFormula
      case 200: // Disjunction
      case 201: // Literal
        value.move< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 151: // TfxTuple
      case 197: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 148: // TfxLetDefnList
      case 152: // TffArguments
      case 159: // TffTypeArguments
      case 193: // FofArguments
      case 198: // FofFormulaTupleList
        value.move< Logics::Ptr > (YY_MOVE (that.value));
        break;

      case 129: // TffVariableList
      case 181: // FofVariableList
      case 226: // NameList
      case 232: // GeneralTerms
        value.move< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 128: // TffQuantifiedFormula
      case 180: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 207: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 155: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 244: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 243: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 165: // TfxSequent
      case 196: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // AtomicWord
      case 238: // AtomicDefinedWord
      case 239: // AtomicSystemWord
      case 246: // DistinctObjectLiteral
      case 247: // LowerWordLiteral
      case 248: // SingleQuotedLiteral
      case 249: // DollarWordLiteral
      case 250: // DollarDollarWordLiteral
        value.move< StringLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 164: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 135: // TffAtomicFormula
      case 137: // TffDefinedAtomic
      case 138: // TffDefinedPlain
      case 183: // FofPlainAtomicFormula
      case 185: // FofDefinedPlainFormula
      case 187: // FofSystemAtomicFormula
      case 194: // FofTerm
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
      case 12: // "!>"
      case 13: // "@"
      case 14: // "&"
      case 15: // "$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "-"
      case 21: // "="
      case 22: // "!="
      case 23: // "("
      case 24: // ")"
      case 25: // "["
      case 26: // "]"
      case 27: // "{"
      case 28: // "}"
      case 29: // "|"
      case 30: // "*"
      case 31: // ">"
      case 32: // "<"
      case 33: // "!"
      case 34: // "~"
      case 35: // "?"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@"
      case 40: // "<=>"
      case 41: // "=>"
      case 42: // "<="
      case 43: // "<~>"
      case 44: // "~|"
      case 45: // "~&"
      case 46: // ":="
      case 47: // "-->"
      case 48: // "<<"
      case 49: // "include"
        value.move< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 162: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 143: // TfxLetTypes
      case 154: // TffTopLevelType
      case 156: // TffMonotype
      case 157: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 153: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 144: // TffAtomTypingList
      case 163: // TffTypeList
        value.move< Types::Ptr > (YY_MOVE (that.value));
        break;

      case 210: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 133: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 240: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 127: // TfxUnitaryFormula
      case 130: // TffVariable
      case 131: // TffTypedVariable
      case 245: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 50: // "integer"
      case 51: // "real"
      case 52: // "rational"
      case 53: // "double_quoted"
      case 54: // "lower_word"
      case 55: // "upper_word"
      case 56: // "identifier"
      case 57: // "single_quoted"
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
      case 69: // Annotations
        value.move< Annotation::Ptr > (that.value);
        break;

      case 136: // TffPlainAtomic
      case 140: // TffSystemAtomic
      case 188: // FofPlainTerm
      case 189: // FofDefinedTerm
      case 190: // FofDefinedAtomicTerm
      case 191: // FofDefinedPlainTerm
      case 192: // FofSystemTerm
      case 195: // FofFunctionTerm
        value.move< Atom::Ptr > (that.value);
        break;

      case 158: // TffAtomicType
        value.move< AtomType::Ptr > (that.value);
        break;

      case 208: // NonassocConnective
      case 209: // AssocConnective
        value.move< BinaryConnective_t > (that.value);
        break;

      case 119: // TffBinaryFormula
      case 120: // TffBinaryNonassoc
      case 121: // TffBinaryAssoc
      case 122: // TffOrFormula
      case 123: // TffAndFormula
      case 171: // FofBinaryFormula
      case 172: // FofBinaryNonassoc
      case 173: // FofBinaryAssoc
      case 174: // FofOrFormula
      case 175: // FofAndFormula
        value.move< BinaryLogic::Ptr > (that.value);
        break;

      case 160: // TffMappingType
      case 161: // TffXprodType
        value.move< BinaryType::Ptr > (that.value);
        break;

      case 141: // TfxConditional
        value.move< ConditionalTerm::Ptr > (that.value);
        break;

      case 225: // DefinedTerm
        value.move< DefinedAtom::Ptr > (that.value);
        break;

      case 61: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 146: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (that.value);
        break;

      case 142: // TfxLet
        value.move< DefinitionTerm::Ptr > (that.value);
        break;

      case 60: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 70: // TpiFormula
      case 169: // FofFormula
        value.move< FirstOrderFormula::Ptr > (that.value);
        break;

      case 62: // AnnotatedFormula
      case 66: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
        break;

      case 228: // FormulaRole
        value.move< FormulaRole::Ptr > (that.value);
        break;

      case 230: // GeneralData
        value.move< GeneralData::Ptr > (that.value);
        break;

      case 231: // GeneralFunction
        value.move< GeneralFunction::Ptr > (that.value);
        break;

      case 234: // GeneralList
        value.move< GeneralList::Ptr > (that.value);
        break;

      case 229: // GeneralTerm
        value.move< GeneralTerm::Ptr > (that.value);
        break;

      case 211: // TypeConstant
      case 212: // TypeFunctor
      case 213: // DefinedType
      case 214: // Atom
      case 215: // UntypedAtom
      case 219: // Constant
      case 220: // Functor
      case 221: // SystemConstant
      case 222: // SystemFunctor
      case 223: // DefinedConstant
      case 224: // DefinedFunctor
      case 227: // Name
      case 241: // FileName
        value.move< Identifier::Ptr > (that.value);
        break;

      case 235: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (that.value);
        break;

      case 216: // DefinedInfixPred
      case 217: // InfixEquality
      case 218: // InfixInequality
        value.move< InfixConnective_t > (that.value);
        break;

      case 134: // TffInfixUnary
      case 139: // TffDefinedInfix
      case 177: // FofInfixUnary
      case 186: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (that.value);
        break;

      case 242: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (that.value);
        break;

      case 236: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 117: // TffFormula
      case 118: // TffLogicFormula
      case 124: // TffUnitFormula
      case 125: // TffPreunitFormula
      case 126: // TffUnitaryFormula
      case 132: // TffUnaryFormula
      case 145: // TfxLetDefns
      case 147: // TfxLetLhs
      case 149: // TffTerm
      case 150: // TffUnitaryTerm
      case 170: // FofLogicFormula
      case 176: // FofUnaryFormula
      case 178: // FofUnitFormula
      case 179: // FofUnitaryFormula
      case 182: // FofAtomicFormula
      case 184: // FofDefinedAtomicFormula
      case 199: // CnfFormula
      case 200: // Disjunction
      case 201: // Literal
        value.move< Logic::Ptr > (that.value);
        break;

      case 151: // TfxTuple
      case 197: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (that.value);
        break;

      case 148: // TfxLetDefnList
      case 152: // TffArguments
      case 159: // TffTypeArguments
      case 193: // FofArguments
      case 198: // FofFormulaTupleList
        value.move< Logics::Ptr > (that.value);
        break;

      case 129: // TffVariableList
      case 181: // FofVariableList
      case 226: // NameList
      case 232: // GeneralTerms
        value.move< Nodes::Ptr > (that.value);
        break;

      case 128: // TffQuantifiedFormula
      case 180: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (that.value);
        break;

      case 207: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (that.value);
        break;

      case 155: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (that.value);
        break;

      case 244: // RationalLiteral
        value.move< RationalLiteral::Ptr > (that.value);
        break;

      case 243: // RealLiteral
        value.move< RealLiteral::Ptr > (that.value);
        break;

      case 165: // TfxSequent
      case 196: // FofSequent
        value.move< SequentLogic::Ptr > (that.value);
        break;

      case 59: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 237: // AtomicWord
      case 238: // AtomicDefinedWord
      case 239: // AtomicSystemWord
      case 246: // DistinctObjectLiteral
      case 247: // LowerWordLiteral
      case 248: // SingleQuotedLiteral
      case 249: // DollarWordLiteral
      case 250: // DollarDollarWordLiteral
        value.move< StringLiteral::Ptr > (that.value);
        break;

      case 164: // TffSubtype
        value.move< SubType::Ptr > (that.value);
        break;

      case 135: // TffAtomicFormula
      case 137: // TffDefinedAtomic
      case 138: // TffDefinedPlain
      case 183: // FofPlainAtomicFormula
      case 185: // FofDefinedPlainFormula
      case 187: // FofSystemAtomicFormula
      case 194: // FofTerm
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
      case 12: // "!>"
      case 13: // "@"
      case 14: // "&"
      case 15: // "$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "-"
      case 21: // "="
      case 22: // "!="
      case 23: // "("
      case 24: // ")"
      case 25: // "["
      case 26: // "]"
      case 27: // "{"
      case 28: // "}"
      case 29: // "|"
      case 30: // "*"
      case 31: // ">"
      case 32: // "<"
      case 33: // "!"
      case 34: // "~"
      case 35: // "?"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@"
      case 40: // "<=>"
      case 41: // "=>"
      case 42: // "<="
      case 43: // "<~>"
      case 44: // "~|"
      case 45: // "~&"
      case 46: // ":="
      case 47: // "-->"
      case 48: // "<<"
      case 49: // "include"
        value.move< Token::Ptr > (that.value);
        break;

      case 162: // TfxTupleType
        value.move< TupleType::Ptr > (that.value);
        break;

      case 143: // TfxLetTypes
      case 154: // TffTopLevelType
      case 156: // TffMonotype
      case 157: // TffUnitaryType
        value.move< Type::Ptr > (that.value);
        break;

      case 153: // TffAtomTyping
        value.move< TypedAtom::Ptr > (that.value);
        break;

      case 144: // TffAtomTypingList
      case 163: // TffTypeList
        value.move< Types::Ptr > (that.value);
        break;

      case 210: // UnaryConnective
        value.move< UnaryConnective_t > (that.value);
        break;

      case 133: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (that.value);
        break;

      case 240: // Number
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 127: // TfxUnitaryFormula
      case 130: // TffVariable
      case 131: // TffTypedVariable
      case 245: // Variable
        value.move< VariableTerm::Ptr > (that.value);
        break;

      case 50: // "integer"
      case 51: // "real"
      case 52: // "rational"
      case 53: // "double_quoted"
      case 54: // "lower_word"
      case 55: // "upper_word"
      case 56: // "identifier"
      case 57: // "single_quoted"
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
      case 69: // Annotations
        yylhs.value.emplace< Annotation::Ptr > ();
        break;

      case 136: // TffPlainAtomic
      case 140: // TffSystemAtomic
      case 188: // FofPlainTerm
      case 189: // FofDefinedTerm
      case 190: // FofDefinedAtomicTerm
      case 191: // FofDefinedPlainTerm
      case 192: // FofSystemTerm
      case 195: // FofFunctionTerm
        yylhs.value.emplace< Atom::Ptr > ();
        break;

      case 158: // TffAtomicType
        yylhs.value.emplace< AtomType::Ptr > ();
        break;

      case 208: // NonassocConnective
      case 209: // AssocConnective
        yylhs.value.emplace< BinaryConnective_t > ();
        break;

      case 119: // TffBinaryFormula
      case 120: // TffBinaryNonassoc
      case 121: // TffBinaryAssoc
      case 122: // TffOrFormula
      case 123: // TffAndFormula
      case 171: // FofBinaryFormula
      case 172: // FofBinaryNonassoc
      case 173: // FofBinaryAssoc
      case 174: // FofOrFormula
      case 175: // FofAndFormula
        yylhs.value.emplace< BinaryLogic::Ptr > ();
        break;

      case 160: // TffMappingType
      case 161: // TffXprodType
        yylhs.value.emplace< BinaryType::Ptr > ();
        break;

      case 141: // TfxConditional
        yylhs.value.emplace< ConditionalTerm::Ptr > ();
        break;

      case 225: // DefinedTerm
        yylhs.value.emplace< DefinedAtom::Ptr > ();
        break;

      case 61: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 146: // TfxLetDefn
        yylhs.value.emplace< DefinitionAtom::Ptr > ();
        break;

      case 142: // TfxLet
        yylhs.value.emplace< DefinitionTerm::Ptr > ();
        break;

      case 60: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 70: // TpiFormula
      case 169: // FofFormula
        yylhs.value.emplace< FirstOrderFormula::Ptr > ();
        break;

      case 62: // AnnotatedFormula
      case 66: // FofAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
        break;

      case 228: // FormulaRole
        yylhs.value.emplace< FormulaRole::Ptr > ();
        break;

      case 230: // GeneralData
        yylhs.value.emplace< GeneralData::Ptr > ();
        break;

      case 231: // GeneralFunction
        yylhs.value.emplace< GeneralFunction::Ptr > ();
        break;

      case 234: // GeneralList
        yylhs.value.emplace< GeneralList::Ptr > ();
        break;

      case 229: // GeneralTerm
        yylhs.value.emplace< GeneralTerm::Ptr > ();
        break;

      case 211: // TypeConstant
      case 212: // TypeFunctor
      case 213: // DefinedType
      case 214: // Atom
      case 215: // UntypedAtom
      case 219: // Constant
      case 220: // Functor
      case 221: // SystemConstant
      case 222: // SystemFunctor
      case 223: // DefinedConstant
      case 224: // DefinedFunctor
      case 227: // Name
      case 241: // FileName
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 235: // IncludeDefinition
        yylhs.value.emplace< IncludeDefinition::Ptr > ();
        break;

      case 216: // DefinedInfixPred
      case 217: // InfixEquality
      case 218: // InfixInequality
        yylhs.value.emplace< InfixConnective_t > ();
        break;

      case 134: // TffInfixUnary
      case 139: // TffDefinedInfix
      case 177: // FofInfixUnary
      case 186: // FofDefinedInfixFormula
        yylhs.value.emplace< InfixLogic::Ptr > ();
        break;

      case 242: // IntegerLiteral
        yylhs.value.emplace< IntegerLiteral::Ptr > ();
        break;

      case 236: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 117: // TffFormula
      case 118: // TffLogicFormula
      case 124: // TffUnitFormula
      case 125: // TffPreunitFormula
      case 126: // TffUnitaryFormula
      case 132: // TffUnaryFormula
      case 145: // TfxLetDefns
      case 147: // TfxLetLhs
      case 149: // TffTerm
      case 150: // TffUnitaryTerm
      case 170: // FofLogicFormula
      case 176: // FofUnaryFormula
      case 178: // FofUnitFormula
      case 179: // FofUnitaryFormula
      case 182: // FofAtomicFormula
      case 184: // FofDefinedAtomicFormula
      case 199: // CnfFormula
      case 200: // Disjunction
      case 201: // Literal
        yylhs.value.emplace< Logic::Ptr > ();
        break;

      case 151: // TfxTuple
      case 197: // FofFormulaTuple
        yylhs.value.emplace< LogicTuple::Ptr > ();
        break;

      case 148: // TfxLetDefnList
      case 152: // TffArguments
      case 159: // TffTypeArguments
      case 193: // FofArguments
      case 198: // FofFormulaTupleList
        yylhs.value.emplace< Logics::Ptr > ();
        break;

      case 129: // TffVariableList
      case 181: // FofVariableList
      case 226: // NameList
      case 232: // GeneralTerms
        yylhs.value.emplace< Nodes::Ptr > ();
        break;

      case 128: // TffQuantifiedFormula
      case 180: // FofQuantifiedFormula
        yylhs.value.emplace< QuantifiedLogic::Ptr > ();
        break;

      case 207: // FofQuantifier
        yylhs.value.emplace< QuantifiedQuantifier_t > ();
        break;

      case 155: // Tf1QuantifiedType
        yylhs.value.emplace< QuantifiedType::Ptr > ();
        break;

      case 244: // RationalLiteral
        yylhs.value.emplace< RationalLiteral::Ptr > ();
        break;

      case 243: // RealLiteral
        yylhs.value.emplace< RealLiteral::Ptr > ();
        break;

      case 165: // TfxSequent
      case 196: // FofSequent
        yylhs.value.emplace< SequentLogic::Ptr > ();
        break;

      case 59: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 237: // AtomicWord
      case 238: // AtomicDefinedWord
      case 239: // AtomicSystemWord
      case 246: // DistinctObjectLiteral
      case 247: // LowerWordLiteral
      case 248: // SingleQuotedLiteral
      case 249: // DollarWordLiteral
      case 250: // DollarDollarWordLiteral
        yylhs.value.emplace< StringLiteral::Ptr > ();
        break;

      case 164: // TffSubtype
        yylhs.value.emplace< SubType::Ptr > ();
        break;

      case 135: // TffAtomicFormula
      case 137: // TffDefinedAtomic
      case 138: // TffDefinedPlain
      case 183: // FofPlainAtomicFormula
      case 185: // FofDefinedPlainFormula
      case 187: // FofSystemAtomicFormula
      case 194: // FofTerm
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
      case 12: // "!>"
      case 13: // "@"
      case 14: // "&"
      case 15: // "$"
      case 16: // ":"
      case 17: // ","
      case 18: // "."
      case 19: // "+"
      case 20: // "-"
      case 21: // "="
      case 22: // "!="
      case 23: // "("
      case 24: // ")"
      case 25: // "["
      case 26: // "]"
      case 27: // "{"
      case 28: // "}"
      case 29: // "|"
      case 30: // "*"
      case 31: // ">"
      case 32: // "<"
      case 33: // "!"
      case 34: // "~"
      case 35: // "?"
      case 36: // "^"
      case 37: // "!!"
      case 38: // "??"
      case 39: // "@@"
      case 40: // "<=>"
      case 41: // "=>"
      case 42: // "<="
      case 43: // "<~>"
      case 44: // "~|"
      case 45: // "~&"
      case 46: // ":="
      case 47: // "-->"
      case 48: // "<<"
      case 49: // "include"
        yylhs.value.emplace< Token::Ptr > ();
        break;

      case 162: // TfxTupleType
        yylhs.value.emplace< TupleType::Ptr > ();
        break;

      case 143: // TfxLetTypes
      case 154: // TffTopLevelType
      case 156: // TffMonotype
      case 157: // TffUnitaryType
        yylhs.value.emplace< Type::Ptr > ();
        break;

      case 153: // TffAtomTyping
        yylhs.value.emplace< TypedAtom::Ptr > ();
        break;

      case 144: // TffAtomTypingList
      case 163: // TffTypeList
        yylhs.value.emplace< Types::Ptr > ();
        break;

      case 210: // UnaryConnective
        yylhs.value.emplace< UnaryConnective_t > ();
        break;

      case 133: // TffPrefixUnary
        yylhs.value.emplace< UnaryLogic::Ptr > ();
        break;

      case 240: // Number
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 127: // TfxUnitaryFormula
      case 130: // TffVariable
      case 131: // TffTypedVariable
      case 245: // Variable
        yylhs.value.emplace< VariableTerm::Ptr > ();
        break;

      case 50: // "integer"
      case 51: // "real"
      case 52: // "rational"
      case 53: // "double_quoted"
      case 54: // "lower_word"
      case 55: // "upper_word"
      case 56: // "identifier"
      case 57: // "single_quoted"
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
#line 321 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      m_specification.setDefinitions( yystack_[0].value.as< Definitions::Ptr > () );
  }
#line 1891 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 3:
#line 328 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = yystack_[1].value.as< Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as< Definition::Ptr > ());
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 1901 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 4:
#line 334 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as< Definition::Ptr > () );
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 1911 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 5:
#line 344 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 1919 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 6:
#line 348 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< IncludeDefinition::Ptr > ();
  }
#line 1927 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 7:
#line 355 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1935 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 8:
#line 359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1943 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 9:
#line 363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1951 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 10:
#line 367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1959 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 11:
#line 371 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1967 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 12:
#line 375 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1975 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 13:
#line 391 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1982 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 14:
#line 394 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1989 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 15:
#line 399 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1996 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 16:
#line 402 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2003 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 17:
#line 407 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2010 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 18:
#line 410 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2017 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 19:
#line 415 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< FormulaRole::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 2028 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 20:
#line 422 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< FormulaRole::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
  }
#line 2042 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 21:
#line 434 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2049 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 22:
#line 437 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2056 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 23:
#line 442 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2063 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 24:
#line 445 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2070 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 25:
#line 488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as< GeneralTerm::Ptr > ());
    //source
  }
#line 2079 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 26:
#line 493 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source, optionalInfo
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as< GeneralTerm::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralList::Ptr > ());
  }
#line 2088 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 27:
#line 523 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = yystack_[0].value.as< FirstOrderFormula::Ptr > ();
  }
#line 2096 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 28:
#line 530 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2103 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 29:
#line 533 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2110 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 30:
#line 536 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2117 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 31:
#line 539 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2124 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 32:
#line 545 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2131 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 33:
#line 548 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2138 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 34:
#line 551 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2145 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 35:
#line 554 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2152 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 36:
#line 560 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2159 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 37:
#line 563 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2166 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 38:
#line 566 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2173 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 39:
#line 572 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2180 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 40:
#line 578 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2187 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 41:
#line 581 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2194 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 42:
#line 584 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2201 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 43:
#line 590 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2208 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 44:
#line 593 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2215 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 45:
#line 599 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2222 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 46:
#line 602 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2229 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 47:
#line 608 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2236 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 48:
#line 611 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2243 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 49:
#line 617 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2250 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 50:
#line 620 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2257 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 51:
#line 623 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2264 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 52:
#line 629 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2271 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 53:
#line 632 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2278 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 54:
#line 638 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2285 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 55:
#line 641 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2292 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 56:
#line 644 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2299 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 57:
#line 647 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2306 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 58:
#line 653 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2313 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 59:
#line 659 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2320 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 60:
#line 665 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2327 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 61:
#line 668 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2334 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 62:
#line 674 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2341 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 63:
#line 680 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2348 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 64:
#line 683 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2355 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 65:
#line 689 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2362 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 66:
#line 695 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2369 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 67:
#line 701 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2376 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 68:
#line 704 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2383 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 69:
#line 707 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2390 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 70:
#line 710 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2397 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 71:
#line 716 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2404 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 72:
#line 719 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2411 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 73:
#line 725 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2418 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 74:
#line 728 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2425 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 75:
#line 731 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2432 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 76:
#line 734 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2439 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 77:
#line 737 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2446 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 78:
#line 743 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2453 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 79:
#line 749 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2460 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 80:
#line 755 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2467 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 81:
#line 758 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2474 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 82:
#line 761 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2481 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 83:
#line 767 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2488 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 84:
#line 773 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2495 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 85:
#line 779 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2502 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 86:
#line 782 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2509 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 87:
#line 788 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2516 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 88:
#line 791 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2523 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 89:
#line 797 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2530 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 90:
#line 800 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2537 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 91:
#line 806 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2544 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 92:
#line 812 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2551 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 93:
#line 815 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2558 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 94:
#line 821 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2565 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 95:
#line 824 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2572 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 96:
#line 827 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2579 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 97:
#line 833 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2586 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 98:
#line 836 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2593 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 99:
#line 842 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2600 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 100:
#line 845 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2607 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 101:
#line 851 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2614 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 102:
#line 854 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2621 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 103:
#line 857 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2628 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 104:
#line 860 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2635 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 105:
#line 866 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2642 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 106:
#line 872 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2649 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 107:
#line 875 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2656 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 108:
#line 881 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2663 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 109:
#line 884 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2670 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 110:
#line 887 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2677 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 111:
#line 893 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2684 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 112:
#line 899 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2691 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 113:
#line 905 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2698 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 114:
#line 908 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2705 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 115:
#line 911 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2712 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 116:
#line 917 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2719 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 117:
#line 920 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2726 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 118:
#line 926 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2733 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 119:
#line 929 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2740 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 120:
#line 935 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2747 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 121:
#line 938 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2754 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 122:
#line 944 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2761 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 123:
#line 950 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2768 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 124:
#line 953 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2775 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 125:
#line 960 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2783 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 126:
#line 964 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 2791 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 127:
#line 968 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SubType::Ptr > ();
  }
#line 2799 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 128:
#line 972 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< SequentLogic::Ptr > ();
  }
#line 2807 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 129:
#line 979 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2815 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 130:
#line 983 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2823 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 131:
#line 987 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2831 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 132:
#line 991 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2839 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 133:
#line 998 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2847 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 134:
#line 1002 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2855 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 135:
#line 1009 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2863 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 136:
#line 1016 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2871 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 137:
#line 1020 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 2879 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 138:
#line 1027 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2888 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 139:
#line 1032 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2897 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 140:
#line 1040 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2906 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 141:
#line 1045 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 2915 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 142:
#line 1053 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2923 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 143:
#line 1057 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2931 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 144:
#line 1061 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 2939 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 145:
#line 1068 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 2947 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 146:
#line 1072 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 2955 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 147:
#line 1079 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 2963 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 148:
#line 1083 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 2971 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 149:
#line 1087 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2979 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 150:
#line 1091 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 2990 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 151:
#line 1101 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 2998 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 152:
#line 1108 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yystack_[3].location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), list, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3007 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 153:
#line 1116 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use correct type
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3018 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 154:
#line 1123 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Nodes::Ptr > ();
	list->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3029 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 155:
#line 1133 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3037 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 156:
#line 1137 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< VariableTerm::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3045 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 157:
#line 1144 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variable = yystack_[2].value.as< VariableTerm::Ptr > ();
	variable->setColon(yystack_[1].value.as< Token::Ptr > ());
	Type::Ptr type = yystack_[0].value.as< AtomType::Ptr > (); //cast before set type is called, which would make a temporary Type::Ptr object, which cannot be passed to std::experimental::optional
	variable->setType(type);
	yylhs.value.as< VariableTerm::Ptr > () = variable;
  }
#line 3057 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 158:
#line 1155 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< UnaryLogic::Ptr > ();
  }
#line 3065 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 159:
#line 1159 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3073 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 160:
#line 1166 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryLogic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3081 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 161:
#line 1173 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3089 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 162:
#line 1180 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3097 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 163:
#line 1184 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3105 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 164:
#line 1188 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3113 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 165:
#line 1195 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3121 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 166:
#line 1199 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3129 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 167:
#line 1206 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3137 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 168:
#line 1213 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3145 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 169:
#line 1217 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 3153 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 170:
#line 1221 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< ConditionalTerm::Ptr > ();
  }
#line 3161 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 171:
#line 1225 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< DefinitionTerm::Ptr > ();
  }
#line 3169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 172:
#line 1232 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3177 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 173:
#line 1239 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3185 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 174:
#line 1243 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 3193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 175:
#line 1250 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< ConditionalTerm::Ptr > () = libtptp::make< ConditionalTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Logic::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3201 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 176:
#line 1257 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionTerm::Ptr > () = libtptp::make< DefinitionTerm >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Type::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Logic::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logic::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3209 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 177:
#line 1264 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< TypedAtom::Ptr > ();
  }
#line 3217 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 178:
#line 1268 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3225 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 179:
#line 1275 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3235 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 180:
#line 1281 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< TypedAtom::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3246 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 181:
#line 1291 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinitionAtom::Ptr > ();
  }
#line 3254 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 182:
#line 1295 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3262 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 183:
#line 1302 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinitionAtom::Ptr > () = libtptp::make< DefinitionAtom >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3270 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 184:
#line 1309 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3278 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 185:
#line 1313 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3286 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 186:
#line 1320 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3296 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 187:
#line 1326 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< DefinitionAtom::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3307 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 188:
#line 1336 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3315 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 189:
#line 1340 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3323 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 190:
#line 1344 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3331 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 191:
#line 1351 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3339 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 192:
#line 1355 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3347 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 193:
#line 1359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< LogicTuple::Ptr > ();
  }
#line 3355 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 194:
#line 1363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 3363 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 195:
#line 1367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3374 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 196:
#line 1377 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3382 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 197:
#line 1381 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3390 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 198:
#line 1388 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3400 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 199:
#line 1394 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3411 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 200:
#line 1404 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TypedAtom::Ptr > () = libtptp::make< TypedAtom >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3419 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 201:
#line 1408 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< TypedAtom::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< TypedAtom::Ptr > () = type;
  }
#line 3430 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 202:
#line 1418 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3438 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 203:
#line 1422 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< BinaryType::Ptr > ();
  }
#line 3446 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 204:
#line 1426 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< QuantifiedType::Ptr > ();
  }
#line 3454 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 205:
#line 1430 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< Type::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3465 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 206:
#line 1440 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< QuantifiedType::Ptr > () = libtptp::make< QuantifiedType >(yylhs.location, yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Type::Ptr > ());
  }
#line 3473 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 207:
#line 1447 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3481 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 208:
#line 1451 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3492 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 209:
#line 1461 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Type::Ptr > () = yystack_[0].value.as< AtomType::Ptr > ();
  }
#line 3500 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 210:
#line 1465 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto type = yystack_[1].value.as< BinaryType::Ptr > ();
	type->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	type->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Type::Ptr > () = type;
  }
#line 3511 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 211:
#line 1475 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3519 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 212:
#line 1479 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3527 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 213:
#line 1483 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto functor = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::TYPE);
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, functor);
  }
#line 3536 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 214:
#line 1488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 3544 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 215:
#line 1492 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< AtomType::Ptr > () = libtptp::make< AtomType >(yylhs.location, yystack_[0].value.as< TupleType::Ptr > ());
  }
#line 3552 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 216:
#line 1499 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
  }
#line 3561 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 217:
#line 1504 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< AtomType::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 3572 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 218:
#line 1514 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::MAPPING);
  }
#line 3580 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 219:
#line 1521 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< Type::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3588 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 220:
#line 1525 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryType::Ptr > () = libtptp::make< BinaryType >(yylhs.location, yystack_[2].value.as< BinaryType::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< AtomType::Ptr > (), BinaryType::Kind::XPROD);
  }
#line 3596 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 221:
#line 1532 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< TupleType::Ptr > () = libtptp::make< TupleType >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Types::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3604 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 222:
#line 1539 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Types >(yylhs.location);
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3614 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 223:
#line 1545 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Types::Ptr > ();
	list->add(yystack_[0].value.as< Type::Ptr > ());
	yylhs.value.as< Types::Ptr > () = list;
  }
#line 3625 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 224:
#line 1555 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SubType::Ptr > () = libtptp::make< SubType >(yylhs.location, yystack_[2].value.as< Identifier::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3633 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 225:
#line 1562 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 3641 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 226:
#line 1566 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< SequentLogic::Ptr > () = sequent;
  }
#line 3652 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 227:
#line 1577 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3659 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 228:
#line 1580 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3666 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 229:
#line 1586 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3673 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 230:
#line 1589 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3680 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 231:
#line 1595 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3687 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 232:
#line 1603 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = libtptp::make< FirstOrderFormula >(yylhs.location, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3695 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 233:
#line 1607 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< FirstOrderFormula::Ptr > () = libtptp::make< FirstOrderFormula >(yylhs.location, yystack_[0].value.as< SequentLogic::Ptr > ());
  }
#line 3703 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 234:
#line 1614 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3711 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 235:
#line 1618 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3719 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 236:
#line 1622 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3727 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 237:
#line 1629 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3735 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 238:
#line 1633 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3743 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 239:
#line 1640 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), yystack_[1].value.as< BinaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3751 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 240:
#line 1647 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3759 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 241:
#line 1651 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryLogic::Ptr > () = yystack_[0].value.as< BinaryLogic::Ptr > ();
  }
#line 3767 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 242:
#line 1658 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3776 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 243:
#line 1663 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3785 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 244:
#line 1671 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3794 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 245:
#line 1676 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
	yylhs.value.as< BinaryLogic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< BinaryLogic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3803 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 246:
#line 1684 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, yystack_[1].value.as< UnaryConnective_t > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3811 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 247:
#line 1688 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3819 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 248:
#line 1695 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 3827 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 249:
#line 1702 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3835 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 250:
#line 1706 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3843 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 251:
#line 1713 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< QuantifiedLogic::Ptr > ();
  }
#line 3851 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 252:
#line 1717 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3859 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 253:
#line 1721 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 3870 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 254:
#line 1731 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto variables = libtptp::make< ListLiteral >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Nodes::Ptr > (), yystack_[2].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedLogic::Ptr > () = libtptp::make< QuantifiedLogic >(yylhs.location, yystack_[5].value.as< QuantifiedQuantifier_t > (), variables, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Logic::Ptr > ());
  }
#line 3879 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 255:
#line 1739 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj make variableTerms list
	auto variables = libtptp::make< Nodes >(yylhs.location);
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 3890 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 256:
#line 1746 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto variables = yystack_[2].value.as< Nodes::Ptr > ();
	variables->add(yystack_[0].value.as< VariableTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = variables;
  }
#line 3901 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 257:
#line 1756 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3909 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 258:
#line 1760 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 3917 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 259:
#line 1764 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3925 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 260:
#line 1771 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3933 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 261:
#line 1778 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Term::Ptr > ();
  }
#line 3941 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 262:
#line 1782 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 3949 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 263:
#line 1789 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3957 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 264:
#line 1796 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixLogic::Ptr > () = libtptp::make< InfixLogic >(yylhs.location, yystack_[2].value.as< Term::Ptr > (), yystack_[1].value.as< InfixConnective_t > (), yystack_[0].value.as< Term::Ptr > ());
  }
#line 3965 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 265:
#line 1803 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 3973 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 266:
#line 1810 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3981 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 267:
#line 1814 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::PLAIN);
  }
#line 3989 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 268:
#line 1821 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< DefinedAtom::Ptr > ();
  }
#line 3997 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 269:
#line 1825 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4005 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 270:
#line 1832 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4013 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 271:
#line 1839 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4021 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 272:
#line 1843 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::DEFINED);
  }
#line 4029 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 273:
#line 1850 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< ConstantAtom >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4037 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 274:
#line 1854 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = libtptp::make< FunctorAtom >(yylhs.location, yystack_[3].value.as< Identifier::Ptr > (), yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > (), Atom::Kind::SYSTEM);
  }
#line 4045 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 275:
#line 1861 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto terms = libtptp::make< Logics >(yylhs.location);
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4055 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 276:
#line 1867 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto terms = yystack_[2].value.as< Logics::Ptr > ();
	terms->add(yystack_[0].value.as< Term::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = terms;
  }
#line 4066 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 277:
#line 1877 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4074 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 278:
#line 1881 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Term::Ptr > () = yystack_[0].value.as< VariableTerm::Ptr > ();
  }
#line 4082 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 279:
#line 1888 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4090 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 280:
#line 1892 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4098 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 281:
#line 1896 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Atom::Ptr > () = yystack_[0].value.as< Atom::Ptr > ();
  }
#line 4106 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 282:
#line 1903 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< SequentLogic::Ptr > () = libtptp::make< SequentLogic >(yylhs.location, yystack_[2].value.as< LogicTuple::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< LogicTuple::Ptr > ());
  }
#line 4114 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 283:
#line 1907 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto sequent = yystack_[1].value.as< SequentLogic::Ptr > ();
	sequent->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	sequent->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
  }
#line 4124 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 284:
#line 1916 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4132 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 285:
#line 1920 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< LogicTuple::Ptr > () = libtptp::make< LogicTuple >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Logics::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4140 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 286:
#line 1927 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Logics >(yylhs.location);
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4150 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 287:
#line 1933 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma token
	auto list = yystack_[2].value.as< Logics::Ptr > ();
	list->add(yystack_[0].value.as< Logic::Ptr > ());
	yylhs.value.as< Logics::Ptr > () = list;
  }
#line 4161 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 288:
#line 1943 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 289:
#line 1947 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto logic = yystack_[1].value.as< Logic::Ptr > ();
	logic->setLeftDelimiter(yystack_[2].value.as< Token::Ptr > ());
	logic->setRightDelimiter(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< Logic::Ptr > () = logic;
  }
#line 4180 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 290:
#line 1957 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4188 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 291:
#line 1961 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< BinaryLogic >(yylhs.location, yystack_[2].value.as< Logic::Ptr > (), op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4197 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 292:
#line 1969 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< Logic::Ptr > ();
  }
#line 4205 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 293:
#line 1973 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto op = std::make_pair(yystack_[1].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
	yylhs.value.as< Logic::Ptr > () = libtptp::make< UnaryLogic >(yylhs.location, op, yystack_[0].value.as< Logic::Ptr > ());
  }
#line 4214 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 294:
#line 1978 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Logic::Ptr > () = yystack_[0].value.as< InfixLogic::Ptr > ();
  }
#line 4222 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 295:
#line 1985 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4229 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 296:
#line 1988 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4236 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 297:
#line 1991 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4243 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 298:
#line 1997 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4250 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 299:
#line 2000 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4257 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 300:
#line 2006 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4264 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 301:
#line 2009 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4271 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 302:
#line 2012 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4278 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 303:
#line 2018 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4285 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 304:
#line 2021 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4292 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 305:
#line 2027 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4299 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 306:
#line 2030 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4306 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 307:
#line 2033 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4313 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 308:
#line 2036 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4320 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 309:
#line 2039 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4327 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 310:
#line 2045 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto tokens = libtptp::make< Tokens >(yylhs.location);
	tokens->add(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(tokens, QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4337 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 311:
#line 2051 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto tokens = libtptp::make< Tokens >(yylhs.location);
	tokens->add(yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< QuantifiedQuantifier_t > () = std::make_pair(tokens, QuantifiedLogic::Quantifier::UNIVERSAL);
  }
#line 4347 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 312:
#line 2062 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::EQUIVALENCE);
  }
#line 4355 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 313:
#line 2066 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::IMPLICATION);
  }
#line 4363 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 314:
#line 2070 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::REVERSE_IMPLICATION);
  }
#line 4371 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 315:
#line 2074 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NON_EQUIVALENCE);
  }
#line 4379 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 316:
#line 2078 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_DISJUNCTION);
  }
#line 4387 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 317:
#line 2082 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::NEGATED_CONJUNCTION);
  }
#line 4395 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 318:
#line 2089 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::DISJUNCTION);
  }
#line 4403 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 319:
#line 2093 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< BinaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), BinaryLogic::Connective::CONJUNCTION);
  }
#line 4411 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 320:
#line 2100 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< UnaryConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), UnaryLogic::Connective::NEGATION);
  }
#line 4419 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 321:
#line 2107 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4427 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 322:
#line 2114 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4435 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 323:
#line 2121 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4443 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 324:
#line 2128 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4451 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 325:
#line 2132 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4459 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 326:
#line 2139 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4467 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 327:
#line 2143 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4475 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 328:
#line 2150 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = yystack_[0].value.as< InfixConnective_t > ();
  }
#line 4483 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 329:
#line 2157 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::EQUALITY);
  }
#line 4491 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 330:
#line 2164 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
//EXCLAMATION EQUAL
	yylhs.value.as< InfixConnective_t > () = std::make_pair(yystack_[0].value.as< Token::Ptr > (), InfixLogic::Connective::INEQUALITY);
  }
#line 4500 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 331:
#line 2172 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4508 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 332:
#line 2179 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4516 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 333:
#line 2186 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4524 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 334:
#line 2193 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4532 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 335:
#line 2200 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = yystack_[0].value.as< Identifier::Ptr > ();
  }
#line 4540 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 336:
#line 2207 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4548 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 337:
#line 2214 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 4556 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 338:
#line 2218 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< DefinedAtom::Ptr > () = libtptp::make< DefinedAtom >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4564 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 339:
#line 2225 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< Identifier::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 4576 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 340:
#line 2233 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj add delimiter
	const auto list = yystack_[2].value.as< Nodes::Ptr > ();
	const auto name = yystack_[0].value.as< Identifier::Ptr > ();
	//name->prefix().add($2); //setDelimiter
	list->add(name);
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 4589 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 341:
#line 2245 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4597 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 342:
#line 2249 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< IntegerLiteral::Ptr > ());
  }
#line 4605 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 343:
#line 2256 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaRole::Ptr > () = libtptp::make< FormulaRole >( yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > () );
  }
#line 4613 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 344:
#line 2263 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralData::Ptr > ();
  }
#line 4621 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 345:
#line 2267 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as< GeneralData::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralTerm::Ptr > ());
  }
#line 4629 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 346:
#line 2271 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralList::Ptr > ();
  }
#line 4637 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 347:
#line 2278 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4645 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 348:
#line 2282 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< GeneralFunction::Ptr > ());
  }
#line 4653 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 349:
#line 2286 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< VariableTerm::Ptr > ());
  }
#line 4661 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 350:
#line 2290 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 4669 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 351:
#line 2294 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4677 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 352:
#line 2298 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//$$ = libtptp::make< GeneralData >(@$, $1);
	//TODO: @moosbruggerj remove wrong token
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, uToken);
  }
#line 4687 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 353:
#line 2307 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto name = libtptp::make< Identifier >(yystack_[3].location, yystack_[3].value.as< StringLiteral::Ptr > ());
	yylhs.value.as< GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, name, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4696 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 354:
#line 2315 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 4706 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 355:
#line 2321 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma
	
    auto terms = yystack_[2].value.as< Nodes::Ptr > ();
    terms->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
    yylhs.value.as< Nodes::Ptr > () = terms;
  }
#line 4718 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 356:
#line 2340 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4725 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 357:
#line 2343 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4732 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 358:
#line 2346 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4739 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 359:
#line 2349 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4746 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 360:
#line 2352 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 4753 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 361:
#line 2358 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 4762 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 362:
#line 2363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 4771 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 363:
#line 2372 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4780 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 364:
#line 2377 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Identifier::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< ListLiteral::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 4788 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 365:
#line 2384 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< ListLiteral::Ptr > () = list;
  }
#line 4797 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 366:
#line 2412 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 4805 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 367:
#line 2416 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 4813 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 368:
#line 2423 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 4821 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 369:
#line 2430 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 4829 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 370:
#line 2437 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< IntegerLiteral::Ptr > ();
  }
#line 4837 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 371:
#line 2441 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RealLiteral::Ptr > ();
  }
#line 4845 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 372:
#line 2445 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RationalLiteral::Ptr > ();
  }
#line 4853 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 373:
#line 2452 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make<Identifier>(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 4861 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 374:
#line 2459 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as< std::string > ());
  }
#line 4869 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 375:
#line 2466 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 4877 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 376:
#line 2472 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 4885 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 377:
#line 2479 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto literal = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
	auto identifier = libtptp::make< Identifier >(yylhs.location, literal);
	yylhs.value.as< VariableTerm::Ptr > () = libtptp::make< VariableTerm >(yylhs.location, identifier);
  }
#line 4895 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 378:
#line 2488 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 4903 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 379:
#line 2495 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 4911 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 380:
#line 2502 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 4919 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 381:
#line 2509 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 4927 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 382:
#line 2516 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< std::string > ());
  }
#line 4935 "GrammarParser.cpp" // lalr1.cc:906
    break;


#line 4939 "GrammarParser.cpp" // lalr1.cc:906
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


  const short Parser::yypact_ninf_ = -599;

  const short Parser::yytable_ninf_ = -328;

  const short
  Parser::yypact_[] =
  {
     498,    62,   163,   175,   181,   194,   196,   199,    83,   498,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   149,
     149,   149,   149,   149,   149,   168,  -599,  -599,  -599,  -599,
    -599,   262,  -599,  -599,  -599,  -599,   274,   277,   280,   282,
     297,   470,  -599,   210,   210,   210,   210,   210,   210,   292,
     318,   334,  -599,   345,   349,   359,   434,   436,   149,   423,
    -599,  1641,  1054,  1735,  1341,  1641,  1254,   103,  -599,   371,
      60,  1641,  1826,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
     509,  -599,  -599,  -599,  -599,  -599,   426,   452,   224,  -599,
    1031,   412,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   372,
    -599,  -599,   385,   566,   636,  -599,  -599,   461,   456,  2112,
    -599,   454,  -599,   476,  -599,   489,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   319,
     106,  1113,   825,   488,  -599,  -599,  -599,   652,   552,  -599,
    -599,  -599,  -599,   501,   508,   527,   773,   884,  -599,  1519,
     560,  -599,  -599,   664,  -599,  -599,   688,  -599,  -599,  -599,
    -599,   636,   503,  -599,   258,  -599,  -599,   532,   573,  -599,
    -599,   554,  -599,  -599,  1946,  -599,  -599,  -599,   143,   271,
     541,   308,   580,  -599,   586,  -599,   673,   116,  1735,  1179,
     565,  -599,  -599,  -599,  -599,   591,   624,  1131,   188,  -599,
    -599,   276,  -599,  -599,   675,  -599,  -599,  -599,   428,  -599,
    -599,  -599,   636,   606,  -599,  -599,  -599,   634,   595,   311,
     271,   639,   308,   669,  -599,   684,  -599,   706,  2350,   686,
     365,  -599,   653,  -599,  -599,  -599,  -599,  -599,   700,  -599,
     726,   735,   761,   656,   870,   689,   149,  -599,  -599,   746,
    -599,   803,   815,  2112,  -599,  -599,   140,    93,   829,  2112,
    2112,  2112,  2112,  -599,  -599,  -599,  -599,  -599,  -599,  2112,
    -599,  -599,   365,  -599,   365,   779,   794,  -599,  -599,  -599,
     365,   365,   365,  -599,  -599,  -599,   831,   843,  -599,  -599,
     846,   848,   859,   860,  1946,  -599,  -599,   873,  -599,  1390,
    -599,  -599,  -599,   125,  -599,  -599,  -599,  -599,  -599,    93,
     868,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  -599,  -599,
    -599,  -599,   668,   668,   866,   919,   919,   919,   919,   919,
     794,  1390,  -599,  -599,  -599,  -599,  -599,  1519,   209,  1519,
    1519,  1519,   869,   871,   876,   878,   883,  2297,  -599,  -599,
    -599,   757,   324,  -599,  -599,   767,    93,   877,  2297,  2297,
    2297,  2297,  2297,   935,   935,   888,   794,  2297,  -599,  -599,
    -599,  -599,  -599,   545,   209,  2297,  2297,  2297,   467,   254,
     794,  -599,   895,    93,   908,   870,    93,   910,    93,   911,
    -599,  -599,  -599,  -599,  2112,  -599,   932,  1264,   909,   921,
     927,  -599,  -599,  -599,   922,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
     344,  -599,   714,  -599,   715,   720,  1519,   107,   769,  -599,
    -599,  -599,  1519,  -599,   924,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  1390,  -599,  -599,  -599,  -599,  -599,   655,
    -599,  -599,  -599,   915,  -599,  -599,  -599,   348,  -599,   933,
     929,   527,   938,   944,  -599,   915,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,   942,   939,   940,   941,
    2297,   718,   782,  -599,  -599,  -599,  2297,  -599,   953,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  2297,  -599,
    -599,  -599,  -599,  -599,   413,  -599,  -599,   946,   954,   943,
     925,   545,   545,  -599,  -599,   949,   791,  -599,  -599,  -599,
     959,  -599,  -599,  -599,  -599,  -599,   723,   756,   788,   968,
    -599,   416,   967,  -599,  -599,   969,  -599,   970,  -599,  -599,
     979,   980,   982,   993,   994,  -599,  -599,   424,  1001,   995,
      93,    93,   794,  1005,   365,  -599,  -599,  -599,  1006,   582,
     582,  1007,  -599,  -599,  1008,  1003,   794,  1009,  1519,  -599,
    -599,  -599,  -599,  1011,   467,  1013,  -599,  -599,  1015,  1010,
     794,  1019,   558,  -599,   794,  1014,   802,    76,  -599,   450,
     558,   558,  -599,  -599,  -599,  1021,  1022,  1023,  1024,  1054,
    1735,  1641,  1254,   365,    93,  -599,  -599,  -599,  -599,   806,
    -599,  2112,  -599,  1519,   472,  -599,  2209,  -599,  -599,  -599,
    -599,  -599,  2297,   493,  -599,   193,  -599,  -599,  -599,  2297,
    -599,   511,  -599,   558,  -599,   558,   545,  -599,  -599,  -599,
     807,  1254,  -599,  -599,  -599,  1020,  1025,  1027,  1034,  1035,
    -599,  -599,  -599,  1026,   582,  -599,   825,  1000,  1030,  -599,
    1048,   467,  -599,  1179,  -599,  1061,  -599,  1036,  -599,  -599,
    1064,  -599,  -599,  -599,   558,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  1519,  -599,  1000,  -599,   539,  1519,  1054,  2297,
    -599,  1037,  -599,   549,    77,  2297,  2297,   330,  -599,  1057,
    1519,  -599,  -599,  1060,  1062,   256,  -599,  1070,  -599,   460,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   460,  -599,
    1073,  1055,  -599
  };

  const unsigned short
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     5,     7,     8,     9,    10,    11,    12,     6,     0,
       0,     0,     0,     0,     0,     0,     1,     3,   374,   379,
     380,     0,   341,   342,   366,   367,     0,     0,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,   339,     0,
       0,     0,     0,   310,   320,   311,   375,   376,   378,   377,
       0,    27,   232,   234,   237,   238,   240,   241,   250,   247,
       0,   249,   251,   252,   257,   258,   261,   262,   259,   260,
     280,   269,   263,   265,     0,   277,   233,     0,     0,     0,
     266,   331,   273,   333,   271,   335,   268,   332,   336,   334,
     337,   370,   371,   372,   278,   338,   368,   369,   298,     0,
       0,     0,     0,   311,   300,   305,   306,     0,     0,    28,
      34,    36,    37,    40,    41,    42,     0,    49,    54,     0,
      50,    63,    64,    55,    67,    68,    51,    69,    70,    74,
      75,     0,    72,    29,     0,    38,   113,   114,   115,    30,
      31,     0,   297,   296,     0,   304,   295,   303,     0,    71,
     331,    79,   333,    73,   335,    77,    56,     0,     0,     0,
       0,   125,   131,   133,   134,   136,   137,     0,   142,   149,
     147,   143,   158,   159,   148,   162,   163,   167,   144,   164,
     170,   171,     0,   193,   126,   127,   128,     0,     0,     0,
     165,   331,   173,   333,   168,   335,   192,   151,     0,     0,
       0,   228,     0,   227,   229,   294,   292,   230,   288,   290,
       0,   266,   273,     0,     0,     0,     0,   365,   364,     0,
     381,     0,     0,     0,   284,   286,     0,     0,     0,     0,
       0,     0,     0,   312,   313,   314,   315,   316,   317,     0,
     329,   330,     0,   328,     0,     0,     0,   250,   246,   249,
       0,     0,     0,   301,   302,   309,     0,     0,   319,   318,
       0,     0,     0,     0,   104,   101,   102,     0,   103,     0,
      97,    99,    72,     0,    71,    79,   299,   307,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    52,    53,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,   188,
     198,   190,     0,   165,   173,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   145,
     146,   148,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
     340,   382,   253,   283,     0,   285,     0,     0,     0,    25,
     344,   348,   352,   346,   347,   350,   349,   351,    23,   243,
     245,   244,   242,   239,   279,   270,   281,   264,   248,   282,
       0,   255,     0,   275,     0,     0,     0,     0,    57,    76,
     107,   124,     0,    98,     0,    13,    44,    46,    48,    47,
      45,    43,    39,     0,    94,    78,    95,    66,   123,     0,
     111,   120,   118,   116,   117,   119,   121,     0,    60,     0,
       0,   112,     0,   111,   106,   108,   110,   109,   122,   324,
     326,   331,   327,   333,   325,   335,   105,     0,     0,     0,
       0,     0,   150,   201,   226,   193,     0,   197,     0,    15,
     139,   142,   143,   144,   141,   140,   138,   135,     0,   191,
     172,   194,   161,   225,     0,   153,   155,   156,     0,     0,
       0,     0,     0,   200,   204,     0,   202,   203,   215,   211,
     321,   212,   322,   323,   214,   224,     0,     0,     0,     0,
     289,     0,     0,    17,   291,     0,    19,     0,    21,   287,
       0,     0,     0,     0,     0,   361,   354,     0,     0,     0,
       0,     0,     0,     0,     0,   267,   274,   272,     0,     0,
       0,     0,    85,   100,     0,     0,     0,     0,     0,    57,
      80,    82,    81,     0,     0,     0,   177,   199,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,   222,     0,
       0,     0,   166,   174,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,    24,    26,   345,     0,
     256,     0,   276,     0,     0,    87,     0,    14,    96,    61,
      59,    62,     0,     0,   179,     0,    16,   195,   154,     0,
     157,     0,   205,     0,   210,     0,     0,   221,   218,   216,
       0,     0,    18,    20,    22,     0,     0,     0,     0,     0,
     355,   353,   254,     0,     0,    86,     0,     0,     0,    89,
       0,     0,   178,     0,   184,     0,   181,     0,   185,   152,
       0,   219,   220,   223,     0,   213,   231,   356,   357,   358,
     359,   360,     0,    88,    99,    92,     0,     0,     0,     0,
     180,   162,   186,     0,   190,     0,     0,     0,   217,     0,
       0,    90,    91,     0,     0,     0,   182,     0,   183,     0,
     206,   207,    83,    93,    84,   175,   187,   176,     0,   209,
       0,     0,   208
  };

  const short
  Parser::yypgoto_[] =
  {
    -599,  -599,  -599,  1089,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,    49,  -599,  -564,    48,  -599,  -599,  -599,  -599,  -599,
    -315,   -82,  -599,   482,  -599,  -599,  -599,   473,    97,  -136,
    -599,   430,  -599,  -599,   147,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -588,  -599,   513,   -44,  -115,  -599,   512,  -111,
     531,  -224,  -599,  -599,  -303,  -599,  -599,  -599,   983,   510,
     -52,  -599,  -599,  -599,  -599,  -599,  -331,  -599,  -206,  -599,
    -599,  -333,   521,  -599,  -280,   897,  -599,  -163,  -577,  -599,
    -599,  -269,  -599,  -599,  -599,  -599,  -599,  -599,  -598,  -599,
    -599,  -453,   505,    21,   247,   -54,  -416,  -599,  -599,  -469,
    -209,  -599,   404,  -599,  -599,  -599,  -599,   928,  -599,  -599,
    -599,   -59,   -46,  -599,  -599,  -599,  -599,  -599,   -88,   -51,
     -77,   -72,  -599,  -599,   -50,  -599,  -599,  -599,  -599,  -599,
    -231,  -599,  -599,  -228,  -208,   575,  -211,  -599,  1049,   844,
    -599,   -43,   -33,   736,  -599,  -599,  -599,   -91,  -599,  2065,
     -31,  -599,  2121,  -599,  -599,  -599,   750,    -6,  -103,   -86,
    -101,   407,   637,   991,  1221,  1453,  1675,  1843,  -599,   117,
     716,  -335,  -599,  -599,   578,  -599,   581,  -599,  -599,   -19,
     238,  -599,  -221,  -599,   380,  -599,  -599,   -55,  -160,   798,
    1106,  -599,  -599
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   398,    80,   138,   301,   140,   141,   142,   143,   144,
     145,   146,   332,   147,   148,   149,   457,   458,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   561,
     614,   658,   659,   686,   161,   302,   476,   291,   477,   163,
     464,   164,   466,   165,   166,   167,   168,   169,   170,   190,
     349,   192,   193,   194,   195,   196,   197,   368,   198,   199,
     200,   504,   505,   506,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   575,   623,   665,   666,   667,
     693,   350,   212,   485,   352,   345,   513,   514,   710,   515,
     516,   640,   517,   587,   518,   589,   215,   216,   232,   233,
     234,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   420,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   422,   104,   105,   106,   107,
     256,   237,   238,   239,   171,   172,   173,   174,   175,   176,
     295,   296,   177,   519,   520,   521,   468,   240,   272,   273,
     274,   304,   180,   305,   182,   183,   184,   185,    67,    31,
      51,   399,   400,   401,   547,   402,   403,    18,    59,   117,
     118,   119,   120,    41,   121,   122,   123,   124,   125,    34,
      35,   126,   127
  };

  const short
  Parser::yytable_[] =
  {
      32,    32,    32,    32,    32,    32,   243,   186,   227,   214,
     231,   191,   369,   235,   236,   235,   236,   303,   162,   382,
     292,   277,   461,   245,   454,   251,   255,   490,   494,   495,
     496,   497,   278,   577,   467,   645,   405,   279,   334,    32,
     294,   414,   586,   414,   415,   298,   415,   531,   664,   414,
     414,   414,   415,   415,   415,   371,   178,   219,   322,   269,
     323,   417,   546,   418,   416,   692,   416,   318,   685,   423,
     423,   423,   416,   416,   416,   249,   186,   186,   492,   492,
     492,   492,   492,    26,   213,    19,   691,   162,   405,   493,
     493,   493,   493,   493,   186,   585,   588,   407,  -193,  -193,
     634,   451,   452,   453,   455,   456,   635,   716,   396,   363,
     139,   364,   713,   465,   250,   317,   286,   287,   397,   336,
     246,   249,   529,  -185,   703,   297,   342,   343,   664,   247,
     559,   249,   560,   227,   227,   405,   344,    36,    37,    38,
      39,    40,   432,    28,    76,    77,    78,    29,    79,   407,
      30,   433,   491,   491,   491,   491,   491,   394,   334,   337,
     250,    29,   405,   372,    30,   405,   362,   405,   395,   660,
     250,   277,   277,   277,   277,    68,   405,   235,   236,   290,
     381,   277,   409,   410,   411,   412,    20,   279,   279,   279,
     279,   338,   413,   235,   236,   379,   407,   279,    21,    28,
     499,   499,   406,    29,    22,  -129,    30,   251,   294,   213,
     351,   379,  -129,   298,  -129,   608,   546,    23,   663,    24,
     673,   421,    25,   407,    70,    30,   407,    32,   407,   436,
     437,   438,   439,   440,   441,   442,   704,   407,   404,   336,
     294,  -235,   707,   708,   186,   298,   320,    29,  -235,   721,
      30,   631,  -235,   461,   406,   462,   186,   186,   186,   186,
     186,   186,   186,    29,    29,   467,    30,   446,   446,   650,
     336,   336,   336,   336,   336,   459,   186,   325,   530,    43,
     448,   189,   186,   385,   186,   186,   186,  -326,   326,   327,
     404,    44,   227,  -130,    45,   344,   321,    46,   669,    47,
    -130,   406,  -130,   227,   227,   227,   227,   227,   501,   501,
      29,   507,   227,    30,    48,   508,   562,    58,   524,  -326,
     227,   227,   227,   414,  -327,   507,   415,   373,   406,   405,
     405,   406,   469,   406,   235,   236,    60,   404,   283,   284,
     285,   486,   406,   612,   465,   510,   416,   290,   539,   492,
     487,    61,   294,   709,   522,   512,  -327,   298,   434,   374,
     493,   552,    62,   390,   404,   566,    63,   404,   469,   404,
     553,   186,   414,   630,   567,   415,    64,   186,   404,   460,
      70,   638,   639,   405,    29,    79,   503,    30,   186,   248,
     407,   407,   649,  -279,  -279,   416,   351,   351,   351,    33,
      33,    33,    33,    33,    33,   488,  -270,  -270,   320,   320,
     320,   320,   320,   320,   320,    28,    76,    77,    78,    29,
      79,   297,    30,   491,   671,   227,   672,   576,   573,  -236,
     580,   227,   532,   580,   320,   535,  -236,   537,    33,   581,
    -236,   604,   595,   227,   407,  -132,   579,    69,   292,   615,
     605,    65,  -132,    66,  -132,   259,   524,   524,   321,   321,
     321,   321,   321,   321,   321,   698,   260,   636,   110,   179,
     220,   241,   110,   110,   558,   510,   637,   280,   110,   110,
     563,   276,   529,   718,   321,   512,   462,    49,   711,   654,
     378,   565,   522,   522,    50,   406,   406,   610,   655,   281,
     719,     1,     2,     3,     4,     5,     6,   351,   275,   719,
     661,   459,   282,   186,    29,    79,   110,    30,   306,   662,
     624,    29,   312,   277,    30,   507,   257,   524,   580,   507,
     311,   404,   404,   258,   652,   524,   524,   670,   179,   279,
     313,   303,   647,   683,   186,   227,   214,     7,   191,   406,
     324,   235,   236,   297,   297,   162,   700,   509,   186,   648,
     510,   186,   328,   522,   339,   701,   705,   227,   511,   309,
     512,   522,   522,   510,   227,   706,   310,   -33,   524,   330,
     524,   524,   356,   512,   -33,   404,   -33,  -281,  -281,   357,
     235,   236,   329,   178,   219,   220,   353,   529,   676,    29,
      79,   186,    30,   340,   335,   559,   -33,   690,   227,   341,
     187,   523,    29,    79,   522,    30,   522,   522,   367,   524,
     358,   213,   526,   527,   528,   353,    33,   186,    73,    74,
      75,   319,   186,   186,   227,   241,    29,   110,   359,    30,
     227,   227,   524,   351,   162,   186,   668,   139,   297,    29,
      79,   110,    30,   365,   524,   522,   333,   270,   271,   366,
     110,   653,   375,   524,   657,   320,   110,   110,   110,   110,
     383,   307,   308,   386,   283,   284,   110,   384,   522,   110,
     387,   110,   178,   130,   694,   -94,   -94,   110,   110,   110,
     522,   443,   376,   132,   -95,   -95,  -191,  -191,   111,   522,
     221,   111,   111,   111,   684,   -35,   388,   377,   111,   111,
     351,   380,   -35,   389,   -35,   321,   351,   351,    28,    76,
      77,    78,    29,    79,   335,    30,   668,  -194,  -194,   385,
     699,   554,   554,   529,   -35,   702,   139,   554,   555,   556,
     486,   378,   373,   574,   557,   470,   111,   592,   657,   523,
     523,  -326,   444,   444,   353,   335,   335,   335,   335,   335,
      53,    54,    55,    56,    57,   353,   353,   353,   353,   353,
     353,   353,    29,   486,   353,    30,   333,  -327,  -193,  -193,
     593,   470,   353,   353,   353,   470,   314,   315,  -192,  -192,
     -96,   -96,   110,   319,   319,   319,   319,   319,   319,   319,
     391,   110,   316,  -195,  -195,   486,    72,   450,   450,   450,
     450,   450,   594,   263,   264,   265,   266,   267,   268,   463,
     523,  -209,  -209,   604,   674,   221,   221,   392,   523,   523,
     651,   675,   633,   590,   470,   445,   447,   128,   129,   393,
     130,    52,    52,    52,    52,    52,    52,   408,   299,    79,
     132,   300,   478,   479,   426,   221,   424,   425,    73,    74,
     133,   134,   135,   136,   137,   111,   427,   111,   500,   502,
     428,   523,   429,   523,   523,    28,    76,    77,    78,    29,
      79,   111,    30,   430,   431,    70,   435,   353,   470,   337,
     111,   132,   480,   353,   481,   489,   111,   111,   111,   111,
     482,   -32,   483,  -111,   230,   353,   111,   484,   -32,   111,
     -32,   111,   523,   189,  -111,  -111,   270,   111,   111,   111,
      28,    76,    77,    78,    29,    79,   533,    30,   536,   538,
     -32,   128,   449,   548,   130,   523,   540,   541,   549,   542,
     543,   544,   331,   550,   132,   551,   327,   523,   564,   568,
     187,   314,    73,   569,   133,   134,   523,   -49,   498,   432,
     189,   110,   582,   570,   571,   572,   470,   470,   584,    28,
      76,    77,    78,    29,    79,   471,    30,   578,   583,   250,
     590,   470,   591,   249,   221,    28,    76,    77,    78,    29,
      79,   596,    30,   597,   598,   221,   221,   221,   221,   221,
     221,   221,   599,   600,   221,   601,   179,   220,   110,   110,
     110,   471,   221,   221,   221,   471,   602,   603,   110,   606,
     397,   611,   111,   613,   616,   620,   617,   618,   622,   353,
     625,   111,   353,   626,   627,   629,   353,   641,   632,   619,
     642,   643,   644,   682,   677,   261,   687,   688,   110,   678,
     463,   679,   112,   181,   222,   242,   112,   112,   680,   681,
     262,   470,   112,   112,   471,   689,   128,   129,   470,   130,
     353,   263,   264,   265,   266,   267,   268,   131,   695,   132,
     697,   712,   696,  -184,   714,   633,   715,    73,    74,   133,
     134,   135,   136,   137,   717,   179,   353,   722,    27,   621,
     112,   628,   353,   353,    28,    76,    77,    78,    29,    79,
     646,    30,   353,   720,   293,   370,   346,   221,   471,   419,
     252,   534,   181,   221,   525,   128,   129,   288,   130,   609,
     607,    42,     0,     0,   270,   221,   131,     0,   132,     0,
       0,     0,   289,     0,     0,   360,    73,    74,   133,   134,
     135,   136,   137,   263,   264,   265,   266,   267,   268,     0,
     361,     0,     0,    28,    76,    77,    78,    29,    79,     0,
      30,   263,   264,   265,   266,   267,   268,     0,     0,   222,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,   187,     0,   471,   471,     0,     0,
       0,     0,   347,     0,   189,   348,     0,     0,     0,   354,
       0,   471,    73,    74,    75,     0,     0,     0,     0,   242,
       0,   112,     0,     0,     0,     0,     0,     0,     0,    28,
      76,    77,    78,    29,    79,   112,    30,   221,   111,   111,
     111,     0,     0,     0,   112,     0,     0,     0,   111,     0,
     112,   112,   112,   112,     0,     0,     0,     0,     0,   221,
     112,     0,   221,   112,     0,   112,   221,     0,     0,    70,
       0,   112,   112,   112,     0,     0,     0,   244,   111,   396,
       0,     0,   113,     0,   223,   113,   113,   113,   230,   397,
     545,   471,   113,   113,     0,     0,     0,     0,   471,     0,
     221,     0,     0,     0,    28,    76,    77,    78,    29,    79,
       0,    30,     0,     0,    28,    76,    77,    78,    29,    79,
       0,    30,     0,     0,     0,     0,   221,     0,     0,   472,
     113,     0,   221,   221,     0,     0,     0,     0,   354,     0,
       0,     0,   221,     0,     0,     0,     0,     0,     0,   354,
     354,   354,   354,   354,   354,   354,    70,     0,   354,     0,
       0,     0,     0,     0,   228,   472,   354,   354,   354,   472,
       0,     0,     0,     0,   229,   230,   112,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,    28,    76,    77,    78,    29,    79,     0,    30,     0,
       0,     0,   128,   129,   288,   130,     0,     0,     0,   223,
     223,   270,     0,   299,     0,   132,     0,     0,   472,   289,
       0,     0,     0,    73,    74,   133,   134,   135,   136,   137,
     263,   264,   265,   266,   267,   268,     0,     0,     0,   223,
      28,    76,    77,    78,    29,    79,     0,    30,     0,   113,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,   354,   472,     0,   113,     0,     0,   354,     0,     0,
     113,   113,   113,   113,     0,     0,     0,     0,     0,   354,
     113,     0,     0,   113,     0,   113,     0,     0,     0,     0,
       0,   113,   113,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,   224,   114,   114,   114,
       0,     0,     0,     0,   114,   114,     0,     0,     0,     0,
       0,   128,   129,     0,   130,     0,     0,     0,     0,     0,
       0,     0,   299,     0,   132,   112,     0,     0,     0,     0,
     472,   472,    73,    74,   133,   134,   135,   136,   137,   473,
       0,     0,   114,     0,     0,   472,     0,     0,   223,    28,
      76,    77,    78,    29,    79,     0,    30,     0,     0,   223,
     223,   223,   223,   223,   223,   223,     0,     0,   223,     0,
     181,   222,   112,   112,   112,   473,   223,   223,   223,   473,
       0,     0,   112,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,   354,     0,   113,     0,     0,     0,     0,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   224,     0,     0,   472,     0,     0,   473,     0,
       0,     0,   472,     0,   354,     0,    70,     0,     0,     0,
       0,     0,     0,     0,    71,     0,     0,     0,    72,     0,
       0,   224,     0,     0,    73,    74,    75,     0,     0,   181,
     354,   114,     0,   114,     0,     0,   354,   354,     0,     0,
       0,    28,    76,    77,    78,    29,    79,   114,    30,     0,
       0,   223,   473,     0,     0,     0,   114,   223,     0,     0,
       0,     0,   114,   114,   114,   114,     0,     0,     0,   223,
       0,     0,   114,     0,     0,   114,     0,   114,     0,     0,
       0,     0,     0,   114,   114,   114,   115,     0,   225,   115,
     115,   115,     0,     0,     0,     0,   115,   115,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,   188,     0,
     189,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     473,   473,     0,     0,   115,    28,    76,    77,    78,    29,
      79,   474,    30,     0,     0,   473,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   224,   224,   224,   224,   224,   224,     0,     0,
     224,   223,   113,   113,   113,     0,     0,   474,   224,   224,
     224,     0,   113,     0,     0,     0,     0,     0,   114,     0,
       0,    70,     0,   223,     0,     0,     0,   114,     0,   253,
     223,     0,     0,     0,   254,     0,     0,     0,     0,    73,
      74,    75,   113,   225,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,    28,    76,    77,    78,
      29,    79,   473,    30,   223,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   115,   226,   116,   116,   116,
     223,     0,     0,     0,   116,   116,   223,   223,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   224,   115,   115,   115,   115,     0,   224,
       0,     0,     0,     0,   115,     0,     0,   115,     0,   115,
       0,   224,   116,     0,     0,   115,   115,   115,   128,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,   331,
       0,   132,     0,     0,     0,     0,     0,     0,     0,    73,
      74,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    76,    77,    78,
      29,    79,     0,    30,     0,     0,     0,   114,     0,     0,
       0,     0,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   355,   225,   225,   225,   225,   225,   225,   225,
       0,     0,   225,     0,     0,     0,     0,     0,     0,   475,
     225,   225,   225,   224,   114,   114,   114,     0,     0,     0,
     115,     0,     0,     0,   114,     0,     0,     0,     0,   115,
       0,   116,     0,   116,     0,   224,     0,     0,     0,     0,
       0,     0,   224,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,   114,     0,   116,     0,     0,     0,
       0,     0,   116,   116,   116,   116,     0,     0,     0,     0,
       0,     0,   116,     0,     0,   116,   224,   116,     0,     0,
       0,     0,     0,   116,   116,   116,   108,    70,   217,     0,
     108,     0,     0,     0,     0,   253,   108,   108,     0,     0,
       0,     0,   224,     0,     0,    73,    74,    75,   224,   224,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,   225,    28,    76,    77,    78,    29,    79,     0,    30,
       0,     0,     0,   225,   108,     0,     0,     0,     0,     0,
       0,     0,   109,     0,   218,     0,   109,     0,     0,     0,
     226,     0,   109,   109,     0,     0,     0,     0,     0,     0,
       0,   226,   226,   226,   226,   226,   226,   226,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,   355,   355,
     355,   128,   129,     0,   130,     0,     0,     0,   116,   115,
     109,     0,   299,     0,   656,     0,     0,   116,     0,     0,
       0,     0,    73,    74,   133,   134,   135,   136,   137,     0,
       0,     0,     0,   217,   217,     0,     0,     0,     0,    28,
      76,    77,    78,    29,    79,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   115,   115,   115,     0,
       0,     0,     0,   217,     0,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,   218,
     218,     0,   187,     0,     0,     0,   115,     0,   108,     0,
     347,     0,   189,   226,   108,   108,   108,   108,     0,   355,
      73,    74,    75,     0,   108,     0,     0,     0,   225,   218,
       0,   226,     0,     0,     0,     0,     0,    28,    76,    77,
      78,    29,    79,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,    70,     0,     0,     0,     0,
     225,   225,     0,   378,   109,     0,     0,     0,     0,     0,
     109,   109,   109,   109,   230,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,   116,     0,     0,
      28,    76,    77,    78,    29,    79,     0,    30,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,   217,   217,   217,   217,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
     217,   217,   217,   226,   116,   116,   116,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,   355,     0,     0,   218,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,   218,
     218,   218,   218,   218,   116,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,   218,   218,   218,     0,
       0,     0,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,   355,   355,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,   109,     0,     0,     0,     0,     0,   217,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
     218,     0,     0,     0,   217,     0,     0,     0,     0,     0,
     217,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,   218,   218
  };

  const short
  Parser::yycheck_[] =
  {
      19,    20,    21,    22,    23,    24,    65,    62,    63,    63,
      64,    63,   218,    64,    64,    66,    66,   132,    62,   230,
     131,   109,   337,    66,   327,    71,    72,   358,   359,   360,
     361,   362,   109,   486,   337,   599,   257,   109,   174,    58,
     131,   272,   511,   274,   272,   131,   274,   380,   625,   280,
     281,   282,   280,   281,   282,   218,    62,    63,   161,    90,
     161,   272,   397,   274,   272,   663,   274,   149,   656,   280,
     281,   282,   280,   281,   282,    15,   131,   132,   358,   359,
     360,   361,   362,     0,    63,    23,   663,   131,   309,   358,
     359,   360,   361,   362,   149,   511,   512,   257,    21,    22,
      24,   325,   326,   327,   328,   329,    30,   705,    15,   212,
      62,   212,   700,   337,    54,   146,    10,    11,    25,   174,
      17,    15,    15,    46,   688,   131,    10,    11,   705,    26,
      23,    15,    25,   188,   189,   356,   188,    20,    21,    22,
      23,    24,    17,    50,    51,    52,    53,    54,    55,   309,
      57,    26,   358,   359,   360,   361,   362,    17,   294,    16,
      54,    54,   383,   218,    57,   386,   197,   388,    28,   622,
      54,   259,   260,   261,   262,    58,   397,   228,   228,   131,
     230,   269,   259,   260,   261,   262,    23,   259,   260,   261,
     262,    48,   269,   244,   244,   228,   356,   269,    23,    50,
     363,   364,   257,    54,    23,    17,    57,   253,   299,   188,
     189,   244,    24,   299,    26,   550,   551,    23,    25,    23,
     636,   276,    23,   383,    15,    57,   386,   246,   388,   311,
     312,   313,   314,   315,   316,   317,   689,   397,   257,   294,
     331,    17,   695,   696,   299,   331,   149,    54,    24,   718,
      57,   584,    28,   568,   309,   337,   311,   312,   313,   314,
     315,   316,   317,    54,    54,   568,    57,   322,   323,   604,
     325,   326,   327,   328,   329,   330,   331,    19,    24,    17,
     324,    25,   337,    29,   339,   340,   341,    16,    30,    31,
     309,    17,   347,    17,    17,   347,   149,    17,   629,    17,
      24,   356,    26,   358,   359,   360,   361,   362,   363,   364,
      54,   366,   367,    57,    17,   367,   427,    25,   373,    48,
     375,   376,   377,   554,    16,   380,   554,    16,   383,   550,
     551,   386,   338,   388,   385,   385,    18,   356,    19,    20,
      21,    17,   397,   554,   568,    15,   554,   299,   394,   629,
      26,    17,   443,    23,   373,    25,    48,   443,   309,    48,
     629,    17,    17,   246,   383,    17,    17,   386,   374,   388,
      26,   426,   603,   582,    26,   603,    17,   432,   397,   331,
      15,   590,   591,   604,    54,    55,   365,    57,   443,    18,
     550,   551,   603,    21,    22,   603,   375,   376,   377,    19,
      20,    21,    22,    23,    24,   356,    21,    22,   311,   312,
     313,   314,   315,   316,   317,    50,    51,    52,    53,    54,
      55,   427,    57,   629,   633,   480,   635,   481,   480,    17,
      17,   486,   383,    17,   337,   386,    24,   388,    58,    26,
      28,    17,    26,   498,   604,    17,   498,    24,   559,   560,
      26,    17,    24,    17,    26,    29,   511,   512,   311,   312,
     313,   314,   315,   316,   317,   674,    14,    17,    61,    62,
      63,    64,    65,    66,   426,    15,    26,    23,    71,    72,
     432,    25,    15,    23,   337,    25,   568,    17,   697,    17,
      23,   443,   511,   512,    24,   550,   551,   552,    26,    23,
     709,     3,     4,     5,     6,     7,     8,   486,    47,   718,
      17,   566,    23,   568,    54,    55,   109,    57,    30,    26,
     574,    54,    14,   611,    57,   580,    17,   582,    17,   584,
      29,   550,   551,    24,   611,   590,   591,    26,   131,   611,
      13,   656,   601,   654,   599,   600,   600,    49,   600,   604,
      47,   602,   602,   559,   560,   599,    17,    12,   613,   602,
      15,   616,    30,   582,    23,    26,    17,   622,    23,    17,
      25,   590,   591,    15,   629,    26,    24,    17,   633,    25,
     635,   636,    17,    25,    24,   604,    26,    21,    22,    24,
     641,   641,    19,   599,   600,   188,   189,    15,   641,    54,
      55,   656,    57,    23,   174,    23,    46,   661,   663,    23,
      15,   373,    54,    55,   633,    57,   635,   636,    23,   674,
      29,   600,   375,   376,   377,   218,   246,   682,    33,    34,
      35,   149,   687,   688,   689,   228,    54,   230,    14,    57,
     695,   696,   697,   622,   688,   700,   625,   599,   654,    54,
      55,   244,    57,    47,   709,   674,   174,    21,    22,    25,
     253,   613,    23,   718,   616,   568,   259,   260,   261,   262,
      17,    19,    20,    17,    19,    20,   269,    24,   697,   272,
      24,   274,   688,    15,   663,    21,    22,   280,   281,   282,
     709,    23,    23,    25,    21,    22,    21,    22,    61,   718,
      63,    64,    65,    66,   656,    17,    17,    23,    71,    72,
     689,    25,    24,    24,    26,   568,   695,   696,    50,    51,
      52,    53,    54,    55,   294,    57,   705,    21,    22,    29,
     682,    17,    17,    15,    46,   687,   688,    17,    24,    24,
      17,    23,    16,    25,    24,   338,   109,    24,   700,   511,
     512,    16,   322,   323,   347,   325,   326,   327,   328,   329,
      44,    45,    46,    47,    48,   358,   359,   360,   361,   362,
     363,   364,    54,    17,   367,    57,   294,    16,    21,    22,
      24,   374,   375,   376,   377,   378,    13,    14,    21,    22,
      21,    22,   385,   311,   312,   313,   314,   315,   316,   317,
      54,   394,    29,    21,    22,    17,    27,   325,   326,   327,
     328,   329,    24,    40,    41,    42,    43,    44,    45,   337,
     582,    30,    31,    17,    17,   188,   189,    24,   590,   591,
      24,    24,    30,    31,   427,   322,   323,    12,    13,    24,
      15,    43,    44,    45,    46,    47,    48,    18,    23,    55,
      25,    26,   340,   341,    23,   218,   281,   282,    33,    34,
      35,    36,    37,    38,    39,   228,    23,   230,   363,   364,
      24,   633,    24,   635,   636,    50,    51,    52,    53,    54,
      55,   244,    57,    24,    24,    15,    18,   480,   481,    16,
     253,    25,    23,   486,    23,    18,   259,   260,   261,   262,
      24,    17,    24,    19,    34,   498,   269,    24,    24,   272,
      26,   274,   674,    25,    30,    31,    21,   280,   281,   282,
      50,    51,    52,    53,    54,    55,    18,    57,    18,    18,
      46,    12,    13,    24,    15,   697,     4,     5,    17,     7,
       8,     9,    23,    16,    25,    23,    31,   709,    24,    16,
      15,    13,    33,    24,    35,    36,   718,    13,    23,    17,
      25,   554,    16,    24,    24,    24,   559,   560,    25,    50,
      51,    52,    53,    54,    55,   338,    57,    24,    24,    54,
      31,   574,    23,    15,   347,    50,    51,    52,    53,    54,
      55,    24,    57,    24,    24,   358,   359,   360,   361,   362,
     363,   364,    23,    23,   367,    23,   599,   600,   601,   602,
     603,   374,   375,   376,   377,   378,    23,    23,   611,    18,
      25,    16,   385,    17,    17,    16,    18,    24,    17,   622,
      17,   394,   625,    18,    24,    16,   629,    16,    24,   566,
      18,    18,    18,    17,    24,    14,    46,    17,   641,    24,
     568,    24,    61,    62,    63,    64,    65,    66,    24,    24,
      29,   654,    71,    72,   427,    17,    12,    13,   661,    15,
     663,    40,    41,    42,    43,    44,    45,    23,    17,    25,
      16,    24,    46,    46,    24,    30,    24,    33,    34,    35,
      36,    37,    38,    39,    24,   688,   689,    24,     9,   568,
     109,   580,   695,   696,    50,    51,    52,    53,    54,    55,
     600,    57,   705,   709,   131,   218,   188,   480,   481,   275,
      71,   385,   131,   486,   374,    12,    13,    14,    15,   551,
     549,    25,    -1,    -1,    21,   498,    23,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    14,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      29,    -1,    -1,    50,    51,    52,    53,    54,    55,    -1,
      57,    40,    41,    42,    43,    44,    45,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,    -1,    -1,    15,    -1,   559,   560,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,   218,
      -1,   574,    33,    34,    35,    -1,    -1,    -1,    -1,   228,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,   244,    57,   600,   601,   602,
     603,    -1,    -1,    -1,   253,    -1,    -1,    -1,   611,    -1,
     259,   260,   261,   262,    -1,    -1,    -1,    -1,    -1,   622,
     269,    -1,   625,   272,    -1,   274,   629,    -1,    -1,    15,
      -1,   280,   281,   282,    -1,    -1,    -1,    23,   641,    15,
      -1,    -1,    61,    -1,    63,    64,    65,    66,    34,    25,
      26,   654,    71,    72,    -1,    -1,    -1,    -1,   661,    -1,
     663,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,   689,    -1,    -1,   338,
     109,    -1,   695,   696,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,   358,
     359,   360,   361,   362,   363,   364,    15,    -1,   367,    -1,
      -1,    -1,    -1,    -1,    23,   374,   375,   376,   377,   378,
      -1,    -1,    -1,    -1,    33,    34,   385,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    -1,    12,    13,    14,    15,    -1,    -1,    -1,   188,
     189,    21,    -1,    23,    -1,    25,    -1,    -1,   427,    29,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,   218,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,   228,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,   480,   481,    -1,   253,    -1,    -1,   486,    -1,    -1,
     259,   260,   261,   262,    -1,    -1,    -1,    -1,    -1,   498,
     269,    -1,    -1,   272,    -1,   274,    -1,    -1,    -1,    -1,
      -1,   280,   281,   282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,   554,    -1,    -1,    -1,    -1,
     559,   560,    33,    34,    35,    36,    37,    38,    39,   338,
      -1,    -1,   109,    -1,    -1,   574,    -1,    -1,   347,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,   358,
     359,   360,   361,   362,   363,   364,    -1,    -1,   367,    -1,
     599,   600,   601,   602,   603,   374,   375,   376,   377,   378,
      -1,    -1,   611,    -1,    -1,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,   394,    -1,    -1,    -1,    -1,
     629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,    -1,    -1,   654,    -1,    -1,   427,    -1,
      -1,    -1,   661,    -1,   663,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    -1,
      -1,   218,    -1,    -1,    33,    34,    35,    -1,    -1,   688,
     689,   228,    -1,   230,    -1,    -1,   695,   696,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,   244,    57,    -1,
      -1,   480,   481,    -1,    -1,    -1,   253,   486,    -1,    -1,
      -1,    -1,   259,   260,   261,   262,    -1,    -1,    -1,   498,
      -1,    -1,   269,    -1,    -1,   272,    -1,   274,    -1,    -1,
      -1,    -1,    -1,   280,   281,   282,    61,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,
     559,   560,    -1,    -1,   109,    50,    51,    52,    53,    54,
      55,   338,    57,    -1,    -1,   574,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,   359,   360,   361,   362,   363,   364,    -1,    -1,
     367,   600,   601,   602,   603,    -1,    -1,   374,   375,   376,
     377,    -1,   611,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    15,    -1,   622,    -1,    -1,    -1,   394,    -1,    23,
     629,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,   641,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   654,    50,    51,    52,    53,
      54,    55,   661,    57,   663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,    61,   230,    63,    64,    65,    66,
     689,    -1,    -1,    -1,    71,    72,   695,   696,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,   480,   259,   260,   261,   262,    -1,   486,
      -1,    -1,    -1,    -1,   269,    -1,    -1,   272,    -1,   274,
      -1,   498,   109,    -1,    -1,   280,   281,   282,    12,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    -1,   554,    -1,    -1,
      -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   358,   359,   360,   361,   362,   363,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     375,   376,   377,   600,   601,   602,   603,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   611,    -1,    -1,    -1,    -1,   394,
      -1,   228,    -1,   230,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,   629,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   641,    -1,   253,    -1,    -1,    -1,
      -1,    -1,   259,   260,   261,   262,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,   272,   663,   274,    -1,    -1,
      -1,    -1,    -1,   280,   281,   282,    61,    15,    63,    -1,
      65,    -1,    -1,    -1,    -1,    23,    71,    72,    -1,    -1,
      -1,    -1,   689,    -1,    -1,    33,    34,    35,   695,   696,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,   486,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    -1,   498,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    63,    -1,    65,    -1,    -1,    -1,
     347,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,   359,   360,   361,   362,   363,   364,    -1,    -1,
     367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,   376,
     377,    12,    13,    -1,    15,    -1,    -1,    -1,   385,   554,
     109,    -1,    23,    -1,    25,    -1,    -1,   394,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   600,   601,   602,   603,    -1,
      -1,    -1,    -1,   218,    -1,    -1,   611,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,   188,
     189,    -1,    15,    -1,    -1,    -1,   641,    -1,   253,    -1,
      23,    -1,    25,   480,   259,   260,   261,   262,    -1,   486,
      33,    34,    35,    -1,   269,    -1,    -1,    -1,   663,   218,
      -1,   498,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   689,    15,    -1,    -1,    -1,    -1,
     695,   696,    -1,    23,   253,    -1,    -1,    -1,    -1,    -1,
     259,   260,   261,   262,    34,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,   359,   360,   361,   362,    -1,    -1,
      -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     375,   376,   377,   600,   601,   602,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   611,    -1,    -1,    -1,    -1,   394,
      -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,   347,    -1,
      -1,    -1,   629,    -1,    -1,    -1,    -1,    -1,    -1,   358,
     359,   360,   361,   362,   641,    -1,    -1,    -1,   367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,   376,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   689,    -1,    -1,    -1,    -1,    -1,   695,   696,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   611,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   600,   601,    -1,    -1,    -1,    -1,    -1,   663,    -1,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
     629,    -1,    -1,    -1,   689,    -1,    -1,    -1,    -1,    -1,
     695,   696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     689,    -1,    -1,    -1,    -1,    -1,   695,   696
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    49,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   235,    23,
      23,    23,    23,    23,    23,    23,     0,    61,    50,    54,
      57,   227,   237,   242,   247,   248,   227,   227,   227,   227,
     227,   241,   248,    17,    17,    17,    17,    17,    17,    17,
      24,   228,   247,   228,   228,   228,   228,   228,    25,   236,
      18,    17,    17,    17,    17,    17,    17,   226,   227,    24,
      15,    23,    27,    33,    34,    35,    51,    52,    53,    55,
      70,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   194,   195,   196,   197,   207,   210,
     219,   220,   221,   222,   223,   224,   225,   237,   238,   239,
     240,   242,   243,   244,   245,   246,   249,   250,    12,    13,
      15,    23,    25,    35,    36,    37,    38,    39,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    81,    82,    83,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   102,   103,   107,   109,   111,   112,   113,   114,   115,
     116,   202,   203,   204,   205,   206,   207,   210,   215,   219,
     220,   221,   222,   223,   224,   225,   245,    15,    23,    25,
     117,   118,   119,   120,   121,   122,   123,   124,   126,   127,
     128,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   150,   151,   153,   164,   165,   207,   210,   215,
     219,   220,   221,   222,   223,   224,   225,   245,    23,    33,
      34,   153,   166,   167,   168,   177,   182,   199,   200,   201,
     215,   219,   221,   169,    23,   199,    17,    26,    18,    15,
      54,   170,   196,    23,    28,   170,   198,    17,    24,    29,
      14,    14,    29,    40,    41,    42,    43,    44,    45,   208,
      21,    22,   216,   217,   218,    47,    25,   176,   178,   179,
      23,    23,    23,    19,    20,    21,    10,    11,    14,    29,
      72,   105,   107,   116,   205,   208,   209,   215,   217,    23,
      26,    72,   103,   104,   219,   221,    30,    19,    20,    17,
      24,    29,    14,    13,    13,    14,    29,   208,    79,    81,
      86,    92,   216,   218,    47,    19,    30,    31,    30,    19,
      25,    23,    80,    81,    87,    89,   245,    16,    48,    23,
      23,    23,    10,    11,   118,   153,   165,    23,    26,   118,
     149,   151,   152,   219,   221,   225,    17,    24,    29,    14,
      14,    29,   208,   216,   218,    47,    25,    23,   125,   126,
     133,   135,   245,    16,    48,    23,    23,    23,    23,   200,
      25,   182,   194,    17,    24,    29,    17,    24,    17,    24,
     227,    54,    24,    24,    17,    28,    15,    25,    69,   229,
     230,   231,   233,   234,   237,   240,   245,   246,    18,   178,
     178,   178,   178,   178,   188,   191,   192,   194,   194,   197,
     181,   245,   193,   194,   193,   193,    23,    23,    24,    24,
      24,    24,    17,    26,    69,    18,    79,    79,    79,    79,
      79,    79,    79,    23,    89,   102,   245,   102,   103,    13,
      81,   109,   109,   109,   112,   109,   109,    84,    85,   245,
      72,    78,    79,    81,   108,   109,   110,   112,   214,   215,
     219,   220,   221,   222,   223,   224,   104,   106,   106,   106,
      23,    23,    24,    24,    24,   151,    17,    26,    69,    18,
     124,   126,   132,   139,   124,   124,   124,   124,    23,   135,
     150,   245,   150,   151,   129,   130,   131,   245,   118,    12,
      15,    23,    25,   154,   155,   157,   158,   160,   162,   211,
     212,   213,   237,   238,   245,   214,   152,   152,   152,    15,
      24,   129,    69,    18,   201,    69,    18,    69,    18,   170,
       4,     5,     7,     8,     9,    26,   229,   232,    24,    17,
      16,    23,    17,    26,    17,    24,    24,    24,    72,    23,
      25,    97,   107,    72,    24,    72,    17,    26,    16,    24,
      24,    24,    24,   118,    25,   143,   153,   149,    24,   118,
      17,    26,    16,    24,    25,   154,   157,   161,   154,   163,
      31,    23,    24,    24,    24,    26,    24,    24,    24,    23,
      23,    23,    23,    23,    17,    26,    18,   234,   229,   232,
     245,    16,   194,    17,    98,   107,    17,    18,    24,    85,
      16,   108,    17,   144,   153,    17,    18,    24,   130,    16,
     158,   129,    24,    30,    24,    30,    17,    26,   158,   158,
     159,    16,    18,    18,    18,    71,   117,   169,   199,   194,
     229,    24,   178,    72,    17,    26,    25,    72,    99,   100,
     149,    17,    26,    25,   136,   145,   146,   147,   151,   124,
      26,   158,   158,   154,    17,    24,   199,    24,    24,    24,
      24,    24,    17,   107,    72,   100,   101,    46,    17,    17,
     153,   136,   146,   148,   151,    17,    46,    16,   158,    72,
      17,    26,    72,    71,   149,    17,    26,   149,   149,    23,
     156,   158,    24,   100,    24,    24,   146,    24,    23,   158,
     160,   157,    24
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    74,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    83,
      84,    84,    85,    86,    86,    87,    88,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    92,    93,
      94,    94,    94,    95,    96,    97,    97,    98,    98,    99,
      99,   100,   101,   101,   102,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   105,   106,   107,   107,   108,   108,
     108,   109,   110,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   125,   125,   126,   126,   126,
     126,   127,   128,   129,   129,   130,   130,   131,   132,   132,
     133,   134,   135,   135,   135,   136,   136,   137,   138,   138,
     138,   138,   139,   140,   140,   141,   142,   143,   143,   144,
     144,   145,   145,   146,   147,   147,   148,   148,   149,   149,
     149,   150,   150,   150,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   154,   154,   155,   156,   156,   157,
     157,   158,   158,   158,   158,   158,   159,   159,   160,   161,
     161,   162,   163,   163,   164,   165,   165,   166,   166,   167,
     167,   168,   169,   169,   170,   170,   170,   171,   171,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   177,   178,
     178,   179,   179,   179,   180,   181,   181,   182,   182,   182,
     183,   184,   184,   185,   186,   187,   188,   188,   189,   189,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   202,   202,   202,   203,   203,
     204,   204,   204,   205,   205,   206,   206,   206,   206,   206,
     207,   207,   208,   208,   208,   208,   208,   208,   209,   209,
     210,   211,   212,   213,   214,   214,   215,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   225,   226,
     226,   227,   227,   228,   229,   229,   229,   230,   230,   230,
     230,   230,   230,   231,   232,   232,   233,   233,   233,   233,
     233,   234,   234,   235,   235,   236,   237,   237,   238,   239,
     240,   240,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,    11,     9,    11,     9,    11,     9,
      11,     9,    11,     9,    11,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     5,
       1,     3,     3,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       4,     4,     4,     9,     9,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     1,     3,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     6,     1,     3,     1,     1,     3,     1,     1,
       2,     3,     1,     1,     1,     1,     4,     1,     1,     4,
       1,     1,     3,     1,     4,     9,     9,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     1,     3,
       3,     3,     1,     1,     1,     3,     6,     1,     3,     1,
       3,     1,     1,     4,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     2,     1,     3,     1,
       1,     1,     1,     3,     6,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     4,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     5,     5,     5,     5,
       5,     2,     3,     5,     7,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"tpi\"", "\"thf\"",
  "\"tff\"", "\"tcf\"", "\"fof\"", "\"cnf\"", "\"fot\"", "\"ite\"",
  "\"let\"", "\"!>\"", "\"@\"", "\"&\"", "\"$\"", "\":\"", "\",\"",
  "\".\"", "\"+\"", "\"-\"", "\"=\"", "\"!=\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"{\"", "\"}\"", "\"|\"", "\"*\"", "\">\"", "\"<\"", "\"!\"",
  "\"~\"", "\"?\"", "\"^\"", "\"!!\"", "\"??\"", "\"@@\"", "\"<=>\"",
  "\"=>\"", "\"<=\"", "\"<~>\"", "\"~|\"", "\"~&\"", "\":=\"", "\"-->\"",
  "\"<<\"", "\"include\"", "\"integer\"", "\"real\"", "\"rational\"",
  "\"double_quoted\"", "\"lower_word\"", "\"upper_word\"",
  "\"identifier\"", "\"single_quoted\"", "$accept", "Specification",
  "Definitions", "Definition", "AnnotatedFormula", "ThfAnnotated",
  "TffAnnotated", "TcfAnnotated", "FofAnnotated", "CnfAnnotated",
  "TpiAnnotated", "Annotations", "TpiFormula", "ThfFormula",
  "ThfLogicFormula", "ThfBinaryFormula", "ThfBinaryNonassoc",
  "ThfBinaryAssoc", "ThfOrFormula", "ThfAndFormula", "ThfApplyFormula",
  "ThfUnitFormula", "ThfPreunitFormula", "ThfUnitaryFormula",
  "ThfQuantifiedFormula", "ThfQuantification", "ThfVariableList",
  "ThfTypedVariable", "ThfUnaryFormula", "ThfPrefixUnary", "ThfInfixUnary",
  "ThfAtomicFormula", "ThfPlainAtomic", "ThfDefinedAtomic",
  "ThfDefinedInfix", "ThfSystemAtomic", "ThfFofFunction", "ThfConditional",
  "ThfLet", "ThfLetTypes", "ThfAtomTypingList", "ThfLetDefns",
  "ThfLetDefn", "ThfLetDefnList", "ThfUnitaryTerm", "ThfTuple",
  "ThfFormulaList", "ThfConnTerm", "ThfArguments", "ThfAtomTyping",
  "ThfTopLevelType", "ThfUnitaryType", "ThfApplyType", "ThfBinaryType",
  "ThfMappingType", "ThfXprodType", "ThfUnionType", "ThfSubtype",
  "ThfSequent", "TffFormula", "TffLogicFormula", "TffBinaryFormula",
  "TffBinaryNonassoc", "TffBinaryAssoc", "TffOrFormula", "TffAndFormula",
  "TffUnitFormula", "TffPreunitFormula", "TffUnitaryFormula",
  "TfxUnitaryFormula", "TffQuantifiedFormula", "TffVariableList",
  "TffVariable", "TffTypedVariable", "TffUnaryFormula", "TffPrefixUnary",
  "TffInfixUnary", "TffAtomicFormula", "TffPlainAtomic",
  "TffDefinedAtomic", "TffDefinedPlain", "TffDefinedInfix",
  "TffSystemAtomic", "TfxConditional", "TfxLet", "TfxLetTypes",
  "TffAtomTypingList", "TfxLetDefns", "TfxLetDefn", "TfxLetLhs",
  "TfxLetDefnList", "TffTerm", "TffUnitaryTerm", "TfxTuple",
  "TffArguments", "TffAtomTyping", "TffTopLevelType", "Tf1QuantifiedType",
  "TffMonotype", "TffUnitaryType", "TffAtomicType", "TffTypeArguments",
  "TffMappingType", "TffXprodType", "TfxTupleType", "TffTypeList",
  "TffSubtype", "TfxSequent", "TcfFormula", "TcfLogicFormula",
  "TcfQuantifiedFormula", "FofFormula", "FofLogicFormula",
  "FofBinaryFormula", "FofBinaryNonassoc", "FofBinaryAssoc",
  "FofOrFormula", "FofAndFormula", "FofUnaryFormula", "FofInfixUnary",
  "FofUnitFormula", "FofUnitaryFormula", "FofQuantifiedFormula",
  "FofVariableList", "FofAtomicFormula", "FofPlainAtomicFormula",
  "FofDefinedAtomicFormula", "FofDefinedPlainFormula",
  "FofDefinedInfixFormula", "FofSystemAtomicFormula", "FofPlainTerm",
  "FofDefinedTerm", "FofDefinedAtomicTerm", "FofDefinedPlainTerm",
  "FofSystemTerm", "FofArguments", "FofTerm", "FofFunctionTerm",
  "FofSequent", "FofFormulaTuple", "FofFormulaTupleList", "CnfFormula",
  "Disjunction", "Literal", "ThfQuantifier", "Th1Quantifier",
  "Th0Quantifier", "ThfUnaryConnective", "Th1UnaryConnective",
  "FofQuantifier", "NonassocConnective", "AssocConnective",
  "UnaryConnective", "TypeConstant", "TypeFunctor", "DefinedType", "Atom",
  "UntypedAtom", "DefinedInfixPred", "InfixEquality", "InfixInequality",
  "Constant", "Functor", "SystemConstant", "SystemFunctor",
  "DefinedConstant", "DefinedFunctor", "DefinedTerm", "NameList", "Name",
  "FormulaRole", "GeneralTerm", "GeneralData", "GeneralFunction",
  "GeneralTerms", "FormulaData", "GeneralList", "IncludeDefinition",
  "FormulaSelection", "AtomicWord", "AtomicDefinedWord",
  "AtomicSystemWord", "Number", "FileName", "IntegerLiteral",
  "RealLiteral", "RationalLiteral", "Variable", "DistinctObjectLiteral",
  "LowerWordLiteral", "SingleQuotedLiteral", "DollarWordLiteral",
  "DollarDollarWordLiteral", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   320,   320,   327,   333,   343,   347,   354,   358,   362,
     366,   370,   374,   390,   393,   398,   401,   406,   409,   414,
     421,   433,   436,   441,   444,   487,   492,   522,   529,   532,
     535,   538,   544,   547,   550,   553,   559,   562,   565,   571,
     577,   580,   583,   589,   592,   598,   601,   607,   610,   616,
     619,   622,   628,   631,   637,   640,   643,   646,   652,   658,
     664,   667,   673,   679,   682,   688,   694,   700,   703,   706,
     709,   715,   718,   724,   727,   730,   733,   736,   742,   748,
     754,   757,   760,   766,   772,   778,   781,   787,   790,   796,
     799,   805,   811,   814,   820,   823,   826,   832,   835,   841,
     844,   850,   853,   856,   859,   865,   871,   874,   880,   883,
     886,   892,   898,   904,   907,   910,   916,   919,   925,   928,
     934,   937,   943,   949,   952,   959,   963,   967,   971,   978,
     982,   986,   990,   997,  1001,  1008,  1015,  1019,  1026,  1031,
    1039,  1044,  1052,  1056,  1060,  1067,  1071,  1078,  1082,  1086,
    1090,  1100,  1107,  1115,  1122,  1132,  1136,  1143,  1154,  1158,
    1165,  1172,  1179,  1183,  1187,  1194,  1198,  1205,  1212,  1216,
    1220,  1224,  1231,  1238,  1242,  1249,  1256,  1263,  1267,  1274,
    1280,  1290,  1294,  1301,  1308,  1312,  1319,  1325,  1335,  1339,
    1343,  1350,  1354,  1358,  1362,  1366,  1376,  1380,  1387,  1393,
    1403,  1407,  1417,  1421,  1425,  1429,  1439,  1446,  1450,  1460,
    1464,  1474,  1478,  1482,  1487,  1491,  1498,  1503,  1513,  1520,
    1524,  1531,  1538,  1544,  1554,  1561,  1565,  1576,  1579,  1585,
    1588,  1594,  1602,  1606,  1613,  1617,  1621,  1628,  1632,  1639,
    1646,  1650,  1657,  1662,  1670,  1675,  1683,  1687,  1694,  1701,
    1705,  1712,  1716,  1720,  1730,  1738,  1745,  1755,  1759,  1763,
    1770,  1777,  1781,  1788,  1795,  1802,  1809,  1813,  1820,  1824,
    1831,  1838,  1842,  1849,  1853,  1860,  1866,  1876,  1880,  1887,
    1891,  1895,  1902,  1906,  1915,  1919,  1926,  1932,  1942,  1946,
    1956,  1960,  1968,  1972,  1977,  1984,  1987,  1990,  1996,  1999,
    2005,  2008,  2011,  2017,  2020,  2026,  2029,  2032,  2035,  2038,
    2044,  2050,  2061,  2065,  2069,  2073,  2077,  2081,  2088,  2092,
    2099,  2106,  2113,  2120,  2127,  2131,  2138,  2142,  2149,  2156,
    2163,  2171,  2178,  2185,  2192,  2199,  2206,  2213,  2217,  2224,
    2232,  2244,  2248,  2255,  2262,  2266,  2270,  2277,  2281,  2285,
    2289,  2293,  2297,  2306,  2314,  2320,  2339,  2342,  2345,  2348,
    2351,  2357,  2362,  2371,  2376,  2383,  2411,  2415,  2422,  2429,
    2436,  2440,  2444,  2451,  2458,  2465,  2471,  2478,  2487,  2494,
    2501,  2508,  2515
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
#line 6296 "GrammarParser.cpp" // lalr1.cc:1217
#line 2521 "../../obj/src/GrammarParser.yy" // lalr1.cc:1218


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

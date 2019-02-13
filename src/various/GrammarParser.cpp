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
#line 86 "../../obj/src/GrammarParser.yy" // lalr1.cc:437

    // #include <libtptp/ ... >
	//TODO: @moosbruggerj remove temporary includes
	#include <libtptp/General>

    //#include "../../src/SourceLocation.h"
    #include "../../src/Lexer.h"
    #include "../../src/various/GrammarToken.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

	static const auto uToken = std::make_shared<Token>(Grammar::Token::UNRESOLVED );
    // static Lexer helper functions shall be located here 

#line 63 "GrammarParser.cpp" // lalr1.cc:437


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
#line 158 "GrammarParser.cpp" // lalr1.cc:512

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
      case 67: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 58: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // AnnotatedFormula
      case 64: // FofAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 226: // FormulaRole
        value.YY_MOVE_OR_COPY< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 227: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 225: // Name
      case 239: // FileName
      case 243: // Variable
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 240: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 224: // NameList
      case 230: // GeneralTerms
        value.YY_MOVE_OR_COPY< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 241: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 57: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // AtomicWord
      case 244: // DistinctObjectLiteral
      case 245: // LowerWordLiteral
      case 246: // SingleQuotedLiteral
        value.YY_MOVE_OR_COPY< StringLiteral::Ptr > (YY_MOVE (that.value));
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
      case 19: // "-"
      case 20: // "="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "<"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "^"
      case 35: // "!!"
      case 36: // "??"
      case 37: // "@@"
      case 38: // "<=>"
      case 39: // "=>"
      case 40: // "<="
      case 41: // "<~>"
      case 42: // "~|"
      case 43: // "~&"
      case 44: // ":="
      case 45: // "-->"
      case 46: // "<<"
      case 47: // "include"
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
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
      case 67: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 59: // Definition
        value.move< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 58: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 60: // AnnotatedFormula
      case 64: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 226: // FormulaRole
        value.move< FormulaRole::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 227: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 225: // Name
      case 239: // FileName
      case 243: // Variable
        value.move< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 240: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 224: // NameList
      case 230: // GeneralTerms
        value.move< Nodes::Ptr > (YY_MOVE (that.value));
        break;

      case 242: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 241: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 57: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 235: // AtomicWord
      case 244: // DistinctObjectLiteral
      case 245: // LowerWordLiteral
      case 246: // SingleQuotedLiteral
        value.move< StringLiteral::Ptr > (YY_MOVE (that.value));
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
      case 19: // "-"
      case 20: // "="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "<"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "^"
      case 35: // "!!"
      case 36: // "??"
      case 37: // "@@"
      case 38: // "<=>"
      case 39: // "=>"
      case 40: // "<="
      case 41: // "<~>"
      case 42: // "~|"
      case 43: // "~&"
      case 44: // ":="
      case 45: // "-->"
      case 46: // "<<"
      case 47: // "include"
        value.move< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
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
      case 67: // Annotations
        value.move< Annotation::Ptr > (that.value);
        break;

      case 59: // Definition
        value.move< Definition::Ptr > (that.value);
        break;

      case 58: // Definitions
        value.move< Definitions::Ptr > (that.value);
        break;

      case 60: // AnnotatedFormula
      case 64: // FofAnnotated
        value.move< FormulaDefinition::Ptr > (that.value);
        break;

      case 226: // FormulaRole
        value.move< FormulaRole::Ptr > (that.value);
        break;

      case 228: // GeneralData
        value.move< GeneralData::Ptr > (that.value);
        break;

      case 229: // GeneralFunction
        value.move< GeneralFunction::Ptr > (that.value);
        break;

      case 232: // GeneralList
        value.move< GeneralList::Ptr > (that.value);
        break;

      case 227: // GeneralTerm
        value.move< GeneralTerm::Ptr > (that.value);
        break;

      case 225: // Name
      case 239: // FileName
      case 243: // Variable
        value.move< Identifier::Ptr > (that.value);
        break;

      case 233: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (that.value);
        break;

      case 240: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (that.value);
        break;

      case 234: // FormulaSelection
        value.move< ListLiteral::Ptr > (that.value);
        break;

      case 224: // NameList
      case 230: // GeneralTerms
        value.move< Nodes::Ptr > (that.value);
        break;

      case 242: // RationalLiteral
        value.move< RationalLiteral::Ptr > (that.value);
        break;

      case 241: // RealLiteral
        value.move< RealLiteral::Ptr > (that.value);
        break;

      case 57: // Specification
        value.move< Specification::Ptr > (that.value);
        break;

      case 235: // AtomicWord
      case 244: // DistinctObjectLiteral
      case 245: // LowerWordLiteral
      case 246: // SingleQuotedLiteral
        value.move< StringLiteral::Ptr > (that.value);
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
      case 19: // "-"
      case 20: // "="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "<"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "^"
      case 35: // "!!"
      case 36: // "??"
      case 37: // "@@"
      case 38: // "<=>"
      case 39: // "=>"
      case 40: // "<="
      case 41: // "<~>"
      case 42: // "~|"
      case 43: // "~&"
      case 44: // ":="
      case 45: // "-->"
      case 46: // "<<"
      case 47: // "include"
        value.move< Token::Ptr > (that.value);
        break;

      case 238: // Number
        value.move< ValueLiteral::Ptr > (that.value);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
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
      case 67: // Annotations
        yylhs.value.emplace< Annotation::Ptr > ();
        break;

      case 59: // Definition
        yylhs.value.emplace< Definition::Ptr > ();
        break;

      case 58: // Definitions
        yylhs.value.emplace< Definitions::Ptr > ();
        break;

      case 60: // AnnotatedFormula
      case 64: // FofAnnotated
        yylhs.value.emplace< FormulaDefinition::Ptr > ();
        break;

      case 226: // FormulaRole
        yylhs.value.emplace< FormulaRole::Ptr > ();
        break;

      case 228: // GeneralData
        yylhs.value.emplace< GeneralData::Ptr > ();
        break;

      case 229: // GeneralFunction
        yylhs.value.emplace< GeneralFunction::Ptr > ();
        break;

      case 232: // GeneralList
        yylhs.value.emplace< GeneralList::Ptr > ();
        break;

      case 227: // GeneralTerm
        yylhs.value.emplace< GeneralTerm::Ptr > ();
        break;

      case 225: // Name
      case 239: // FileName
      case 243: // Variable
        yylhs.value.emplace< Identifier::Ptr > ();
        break;

      case 233: // IncludeDefinition
        yylhs.value.emplace< IncludeDefinition::Ptr > ();
        break;

      case 240: // IntegerLiteral
        yylhs.value.emplace< IntegerLiteral::Ptr > ();
        break;

      case 234: // FormulaSelection
        yylhs.value.emplace< ListLiteral::Ptr > ();
        break;

      case 224: // NameList
      case 230: // GeneralTerms
        yylhs.value.emplace< Nodes::Ptr > ();
        break;

      case 242: // RationalLiteral
        yylhs.value.emplace< RationalLiteral::Ptr > ();
        break;

      case 241: // RealLiteral
        yylhs.value.emplace< RealLiteral::Ptr > ();
        break;

      case 57: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
        break;

      case 235: // AtomicWord
      case 244: // DistinctObjectLiteral
      case 245: // LowerWordLiteral
      case 246: // SingleQuotedLiteral
        yylhs.value.emplace< StringLiteral::Ptr > ();
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
      case 19: // "-"
      case 20: // "="
      case 21: // "("
      case 22: // ")"
      case 23: // "["
      case 24: // "]"
      case 25: // "{"
      case 26: // "}"
      case 27: // "|"
      case 28: // "*"
      case 29: // ">"
      case 30: // "<"
      case 31: // "!"
      case 32: // "~"
      case 33: // "?"
      case 34: // "^"
      case 35: // "!!"
      case 36: // "??"
      case 37: // "@@"
      case 38: // "<=>"
      case 39: // "=>"
      case 40: // "<="
      case 41: // "<~>"
      case 42: // "~|"
      case 43: // "~&"
      case 44: // ":="
      case 45: // "-->"
      case 46: // "<<"
      case 47: // "include"
        yylhs.value.emplace< Token::Ptr > ();
        break;

      case 238: // Number
        yylhs.value.emplace< ValueLiteral::Ptr > ();
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
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
#line 249 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      m_specification.setDefinitions( yystack_[0].value.as< Definitions::Ptr > () );
  }
#line 1125 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 3:
#line 256 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = yystack_[1].value.as< Definitions::Ptr > ();
    definitions->add(yystack_[0].value.as< Definition::Ptr > ());
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 1135 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 4:
#line 262 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    const auto definitions = make< Definitions >( yylhs.location );
    definitions->add( yystack_[0].value.as< Definition::Ptr > () );
    yylhs.value.as< Definitions::Ptr > () = definitions;
  }
#line 1145 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 5:
#line 272 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< FormulaDefinition::Ptr > ();
  }
#line 1153 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 6:
#line 276 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      yylhs.value.as< Definition::Ptr > () = yystack_[0].value.as< IncludeDefinition::Ptr > ();
  }
#line 1161 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 7:
#line 283 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 8:
#line 287 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1177 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 9:
#line 291 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1185 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 10:
#line 295 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 11:
#line 299 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1201 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 12:
#line 303 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1
  }
#line 1209 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 13:
#line 319 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1216 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 14:
#line 322 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1223 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 15:
#line 327 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1230 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 16:
#line 330 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1237 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 17:
#line 335 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1244 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 18:
#line 338 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1251 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 19:
#line 343 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[8].value.as< Token::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< Identifier::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< FormulaRole::Ptr > (), yystack_[3].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 1262 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 20:
#line 350 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj fix me
	auto logic = libtptp::make< UnitaryLogic >(yylhs.location);
	auto formula = libtptp::make< FirstOrderFormula >(yylhs.location, logic);
	yylhs.value.as< FormulaDefinition::Ptr > () = libtptp::make< FormulaDefinition >(yylhs.location, yystack_[10].value.as< Token::Ptr > (), yystack_[9].value.as< Token::Ptr > (), yystack_[8].value.as< Identifier::Ptr > (), yystack_[7].value.as< Token::Ptr > (), yystack_[6].value.as< FormulaRole::Ptr > (), yystack_[5].value.as< Token::Ptr > (), formula, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	auto annotation = yystack_[2].value.as< Annotation::Ptr > ();
	annotation->setDelimiter(yystack_[3].value.as< Token::Ptr > ());
	formula->setAnnotations(annotation);
  }
#line 1276 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 21:
#line 362 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1283 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 22:
#line 365 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1290 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 23:
#line 370 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1297 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 24:
#line 373 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1304 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 25:
#line 416 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[0].value.as< GeneralTerm::Ptr > ());
    //source
  }
#line 1313 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 26:
#line 421 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source, optionalInfo
	yylhs.value.as< Annotation::Ptr > () = libtptp::make< Annotation >(yylhs.location, yystack_[2].value.as< GeneralTerm::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralList::Ptr > ());
  }
#line 1322 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 27:
#line 451 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1329 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 28:
#line 457 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1336 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 29:
#line 460 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1343 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 30:
#line 463 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1350 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 31:
#line 466 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1357 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 32:
#line 472 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1364 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 33:
#line 475 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1371 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 34:
#line 478 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1378 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 35:
#line 481 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1385 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 36:
#line 487 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1392 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 37:
#line 490 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1399 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 38:
#line 493 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1406 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 39:
#line 499 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1413 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 40:
#line 505 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1420 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 41:
#line 508 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1427 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 42:
#line 511 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1434 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 43:
#line 517 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1441 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 44:
#line 520 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1448 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 45:
#line 526 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1455 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 46:
#line 529 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1462 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 47:
#line 535 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1469 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 48:
#line 538 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1476 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 49:
#line 544 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1483 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 50:
#line 547 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1490 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 51:
#line 550 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1497 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 52:
#line 556 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1504 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 53:
#line 559 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1511 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 54:
#line 565 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1518 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 55:
#line 568 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1525 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 56:
#line 571 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1532 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 57:
#line 574 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1539 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 58:
#line 580 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1546 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 59:
#line 586 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1553 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 60:
#line 592 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1560 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 61:
#line 595 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1567 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 62:
#line 601 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1574 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 63:
#line 607 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1581 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 64:
#line 610 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1588 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 65:
#line 616 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1595 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 66:
#line 622 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1602 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 67:
#line 628 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1609 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 68:
#line 631 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1616 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 69:
#line 634 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1623 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 70:
#line 637 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1630 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 71:
#line 643 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1637 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 72:
#line 646 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1644 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 73:
#line 652 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1651 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 74:
#line 655 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1658 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 75:
#line 658 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1665 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 76:
#line 661 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1672 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 77:
#line 664 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1679 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 78:
#line 670 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1686 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 79:
#line 676 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1693 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 80:
#line 682 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1700 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 81:
#line 685 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1707 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 82:
#line 688 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1714 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 83:
#line 694 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1721 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 84:
#line 700 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1728 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 85:
#line 706 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1735 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 86:
#line 709 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1742 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 87:
#line 715 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1749 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 88:
#line 718 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1756 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 89:
#line 724 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1763 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 90:
#line 727 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1770 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 91:
#line 733 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1777 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 92:
#line 739 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1784 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 93:
#line 742 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1791 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 94:
#line 748 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1798 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 95:
#line 751 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1805 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 96:
#line 754 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1812 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 97:
#line 760 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1819 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 98:
#line 763 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1826 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 99:
#line 769 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1833 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 100:
#line 772 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1840 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 101:
#line 778 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1847 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 102:
#line 781 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1854 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 103:
#line 784 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1861 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 104:
#line 787 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1868 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 105:
#line 793 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1875 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 106:
#line 799 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1882 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 107:
#line 802 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1889 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 108:
#line 808 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1896 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 109:
#line 811 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1903 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 110:
#line 814 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1910 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 111:
#line 820 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1917 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 112:
#line 826 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1924 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 113:
#line 832 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1931 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 114:
#line 835 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1938 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 115:
#line 838 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1945 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 116:
#line 844 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1952 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 117:
#line 847 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1959 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 118:
#line 853 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1966 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 119:
#line 856 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1973 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 120:
#line 862 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1980 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 121:
#line 865 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1987 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 122:
#line 871 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1994 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 123:
#line 877 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2001 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 124:
#line 880 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2008 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 125:
#line 887 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2015 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 126:
#line 890 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2022 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 127:
#line 893 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2029 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 128:
#line 896 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2036 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 129:
#line 902 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2043 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 130:
#line 905 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2050 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 131:
#line 908 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2057 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 132:
#line 911 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2064 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 133:
#line 917 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2071 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 134:
#line 920 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2078 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 135:
#line 926 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2085 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 136:
#line 932 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2092 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 137:
#line 935 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2099 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 138:
#line 941 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2106 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 139:
#line 944 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2113 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 140:
#line 950 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2120 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 141:
#line 953 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2127 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 142:
#line 959 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2134 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 143:
#line 962 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2141 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 144:
#line 965 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2148 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 145:
#line 971 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2155 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 146:
#line 974 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2162 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 147:
#line 980 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 148:
#line 983 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2176 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 149:
#line 986 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2183 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 150:
#line 989 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2190 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 151:
#line 995 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2197 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 152:
#line 1001 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2204 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 153:
#line 1007 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2211 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 154:
#line 1010 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2218 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 155:
#line 1016 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2225 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 156:
#line 1019 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2232 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 157:
#line 1025 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2239 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 158:
#line 1031 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2246 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 159:
#line 1034 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2253 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 160:
#line 1040 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2260 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 161:
#line 1046 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2267 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 162:
#line 1052 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2274 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 163:
#line 1055 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2281 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 164:
#line 1058 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2288 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 165:
#line 1064 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2295 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 166:
#line 1067 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2302 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 167:
#line 1073 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2309 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 168:
#line 1079 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2316 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 169:
#line 1082 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2323 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 170:
#line 1085 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2330 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 171:
#line 1088 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2337 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 172:
#line 1094 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2344 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 173:
#line 1100 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2351 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 174:
#line 1103 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2358 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 175:
#line 1109 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2365 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 176:
#line 1115 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2372 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 177:
#line 1121 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2379 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 178:
#line 1124 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2386 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 179:
#line 1130 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2393 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 180:
#line 1133 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2400 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 181:
#line 1139 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2407 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 182:
#line 1142 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2414 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 183:
#line 1148 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2421 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 184:
#line 1154 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2428 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 185:
#line 1157 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2435 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 186:
#line 1163 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2442 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 187:
#line 1166 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2449 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 188:
#line 1172 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2456 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 189:
#line 1175 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2463 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 190:
#line 1178 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2470 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 191:
#line 1184 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2477 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 192:
#line 1187 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2484 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 193:
#line 1190 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2491 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 194:
#line 1193 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2498 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 195:
#line 1196 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2505 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 196:
#line 1202 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2512 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 197:
#line 1205 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2519 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 198:
#line 1211 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2526 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 199:
#line 1214 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2533 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 200:
#line 1220 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2540 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 201:
#line 1223 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2547 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 202:
#line 1229 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2554 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 203:
#line 1232 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2561 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 204:
#line 1235 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2568 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 205:
#line 1238 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2575 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 206:
#line 1244 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2582 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 207:
#line 1250 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2589 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 208:
#line 1253 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2596 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 209:
#line 1259 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2603 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 210:
#line 1262 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2610 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 211:
#line 1268 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2617 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 212:
#line 1271 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2624 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 213:
#line 1274 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2631 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 214:
#line 1277 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2638 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 215:
#line 1280 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2645 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 216:
#line 1286 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2652 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 217:
#line 1289 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2659 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 218:
#line 1295 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2666 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 219:
#line 1301 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2673 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 220:
#line 1304 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2680 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 221:
#line 1310 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2687 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 222:
#line 1316 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2694 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 223:
#line 1319 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2701 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 224:
#line 1325 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2708 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 225:
#line 1331 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2715 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 226:
#line 1334 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2722 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 227:
#line 1341 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2729 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 228:
#line 1344 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2736 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 229:
#line 1350 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2743 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 230:
#line 1353 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2750 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 231:
#line 1359 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2757 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 232:
#line 1367 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2764 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 233:
#line 1370 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2771 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 234:
#line 1376 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2778 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 235:
#line 1379 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2785 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 236:
#line 1382 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2792 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 237:
#line 1388 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2799 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 238:
#line 1391 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2806 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 239:
#line 1397 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2813 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 240:
#line 1403 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2820 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 241:
#line 1406 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2827 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 242:
#line 1412 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2834 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 243:
#line 1415 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2841 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 244:
#line 1421 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2848 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 245:
#line 1424 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2855 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 246:
#line 1430 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2862 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 247:
#line 1433 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2869 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 248:
#line 1439 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2876 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 249:
#line 1445 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2883 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 250:
#line 1448 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2890 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 251:
#line 1454 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2897 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 252:
#line 1457 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2904 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 253:
#line 1460 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2911 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 254:
#line 1466 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2918 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 255:
#line 1472 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2925 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 256:
#line 1475 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2932 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 257:
#line 1481 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2939 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 258:
#line 1484 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2946 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 259:
#line 1487 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2953 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 260:
#line 1493 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2960 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 261:
#line 1499 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2967 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 262:
#line 1502 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2974 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 263:
#line 1508 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2981 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 264:
#line 1514 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2988 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 265:
#line 1520 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2995 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 266:
#line 1526 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3002 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 267:
#line 1529 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3009 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 268:
#line 1535 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3016 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 269:
#line 1538 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3023 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 270:
#line 1544 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3030 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 271:
#line 1550 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3037 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 272:
#line 1553 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3044 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 273:
#line 1559 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3051 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 274:
#line 1562 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3058 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 275:
#line 1568 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3065 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 276:
#line 1571 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3072 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 277:
#line 1577 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3079 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 278:
#line 1580 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3086 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 279:
#line 1586 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3093 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 280:
#line 1589 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3100 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 281:
#line 1592 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3107 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 282:
#line 1598 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3114 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 283:
#line 1601 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3121 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 284:
#line 1607 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3128 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 285:
#line 1610 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3135 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 286:
#line 1616 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3142 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 287:
#line 1619 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3149 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 288:
#line 1625 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3156 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 289:
#line 1628 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3163 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 290:
#line 1634 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3170 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 291:
#line 1637 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3177 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 292:
#line 1643 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3184 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 293:
#line 1646 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3191 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 294:
#line 1649 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3198 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 295:
#line 1655 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3205 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 296:
#line 1658 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3212 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 297:
#line 1661 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3219 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 298:
#line 1667 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3226 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 299:
#line 1670 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3233 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 300:
#line 1676 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3240 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 301:
#line 1679 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3247 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 302:
#line 1682 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3254 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 303:
#line 1688 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3261 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 304:
#line 1691 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3268 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 305:
#line 1697 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3275 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 306:
#line 1700 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3282 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 307:
#line 1703 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3289 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 308:
#line 1706 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3296 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 309:
#line 1709 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3303 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 310:
#line 1715 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3310 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 311:
#line 1718 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3317 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 312:
#line 1726 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3324 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 313:
#line 1729 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3331 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 314:
#line 1732 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3338 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 315:
#line 1735 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3345 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 316:
#line 1738 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3352 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 317:
#line 1741 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3359 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 318:
#line 1747 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3366 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 319:
#line 1750 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3373 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 320:
#line 1756 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3380 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 321:
#line 1762 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3387 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 322:
#line 1768 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3394 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 323:
#line 1774 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3401 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 324:
#line 1780 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3408 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 325:
#line 1783 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3415 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 326:
#line 1789 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3422 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 327:
#line 1792 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3429 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 328:
#line 1798 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3436 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 329:
#line 1804 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3443 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 330:
#line 1810 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3450 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 331:
#line 1816 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3457 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 332:
#line 1822 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3464 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 333:
#line 1828 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3471 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 334:
#line 1834 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3478 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 335:
#line 1840 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3485 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 336:
#line 1846 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3492 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 337:
#line 1852 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3499 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 338:
#line 1855 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3506 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 339:
#line 1861 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj change to identifiers list
	//const auto list = libtptp::make< Identifiers >(@$);
	const auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< Identifier::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3518 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 340:
#line 1869 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj add delimiter
	const auto list = yystack_[2].value.as< Nodes::Ptr > ();
	const auto name = yystack_[0].value.as< Identifier::Ptr > ();
	//name->prefix().add($2); //setDelimiter
	list->add(name);
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3531 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 341:
#line 1881 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 3539 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 342:
#line 1885 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, yystack_[0].value.as< IntegerLiteral::Ptr > ());
  }
#line 3547 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 343:
#line 1892 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< FormulaRole::Ptr > () = libtptp::make< FormulaRole >( yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > () );
  }
#line 3555 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 344:
#line 1899 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralData::Ptr > ();
  }
#line 3563 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 345:
#line 1903 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = libtptp::make< GeneralAggregator >(yylhs.location, yystack_[2].value.as< GeneralData::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< GeneralTerm::Ptr > ());
  }
#line 3571 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 346:
#line 1907 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralTerm::Ptr > () = yystack_[0].value.as< GeneralList::Ptr > ();
  }
#line 3579 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 347:
#line 1914 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 3587 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 348:
#line 1918 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< GeneralFunction::Ptr > ());
  }
#line 3595 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 349:
#line 1922 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< Identifier::Ptr > ());
  }
#line 3603 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 350:
#line 1926 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< ValueLiteral::Ptr > ());
  }
#line 3611 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 351:
#line 1930 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 3619 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 352:
#line 1934 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//$$ = libtptp::make< GeneralData >(@$, $1);
	//TODO: @moosbruggerj remove wrong token
	yylhs.value.as< GeneralData::Ptr > () = libtptp::make< GeneralData >(yylhs.location, uToken);
  }
#line 3629 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 353:
#line 1943 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto name = libtptp::make< Identifier >(yystack_[3].location, yystack_[3].value.as< StringLiteral::Ptr > ());
	yylhs.value.as< GeneralFunction::Ptr > () = libtptp::make< GeneralFunction >(yylhs.location, name, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3638 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 354:
#line 1951 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< Nodes >(yylhs.location);
	list->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
	yylhs.value.as< Nodes::Ptr > () = list;
  }
#line 3648 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 355:
#line 1957 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	//TODO: @moosbruggerj use comma
	
    auto terms = yystack_[2].value.as< Nodes::Ptr > ();
    terms->add(yystack_[0].value.as< GeneralTerm::Ptr > ());
    yylhs.value.as< Nodes::Ptr > () = terms;
  }
#line 3660 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 356:
#line 1976 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3667 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 357:
#line 1979 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3674 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 358:
#line 1982 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3681 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 359:
#line 1985 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3688 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 360:
#line 1988 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3695 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 361:
#line 1994 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 3704 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 362:
#line 1999 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< GeneralList::Ptr > () = libtptp::make< GeneralList >(yylhs.location, list);
  }
#line 3713 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 363:
#line 2008 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	const auto formulaSelection = libtptp::make< ListLiteral >(yystack_[0].location, uToken, uToken);
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[4].value.as< Token::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< Identifier::Ptr > (), uToken, formulaSelection, yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3722 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 364:
#line 2013 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IncludeDefinition::Ptr > () = libtptp::make< IncludeDefinition >(yylhs.location, yystack_[6].value.as< Token::Ptr > (), yystack_[5].value.as< Token::Ptr > (), yystack_[4].value.as< Identifier::Ptr > (), yystack_[3].value.as< Token::Ptr > (), yystack_[2].value.as< ListLiteral::Ptr > (), yystack_[1].value.as< Token::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
  }
#line 3730 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 365:
#line 2020 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto list = libtptp::make< ListLiteral >(yylhs.location, yystack_[2].value.as< Token::Ptr > (), yystack_[1].value.as< Nodes::Ptr > (), yystack_[0].value.as< Token::Ptr > ());
	yylhs.value.as< ListLiteral::Ptr > () = list;
	/*
	auto nameList = $2;
	nameList->prefix().add($1);
	nameList->suffix().add($3);
	$$ = nameList;
	*/
  }
#line 3745 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 366:
#line 2054 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 3753 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 367:
#line 2058 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = yystack_[0].value.as< StringLiteral::Ptr > ();
  }
#line 3761 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 368:
#line 2065 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3768 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 369:
#line 2071 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3775 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 370:
#line 2077 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< IntegerLiteral::Ptr > ();
  }
#line 3783 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 371:
#line 2081 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RealLiteral::Ptr > ();
  }
#line 3791 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 372:
#line 2085 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    yylhs.value.as< ValueLiteral::Ptr > () = yystack_[0].value.as< RationalLiteral::Ptr > ();
  }
#line 3799 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 373:
#line 2092 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< Identifier::Ptr > () = libtptp::make<Identifier>(yylhs.location, yystack_[0].value.as< StringLiteral::Ptr > ());
  }
#line 3807 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 374:
#line 2099 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< IntegerLiteral::Ptr > () = libtptp::make< IntegerLiteral >(yystack_[0].location, yystack_[0].value.as< std::string > ());
  }
#line 3815 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 375:
#line 2106 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RealLiteral::Ptr > () = libtptp::make< RealLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 3823 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 376:
#line 2112 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< RationalLiteral::Ptr > () = libtptp::make< RationalLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 3831 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 377:
#line 2119 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	auto literal = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
	yylhs.value.as< Identifier::Ptr > () = libtptp::make< Identifier >(yylhs.location, literal, true);
  }
#line 3840 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 378:
#line 2127 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 3848 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 379:
#line 2134 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 3856 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 380:
#line 2141 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
	yylhs.value.as< StringLiteral::Ptr > () = libtptp::make< StringLiteral >(yylhs.location, yystack_[0].value.as< std::string > ());
  }
#line 3864 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 381:
#line 2148 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3871 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 382:
#line 2154 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 3878 "GrammarParser.cpp" // lalr1.cc:906
    break;


#line 3882 "GrammarParser.cpp" // lalr1.cc:906
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


  const short Parser::yypact_ninf_ = -598;

  const short Parser::yytable_ninf_ = -328;

  const short
  Parser::yypact_[] =
  {
     435,    29,    81,    84,   131,   214,   229,   231,    41,   435,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   557,
     557,   557,   557,   557,   557,   200,  -598,  -598,  -598,  -598,
    -598,   302,  -598,  -598,  -598,  -598,   338,   345,   369,   411,
     431,   104,  -598,   319,   319,   319,   319,   319,   319,   436,
     447,   463,  -598,   474,   476,   507,   509,   511,   557,   514,
    -598,   798,  1219,  1490,   758,   798,   948,    87,  -598,   521,
      20,   798,  1530,  -598,  -598,  -598,  -598,  -598,  -598,  -598,
     329,  -598,  -598,  -598,  -598,  -598,   532,   549,   482,  -598,
     944,   491,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   168,
    -598,  -598,   261,   286,   303,  -598,  -598,   519,   558,  1576,
    -598,   578,  -598,   583,  -598,   610,  -598,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   663,   137,
     903,   831,   619,   623,  -598,  -598,  -598,   362,   368,  -598,
    -598,  -598,  -598,   628,   658,   661,  1119,  1089,  -598,  1261,
     428,  -598,  -598,   316,  -598,  -598,   475,  -598,  -598,  -598,
    -598,   303,   650,  -598,   144,  -598,  -598,   672,   698,  -598,
    -598,   712,  -598,  -598,  1307,  -598,  -598,  -598,   141,   148,
     716,   210,   721,  -598,   725,  -598,   343,   235,  1490,  1120,
     585,  -598,  -598,  -598,  -598,   730,   763,  1448,   277,  -598,
    -598,   441,  -598,  -598,   355,  -598,  -598,  -598,   504,  -598,
    -598,  -598,   303,   726,  -598,  -598,  -598,   755,   876,   258,
     148,   764,   210,   767,  -598,   778,  -598,   358,  1037,   779,
    1186,  -598,   600,  -598,  -598,  -598,  -598,  -598,   774,  -598,
     788,   789,   805,   603,   699,   604,   557,  -598,  -598,   319,
    -598,   799,   806,  1576,  -598,  -598,   243,  1607,   818,  1576,
    1576,  1576,  1576,  -598,  -598,  -598,  -598,  -598,  -598,  1576,
    -598,   817,  1186,  -598,  1186,   815,   791,  -598,  -598,  -598,
    1186,  1186,  1186,  -598,  -598,  -598,   820,   821,  -598,  -598,
     836,   837,   838,   839,  1307,  -598,  -598,   854,  -598,  1172,
    -598,  -598,  -598,   122,  -598,  -598,  -598,  -598,  -598,  -598,
    1607,   855,  1261,  1261,  1261,  1261,  1261,  1261,  1261,  -598,
    -598,  -598,  -598,  1388,  1388,   848,  1026,  1026,  1026,  1026,
    1026,   791,  1172,  -598,  -598,  -598,  -598,  -598,  1261,    72,
    1261,  1261,  1261,   852,   853,   863,   867,   869,  1543,  -598,
    -598,  -598,   374,   198,  -598,  -598,   383,  1607,   858,  1543,
    1543,  1543,  1543,  1543,  1563,  1563,   871,   791,  1543,  -598,
    -598,  -598,  -598,  -598,   403,    72,  1543,  1543,  1543,   215,
      26,   791,  -598,   856,  1607,   860,   699,  1607,   875,  1607,
     878,  -598,  -598,  -598,  -598,  1576,  -598,   751,  1596,   874,
     882,   884,  -598,  -598,  -598,   879,  -598,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,   278,  -598,   605,  -598,   620,   653,  1261,   307,
     384,  -598,  -598,  -598,  1261,  -598,   880,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,  -598,  1172,  -598,  -598,  -598,  -598,
    -598,   389,  -598,  -598,  -598,   877,  -598,  -598,  -598,   342,
    -598,   888,   889,   661,   892,   900,  -598,   877,  -598,  -598,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   898,   896,
     897,   899,  1543,   501,   400,  -598,  -598,  -598,  1543,  -598,
     905,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,
    1543,  -598,  -598,  -598,  -598,  -598,   409,  -598,  -598,   910,
     911,   319,   403,   403,   909,  -598,  -598,   891,   446,  -598,
    -598,  -598,   926,  -598,  -598,  -598,  -598,  -598,   654,   662,
     681,   934,  -598,   438,   937,  -598,  -598,   938,  -598,   941,
    -598,  -598,   947,   949,   951,   952,   953,  -598,  -598,   479,
     958,   942,  1607,  1607,   791,   961,  1186,  -598,  -598,  -598,
     962,   230,   230,   972,  -598,  -598,   960,   968,   791,   977,
    1261,  -598,  -598,  -598,  -598,   978,   215,   979,  -598,  -598,
     976,   980,   791,   989,   157,  -598,   990,   483,   677,  -598,
     544,   791,   157,   157,  -598,  -598,  -598,   996,   998,   999,
    1000,  1219,  1490,   798,   948,  1186,  1607,  -598,  -598,  -598,
    -598,   717,  -598,  1576,  -598,  1261,   553,  -598,  1398,  -598,
    -598,  -598,  -598,  -598,  1543,   562,  -598,   112,  -598,  -598,
    -598,  1543,  -598,  -598,   157,  -598,   157,   403,  -598,   564,
    -598,  -598,   718,   948,  -598,  -598,  -598,   991,   997,  1002,
    1003,  1004,  -598,  -598,  -598,  1011,   230,  -598,   831,   984,
    1015,  -598,  1018,   215,  -598,  1120,  -598,  1021,  -598,   995,
    -598,  -598,  -598,  -598,  -598,  1029,   157,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,  1261,  -598,   984,  -598,   567,  1261,
    1219,  1543,  -598,  1001,  -598,   579,   283,  1543,  1543,   675,
    -598,  1024,  1261,  -598,  -598,  1028,  1030,   245,  -598,  1031,
    -598,   722,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,
     722,  -598,  1032,  1027,  -598
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
     337,   370,   371,   372,   278,   338,   368,   369,     0,     0,
       0,     0,   310,   311,   300,   305,   306,     0,     0,    28,
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
     329,     0,     0,   328,     0,     0,     0,   250,   246,   249,
       0,     0,     0,   301,   302,   309,     0,     0,   319,   318,
       0,     0,     0,     0,   104,   101,   102,     0,   103,     0,
      97,    99,    72,     0,    71,    79,   298,   299,   307,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      49,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    52,    53,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
     188,   198,   190,     0,   165,   173,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     145,   146,   148,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,   340,   382,   253,   283,     0,   285,     0,     0,     0,
      25,   344,   348,   352,   346,   347,   350,   349,   351,    23,
     243,   245,   244,   242,   239,   330,   279,   270,   281,   264,
     248,   282,     0,   255,     0,   275,     0,     0,     0,     0,
      57,    76,   107,   124,     0,    98,     0,    13,    44,    46,
      48,    47,    45,    43,    39,     0,    94,    78,    95,    66,
     123,     0,   111,   120,   118,   116,   117,   119,   121,     0,
      60,     0,     0,   112,     0,   111,   106,   108,   110,   109,
     122,   324,   326,   331,   327,   333,   325,   335,   105,     0,
       0,     0,     0,     0,   150,   201,   226,   193,     0,   197,
       0,    15,   139,   142,   143,   144,   141,   140,   138,   135,
       0,   191,   172,   194,   161,   225,     0,   153,   155,   156,
       0,     0,     0,     0,     0,   200,   204,     0,   202,   203,
     215,   211,   321,   212,   322,   323,   214,   224,     0,     0,
       0,     0,   289,     0,     0,    17,   291,     0,    19,     0,
      21,   287,     0,     0,     0,     0,     0,   361,   354,     0,
       0,     0,     0,     0,     0,     0,     0,   267,   274,   272,
       0,     0,     0,     0,    85,   100,     0,     0,     0,     0,
       0,    57,    80,    82,    81,     0,     0,     0,   177,   199,
       0,     0,     0,     0,     0,   150,     0,     0,     0,   222,
       0,     0,     0,     0,   166,   174,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   362,    24,    26,
     345,     0,   256,     0,   276,     0,     0,    87,     0,    14,
      96,    61,    59,    62,     0,     0,   179,     0,    16,   195,
     154,     0,   157,   205,     0,   210,     0,     0,   221,     0,
     218,   216,     0,     0,    18,    20,    22,     0,     0,     0,
       0,     0,   355,   353,   254,     0,     0,    86,     0,     0,
       0,    89,     0,     0,   178,     0,   184,     0,   181,     0,
     185,   152,   219,   220,   223,     0,     0,   213,   231,   356,
     357,   358,   359,   360,     0,    88,    99,    92,     0,     0,
       0,     0,   180,   162,   186,     0,   190,     0,     0,     0,
     217,     0,     0,    90,    91,     0,     0,     0,   182,     0,
     183,     0,   206,   207,    83,    93,    84,   175,   187,   176,
       0,   209,     0,     0,   208
  };

  const short
  Parser::yypgoto_[] =
  {
    -598,  -598,  -598,  1047,  -598,  -598,  -598,  -598,  -598,  -598,
    -598,    62,  -598,  -565,   103,  -598,  -598,  -598,  -598,  -598,
    -317,   -97,  -598,    83,  -598,  -598,  -598,   494,   171,  -144,
    -598,   396,  -598,  -598,   394,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,  -581,  -598,   305,   -30,  -116,  -598,   299,   -81,
     493,  -272,  -598,  -598,  -316,  -598,  -598,  -598,   935,   462,
      -4,  -598,  -598,  -598,  -598,  -598,  -298,  -598,  -202,  -598,
    -598,  -357,   484,  -598,  -271,   849,  -598,  -195,  -567,  -598,
    -598,  -244,  -598,  -598,  -598,  -598,  -598,  -598,  -597,  -598,
    -598,  -275,   279,   -35,   420,   -55,  -442,  -598,  -598,  -477,
      18,  -598,   360,  -598,  -598,  -598,  -598,   885,  -598,  -598,
    -598,   -51,   -45,  -598,  -598,  -598,  -598,  -598,   -84,   -46,
     -69,   -58,  -598,  -598,   -47,  -598,  -598,  -598,  -598,  -598,
    -187,  -598,  -598,  -173,  -168,   481,  -199,  -598,  1009,   797,
    -598,   -53,   -89,   696,  -598,  -598,  -598,   -93,  -598,  2168,
     -23,  -598,  2495,  -598,  -598,  -598,   708,   -56,  -132,   -92,
    -128,   405,   761,  1117,  1464,  1811,  2119,  2331,  -598,   121,
     770,  -322,  -598,  -598,   531,  -598,   540,  -598,  -598,   -19,
     202,  -598,  -161,  -598,   110,  -598,  -598,   -52,   304,    -1,
    1068,  -598,  -598
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   399,    80,   138,   301,   140,   141,   142,   143,   144,
     145,   146,   333,   147,   148,   149,   459,   460,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   563,
     616,   660,   661,   688,   161,   302,   478,   291,   479,   163,
     466,   164,   468,   165,   166,   167,   168,   169,   170,   190,
     350,   192,   193,   194,   195,   196,   197,   369,   198,   199,
     200,   506,   507,   508,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   577,   625,   667,   668,   669,
     695,   351,   212,   487,   353,   346,   515,   516,   712,   517,
     518,   642,   519,   588,   520,   590,   215,   216,   232,   233,
     234,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   422,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   424,   104,   105,   106,   107,
     256,   237,   238,   239,   171,   172,   173,   174,   175,   176,
     295,   296,   177,   521,   522,   523,   470,   240,   272,   273,
     274,   304,   180,   305,   182,   183,   184,   185,    67,    31,
      51,   400,   401,   402,   549,   403,   404,    18,    59,   117,
     118,   119,   120,    41,   121,   122,   123,   124,   125,    34,
      35,   126,   127
  };

  const short
  Parser::yytable_[] =
  {
      32,    32,    32,    32,    32,    32,   178,   219,   214,   231,
     186,   227,   456,   245,   243,   303,   370,   236,   235,   236,
     235,   463,   469,   372,   533,   277,   251,   255,   213,   323,
     335,   383,   162,   324,   249,   587,   647,   294,   298,    32,
     278,    26,    52,    52,    52,    52,    52,    52,   532,   292,
      19,   279,   319,   386,   453,   454,   455,   457,   458,   191,
     666,   492,   496,   497,   498,   499,   467,   269,   694,   250,
     586,   589,    29,   419,   297,   420,   548,   687,   186,   186,
     364,   425,   425,   425,   365,   416,    70,   416,   494,   494,
     494,   494,   494,   416,   416,   416,   406,   186,   693,   417,
     162,   417,    20,   246,   418,    21,   418,   417,   417,   417,
     718,   247,   418,   418,   418,   495,   495,   495,   495,   495,
      49,   715,   337,   318,    29,   705,    50,    30,   250,    33,
      33,    33,    33,    33,    33,   665,   227,   227,   434,   380,
     666,    36,    37,    38,    39,    40,   435,   286,   287,   406,
     335,   249,    22,   213,   352,   380,   338,   493,   493,   493,
     493,   493,   326,  -326,    29,   139,   373,    30,    33,   501,
     501,   511,   327,   328,   363,   277,   277,   277,   277,    68,
     513,   236,   235,   382,   345,   277,   250,   339,  -279,    29,
     410,   411,   412,   413,  -326,   674,   406,   236,   235,  -279,
     414,   279,   279,   279,   279,   407,   294,   298,   251,    29,
      79,   279,    30,   579,   488,   438,   439,   440,   441,   442,
     443,   444,   489,   406,   423,  -327,   406,    32,   406,   531,
     610,   548,   320,   290,   639,    23,   379,   406,   405,   294,
     298,   464,   337,   723,   531,   343,   344,   186,   392,   249,
      24,   561,    25,   463,   469,    30,  -327,   334,   407,   395,
     186,   186,   186,   186,   186,   186,   186,    29,   189,   396,
      30,   448,   448,   374,   337,   337,   337,   337,   337,   461,
     186,  -270,    29,   471,   652,    30,   186,    29,   186,   186,
     186,   405,  -270,  -129,   554,   450,   227,    29,   467,  -129,
      30,  -129,   555,  -193,   375,   407,  -281,   227,   227,   227,
     227,   227,   503,   503,  -193,   509,   227,  -281,    43,   471,
     321,   531,   526,   270,   227,   227,   227,  -185,   561,   509,
     562,   505,   407,   671,   271,   407,   -94,   407,   405,   236,
     235,   352,   352,   352,   345,   257,   407,   -94,   564,   662,
     541,   258,   294,   298,    44,   524,    33,   614,   568,    29,
     494,    45,    30,   -95,   510,   405,   569,   391,   405,   416,
     405,    29,   436,   297,   -95,  -191,   186,   334,  -194,   405,
     308,   309,   186,   417,   310,    46,  -191,   495,   418,  -194,
     311,   406,   406,   186,  -193,   320,   320,   320,   320,   320,
     320,   320,   290,  -192,   -96,  -193,   651,   283,   284,   452,
     452,   452,   452,   452,  -192,   -96,   706,   511,   416,   490,
    -195,   465,   709,   710,   512,   582,   513,    47,   578,   493,
     227,  -195,   417,   583,   514,   462,   227,   418,     1,     2,
       3,     4,     5,     6,   -33,   406,   534,    48,   227,   537,
     -33,   539,   -33,   352,   582,    29,    79,  -130,    30,    58,
     526,   526,   597,  -130,    60,  -130,   110,   179,   220,   241,
     110,   110,   -33,   464,  -209,  -209,   110,   110,   575,    61,
     292,   617,     7,   321,   321,   321,   321,   321,   321,   321,
      62,   -35,    63,   524,   524,   606,   581,   -35,  -235,   -35,
     407,   407,   612,   607,  -235,   297,   297,  -236,  -235,   321,
     250,   634,   592,  -236,   110,   531,   461,  -236,   186,   -35,
    -132,   626,   379,    64,   576,    65,  -132,    66,  -132,   277,
     509,   560,   526,   405,   405,   179,    69,   565,   248,   509,
     526,   526,   303,   322,   654,   178,   219,   214,   567,   186,
     227,   650,   649,    29,   407,   279,    30,   236,   235,   259,
     637,   408,   260,   186,   275,   524,   186,   213,   638,   656,
     336,   162,   227,   524,   524,   685,   525,   657,   663,   227,
     582,   276,   526,   702,   526,   526,   664,   405,   675,   352,
     678,   703,   670,   220,   354,   707,   236,   235,   191,   280,
     297,   357,   632,   708,   281,    28,   186,   358,   692,    29,
     640,   641,    30,   227,   408,   524,   384,   524,   524,   387,
     389,   556,   385,   354,   526,   388,   390,   557,   447,   449,
     696,   282,   186,   241,   178,   110,   556,   186,   186,   227,
     480,   481,   558,   502,   504,   227,   227,   526,   306,   110,
     186,   307,   672,   465,   673,   312,   352,   524,   110,   526,
     162,   408,   352,   352,   110,   110,   110,   110,   526,   556,
     488,   313,   670,   314,   110,   559,   594,   110,   488,   110,
     524,   283,   284,   285,   595,   110,   110,   110,   408,   511,
     336,   408,   524,   408,   700,   325,   711,   488,   513,   635,
     329,   524,   408,   596,   139,   636,   322,   322,   322,   322,
     322,   322,   322,    70,   525,   525,   330,   713,   655,   446,
     446,   659,   336,   336,   336,   336,   336,    29,    79,   721,
      30,   230,   322,   606,   676,   331,   511,   340,   721,   653,
     677,   321,   341,   720,   472,   513,   342,    28,    76,    77,
      78,    29,    79,   354,    30,   542,   543,   359,   544,   545,
     546,   686,   426,   427,   354,   354,   354,   354,   354,   354,
     354,   366,    70,   354,    29,    79,   360,    30,   367,   228,
     472,   354,   354,   354,   472,   376,   525,   701,   377,   229,
     230,   110,   704,   139,   525,   525,   528,   529,   530,   378,
     110,   386,   381,   374,  -326,   659,    28,    76,    77,    78,
      29,    79,    70,    30,    53,    54,    55,    56,    57,    71,
    -327,   393,   111,    72,   221,   111,   111,   111,   394,    73,
      74,    75,   111,   111,   472,   409,   525,   415,   525,   525,
      72,   428,   429,   128,    79,   129,    28,    76,    77,    78,
      29,    79,   299,    30,   131,   300,   408,   408,   430,   431,
     432,   433,   132,    74,   133,   134,   135,   136,   137,   338,
     111,   131,   437,   482,   483,   491,   270,   535,   525,    28,
      76,    77,    78,    29,    79,   484,    30,   354,   472,   485,
     187,   486,   538,   354,   189,   540,   550,   368,   551,   552,
     553,   525,   566,   570,   315,   354,   328,    73,    74,    75,
     408,   571,   -49,   525,   434,   128,   288,   129,   572,   573,
     592,   574,   525,   270,   130,   584,   131,   580,    29,    79,
     289,    30,   591,   585,   132,    74,   133,   134,   135,   136,
     137,   263,   264,   265,   266,   267,   268,   593,   249,   221,
     221,    28,    76,    77,    78,    29,    79,   261,    30,   598,
     599,   110,    70,   600,   322,   398,   472,   472,   601,   244,
     602,   262,   603,   604,   605,   608,   613,   619,   615,   221,
     230,   472,   263,   264,   265,   266,   267,   268,   618,   111,
     620,   111,   622,   628,   624,   627,    28,    76,    77,    78,
      29,    79,   629,    30,   631,   111,   179,   220,   110,   110,
     110,   643,   633,   679,   111,   644,   645,   646,   110,   680,
     111,   111,   111,   111,   681,   682,   683,   684,   689,   354,
     111,   690,   354,   111,   691,   111,   354,   697,   451,   698,
     129,   111,   111,   111,   699,  -184,   714,   332,   110,   131,
     716,    70,   717,   719,   724,   634,    27,   132,   379,   133,
     134,   472,   621,   623,   648,   293,   630,   371,   472,   230,
     354,   722,   421,   347,    28,    76,    77,    78,    29,    79,
     252,    30,   536,   527,   611,    28,    76,    77,    78,    29,
      79,   609,    30,    42,     0,   179,   354,     0,     0,     0,
     473,     0,   354,   354,     0,   -32,     0,  -111,     0,   221,
       0,   -32,   354,   -32,     0,     0,     0,  -111,  -111,     0,
     221,   221,   221,   221,   221,   221,   221,     0,     0,   221,
       0,   315,   316,   -32,   187,     0,   473,   221,   221,   221,
     473,   348,     0,   189,   349,     0,   317,   111,     0,     0,
       0,    73,    74,    75,     0,     0,   111,   263,   264,   265,
     266,   267,   268,     0,     0,     0,     0,     0,    28,    76,
      77,    78,    29,    79,     0,    30,     0,     0,   112,   181,
     222,   242,   112,   112,   128,   288,   129,     0,   112,   112,
     473,     0,   270,   299,     0,   131,     0,     0,     0,   289,
      70,     0,     0,   132,    74,   133,   134,   135,   136,   137,
     263,   264,   265,   266,   267,   268,     0,     0,     0,     0,
      28,    76,    77,    78,    29,    79,   112,    30,     0,     0,
       0,   128,     0,   129,    28,    76,    77,    78,    29,    79,
     130,    30,   131,   221,   473,     0,     0,   181,     0,   221,
     132,    74,   133,   134,   135,   136,   137,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,    28,    76,    77,
      78,    29,    79,   128,    30,   129,     0,     0,     0,     0,
       0,     0,   299,     0,   131,     0,     0,     0,     0,     0,
       0,     0,   132,    74,   133,   134,   135,   136,   137,     0,
       0,     0,     0,     0,     0,   222,   355,     0,     0,    28,
      76,    77,    78,    29,    79,     0,    30,   111,     0,   128,
       0,   129,   473,   473,     0,     0,     0,     0,   332,     0,
     131,     0,     0,     0,     0,   355,     0,   473,   132,    74,
     133,   134,   135,   136,   137,   242,     0,   112,     0,     0,
       0,     0,     0,     0,     0,    28,    76,    77,    78,    29,
      79,   112,    30,   221,   111,   111,   111,     0,     0,     0,
     112,     0,     0,     0,   111,     0,   112,   112,   112,   112,
       0,     0,     0,     0,     0,   221,   112,     0,   221,   112,
       0,   112,   221,     0,     0,     0,     0,   112,   112,   112,
       0,     0,   129,     0,   111,     0,     0,     0,     0,   445,
     128,   131,   129,     0,     0,     0,     0,   473,     0,   299,
       0,   658,     0,     0,   473,     0,   221,     0,     0,   132,
      74,   133,   134,   135,   136,   137,    28,    76,    77,    78,
      29,    79,     0,    30,     0,     0,    28,    76,    77,    78,
      29,    79,   221,    30,     0,     0,   474,     0,   221,   221,
       0,   361,     0,     0,     0,   355,     0,     0,   221,     0,
       0,     0,     0,     0,     0,   362,   355,   355,   355,   355,
     355,   355,   355,     0,     0,   355,   263,   264,   265,   266,
     267,   268,   474,   355,   355,   355,   474,     0,     0,     0,
       0,     0,     0,   112,   187,     0,     0,     0,     0,     0,
       0,   188,   112,   189,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,     0,   113,     0,   223,   113,   113,
     113,     0,     0,     0,     0,   113,   113,     0,    28,    76,
      77,    78,    29,    79,    70,    30,   474,     0,     0,     0,
       0,   253,     0,     0,     0,     0,   254,   187,     0,     0,
       0,    73,    74,    75,   348,     0,   189,     0,     0,     0,
       0,     0,     0,   113,    73,    74,    75,   187,    28,    76,
      77,    78,    29,    79,   500,    30,   189,     0,     0,     0,
      70,    28,    76,    77,    78,    29,    79,   253,    30,   355,
     474,     0,     0,     0,     0,   355,     0,    73,    74,    75,
     397,    28,    76,    77,    78,    29,    79,   355,    30,   398,
     547,   397,     0,     0,    28,    76,    77,    78,    29,    79,
     398,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    76,    77,    78,    29,    79,
       0,    30,   223,   223,     0,    28,    76,    77,    78,    29,
      79,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,     0,   474,   474,
       0,     0,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   474,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   181,   222,
     112,   112,   112,   113,   113,   113,   113,     0,     0,     0,
     112,     0,     0,   113,     0,     0,   113,     0,   113,     0,
       0,   355,     0,     0,   113,   113,   113,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
     474,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,     0,     0,     0,   181,   355,     0,
       0,     0,   223,     0,   355,   355,     0,     0,     0,     0,
       0,     0,     0,   223,   223,   223,   223,   223,   223,   223,
       0,     0,   223,     0,     0,     0,     0,     0,     0,   475,
     223,   223,   223,   475,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,   224,   114,   114,   114,     0,     0,
       0,     0,   114,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,   475,     0,     0,
       0,     0,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,   475,   475,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     475,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,   223,   113,   113,   113,
     114,   114,   114,   114,     0,     0,     0,   113,     0,     0,
     114,     0,     0,   114,     0,   114,     0,     0,   223,     0,
       0,   114,   114,   114,     0,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,   475,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,     0,     0,     0,     0,   223,     0,     0,     0,   224,
       0,   223,   223,     0,     0,     0,     0,     0,     0,     0,
     224,   224,   224,   224,   224,   224,   224,     0,     0,   224,
     115,     0,   225,   115,   115,   115,   476,   224,   224,   224,
     115,   115,     0,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   108,
       0,   217,     0,   108,     0,     0,     0,     0,     0,   108,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,   225,   225,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,   115,
       0,     0,     0,     0,     0,     0,   217,   217,     0,     0,
       0,     0,     0,   115,     0,     0,     0,   114,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,   115,   115,
     115,   115,     0,     0,     0,     0,   217,     0,   115,     0,
       0,   115,   116,   115,   226,   116,   116,   116,     0,   115,
     115,   115,   116,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,   114,   114,   114,     0,     0,     0,
       0,   108,     0,     0,   114,     0,     0,   108,   108,   108,
     108,     0,     0,     0,     0,   224,     0,   108,     0,     0,
     116,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,   224,     0,   225,   225,
     225,   225,   225,   225,   225,     0,     0,   225,     0,     0,
       0,     0,     0,     0,   477,   225,   225,   225,     0,     0,
       0,     0,   224,     0,     0,   115,     0,     0,   224,   224,
       0,     0,     0,     0,   115,     0,   217,     0,     0,   226,
     356,     0,     0,     0,     0,     0,     0,   217,   217,   217,
     217,   217,     0,     0,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,   217,   217,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,   218,   116,
     109,   116,     0,   108,     0,     0,   109,   109,     0,     0,
       0,     0,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,     0,
     116,   116,   116,   116,     0,     0,     0,     0,     0,     0,
     116,   225,     0,   116,   109,   116,     0,   225,     0,     0,
       0,   116,   116,   116,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,     0,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
       0,     0,     0,     0,     0,   115,     0,     0,     0,   226,
       0,     0,     0,   218,   218,     0,     0,     0,     0,     0,
     226,   226,   226,   226,   226,   226,   226,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,   356,   356,   356,
       0,     0,     0,   218,     0,     0,     0,   116,     0,     0,
       0,   225,   115,   115,   115,     0,   116,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,   109,     0,
     225,     0,     0,     0,   109,   109,   109,   109,     0,     0,
       0,     0,   115,     0,   109,     0,     0,     0,     0,     0,
     217,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,     0,     0,   226,     0,     0,   225,   225,     0,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,   218,   218,   218,   218,   217,
       0,     0,     0,   218,     0,   217,   217,     0,     0,     0,
       0,   218,   218,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   116,   116,   116,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,   218,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,     0,     0,     0,     0,     0,   356,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,   218,   218
  };

  const short
  Parser::yycheck_[] =
  {
      19,    20,    21,    22,    23,    24,    62,    63,    63,    64,
      62,    63,   328,    66,    65,   131,   218,    64,    64,    66,
      66,   338,   338,   218,   381,   109,    71,    72,    63,   161,
     174,   230,    62,   161,    14,   512,   601,   130,   130,    58,
     109,     0,    43,    44,    45,    46,    47,    48,    22,   130,
      21,   109,   149,    27,   326,   327,   328,   329,   330,    63,
     627,   359,   360,   361,   362,   363,   338,    90,   665,    70,
     512,   513,    52,   272,   130,   274,   398,   658,   130,   131,
     212,   280,   281,   282,   212,   272,    14,   274,   359,   360,
     361,   362,   363,   280,   281,   282,   257,   149,   665,   272,
     130,   274,    21,    16,   272,    21,   274,   280,   281,   282,
     707,    24,   280,   281,   282,   359,   360,   361,   362,   363,
      16,   702,   174,   146,    52,   690,    22,    55,   129,    19,
      20,    21,    22,    23,    24,    23,   188,   189,    16,   228,
     707,    20,    21,    22,    23,    24,    24,    10,    11,   310,
     294,    14,    21,   188,   189,   244,    15,   359,   360,   361,
     362,   363,    18,    15,    52,    62,   218,    55,    58,   364,
     365,    14,    28,    29,   197,   259,   260,   261,   262,    58,
      23,   228,   228,   230,   188,   269,   187,    46,    20,    52,
     259,   260,   261,   262,    46,   637,   357,   244,   244,    31,
     269,   259,   260,   261,   262,   257,   299,   299,   253,    52,
      53,   269,    55,   488,    16,   312,   313,   314,   315,   316,
     317,   318,    24,   384,   276,    15,   387,   246,   389,    14,
     552,   553,   149,   130,   591,    21,    21,   398,   257,   332,
     332,   338,   294,   720,    14,    10,    11,   299,   249,    14,
      21,    21,    21,   570,   570,    55,    46,   174,   310,    16,
     312,   313,   314,   315,   316,   317,   318,    52,    23,    26,
      55,   323,   324,    15,   326,   327,   328,   329,   330,   331,
     332,    20,    52,   339,   606,    55,   338,    52,   340,   341,
     342,   310,    31,    16,    16,   325,   348,    52,   570,    22,
      55,    24,    24,    20,    46,   357,    20,   359,   360,   361,
     362,   363,   364,   365,    31,   367,   368,    31,    16,   375,
     149,    14,   374,    20,   376,   377,   378,    44,    21,   381,
      23,   366,   384,   631,    31,   387,    20,   389,   357,   386,
     386,   376,   377,   378,   348,    16,   398,    31,   429,   624,
     395,    22,   445,   445,    16,   374,   246,   556,    16,    52,
     631,    16,    55,    20,   368,   384,    24,   246,   387,   556,
     389,    52,   310,   429,    31,    20,   428,   294,    20,   398,
      18,    19,   434,   556,    16,    16,    31,   631,   556,    31,
      22,   552,   553,   445,    20,   312,   313,   314,   315,   316,
     317,   318,   299,    20,    20,    31,   605,    18,    19,   326,
     327,   328,   329,   330,    31,    31,   691,    14,   605,   357,
      20,   338,   697,   698,    21,    16,    23,    16,   483,   631,
     482,    31,   605,    24,    31,   332,   488,   605,     3,     4,
       5,     6,     7,     8,    16,   606,   384,    16,   500,   387,
      22,   389,    24,   488,    16,    52,    53,    16,    55,    23,
     512,   513,    24,    22,    17,    24,    61,    62,    63,    64,
      65,    66,    44,   570,    28,    29,    71,    72,   482,    16,
     561,   562,    47,   312,   313,   314,   315,   316,   317,   318,
      16,    16,    16,   512,   513,    16,   500,    22,    16,    24,
     552,   553,   554,    24,    22,   561,   562,    16,    26,   338,
     511,    28,    29,    22,   109,    14,   568,    26,   570,    44,
      16,   576,    21,    16,    23,    16,    22,    16,    24,   613,
     582,   428,   584,   552,   553,   130,    22,   434,    17,   591,
     592,   593,   658,   149,   613,   601,   602,   602,   445,   601,
     602,   604,   603,    52,   606,   613,    55,   604,   604,    27,
      16,   257,    13,   615,    45,   584,   618,   602,    24,    16,
     174,   601,   624,   592,   593,   656,   374,    24,    16,   631,
      16,    23,   634,    16,   636,   637,    24,   606,    24,   624,
     643,    24,   627,   188,   189,    16,   643,   643,   602,    21,
     656,    16,   584,    24,    21,    48,   658,    22,   663,    52,
     592,   593,    55,   665,   310,   634,    16,   636,   637,    16,
      16,    16,    22,   218,   676,    22,    22,    22,   323,   324,
     665,    21,   684,   228,   690,   230,    16,   689,   690,   691,
     341,   342,    22,   364,   365,   697,   698,   699,    29,   244,
     702,    28,   634,   570,   636,    27,   691,   676,   253,   711,
     690,   357,   697,   698,   259,   260,   261,   262,   720,    16,
      16,    13,   707,    12,   269,    22,    22,   272,    16,   274,
     699,    18,    19,    20,    22,   280,   281,   282,   384,    14,
     294,   387,   711,   389,   676,    45,    21,    16,    23,    22,
      28,   720,   398,    22,   601,    28,   312,   313,   314,   315,
     316,   317,   318,    14,   512,   513,    18,   699,   615,   323,
     324,   618,   326,   327,   328,   329,   330,    52,    53,   711,
      55,    32,   338,    16,    16,    23,    14,    21,   720,    22,
      22,   570,    21,    21,   339,    23,    21,    48,    49,    50,
      51,    52,    53,   348,    55,     4,     5,    27,     7,     8,
       9,   658,   281,   282,   359,   360,   361,   362,   363,   364,
     365,    45,    14,   368,    52,    53,    13,    55,    23,    21,
     375,   376,   377,   378,   379,    21,   584,   684,    21,    31,
      32,   386,   689,   690,   592,   593,   376,   377,   378,    21,
     395,    27,    23,    15,    15,   702,    48,    49,    50,    51,
      52,    53,    14,    55,    44,    45,    46,    47,    48,    21,
      15,    22,    61,    25,    63,    64,    65,    66,    22,    31,
      32,    33,    71,    72,   429,    17,   634,    20,   636,   637,
      25,    21,    21,    12,    53,    14,    48,    49,    50,    51,
      52,    53,    21,    55,    23,    24,   552,   553,    22,    22,
      22,    22,    31,    32,    33,    34,    35,    36,    37,    15,
     109,    23,    17,    21,    21,    17,    20,    17,   676,    48,
      49,    50,    51,    52,    53,    22,    55,   482,   483,    22,
      14,    22,    17,   488,    23,    17,    22,    21,    16,    15,
      21,   699,    22,    15,    12,   500,    29,    31,    32,    33,
     606,    22,    12,   711,    16,    12,    13,    14,    22,    22,
      29,    22,   720,    20,    21,    15,    23,    22,    52,    53,
      27,    55,    23,    22,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    21,    14,   188,
     189,    48,    49,    50,    51,    52,    53,    13,    55,    22,
      22,   556,    14,    22,   570,    23,   561,   562,    21,    21,
      21,    27,    21,    21,    21,    17,    15,    17,    16,   218,
      32,   576,    38,    39,    40,    41,    42,    43,    16,   228,
      22,   230,    15,    17,    16,    16,    48,    49,    50,    51,
      52,    53,    22,    55,    15,   244,   601,   602,   603,   604,
     605,    15,    22,    22,   253,    17,    17,    17,   613,    22,
     259,   260,   261,   262,    22,    22,    22,    16,    44,   624,
     269,    16,   627,   272,    16,   274,   631,    16,    12,    44,
      14,   280,   281,   282,    15,    44,    22,    21,   643,    23,
      22,    14,    22,    22,    22,    28,     9,    31,    21,    33,
      34,   656,   568,   570,   602,   130,   582,   218,   663,    32,
     665,   711,   275,   188,    48,    49,    50,    51,    52,    53,
      71,    55,   386,   375,   553,    48,    49,    50,    51,    52,
      53,   551,    55,    25,    -1,   690,   691,    -1,    -1,    -1,
     339,    -1,   697,   698,    -1,    16,    -1,    18,    -1,   348,
      -1,    22,   707,    24,    -1,    -1,    -1,    28,    29,    -1,
     359,   360,   361,   362,   363,   364,   365,    -1,    -1,   368,
      -1,    12,    13,    44,    14,    -1,   375,   376,   377,   378,
     379,    21,    -1,    23,    24,    -1,    27,   386,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,   395,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    -1,    61,    62,
      63,    64,    65,    66,    12,    13,    14,    -1,    71,    72,
     429,    -1,    20,    21,    -1,    23,    -1,    -1,    -1,    27,
      14,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,   109,    55,    -1,    -1,
      -1,    12,    -1,    14,    48,    49,    50,    51,    52,    53,
      21,    55,    23,   482,   483,    -1,    -1,   130,    -1,   488,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,   500,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    12,    55,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,   556,    -1,    12,
      -1,    14,   561,   562,    -1,    -1,    -1,    -1,    21,    -1,
      23,    -1,    -1,    -1,    -1,   218,    -1,   576,    31,    32,
      33,    34,    35,    36,    37,   228,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,   244,    55,   602,   603,   604,   605,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   613,    -1,   259,   260,   261,   262,
      -1,    -1,    -1,    -1,    -1,   624,   269,    -1,   627,   272,
      -1,   274,   631,    -1,    -1,    -1,    -1,   280,   281,   282,
      -1,    -1,    14,    -1,   643,    -1,    -1,    -1,    -1,    21,
      12,    23,    14,    -1,    -1,    -1,    -1,   656,    -1,    21,
      -1,    23,    -1,    -1,   663,    -1,   665,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    -1,    48,    49,    50,    51,
      52,    53,   691,    55,    -1,    -1,   339,    -1,   697,   698,
      -1,    13,    -1,    -1,    -1,   348,    -1,    -1,   707,    -1,
      -1,    -1,    -1,    -1,    -1,    27,   359,   360,   361,   362,
     363,   364,   365,    -1,    -1,   368,    38,    39,    40,    41,
      42,    43,   375,   376,   377,   378,   379,    -1,    -1,    -1,
      -1,    -1,    -1,   386,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,   395,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    -1,    61,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    -1,    48,    49,
      50,    51,    52,    53,    14,    55,   429,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    14,    -1,    -1,
      -1,    31,    32,    33,    21,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    31,    32,    33,    14,    48,    49,
      50,    51,    52,    53,    21,    55,    23,    -1,    -1,    -1,
      14,    48,    49,    50,    51,    52,    53,    21,    55,   482,
     483,    -1,    -1,    -1,    -1,   488,    -1,    31,    32,    33,
      14,    48,    49,    50,    51,    52,    53,   500,    55,    23,
      24,    14,    -1,    -1,    48,    49,    50,    51,    52,    53,
      23,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,   188,   189,    -1,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,   561,   562,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   576,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   601,   602,
     603,   604,   605,   259,   260,   261,   262,    -1,    -1,    -1,
     613,    -1,    -1,   269,    -1,    -1,   272,    -1,   274,    -1,
      -1,   624,    -1,    -1,   280,   281,   282,    -1,   631,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,
     663,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   339,    -1,    -1,    -1,   690,   691,    -1,
      -1,    -1,   348,    -1,   697,   698,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,   360,   361,   362,   363,   364,   365,
      -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,   375,
     376,   377,   378,   379,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   482,   483,    -1,    -1,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     556,    -1,    -1,    -1,    -1,   561,   562,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     576,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,   602,   603,   604,   605,
     259,   260,   261,   262,    -1,    -1,    -1,   613,    -1,    -1,
     269,    -1,    -1,   272,    -1,   274,    -1,    -1,   624,    -1,
      -1,   280,   281,   282,    -1,   631,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     656,    -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,   665,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,   691,    -1,    -1,    -1,   348,
      -1,   697,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,   363,   364,   365,    -1,    -1,   368,
      61,    -1,    63,    64,    65,    66,   375,   376,   377,   378,
      71,    72,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    61,
      -1,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,    -1,
      -1,   500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   556,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   260,
     261,   262,    -1,    -1,    -1,    -1,   218,    -1,   269,    -1,
      -1,   272,    61,   274,    63,    64,    65,    66,    -1,   280,
     281,   282,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,   603,   604,   605,    -1,    -1,    -1,
      -1,   253,    -1,    -1,   613,    -1,    -1,   259,   260,   261,
     262,    -1,    -1,    -1,    -1,   624,    -1,   269,    -1,    -1,
     109,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,   339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   665,    -1,   359,   360,
     361,   362,   363,   364,   365,    -1,    -1,   368,    -1,    -1,
      -1,    -1,    -1,    -1,   375,   376,   377,   378,    -1,    -1,
      -1,    -1,   691,    -1,    -1,   386,    -1,    -1,   697,   698,
      -1,    -1,    -1,    -1,   395,    -1,   348,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   359,   360,   361,
     362,   363,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   376,   377,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,   228,
      65,   230,    -1,   395,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     259,   260,   261,   262,    -1,    -1,    -1,    -1,    -1,    -1,
     269,   482,    -1,   272,   109,   274,    -1,   488,    -1,    -1,
      -1,   280,   281,   282,    -1,    -1,    -1,    -1,    -1,   500,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,   348,
      -1,    -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
     359,   360,   361,   362,   363,   364,   365,    -1,    -1,   368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,   377,   378,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   602,   603,   604,   605,    -1,   395,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,   253,    -1,
     631,    -1,    -1,    -1,   259,   260,   261,   262,    -1,    -1,
      -1,    -1,   643,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     602,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   613,    -1,    -1,   665,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,   631,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     691,    -1,    -1,   482,    -1,    -1,   697,   698,    -1,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   500,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   359,   360,   361,   362,   363,   691,
      -1,    -1,    -1,   368,    -1,   697,   698,    -1,    -1,    -1,
      -1,   376,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,   603,   604,   605,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,
      -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   643,    -1,    -1,   482,    -1,    -1,
      -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   500,   665,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   691,    -1,    -1,    -1,    -1,    -1,   697,   698,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,   603,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,    -1,    -1,    -1,    -1,   631,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   691,    -1,    -1,    -1,
      -1,    -1,   697,   698
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    47,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   233,    21,
      21,    21,    21,    21,    21,    21,     0,    59,    48,    52,
      55,   225,   235,   240,   245,   246,   225,   225,   225,   225,
     225,   239,   246,    16,    16,    16,    16,    16,    16,    16,
      22,   226,   245,   226,   226,   226,   226,   226,    23,   234,
      17,    16,    16,    16,    16,    16,    16,   224,   225,    22,
      14,    21,    25,    31,    32,    33,    49,    50,    51,    53,
      68,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   192,   193,   194,   195,   205,   208,
     217,   218,   219,   220,   221,   222,   223,   235,   236,   237,
     238,   240,   241,   242,   243,   244,   247,   248,    12,    14,
      21,    23,    31,    33,    34,    35,    36,    37,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    80,    81,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   100,   101,   105,   107,   109,   110,   111,   112,   113,
     114,   200,   201,   202,   203,   204,   205,   208,   213,   217,
     218,   219,   220,   221,   222,   223,   243,    14,    21,    23,
     115,   116,   117,   118,   119,   120,   121,   122,   124,   125,
     126,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   148,   149,   151,   162,   163,   205,   208,   213,
     217,   218,   219,   220,   221,   222,   223,   243,    21,    31,
      32,   151,   164,   165,   166,   175,   180,   197,   198,   199,
     213,   217,   219,   167,    21,   197,    16,    24,    17,    14,
     245,   168,   194,    21,    26,   168,   196,    16,    22,    27,
      13,    13,    27,    38,    39,    40,    41,    42,    43,   206,
      20,    31,   214,   215,   216,    45,    23,   174,   176,   177,
      21,    21,    21,    18,    19,    20,    10,    11,    13,    27,
      70,   103,   105,   114,   203,   206,   207,   213,   215,    21,
      24,    70,   101,   102,   217,   219,    29,    28,    18,    19,
      16,    22,    27,    13,    12,    12,    13,    27,   206,    77,
      79,    84,    90,   214,   216,    45,    18,    28,    29,    28,
      18,    23,    21,    78,    79,    85,    87,   243,    15,    46,
      21,    21,    21,    10,    11,   116,   151,   163,    21,    24,
     116,   147,   149,   150,   217,   219,   223,    16,    22,    27,
      13,    13,    27,   206,   214,   216,    45,    23,    21,   123,
     124,   131,   133,   243,    15,    46,    21,    21,    21,    21,
     198,    23,   180,   192,    16,    22,    27,    16,    22,    16,
      22,   225,   245,    22,    22,    16,    26,    14,    23,    67,
     227,   228,   229,   231,   232,   235,   238,   243,   244,    17,
     176,   176,   176,   176,   176,    20,   186,   189,   190,   192,
     192,   195,   179,   243,   191,   192,   191,   191,    21,    21,
      22,    22,    22,    22,    16,    24,    67,    17,    77,    77,
      77,    77,    77,    77,    77,    21,    87,   100,   243,   100,
     101,    12,    79,   107,   107,   107,   110,   107,   107,    82,
      83,   243,    70,    76,    77,    79,   106,   107,   108,   110,
     212,   213,   217,   218,   219,   220,   221,   222,   102,   104,
     104,   104,    21,    21,    22,    22,    22,   149,    16,    24,
      67,    17,   122,   124,   130,   137,   122,   122,   122,   122,
      21,   133,   148,   243,   148,   149,   127,   128,   129,   243,
     116,    14,    21,    23,    31,   152,   153,   155,   156,   158,
     160,   209,   210,   211,   235,   236,   243,   212,   150,   150,
     150,    14,    22,   127,    67,    17,   199,    67,    17,    67,
      17,   168,     4,     5,     7,     8,     9,    24,   227,   230,
      22,    16,    15,    21,    16,    24,    16,    22,    22,    22,
      70,    21,    23,    95,   105,    70,    22,    70,    16,    24,
      15,    22,    22,    22,    22,   116,    23,   141,   151,   147,
      22,   116,    16,    24,    15,    22,   152,   155,   159,   152,
     161,    23,    29,    21,    22,    22,    22,    24,    22,    22,
      22,    21,    21,    21,    21,    21,    16,    24,    17,   232,
     227,   230,   243,    15,   192,    16,    96,   105,    16,    17,
      22,    83,    15,   106,    16,   142,   151,    16,    17,    22,
     128,    15,   156,    22,    28,    22,    28,    16,    24,   127,
     156,   156,   157,    15,    17,    17,    17,    69,   115,   167,
     197,   192,   227,    22,   176,    70,    16,    24,    23,    70,
      97,    98,   147,    16,    24,    23,   134,   143,   144,   145,
     149,   122,   156,   156,   152,    24,    16,    22,   197,    22,
      22,    22,    22,    22,    16,   105,    70,    98,    99,    44,
      16,    16,   151,   134,   144,   146,   149,    16,    44,    15,
     156,    70,    16,    24,    70,    69,   147,    16,    24,   147,
     147,    21,   154,   156,    22,    98,    22,    22,   144,    22,
      21,   156,   158,   155,    22
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    72,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    78,    78,    79,    79,    79,    79,    80,    81,
      82,    82,    83,    84,    84,    85,    86,    87,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    90,    91,
      92,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      97,    98,    99,    99,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   105,   105,   106,   106,
     106,   107,   108,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   114,   114,   115,   115,   115,   115,   116,
     116,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   124,
     124,   125,   126,   127,   127,   128,   128,   129,   130,   130,
     131,   132,   133,   133,   133,   134,   134,   135,   136,   136,
     136,   136,   137,   138,   138,   139,   140,   141,   141,   142,
     142,   143,   143,   144,   145,   145,   146,   146,   147,   147,
     147,   148,   148,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   152,   153,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   157,   157,   158,   159,
     159,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   167,   167,   168,   168,   168,   169,   169,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   176,
     176,   177,   177,   177,   178,   179,   179,   180,   180,   180,
     181,   182,   182,   183,   184,   185,   186,   186,   187,   187,
     188,   189,   189,   190,   190,   191,   191,   192,   192,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     198,   198,   199,   199,   199,   200,   200,   200,   201,   201,
     202,   202,   202,   203,   203,   204,   204,   204,   204,   204,
     205,   205,   206,   206,   206,   206,   206,   206,   207,   207,
     208,   209,   210,   211,   212,   212,   213,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   223,   224,
     224,   225,   225,   226,   227,   227,   227,   228,   228,   228,
     228,   228,   228,   229,   230,   230,   231,   231,   231,   231,
     231,   232,   232,   233,   233,   234,   235,   235,   236,   237,
     238,   238,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248
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
       1,     3,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "\"let\"", "\"@\"", "\"&\"", "\"$\"", "\":\"", "\",\"", "\".\"", "\"+\"",
  "\"-\"", "\"=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"|\"", "\"*\"", "\">\"", "\"<\"", "\"!\"", "\"~\"", "\"?\"", "\"^\"",
  "\"!!\"", "\"??\"", "\"@@\"", "\"<=>\"", "\"=>\"", "\"<=\"", "\"<~>\"",
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
  "ThfQuantification", "ThfVariableList", "ThfTypedVariable",
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
       0,   248,   248,   255,   261,   271,   275,   282,   286,   290,
     294,   298,   302,   318,   321,   326,   329,   334,   337,   342,
     349,   361,   364,   369,   372,   415,   420,   450,   456,   459,
     462,   465,   471,   474,   477,   480,   486,   489,   492,   498,
     504,   507,   510,   516,   519,   525,   528,   534,   537,   543,
     546,   549,   555,   558,   564,   567,   570,   573,   579,   585,
     591,   594,   600,   606,   609,   615,   621,   627,   630,   633,
     636,   642,   645,   651,   654,   657,   660,   663,   669,   675,
     681,   684,   687,   693,   699,   705,   708,   714,   717,   723,
     726,   732,   738,   741,   747,   750,   753,   759,   762,   768,
     771,   777,   780,   783,   786,   792,   798,   801,   807,   810,
     813,   819,   825,   831,   834,   837,   843,   846,   852,   855,
     861,   864,   870,   876,   879,   886,   889,   892,   895,   901,
     904,   907,   910,   916,   919,   925,   931,   934,   940,   943,
     949,   952,   958,   961,   964,   970,   973,   979,   982,   985,
     988,   994,  1000,  1006,  1009,  1015,  1018,  1024,  1030,  1033,
    1039,  1045,  1051,  1054,  1057,  1063,  1066,  1072,  1078,  1081,
    1084,  1087,  1093,  1099,  1102,  1108,  1114,  1120,  1123,  1129,
    1132,  1138,  1141,  1147,  1153,  1156,  1162,  1165,  1171,  1174,
    1177,  1183,  1186,  1189,  1192,  1195,  1201,  1204,  1210,  1213,
    1219,  1222,  1228,  1231,  1234,  1237,  1243,  1249,  1252,  1258,
    1261,  1267,  1270,  1273,  1276,  1279,  1285,  1288,  1294,  1300,
    1303,  1309,  1315,  1318,  1324,  1330,  1333,  1340,  1343,  1349,
    1352,  1358,  1366,  1369,  1375,  1378,  1381,  1387,  1390,  1396,
    1402,  1405,  1411,  1414,  1420,  1423,  1429,  1432,  1438,  1444,
    1447,  1453,  1456,  1459,  1465,  1471,  1474,  1480,  1483,  1486,
    1492,  1498,  1501,  1507,  1513,  1519,  1525,  1528,  1534,  1537,
    1543,  1549,  1552,  1558,  1561,  1567,  1570,  1576,  1579,  1585,
    1588,  1591,  1597,  1600,  1606,  1609,  1615,  1618,  1624,  1627,
    1633,  1636,  1642,  1645,  1648,  1654,  1657,  1660,  1666,  1669,
    1675,  1678,  1681,  1687,  1690,  1696,  1699,  1702,  1705,  1708,
    1714,  1717,  1725,  1728,  1731,  1734,  1737,  1740,  1746,  1749,
    1755,  1761,  1767,  1773,  1779,  1782,  1788,  1791,  1797,  1803,
    1809,  1815,  1821,  1827,  1833,  1839,  1845,  1851,  1854,  1860,
    1868,  1880,  1884,  1891,  1898,  1902,  1906,  1913,  1917,  1921,
    1925,  1929,  1933,  1942,  1950,  1956,  1975,  1978,  1981,  1984,
    1987,  1993,  1998,  2007,  2012,  2019,  2053,  2057,  2064,  2070,
    2076,  2080,  2084,  2091,  2098,  2105,  2111,  2118,  2126,  2133,
    2140,  2147,  2153
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
#line 5314 "GrammarParser.cpp" // lalr1.cc:1217
#line 2158 "../../obj/src/GrammarParser.yy" // lalr1.cc:1218


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

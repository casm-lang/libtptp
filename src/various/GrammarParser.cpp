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
#line 84 "../../obj/src/GrammarParser.yy" // lalr1.cc:437

    #include "../../src/Lexer.h"
    #include "../../src/various/GrammarToken.h"

    #include <libtptp/Logger>

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

    // static Lexer helper functions shall be located here 

#line 59 "GrammarParser.cpp" // lalr1.cc:437


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
#line 154 "GrammarParser.cpp" // lalr1.cc:512

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
      case 57: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (that.value));
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
      case 57: // Specification
        value.move< Specification::Ptr > (YY_MOVE (that.value));
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
      case 57: // Specification
        value.move< Specification::Ptr > (that.value);
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
      case 57: // Specification
        yylhs.value.emplace< Specification::Ptr > ();
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
#line 218 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      //m_specification.setInputs( $1 );
  }
#line 805 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 3:
#line 225 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //auto inputs = $1;
    //inputs->add($2);
    //$$ = inputs;
  }
#line 815 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 4:
#line 231 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //auto inputs = make< Nodes >( @$ );
    //inputs->add( $1 );
    //$$ = inputs;
  }
#line 825 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 5:
#line 248 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      //$$ = $1;
  }
#line 833 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 6:
#line 252 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      //$$ = $1;
  }
#line 841 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 7:
#line 286 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //auto formula = $1;
    //formula->set ...
  }
#line 850 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 8:
#line 293 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 857 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 9:
#line 296 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 864 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 10:
#line 299 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 871 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 11:
#line 302 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 878 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 12:
#line 305 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = libtptp::make< FirstOrderFormula >( @$ );
  }
#line 886 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 13:
#line 309 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 893 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 14:
#line 315 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //auto formula = $1;
    //formula->setAnnotations($3);
    //$$ = formula;
  }
#line 903 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 15:
#line 321 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 911 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 16:
#line 328 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source
  }
#line 919 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 17:
#line 332 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //source, optionalInfo
  }
#line 927 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 18:
#line 339 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 934 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 19:
#line 345 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 941 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 20:
#line 348 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 948 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 21:
#line 351 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 955 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 22:
#line 354 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 962 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 23:
#line 360 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 969 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 24:
#line 363 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 976 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 25:
#line 366 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 983 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 26:
#line 369 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 990 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 27:
#line 375 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 997 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 28:
#line 378 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1004 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 29:
#line 381 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1011 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 30:
#line 387 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1018 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 31:
#line 393 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1025 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 32:
#line 396 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1032 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 33:
#line 399 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1039 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 34:
#line 405 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1046 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 35:
#line 408 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1053 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 36:
#line 414 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1060 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 37:
#line 417 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1067 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 38:
#line 423 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1074 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 39:
#line 426 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1081 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 40:
#line 432 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1088 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 41:
#line 435 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1095 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 42:
#line 438 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1102 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 43:
#line 444 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1109 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 44:
#line 447 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1116 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 45:
#line 453 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1123 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 46:
#line 456 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1130 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 47:
#line 459 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1137 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 48:
#line 462 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1144 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 49:
#line 468 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1151 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 50:
#line 474 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1158 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 51:
#line 480 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1165 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 52:
#line 483 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1172 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 53:
#line 489 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1179 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 54:
#line 495 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1186 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 55:
#line 498 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 56:
#line 504 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1200 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 57:
#line 510 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1207 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 58:
#line 516 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1214 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 59:
#line 519 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1221 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 60:
#line 522 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1228 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 61:
#line 525 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1235 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 62:
#line 531 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1242 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 63:
#line 534 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1249 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 64:
#line 540 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1256 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 65:
#line 543 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1263 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 66:
#line 546 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1270 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 67:
#line 549 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1277 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 68:
#line 552 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1284 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 69:
#line 558 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1291 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 70:
#line 564 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1298 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 71:
#line 570 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1305 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 72:
#line 573 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1312 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 73:
#line 576 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1319 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 74:
#line 582 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1326 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 75:
#line 588 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1333 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 76:
#line 594 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1340 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 77:
#line 597 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1347 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 78:
#line 603 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1354 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 79:
#line 606 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1361 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 80:
#line 612 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1368 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 81:
#line 615 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1375 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 82:
#line 621 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1382 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 83:
#line 627 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1389 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 84:
#line 630 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1396 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 85:
#line 636 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1403 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 86:
#line 639 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1410 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 87:
#line 642 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1417 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 88:
#line 648 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1424 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 89:
#line 651 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1431 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 90:
#line 657 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1438 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 91:
#line 660 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1445 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 92:
#line 666 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1452 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 93:
#line 669 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1459 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 94:
#line 672 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1466 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 95:
#line 675 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1473 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 96:
#line 681 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1480 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 97:
#line 687 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1487 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 98:
#line 690 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1494 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 99:
#line 696 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1501 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 100:
#line 699 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1508 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 101:
#line 702 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1515 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 102:
#line 708 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1522 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 103:
#line 714 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1529 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 104:
#line 720 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1536 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 105:
#line 723 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1543 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 106:
#line 726 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1550 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 107:
#line 732 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1557 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 108:
#line 735 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1564 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 109:
#line 741 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1571 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 110:
#line 744 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1578 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 111:
#line 750 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1585 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 112:
#line 753 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1592 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 113:
#line 759 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1599 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 114:
#line 765 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1606 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 115:
#line 768 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1613 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 116:
#line 1543 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1620 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 117:
#line 1546 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1627 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 118:
#line 1549 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1634 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 119:
#line 1555 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1641 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 120:
#line 1558 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1648 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 121:
#line 1564 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1655 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 122:
#line 1567 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1662 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 123:
#line 1570 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1669 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 124:
#line 1576 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1676 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 125:
#line 1579 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1683 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 126:
#line 1585 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1690 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 127:
#line 1588 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1697 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 128:
#line 1591 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1704 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 129:
#line 1594 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1711 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 130:
#line 1597 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1718 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 131:
#line 1603 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1725 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 132:
#line 1606 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1732 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 133:
#line 1614 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1739 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 134:
#line 1617 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1746 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 135:
#line 1620 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1753 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 136:
#line 1623 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1760 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 137:
#line 1626 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1767 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 138:
#line 1629 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1774 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 139:
#line 1635 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1781 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 140:
#line 1638 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1788 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 141:
#line 1644 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1795 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 142:
#line 1668 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1802 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 143:
#line 1671 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1809 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 144:
#line 1677 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1816 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 145:
#line 1680 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1823 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 146:
#line 1686 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1830 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 147:
#line 1692 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1837 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 148:
#line 1698 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1844 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 149:
#line 1704 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1851 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 150:
#line 1710 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1858 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 151:
#line 1716 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1865 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 152:
#line 1722 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1872 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 153:
#line 1728 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1879 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 154:
#line 1734 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1886 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 155:
#line 1740 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1893 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 156:
#line 1743 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1900 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 157:
#line 1749 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1907 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 158:
#line 1752 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1914 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 159:
#line 1758 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 1922 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 160:
#line 1762 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 1930 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 161:
#line 1769 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    // $$ = libtptp::make< FormulaRole >( @$, $1 );
  }
#line 1938 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 162:
#line 1776 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1945 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 163:
#line 1779 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1952 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 164:
#line 1782 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1959 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 165:
#line 1788 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1966 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 166:
#line 1791 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1973 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 167:
#line 1794 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1980 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 168:
#line 1797 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1987 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 169:
#line 1800 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 1994 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 170:
#line 1803 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2001 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 171:
#line 1809 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2008 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 172:
#line 1815 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2015 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 173:
#line 1818 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //auto terms = $1;
    //terms->add($3);
    //$$ = terms;
  }
#line 2025 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 174:
#line 1827 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2032 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 175:
#line 1833 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2039 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 176:
#line 1836 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2046 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 177:
#line 1843 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2053 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 178:
#line 1846 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2060 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 179:
#line 1852 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2067 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 180:
#line 1858 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2074 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 181:
#line 1861 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2081 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 182:
#line 1864 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2088 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 183:
#line 1867 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2095 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 184:
#line 1870 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2102 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 185:
#line 1883 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2109 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 186:
#line 1886 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2116 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 187:
#line 1892 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2123 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 188:
#line 1898 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2130 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 189:
#line 1904 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 2138 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 190:
#line 1908 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 2146 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 191:
#line 1912 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //$$ = $1;
  }
#line 2154 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 192:
#line 1919 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2161 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 193:
#line 1925 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      // ...
  }
#line 2169 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 194:
#line 1932 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      // ...
  }
#line 2177 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 195:
#line 1938 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
      // ...
  }
#line 2185 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 196:
#line 1945 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    // ...
  }
#line 2193 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 197:
#line 1952 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2200 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 198:
#line 1958 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
    //
  }
#line 2208 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 199:
#line 1965 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2215 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 200:
#line 1971 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2222 "GrammarParser.cpp" // lalr1.cc:906
    break;

  case 201:
#line 1977 "../../obj/src/GrammarParser.yy" // lalr1.cc:906
    {
  }
#line 2229 "GrammarParser.cpp" // lalr1.cc:906
    break;


#line 2233 "GrammarParser.cpp" // lalr1.cc:906
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


  const short Parser::yypact_ninf_ = -284;

  const short Parser::yytable_ninf_ = -146;

  const short
  Parser::yypact_[] =
  {
      57,  -284,  -284,  -284,  -284,  -284,  -284,    -6,    39,    57,
    -284,  -284,    88,  -284,   112,  -284,  -284,   242,  -284,   189,
    -284,  -284,  -284,   152,  -284,  -284,  -284,  -284,    96,   213,
     165,   242,   222,  -284,   231,  -284,    61,  -284,   240,   390,
     242,  -284,  -284,   281,    26,   275,   357,  -284,  -284,   230,
    -284,  -284,  -284,    63,  -284,  -284,  -284,  -284,   239,   251,
    -284,  -284,  -284,  -284,  -284,   246,   261,   274,   558,   184,
    -284,   423,   175,  -284,  -284,   103,  -284,  -284,   185,  -284,
    -284,  -284,  -284,   183,   247,  -284,   161,  -284,  -284,   263,
     285,  -284,  -284,   296,  -284,  -284,   456,  -284,  -284,  -284,
      -1,    41,   283,    44,   299,  -284,   300,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,   205,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,   301,   308,   165,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,   309,   310,   311,   312,
     456,  -284,  -284,   320,  -284,   324,  -284,  -284,  -284,    94,
    -284,  -284,  -284,  -284,  -284,   326,   529,   423,   423,   423,
     423,   423,   423,   423,  -284,  -284,  -284,  -284,   321,   513,
    -284,   513,   323,    20,    20,    20,    20,    20,   295,   324,
    -284,  -284,  -284,  -284,  -284,   423,   141,   423,   423,   423,
     423,    53,  -284,   223,  -284,  -284,  -284,   423,  -284,  -284,
     378,   505,  -284,   333,   335,  -284,  -284,  -284,   331,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
     324,  -284,  -284,  -284,  -284,  -284,   106,  -284,  -284,  -284,
     339,  -284,  -284,  -284,   200,  -284,   338,   348,   274,   372,
     383,  -284,   339,  -284,  -284,    34,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,   380,   375,   376,   377,   384,   387,
      28,    28,   398,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
     382,  -284,  -284,   229,   392,   529,   529,   394,   295,   402,
     423,  -284,  -284,  -284,  -284,   423,   232,  -284,   489,   390,
     529,  -284,  -284,  -284,   199,  -284,  -284,  -284,  -284,   403,
      28,  -284,   357,   374,   404,  -284,   406,  -284,  -284,   423,
    -284,   374,  -284,   256,   423,   390,  -284,   407,   423,  -284,
    -284,   408,  -284,  -284,  -284
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     8,     9,    10,    11,    12,    13,     0,     0,     2,
       4,     5,     0,     6,     0,     1,     3,     0,   199,     0,
     192,   193,   198,     0,   159,   160,   185,   186,     0,     0,
       0,     0,     0,   177,     0,   161,     0,   157,     0,     0,
       0,   179,   178,     0,     0,     0,     0,   119,   141,   132,
     121,   126,   127,     0,   194,   195,   197,   196,     0,    15,
      18,    19,    25,    27,    28,    31,    32,    33,     0,    40,
      45,     0,    41,    54,    55,    46,    58,    59,    42,    60,
      61,    65,    66,     0,    63,    20,     0,    29,   104,   105,
     106,    21,    22,     0,   118,   117,     0,   125,   116,   124,
       0,    62,   149,    70,   151,    64,   153,    68,   150,   154,
     152,   155,   189,   190,   191,    47,   156,   187,   188,   158,
     122,   123,   130,     0,     0,     0,   200,   140,   147,   139,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
      95,    92,    93,     0,    94,     0,    88,    90,    63,     0,
      62,    70,   120,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    40,    41,    42,     0,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    43,    44,    46,    47,     0,     0,     0,     0,     0,
       0,     0,   201,    48,    67,    98,   115,     0,    89,     7,
       0,     0,    14,    16,   162,   166,   170,   164,   165,   168,
     167,   169,    35,    37,    39,    38,    36,    34,    30,   148,
       0,    85,    69,    86,    57,   114,     0,   102,   111,   109,
     107,   108,   110,   112,     0,    51,     0,     0,   103,     0,
     102,    97,    99,   101,   100,     0,   113,   142,   144,   149,
     145,   151,   143,   153,    96,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    91,   180,   181,   182,   183,   184,
       0,   175,   172,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    71,    73,    72,     0,     0,    78,     0,     0,
       0,   176,    17,   163,     0,    87,    52,    50,    53,     0,
       0,    77,     0,     0,     0,    80,     0,   173,   171,     0,
      79,    90,    83,     0,     0,     0,   174,     0,     0,    81,
      82,     0,    74,    84,    75
  };

  const short
  Parser::yypgoto_[] =
  {
    -284,  -284,  -284,   422,  -284,  -284,  -284,  -284,   143,   118,
     -39,  -284,  -284,  -284,  -284,  -284,  -173,   -16,  -284,   -46,
    -284,  -284,  -284,   156,    13,   -83,  -284,   -74,  -284,  -284,
      25,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -283,  -284,
     113,   -37,   -42,  -284,   -51,   -29,   167,  -147,  -284,  -284,
    -154,  -284,  -284,  -284,   391,  -284,  -284,  -284,   -25,  -284,
    -284,   381,  -284,  -284,  -284,   -30,  -284,   365,  -284,   -38,
    -168,   -34,  -139,   264,   265,  -284,  -284,    48,  -284,   -98,
    -284,  -284,   176,  -284,   179,  -284,  -284,  -284,    -7,  -284,
    -284,  -112,  -284,   119,  -284,  -284,    64,  -110,   -27,   447,
    -284,  -284
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    11,    12,    58,   202,    59,    60,
     147,    62,    63,    64,    65,    66,    67,    68,   180,    69,
      70,    71,   234,   235,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   262,   286,   304,   305,   313,
      83,   148,   254,   137,   255,    85,   241,    86,   243,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   141,   142,    99,   246,   143,   169,   144,   171,   150,
     102,   151,   104,   105,   106,   107,    36,    23,    34,   272,
     204,   205,   273,   206,   207,    13,    32,   270,   108,   109,
     110,   111,    19,   112,   113,   114,   115,   116,    26,    27,
     117,   118
  };

  const short
  Parser::yytable_[] =
  {
      61,   101,    84,    35,   149,   103,   136,   101,    84,   100,
      24,   103,   238,   182,   185,    14,   138,   126,   249,   312,
     140,   231,   183,   249,    24,   165,   228,   229,   230,   232,
     233,   244,   226,    24,    44,   323,   123,   124,   242,    15,
     125,   179,   259,    46,   209,   186,   211,   251,   125,   260,
     181,    47,   251,    49,    50,   164,  -144,   182,   203,  -145,
       1,     2,     3,     4,     5,     6,   183,   259,    21,    54,
      55,    56,    22,    57,   260,    18,   261,    40,    22,    37,
      22,   153,   154,    18,   166,    41,    22,  -144,   119,   209,
    -145,   211,   249,   249,   181,   221,   167,   221,   192,   183,
     183,   183,   183,   183,     7,    22,   136,   238,    18,    17,
     197,   165,   165,   165,   165,   165,   165,   165,   198,    31,
     140,   251,   251,   -85,   120,   121,   244,   227,   227,   227,
     227,   227,   249,   242,   -85,   225,    25,   256,   257,   240,
     237,   212,   213,   214,   215,   216,   217,   218,   248,   208,
      25,   258,   250,   248,   140,   245,   247,   250,   264,    25,
     184,   251,   263,   209,   209,   211,   211,    18,    30,   239,
     166,   166,   166,   166,   166,   166,   166,   293,   209,   173,
     211,   277,   167,   167,   167,   167,   167,   167,   167,   174,
     175,   -24,   307,    22,   208,   140,    18,   -24,   166,   -24,
     -23,   -26,  -102,   128,   184,    28,   -23,   -26,   -23,   -26,
     167,    29,  -102,  -102,   168,   290,   278,    22,   126,   -24,
     210,   308,   248,   248,   279,   -86,   250,   250,   -23,   -26,
      33,   138,   287,   223,   240,   223,   -86,   184,   184,   184,
     184,   184,   236,   -87,    38,   290,   299,    39,   300,   303,
      61,   101,    84,   291,   -87,   103,   301,    42,   152,   100,
     149,   155,   248,   311,   239,   210,   250,   156,   208,   208,
     317,   310,   318,   157,   158,   320,    61,   101,    84,   303,
     319,   103,   222,   208,   224,   100,   159,    43,   127,    44,
      21,   176,   172,   166,    22,   128,    45,    18,    46,   120,
     121,   122,   129,   177,   187,   167,    47,    48,    49,    50,
      51,    52,    53,   130,   131,   132,   133,   134,   135,   178,
     188,   189,   190,    21,    54,    55,    56,    22,    57,   191,
      18,   193,   194,   195,   196,   185,    43,   127,    44,   210,
     210,   219,   236,   199,   128,   145,    46,    46,    57,   274,
     275,   129,   276,   280,   210,    47,    48,    49,    50,    51,
      52,    53,   130,   131,   132,   133,   134,   135,   175,    43,
     281,    44,    21,    54,    55,    56,    22,    57,   145,    18,
      46,   146,   265,   266,   160,   267,   268,   269,    47,    48,
      49,    50,    51,    52,    53,   -40,   197,   282,   283,   284,
     285,   125,    43,   289,    44,    21,    54,    55,    56,    22,
      57,    45,    18,    46,   288,   201,   295,   297,   314,   309,
     315,    47,    48,    49,    50,    51,    52,    53,   316,   322,
     324,    16,   306,   321,   296,    43,   139,    44,    21,    54,
      55,    56,    22,    57,   145,    18,    46,   298,   170,   163,
     252,   253,   294,   292,    47,    48,    49,    50,    51,    52,
      53,    20,     0,     0,     0,     0,     0,     0,    43,     0,
      44,    21,    54,    55,    56,    22,    57,   179,    18,    46,
       0,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,    43,     0,    44,    21,    54,    55,    56,    22,    57,
     145,    18,   302,     0,     0,     0,     0,     0,     0,   200,
      47,    48,    49,    50,    51,    52,    53,    44,   201,   271,
       0,     0,     0,     0,   220,     0,    46,    21,    54,    55,
      56,    22,    57,   200,    18,     0,     0,     0,     0,     0,
       0,     0,   201,    21,    54,    55,    56,    22,    57,     0,
      18,    21,    54,    55,    56,    22,    57,     0,    18,     0,
     160,   161,     0,     0,     0,     0,     0,    21,    54,    55,
      56,    22,    57,     0,    18,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135
  };

  const short
  Parser::yycheck_[] =
  {
      39,    39,    39,    30,    46,    39,    45,    45,    45,    39,
      17,    45,   185,    96,    15,    21,    45,    44,   186,   302,
      45,   175,    96,   191,    31,    71,   173,   174,   175,   176,
     177,   185,    12,    40,    14,   318,    10,    11,   185,     0,
      14,    21,    14,    23,   156,    46,   156,   186,    14,    21,
      96,    31,   191,    33,    34,    71,    15,   140,   156,    15,
       3,     4,     5,     6,     7,     8,   140,    14,    48,    49,
      50,    51,    52,    53,    21,    55,    23,    16,    52,    31,
      52,    18,    19,    55,    71,    24,    52,    46,    40,   201,
      46,   201,   260,   261,   140,   169,    71,   171,   125,   173,
     174,   175,   176,   177,    47,    52,   145,   280,    55,    21,
      16,   157,   158,   159,   160,   161,   162,   163,    24,    23,
     145,   260,   261,    20,    18,    19,   280,   173,   174,   175,
     176,   177,   300,   280,    31,   172,    17,   188,   189,   185,
     179,   157,   158,   159,   160,   161,   162,   163,   186,   156,
      31,   190,   186,   191,   179,    14,   186,   191,   197,    40,
      96,   300,   191,   275,   276,   275,   276,    55,    16,   185,
     157,   158,   159,   160,   161,   162,   163,   275,   290,    18,
     290,   220,   157,   158,   159,   160,   161,   162,   163,    28,
      29,    16,   290,    52,   201,   220,    55,    22,   185,    24,
      16,    16,    18,    20,   140,    16,    22,    22,    24,    24,
     185,    22,    28,    29,    31,    16,    16,    52,   245,    44,
     156,    22,   260,   261,    24,    20,   260,   261,    44,    44,
      17,   260,   261,   169,   280,   171,    31,   173,   174,   175,
     176,   177,   178,    20,    22,    16,   285,    16,    16,   288,
     289,   289,   289,    24,    31,   289,    24,    17,    28,   289,
     302,    22,   300,   302,   280,   201,   300,    16,   275,   276,
     309,   300,    16,    27,    13,   314,   315,   315,   315,   318,
      24,   315,   169,   290,   171,   315,    12,    12,    13,    14,
      48,    28,    45,   280,    52,    20,    21,    55,    23,    18,
      19,    20,    27,    18,    21,   280,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    23,
      21,    21,    21,    48,    49,    50,    51,    52,    53,    21,
      55,    22,    22,    22,    22,    15,    12,    13,    14,   275,
     276,    20,   278,    17,    20,    21,    23,    23,    53,    16,
      15,    27,    21,    15,   290,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    29,    12,
      22,    14,    48,    49,    50,    51,    52,    53,    21,    55,
      23,    24,     4,     5,    12,     7,     8,     9,    31,    32,
      33,    34,    35,    36,    37,    12,    16,    22,    22,    22,
      16,    14,    12,    21,    14,    48,    49,    50,    51,    52,
      53,    21,    55,    23,    16,    23,    22,    15,    44,    16,
      16,    31,    32,    33,    34,    35,    36,    37,    22,    22,
      22,     9,   289,   315,   278,    12,    45,    14,    48,    49,
      50,    51,    52,    53,    21,    55,    23,   280,    83,    68,
     186,   186,   276,   274,    31,    32,    33,    34,    35,    36,
      37,    14,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      14,    48,    49,    50,    51,    52,    53,    21,    55,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    14,    48,    49,    50,    51,    52,    53,
      21,    55,    23,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      31,    32,    33,    34,    35,    36,    37,    14,    23,    24,
      -1,    -1,    -1,    -1,    21,    -1,    23,    48,    49,    50,
      51,    52,    53,    14,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    48,    49,    50,    51,    52,    53,    -1,
      55,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    -1,    55,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    47,    57,    58,
      59,    60,    61,   141,    21,     0,    59,    21,    55,   148,
     155,    48,    52,   133,   144,   149,   154,   155,    16,    22,
      16,    23,   142,    17,   134,   154,   132,   133,    22,    16,
      16,    24,    17,    12,    14,    21,    23,    31,    32,    33,
      34,    35,    36,    37,    49,    50,    51,    53,    62,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    75,
      76,    77,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    96,    97,   101,   103,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   119,
     121,   125,   126,   127,   128,   129,   130,   131,   144,   145,
     146,   147,   149,   150,   151,   152,   153,   156,   157,   133,
      18,    19,    20,    10,    11,    14,   154,    13,    20,    27,
      38,    39,    40,    41,    42,    43,    66,    99,   101,   110,
     114,   117,   118,   121,   123,    21,    24,    66,    97,    98,
     125,   127,    28,    18,    19,    22,    16,    27,    13,    12,
      12,    13,    27,   117,    73,    75,    80,    86,    31,   122,
     123,   124,    45,    18,    28,    29,    28,    18,    23,    21,
      74,    75,    81,    83,   152,    15,    46,    21,    21,    21,
      21,    21,   154,    22,    22,    22,    22,    16,    24,    17,
      14,    23,    63,   135,   136,   137,   139,   140,   144,   147,
     152,   153,    73,    73,    73,    73,    73,    73,    73,    20,
      21,    83,    96,   152,    96,    97,    12,    75,   103,   103,
     103,   106,   103,   103,    78,    79,   152,    66,    72,    73,
      75,   102,   103,   104,   106,    14,   120,   121,   125,   126,
     127,   128,   129,   130,    98,   100,   100,   100,    66,    14,
      21,    23,    91,   101,    66,     4,     5,     7,     8,     9,
     143,    24,   135,   138,    16,    15,    21,    66,    16,    24,
      15,    22,    22,    22,    22,    16,    92,   101,    16,    21,
      16,    24,   140,   135,   138,    22,    79,    15,   102,    66,
      16,    24,    23,    66,    93,    94,    64,   135,    22,    16,
     101,    66,    94,    95,    44,    16,    22,    66,    16,    24,
      66,    65,    22,    94,    22
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      77,    78,    78,    79,    80,    80,    81,    82,    83,    83,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    86,
      87,    88,    88,    88,    89,    90,    91,    91,    92,    92,
      93,    93,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,   100,   101,   101,   102,
     102,   102,   103,   104,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   131,   132,   132,   133,
     133,   134,   135,   135,   135,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   139,   140,   140,   141,   141,   142,
     143,   143,   143,   143,   143,   144,   144,   145,   146,   147,
     147,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     9,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       5,     1,     3,     3,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     4,     4,     4,     9,     9,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     3,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     5,     2,     3,     5,     7,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "\"-\"", "\"=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"|\"", "\"*\"", "\">\"", "\"<\"", "\"!\"", "\"~\"", "\"?\"", "\"^\"",
  "\"!!\"", "\"??\"", "\"@@\"", "\"<=>\"", "\"=>\"", "\"<=\"", "\"<~>\"",
  "\"~|\"", "\"~&\"", "\":=\"", "\"-->\"", "\"<<\"", "\"include\"",
  "\"integer\"", "\"real\"", "\"rational\"", "\"double_quoted\"",
  "\"lower_word\"", "\"upper_word\"", "\"identifier\"",
  "\"single_quoted\"", "$accept", "Specification", "Inputs", "Input",
  "AnnotatedFormula", "FormulaKeyword", "FormulaSpecification",
  "Annotations", "Formula", "ThfFormula", "ThfLogicFormula",
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
  "ThfXprodType", "ThfUnionType", "ThfSubtype", "ThfSequent",
  "ThfQuantifier", "Th1Quantifier", "Th0Quantifier", "ThfUnaryConnective",
  "Th1UnaryConnective", "FofQuantifier", "NonassocConnective",
  "AssocConnective", "UnaryConnective", "Atom", "UntypedAtom",
  "DefinedInfixPred", "InfixEquality", "InfixInequality", "Constant",
  "Functor", "SystemConstant", "SystemFunctor", "DefinedConstant",
  "DefinedFunctor", "DefinedTerm", "NameList", "Name", "FormulaRole",
  "GeneralTerm", "GeneralData", "GeneralFunction", "GeneralTerms",
  "FormulaData", "GeneralList", "Include", "FormulaSelection",
  "FormulaDataKeyword", "AtomicWord", "AtomicDefinedWord",
  "AtomicSystemWord", "Number", "FileName", "IntegerLiteral",
  "RealLiteral", "RationalLiteral", "Variable", "DistinctObjectLiteral",
  "LowerWordLiteral", "SingleQuotedLiteral", "DollarWordLiteral",
  "DollarDollarWordLiteral", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   217,   217,   224,   230,   247,   251,   285,   292,   295,
     298,   301,   304,   308,   314,   320,   327,   331,   338,   344,
     347,   350,   353,   359,   362,   365,   368,   374,   377,   380,
     386,   392,   395,   398,   404,   407,   413,   416,   422,   425,
     431,   434,   437,   443,   446,   452,   455,   458,   461,   467,
     473,   479,   482,   488,   494,   497,   503,   509,   515,   518,
     521,   524,   530,   533,   539,   542,   545,   548,   551,   557,
     563,   569,   572,   575,   581,   587,   593,   596,   602,   605,
     611,   614,   620,   626,   629,   635,   638,   641,   647,   650,
     656,   659,   665,   668,   671,   674,   680,   686,   689,   695,
     698,   701,   707,   713,   719,   722,   725,   731,   734,   740,
     743,   749,   752,   758,   764,   767,  1542,  1545,  1548,  1554,
    1557,  1563,  1566,  1569,  1575,  1578,  1584,  1587,  1590,  1593,
    1596,  1602,  1605,  1613,  1616,  1619,  1622,  1625,  1628,  1634,
    1637,  1643,  1667,  1670,  1676,  1679,  1685,  1691,  1697,  1703,
    1709,  1715,  1721,  1727,  1733,  1739,  1742,  1748,  1751,  1757,
    1761,  1768,  1775,  1778,  1781,  1787,  1790,  1793,  1796,  1799,
    1802,  1808,  1814,  1817,  1826,  1832,  1835,  1842,  1845,  1851,
    1857,  1860,  1863,  1866,  1869,  1882,  1885,  1891,  1897,  1903,
    1907,  1911,  1918,  1924,  1931,  1937,  1944,  1951,  1957,  1964,
    1970,  1976
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
#line 2930 "GrammarParser.cpp" // lalr1.cc:1217
#line 1981 "../../obj/src/GrammarParser.yy" // lalr1.cc:1218


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

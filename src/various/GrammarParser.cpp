// A Bison parser, made by GNU Bison 3.1.

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


// First part of user declarations.

#line 37 "GrammarParser.cpp" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "GrammarParser.tab.h"

// User implementation prologue.

#line 51 "GrammarParser.cpp" // lalr1.cc:415
// Unqualified %code blocks.
#line 84 "../../obj/src/GrammarParser.yy" // lalr1.cc:416

    // #include <libtptp/ ... >

    //#include "../../src/SourceLocation.h"
    #include "../../src/Lexer.h"
    #include "../../src/various/GrammarToken.h"

    #include <libstdhl/Type>

    #undef yylex
    #define yylex m_lexer.nextToken

    // static Lexer helper functions shall be located here 

#line 68 "GrammarParser.cpp" // lalr1.cc:416


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

#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:491
namespace libtptp {
#line 163 "GrammarParser.cpp" // lalr1.cc:491

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
  Parser::Parser (Lexer& m_lexer_yyarg, Specification& m_specification_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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

  Parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    switch (that.type_get ())
    {
      case 57: // Specification
        value.copy< Specification::Ptr > (that.value);
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
        value.copy< Token::Ptr > (that.value);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
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

    // that is emptied.
    that.type = empty_symbol;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 57: // Specification
        value.copy< Specification::Ptr > (that.value);
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
        value.copy< Token::Ptr > (that.value);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


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
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  Parser::yypop_ (unsigned n)
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
    yypush_ (YY_NULLPTR, 0, yyla);

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
    yypush_ ("Shifting", yyn, yyla);
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
        yylhs.value.build< Specification::Ptr > ();
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
        yylhs.value.build< Token::Ptr > ();
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        yylhs.value.build< std::string > ();
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
#line 219 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      //m_specification.setInputs( $1 );
  }
#line 796 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 3:
#line 226 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //auto inputs = $1;
    //inputs->add($2);
    //$$ = inputs;
  }
#line 806 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 4:
#line 232 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //auto inputs = make< Nodes >( @$ );
    //inputs->add( $1 );
    //$$ = inputs;
  }
#line 816 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 5:
#line 249 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      //$$ = $1;
  }
#line 824 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 6:
#line 253 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      //$$ = $1;
  }
#line 832 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 7:
#line 287 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //auto formula = $1;
    //formula->set ...
  }
#line 841 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 8:
#line 294 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 848 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 9:
#line 297 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 855 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 10:
#line 300 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 862 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 11:
#line 303 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 869 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 12:
#line 306 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = libtptp::make< FirstOrderFormula >( @$ );
  }
#line 877 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 13:
#line 310 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 884 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 14:
#line 316 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //auto formula = $1;
    //formula->setAnnotations($3);
    //$$ = formula;
  }
#line 894 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 15:
#line 322 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 902 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 16:
#line 329 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //source
  }
#line 910 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 17:
#line 333 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //source, optionalInfo
  }
#line 918 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 18:
#line 340 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 925 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 19:
#line 346 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 932 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 20:
#line 349 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 939 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 21:
#line 352 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 946 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 22:
#line 355 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 953 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 23:
#line 361 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 960 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 24:
#line 364 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 967 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 25:
#line 367 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 974 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 26:
#line 370 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 981 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 27:
#line 376 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 988 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 28:
#line 379 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 995 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 29:
#line 382 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1002 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 30:
#line 388 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1009 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 31:
#line 394 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1016 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 32:
#line 397 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1023 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 33:
#line 400 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1030 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 34:
#line 406 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1037 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 35:
#line 409 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1044 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 36:
#line 415 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1051 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 37:
#line 418 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1058 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 38:
#line 424 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1065 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 39:
#line 427 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1072 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 40:
#line 433 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1079 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 41:
#line 436 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1086 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 42:
#line 439 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1093 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 43:
#line 445 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1100 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 44:
#line 448 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1107 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 45:
#line 454 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1114 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 46:
#line 457 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1121 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 47:
#line 460 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1128 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 48:
#line 463 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1135 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 49:
#line 469 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1142 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 50:
#line 475 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1149 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 51:
#line 481 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1156 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 52:
#line 484 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1163 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 53:
#line 490 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1170 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 54:
#line 496 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1177 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 55:
#line 499 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1184 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 56:
#line 505 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1191 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 57:
#line 511 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1198 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 58:
#line 517 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1205 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 59:
#line 520 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1212 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 60:
#line 523 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1219 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 61:
#line 526 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1226 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 62:
#line 532 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1233 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 63:
#line 535 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1240 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 64:
#line 541 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1247 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 65:
#line 544 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1254 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 66:
#line 547 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1261 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 67:
#line 550 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1268 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 68:
#line 553 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1275 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 69:
#line 559 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1282 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 70:
#line 565 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1289 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 71:
#line 571 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1296 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 72:
#line 574 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1303 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 73:
#line 577 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1310 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 74:
#line 583 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1317 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 75:
#line 589 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1324 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 76:
#line 595 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1331 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 77:
#line 598 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1338 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 78:
#line 604 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1345 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 79:
#line 607 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1352 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 80:
#line 613 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1359 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 81:
#line 616 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1366 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 82:
#line 622 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1373 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 83:
#line 628 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1380 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 84:
#line 631 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1387 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 85:
#line 637 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1394 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 86:
#line 640 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1401 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 87:
#line 643 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1408 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 88:
#line 649 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1415 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 89:
#line 652 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1422 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 90:
#line 658 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1429 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 91:
#line 661 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1436 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 92:
#line 667 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1443 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 93:
#line 670 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1450 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 94:
#line 673 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1457 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 95:
#line 676 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1464 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 96:
#line 682 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1471 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 97:
#line 688 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1478 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 98:
#line 691 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1485 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 99:
#line 697 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1492 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 100:
#line 700 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1499 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 101:
#line 703 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1506 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 102:
#line 709 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1513 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 103:
#line 715 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1520 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 104:
#line 721 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1527 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 105:
#line 724 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1534 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 106:
#line 727 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1541 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 107:
#line 733 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1548 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 108:
#line 736 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1555 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 109:
#line 742 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1562 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 110:
#line 745 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1569 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 111:
#line 751 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1576 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 112:
#line 754 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1583 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 113:
#line 760 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1590 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 114:
#line 766 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1597 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 115:
#line 769 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1604 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 116:
#line 1544 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1611 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 117:
#line 1547 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1618 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 118:
#line 1550 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1625 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 119:
#line 1556 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1632 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 120:
#line 1559 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1639 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 121:
#line 1565 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1646 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 122:
#line 1568 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1653 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 123:
#line 1571 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1660 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 124:
#line 1577 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1667 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 125:
#line 1580 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1674 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 126:
#line 1586 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1681 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 127:
#line 1589 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1688 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 128:
#line 1592 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1695 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 129:
#line 1595 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1702 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 130:
#line 1598 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1709 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 131:
#line 1604 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1716 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 132:
#line 1607 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1723 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 133:
#line 1615 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1730 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 134:
#line 1618 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1737 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 135:
#line 1621 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1744 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 136:
#line 1624 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1751 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 137:
#line 1627 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1758 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 138:
#line 1630 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1765 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 139:
#line 1636 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1772 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 140:
#line 1639 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1779 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 141:
#line 1645 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1786 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 142:
#line 1669 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1793 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 143:
#line 1672 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1800 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 144:
#line 1678 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1807 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 145:
#line 1681 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1814 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 146:
#line 1687 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1821 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 147:
#line 1693 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1828 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 148:
#line 1699 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1835 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 149:
#line 1705 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1842 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 150:
#line 1711 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1849 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 151:
#line 1717 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1856 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 152:
#line 1723 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1863 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 153:
#line 1729 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1870 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 154:
#line 1735 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1877 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 155:
#line 1741 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1884 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 156:
#line 1744 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1891 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 157:
#line 1750 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1898 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 158:
#line 1753 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1905 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 159:
#line 1759 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 1913 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 160:
#line 1763 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 1921 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 161:
#line 1770 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    // $$ = libtptp::make< FormulaRole >( @$, $1 );
  }
#line 1929 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 162:
#line 1777 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1936 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 163:
#line 1780 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1943 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 164:
#line 1783 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1950 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 165:
#line 1789 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1957 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 166:
#line 1792 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1964 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 167:
#line 1795 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1971 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 168:
#line 1798 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1978 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 169:
#line 1801 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1985 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 170:
#line 1804 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1992 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 171:
#line 1810 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 1999 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 172:
#line 1816 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2006 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 173:
#line 1819 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //auto terms = $1;
    //terms->add($3);
    //$$ = terms;
  }
#line 2016 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 174:
#line 1828 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2023 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 175:
#line 1834 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2030 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 176:
#line 1837 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2037 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 177:
#line 1844 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2044 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 178:
#line 1847 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2051 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 179:
#line 1853 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2058 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 180:
#line 1859 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2065 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 181:
#line 1862 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2072 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 182:
#line 1865 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2079 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 183:
#line 1868 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2086 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 184:
#line 1871 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2093 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 185:
#line 1884 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2100 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 186:
#line 1887 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2107 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 187:
#line 1893 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2114 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 188:
#line 1899 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2121 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 189:
#line 1905 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 2129 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 190:
#line 1909 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 2137 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 191:
#line 1913 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //$$ = $1;
  }
#line 2145 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 192:
#line 1920 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2152 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 193:
#line 1926 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      // ...
  }
#line 2160 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 194:
#line 1933 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      // ...
  }
#line 2168 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 195:
#line 1939 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
      // ...
  }
#line 2176 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 196:
#line 1946 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    // ...
  }
#line 2184 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 197:
#line 1953 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2191 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 198:
#line 1959 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
    //
  }
#line 2199 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 199:
#line 1966 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2206 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 200:
#line 1972 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2213 "GrammarParser.cpp" // lalr1.cc:870
    break;

  case 201:
#line 1978 "../../obj/src/GrammarParser.yy" // lalr1.cc:870
    {
  }
#line 2220 "GrammarParser.cpp" // lalr1.cc:870
    break;


#line 2224 "GrammarParser.cpp" // lalr1.cc:870
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
      yypush_ (YY_NULLPTR, yylhs);
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
      yypush_ ("Shifting", error_token);
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
       0,   218,   218,   225,   231,   248,   252,   286,   293,   296,
     299,   302,   305,   309,   315,   321,   328,   332,   339,   345,
     348,   351,   354,   360,   363,   366,   369,   375,   378,   381,
     387,   393,   396,   399,   405,   408,   414,   417,   423,   426,
     432,   435,   438,   444,   447,   453,   456,   459,   462,   468,
     474,   480,   483,   489,   495,   498,   504,   510,   516,   519,
     522,   525,   531,   534,   540,   543,   546,   549,   552,   558,
     564,   570,   573,   576,   582,   588,   594,   597,   603,   606,
     612,   615,   621,   627,   630,   636,   639,   642,   648,   651,
     657,   660,   666,   669,   672,   675,   681,   687,   690,   696,
     699,   702,   708,   714,   720,   723,   726,   732,   735,   741,
     744,   750,   753,   759,   765,   768,  1543,  1546,  1549,  1555,
    1558,  1564,  1567,  1570,  1576,  1579,  1585,  1588,  1591,  1594,
    1597,  1603,  1606,  1614,  1617,  1620,  1623,  1626,  1629,  1635,
    1638,  1644,  1668,  1671,  1677,  1680,  1686,  1692,  1698,  1704,
    1710,  1716,  1722,  1728,  1734,  1740,  1743,  1749,  1752,  1758,
    1762,  1769,  1776,  1779,  1782,  1788,  1791,  1794,  1797,  1800,
    1803,  1809,  1815,  1818,  1827,  1833,  1836,  1843,  1846,  1852,
    1858,  1861,  1864,  1867,  1870,  1883,  1886,  1892,  1898,  1904,
    1908,  1912,  1919,  1925,  1932,  1938,  1945,  1952,  1958,  1965,
    1971,  1977
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


#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:1181
} // libtptp
#line 2921 "GrammarParser.cpp" // lalr1.cc:1181
#line 1982 "../../obj/src/GrammarParser.yy" // lalr1.cc:1182


void Parser::error( const SourceLocation& location, const std::string& message )
{
    // m_log.error( {location}, message, Code::SyntaxError );
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

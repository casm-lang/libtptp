// A Bison parser, made by GNU Bison 3.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file GrammarParser.tab.h
 ** Define the libtptp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
# define YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
// //                    "%code requires" blocks.
#line 61 "../../obj/src/GrammarParser.yy" // lalr1.cc:380

    namespace libtptp
    {
        class Lexer;
        // class Logger;
        class SourceLocation;
    }

    #include <libtptp/Specification>
    #include <libtptp/Token>

    #include "../../src/SourceLocation.h"

    using namespace libtptp;

    #define YY_NULLPTR nullptr

#line 62 "GrammarParser.tab.h" // lalr1.cc:380

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:380
namespace libtptp {
#line 146 "GrammarParser.tab.h" // lalr1.cc:380



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // Specification
      char dummy1[sizeof(Specification::Ptr)];

      // "tpi"
      // "thf"
      // "tff"
      // "tcf"
      // "fof"
      // "cnf"
      // "fot"
      // "ite"
      // "let"
      // "@"
      // "&"
      // "$"
      // ":"
      // ","
      // "."
      // "+"
      // "-"
      // "="
      // "("
      // ")"
      // "["
      // "]"
      // "{"
      // "}"
      // "|"
      // "*"
      // ">"
      // "<"
      // "!"
      // "~"
      // "?"
      // "^"
      // "!!"
      // "??"
      // "@@"
      // "<=>"
      // "=>"
      // "<="
      // "<~>"
      // "~|"
      // "~&"
      // ":="
      // "-->"
      // "<<"
      // "include"
      char dummy2[sizeof(Token::Ptr)];

      // "integer"
      // "real"
      // "rational"
      // "double_quoted"
      // "lower_word"
      // "upper_word"
      // "identifier"
      // "single_quoted"
      char dummy3[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef SourceLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        TPI = 258,
        THF = 259,
        TFF = 260,
        TCF = 261,
        FOF = 262,
        CNF = 263,
        FOT = 264,
        ITE = 265,
        LET = 266,
        AT = 267,
        AND = 268,
        DOLLAR = 269,
        COLON = 270,
        COMMA = 271,
        DOT = 272,
        PLUS = 273,
        MINUS = 274,
        EQUAL = 275,
        LPAREN = 276,
        RPAREN = 277,
        LSQPAREN = 278,
        RSQPAREN = 279,
        LCURPAREN = 280,
        RCURPAREN = 281,
        VLINE = 282,
        STAR = 283,
        GREATER = 284,
        LESS = 285,
        EXCLAMATION = 286,
        TILDE = 287,
        QUESTIONMARK = 288,
        CARET = 289,
        DOUBLEEXCLAMATION = 290,
        DOUBLEQUESTIONMARK = 291,
        DOUBLEAT = 292,
        EQUALITY = 293,
        IMPLICATION = 294,
        RIMPLICATION = 295,
        INEQUALITY = 296,
        NOR = 297,
        NAND = 298,
        ASSIGNMENT = 299,
        GENTZENARROW = 300,
        SUBTYPESIGN = 301,
        INCLUDE = 302,
        INTEGER = 303,
        REAL = 304,
        RATIONAL = 305,
        DQUOTED = 306,
        LOWER_WORD = 307,
        UPPER_WORD = 308,
        IDENTIFIER = 309,
        SINGLE_QUOTED = 310
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Specification::Ptr& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Token::Ptr& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_TPI (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_THF (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_TFF (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_TCF (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_FOF (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_CNF (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_FOT (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_ITE (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_LET (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_AT (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_AND (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_DOLLAR (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_COLON (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_COMMA (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_DOT (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_EQUAL (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_LPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_RPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_LSQPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_RSQPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_LCURPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_RCURPAREN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_VLINE (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_STAR (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_GREATER (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_LESS (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_EXCLAMATION (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_TILDE (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_QUESTIONMARK (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_CARET (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_DOUBLEEXCLAMATION (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_DOUBLEQUESTIONMARK (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_DOUBLEAT (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_EQUALITY (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_IMPLICATION (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_RIMPLICATION (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_INEQUALITY (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_NOR (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_NAND (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_ASSIGNMENT (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_GENTZENARROW (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_SUBTYPESIGN (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_INCLUDE (const Token::Ptr& v, const location_type& l);

    static inline
    symbol_type
    make_INTEGER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_REAL (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_RATIONAL (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_DQUOTED (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_LOWER_WORD (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_UPPER_WORD (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_SINGLE_QUOTED (const std::string& v, const location_type& l);


    /// Build a parser object.
    Parser (Lexer& m_lexer_yyarg, Specification& m_specification_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Copy construct (for efficiency).
      stack_symbol_type (const stack_symbol_type& that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 601,     ///< Last index in yytable_.
      yynnts_ = 102,  ///< Number of nonterminal symbols.
      yyfinal_ = 15, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 56  ///< Number of tokens.
    };


    // User arguments.
    Lexer& m_lexer;
    Specification& m_specification;
  };

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    const unsigned user_token_number_max_ = 310;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    switch (other.type_get ())
    {
      case 57: // Specification
        value.copy< Specification::Ptr > (other.value);
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
        value.copy< Token::Ptr > (other.value);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
    switch (this->type_get ())
    {
      case 57: // Specification
        value.copy< Specification::Ptr > (v);
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
        value.copy< Token::Ptr > (v);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Specification::Ptr& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Token::Ptr& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
  switch (yytype)
    {
      case 57: // Specification
        value.template destroy< Specification::Ptr > ();
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
        value.template destroy< Token::Ptr > ();
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 57: // Specification
        value.move< Specification::Ptr > (s.value);
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
        value.move< Token::Ptr > (s.value);
        break;

      case 48: // "integer"
      case 49: // "real"
      case 50: // "rational"
      case 51: // "double_quoted"
      case 52: // "lower_word"
      case 53: // "upper_word"
      case 54: // "identifier"
      case 55: // "single_quoted"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }

  inline
  Parser::token_type
  Parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  Parser::symbol_type
  Parser::make_TPI (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::TPI, v, l);
  }

  Parser::symbol_type
  Parser::make_THF (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::THF, v, l);
  }

  Parser::symbol_type
  Parser::make_TFF (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::TFF, v, l);
  }

  Parser::symbol_type
  Parser::make_TCF (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::TCF, v, l);
  }

  Parser::symbol_type
  Parser::make_FOF (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::FOF, v, l);
  }

  Parser::symbol_type
  Parser::make_CNF (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::CNF, v, l);
  }

  Parser::symbol_type
  Parser::make_FOT (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::FOT, v, l);
  }

  Parser::symbol_type
  Parser::make_ITE (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::ITE, v, l);
  }

  Parser::symbol_type
  Parser::make_LET (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::LET, v, l);
  }

  Parser::symbol_type
  Parser::make_AT (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::AT, v, l);
  }

  Parser::symbol_type
  Parser::make_AND (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::AND, v, l);
  }

  Parser::symbol_type
  Parser::make_DOLLAR (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::DOLLAR, v, l);
  }

  Parser::symbol_type
  Parser::make_COLON (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::COLON, v, l);
  }

  Parser::symbol_type
  Parser::make_COMMA (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::COMMA, v, l);
  }

  Parser::symbol_type
  Parser::make_DOT (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::DOT, v, l);
  }

  Parser::symbol_type
  Parser::make_PLUS (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::PLUS, v, l);
  }

  Parser::symbol_type
  Parser::make_MINUS (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::MINUS, v, l);
  }

  Parser::symbol_type
  Parser::make_EQUAL (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::EQUAL, v, l);
  }

  Parser::symbol_type
  Parser::make_LPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::LPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_RPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::RPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_LSQPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::LSQPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_RSQPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::RSQPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_LCURPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::LCURPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_RCURPAREN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::RCURPAREN, v, l);
  }

  Parser::symbol_type
  Parser::make_VLINE (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::VLINE, v, l);
  }

  Parser::symbol_type
  Parser::make_STAR (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::STAR, v, l);
  }

  Parser::symbol_type
  Parser::make_GREATER (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::GREATER, v, l);
  }

  Parser::symbol_type
  Parser::make_LESS (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::LESS, v, l);
  }

  Parser::symbol_type
  Parser::make_EXCLAMATION (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::EXCLAMATION, v, l);
  }

  Parser::symbol_type
  Parser::make_TILDE (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::TILDE, v, l);
  }

  Parser::symbol_type
  Parser::make_QUESTIONMARK (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::QUESTIONMARK, v, l);
  }

  Parser::symbol_type
  Parser::make_CARET (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::CARET, v, l);
  }

  Parser::symbol_type
  Parser::make_DOUBLEEXCLAMATION (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::DOUBLEEXCLAMATION, v, l);
  }

  Parser::symbol_type
  Parser::make_DOUBLEQUESTIONMARK (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::DOUBLEQUESTIONMARK, v, l);
  }

  Parser::symbol_type
  Parser::make_DOUBLEAT (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::DOUBLEAT, v, l);
  }

  Parser::symbol_type
  Parser::make_EQUALITY (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::EQUALITY, v, l);
  }

  Parser::symbol_type
  Parser::make_IMPLICATION (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::IMPLICATION, v, l);
  }

  Parser::symbol_type
  Parser::make_RIMPLICATION (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::RIMPLICATION, v, l);
  }

  Parser::symbol_type
  Parser::make_INEQUALITY (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::INEQUALITY, v, l);
  }

  Parser::symbol_type
  Parser::make_NOR (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::NOR, v, l);
  }

  Parser::symbol_type
  Parser::make_NAND (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::NAND, v, l);
  }

  Parser::symbol_type
  Parser::make_ASSIGNMENT (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::ASSIGNMENT, v, l);
  }

  Parser::symbol_type
  Parser::make_GENTZENARROW (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::GENTZENARROW, v, l);
  }

  Parser::symbol_type
  Parser::make_SUBTYPESIGN (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::SUBTYPESIGN, v, l);
  }

  Parser::symbol_type
  Parser::make_INCLUDE (const Token::Ptr& v, const location_type& l)
  {
    return symbol_type (token::INCLUDE, v, l);
  }

  Parser::symbol_type
  Parser::make_INTEGER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::INTEGER, v, l);
  }

  Parser::symbol_type
  Parser::make_REAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::REAL, v, l);
  }

  Parser::symbol_type
  Parser::make_RATIONAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RATIONAL, v, l);
  }

  Parser::symbol_type
  Parser::make_DQUOTED (const std::string& v, const location_type& l)
  {
    return symbol_type (token::DQUOTED, v, l);
  }

  Parser::symbol_type
  Parser::make_LOWER_WORD (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LOWER_WORD, v, l);
  }

  Parser::symbol_type
  Parser::make_UPPER_WORD (const std::string& v, const location_type& l)
  {
    return symbol_type (token::UPPER_WORD, v, l);
  }

  Parser::symbol_type
  Parser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IDENTIFIER, v, l);
  }

  Parser::symbol_type
  Parser::make_SINGLE_QUOTED (const std::string& v, const location_type& l)
  {
    return symbol_type (token::SINGLE_QUOTED, v, l);
  }


#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:380
} // libtptp
#line 1811 "GrammarParser.tab.h" // lalr1.cc:380




#endif // !YY_YY_GRAMMARPARSER_TAB_H_INCLUDED

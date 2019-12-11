// A Bison parser, made by GNU Bison 3.4.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file GrammarParser.tab.h
 ** Define the libtptp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
# define YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
// //                    "%code requires" blocks.
#line 60 "../../obj/src/GrammarParser.yy"

    namespace libtptp
    {
        class Lexer;
        class Logger;
    }

    #include <libtptp/Logger>
    #include <libtptp/Specification>
    #include <libtptp/Token>

    using namespace libtptp;

	//to prevent
	//error: too many arguments provided to function-like macro invocation
	//because YY_RVREF macro consumes ',' in std::pair definition and interprets it as parameter separator
	//@see: https://stackoverflow.com/a/38030161
	using UnaryConnective_t = std::pair<Token::Ptr, UnaryLogic::Connective>;
	using BinaryConnective_t = std::pair<Token::Ptr, BinaryLogic::Connective>;
	using QuantifiedQuantifier_t = std::pair<Token::Ptr, QuantifiedLogic::Quantifier>;
	using InfixConnective_t = std::pair<Token::Ptr, InfixLogic::Connective>;

    #define YY_NULLPTR nullptr

#line 73 "GrammarParser.tab.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

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
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 47 "../../obj/src/GrammarParser.yy"
namespace libtptp {
#line 189 "GrammarParser.tab.h"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
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
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // Annotations
      char dummy1[sizeof (Annotation::Ptr)];

      // TffPlainAtomic
      // TffSystemAtomic
      // FofPlainTerm
      // FofDefinedTerm
      // FofDefinedAtomicTerm
      // FofDefinedPlainTerm
      // FofSystemTerm
      // FofFunctionTerm
      char dummy2[sizeof (Atom::Ptr)];

      // ThfUnitaryType
      // ThfApplyType
      // TffAtomicType
      char dummy3[sizeof (AtomType::Ptr)];

      // NonassocConnective
      // AssocConnective
      char dummy4[sizeof (BinaryConnective_t)];

      // ThfBinaryNonassoc
      // ThfBinaryAssoc
      // ThfOrFormula
      // ThfAndFormula
      // ThfApplyFormula
      // TffBinaryFormula
      // TffBinaryNonassoc
      // TffBinaryAssoc
      // TffOrFormula
      // TffAndFormula
      // FofBinaryFormula
      // FofBinaryNonassoc
      // FofBinaryAssoc
      // FofOrFormula
      // FofAndFormula
      char dummy5[sizeof (BinaryLogic::Ptr)];

      // ThfBinaryType
      // ThfMappingType
      // ThfXprodType
      // ThfUnionType
      // TffMappingType
      // TffXprodType
      char dummy6[sizeof (BinaryType::Ptr)];

      // ThfConditional
      // TfxConditional
      char dummy7[sizeof (ConditionalTerm::Ptr)];

      // ThfConnTerm
      char dummy8[sizeof (ConnectiveAtom::Ptr)];

      // ThfSystemAtomic
      char dummy9[sizeof (ConstantAtom::Ptr)];

      // DefinedTerm
      char dummy10[sizeof (DefinedAtom::Ptr)];

      // Definition
      char dummy11[sizeof (Definition::Ptr)];

      // ThfLetDefn
      // TfxLetDefn
      char dummy12[sizeof (DefinitionAtom::Ptr)];

      // ThfLet
      // TfxLet
      char dummy13[sizeof (DefinitionTerm::Ptr)];

      // Definitions
      char dummy14[sizeof (Definitions::Ptr)];

      // DistinctObjectLiteral
      char dummy15[sizeof (DistinctObjectLiteral::Ptr)];

      // FormulaData
      char dummy16[sizeof (FormulaData::Ptr)];

      // AnnotatedFormula
      // ThfAnnotated
      // TffAnnotated
      // TcfAnnotated
      // FofAnnotated
      // CnfAnnotated
      // TpiAnnotated
      char dummy17[sizeof (FormulaDefinition::Ptr)];

      // ThfFofFunction
      char dummy18[sizeof (FunctorAtom::Ptr)];

      // GeneralData
      char dummy19[sizeof (GeneralData::Ptr)];

      // GeneralFunction
      char dummy20[sizeof (GeneralFunction::Ptr)];

      // GeneralList
      char dummy21[sizeof (GeneralList::Ptr)];

      // GeneralTerm
      char dummy22[sizeof (GeneralTerm::Ptr)];

      // TypeConstant
      // TypeFunctor
      // DefinedType
      // Atom
      // UntypedAtom
      // Constant
      // Functor
      // SystemConstant
      // SystemFunctor
      // DefinedConstant
      // DefinedFunctor
      // Name
      // AtomicWord
      // AtomicDefinedWord
      // AtomicSystemWord
      // FileName
      // LowerWordLiteral
      // SingleQuotedLiteral
      // DollarWordLiteral
      // DollarDollarWordLiteral
      char dummy23[sizeof (Identifier::Ptr)];

      // IncludeDefinition
      char dummy24[sizeof (IncludeDefinition::Ptr)];

      // DefinedInfixPred
      // InfixEquality
      // InfixInequality
      char dummy25[sizeof (InfixConnective_t)];

      // ThfInfixUnary
      // ThfDefinedInfix
      // TffInfixUnary
      // TffDefinedInfix
      // FofInfixUnary
      // FofDefinedInfixFormula
      char dummy26[sizeof (InfixLogic::Ptr)];

      // IntegerLiteral
      char dummy27[sizeof (IntegerLiteral::Ptr)];

      // FormulaSelection
      char dummy28[sizeof (ListLiteral::Ptr)];

      // ThfLetDefnList
      // ThfFormulaList
      // ThfArguments
      // TfxLetDefnList
      // TffArguments
      // TffTypeArguments
      // FofArguments
      // FofFormulaTupleList
      char dummy29[sizeof (ListLogicElements::Ptr)];

      // ThfVariableList
      // TffVariableList
      // FofVariableList
      // NameList
      // GeneralTerms
      char dummy30[sizeof (ListNodeElements::Ptr)];

      // ThfAtomTypingList
      // TffAtomTypingList
      // TffTypeList
      char dummy31[sizeof (ListTypeElements::Ptr)];

      // TpiFormula
      // ThfFormula
      // ThfLogicFormula
      // ThfBinaryFormula
      // ThfUnitFormula
      // ThfPreunitFormula
      // ThfUnitaryFormula
      // ThfUnaryFormula
      // ThfAtomicFormula
      // ThfPlainAtomic
      // ThfLetDefns
      // ThfUnitaryTerm
      // TffFormula
      // TffLogicFormula
      // TffUnitFormula
      // TffPreunitFormula
      // TffUnitaryFormula
      // TffUnaryFormula
      // TfxLetDefns
      // TfxLetLhs
      // TffTerm
      // TffUnitaryTerm
      // TcfFormula
      // TcfLogicFormula
      // FofFormula
      // FofLogicFormula
      // FofUnaryFormula
      // FofUnitFormula
      // FofUnitaryFormula
      // FofAtomicFormula
      // FofDefinedAtomicFormula
      // CnfFormula
      // Disjunction
      // Literal
      char dummy32[sizeof (Logic::Ptr)];

      // ThfTuple
      // TfxTuple
      // FofFormulaTuple
      char dummy33[sizeof (LogicTuple::Ptr)];

      // ThfQuantifiedFormula
      // TffQuantifiedFormula
      // TcfQuantifiedFormula
      // FofQuantifiedFormula
      char dummy34[sizeof (QuantifiedLogic::Ptr)];

      // ThfQuantifier
      // Th1Quantifier
      // Th0Quantifier
      // FofQuantifier
      char dummy35[sizeof (QuantifiedQuantifier_t)];

      // Tf1QuantifiedType
      char dummy36[sizeof (QuantifiedType::Ptr)];

      // RationalLiteral
      char dummy37[sizeof (RationalLiteral::Ptr)];

      // RealLiteral
      char dummy38[sizeof (RealLiteral::Ptr)];

      // FormulaRole
      char dummy39[sizeof (Role::Ptr)];

      // ThfSequent
      // TfxSequent
      // FofSequent
      char dummy40[sizeof (SequentLogic::Ptr)];

      // Specification
      char dummy41[sizeof (Specification::Ptr)];

      // ThfSubtype
      // TffSubtype
      char dummy42[sizeof (SubType::Ptr)];

      // ThfDefinedAtomic
      // TffAtomicFormula
      // TffDefinedAtomic
      // TffDefinedPlain
      // FofPlainAtomicFormula
      // FofDefinedPlainFormula
      // FofSystemAtomicFormula
      // FofTerm
      char dummy43[sizeof (Term::Ptr)];

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
      // "$$"
      // ":"
      // ","
      // "."
      // "+"
      // "="
      // "!="
      // "("
      // ")"
      // "["
      // "]"
      // "{"
      // "}"
      // "|"
      // "*"
      // ">"
      // "!"
      // "~"
      // "?"
      // "@-"
      // "@+"
      // "^"
      // "!!"
      // "??"
      // "@@+"
      // "@@-"
      // "@="
      // "!>"
      // "?*"
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
      char dummy44[sizeof (Token::Ptr)];

      // TfxTupleType
      char dummy45[sizeof (TupleType::Ptr)];

      // ThfLetTypes
      // ThfTopLevelType
      // TfxLetTypes
      // TffTopLevelType
      // TffMonotype
      // TffUnitaryType
      char dummy46[sizeof (Type::Ptr)];

      // ThfAtomTyping
      // TffAtomTyping
      char dummy47[sizeof (TypedAtom::Ptr)];

      // ThfUnaryConnective
      // Th1UnaryConnective
      // UnaryConnective
      char dummy48[sizeof (UnaryConnective_t)];

      // ThfPrefixUnary
      // TffPrefixUnary
      char dummy49[sizeof (UnaryLogic::Ptr)];

      // Number
      char dummy50[sizeof (ValueLiteral::Ptr)];

      // ThfTypedVariable
      // TfxUnitaryFormula
      // TffVariable
      // TffTypedVariable
      // Variable
      char dummy51[sizeof (VariableTerm::Ptr)];

      // "integer"
      // "real"
      // "rational"
      // "double_quoted"
      // "lower_word"
      // "upper_word"
      // "identifier"
      // "single_quoted"
      char dummy52[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef libstdhl::SourceLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

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
        DOLLARDOLLAR = 270,
        COLON = 271,
        COMMA = 272,
        DOT = 273,
        PLUS = 274,
        EQUAL = 275,
        INFIXINEQUALITY = 276,
        LPAREN = 277,
        RPAREN = 278,
        LSQPAREN = 279,
        RSQPAREN = 280,
        LCURPAREN = 281,
        RCURPAREN = 282,
        VLINE = 283,
        STAR = 284,
        GREATER = 285,
        EXCLAMATION = 286,
        TILDE = 287,
        QUESTIONMARK = 288,
        ATMINUS = 289,
        ATPLUS = 290,
        CARET = 291,
        DOUBLEEXCLAMATION = 292,
        DOUBLEQUESTIONMARK = 293,
        DOUBLEATPLUS = 294,
        DOUBLEATMINUS = 295,
        ATEQUAL = 296,
        EXCLAMATIONGREATER = 297,
        QUESTIONMARKSTAR = 298,
        EQUALITY = 299,
        IMPLICATION = 300,
        RIMPLICATION = 301,
        INEQUALITY = 302,
        NOR = 303,
        NAND = 304,
        ASSIGNMENT = 305,
        GENTZENARROW = 306,
        SUBTYPESIGN = 307,
        INCLUDE = 308,
        INTEGER = 309,
        REAL = 310,
        RATIONAL = 311,
        DQUOTED = 312,
        LOWER_WORD = 313,
        UPPER_WORD = 314,
        IDENTIFIER = 315,
        SINGLE_QUOTED = 316
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
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Annotation::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Annotation::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Atom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Atom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AtomType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AtomType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BinaryConnective_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BinaryConnective_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BinaryLogic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BinaryLogic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BinaryType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BinaryType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConditionalTerm::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConditionalTerm::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConnectiveAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConnectiveAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConstantAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConstantAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DefinedAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DefinedAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Definition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Definition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DefinitionAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DefinitionAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DefinitionTerm::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DefinitionTerm::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Definitions::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Definitions::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DistinctObjectLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DistinctObjectLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FormulaData::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FormulaData::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FormulaDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FormulaDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FunctorAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FunctorAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GeneralData::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GeneralData::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GeneralFunction::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GeneralFunction::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GeneralList::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GeneralList::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GeneralTerm::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GeneralTerm::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Identifier::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Identifier::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IncludeDefinition::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IncludeDefinition::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, InfixConnective_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const InfixConnective_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, InfixLogic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const InfixLogic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IntegerLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IntegerLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListLogicElements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListLogicElements::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListNodeElements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListNodeElements::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListTypeElements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListTypeElements::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Logic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Logic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LogicTuple::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LogicTuple::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, QuantifiedLogic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const QuantifiedLogic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, QuantifiedQuantifier_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const QuantifiedQuantifier_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, QuantifiedType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const QuantifiedType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RationalLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RationalLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RealLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RealLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Role::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Role::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SequentLogic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SequentLogic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Specification::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Specification::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SubType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SubType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Term::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Term::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Token::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Token::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TupleType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TupleType::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Type::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Type::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypedAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypedAtom::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, UnaryConnective_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const UnaryConnective_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, UnaryLogic::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const UnaryLogic::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ValueLiteral::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ValueLiteral::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VariableTerm::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VariableTerm::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
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
      case 73: // Annotations
        value.template destroy< Annotation::Ptr > ();
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.template destroy< Atom::Ptr > ();
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.template destroy< AtomType::Ptr > ();
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.template destroy< BinaryConnective_t > ();
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
        value.template destroy< BinaryLogic::Ptr > ();
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.template destroy< BinaryType::Ptr > ();
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.template destroy< ConditionalTerm::Ptr > ();
        break;

      case 108: // ThfConnTerm
        value.template destroy< ConnectiveAtom::Ptr > ();
        break;

      case 96: // ThfSystemAtomic
        value.template destroy< ConstantAtom::Ptr > ();
        break;

      case 228: // DefinedTerm
        value.template destroy< DefinedAtom::Ptr > ();
        break;

      case 65: // Definition
        value.template destroy< Definition::Ptr > ();
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.template destroy< DefinitionAtom::Ptr > ();
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.template destroy< DefinitionTerm::Ptr > ();
        break;

      case 64: // Definitions
        value.template destroy< Definitions::Ptr > ();
        break;

      case 249: // DistinctObjectLiteral
        value.template destroy< DistinctObjectLiteral::Ptr > ();
        break;

      case 236: // FormulaData
        value.template destroy< FormulaData::Ptr > ();
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.template destroy< FormulaDefinition::Ptr > ();
        break;

      case 97: // ThfFofFunction
        value.template destroy< FunctorAtom::Ptr > ();
        break;

      case 233: // GeneralData
        value.template destroy< GeneralData::Ptr > ();
        break;

      case 234: // GeneralFunction
        value.template destroy< GeneralFunction::Ptr > ();
        break;

      case 237: // GeneralList
        value.template destroy< GeneralList::Ptr > ();
        break;

      case 232: // GeneralTerm
        value.template destroy< GeneralTerm::Ptr > ();
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
        value.template destroy< Identifier::Ptr > ();
        break;

      case 238: // IncludeDefinition
        value.template destroy< IncludeDefinition::Ptr > ();
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.template destroy< InfixConnective_t > ();
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.template destroy< InfixLogic::Ptr > ();
        break;

      case 245: // IntegerLiteral
        value.template destroy< IntegerLiteral::Ptr > ();
        break;

      case 239: // FormulaSelection
        value.template destroy< ListLiteral::Ptr > ();
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.template destroy< ListLogicElements::Ptr > ();
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.template destroy< ListNodeElements::Ptr > ();
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.template destroy< ListTypeElements::Ptr > ();
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
        value.template destroy< Logic::Ptr > ();
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.template destroy< LogicTuple::Ptr > ();
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.template destroy< QuantifiedLogic::Ptr > ();
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.template destroy< QuantifiedQuantifier_t > ();
        break;

      case 158: // Tf1QuantifiedType
        value.template destroy< QuantifiedType::Ptr > ();
        break;

      case 247: // RationalLiteral
        value.template destroy< RationalLiteral::Ptr > ();
        break;

      case 246: // RealLiteral
        value.template destroy< RealLiteral::Ptr > ();
        break;

      case 231: // FormulaRole
        value.template destroy< Role::Ptr > ();
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.template destroy< SequentLogic::Ptr > ();
        break;

      case 63: // Specification
        value.template destroy< Specification::Ptr > ();
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.template destroy< SubType::Ptr > ();
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
        value.template destroy< Term::Ptr > ();
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
        value.template destroy< Token::Ptr > ();
        break;

      case 165: // TfxTupleType
        value.template destroy< TupleType::Ptr > ();
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.template destroy< Type::Ptr > ();
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.template destroy< TypedAtom::Ptr > ();
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.template destroy< UnaryConnective_t > ();
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.template destroy< UnaryLogic::Ptr > ();
        break;

      case 243: // Number
        value.template destroy< ValueLiteral::Ptr > ();
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.template destroy< VariableTerm::Ptr > ();
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

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
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::END);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, Token::Ptr v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::TPI || tok == token::THF || tok == token::TFF || tok == token::TCF || tok == token::FOF || tok == token::CNF || tok == token::FOT || tok == token::ITE || tok == token::LET || tok == token::AT || tok == token::AND || tok == token::DOLLAR || tok == token::DOLLARDOLLAR || tok == token::COLON || tok == token::COMMA || tok == token::DOT || tok == token::PLUS || tok == token::EQUAL || tok == token::INFIXINEQUALITY || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::VLINE || tok == token::STAR || tok == token::GREATER || tok == token::EXCLAMATION || tok == token::TILDE || tok == token::QUESTIONMARK || tok == token::ATMINUS || tok == token::ATPLUS || tok == token::CARET || tok == token::DOUBLEEXCLAMATION || tok == token::DOUBLEQUESTIONMARK || tok == token::DOUBLEATPLUS || tok == token::DOUBLEATMINUS || tok == token::ATEQUAL || tok == token::EXCLAMATIONGREATER || tok == token::QUESTIONMARKSTAR || tok == token::EQUALITY || tok == token::IMPLICATION || tok == token::RIMPLICATION || tok == token::INEQUALITY || tok == token::NOR || tok == token::NAND || tok == token::ASSIGNMENT || tok == token::GENTZENARROW || tok == token::SUBTYPESIGN || tok == token::INCLUDE);
      }
#else
      symbol_type (int tok, const Token::Ptr& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::TPI || tok == token::THF || tok == token::TFF || tok == token::TCF || tok == token::FOF || tok == token::CNF || tok == token::FOT || tok == token::ITE || tok == token::LET || tok == token::AT || tok == token::AND || tok == token::DOLLAR || tok == token::DOLLARDOLLAR || tok == token::COLON || tok == token::COMMA || tok == token::DOT || tok == token::PLUS || tok == token::EQUAL || tok == token::INFIXINEQUALITY || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::VLINE || tok == token::STAR || tok == token::GREATER || tok == token::EXCLAMATION || tok == token::TILDE || tok == token::QUESTIONMARK || tok == token::ATMINUS || tok == token::ATPLUS || tok == token::CARET || tok == token::DOUBLEEXCLAMATION || tok == token::DOUBLEQUESTIONMARK || tok == token::DOUBLEATPLUS || tok == token::DOUBLEATMINUS || tok == token::ATEQUAL || tok == token::EXCLAMATIONGREATER || tok == token::QUESTIONMARKSTAR || tok == token::EQUALITY || tok == token::IMPLICATION || tok == token::RIMPLICATION || tok == token::INEQUALITY || tok == token::NOR || tok == token::NAND || tok == token::ASSIGNMENT || tok == token::GENTZENARROW || tok == token::SUBTYPESIGN || tok == token::INCLUDE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::INTEGER || tok == token::REAL || tok == token::RATIONAL || tok == token::DQUOTED || tok == token::LOWER_WORD || tok == token::UPPER_WORD || tok == token::IDENTIFIER || tok == token::SINGLE_QUOTED);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::INTEGER || tok == token::REAL || tok == token::RATIONAL || tok == token::DQUOTED || tok == token::LOWER_WORD || tok == token::UPPER_WORD || tok == token::IDENTIFIER || tok == token::SINGLE_QUOTED);
      }
#endif
    };

    /// Build a parser object.
    Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg);
    virtual ~Parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

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

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TPI (Token::Ptr v, location_type l)
      {
        return symbol_type (token::TPI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TPI (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::TPI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THF (Token::Ptr v, location_type l)
      {
        return symbol_type (token::THF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THF (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::THF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TFF (Token::Ptr v, location_type l)
      {
        return symbol_type (token::TFF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TFF (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::TFF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCF (Token::Ptr v, location_type l)
      {
        return symbol_type (token::TCF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TCF (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::TCF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOF (Token::Ptr v, location_type l)
      {
        return symbol_type (token::FOF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOF (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::FOF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CNF (Token::Ptr v, location_type l)
      {
        return symbol_type (token::CNF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CNF (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::CNF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOT (Token::Ptr v, location_type l)
      {
        return symbol_type (token::FOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOT (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::FOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ITE (Token::Ptr v, location_type l)
      {
        return symbol_type (token::ITE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ITE (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ITE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (Token::Ptr v, location_type l)
      {
        return symbol_type (token::LET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (Token::Ptr v, location_type l)
      {
        return symbol_type (token::AT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::AT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (Token::Ptr v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOLLAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOLLAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLARDOLLAR (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOLLARDOLLAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLARDOLLAR (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOLLARDOLLAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (Token::Ptr v, location_type l)
      {
        return symbol_type (token::COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (Token::Ptr v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (Token::Ptr v, location_type l)
      {
        return symbol_type (token::PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (Token::Ptr v, location_type l)
      {
        return symbol_type (token::EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INFIXINEQUALITY (Token::Ptr v, location_type l)
      {
        return symbol_type (token::INFIXINEQUALITY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INFIXINEQUALITY (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INFIXINEQUALITY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSQPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::LSQPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSQPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LSQPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSQPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::RSQPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSQPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RSQPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCURPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::LCURPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LCURPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::LCURPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCURPAREN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::RCURPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCURPAREN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RCURPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VLINE (Token::Ptr v, location_type l)
      {
        return symbol_type (token::VLINE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VLINE (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::VLINE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (Token::Ptr v, location_type l)
      {
        return symbol_type (token::STAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::STAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (Token::Ptr v, location_type l)
      {
        return symbol_type (token::GREATER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::GREATER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (Token::Ptr v, location_type l)
      {
        return symbol_type (token::EXCLAMATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EXCLAMATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (Token::Ptr v, location_type l)
      {
        return symbol_type (token::TILDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::TILDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTIONMARK (Token::Ptr v, location_type l)
      {
        return symbol_type (token::QUESTIONMARK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTIONMARK (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::QUESTIONMARK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATMINUS (Token::Ptr v, location_type l)
      {
        return symbol_type (token::ATMINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATMINUS (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ATMINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATPLUS (Token::Ptr v, location_type l)
      {
        return symbol_type (token::ATPLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATPLUS (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ATPLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET (Token::Ptr v, location_type l)
      {
        return symbol_type (token::CARET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CARET (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::CARET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLEEXCLAMATION (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOUBLEEXCLAMATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLEEXCLAMATION (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOUBLEEXCLAMATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLEQUESTIONMARK (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOUBLEQUESTIONMARK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLEQUESTIONMARK (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOUBLEQUESTIONMARK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLEATPLUS (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOUBLEATPLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLEATPLUS (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOUBLEATPLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLEATMINUS (Token::Ptr v, location_type l)
      {
        return symbol_type (token::DOUBLEATMINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLEATMINUS (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::DOUBLEATMINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATEQUAL (Token::Ptr v, location_type l)
      {
        return symbol_type (token::ATEQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATEQUAL (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ATEQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATIONGREATER (Token::Ptr v, location_type l)
      {
        return symbol_type (token::EXCLAMATIONGREATER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATIONGREATER (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EXCLAMATIONGREATER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTIONMARKSTAR (Token::Ptr v, location_type l)
      {
        return symbol_type (token::QUESTIONMARKSTAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTIONMARKSTAR (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::QUESTIONMARKSTAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALITY (Token::Ptr v, location_type l)
      {
        return symbol_type (token::EQUALITY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUALITY (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::EQUALITY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPLICATION (Token::Ptr v, location_type l)
      {
        return symbol_type (token::IMPLICATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IMPLICATION (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::IMPLICATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIMPLICATION (Token::Ptr v, location_type l)
      {
        return symbol_type (token::RIMPLICATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIMPLICATION (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::RIMPLICATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INEQUALITY (Token::Ptr v, location_type l)
      {
        return symbol_type (token::INEQUALITY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INEQUALITY (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INEQUALITY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOR (Token::Ptr v, location_type l)
      {
        return symbol_type (token::NOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOR (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::NOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAND (Token::Ptr v, location_type l)
      {
        return symbol_type (token::NAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAND (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::NAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGNMENT (Token::Ptr v, location_type l)
      {
        return symbol_type (token::ASSIGNMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGNMENT (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::ASSIGNMENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GENTZENARROW (Token::Ptr v, location_type l)
      {
        return symbol_type (token::GENTZENARROW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GENTZENARROW (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::GENTZENARROW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBTYPESIGN (Token::Ptr v, location_type l)
      {
        return symbol_type (token::SUBTYPESIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUBTYPESIGN (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::SUBTYPESIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCLUDE (Token::Ptr v, location_type l)
      {
        return symbol_type (token::INCLUDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INCLUDE (const Token::Ptr& v, const location_type& l)
      {
        return symbol_type (token::INCLUDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REAL (std::string v, location_type l)
      {
        return symbol_type (token::REAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::REAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RATIONAL (std::string v, location_type l)
      {
        return symbol_type (token::RATIONAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RATIONAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RATIONAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DQUOTED (std::string v, location_type l)
      {
        return symbol_type (token::DQUOTED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DQUOTED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DQUOTED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_WORD (std::string v, location_type l)
      {
        return symbol_type (token::LOWER_WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER_WORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LOWER_WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UPPER_WORD (std::string v, location_type l)
      {
        return symbol_type (token::UPPER_WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UPPER_WORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::UPPER_WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINGLE_QUOTED (std::string v, location_type l)
      {
        return symbol_type (token::SINGLE_QUOTED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SINGLE_QUOTED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SINGLE_QUOTED, v, l);
      }
#endif


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
  static const unsigned short yydefact_[];

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

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
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
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

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
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 2748,     ///< Last index in yytable_.
      yynnts_ = 192,  ///< Number of nonterminal symbols.
      yyfinal_ = 26, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 62  ///< Number of tokens.
    };


    // User arguments.
    Logger& m_log;
    Lexer& m_lexer;
    Specification& m_specification;
  };

  inline
  Parser::token_number_type
  Parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
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
      55,    56,    57,    58,    59,    60,    61
    };
    const unsigned user_token_number_max_ = 316;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 73: // Annotations
        value.move< Annotation::Ptr > (std::move (that.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (std::move (that.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.move< AtomType::Ptr > (std::move (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.move< BinaryConnective_t > (std::move (that.value));
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
        value.move< BinaryLogic::Ptr > (std::move (that.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.move< BinaryType::Ptr > (std::move (that.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.move< ConditionalTerm::Ptr > (std::move (that.value));
        break;

      case 108: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (std::move (that.value));
        break;

      case 96: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (std::move (that.value));
        break;

      case 228: // DefinedTerm
        value.move< DefinedAtom::Ptr > (std::move (that.value));
        break;

      case 65: // Definition
        value.move< Definition::Ptr > (std::move (that.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (std::move (that.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.move< DefinitionTerm::Ptr > (std::move (that.value));
        break;

      case 64: // Definitions
        value.move< Definitions::Ptr > (std::move (that.value));
        break;

      case 249: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (std::move (that.value));
        break;

      case 236: // FormulaData
        value.move< FormulaData::Ptr > (std::move (that.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (std::move (that.value));
        break;

      case 97: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (std::move (that.value));
        break;

      case 233: // GeneralData
        value.move< GeneralData::Ptr > (std::move (that.value));
        break;

      case 234: // GeneralFunction
        value.move< GeneralFunction::Ptr > (std::move (that.value));
        break;

      case 237: // GeneralList
        value.move< GeneralList::Ptr > (std::move (that.value));
        break;

      case 232: // GeneralTerm
        value.move< GeneralTerm::Ptr > (std::move (that.value));
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
        value.move< Identifier::Ptr > (std::move (that.value));
        break;

      case 238: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (std::move (that.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.move< InfixConnective_t > (std::move (that.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (std::move (that.value));
        break;

      case 245: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (std::move (that.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (std::move (that.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (std::move (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (std::move (that.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (std::move (that.value));
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
        value.move< Logic::Ptr > (std::move (that.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (std::move (that.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (std::move (that.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (std::move (that.value));
        break;

      case 158: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (std::move (that.value));
        break;

      case 247: // RationalLiteral
        value.move< RationalLiteral::Ptr > (std::move (that.value));
        break;

      case 246: // RealLiteral
        value.move< RealLiteral::Ptr > (std::move (that.value));
        break;

      case 231: // FormulaRole
        value.move< Role::Ptr > (std::move (that.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.move< SequentLogic::Ptr > (std::move (that.value));
        break;

      case 63: // Specification
        value.move< Specification::Ptr > (std::move (that.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.move< SubType::Ptr > (std::move (that.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
        value.move< Term::Ptr > (std::move (that.value));
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
        value.move< Token::Ptr > (std::move (that.value));
        break;

      case 165: // TfxTupleType
        value.move< TupleType::Ptr > (std::move (that.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.move< Type::Ptr > (std::move (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypedAtom::Ptr > (std::move (that.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.move< UnaryConnective_t > (std::move (that.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (std::move (that.value));
        break;

      case 243: // Number
        value.move< ValueLiteral::Ptr > (std::move (that.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.move< VariableTerm::Ptr > (std::move (that.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 73: // Annotations
        value.copy< Annotation::Ptr > (YY_MOVE (that.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.copy< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.copy< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.copy< BinaryConnective_t > (YY_MOVE (that.value));
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
        value.copy< BinaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.copy< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.copy< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 108: // ThfConnTerm
        value.copy< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 96: // ThfSystemAtomic
        value.copy< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 228: // DefinedTerm
        value.copy< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 65: // Definition
        value.copy< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.copy< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.copy< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 64: // Definitions
        value.copy< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case 249: // DistinctObjectLiteral
        value.copy< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 236: // FormulaData
        value.copy< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.copy< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 97: // ThfFofFunction
        value.copy< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 233: // GeneralData
        value.copy< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case 234: // GeneralFunction
        value.copy< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case 237: // GeneralList
        value.copy< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case 232: // GeneralTerm
        value.copy< GeneralTerm::Ptr > (YY_MOVE (that.value));
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
        value.copy< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case 238: // IncludeDefinition
        value.copy< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.copy< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.copy< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 245: // IntegerLiteral
        value.copy< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.copy< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.copy< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.copy< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.copy< ListTypeElements::Ptr > (YY_MOVE (that.value));
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
        value.copy< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.copy< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.copy< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.copy< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case 158: // Tf1QuantifiedType
        value.copy< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case 247: // RationalLiteral
        value.copy< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 246: // RealLiteral
        value.copy< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
        value.copy< Role::Ptr > (YY_MOVE (that.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.copy< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 63: // Specification
        value.copy< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.copy< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
        value.copy< Term::Ptr > (YY_MOVE (that.value));
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
        value.copy< Token::Ptr > (YY_MOVE (that.value));
        break;

      case 165: // TfxTupleType
        value.copy< TupleType::Ptr > (YY_MOVE (that.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.copy< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.copy< TypedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.copy< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.copy< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case 243: // Number
        value.copy< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.copy< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
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
      case 73: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (s.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.move< Atom::Ptr > (YY_MOVE (s.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (s.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.move< BinaryConnective_t > (YY_MOVE (s.value));
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
        value.move< BinaryLogic::Ptr > (YY_MOVE (s.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.move< BinaryType::Ptr > (YY_MOVE (s.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (s.value));
        break;

      case 108: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 96: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 228: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 65: // Definition
        value.move< Definition::Ptr > (YY_MOVE (s.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (s.value));
        break;

      case 64: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (s.value));
        break;

      case 249: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 236: // FormulaData
        value.move< FormulaData::Ptr > (YY_MOVE (s.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 97: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 233: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (s.value));
        break;

      case 234: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (s.value));
        break;

      case 237: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (s.value));
        break;

      case 232: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (s.value));
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
        value.move< Identifier::Ptr > (YY_MOVE (s.value));
        break;

      case 238: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (s.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (s.value));
        break;

      case 245: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (s.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (s.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.move< ListTypeElements::Ptr > (YY_MOVE (s.value));
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
        value.move< Logic::Ptr > (YY_MOVE (s.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (s.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (s.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (s.value));
        break;

      case 158: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (s.value));
        break;

      case 247: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 246: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 231: // FormulaRole
        value.move< Role::Ptr > (YY_MOVE (s.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (s.value));
        break;

      case 63: // Specification
        value.move< Specification::Ptr > (YY_MOVE (s.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (s.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
        value.move< Term::Ptr > (YY_MOVE (s.value));
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
        value.move< Token::Ptr > (YY_MOVE (s.value));
        break;

      case 165: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (s.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (s.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (s.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (s.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (s.value));
        break;

      case 243: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (s.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
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
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  Parser::token_type
  Parser::by_type::token () const YY_NOEXCEPT
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
    };
    return token_type (yytoken_number_[type]);
  }

#line 47 "../../obj/src/GrammarParser.yy"
} // libtptp
#line 4779 "GrammarParser.tab.h"





#endif // !YY_YY_GRAMMARPARSER_TAB_H_INCLUDED

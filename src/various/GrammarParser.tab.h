<<<<<<< HEAD
// A Bison parser, made by GNU Bison 3.7.2.
=======
// A Bison parser, made by GNU Bison 3.5.
>>>>>>> f10593b (Grammar: updated built files)

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file GrammarParser.tab.h
 ** Define the libtptp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
# define YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
// "%code requires" blocks.
<<<<<<< HEAD
#line 61 "../../obj/src/GrammarParser.yy"
=======
#line 60 "../../obj/src/GrammarParser.yy"
>>>>>>> f10593b (Grammar: updated built files)

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

#line 74 "GrammarParser.tab.h"

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
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
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
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#line 48 "../../obj/src/GrammarParser.yy"
namespace libtptp {
<<<<<<< HEAD
#line 209 "GrammarParser.tab.h"
=======
#line 208 "GrammarParser.tab.h"
>>>>>>> f10593b (Grammar: updated built files)




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
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
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
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
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
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
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
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

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

      // ThfUnitaryType
      // ThfApplyType
      char dummy2[sizeof (ApplyType::Ptr)];

      // ThfLetTypes
      // ThfLetDefns
      // TffPlainAtomic
      // TffSystemAtomic
      // TfxLetTypes
      // TfxLetDefns
      // FofPlainTerm
      // FofDefinedTerm
      // FofDefinedAtomicTerm
      // FofDefinedPlainTerm
      // FofSystemTerm
      // FofFunctionTerm
      char dummy3[sizeof (Atom::Ptr)];

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

      // ThfMappingType
      // ThfUnionType
      // TffMappingType
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

      // ThfAtomTypingList
      // ThfLetDefnList
      // TffAtomTypingList
      // TfxLetDefnList
      char dummy28[sizeof (ListAtomElements::Ptr)];

      // FormulaSelection
      char dummy29[sizeof (ListLiteral::Ptr)];

      // ThfFormulaList
      // ThfArguments
      // TffArguments
      // FofArguments
      // FofFormulaTupleList
      char dummy30[sizeof (ListLogicElements::Ptr)];

      // NameList
      // GeneralTerms
      char dummy31[sizeof (ListNodeElements::Ptr)];

      // TffTypeArguments
      // TffTypeList
      char dummy32[sizeof (ListTypeElements<>::Ptr)];

      // ThfVariableList
      // TffVariableList
      // FofVariableList
      char dummy33[sizeof (ListVariableElements::Ptr)];

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
      // ThfUnitaryTerm
      // TffFormula
      // TffLogicFormula
      // TffUnitFormula
      // TffPreunitFormula
      // TffUnitaryFormula
      // TffUnaryFormula
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
      char dummy34[sizeof (Logic::Ptr)];

      // ThfTuple
      // TfxTuple
      // FofFormulaTuple
      char dummy35[sizeof (LogicTuple::Ptr)];

      // ThfQuantifiedFormula
      // TffQuantifiedFormula
      // TcfQuantifiedFormula
      // FofQuantifiedFormula
      char dummy36[sizeof (QuantifiedLogic::Ptr)];

      // ThfQuantifier
      // Th1Quantifier
      // Th0Quantifier
      // FofQuantifier
      char dummy37[sizeof (QuantifiedQuantifier_t)];

      // Tf1QuantifiedType
      char dummy38[sizeof (QuantifiedType::Ptr)];

      // RationalLiteral
      char dummy39[sizeof (RationalLiteral::Ptr)];

      // RealLiteral
      char dummy40[sizeof (RealLiteral::Ptr)];

      // ThfXprodType
      // TffXprodType
      char dummy41[sizeof (RelationType::Ptr)];

      // FormulaRole
      char dummy42[sizeof (Role::Ptr)];

      // ThfSequent
      // TfxSequent
      // FofSequent
      char dummy43[sizeof (SequentLogic::Ptr)];

      // Specification
      char dummy44[sizeof (Specification::Ptr)];

      // ThfSubtype
      // TffSubtype
      char dummy45[sizeof (SubType::Ptr)];

      // ThfDefinedAtomic
      // TffAtomicFormula
      // TffDefinedAtomic
      // TffDefinedPlain
      // FofPlainAtomicFormula
      // FofDefinedPlainFormula
      // FofSystemAtomicFormula
      // FofTerm
      char dummy46[sizeof (Term::Ptr)];

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
      char dummy47[sizeof (Token::Ptr)];

      // TfxTupleType
      char dummy48[sizeof (TupleType::Ptr)];

      // ThfTopLevelType
      // ThfBinaryType
      // TffTopLevelType
      // TffMonotype
      // TffUnitaryType
      // TffAtomicType
      char dummy49[sizeof (Type::Ptr)];

      // ThfAtomTyping
      // TffAtomTyping
      char dummy50[sizeof (TypeAtom::Ptr)];

      // ThfUnaryConnective
      // Th1UnaryConnective
      // UnaryConnective
      char dummy51[sizeof (UnaryConnective_t)];

      // ThfPrefixUnary
      // TffPrefixUnary
      char dummy52[sizeof (UnaryLogic::Ptr)];

      // Number
      char dummy53[sizeof (ValueLiteral::Ptr)];

      // ThfTypedVariable
      // TfxUnitaryFormula
      // TffVariable
      // TffTypedVariable
      // Variable
      char dummy54[sizeof (VariableTerm::Ptr)];

      // "integer"
      // "real"
      // "rational"
      // "double_quoted"
      // "lower_word"
      // "upper_word"
      // "identifier"
      // "single_quoted"
      char dummy55[sizeof (std::string)];
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

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    TPI = 258,                     // "tpi"
    THF = 259,                     // "thf"
    TFF = 260,                     // "tff"
    TCF = 261,                     // "tcf"
    FOF = 262,                     // "fof"
    CNF = 263,                     // "cnf"
    FOT = 264,                     // "fot"
    ITE = 265,                     // "ite"
    LET = 266,                     // "let"
    AT = 267,                      // "@"
    AND = 268,                     // "&"
    DOLLAR = 269,                  // "$"
    DOLLARDOLLAR = 270,            // "$$"
    COLON = 271,                   // ":"
    COMMA = 272,                   // ","
    DOT = 273,                     // "."
    PLUS = 274,                    // "+"
    EQUAL = 275,                   // "="
    INFIXINEQUALITY = 276,         // "!="
    LPAREN = 277,                  // "("
    RPAREN = 278,                  // ")"
    LSQPAREN = 279,                // "["
    RSQPAREN = 280,                // "]"
    LCURPAREN = 281,               // "{"
    RCURPAREN = 282,               // "}"
    VLINE = 283,                   // "|"
    STAR = 284,                    // "*"
    GREATER = 285,                 // ">"
    EXCLAMATION = 286,             // "!"
    TILDE = 287,                   // "~"
    QUESTIONMARK = 288,            // "?"
    ATMINUS = 289,                 // "@-"
    ATPLUS = 290,                  // "@+"
    CARET = 291,                   // "^"
    DOUBLEEXCLAMATION = 292,       // "!!"
    DOUBLEQUESTIONMARK = 293,      // "??"
    DOUBLEATPLUS = 294,            // "@@+"
    DOUBLEATMINUS = 295,           // "@@-"
    ATEQUAL = 296,                 // "@="
    EXCLAMATIONGREATER = 297,      // "!>"
    QUESTIONMARKSTAR = 298,        // "?*"
    EQUALITY = 299,                // "<=>"
    IMPLICATION = 300,             // "=>"
    RIMPLICATION = 301,            // "<="
    INEQUALITY = 302,              // "<~>"
    NOR = 303,                     // "~|"
    NAND = 304,                    // "~&"
    ASSIGNMENT = 305,              // ":="
    GENTZENARROW = 306,            // "-->"
    SUBTYPESIGN = 307,             // "<<"
    INCLUDE = 308,                 // "include"
    INTEGER = 309,                 // "integer"
    REAL = 310,                    // "real"
    RATIONAL = 311,                // "rational"
    DQUOTED = 312,                 // "double_quoted"
    LOWER_WORD = 313,              // "lower_word"
    UPPER_WORD = 314,              // "upper_word"
    IDENTIFIER = 315,              // "identifier"
    SINGLE_QUOTED = 316            // "single_quoted"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 62, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TPI = 3,                               // "tpi"
        S_THF = 4,                               // "thf"
        S_TFF = 5,                               // "tff"
        S_TCF = 6,                               // "tcf"
        S_FOF = 7,                               // "fof"
        S_CNF = 8,                               // "cnf"
        S_FOT = 9,                               // "fot"
        S_ITE = 10,                              // "ite"
        S_LET = 11,                              // "let"
        S_AT = 12,                               // "@"
        S_AND = 13,                              // "&"
        S_DOLLAR = 14,                           // "$"
        S_DOLLARDOLLAR = 15,                     // "$$"
        S_COLON = 16,                            // ":"
        S_COMMA = 17,                            // ","
        S_DOT = 18,                              // "."
        S_PLUS = 19,                             // "+"
        S_EQUAL = 20,                            // "="
        S_INFIXINEQUALITY = 21,                  // "!="
        S_LPAREN = 22,                           // "("
        S_RPAREN = 23,                           // ")"
        S_LSQPAREN = 24,                         // "["
        S_RSQPAREN = 25,                         // "]"
        S_LCURPAREN = 26,                        // "{"
        S_RCURPAREN = 27,                        // "}"
        S_VLINE = 28,                            // "|"
        S_STAR = 29,                             // "*"
        S_GREATER = 30,                          // ">"
        S_EXCLAMATION = 31,                      // "!"
        S_TILDE = 32,                            // "~"
        S_QUESTIONMARK = 33,                     // "?"
        S_ATMINUS = 34,                          // "@-"
        S_ATPLUS = 35,                           // "@+"
        S_CARET = 36,                            // "^"
        S_DOUBLEEXCLAMATION = 37,                // "!!"
        S_DOUBLEQUESTIONMARK = 38,               // "??"
        S_DOUBLEATPLUS = 39,                     // "@@+"
        S_DOUBLEATMINUS = 40,                    // "@@-"
        S_ATEQUAL = 41,                          // "@="
        S_EXCLAMATIONGREATER = 42,               // "!>"
        S_QUESTIONMARKSTAR = 43,                 // "?*"
        S_EQUALITY = 44,                         // "<=>"
        S_IMPLICATION = 45,                      // "=>"
        S_RIMPLICATION = 46,                     // "<="
        S_INEQUALITY = 47,                       // "<~>"
        S_NOR = 48,                              // "~|"
        S_NAND = 49,                             // "~&"
        S_ASSIGNMENT = 50,                       // ":="
        S_GENTZENARROW = 51,                     // "-->"
        S_SUBTYPESIGN = 52,                      // "<<"
        S_INCLUDE = 53,                          // "include"
        S_INTEGER = 54,                          // "integer"
        S_REAL = 55,                             // "real"
        S_RATIONAL = 56,                         // "rational"
        S_DQUOTED = 57,                          // "double_quoted"
        S_LOWER_WORD = 58,                       // "lower_word"
        S_UPPER_WORD = 59,                       // "upper_word"
        S_IDENTIFIER = 60,                       // "identifier"
        S_SINGLE_QUOTED = 61,                    // "single_quoted"
        S_YYACCEPT = 62,                         // $accept
        S_Specification = 63,                    // Specification
        S_Definitions = 64,                      // Definitions
        S_Definition = 65,                       // Definition
        S_AnnotatedFormula = 66,                 // AnnotatedFormula
        S_ThfAnnotated = 67,                     // ThfAnnotated
        S_TffAnnotated = 68,                     // TffAnnotated
        S_TcfAnnotated = 69,                     // TcfAnnotated
        S_FofAnnotated = 70,                     // FofAnnotated
        S_CnfAnnotated = 71,                     // CnfAnnotated
        S_TpiAnnotated = 72,                     // TpiAnnotated
        S_Annotations = 73,                      // Annotations
        S_TpiFormula = 74,                       // TpiFormula
        S_ThfFormula = 75,                       // ThfFormula
        S_ThfLogicFormula = 76,                  // ThfLogicFormula
        S_ThfBinaryFormula = 77,                 // ThfBinaryFormula
        S_ThfBinaryNonassoc = 78,                // ThfBinaryNonassoc
        S_ThfBinaryAssoc = 79,                   // ThfBinaryAssoc
        S_ThfOrFormula = 80,                     // ThfOrFormula
        S_ThfAndFormula = 81,                    // ThfAndFormula
        S_ThfApplyFormula = 82,                  // ThfApplyFormula
        S_ThfUnitFormula = 83,                   // ThfUnitFormula
        S_ThfPreunitFormula = 84,                // ThfPreunitFormula
        S_ThfUnitaryFormula = 85,                // ThfUnitaryFormula
        S_ThfQuantifiedFormula = 86,             // ThfQuantifiedFormula
        S_ThfVariableList = 87,                  // ThfVariableList
        S_ThfTypedVariable = 88,                 // ThfTypedVariable
        S_ThfUnaryFormula = 89,                  // ThfUnaryFormula
        S_ThfPrefixUnary = 90,                   // ThfPrefixUnary
        S_ThfInfixUnary = 91,                    // ThfInfixUnary
        S_ThfAtomicFormula = 92,                 // ThfAtomicFormula
        S_ThfPlainAtomic = 93,                   // ThfPlainAtomic
        S_ThfDefinedAtomic = 94,                 // ThfDefinedAtomic
        S_ThfDefinedInfix = 95,                  // ThfDefinedInfix
        S_ThfSystemAtomic = 96,                  // ThfSystemAtomic
        S_ThfFofFunction = 97,                   // ThfFofFunction
        S_ThfConditional = 98,                   // ThfConditional
        S_ThfLet = 99,                           // ThfLet
        S_ThfLetTypes = 100,                     // ThfLetTypes
        S_ThfAtomTypingList = 101,               // ThfAtomTypingList
        S_ThfLetDefns = 102,                     // ThfLetDefns
        S_ThfLetDefn = 103,                      // ThfLetDefn
        S_ThfLetDefnList = 104,                  // ThfLetDefnList
        S_ThfUnitaryTerm = 105,                  // ThfUnitaryTerm
        S_ThfTuple = 106,                        // ThfTuple
        S_ThfFormulaList = 107,                  // ThfFormulaList
        S_ThfConnTerm = 108,                     // ThfConnTerm
        S_ThfArguments = 109,                    // ThfArguments
        S_ThfAtomTyping = 110,                   // ThfAtomTyping
        S_ThfTopLevelType = 111,                 // ThfTopLevelType
        S_ThfUnitaryType = 112,                  // ThfUnitaryType
        S_ThfApplyType = 113,                    // ThfApplyType
        S_ThfBinaryType = 114,                   // ThfBinaryType
        S_ThfMappingType = 115,                  // ThfMappingType
        S_ThfXprodType = 116,                    // ThfXprodType
        S_ThfUnionType = 117,                    // ThfUnionType
        S_ThfSubtype = 118,                      // ThfSubtype
        S_ThfSequent = 119,                      // ThfSequent
        S_TffFormula = 120,                      // TffFormula
        S_TffLogicFormula = 121,                 // TffLogicFormula
        S_TffBinaryFormula = 122,                // TffBinaryFormula
        S_TffBinaryNonassoc = 123,               // TffBinaryNonassoc
        S_TffBinaryAssoc = 124,                  // TffBinaryAssoc
        S_TffOrFormula = 125,                    // TffOrFormula
        S_TffAndFormula = 126,                   // TffAndFormula
        S_TffUnitFormula = 127,                  // TffUnitFormula
        S_TffPreunitFormula = 128,               // TffPreunitFormula
        S_TffUnitaryFormula = 129,               // TffUnitaryFormula
        S_TfxUnitaryFormula = 130,               // TfxUnitaryFormula
        S_TffQuantifiedFormula = 131,            // TffQuantifiedFormula
        S_TffVariableList = 132,                 // TffVariableList
        S_TffVariable = 133,                     // TffVariable
        S_TffTypedVariable = 134,                // TffTypedVariable
        S_TffUnaryFormula = 135,                 // TffUnaryFormula
        S_TffPrefixUnary = 136,                  // TffPrefixUnary
        S_TffInfixUnary = 137,                   // TffInfixUnary
        S_TffAtomicFormula = 138,                // TffAtomicFormula
        S_TffPlainAtomic = 139,                  // TffPlainAtomic
        S_TffDefinedAtomic = 140,                // TffDefinedAtomic
        S_TffDefinedPlain = 141,                 // TffDefinedPlain
        S_TffDefinedInfix = 142,                 // TffDefinedInfix
        S_TffSystemAtomic = 143,                 // TffSystemAtomic
        S_TfxConditional = 144,                  // TfxConditional
        S_TfxLet = 145,                          // TfxLet
        S_TfxLetTypes = 146,                     // TfxLetTypes
        S_TffAtomTypingList = 147,               // TffAtomTypingList
        S_TfxLetDefns = 148,                     // TfxLetDefns
        S_TfxLetDefn = 149,                      // TfxLetDefn
        S_TfxLetLhs = 150,                       // TfxLetLhs
        S_TfxLetDefnList = 151,                  // TfxLetDefnList
        S_TffTerm = 152,                         // TffTerm
        S_TffUnitaryTerm = 153,                  // TffUnitaryTerm
        S_TfxTuple = 154,                        // TfxTuple
        S_TffArguments = 155,                    // TffArguments
        S_TffAtomTyping = 156,                   // TffAtomTyping
        S_TffTopLevelType = 157,                 // TffTopLevelType
        S_Tf1QuantifiedType = 158,               // Tf1QuantifiedType
        S_TffMonotype = 159,                     // TffMonotype
        S_TffUnitaryType = 160,                  // TffUnitaryType
        S_TffAtomicType = 161,                   // TffAtomicType
        S_TffTypeArguments = 162,                // TffTypeArguments
        S_TffMappingType = 163,                  // TffMappingType
        S_TffXprodType = 164,                    // TffXprodType
        S_TfxTupleType = 165,                    // TfxTupleType
        S_TffTypeList = 166,                     // TffTypeList
        S_TffSubtype = 167,                      // TffSubtype
        S_TfxSequent = 168,                      // TfxSequent
        S_TcfFormula = 169,                      // TcfFormula
        S_TcfLogicFormula = 170,                 // TcfLogicFormula
        S_TcfQuantifiedFormula = 171,            // TcfQuantifiedFormula
        S_FofFormula = 172,                      // FofFormula
        S_FofLogicFormula = 173,                 // FofLogicFormula
        S_FofBinaryFormula = 174,                // FofBinaryFormula
        S_FofBinaryNonassoc = 175,               // FofBinaryNonassoc
        S_FofBinaryAssoc = 176,                  // FofBinaryAssoc
        S_FofOrFormula = 177,                    // FofOrFormula
        S_FofAndFormula = 178,                   // FofAndFormula
        S_FofUnaryFormula = 179,                 // FofUnaryFormula
        S_FofInfixUnary = 180,                   // FofInfixUnary
        S_FofUnitFormula = 181,                  // FofUnitFormula
        S_FofUnitaryFormula = 182,               // FofUnitaryFormula
        S_FofQuantifiedFormula = 183,            // FofQuantifiedFormula
        S_FofVariableList = 184,                 // FofVariableList
        S_FofAtomicFormula = 185,                // FofAtomicFormula
        S_FofPlainAtomicFormula = 186,           // FofPlainAtomicFormula
        S_FofDefinedAtomicFormula = 187,         // FofDefinedAtomicFormula
        S_FofDefinedPlainFormula = 188,          // FofDefinedPlainFormula
        S_FofDefinedInfixFormula = 189,          // FofDefinedInfixFormula
        S_FofSystemAtomicFormula = 190,          // FofSystemAtomicFormula
        S_FofPlainTerm = 191,                    // FofPlainTerm
        S_FofDefinedTerm = 192,                  // FofDefinedTerm
        S_FofDefinedAtomicTerm = 193,            // FofDefinedAtomicTerm
        S_FofDefinedPlainTerm = 194,             // FofDefinedPlainTerm
        S_FofSystemTerm = 195,                   // FofSystemTerm
        S_FofArguments = 196,                    // FofArguments
        S_FofTerm = 197,                         // FofTerm
        S_FofFunctionTerm = 198,                 // FofFunctionTerm
        S_FofSequent = 199,                      // FofSequent
        S_FofFormulaTuple = 200,                 // FofFormulaTuple
        S_FofFormulaTupleList = 201,             // FofFormulaTupleList
        S_CnfFormula = 202,                      // CnfFormula
        S_Disjunction = 203,                     // Disjunction
        S_Literal = 204,                         // Literal
        S_ThfQuantifier = 205,                   // ThfQuantifier
        S_Th1Quantifier = 206,                   // Th1Quantifier
        S_Th0Quantifier = 207,                   // Th0Quantifier
        S_ThfUnaryConnective = 208,              // ThfUnaryConnective
        S_Th1UnaryConnective = 209,              // Th1UnaryConnective
        S_FofQuantifier = 210,                   // FofQuantifier
        S_NonassocConnective = 211,              // NonassocConnective
        S_AssocConnective = 212,                 // AssocConnective
        S_UnaryConnective = 213,                 // UnaryConnective
        S_TypeConstant = 214,                    // TypeConstant
        S_TypeFunctor = 215,                     // TypeFunctor
        S_DefinedType = 216,                     // DefinedType
        S_Atom = 217,                            // Atom
        S_UntypedAtom = 218,                     // UntypedAtom
        S_DefinedInfixPred = 219,                // DefinedInfixPred
        S_InfixEquality = 220,                   // InfixEquality
        S_InfixInequality = 221,                 // InfixInequality
        S_Constant = 222,                        // Constant
        S_Functor = 223,                         // Functor
        S_SystemConstant = 224,                  // SystemConstant
        S_SystemFunctor = 225,                   // SystemFunctor
        S_DefinedConstant = 226,                 // DefinedConstant
        S_DefinedFunctor = 227,                  // DefinedFunctor
        S_DefinedTerm = 228,                     // DefinedTerm
        S_NameList = 229,                        // NameList
        S_Name = 230,                            // Name
        S_FormulaRole = 231,                     // FormulaRole
        S_GeneralTerm = 232,                     // GeneralTerm
        S_GeneralData = 233,                     // GeneralData
        S_GeneralFunction = 234,                 // GeneralFunction
        S_GeneralTerms = 235,                    // GeneralTerms
        S_FormulaData = 236,                     // FormulaData
        S_GeneralList = 237,                     // GeneralList
        S_IncludeDefinition = 238,               // IncludeDefinition
        S_FormulaSelection = 239,                // FormulaSelection
        S_AtomicWord = 240,                      // AtomicWord
        S_AtomicDefinedWord = 241,               // AtomicDefinedWord
        S_AtomicSystemWord = 242,                // AtomicSystemWord
        S_Number = 243,                          // Number
        S_FileName = 244,                        // FileName
        S_IntegerLiteral = 245,                  // IntegerLiteral
        S_RealLiteral = 246,                     // RealLiteral
        S_RationalLiteral = 247,                 // RationalLiteral
        S_Variable = 248,                        // Variable
        S_DistinctObjectLiteral = 249,           // DistinctObjectLiteral
        S_LowerWordLiteral = 250,                // LowerWordLiteral
        S_SingleQuotedLiteral = 251,             // SingleQuotedLiteral
        S_DollarWordLiteral = 252,               // DollarWordLiteral
        S_DollarDollarWordLiteral = 253          // DollarDollarWordLiteral
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

<<<<<<< HEAD
    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;
=======
    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;
>>>>>>> f10593b (Grammar: updated built files)

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
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
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.move< Annotation::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_TffPlainAtomic: // TffPlainAtomic
      case symbol_kind::S_TffSystemAtomic: // TffSystemAtomic
      case symbol_kind::S_FofPlainTerm: // FofPlainTerm
      case symbol_kind::S_FofDefinedTerm: // FofDefinedTerm
      case symbol_kind::S_FofDefinedAtomicTerm: // FofDefinedAtomicTerm
      case symbol_kind::S_FofDefinedPlainTerm: // FofDefinedPlainTerm
      case symbol_kind::S_FofSystemTerm: // FofSystemTerm
      case symbol_kind::S_FofFunctionTerm: // FofFunctionTerm
        value.move< Atom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.move< AtomType::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
        value.move< BinaryConnective_t > (std::move (that.value));
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
        value.move< BinaryLogic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfBinaryType: // ThfBinaryType
      case symbol_kind::S_ThfMappingType: // ThfMappingType
      case symbol_kind::S_ThfXprodType: // ThfXprodType
      case symbol_kind::S_ThfUnionType: // ThfUnionType
      case symbol_kind::S_TffMappingType: // TffMappingType
      case symbol_kind::S_TffXprodType: // TffXprodType
        value.move< BinaryType::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.move< ConditionalTerm::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.move< DefinedAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_Definition: // Definition
        value.move< Definition::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.move< DefinitionTerm::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.move< Definitions::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.move< FormulaData::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.move< GeneralData::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.move< GeneralFunction::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.move< GeneralList::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.move< GeneralTerm::Ptr > (std::move (that.value));
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
        value.move< Identifier::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.move< InfixConnective_t > (std::move (that.value));
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.move< ListLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.move< ListNodeElements::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.move< ListTypeElements::Ptr > (std::move (that.value));
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
        value.move< Logic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (std::move (that.value));
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.move< RationalLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.move< RealLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_FormulaRole: // FormulaRole
        value.move< Role::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.move< SequentLogic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_Specification: // Specification
        value.move< Specification::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.move< SubType::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.move< Term::Ptr > (std::move (that.value));
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
        value.move< Token::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.move< TupleType::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.move< Type::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.move< TypedAtom::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.move< UnaryConnective_t > (std::move (that.value));
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.move< ValueLiteral::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.move< VariableTerm::Ptr > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
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
      basic_symbol (typename Base::kind_type t, ApplyType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ApplyType::Ptr& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, ListAtomElements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListAtomElements::Ptr& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, ListTypeElements<>::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListTypeElements<>::Ptr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListVariableElements::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListVariableElements::Ptr& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, RelationType::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RelationType::Ptr& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, TypeAtom::Ptr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeAtom::Ptr& v, const location_type& l)
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
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_Annotations: // Annotations
        value.template destroy< Annotation::Ptr > ();
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
        value.template destroy< Atom::Ptr > ();
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.template destroy< AtomType::Ptr > ();
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.template destroy< ApplyType::Ptr > ();
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
        value.template destroy< Atom::Ptr > ();
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.template destroy< BinaryConnective_t > ();
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
        value.template destroy< BinaryLogic::Ptr > ();
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
        value.template destroy< BinaryType::Ptr > ();
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.template destroy< ConditionalTerm::Ptr > ();
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.template destroy< ConnectiveAtom::Ptr > ();
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.template destroy< ConstantAtom::Ptr > ();
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.template destroy< DefinedAtom::Ptr > ();
        break;

      case symbol_kind::S_Definition: // Definition
        value.template destroy< Definition::Ptr > ();
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.template destroy< DefinitionAtom::Ptr > ();
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.template destroy< DefinitionTerm::Ptr > ();
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.template destroy< Definitions::Ptr > ();
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.template destroy< DistinctObjectLiteral::Ptr > ();
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.template destroy< FormulaData::Ptr > ();
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.template destroy< FormulaDefinition::Ptr > ();
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.template destroy< FunctorAtom::Ptr > ();
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.template destroy< GeneralData::Ptr > ();
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.template destroy< GeneralFunction::Ptr > ();
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.template destroy< GeneralList::Ptr > ();
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.template destroy< GeneralTerm::Ptr > ();
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
        value.template destroy< Identifier::Ptr > ();
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.template destroy< IncludeDefinition::Ptr > ();
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.template destroy< InfixConnective_t > ();
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.template destroy< InfixLogic::Ptr > ();
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.template destroy< IntegerLiteral::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.template destroy< ListLiteral::Ptr > ();
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.template destroy< ListLogicElements::Ptr > ();
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.template destroy< ListNodeElements::Ptr > ();
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.template destroy< ListTypeElements::Ptr > ();
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
        value.template destroy< ListAtomElements::Ptr > ();
        break;

      case 239: // FormulaSelection
        value.template destroy< ListLiteral::Ptr > ();
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.template destroy< ListLogicElements::Ptr > ();
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.template destroy< ListNodeElements::Ptr > ();
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.template destroy< ListTypeElements<>::Ptr > ();
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.template destroy< ListVariableElements::Ptr > ();
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
        value.template destroy< Logic::Ptr > ();
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.template destroy< LogicTuple::Ptr > ();
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.template destroy< QuantifiedLogic::Ptr > ();
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.template destroy< QuantifiedQuantifier_t > ();
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.template destroy< QuantifiedType::Ptr > ();
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.template destroy< RationalLiteral::Ptr > ();
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.template destroy< RealLiteral::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.template destroy< RelationType::Ptr > ();
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.template destroy< Role::Ptr > ();
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.template destroy< SequentLogic::Ptr > ();
        break;

      case symbol_kind::S_Specification: // Specification
        value.template destroy< Specification::Ptr > ();
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.template destroy< SubType::Ptr > ();
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.template destroy< Term::Ptr > ();
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
        value.template destroy< Token::Ptr > ();
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.template destroy< TupleType::Ptr > ();
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.template destroy< Type::Ptr > ();
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.template destroy< TypedAtom::Ptr > ();
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.template destroy< Type::Ptr > ();
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.template destroy< TypeAtom::Ptr > ();
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.template destroy< UnaryConnective_t > ();
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.template destroy< UnaryLogic::Ptr > ();
        break;

      case symbol_kind::S_Number: // Number
        value.template destroy< ValueLiteral::Ptr > ();
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.template destroy< VariableTerm::Ptr > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

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
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

<<<<<<< HEAD
      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
=======
      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
>>>>>>> f10593b (Grammar: updated built files)
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
<<<<<<< HEAD
        YY_ASSERT (tok == token::END || tok == token::YYerror || tok == token::YYUNDEF);
=======
        YY_ASSERT (tok == token::END);
>>>>>>> f10593b (Grammar: updated built files)
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
<<<<<<< HEAD
        YY_ASSERT (tok == token::END || tok == token::YYerror || tok == token::YYUNDEF);
=======
        YY_ASSERT (tok == token::END);
>>>>>>> f10593b (Grammar: updated built files)
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, Token::Ptr v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TPI || tok == token::THF || tok == token::TFF || tok == token::TCF || tok == token::FOF || tok == token::CNF || tok == token::FOT || tok == token::ITE || tok == token::LET || tok == token::AT || tok == token::AND || tok == token::DOLLAR || tok == token::DOLLARDOLLAR || tok == token::COLON || tok == token::COMMA || tok == token::DOT || tok == token::PLUS || tok == token::EQUAL || tok == token::INFIXINEQUALITY || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::VLINE || tok == token::STAR || tok == token::GREATER || tok == token::EXCLAMATION || tok == token::TILDE || tok == token::QUESTIONMARK || tok == token::ATMINUS || tok == token::ATPLUS || tok == token::CARET || tok == token::DOUBLEEXCLAMATION || tok == token::DOUBLEQUESTIONMARK || tok == token::DOUBLEATPLUS || tok == token::DOUBLEATMINUS || tok == token::ATEQUAL || tok == token::EXCLAMATIONGREATER || tok == token::QUESTIONMARKSTAR || tok == token::EQUALITY || tok == token::IMPLICATION || tok == token::RIMPLICATION || tok == token::INEQUALITY || tok == token::NOR || tok == token::NAND || tok == token::ASSIGNMENT || tok == token::GENTZENARROW || tok == token::SUBTYPESIGN || tok == token::INCLUDE);
      }
#else
      symbol_type (int tok, const Token::Ptr& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TPI || tok == token::THF || tok == token::TFF || tok == token::TCF || tok == token::FOF || tok == token::CNF || tok == token::FOT || tok == token::ITE || tok == token::LET || tok == token::AT || tok == token::AND || tok == token::DOLLAR || tok == token::DOLLARDOLLAR || tok == token::COLON || tok == token::COMMA || tok == token::DOT || tok == token::PLUS || tok == token::EQUAL || tok == token::INFIXINEQUALITY || tok == token::LPAREN || tok == token::RPAREN || tok == token::LSQPAREN || tok == token::RSQPAREN || tok == token::LCURPAREN || tok == token::RCURPAREN || tok == token::VLINE || tok == token::STAR || tok == token::GREATER || tok == token::EXCLAMATION || tok == token::TILDE || tok == token::QUESTIONMARK || tok == token::ATMINUS || tok == token::ATPLUS || tok == token::CARET || tok == token::DOUBLEEXCLAMATION || tok == token::DOUBLEQUESTIONMARK || tok == token::DOUBLEATPLUS || tok == token::DOUBLEATMINUS || tok == token::ATEQUAL || tok == token::EXCLAMATIONGREATER || tok == token::QUESTIONMARKSTAR || tok == token::EQUALITY || tok == token::IMPLICATION || tok == token::RIMPLICATION || tok == token::INEQUALITY || tok == token::NOR || tok == token::NAND || tok == token::ASSIGNMENT || tok == token::GENTZENARROW || tok == token::SUBTYPESIGN || tok == token::INCLUDE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::INTEGER || tok == token::REAL || tok == token::RATIONAL || tok == token::DQUOTED || tok == token::LOWER_WORD || tok == token::UPPER_WORD || tok == token::IDENTIFIER || tok == token::SINGLE_QUOTED);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::INTEGER || tok == token::REAL || tok == token::RATIONAL || tok == token::DQUOTED || tok == token::LOWER_WORD || tok == token::UPPER_WORD || tok == token::IDENTIFIER || tok == token::SINGLE_QUOTED);
      }
#endif
    };

    /// Build a parser object.
    Parser (Logger& m_log_yyarg, Lexer& m_lexer_yyarg, Specification& m_specification_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

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

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

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
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
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


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif

<<<<<<< HEAD
=======
    /// Stored state numbers (used for stacks).
    typedef short state_type;
>>>>>>> f10593b (Grammar: updated built files)

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

<<<<<<< HEAD
    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

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
=======
    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

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
    static const signed char yyr2_[];
>>>>>>> f10593b (Grammar: updated built files)

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
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

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

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

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

<<<<<<< HEAD
#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

=======
>>>>>>> f10593b (Grammar: updated built files)
      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
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
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
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
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
<<<<<<< HEAD
=======
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
>>>>>>> f10593b (Grammar: updated built files)
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
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

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yylast_ = 2748,     ///< Last index in yytable_.
      yynnts_ = 192,  ///< Number of nonterminal symbols.
<<<<<<< HEAD
      yyfinal_ = 26 ///< Termination state number.
=======
      yyfinal_ = 26, ///< Termination state number.
      yyntokens_ = 62  ///< Number of tokens.
>>>>>>> f10593b (Grammar: updated built files)
    };


    // User arguments.
    Logger& m_log;
    Lexer& m_lexer;
    Specification& m_specification;

  };

  inline
<<<<<<< HEAD
  Parser::symbol_kind_type
=======
  Parser::token_number_type
>>>>>>> f10593b (Grammar: updated built files)
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
<<<<<<< HEAD
    // Last valid token kind.
    const int code_max = 316;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
=======
    const int user_token_number_max_ = 316;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
>>>>>>> f10593b (Grammar: updated built files)
  }

  // basic_symbol.
<<<<<<< HEAD
=======
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

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.move< ApplyType::Ptr > (std::move (that.value));
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
        value.move< Atom::Ptr > (std::move (that.value));
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

      case 115: // ThfMappingType
      case 117: // ThfUnionType
      case 163: // TffMappingType
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

      case 101: // ThfAtomTypingList
      case 104: // ThfLetDefnList
      case 147: // TffAtomTypingList
      case 151: // TfxLetDefnList
        value.move< ListAtomElements::Ptr > (std::move (that.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (std::move (that.value));
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (std::move (that.value));
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (std::move (that.value));
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.move< ListTypeElements<>::Ptr > (std::move (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.move< ListVariableElements::Ptr > (std::move (that.value));
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

      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.move< RelationType::Ptr > (std::move (that.value));
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

      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.move< Type::Ptr > (std::move (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypeAtom::Ptr > (std::move (that.value));
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

>>>>>>> 508276a (GrammarParser: commmit built files)
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.copy< Annotation::Ptr > (YY_MOVE (that.value));
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
        value.copy< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.copy< AtomType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.copy< ApplyType::Ptr > (YY_MOVE (that.value));
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
        value.copy< Atom::Ptr > (YY_MOVE (that.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.copy< BinaryConnective_t > (YY_MOVE (that.value));
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
        value.copy< BinaryLogic::Ptr > (YY_MOVE (that.value));
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
        value.copy< BinaryType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.copy< ConditionalTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.copy< ConnectiveAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.copy< ConstantAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.copy< DefinedAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definition: // Definition
        value.copy< Definition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.copy< DefinitionAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.copy< DefinitionTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.copy< Definitions::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.copy< DistinctObjectLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.copy< FormulaData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.copy< FormulaDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.copy< FunctorAtom::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.copy< GeneralData::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.copy< GeneralFunction::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.copy< GeneralList::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.copy< GeneralTerm::Ptr > (YY_MOVE (that.value));
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
        value.copy< Identifier::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.copy< IncludeDefinition::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.copy< InfixConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.copy< InfixLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.copy< IntegerLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.copy< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.copy< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.copy< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.copy< ListTypeElements::Ptr > (YY_MOVE (that.value));
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
        value.copy< ListAtomElements::Ptr > (YY_MOVE (that.value));
        break;

      case 239: // FormulaSelection
        value.copy< ListLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.copy< ListLogicElements::Ptr > (YY_MOVE (that.value));
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.copy< ListNodeElements::Ptr > (YY_MOVE (that.value));
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.copy< ListTypeElements<>::Ptr > (YY_MOVE (that.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.copy< ListVariableElements::Ptr > (YY_MOVE (that.value));
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
        value.copy< Logic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.copy< LogicTuple::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.copy< QuantifiedLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.copy< QuantifiedQuantifier_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.copy< QuantifiedType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.copy< RationalLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.copy< RealLiteral::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.copy< RelationType::Ptr > (YY_MOVE (that.value));
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.copy< Role::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.copy< SequentLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Specification: // Specification
        value.copy< Specification::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.copy< SubType::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.copy< Term::Ptr > (YY_MOVE (that.value));
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
        value.copy< Token::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.copy< TupleType::Ptr > (YY_MOVE (that.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.copy< Type::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.copy< TypedAtom::Ptr > (YY_MOVE (that.value));
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.copy< Type::Ptr > (YY_MOVE (that.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.copy< TypeAtom::Ptr > (YY_MOVE (that.value));
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.copy< UnaryConnective_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.copy< UnaryLogic::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.copy< ValueLiteral::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.copy< VariableTerm::Ptr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_Annotations: // Annotations
        value.move< Annotation::Ptr > (YY_MOVE (s.value));
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
        value.move< Atom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfUnitaryType: // ThfUnitaryType
      case symbol_kind::S_ThfApplyType: // ThfApplyType
      case symbol_kind::S_TffAtomicType: // TffAtomicType
        value.move< AtomType::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NonassocConnective: // NonassocConnective
      case symbol_kind::S_AssocConnective: // AssocConnective
=======
      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
        value.move< ApplyType::Ptr > (YY_MOVE (s.value));
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
        value.move< Atom::Ptr > (YY_MOVE (s.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< BinaryConnective_t > (YY_MOVE (s.value));
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
        value.move< BinaryLogic::Ptr > (YY_MOVE (s.value));
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
        value.move< BinaryType::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfConditional: // ThfConditional
      case symbol_kind::S_TfxConditional: // TfxConditional
        value.move< ConditionalTerm::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfConnTerm: // ThfConnTerm
        value.move< ConnectiveAtom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfSystemAtomic: // ThfSystemAtomic
        value.move< ConstantAtom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DefinedTerm: // DefinedTerm
        value.move< DefinedAtom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Definition: // Definition
        value.move< Definition::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfLetDefn: // ThfLetDefn
      case symbol_kind::S_TfxLetDefn: // TfxLetDefn
        value.move< DefinitionAtom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfLet: // ThfLet
      case symbol_kind::S_TfxLet: // TfxLet
        value.move< DefinitionTerm::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Definitions: // Definitions
        value.move< Definitions::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DistinctObjectLiteral: // DistinctObjectLiteral
        value.move< DistinctObjectLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FormulaData: // FormulaData
        value.move< FormulaData::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_AnnotatedFormula: // AnnotatedFormula
      case symbol_kind::S_ThfAnnotated: // ThfAnnotated
      case symbol_kind::S_TffAnnotated: // TffAnnotated
      case symbol_kind::S_TcfAnnotated: // TcfAnnotated
      case symbol_kind::S_FofAnnotated: // FofAnnotated
      case symbol_kind::S_CnfAnnotated: // CnfAnnotated
      case symbol_kind::S_TpiAnnotated: // TpiAnnotated
        value.move< FormulaDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfFofFunction: // ThfFofFunction
        value.move< FunctorAtom::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_GeneralData: // GeneralData
        value.move< GeneralData::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_GeneralFunction: // GeneralFunction
        value.move< GeneralFunction::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_GeneralList: // GeneralList
        value.move< GeneralList::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_GeneralTerm: // GeneralTerm
        value.move< GeneralTerm::Ptr > (YY_MOVE (s.value));
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
        value.move< Identifier::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IncludeDefinition: // IncludeDefinition
        value.move< IncludeDefinition::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DefinedInfixPred: // DefinedInfixPred
      case symbol_kind::S_InfixEquality: // InfixEquality
      case symbol_kind::S_InfixInequality: // InfixInequality
        value.move< InfixConnective_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfInfixUnary: // ThfInfixUnary
      case symbol_kind::S_ThfDefinedInfix: // ThfDefinedInfix
      case symbol_kind::S_TffInfixUnary: // TffInfixUnary
      case symbol_kind::S_TffDefinedInfix: // TffDefinedInfix
      case symbol_kind::S_FofInfixUnary: // FofInfixUnary
      case symbol_kind::S_FofDefinedInfixFormula: // FofDefinedInfixFormula
        value.move< InfixLogic::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IntegerLiteral: // IntegerLiteral
        value.move< IntegerLiteral::Ptr > (YY_MOVE (s.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaSelection: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfLetDefnList: // ThfLetDefnList
      case symbol_kind::S_ThfFormulaList: // ThfFormulaList
      case symbol_kind::S_ThfArguments: // ThfArguments
      case symbol_kind::S_TfxLetDefnList: // TfxLetDefnList
      case symbol_kind::S_TffArguments: // TffArguments
      case symbol_kind::S_TffTypeArguments: // TffTypeArguments
      case symbol_kind::S_FofArguments: // FofArguments
      case symbol_kind::S_FofFormulaTupleList: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfVariableList: // ThfVariableList
      case symbol_kind::S_TffVariableList: // TffVariableList
      case symbol_kind::S_FofVariableList: // FofVariableList
      case symbol_kind::S_NameList: // NameList
      case symbol_kind::S_GeneralTerms: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfAtomTypingList: // ThfAtomTypingList
      case symbol_kind::S_TffAtomTypingList: // TffAtomTypingList
      case symbol_kind::S_TffTypeList: // TffTypeList
        value.move< ListTypeElements::Ptr > (YY_MOVE (s.value));
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
        value.move< ListAtomElements::Ptr > (YY_MOVE (s.value));
        break;

      case 239: // FormulaSelection
        value.move< ListLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 155: // TffArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< ListLogicElements::Ptr > (YY_MOVE (s.value));
        break;

      case 229: // NameList
      case 235: // GeneralTerms
        value.move< ListNodeElements::Ptr > (YY_MOVE (s.value));
        break;

      case 162: // TffTypeArguments
      case 166: // TffTypeList
        value.move< ListTypeElements<>::Ptr > (YY_MOVE (s.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
        value.move< ListVariableElements::Ptr > (YY_MOVE (s.value));
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
        value.move< Logic::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfTuple: // ThfTuple
      case symbol_kind::S_TfxTuple: // TfxTuple
      case symbol_kind::S_FofFormulaTuple: // FofFormulaTuple
        value.move< LogicTuple::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfQuantifiedFormula: // ThfQuantifiedFormula
      case symbol_kind::S_TffQuantifiedFormula: // TffQuantifiedFormula
      case symbol_kind::S_TcfQuantifiedFormula: // TcfQuantifiedFormula
      case symbol_kind::S_FofQuantifiedFormula: // FofQuantifiedFormula
        value.move< QuantifiedLogic::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfQuantifier: // ThfQuantifier
      case symbol_kind::S_Th1Quantifier: // Th1Quantifier
      case symbol_kind::S_Th0Quantifier: // Th0Quantifier
      case symbol_kind::S_FofQuantifier: // FofQuantifier
        value.move< QuantifiedQuantifier_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Tf1QuantifiedType: // Tf1QuantifiedType
        value.move< QuantifiedType::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_RationalLiteral: // RationalLiteral
        value.move< RationalLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_RealLiteral: // RealLiteral
        value.move< RealLiteral::Ptr > (YY_MOVE (s.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_FormulaRole: // FormulaRole
=======
      case 116: // ThfXprodType
      case 164: // TffXprodType
        value.move< RelationType::Ptr > (YY_MOVE (s.value));
        break;

      case 231: // FormulaRole
>>>>>>> 508276a (GrammarParser: commmit built files)
        value.move< Role::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfSequent: // ThfSequent
      case symbol_kind::S_TfxSequent: // TfxSequent
      case symbol_kind::S_FofSequent: // FofSequent
        value.move< SequentLogic::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Specification: // Specification
        value.move< Specification::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfSubtype: // ThfSubtype
      case symbol_kind::S_TffSubtype: // TffSubtype
        value.move< SubType::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfDefinedAtomic: // ThfDefinedAtomic
      case symbol_kind::S_TffAtomicFormula: // TffAtomicFormula
      case symbol_kind::S_TffDefinedAtomic: // TffDefinedAtomic
      case symbol_kind::S_TffDefinedPlain: // TffDefinedPlain
      case symbol_kind::S_FofPlainAtomicFormula: // FofPlainAtomicFormula
      case symbol_kind::S_FofDefinedPlainFormula: // FofDefinedPlainFormula
      case symbol_kind::S_FofSystemAtomicFormula: // FofSystemAtomicFormula
      case symbol_kind::S_FofTerm: // FofTerm
        value.move< Term::Ptr > (YY_MOVE (s.value));
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
        value.move< Token::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TfxTupleType: // TfxTupleType
        value.move< TupleType::Ptr > (YY_MOVE (s.value));
        break;

<<<<<<< HEAD
      case symbol_kind::S_ThfLetTypes: // ThfLetTypes
      case symbol_kind::S_ThfTopLevelType: // ThfTopLevelType
      case symbol_kind::S_TfxLetTypes: // TfxLetTypes
      case symbol_kind::S_TffTopLevelType: // TffTopLevelType
      case symbol_kind::S_TffMonotype: // TffMonotype
      case symbol_kind::S_TffUnitaryType: // TffUnitaryType
        value.move< Type::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfAtomTyping: // ThfAtomTyping
      case symbol_kind::S_TffAtomTyping: // TffAtomTyping
        value.move< TypedAtom::Ptr > (YY_MOVE (s.value));
=======
      case 111: // ThfTopLevelType
      case 114: // ThfBinaryType
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
      case 161: // TffAtomicType
        value.move< Type::Ptr > (YY_MOVE (s.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.move< TypeAtom::Ptr > (YY_MOVE (s.value));
>>>>>>> 508276a (GrammarParser: commmit built files)
        break;

      case symbol_kind::S_ThfUnaryConnective: // ThfUnaryConnective
      case symbol_kind::S_Th1UnaryConnective: // Th1UnaryConnective
      case symbol_kind::S_UnaryConnective: // UnaryConnective
        value.move< UnaryConnective_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfPrefixUnary: // ThfPrefixUnary
      case symbol_kind::S_TffPrefixUnary: // TffPrefixUnary
        value.move< UnaryLogic::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Number: // Number
        value.move< ValueLiteral::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ThfTypedVariable: // ThfTypedVariable
      case symbol_kind::S_TfxUnitaryFormula: // TfxUnitaryFormula
      case symbol_kind::S_TffVariable: // TffVariable
      case symbol_kind::S_TffTypedVariable: // TffTypedVariable
      case symbol_kind::S_Variable: // Variable
        value.move< VariableTerm::Ptr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_RATIONAL: // "rational"
      case symbol_kind::S_DQUOTED: // "double_quoted"
      case symbol_kind::S_LOWER_WORD: // "lower_word"
      case symbol_kind::S_UPPER_WORD: // "upper_word"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_SINGLE_QUOTED: // "single_quoted"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

<<<<<<< HEAD
  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 48 "../../obj/src/GrammarParser.yy"
} // libtptp
<<<<<<< HEAD
#line 5140 "GrammarParser.tab.h"
=======
#line 4860 "GrammarParser.tab.h"
=======
#line 47 "../../obj/src/GrammarParser.yy"
} // libtptp
#line 4852 "GrammarParser.tab.h"
>>>>>>> f10593b (Grammar: updated built files)

>>>>>>> 508276a (GrammarParser: commmit built files)




#endif // !YY_YY_GRAMMARPARSER_TAB_H_INCLUDED

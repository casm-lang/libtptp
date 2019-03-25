// A Bison parser, made by GNU Bison 3.2.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
# define YY_YY_GRAMMARPARSER_TAB_H_INCLUDED
// //                    "%code requires" blocks.
#line 61 "../../obj/src/GrammarParser.yy" // lalr1.cc:403

    namespace libtptp
    {
        class Lexer;
        class Logger;
        class SourceLocation;
    }


    #include <libtptp/Specification>
    #include <libtptp/Token>

	#include <libtptp/Logger>

    #include "../../src/SourceLocation.h"

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

#line 78 "GrammarParser.tab.h" // lalr1.cc:403

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

// Support move semantics when possible.
#if defined __cplusplus && 201103L <= __cplusplus
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

#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:403
namespace libtptp {
#line 172 "GrammarParser.tab.h" // lalr1.cc:403

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
      operator[](0).move (t);
    }

    void
    pop (int n = 1)
    {
      for (; 0 < n; --n)
        seq_.pop_back ();
    }

    void
    clear ()
    {
      seq_.clear ();
    }

    size_type
    size () const
    {
      return seq_.size ();
    }

    const_iterator
    begin () const
    {
      return seq_.rbegin ();
    }

    const_iterator
    end () const
    {
      return seq_.rend ();
    }

  private:
    stack (const stack&);
    stack& operator= (const stack&);
    /// The wrapped container.
    S seq_;
  };

  /// Present a slice of the top of a stack.
  template <typename T, typename S = stack<T> >
  class slice
  {
  public:
    slice (const S& stack, int range)
      : stack_ (stack)
      , range_ (range)
    {}

    const T&
    operator[] (int i) const
    {
      return stack_[range_ - i];
    }

  private:
    const S& stack_;
    int range_;
  };



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
    variant (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

# if defined __cplusplus && 201103L <= __cplusplus
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename U>
    T&
    emplace (U&& u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u));
    }
# else
    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
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
    /// should not be the variant's responsibility.
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
# if defined __cplusplus && 201103L <= __cplusplus
      emplace<T> (std::move (other.as<T> ()));
# else
      emplace<T> ();
      swap<T> (other);
# endif
      other.destroy<T> ();
    }

# if defined __cplusplus && 201103L <= __cplusplus
    /// Move the content of \a other to this.
    template <typename T>
    void
    move (self_type&& other)
    {
      emplace<T> (std::move (other.as<T> ()));
      other.destroy<T> ();
    }
#endif

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      emplace<T> (other.as<T> ());
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
      char dummy29[sizeof (Logic::Ptr)];

      // ThfTuple
      // TfxTuple
      // FofFormulaTuple
      char dummy30[sizeof (LogicTuple::Ptr)];

      // ThfLetDefnList
      // ThfFormulaList
      // ThfArguments
      // TfxLetDefnList
      // TffArguments
      // TffTypeArguments
      // FofArguments
      // FofFormulaTupleList
      char dummy31[sizeof (Logics::Ptr)];

      // ThfVariableList
      // TffVariableList
      // FofVariableList
      // NameList
      // GeneralTerms
      char dummy32[sizeof (Nodes::Ptr)];

      // ThfQuantifiedFormula
      // TffQuantifiedFormula
      // TcfQuantifiedFormula
      // FofQuantifiedFormula
      char dummy33[sizeof (QuantifiedLogic::Ptr)];

      // ThfQuantifier
      // Th1Quantifier
      // Th0Quantifier
      // FofQuantifier
      char dummy34[sizeof (QuantifiedQuantifier_t)];

      // Tf1QuantifiedType
      char dummy35[sizeof (QuantifiedType::Ptr)];

      // RationalLiteral
      char dummy36[sizeof (RationalLiteral::Ptr)];

      // RealLiteral
      char dummy37[sizeof (RealLiteral::Ptr)];

      // FormulaRole
      char dummy38[sizeof (Role::Ptr)];

      // ThfSequent
      // TfxSequent
      // FofSequent
      char dummy39[sizeof (SequentLogic::Ptr)];

      // Specification
      char dummy40[sizeof (Specification::Ptr)];

      // ThfSubtype
      // TffSubtype
      char dummy41[sizeof (SubType::Ptr)];

      // ThfDefinedAtomic
      // TffAtomicFormula
      // TffDefinedAtomic
      // TffDefinedPlain
      // FofPlainAtomicFormula
      // FofDefinedPlainFormula
      // FofSystemAtomicFormula
      // FofTerm
      char dummy42[sizeof (Term::Ptr)];

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
      char dummy43[sizeof (Token::Ptr)];

      // TfxTupleType
      char dummy44[sizeof (TupleType::Ptr)];

      // ThfLetTypes
      // ThfTopLevelType
      // TfxLetTypes
      // TffTopLevelType
      // TffMonotype
      // TffUnitaryType
      char dummy45[sizeof (Type::Ptr)];

      // ThfAtomTyping
      // TffAtomTyping
      char dummy46[sizeof (TypedAtom::Ptr)];

      // ThfAtomTypingList
      // TffAtomTypingList
      // TffTypeList
      char dummy47[sizeof (Types::Ptr)];

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

    /// Symbol semantic values.
    typedef variant<sizeof (union_type)> semantic_type;
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
      basic_symbol ();

      /// Move or copy constructor.
      basic_symbol (YY_RVREF (basic_symbol) other);


      /// Constructor for valueless symbols, and symbols from each type.
      basic_symbol (typename Base::kind_type t, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Annotation::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Atom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (AtomType::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryConnective_t) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryLogic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryType::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (ConditionalTerm::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (ConnectiveAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (ConstantAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (DefinedAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Definition::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (DefinitionAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (DefinitionTerm::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Definitions::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (DistinctObjectLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (FormulaData::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (FormulaDefinition::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (FunctorAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralData::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralFunction::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralList::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralTerm::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Identifier::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (IncludeDefinition::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (InfixConnective_t) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (InfixLogic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (IntegerLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (ListLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Logic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (LogicTuple::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Logics::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Nodes::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedLogic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedQuantifier_t) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedType::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (RationalLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (RealLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Role::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (SequentLogic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Specification::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (SubType::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Term::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Token::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (TupleType::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Type::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (TypedAtom::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (Types::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (UnaryConnective_t) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (UnaryLogic::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (ValueLiteral::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (VariableTerm::Ptr) v, YY_RVREF (location_type) l);
      basic_symbol (typename Base::kind_type t, YY_RVREF (std::string) v, YY_RVREF (location_type) l);


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
#if defined __cplusplus && __cplusplus < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
#endif
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

    // Symbol constructors declarations.
    static
    symbol_type
    make_END (YY_COPY (location_type) l);

    static
    symbol_type
    make_TPI (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_THF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_TFF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_TCF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_FOF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_CNF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_FOT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_ITE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_LET (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_AT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_AND (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOLLAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOLLARDOLLAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_COLON (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_COMMA (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_PLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_EQUAL (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_INFIXINEQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_LPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_RPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_LSQPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_RSQPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_LCURPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_RCURPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_VLINE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_STAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_GREATER (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_EXCLAMATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_TILDE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_QUESTIONMARK (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_ATMINUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_ATPLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_CARET (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLEEXCLAMATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLEQUESTIONMARK (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLEATPLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DOUBLEATMINUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_ATEQUAL (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_EXCLAMATIONGREATER (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_QUESTIONMARKSTAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_EQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_IMPLICATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_RIMPLICATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_INEQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_NOR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_NAND (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_ASSIGNMENT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_GENTZENARROW (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_SUBTYPESIGN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_INCLUDE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_INTEGER (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_REAL (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_RATIONAL (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_DQUOTED (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_LOWER_WORD (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_UPPER_WORD (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_IDENTIFIER (YY_COPY (std::string) v, YY_COPY (location_type) l);

    static
    symbol_type
    make_SINGLE_QUOTED (YY_COPY (std::string) v, YY_COPY (location_type) l);



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
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if defined __cplusplus && __cplusplus < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
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
  Parser::basic_symbol<Base>::basic_symbol (YY_RVREF (basic_symbol) other)
    : Base (YY_MOVE (other))
    , value ()
    , location (YY_MOVE (other.location))
  {
    switch (other.type_get ())
    {
      case 73: // Annotations
        value.YY_MOVE_OR_COPY< Annotation::Ptr > (YY_MOVE (other.value));
        break;

      case 139: // TffPlainAtomic
      case 143: // TffSystemAtomic
      case 191: // FofPlainTerm
      case 192: // FofDefinedTerm
      case 193: // FofDefinedAtomicTerm
      case 194: // FofDefinedPlainTerm
      case 195: // FofSystemTerm
      case 198: // FofFunctionTerm
        value.YY_MOVE_OR_COPY< Atom::Ptr > (YY_MOVE (other.value));
        break;

      case 112: // ThfUnitaryType
      case 113: // ThfApplyType
      case 161: // TffAtomicType
        value.YY_MOVE_OR_COPY< AtomType::Ptr > (YY_MOVE (other.value));
        break;

      case 211: // NonassocConnective
      case 212: // AssocConnective
        value.YY_MOVE_OR_COPY< BinaryConnective_t > (YY_MOVE (other.value));
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
        value.YY_MOVE_OR_COPY< BinaryLogic::Ptr > (YY_MOVE (other.value));
        break;

      case 114: // ThfBinaryType
      case 115: // ThfMappingType
      case 116: // ThfXprodType
      case 117: // ThfUnionType
      case 163: // TffMappingType
      case 164: // TffXprodType
        value.YY_MOVE_OR_COPY< BinaryType::Ptr > (YY_MOVE (other.value));
        break;

      case 98: // ThfConditional
      case 144: // TfxConditional
        value.YY_MOVE_OR_COPY< ConditionalTerm::Ptr > (YY_MOVE (other.value));
        break;

      case 108: // ThfConnTerm
        value.YY_MOVE_OR_COPY< ConnectiveAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 96: // ThfSystemAtomic
        value.YY_MOVE_OR_COPY< ConstantAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 228: // DefinedTerm
        value.YY_MOVE_OR_COPY< DefinedAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 65: // Definition
        value.YY_MOVE_OR_COPY< Definition::Ptr > (YY_MOVE (other.value));
        break;

      case 103: // ThfLetDefn
      case 149: // TfxLetDefn
        value.YY_MOVE_OR_COPY< DefinitionAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 99: // ThfLet
      case 145: // TfxLet
        value.YY_MOVE_OR_COPY< DefinitionTerm::Ptr > (YY_MOVE (other.value));
        break;

      case 64: // Definitions
        value.YY_MOVE_OR_COPY< Definitions::Ptr > (YY_MOVE (other.value));
        break;

      case 249: // DistinctObjectLiteral
        value.YY_MOVE_OR_COPY< DistinctObjectLiteral::Ptr > (YY_MOVE (other.value));
        break;

      case 236: // FormulaData
        value.YY_MOVE_OR_COPY< FormulaData::Ptr > (YY_MOVE (other.value));
        break;

      case 66: // AnnotatedFormula
      case 67: // ThfAnnotated
      case 68: // TffAnnotated
      case 69: // TcfAnnotated
      case 70: // FofAnnotated
      case 71: // CnfAnnotated
      case 72: // TpiAnnotated
        value.YY_MOVE_OR_COPY< FormulaDefinition::Ptr > (YY_MOVE (other.value));
        break;

      case 97: // ThfFofFunction
        value.YY_MOVE_OR_COPY< FunctorAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 233: // GeneralData
        value.YY_MOVE_OR_COPY< GeneralData::Ptr > (YY_MOVE (other.value));
        break;

      case 234: // GeneralFunction
        value.YY_MOVE_OR_COPY< GeneralFunction::Ptr > (YY_MOVE (other.value));
        break;

      case 237: // GeneralList
        value.YY_MOVE_OR_COPY< GeneralList::Ptr > (YY_MOVE (other.value));
        break;

      case 232: // GeneralTerm
        value.YY_MOVE_OR_COPY< GeneralTerm::Ptr > (YY_MOVE (other.value));
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
        value.YY_MOVE_OR_COPY< Identifier::Ptr > (YY_MOVE (other.value));
        break;

      case 238: // IncludeDefinition
        value.YY_MOVE_OR_COPY< IncludeDefinition::Ptr > (YY_MOVE (other.value));
        break;

      case 219: // DefinedInfixPred
      case 220: // InfixEquality
      case 221: // InfixInequality
        value.YY_MOVE_OR_COPY< InfixConnective_t > (YY_MOVE (other.value));
        break;

      case 91: // ThfInfixUnary
      case 95: // ThfDefinedInfix
      case 137: // TffInfixUnary
      case 142: // TffDefinedInfix
      case 180: // FofInfixUnary
      case 189: // FofDefinedInfixFormula
        value.YY_MOVE_OR_COPY< InfixLogic::Ptr > (YY_MOVE (other.value));
        break;

      case 245: // IntegerLiteral
        value.YY_MOVE_OR_COPY< IntegerLiteral::Ptr > (YY_MOVE (other.value));
        break;

      case 239: // FormulaSelection
        value.YY_MOVE_OR_COPY< ListLiteral::Ptr > (YY_MOVE (other.value));
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
        value.YY_MOVE_OR_COPY< Logic::Ptr > (YY_MOVE (other.value));
        break;

      case 106: // ThfTuple
      case 154: // TfxTuple
      case 200: // FofFormulaTuple
        value.YY_MOVE_OR_COPY< LogicTuple::Ptr > (YY_MOVE (other.value));
        break;

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.YY_MOVE_OR_COPY< Logics::Ptr > (YY_MOVE (other.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.YY_MOVE_OR_COPY< Nodes::Ptr > (YY_MOVE (other.value));
        break;

      case 86: // ThfQuantifiedFormula
      case 131: // TffQuantifiedFormula
      case 171: // TcfQuantifiedFormula
      case 183: // FofQuantifiedFormula
        value.YY_MOVE_OR_COPY< QuantifiedLogic::Ptr > (YY_MOVE (other.value));
        break;

      case 205: // ThfQuantifier
      case 206: // Th1Quantifier
      case 207: // Th0Quantifier
      case 210: // FofQuantifier
        value.YY_MOVE_OR_COPY< QuantifiedQuantifier_t > (YY_MOVE (other.value));
        break;

      case 158: // Tf1QuantifiedType
        value.YY_MOVE_OR_COPY< QuantifiedType::Ptr > (YY_MOVE (other.value));
        break;

      case 247: // RationalLiteral
        value.YY_MOVE_OR_COPY< RationalLiteral::Ptr > (YY_MOVE (other.value));
        break;

      case 246: // RealLiteral
        value.YY_MOVE_OR_COPY< RealLiteral::Ptr > (YY_MOVE (other.value));
        break;

      case 231: // FormulaRole
        value.YY_MOVE_OR_COPY< Role::Ptr > (YY_MOVE (other.value));
        break;

      case 119: // ThfSequent
      case 168: // TfxSequent
      case 199: // FofSequent
        value.YY_MOVE_OR_COPY< SequentLogic::Ptr > (YY_MOVE (other.value));
        break;

      case 63: // Specification
        value.YY_MOVE_OR_COPY< Specification::Ptr > (YY_MOVE (other.value));
        break;

      case 118: // ThfSubtype
      case 167: // TffSubtype
        value.YY_MOVE_OR_COPY< SubType::Ptr > (YY_MOVE (other.value));
        break;

      case 94: // ThfDefinedAtomic
      case 138: // TffAtomicFormula
      case 140: // TffDefinedAtomic
      case 141: // TffDefinedPlain
      case 186: // FofPlainAtomicFormula
      case 188: // FofDefinedPlainFormula
      case 190: // FofSystemAtomicFormula
      case 197: // FofTerm
        value.YY_MOVE_OR_COPY< Term::Ptr > (YY_MOVE (other.value));
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
        value.YY_MOVE_OR_COPY< Token::Ptr > (YY_MOVE (other.value));
        break;

      case 165: // TfxTupleType
        value.YY_MOVE_OR_COPY< TupleType::Ptr > (YY_MOVE (other.value));
        break;

      case 100: // ThfLetTypes
      case 111: // ThfTopLevelType
      case 146: // TfxLetTypes
      case 157: // TffTopLevelType
      case 159: // TffMonotype
      case 160: // TffUnitaryType
        value.YY_MOVE_OR_COPY< Type::Ptr > (YY_MOVE (other.value));
        break;

      case 110: // ThfAtomTyping
      case 156: // TffAtomTyping
        value.YY_MOVE_OR_COPY< TypedAtom::Ptr > (YY_MOVE (other.value));
        break;

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.YY_MOVE_OR_COPY< Types::Ptr > (YY_MOVE (other.value));
        break;

      case 208: // ThfUnaryConnective
      case 209: // Th1UnaryConnective
      case 213: // UnaryConnective
        value.YY_MOVE_OR_COPY< UnaryConnective_t > (YY_MOVE (other.value));
        break;

      case 90: // ThfPrefixUnary
      case 136: // TffPrefixUnary
        value.YY_MOVE_OR_COPY< UnaryLogic::Ptr > (YY_MOVE (other.value));
        break;

      case 243: // Number
        value.YY_MOVE_OR_COPY< ValueLiteral::Ptr > (YY_MOVE (other.value));
        break;

      case 88: // ThfTypedVariable
      case 130: // TfxUnitaryFormula
      case 133: // TffVariable
      case 134: // TffTypedVariable
      case 248: // Variable
        value.YY_MOVE_OR_COPY< VariableTerm::Ptr > (YY_MOVE (other.value));
        break;

      case 54: // "integer"
      case 55: // "real"
      case 56: // "rational"
      case 57: // "double_quoted"
      case 58: // "lower_word"
      case 59: // "upper_word"
      case 60: // "identifier"
      case 61: // "single_quoted"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (other.value));
        break;

      default:
        break;
    }

  }


  // Implementation of basic_symbol constructor for each type.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (location_type) l)
    : Base (t)
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Annotation::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Atom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (AtomType::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryConnective_t) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryLogic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (BinaryType::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (ConditionalTerm::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (ConnectiveAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (ConstantAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (DefinedAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Definition::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (DefinitionAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (DefinitionTerm::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Definitions::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (DistinctObjectLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (FormulaData::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (FormulaDefinition::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (FunctorAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralData::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralFunction::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralList::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (GeneralTerm::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Identifier::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (IncludeDefinition::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (InfixConnective_t) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (InfixLogic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (IntegerLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (ListLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Logic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (LogicTuple::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Logics::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Nodes::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedLogic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedQuantifier_t) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (QuantifiedType::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (RationalLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (RealLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Role::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (SequentLogic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Specification::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (SubType::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Term::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Token::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (TupleType::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Type::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (TypedAtom::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (Types::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (UnaryConnective_t) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (UnaryLogic::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (ValueLiteral::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (VariableTerm::Ptr) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (std::string) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
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

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.template destroy< Logics::Ptr > ();
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.template destroy< Nodes::Ptr > ();
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

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.template destroy< Types::Ptr > ();
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

      case 104: // ThfLetDefnList
      case 107: // ThfFormulaList
      case 109: // ThfArguments
      case 151: // TfxLetDefnList
      case 155: // TffArguments
      case 162: // TffTypeArguments
      case 196: // FofArguments
      case 201: // FofFormulaTupleList
        value.move< Logics::Ptr > (YY_MOVE (s.value));
        break;

      case 87: // ThfVariableList
      case 132: // TffVariableList
      case 184: // FofVariableList
      case 229: // NameList
      case 235: // GeneralTerms
        value.move< Nodes::Ptr > (YY_MOVE (s.value));
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

      case 101: // ThfAtomTypingList
      case 147: // TffAtomTypingList
      case 166: // TffTypeList
        value.move< Types::Ptr > (YY_MOVE (s.value));
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }

  // Implementation of make_symbol for each symbol type.
  inline
  Parser::symbol_type
  Parser::make_END (YY_COPY (location_type) l)
  {
    return symbol_type (token::END, YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_TPI (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::TPI, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_THF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::THF, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_TFF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::TFF, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_TCF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::TCF, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_FOF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::FOF, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_CNF (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::CNF, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_FOT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::FOT, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_ITE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::ITE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_LET (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::LET, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_AT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::AT, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_AND (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::AND, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOLLAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOLLAR, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOLLARDOLLAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOLLARDOLLAR, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_COLON (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::COLON, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_COMMA (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::COMMA, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOT, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_PLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::PLUS, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_EQUAL (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::EQUAL, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_INFIXINEQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::INFIXINEQUALITY, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_LPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::LPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_RPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::RPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_LSQPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::LSQPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_RSQPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::RSQPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_LCURPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::LCURPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_RCURPAREN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::RCURPAREN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_VLINE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::VLINE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_STAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::STAR, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_GREATER (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::GREATER, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_EXCLAMATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::EXCLAMATION, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_TILDE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::TILDE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_QUESTIONMARK (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::QUESTIONMARK, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_ATMINUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::ATMINUS, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_ATPLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::ATPLUS, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_CARET (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::CARET, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOUBLEEXCLAMATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLEEXCLAMATION, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOUBLEQUESTIONMARK (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLEQUESTIONMARK, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOUBLEATPLUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLEATPLUS, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DOUBLEATMINUS (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DOUBLEATMINUS, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_ATEQUAL (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::ATEQUAL, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_EXCLAMATIONGREATER (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::EXCLAMATIONGREATER, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_QUESTIONMARKSTAR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::QUESTIONMARKSTAR, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_EQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::EQUALITY, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_IMPLICATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::IMPLICATION, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_RIMPLICATION (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::RIMPLICATION, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_INEQUALITY (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::INEQUALITY, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_NOR (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::NOR, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_NAND (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::NAND, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_ASSIGNMENT (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::ASSIGNMENT, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_GENTZENARROW (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::GENTZENARROW, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_SUBTYPESIGN (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::SUBTYPESIGN, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_INCLUDE (YY_COPY (Token::Ptr) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::INCLUDE, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_INTEGER (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::INTEGER, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_REAL (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::REAL, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_RATIONAL (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::RATIONAL, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_DQUOTED (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::DQUOTED, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_LOWER_WORD (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::LOWER_WORD, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_UPPER_WORD (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::UPPER_WORD, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_IDENTIFIER (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::IDENTIFIER, YY_MOVE (v), YY_MOVE (l));
  }

  inline
  Parser::symbol_type
  Parser::make_SINGLE_QUOTED (YY_COPY (std::string) v, YY_COPY (location_type) l)
  {
    return symbol_type (token::SINGLE_QUOTED, YY_MOVE (v), YY_MOVE (l));
  }


#line 47 "../../obj/src/GrammarParser.yy" // lalr1.cc:403
} // libtptp
#line 3771 "GrammarParser.tab.h" // lalr1.cc:403




#endif // !YY_YY_GRAMMARPARSER_TAB_H_INCLUDED

/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "cminus.y"


#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
//#include "symtab.h"

static char* savedName;
static int savedLineNo;
static TreeNode* savedTree;
static int yylex(void);
int yyerror(char *s);
int scopenum = 0;


#line 90 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_EQUALS = 10,                    /* EQUALS  */
  YYSYMBOL_NOT_EQ = 11,                    /* NOT_EQ  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_GT_EQ = 13,                     /* GT_EQ  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LT_EQ = 15,                     /* LT_EQ  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_SEMICOL = 20,                   /* SEMICOL  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_LPAR = 22,                      /* LPAR  */
  YYSYMBOL_RPAR = 23,                      /* RPAR  */
  YYSYMBOL_LBRACK = 24,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 25,                    /* RBRACK  */
  YYSYMBOL_LCURLY = 26,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 27,                    /* RCURLY  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 29,                /* IDENTIFIER  */
  YYSYMBOL_ENDFILE = 30,                   /* ENDFILE  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_decl_list = 34,                 /* decl_list  */
  YYSYMBOL_decl = 35,                      /* decl  */
  YYSYMBOL_var_decl = 36,                  /* var_decl  */
  YYSYMBOL_37_1 = 37,                      /* @1  */
  YYSYMBOL_type_spec = 38,                 /* type_spec  */
  YYSYMBOL_fun_decl = 39,                  /* fun_decl  */
  YYSYMBOL_40_2 = 40,                      /* @2  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_param_list = 42,                /* param_list  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_cmpnd_stmnt = 44,               /* cmpnd_stmnt  */
  YYSYMBOL_loc_decls = 45,                 /* loc_decls  */
  YYSYMBOL_stmnt_list = 46,                /* stmnt_list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_exp_stmnt = 48,                 /* exp_stmnt  */
  YYSYMBOL_selec_stmnt = 49,               /* selec_stmnt  */
  YYSYMBOL_it_stmnt = 50,                  /* it_stmnt  */
  YYSYMBOL_return_stmnt = 51,              /* return_stmnt  */
  YYSYMBOL_expr = 52,                      /* expr  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_54_3 = 54,                      /* @3  */
  YYSYMBOL_simple_expr = 55,               /* simple_expr  */
  YYSYMBOL_relop = 56,                     /* relop  */
  YYSYMBOL_add_expr = 57,                  /* add_expr  */
  YYSYMBOL_addop = 58,                     /* addop  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_mulop = 60,                     /* mulop  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_call = 62,                      /* call  */
  YYSYMBOL_63_4 = 63,                      /* @4  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_arg_list = 65                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    54,    65,    68,    70,    73,    79,    78,
      92,    97,   104,   103,   116,   120,   126,   135,   140,   146,
     156,   163,   173,   175,   185,   187,   189,   191,   193,   195,
     198,   200,   203,   209,   217,   224,   226,   232,   239,   242,
     248,   247,   258,   265,   268,   270,   272,   274,   276,   278,
     281,   288,   291,   293,   296,   303,   306,   308,   311,   313,
     315,   317,   325,   324,   335,   338,   340,   349
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "VOID", "ASSIGN", "EQUALS", "NOT_EQ", "GT", "GT_EQ",
  "LT", "LT_EQ", "PLUS", "MINUS", "TIMES", "DIV", "SEMICOL", "COMMA",
  "LPAR", "RPAR", "LBRACK", "RBRACK", "LCURLY", "RCURLY", "NUMBER",
  "IDENTIFIER", "ENDFILE", "ERROR", "$accept", "program", "decl_list",
  "decl", "var_decl", "@1", "type_spec", "fun_decl", "@2", "params",
  "param_list", "param", "cmpnd_stmnt", "loc_decls", "stmnt_list",
  "statement", "exp_stmnt", "selec_stmnt", "it_stmnt", "return_stmnt",
  "expr", "var", "@3", "simple_expr", "relop", "add_expr", "addop", "term",
  "mulop", "factor", "call", "@4", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -81,   -81,     6,    18,   -81,   -81,   -18,   -81,   -81,
     -81,    13,   -81,     7,    -6,   -81,    56,    19,    16,    28,
      38,    48,   -81,    50,    49,    45,    18,   -81,    52,   -81,
     -81,   -81,   -81,    18,   -81,    43,     2,    13,    53,    54,
     -19,   -81,    14,   -81,   -81,    36,   -81,   -81,   -81,   -81,
     -81,   -81,    58,    65,   -81,    37,    47,   -81,   -81,    14,
      14,   -81,    59,    57,    60,    61,   -81,    14,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,    14,    14,   -81,   -81,
      14,    62,    63,   -81,   -81,    14,    14,   -81,   -81,    51,
      47,   -81,    12,    12,    64,   -81,    67,    66,    77,   -81,
     -81,   -81,    14,    12,   -81,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,     0,     2,     4,     5,     0,     6,     1,
       3,    12,     7,     0,     0,     8,     0,     0,    11,     0,
       0,    14,    17,     0,    18,     0,     0,     9,     0,    22,
      13,    16,    19,    24,    21,     0,     0,     0,     0,     0,
       0,    31,     0,    20,    61,    39,    26,    23,    25,    27,
      28,    29,     0,    59,    38,    43,    51,    55,    60,     0,
       0,    35,     0,     0,     0,     0,    30,     0,    44,    45,
      49,    47,    48,    46,    52,    53,     0,     0,    56,    57,
       0,     0,     0,    36,    58,     0,    65,    37,    59,    42,
      50,    54,     0,     0,     0,    67,     0,    64,    32,    34,
      41,    63,     0,     0,    66,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,    78,    55,   -81,   -12,   -81,   -81,   -81,
     -81,    68,    70,   -81,   -81,   -80,   -81,   -81,   -81,   -81,
     -40,   -21,   -81,   -81,   -81,    15,   -81,    20,   -81,    21,
     -81,   -81,   -81,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    17,     7,     8,    14,    20,
      21,    22,    46,    33,    36,    47,    48,    49,    50,    51,
      52,    53,    64,    54,    76,    55,    77,    56,    80,    57,
      58,    65,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    61,    63,    42,    19,    38,     9,    39,    40,    44,
      45,    11,    98,    99,    19,    38,    16,    39,    40,    81,
      82,    35,    41,   105,    42,     1,     2,    87,    29,    43,
      44,    45,    41,    12,    42,    15,    42,    13,    29,   -15,
      44,    45,    44,    45,    23,    94,    95,    68,    69,    70,
      71,    72,    73,    74,    75,    88,    88,    24,   -62,    88,
     -40,    25,   104,     1,    18,    78,    79,    74,    75,    26,
      27,    29,    37,    28,    67,    59,    60,    32,    66,    83,
      84,   103,    10,    86,    85,    92,    93,   102,    34,   100,
     101,    89,     0,     0,    31,    30,     0,    90,     0,     0,
       0,    91
};

static const yytype_int8 yycheck[] =
{
      40,    20,    42,    22,    16,     3,     0,     5,     6,    28,
      29,    29,    92,    93,    26,     3,    22,     5,     6,    59,
      60,    33,    20,   103,    22,     7,     8,    67,    26,    27,
      28,    29,    20,    20,    22,    28,    22,    24,    26,    23,
      28,    29,    28,    29,    25,    85,    86,    10,    11,    12,
      13,    14,    15,    16,    17,    76,    77,    29,    22,    80,
      24,    23,   102,     7,     8,    18,    19,    16,    17,    21,
      20,    26,    29,    24,     9,    22,    22,    25,    20,    20,
      23,     4,     4,    22,    24,    23,    23,    21,    33,    25,
      23,    76,    -1,    -1,    26,    25,    -1,    77,    -1,    -1,
      -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    33,    34,    35,    36,    38,    39,     0,
      35,    29,    20,    24,    40,    28,    22,    37,     8,    38,
      41,    42,    43,    25,    29,    23,    21,    20,    24,    26,
      44,    43,    25,    45,    36,    38,    46,    29,     3,     5,
       6,    20,    22,    27,    28,    29,    44,    47,    48,    49,
      50,    51,    52,    53,    55,    57,    59,    61,    62,    22,
      22,    20,    52,    52,    54,    63,    20,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    56,    58,    18,    19,
      60,    52,    52,    20,    23,    24,    22,    52,    53,    57,
      59,    61,    23,    23,    52,    52,    64,    65,    47,    47,
      25,    23,    21,     4,    52,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    37,    36,
      38,    38,    40,    39,    41,    41,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      54,    53,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    63,    62,    64,    64,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     7,
       1,     1,     0,     7,     1,     1,     3,     1,     2,     4,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       2,     1,     5,     7,     5,     2,     3,     3,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     0,     5,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list  */
#line 49 "cminus.y"
            { 
				savedTree = (yyvsp[0].tnode);
				YYACCEPT;
			}
#line 1216 "cminus.tab.c"
    break;

  case 3: /* decl_list: decl_list decl  */
#line 55 "cminus.y"
                {
                    TreeNode* t = (yyvsp[-1].tnode);
                    if (t != NULL) {
                        while (t->sibling != NULL) t = t->sibling;
                        t->sibling = (yyvsp[0].tnode);
                        (yyval.tnode) = (yyvsp[-1].tnode);
                    } else {
                        (yyval.tnode) = (yyvsp[0].tnode);
                    }
                }
#line 1231 "cminus.tab.c"
    break;

  case 4: /* decl_list: decl  */
#line 66 "cminus.y"
                { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1237 "cminus.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 69 "cminus.y"
        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1243 "cminus.tab.c"
    break;

  case 6: /* decl: fun_decl  */
#line 71 "cminus.y"
        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1249 "cminus.tab.c"
    break;

  case 7: /* var_decl: type_spec IDENTIFIER SEMICOL  */
#line 74 "cminus.y"
            {
                (yyval.tnode) = (yyvsp[-2].tnode);
                (yyval.tnode)->attr.name = copyString(lastId);                
            }
#line 1258 "cminus.tab.c"
    break;

  case 8: /* @1: %empty  */
#line 79 "cminus.y"
            {
                (yyval.tnode) = (yyvsp[-3].tnode);
				(yyval.tnode)->type = Array;
                (yyval.tnode)->attr.name = copyString(lastId);
                (yyval.tnode)->child[0] = newExpNode(Const);
                (yyval.tnode)->child[0]->attr.val = atoi(tokenString);
                
            }
#line 1271 "cminus.tab.c"
    break;

  case 9: /* var_decl: type_spec IDENTIFIER LBRACK NUMBER @1 RBRACK SEMICOL  */
#line 88 "cminus.y"
            {
                (yyval.tnode) = (yyvsp[-2].tnode);
            }
#line 1279 "cminus.tab.c"
    break;

  case 10: /* type_spec: INT  */
#line 93 "cminus.y"
            {
                (yyval.tnode) = newDeclNode(Var);
				(yyval.tnode)->type = Int;
            }
#line 1288 "cminus.tab.c"
    break;

  case 11: /* type_spec: VOID  */
#line 98 "cminus.y"
            {
                (yyval.tnode) = newDeclNode(Var);
				(yyval.tnode)->type = Void;
            }
#line 1297 "cminus.tab.c"
    break;

  case 12: /* @2: %empty  */
#line 104 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-1].tnode);
				(yyval.tnode)->kind.decl = Fun;
			    (yyval.tnode)->attr.name = copyString(lastId);
			}
#line 1307 "cminus.tab.c"
    break;

  case 13: /* fun_decl: type_spec IDENTIFIER @2 LPAR params RPAR cmpnd_stmnt  */
#line 110 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-4].tnode);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
      		}
#line 1317 "cminus.tab.c"
    break;

  case 14: /* params: param_list  */
#line 117 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[0].tnode);
			}
#line 1325 "cminus.tab.c"
    break;

  case 15: /* params: VOID  */
#line 121 "cminus.y"
                        { 
				(yyval.tnode) = newDeclNode(Param);
                (yyval.tnode)->type = Void;
			}
#line 1334 "cminus.tab.c"
    break;

  case 16: /* param_list: param_list COMMA param  */
#line 127 "cminus.y"
                        { 
                TreeNode* t = (yyvsp[-2].tnode);
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = (yyvsp[0].tnode);
                    (yyval.tnode) = (yyvsp[-2].tnode);
			    } else (yyval.tnode) = (yyvsp[0].tnode);
			}
#line 1347 "cminus.tab.c"
    break;

  case 17: /* param_list: param  */
#line 136 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[0].tnode); 
            }
#line 1355 "cminus.tab.c"
    break;

  case 18: /* param: type_spec IDENTIFIER  */
#line 141 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-1].tnode);
			    (yyval.tnode)->kind.decl = Param;
			    (yyval.tnode)->attr.name = copyString(lastId);
			}
#line 1365 "cminus.tab.c"
    break;

  case 19: /* param: type_spec IDENTIFIER LBRACK RBRACK  */
#line 147 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-3].tnode);
				(yyval.tnode)->kind.decl = Param;
				(yyval.tnode)->type = Array;
			    (yyval.tnode)->attr.name = copyString(lastId);
				(yyval.tnode)->child[0] = newExpNode(Const);
                (yyval.tnode)->child[0]->attr.val = 0;
			}
#line 1378 "cminus.tab.c"
    break;

  case 20: /* cmpnd_stmnt: LCURLY loc_decls stmnt_list RCURLY  */
#line 157 "cminus.y"
                        {
			    (yyval.tnode) = newStmntNode(Compound);
				(yyval.tnode)->child[0] = (yyvsp[-2].tnode);
				(yyval.tnode)->child[1] = (yyvsp[-1].tnode);
			}
#line 1388 "cminus.tab.c"
    break;

  case 21: /* loc_decls: loc_decls var_decl  */
#line 164 "cminus.y"
                        { 
                TreeNode* t = (yyvsp[-1].tnode);
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = (yyvsp[0].tnode);
                    (yyval.tnode) = (yyvsp[-1].tnode);
			    } else (yyval.tnode) = (yyvsp[0].tnode);
			}
#line 1401 "cminus.tab.c"
    break;

  case 22: /* loc_decls: %empty  */
#line 173 "cminus.y"
                          { (yyval.tnode) = NULL; }
#line 1407 "cminus.tab.c"
    break;

  case 23: /* stmnt_list: stmnt_list statement  */
#line 176 "cminus.y"
                        { 
                TreeNode* t = (yyvsp[-1].tnode);
                if (t != NULL){
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = (yyvsp[0].tnode);
                    (yyval.tnode) = (yyvsp[-1].tnode);
			    } else (yyval.tnode) = (yyvsp[0].tnode);
			}
#line 1420 "cminus.tab.c"
    break;

  case 24: /* stmnt_list: %empty  */
#line 185 "cminus.y"
                          { (yyval.tnode) = NULL; }
#line 1426 "cminus.tab.c"
    break;

  case 25: /* statement: exp_stmnt  */
#line 188 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1432 "cminus.tab.c"
    break;

  case 26: /* statement: cmpnd_stmnt  */
#line 190 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1438 "cminus.tab.c"
    break;

  case 27: /* statement: selec_stmnt  */
#line 192 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1444 "cminus.tab.c"
    break;

  case 28: /* statement: it_stmnt  */
#line 194 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1450 "cminus.tab.c"
    break;

  case 29: /* statement: return_stmnt  */
#line 196 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1456 "cminus.tab.c"
    break;

  case 30: /* exp_stmnt: expr SEMICOL  */
#line 199 "cminus.y"
                          { (yyval.tnode) = (yyvsp[-1].tnode); }
#line 1462 "cminus.tab.c"
    break;

  case 31: /* exp_stmnt: SEMICOL  */
#line 201 "cminus.y"
                          { (yyval.tnode) = NULL; }
#line 1468 "cminus.tab.c"
    break;

  case 32: /* selec_stmnt: IF LPAR expr RPAR statement  */
#line 204 "cminus.y"
                        { 
                (yyval.tnode) = newStmntNode(If);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1478 "cminus.tab.c"
    break;

  case 33: /* selec_stmnt: IF LPAR expr RPAR statement ELSE statement  */
#line 210 "cminus.y"
                        { 
                (yyval.tnode) = newStmntNode(If);
			    (yyval.tnode)->child[0] = (yyvsp[-4].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[2] = (yyvsp[0].tnode);
			}
#line 1489 "cminus.tab.c"
    break;

  case 34: /* it_stmnt: WHILE LPAR expr RPAR statement  */
#line 218 "cminus.y"
                        { 
                (yyval.tnode) = newStmntNode(While);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1499 "cminus.tab.c"
    break;

  case 35: /* return_stmnt: RETURN SEMICOL  */
#line 225 "cminus.y"
                          { (yyval.tnode) = newStmntNode(Return); }
#line 1505 "cminus.tab.c"
    break;

  case 36: /* return_stmnt: RETURN expr SEMICOL  */
#line 227 "cminus.y"
                        { 
                (yyval.tnode) = newStmntNode(Return);
			    (yyval.tnode)->child[0] = (yyvsp[-1].tnode);
			}
#line 1514 "cminus.tab.c"
    break;

  case 37: /* expr: var ASSIGN expr  */
#line 233 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Assign);
				(yyval.tnode)->attr.op = ASSIGN;
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1525 "cminus.tab.c"
    break;

  case 38: /* expr: simple_expr  */
#line 240 "cminus.y"
                          { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1531 "cminus.tab.c"
    break;

  case 39: /* var: IDENTIFIER  */
#line 243 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Id);
			    (yyval.tnode)->attr.name = (char *) copyString(lastId);
			}
#line 1540 "cminus.tab.c"
    break;

  case 40: /* @3: %empty  */
#line 248 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(ArrId);
			    (yyval.tnode)->attr.name = copyString(lastId);
			}
#line 1549 "cminus.tab.c"
    break;

  case 41: /* var: IDENTIFIER @3 LBRACK expr RBRACK  */
#line 253 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-3].tnode);
			    (yyval.tnode)->child[0] = (yyvsp[-1].tnode);
			}
#line 1558 "cminus.tab.c"
    break;

  case 42: /* simple_expr: add_expr relop add_expr  */
#line 259 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Op);
			    (yyval.tnode)->attr.op = (yyvsp[-1].tok);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1569 "cminus.tab.c"
    break;

  case 43: /* simple_expr: add_expr  */
#line 266 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1575 "cminus.tab.c"
    break;

  case 44: /* relop: EQUALS  */
#line 269 "cminus.y"
        { (yyval.tok) = EQUALS; }
#line 1581 "cminus.tab.c"
    break;

  case 45: /* relop: NOT_EQ  */
#line 271 "cminus.y"
        { (yyval.tok) = NOT_EQ; }
#line 1587 "cminus.tab.c"
    break;

  case 46: /* relop: LT_EQ  */
#line 273 "cminus.y"
        { (yyval.tok) = LT_EQ; }
#line 1593 "cminus.tab.c"
    break;

  case 47: /* relop: GT_EQ  */
#line 275 "cminus.y"
        { (yyval.tok) = GT_EQ; }
#line 1599 "cminus.tab.c"
    break;

  case 48: /* relop: LT  */
#line 277 "cminus.y"
        { (yyval.tok) = LT; }
#line 1605 "cminus.tab.c"
    break;

  case 49: /* relop: GT  */
#line 279 "cminus.y"
        { (yyval.tok) = GT; }
#line 1611 "cminus.tab.c"
    break;

  case 50: /* add_expr: add_expr addop term  */
#line 282 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Op);
			    (yyval.tnode)->attr.op = (yyvsp[-1].tok);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1622 "cminus.tab.c"
    break;

  case 51: /* add_expr: term  */
#line 289 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1628 "cminus.tab.c"
    break;

  case 52: /* addop: PLUS  */
#line 292 "cminus.y"
                { (yyval.tok) = PLUS; }
#line 1634 "cminus.tab.c"
    break;

  case 53: /* addop: MINUS  */
#line 294 "cminus.y"
                { (yyval.tok) = MINUS; }
#line 1640 "cminus.tab.c"
    break;

  case 54: /* term: term mulop factor  */
#line 297 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Op);
			    (yyval.tnode)->attr.op = (yyvsp[-1].tok);
			    (yyval.tnode)->child[0] = (yyvsp[-2].tnode);
			    (yyval.tnode)->child[1] = (yyvsp[0].tnode);
			}
#line 1651 "cminus.tab.c"
    break;

  case 55: /* term: factor  */
#line 304 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1657 "cminus.tab.c"
    break;

  case 56: /* mulop: TIMES  */
#line 307 "cminus.y"
                { (yyval.tok) = TIMES; }
#line 1663 "cminus.tab.c"
    break;

  case 57: /* mulop: DIV  */
#line 309 "cminus.y"
                { (yyval.tok) = DIV; }
#line 1669 "cminus.tab.c"
    break;

  case 58: /* factor: LPAR expr RPAR  */
#line 312 "cminus.y"
                        { (yyval.tnode) = (yyvsp[-1].tnode); }
#line 1675 "cminus.tab.c"
    break;

  case 59: /* factor: var  */
#line 314 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1681 "cminus.tab.c"
    break;

  case 60: /* factor: call  */
#line 316 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1687 "cminus.tab.c"
    break;

  case 61: /* factor: NUMBER  */
#line 318 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Const);
				(yyval.tnode)->type = Int;
			    (yyval.tnode)->attr.val = atoi(tokenString);
			}
#line 1697 "cminus.tab.c"
    break;

  case 62: /* @4: %empty  */
#line 325 "cminus.y"
                        { 
                (yyval.tnode) = newExpNode(Call);
			    (yyval.tnode)->attr.name = copyString(lastId);
			}
#line 1706 "cminus.tab.c"
    break;

  case 63: /* call: IDENTIFIER @4 LPAR args RPAR  */
#line 330 "cminus.y"
                        { 
                (yyval.tnode) = (yyvsp[-3].tnode);
			    (yyval.tnode)->child[0] = (yyvsp[-1].tnode);
			}
#line 1715 "cminus.tab.c"
    break;

  case 64: /* args: arg_list  */
#line 336 "cminus.y"
                { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1721 "cminus.tab.c"
    break;

  case 65: /* args: %empty  */
#line 338 "cminus.y"
                { (yyval.tnode) = NULL; }
#line 1727 "cminus.tab.c"
    break;

  case 66: /* arg_list: arg_list COMMA expr  */
#line 341 "cminus.y"
                        { 
                TreeNode * t = (yyvsp[-2].tnode);
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = (yyvsp[0].tnode);
                    (yyval.tnode) = (yyvsp[-2].tnode);
			    } else (yyval.tnode) = (yyvsp[0].tnode);
			}
#line 1740 "cminus.tab.c"
    break;

  case 67: /* arg_list: expr  */
#line 350 "cminus.y"
                        { (yyval.tnode) = (yyvsp[0].tnode); }
#line 1746 "cminus.tab.c"
    break;


#line 1750 "cminus.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 352 "cminus.y"


int yyerror(char * message) {
    fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	Error = TRUE;
	return 0;
}

static int yylex(void) {
	return getToken();
}

TreeNode* parse(void) {
	yyparse();
	return savedTree;
}

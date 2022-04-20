/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grsoft.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>
#include<SDL2/SDL.h>
/*
int yydebug=1;
*/
#define YYDEBUG 1
#define YYSTYPE float
int ll=0;
char identifier[256];
char a[512];
char chars[256];
char string[256];
struct var {
char name[80];
float value;
struct var * next;
};
struct str {
char name[80];
char value[1024];
struct str * next;
};
char A[80];
char cstr[1024];
struct var *r=NULL;
struct var *d;
struct str * root = NULL;
struct str *D;
int c=0;
float cv;
int cx,cy;
char lines[65536][512];
int im=1;
int l=0;
int notdef=1;
extern char * yytext;
extern void destroy();
char s[1024];
int trace=0;
int b1,b2,e1,e2;
SDL_Window* pWindow = NULL;
SDL_Renderer* renderer = NULL;
SDL_bool done;
int hgr=0;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
int infor=0;

#line 128 "grsoft.tab.c"

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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SAVE = 258,                    /* SAVE  */
    GET = 259,                     /* GET  */
    PEEK = 260,                    /* PEEK  */
    POKE = 261,                    /* POKE  */
    RUN = 262,                     /* RUN  */
    RND = 263,                     /* RND  */
    PRINT = 264,                   /* PRINT  */
    IDENTIFIER = 265,              /* IDENTIFIER  */
    PLUS = 266,                    /* PLUS  */
    MINUS = 267,                   /* MINUS  */
    ASTERISK = 268,                /* ASTERISK  */
    DIVIDE = 269,                  /* DIVIDE  */
    NUMBER = 270,                  /* NUMBER  */
    LIST = 271,                    /* LIST  */
    INPUT = 272,                   /* INPUT  */
    LET = 273,                     /* LET  */
    SQR = 274,                     /* SQR  */
    SIN = 275,                     /* SIN  */
    COS = 276,                     /* COS  */
    TAN = 277,                     /* TAN  */
    EXP = 278,                     /* EXP  */
    DIM = 279,                     /* DIM  */
    ABS = 280,                     /* ABS  */
    OR = 281,                      /* OR  */
    AND = 282,                     /* AND  */
    ASC = 283,                     /* ASC  */
    REM = 284,                     /* REM  */
    QUOTE = 285,                   /* QUOTE  */
    EQUAL = 286,                   /* EQUAL  */
    PO = 287,                      /* PO  */
    PF = 288,                      /* PF  */
    CO = 289,                      /* CO  */
    CF = 290,                      /* CF  */
    DP = 291,                      /* DP  */
    PG = 292,                      /* PG  */
    PP = 293,                      /* PP  */
    DIFF = 294,                    /* DIFF  */
    DOT = 295,                     /* DOT  */
    COMMA = 296,                   /* COMMA  */
    SEMICOLOMN = 297,              /* SEMICOLOMN  */
    CR = 298,                      /* CR  */
    RANDOMIZE = 299,               /* RANDOMIZE  */
    MOD = 300,                     /* MOD  */
    CHARS = 301,                   /* CHARS  */
    FLOAT = 302,                   /* FLOAT  */
    SYSTEM = 303,                  /* SYSTEM  */
    DUMP = 304,                    /* DUMP  */
    CLEAR = 305,                   /* CLEAR  */
    COLOR = 306,                   /* COLOR  */
    DRAW = 307,                    /* DRAW  */
    IF = 308,                      /* IF  */
    THEN = 309,                    /* THEN  */
    ELSE = 310,                    /* ELSE  */
    FOR = 311,                     /* FOR  */
    NEXT = 312,                    /* NEXT  */
    STEP = 313,                    /* STEP  */
    TO = 314,                      /* TO  */
    DEBUG = 315,                   /* DEBUG  */
    GOTO = 316,                    /* GOTO  */
    GOSUB = 317,                   /* GOSUB  */
    RETURN = 318,                  /* RETURN  */
    NEW = 319,                     /* NEW  */
    TRACE = 320,                   /* TRACE  */
    ON = 321,                      /* ON  */
    OFF = 322,                     /* OFF  */
    TEXT = 323,                    /* TEXT  */
    HTAB = 324,                    /* HTAB  */
    VTAB = 325,                    /* VTAB  */
    HOME = 326,                    /* HOME  */
    GR = 327,                      /* GR  */
    PLOT = 328,                    /* PLOT  */
    HGR = 329,                     /* HGR  */
    HPLOT = 330,                   /* HPLOT  */
    END = 331,                     /* END  */
    NOT = 332,                     /* NOT  */
    READ = 333,                    /* READ  */
    DATA = 334,                    /* DATA  */
    VLIN = 335,                    /* VLIN  */
    HLIN = 336,                    /* HLIN  */
    MID = 337,                     /* MID  */
    LEFT = 338,                    /* LEFT  */
    RIGHT = 339,                   /* RIGHT  */
    LEN = 340,                     /* LEN  */
    STRING = 341,                  /* STRING  */
    AMPER = 342,                   /* AMPER  */
    AT = 343,                      /* AT  */
    CHR = 344,                     /* CHR  */
    INT = 345                      /* INT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SAVE = 3,                       /* SAVE  */
  YYSYMBOL_GET = 4,                        /* GET  */
  YYSYMBOL_PEEK = 5,                       /* PEEK  */
  YYSYMBOL_POKE = 6,                       /* POKE  */
  YYSYMBOL_RUN = 7,                        /* RUN  */
  YYSYMBOL_RND = 8,                        /* RND  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_IDENTIFIER = 10,                /* IDENTIFIER  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 13,                  /* ASTERISK  */
  YYSYMBOL_DIVIDE = 14,                    /* DIVIDE  */
  YYSYMBOL_NUMBER = 15,                    /* NUMBER  */
  YYSYMBOL_LIST = 16,                      /* LIST  */
  YYSYMBOL_INPUT = 17,                     /* INPUT  */
  YYSYMBOL_LET = 18,                       /* LET  */
  YYSYMBOL_SQR = 19,                       /* SQR  */
  YYSYMBOL_SIN = 20,                       /* SIN  */
  YYSYMBOL_COS = 21,                       /* COS  */
  YYSYMBOL_TAN = 22,                       /* TAN  */
  YYSYMBOL_EXP = 23,                       /* EXP  */
  YYSYMBOL_DIM = 24,                       /* DIM  */
  YYSYMBOL_ABS = 25,                       /* ABS  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_ASC = 28,                       /* ASC  */
  YYSYMBOL_REM = 29,                       /* REM  */
  YYSYMBOL_QUOTE = 30,                     /* QUOTE  */
  YYSYMBOL_EQUAL = 31,                     /* EQUAL  */
  YYSYMBOL_PO = 32,                        /* PO  */
  YYSYMBOL_PF = 33,                        /* PF  */
  YYSYMBOL_CO = 34,                        /* CO  */
  YYSYMBOL_CF = 35,                        /* CF  */
  YYSYMBOL_DP = 36,                        /* DP  */
  YYSYMBOL_PG = 37,                        /* PG  */
  YYSYMBOL_PP = 38,                        /* PP  */
  YYSYMBOL_DIFF = 39,                      /* DIFF  */
  YYSYMBOL_DOT = 40,                       /* DOT  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_SEMICOLOMN = 42,                /* SEMICOLOMN  */
  YYSYMBOL_CR = 43,                        /* CR  */
  YYSYMBOL_RANDOMIZE = 44,                 /* RANDOMIZE  */
  YYSYMBOL_MOD = 45,                       /* MOD  */
  YYSYMBOL_CHARS = 46,                     /* CHARS  */
  YYSYMBOL_FLOAT = 47,                     /* FLOAT  */
  YYSYMBOL_SYSTEM = 48,                    /* SYSTEM  */
  YYSYMBOL_DUMP = 49,                      /* DUMP  */
  YYSYMBOL_CLEAR = 50,                     /* CLEAR  */
  YYSYMBOL_COLOR = 51,                     /* COLOR  */
  YYSYMBOL_DRAW = 52,                      /* DRAW  */
  YYSYMBOL_IF = 53,                        /* IF  */
  YYSYMBOL_THEN = 54,                      /* THEN  */
  YYSYMBOL_ELSE = 55,                      /* ELSE  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_NEXT = 57,                      /* NEXT  */
  YYSYMBOL_STEP = 58,                      /* STEP  */
  YYSYMBOL_TO = 59,                        /* TO  */
  YYSYMBOL_DEBUG = 60,                     /* DEBUG  */
  YYSYMBOL_GOTO = 61,                      /* GOTO  */
  YYSYMBOL_GOSUB = 62,                     /* GOSUB  */
  YYSYMBOL_RETURN = 63,                    /* RETURN  */
  YYSYMBOL_NEW = 64,                       /* NEW  */
  YYSYMBOL_TRACE = 65,                     /* TRACE  */
  YYSYMBOL_ON = 66,                        /* ON  */
  YYSYMBOL_OFF = 67,                       /* OFF  */
  YYSYMBOL_TEXT = 68,                      /* TEXT  */
  YYSYMBOL_HTAB = 69,                      /* HTAB  */
  YYSYMBOL_VTAB = 70,                      /* VTAB  */
  YYSYMBOL_HOME = 71,                      /* HOME  */
  YYSYMBOL_GR = 72,                        /* GR  */
  YYSYMBOL_PLOT = 73,                      /* PLOT  */
  YYSYMBOL_HGR = 74,                       /* HGR  */
  YYSYMBOL_HPLOT = 75,                     /* HPLOT  */
  YYSYMBOL_END = 76,                       /* END  */
  YYSYMBOL_NOT = 77,                       /* NOT  */
  YYSYMBOL_READ = 78,                      /* READ  */
  YYSYMBOL_DATA = 79,                      /* DATA  */
  YYSYMBOL_VLIN = 80,                      /* VLIN  */
  YYSYMBOL_HLIN = 81,                      /* HLIN  */
  YYSYMBOL_MID = 82,                       /* MID  */
  YYSYMBOL_LEFT = 83,                      /* LEFT  */
  YYSYMBOL_RIGHT = 84,                     /* RIGHT  */
  YYSYMBOL_LEN = 85,                       /* LEN  */
  YYSYMBOL_STRING = 86,                    /* STRING  */
  YYSYMBOL_AMPER = 87,                     /* AMPER  */
  YYSYMBOL_AT = 88,                        /* AT  */
  YYSYMBOL_CHR = 89,                       /* CHR  */
  YYSYMBOL_INT = 90,                       /* INT  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_pgm = 92,                       /* pgm  */
  YYSYMBOL_93_1 = 93,                      /* $@1  */
  YYSYMBOL_line = 94,                      /* line  */
  YYSYMBOL_95_2 = 95,                      /* $@2  */
  YYSYMBOL_96_3 = 96,                      /* $@3  */
  YYSYMBOL_inst = 97,                      /* inst  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_99_5 = 99,                      /* $@5  */
  YYSYMBOL_100_6 = 100,                    /* $@6  */
  YYSYMBOL_101_7 = 101,                    /* $@7  */
  YYSYMBOL_102_8 = 102,                    /* $@8  */
  YYSYMBOL_103_9 = 103,                    /* $@9  */
  YYSYMBOL_104_10 = 104,                   /* $@10  */
  YYSYMBOL_105_11 = 105,                   /* $@11  */
  YYSYMBOL_106_12 = 106,                   /* $@12  */
  YYSYMBOL_107_13 = 107,                   /* $@13  */
  YYSYMBOL_108_14 = 108,                   /* $@14  */
  YYSYMBOL_109_15 = 109,                   /* $@15  */
  YYSYMBOL_110_16 = 110,                   /* $@16  */
  YYSYMBOL_111_17 = 111,                   /* $@17  */
  YYSYMBOL_112_18 = 112,                   /* $@18  */
  YYSYMBOL_113_19 = 113,                   /* $@19  */
  YYSYMBOL_114_20 = 114,                   /* $@20  */
  YYSYMBOL_115_21 = 115,                   /* $@21  */
  YYSYMBOL_116_22 = 116,                   /* $@22  */
  YYSYMBOL_117_23 = 117,                   /* $@23  */
  YYSYMBOL_118_24 = 118,                   /* $@24  */
  YYSYMBOL_119_25 = 119,                   /* $@25  */
  YYSYMBOL_120_26 = 120,                   /* $@26  */
  YYSYMBOL_121_27 = 121,                   /* $@27  */
  YYSYMBOL_opt_then = 122,                 /* opt_then  */
  YYSYMBOL_list = 123,                     /* list  */
  YYSYMBOL_cond = 124,                     /* cond  */
  YYSYMBOL_125_28 = 125,                   /* $@28  */
  YYSYMBOL_126_29 = 126,                   /* $@29  */
  YYSYMBOL_127_30 = 127,                   /* $@30  */
  YYSYMBOL_128_31 = 128,                   /* $@31  */
  YYSYMBOL_oper = 129,                     /* oper  */
  YYSYMBOL_sexpr = 130,                    /* sexpr  */
  YYSYMBOL_multi_expr = 131,               /* multi_expr  */
  YYSYMBOL_132_32 = 132,                   /* $@32  */
  YYSYMBOL_133_33 = 133,                   /* $@33  */
  YYSYMBOL_134_34 = 134,                   /* $@34  */
  YYSYMBOL_135_35 = 135,                   /* @35  */
  YYSYMBOL_opt_print = 136,                /* opt_print  */
  YYSYMBOL_sep = 137,                      /* sep  */
  YYSYMBOL_string = 138,                   /* string  */
  YYSYMBOL_expr = 139,                     /* expr  */
  YYSYMBOL_140_36 = 140,                   /* $@36  */
  YYSYMBOL_141_37 = 141,                   /* $@37  */
  YYSYMBOL_142_38 = 142,                   /* $@38  */
  YYSYMBOL_143_39 = 143,                   /* $@39  */
  YYSYMBOL_144_40 = 144,                   /* @40  */
  YYSYMBOL_145_41 = 145,                   /* $@41  */
  YYSYMBOL_146_42 = 146,                   /* $@42  */
  YYSYMBOL_147_43 = 147,                   /* $@43  */
  YYSYMBOL_148_44 = 148,                   /* $@44  */
  YYSYMBOL_149_45 = 149,                   /* $@45  */
  YYSYMBOL_150_46 = 150,                   /* @46  */
  YYSYMBOL_151_47 = 151                    /* $@47  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   148,   148,   149,   152,   152,   153,   153,
     156,   156,   156,   159,   159,   159,   159,   169,   169,   169,
     169,   176,   176,   183,   183,   184,   187,   215,   216,   229,
     230,   231,   232,   233,   234,   234,   235,   235,   236,   236,
     237,   237,   238,   239,   239,   240,   240,   241,   242,   243,
     244,   265,   266,   267,   268,   268,   268,   268,   269,   270,
     271,   272,   273,   274,   274,   274,   274,   275,   275,   275,
     276,   277,   278,   286,   287,   288,   303,   304,   307,   308,
     311,   311,   311,   312,   313,   314,   315,   316,   317,   317,
     317,   320,   321,   322,   325,   326,   327,   328,   329,   332,
     332,   341,   341,   350,   350,   350,   353,   354,   355,   356,
     357,   360,   361,   364,   365,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   372,   373,   374,   375,   397,   397,
     398,   398,   399,   400,   400,   401,   402,   402,   403,   404,
     410,   404,   417,   417
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
  "\"end of file\"", "error", "\"invalid token\"", "SAVE", "GET", "PEEK",
  "POKE", "RUN", "RND", "PRINT", "IDENTIFIER", "PLUS", "MINUS", "ASTERISK",
  "DIVIDE", "NUMBER", "LIST", "INPUT", "LET", "SQR", "SIN", "COS", "TAN",
  "EXP", "DIM", "ABS", "OR", "AND", "ASC", "REM", "QUOTE", "EQUAL", "PO",
  "PF", "CO", "CF", "DP", "PG", "PP", "DIFF", "DOT", "COMMA", "SEMICOLOMN",
  "CR", "RANDOMIZE", "MOD", "CHARS", "FLOAT", "SYSTEM", "DUMP", "CLEAR",
  "COLOR", "DRAW", "IF", "THEN", "ELSE", "FOR", "NEXT", "STEP", "TO",
  "DEBUG", "GOTO", "GOSUB", "RETURN", "NEW", "TRACE", "ON", "OFF", "TEXT",
  "HTAB", "VTAB", "HOME", "GR", "PLOT", "HGR", "HPLOT", "END", "NOT",
  "READ", "DATA", "VLIN", "HLIN", "MID", "LEFT", "RIGHT", "LEN", "STRING",
  "AMPER", "AT", "CHR", "INT", "$accept", "pgm", "$@1", "line", "$@2",
  "$@3", "inst", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "opt_then",
  "list", "cond", "$@28", "$@29", "$@30", "$@31", "oper", "sexpr",
  "multi_expr", "$@32", "$@33", "$@34", "@35", "opt_print", "sep",
  "string", "expr", "$@36", "$@37", "$@38", "$@39", "@40", "$@41", "$@42",
  "$@43", "$@44", "$@45", "@46", "$@47", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345
};
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-104)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,    27,  -131,  -131,  -131,  -131,   225,   225,   -26,    29,
     -49,     9,   122,  -131,  -131,  -131,   -34,  -131,  -131,  -131,
    -131,  -131,   122,  -131,  -131,  -131,   -61,  -131,  -131,  -131,
    -131,   -41,  -131,  -131,  -131,  -131,  -131,     2,  -131,    53,
     122,   122,   122,  -131,    -1,    37,    76,    37,  -131,  -131,
    -131,   122,    59,  -131,  -131,  -131,    61,    62,    67,    89,
      97,   101,  -131,  -131,  -131,    90,    73,  -131,   125,   126,
      -4,    23,   128,  -131,  -131,   122,   122,  -131,  -131,   122,
     122,   122,    80,  -131,   110,   256,   135,   159,   121,  -131,
    -131,  -131,   176,  -131,   122,  -131,  -131,  -131,   122,   122,
      72,   122,   129,  -131,  -131,  -131,  -131,   122,  -131,   122,
      82,    64,  -131,  -131,   122,   143,    23,    23,     8,   122,
     -42,   136,   256,   256,   256,   256,   256,   122,   122,   122,
     122,    82,   225,   151,  -131,   122,   256,   122,   122,   122,
     233,   239,   127,   246,   122,   122,   122,   122,   122,   256,
       4,   256,  -131,   161,   162,   167,  -131,   180,  -131,   169,
     171,   166,   122,    63,    41,    23,    23,  -131,   225,   224,
     173,  -131,   157,   172,   256,     0,    10,   180,    37,  -131,
     256,   296,   302,   306,  -131,  -131,  -131,  -131,   310,   256,
     256,   256,   256,  -131,  -131,     4,    28,   -42,   -42,   -42,
     -42,  -131,  -131,   122,   314,  -131,    41,    41,    37,  -131,
    -131,  -131,  -131,  -131,   122,  -131,  -131,   122,   122,   122,
     175,  -131,  -131,  -131,  -131,    28,   180,   256,   164,   165,
     174,  -131,   122,   122,   256,  -131,   122,   -42,    19,   122,
     122,   256,   256,   256,  -131,   180,   256,   122,   122,   122,
     319,   256,   256,  -131,  -131,   256,   256,   208,   337,   342,
    -131,   122,   122,  -131,  -131,   256,   346,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     8,     1,     6,     5,     3,    13,    13,     0,     0,
       0,     0,     0,    26,    10,    25,    40,    17,    33,    27,
      28,    75,     0,    34,    54,    58,     0,    36,    38,    61,
      73,     0,    48,    43,    45,    47,    50,    63,    62,     0,
       0,     0,     0,    21,     0,     9,     0,     7,     4,    72,
      53,     0,     0,   127,   136,   125,     0,     0,     0,     0,
       0,     0,   123,   126,   142,     0,    99,    42,     0,     0,
       0,    80,     0,    31,    32,     0,     0,    29,    30,     0,
       0,     0,     0,    60,    59,    78,     0,     0,     0,    49,
      23,    14,     0,   139,     0,   133,   130,   128,     0,     0,
       0,     0,     0,   115,   117,   119,   121,     0,    11,     0,
       0,     0,    41,    18,     0,     0,    80,    80,    76,     0,
       0,     0,    37,    39,    44,    46,    64,     0,     0,     0,
       0,     0,    13,     0,    51,     0,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     106,   100,   114,     0,     0,     0,   113,   102,    94,     0,
       0,     0,     0,     0,    87,    80,    80,    77,    13,     0,
       0,    55,     0,     0,    79,     0,     0,    22,    24,    15,
     140,     0,     0,     0,   132,   135,   138,   124,     0,   116,
     118,   120,   122,   111,   112,    12,     0,     0,     0,     0,
       0,   104,    19,     0,     0,    84,    85,    86,    35,    91,
      92,    93,    81,    89,     0,    65,    68,     0,     0,     0,
       0,   134,   131,   129,   143,     0,   108,   107,     0,     0,
       0,    95,     0,     0,    74,    83,     0,     0,     0,     0,
       0,    71,    70,    16,   141,   110,   109,     0,     0,     0,
       0,    20,    82,    90,    56,    66,    69,     0,     0,     0,
     105,     0,     0,    97,    98,    57,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,  -131,  -131,    -5,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -101,  -131,  -131,  -131,  -131,  -131,  -130,
    -131,  -131,  -131,  -131,  -131,  -131,    21,  -117,   -22,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     8,     5,     7,     6,    45,    66,   150,    46,
     133,   219,    69,   160,   233,    88,   132,    71,    75,    76,
      68,    79,    80,    72,   214,   261,    81,   172,   239,    82,
     240,   168,    84,   118,   119,   236,   120,   237,   212,   157,
     108,   109,   110,   111,   232,   195,   196,   158,    65,   145,
     146,   147,   148,   101,   139,   138,   137,    94,   135,   220,
     102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   177,    47,   170,   152,    73,    74,   103,   104,   105,
     106,   103,   104,   105,   106,   163,   164,    48,    85,    86,
      87,   103,   104,   105,   106,    77,    78,     2,   115,    92,
     103,   104,   105,   106,   165,   166,    52,    50,    53,    49,
      54,    51,     3,    55,   156,   193,   194,    56,    57,    58,
      59,    60,    67,   122,   123,   116,    61,   124,   125,   126,
      62,   -67,   167,    83,   206,   207,   226,   165,   166,   -88,
       4,    89,   136,    90,   152,    63,   140,   141,   254,   143,
     228,   229,   230,   231,   114,   149,    91,   151,   217,   165,
     166,    93,   161,    95,    96,   245,   205,   169,   218,    97,
     117,   103,   104,   105,   106,   173,   174,   175,   176,   -88,
     153,   154,   155,   180,   156,   181,   182,   183,    64,  -101,
     253,    98,   188,   189,   190,   191,   192,   178,   152,    99,
      52,   107,    53,   100,    54,   112,   113,    55,   121,   127,
     204,    56,    57,    58,    59,    60,   103,   104,   105,   106,
      61,   128,   131,   159,    62,  -101,  -101,  -101,   142,  -101,
     186,   144,  -103,   208,   153,   154,   155,   171,   156,    63,
     103,   104,   105,   106,   227,   162,   129,   103,   104,   105,
     106,   234,   179,   103,   104,   105,   106,   103,   104,   105,
     106,   200,   238,   197,   198,   241,   242,   243,   215,   199,
     130,   201,   202,   246,   213,   247,   248,   203,   244,   134,
     250,   251,    64,   216,   252,   249,   225,   255,   256,   103,
     104,   105,   106,     0,     0,   257,   258,   259,     9,    10,
      11,    12,    13,     0,    14,   103,   104,   105,   106,   265,
     266,    15,    16,    17,   103,   104,   105,   106,     0,   262,
     103,   104,   105,   106,    18,   209,     0,   103,   104,   105,
     106,   210,   211,     0,     0,     0,   184,   103,   104,   105,
     106,     0,   185,    19,    20,    21,     0,    22,    23,   187,
       0,    24,    25,     0,     0,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,    34,    35,     0,     0,    36,
      37,    38,     0,    39,    40,    41,    42,   103,   104,   105,
     106,    43,    44,   103,   104,   105,   106,   103,   104,   105,
     106,   103,   104,   105,   106,   103,   104,   105,   106,   221,
     103,   104,   105,   106,     0,   222,     0,     0,     0,   223,
       0,     0,     0,   224,     0,     0,     0,   235,   103,   104,
     105,   106,   260,   103,   104,   105,   106,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,     0,     0,     0,   264,     0,     0,     0,   267
};

static const yytype_int16 yycheck[] =
{
      22,   131,     7,   120,    46,    66,    67,    11,    12,    13,
      14,    11,    12,    13,    14,   116,   117,    43,    40,    41,
      42,    11,    12,    13,    14,    66,    67,     0,     5,    51,
      11,    12,    13,    14,    26,    27,     8,    86,    10,    10,
      12,    32,    15,    15,    86,    41,    42,    19,    20,    21,
      22,    23,    86,    75,    76,    32,    28,    79,    80,    81,
      32,    59,    54,    10,   165,   166,   196,    26,    27,    46,
      43,    72,    94,    36,    46,    47,    98,    99,    59,   101,
     197,   198,   199,   200,    88,   107,    10,   109,    88,    26,
      27,    32,   114,    32,    32,   225,    33,   119,    88,    32,
      77,    11,    12,    13,    14,   127,   128,   129,   130,    86,
      82,    83,    84,   135,    86,   137,   138,   139,    90,    46,
     237,    32,   144,   145,   146,   147,   148,   132,    46,    32,
       8,    41,    10,    32,    12,    10,    10,    15,    10,    59,
     162,    19,    20,    21,    22,    23,    11,    12,    13,    14,
      28,    41,    31,    89,    32,    82,    83,    84,    86,    86,
      33,    32,    89,   168,    82,    83,    84,    31,    86,    47,
      11,    12,    13,    14,   196,    32,    41,    11,    12,    13,
      14,   203,    31,    11,    12,    13,    14,    11,    12,    13,
      14,    11,   214,    32,    32,   217,   218,   219,    41,    32,
      41,    32,    31,   225,    31,    41,    41,    41,    33,    33,
     232,   233,    90,    41,   236,    41,   195,   239,   240,    11,
      12,    13,    14,    -1,    -1,   247,   248,   249,     3,     4,
       5,     6,     7,    -1,     9,    11,    12,    13,    14,   261,
     262,    16,    17,    18,    11,    12,    13,    14,    -1,    41,
      11,    12,    13,    14,    29,    31,    -1,    11,    12,    13,
      14,    37,    38,    -1,    -1,    -1,    33,    11,    12,    13,
      14,    -1,    33,    48,    49,    50,    -1,    52,    53,    33,
      -1,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,
      75,    76,    -1,    78,    79,    80,    81,    11,    12,    13,
      14,    86,    87,    11,    12,    13,    14,    11,    12,    13,
      14,    11,    12,    13,    14,    11,    12,    13,    14,    33,
      11,    12,    13,    14,    -1,    33,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    33,    11,    12,
      13,    14,    33,    11,    12,    13,    14,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    92,     0,    15,    43,    94,    96,    95,    93,     3,
       4,     5,     6,     7,     9,    16,    17,    18,    29,    48,
      49,    50,    52,    53,    56,    57,    60,    61,    62,    63,
      64,    65,    68,    69,    70,    71,    74,    75,    76,    78,
      79,    80,    81,    86,    87,    97,   100,    97,    43,    10,
      86,    32,     8,    10,    12,    15,    19,    20,    21,    22,
      23,    28,    32,    47,    90,   139,    98,    86,   111,   103,
     139,   108,   114,    66,    67,   109,   110,    66,    67,   112,
     113,   117,   120,    10,   123,   139,   139,   139,   106,    72,
      36,    10,   139,    32,   148,    32,    32,    32,    32,    32,
      32,   144,   151,    11,    12,    13,    14,    41,   131,   132,
     133,   134,    10,    10,    88,     5,    32,    77,   124,   125,
     127,    10,   139,   139,   139,   139,   139,    59,    41,    41,
      41,    31,   107,   101,    33,   149,   139,   147,   146,   145,
     139,   139,    86,   139,    32,   140,   141,   142,   143,   139,
      99,   139,    46,    82,    83,    84,    86,   130,   138,    89,
     104,   139,    32,   124,   124,    26,    27,    54,   122,   139,
     138,    31,   118,   139,   139,   139,   139,   130,    97,    31,
     139,   139,   139,   139,    33,    33,    33,    33,   139,   139,
     139,   139,   139,    41,    42,   136,   137,    32,    32,    32,
      11,    32,    31,    41,   139,    33,   124,   124,    97,    31,
      37,    38,   129,    31,   115,    41,    41,    88,    88,   102,
     150,    33,    33,    33,    33,   137,   130,   139,   138,   138,
     138,   138,   135,   105,   139,    33,   126,   128,   139,   119,
     121,   139,   139,   139,    33,   130,   139,    41,    41,    41,
     139,   139,   139,   138,    59,   139,   139,   139,   139,   139,
      33,   116,    41,    33,    33,   139,   139,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    92,    92,    95,    94,    96,    94,
      98,    99,    97,   100,   101,   102,    97,   103,   104,   105,
      97,   106,    97,   107,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,   108,    97,   109,    97,   110,    97,
     111,    97,    97,   112,    97,   113,    97,    97,    97,    97,
      97,    97,    97,    97,   114,   115,   116,    97,    97,    97,
      97,    97,    97,   117,   118,   119,    97,   120,   121,    97,
      97,    97,    97,    97,    97,    97,   122,   122,   123,   123,
     125,   126,   124,   124,   124,   124,   124,   124,   127,   128,
     124,   129,   129,   129,   130,   130,   130,   130,   130,   132,
     131,   133,   131,   134,   135,   131,   136,   136,   136,   136,
     136,   137,   137,   138,   138,   140,   139,   141,   139,   142,
     139,   143,   139,   144,   139,   139,   139,   139,   145,   139,
     146,   139,   139,   147,   139,   139,   148,   139,   139,   149,
     150,   139,   151,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     4,     2,     0,     3,     0,     2,
       0,     0,     5,     0,     0,     0,     6,     0,     0,     0,
       7,     0,     4,     0,     4,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     0,     5,     0,     3,     0,     3,
       0,     3,     2,     0,     3,     0,     3,     1,     1,     2,
       1,     4,     4,     2,     0,     0,     0,     9,     1,     2,
       2,     1,     1,     0,     0,     0,     7,     0,     0,     7,
       6,     6,     2,     1,     6,     1,     0,     1,     1,     3,
       0,     0,     5,     4,     3,     3,     3,     2,     0,     0,
       5,     1,     1,     1,     1,     3,     8,     6,     6,     0,
       2,     0,     2,     0,     0,     6,     0,     2,     2,     3,
       3,     1,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     1,     1,     1,     0,     5,
       0,     5,     4,     0,     5,     4,     0,     3,     4,     0,
       0,     6,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* pgm: %empty  */
#line 147 "grsoft.y"
{ printf("]"); }
#line 1621 "grsoft.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 148 "grsoft.y"
            { printf("]"); strcpy(chars,"");strcpy(string,""); }
#line 1627 "grsoft.tab.c"
    break;

  case 5: /* pgm: pgm CR  */
#line 149 "grsoft.y"
          { printf("]"); strcpy(chars,""); }
#line 1633 "grsoft.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 152 "grsoft.y"
             { im=0; l=atoi(yytext); strcpy(lines[l],""); }
#line 1639 "grsoft.tab.c"
    break;

  case 7: /* line: NUMBER $@2 inst  */
#line 152 "grsoft.y"
                                                                 { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
#line 1645 "grsoft.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 153 "grsoft.y"
        { im=1; }
#line 1651 "grsoft.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 156 "grsoft.y"
            { if (!im) strcat(lines[l],"printf(\"%"); }
#line 1657 "grsoft.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 156 "grsoft.y"
                                                                   { if (!im) strcat(lines[l],")"); else {
}
 }
#line 1665 "grsoft.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 159 "grsoft.y"
   { notdef=1; }
#line 1671 "grsoft.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 159 "grsoft.y"
                            { d=r; while(d) { if (strcmp(d->name,identifier)==0) notdef=0; d=d->next; } if (notdef&&!im) strcat(lines[l],"float "); strcpy(a,identifier); }
#line 1677 "grsoft.tab.c"
    break;

  case 15: /* $@8: %empty  */
#line 159 "grsoft.y"
                                                                                                                                                                                  { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  }
#line 1683 "grsoft.tab.c"
    break;

  case 16: /* inst: $@6 IDENTIFIER $@7 EQUAL $@8 expr  */
#line 159 "grsoft.y"
                                                                                                                                                                                                                                                    { 
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=yyvsp[0]; strcpy(d->name,a); d->next=r; r=d;
	} else {	
		if (im) d->value=yyvsp[0];
	}
}
#line 1696 "grsoft.tab.c"
    break;

  case 17: /* $@9: %empty  */
#line 169 "grsoft.y"
       { notdef=1; }
#line 1702 "grsoft.tab.c"
    break;

  case 18: /* $@10: %empty  */
#line 169 "grsoft.y"
                                { if (!im&&notdef) strcat(lines[l],"float "); d=r; strcpy(a,identifier); while (d) { if (strcmp(d->name,identifier)==0) { notdef=0; break; } d=d->next; } }
#line 1708 "grsoft.tab.c"
    break;

  case 19: /* $@11: %empty  */
#line 169 "grsoft.y"
                                                                                                                                                                                                  { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  }
#line 1714 "grsoft.tab.c"
    break;

  case 20: /* inst: LET $@9 IDENTIFIER $@10 EQUAL $@11 expr  */
#line 169 "grsoft.y"
                                                                                                                                                                                                                                                                    { 
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=yyvsp[0]; strcpy(d->name,a); d->next=r; r=d;
	} else
		d->value=yyvsp[0];
}
#line 1726 "grsoft.tab.c"
    break;

  case 21: /* $@12: %empty  */
#line 176 "grsoft.y"
          { if (im) strcpy(A,yytext); }
#line 1732 "grsoft.tab.c"
    break;

  case 22: /* inst: STRING $@12 EQUAL sexpr  */
#line 176 "grsoft.y"
                                                     { if (im) {
	D=(struct str*)malloc(sizeof(struct str));
	strcpy(D->value,string);strcpy(D->name,A); D->next=root; root=D;	
} else {
	sprintf(lines[l],"char * %s = %s",identifier,chars);
}
}
#line 1744 "grsoft.tab.c"
    break;

  case 23: /* $@13: %empty  */
#line 183 "grsoft.y"
           { if (!im) sprintf(lines[l],"%s;",lines[l]); }
#line 1750 "grsoft.tab.c"
    break;

  case 25: /* inst: LIST  */
#line 184 "grsoft.y"
        {
	if (im) for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) printf("%d %s\n",i,lines[i]);
 }
#line 1758 "grsoft.tab.c"
    break;

  case 26: /* inst: RUN  */
#line 187 "grsoft.y"
       { if (im) {
	struct timeval * tv1;
	struct timeval * tv2;
	int diff;
	if (trace) {
		tv1=(struct timeval*)malloc(sizeof(struct timeval));
		tv2=(struct timeval*)malloc(sizeof(struct timeval));
	}
		FILE *fp=fopen("soft.c","w");
		if (!fp) fprintf(stderr,"erreur ouverture soft.c\n");
		basic2c(fp);
		fclose(fp);
		system("gcc soft.c -lm -lSDL2");
	if (trace)
		gettimeofday(tv1,NULL);
#ifdef WIN32
		system("a.exe");
#else
		system("./a.out");
#endif
	if (trace) {
		gettimeofday(tv2,NULL);
		diff=tv2->tv_sec - tv1->tv_sec;
		printf("µsec=%d\n",(int)(diff*1000000 + tv2->tv_usec - tv1->tv_usec));
	}
	
 }
}
#line 1791 "grsoft.tab.c"
    break;

  case 27: /* inst: SYSTEM  */
#line 215 "grsoft.y"
          { if (im) exit(0); else sprintf(lines[l],"%s exit(0)",lines[l]); }
#line 1797 "grsoft.tab.c"
    break;

  case 28: /* inst: DUMP  */
#line 216 "grsoft.y"
        { if (im) {
	struct var *d =r;
	struct str *D=root;
	while(d) {
		printf("%s %g\n",d->name,d->value);
		d=d->next;
	}
	while(D) {
		printf("%s %s\n",D->name,D->value);
		D=D->next;
	}
 }
}
#line 1815 "grsoft.tab.c"
    break;

  case 29: /* inst: TRACE ON  */
#line 229 "grsoft.y"
            { trace=1; }
#line 1821 "grsoft.tab.c"
    break;

  case 30: /* inst: TRACE OFF  */
#line 230 "grsoft.y"
             { trace=0; }
#line 1827 "grsoft.tab.c"
    break;

  case 31: /* inst: DEBUG ON  */
#line 231 "grsoft.y"
            { yydebug=1; }
#line 1833 "grsoft.tab.c"
    break;

  case 32: /* inst: DEBUG OFF  */
#line 232 "grsoft.y"
             { yydebug=0; }
#line 1839 "grsoft.tab.c"
    break;

  case 34: /* $@14: %empty  */
#line 234 "grsoft.y"
      { sprintf(lines[l],"%sif ",lines[l]);}
#line 1845 "grsoft.tab.c"
    break;

  case 36: /* $@15: %empty  */
#line 235 "grsoft.y"
        { sprintf(lines[l],"%s%s",lines[l],"goto L"); }
#line 1851 "grsoft.tab.c"
    break;

  case 38: /* $@16: %empty  */
#line 236 "grsoft.y"
         { if (!im) strcat(lines[l],"if (!setjmp(buf)) goto L"); }
#line 1857 "grsoft.tab.c"
    break;

  case 40: /* $@17: %empty  */
#line 237 "grsoft.y"
         { if (!im) strcat(lines[l],"fgets(s,1024,stdin);float "); }
#line 1863 "grsoft.tab.c"
    break;

  case 41: /* inst: INPUT $@17 IDENTIFIER  */
#line 237 "grsoft.y"
                                                                                { if (!im) sprintf(lines[l],"%s%s=atof(s)",lines[l],identifier); else fprintf(stderr,"NO DIRECT COMMAND\n"); }
#line 1869 "grsoft.tab.c"
    break;

  case 42: /* inst: INPUT STRING  */
#line 238 "grsoft.y"
                { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); }
#line 1875 "grsoft.tab.c"
    break;

  case 43: /* $@18: %empty  */
#line 239 "grsoft.y"
        { if (!im) sprintf(lines[l],"%sprintf(\"%%c[%d;",lines[l],cx); }
#line 1881 "grsoft.tab.c"
    break;

  case 44: /* inst: HTAB $@18 expr  */
#line 239 "grsoft.y"
                                                                              { if (!im) sprintf(lines[l],"%sH\",27)",lines[l]); }
#line 1887 "grsoft.tab.c"
    break;

  case 45: /* $@19: %empty  */
#line 240 "grsoft.y"
        { if (!im) strcat(lines[l],"printf(\"%c["); }
#line 1893 "grsoft.tab.c"
    break;

  case 46: /* inst: VTAB $@19 expr  */
#line 240 "grsoft.y"
                                                           { if (!im) sprintf(lines[l],"%s;%dH\",27)",lines[l],cy); }
#line 1899 "grsoft.tab.c"
    break;

  case 47: /* inst: HOME  */
#line 241 "grsoft.y"
        { if (im) printf("%c[2J",27); else strcat (lines[l],"printf(\"%c[2J\",27)");   }
#line 1905 "grsoft.tab.c"
    break;

  case 48: /* inst: TEXT  */
#line 242 "grsoft.y"
        { if (im) { SDL_Quit(); hgr=0; } }
#line 1911 "grsoft.tab.c"
    break;

  case 50: /* inst: HGR  */
#line 244 "grsoft.y"
       { if (im) {
hgr=1;
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS )) fprintf(stderr, "Echec SDL retour au mode texte (%s)", SDL_GetError());
	if (SDL_CreateWindowAndRenderer(281,192,0,&pWindow,&renderer)==0) {
            done = SDL_FALSE;
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
               SDL_RenderClear(renderer);

               SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	}
} else {
	hgr=1;
	strcat(lines[l],"if (SDL_Init(SDL_INIT_VIDEO)) fprintf(stderr, \"Echec SDL (%s)\", SDL_GetError());\n");
	strcat(lines[l],"if (SDL_CreateWindowAndRenderer(280,192,0,&pWindow,&renderer)==0) {\n");
	strcat(lines[l],"done = SDL_FALSE;\n");
        strcat(lines[l],"SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);\n");
        strcat(lines[l],"SDL_RenderClear(renderer);\n");
        strcat(lines[l],"SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);\n } else fprintf(stderr,\"Erreur SDL\")\n");
}
 }
#line 1937 "grsoft.tab.c"
    break;

  case 54: /* $@20: %empty  */
#line 268 "grsoft.y"
       { infor = 1; }
#line 1943 "grsoft.tab.c"
    break;

  case 55: /* $@21: %empty  */
#line 268 "grsoft.y"
                                       { strcat(lines[l],"for(I="); }
#line 1949 "grsoft.tab.c"
    break;

  case 56: /* $@22: %empty  */
#line 268 "grsoft.y"
                                                                              { strcat(lines[l],";I<="); }
#line 1955 "grsoft.tab.c"
    break;

  case 57: /* inst: FOR $@20 IDENTIFIER EQUAL $@21 expr TO $@22 expr  */
#line 268 "grsoft.y"
                                                                                                                { strcat(lines[l],";I++) {"); }
#line 1961 "grsoft.tab.c"
    break;

  case 58: /* inst: NEXT  */
#line 269 "grsoft.y"
        { if (!im) strcat(lines[l],"}"); }
#line 1967 "grsoft.tab.c"
    break;

  case 61: /* inst: RETURN  */
#line 272 "grsoft.y"
          { if (!im) strcat(lines[l],"longjmp(buf,1)"); }
#line 1973 "grsoft.tab.c"
    break;

  case 62: /* inst: END  */
#line 273 "grsoft.y"
       { if (!im) strcat(lines[l],"return"); else return 0;  }
#line 1979 "grsoft.tab.c"
    break;

  case 63: /* $@23: %empty  */
#line 274 "grsoft.y"
         { if (!im) strcat(lines[l],"hplot(renderer,(int)("); }
#line 1985 "grsoft.tab.c"
    break;

  case 64: /* $@24: %empty  */
#line 274 "grsoft.y"
                                                                     { if(im) b1=atoi(yytext); }
#line 1991 "grsoft.tab.c"
    break;

  case 65: /* $@25: %empty  */
#line 274 "grsoft.y"
                                                                                                       { if (!im) strcat(lines[l],"),(int)("); }
#line 1997 "grsoft.tab.c"
    break;

  case 66: /* inst: HPLOT $@23 expr $@24 COMMA $@25 expr  */
#line 274 "grsoft.y"
                                                                                                                                                      { b2=atoi(yytext); if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
#line 2003 "grsoft.tab.c"
    break;

  case 67: /* $@26: %empty  */
#line 275 "grsoft.y"
         { if (!im) strcat(lines[l],"SDL_RenderDrawLine(renderer,b1,b2,(int)("); }
#line 2009 "grsoft.tab.c"
    break;

  case 68: /* $@27: %empty  */
#line 275 "grsoft.y"
                                                                                                 { if (!im) strcat(lines[l],"),(int)("); }
#line 2015 "grsoft.tab.c"
    break;

  case 69: /* inst: HPLOT $@26 TO expr COMMA $@27 expr  */
#line 275 "grsoft.y"
                                                                                                                                                { if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
#line 2021 "grsoft.tab.c"
    break;

  case 72: /* inst: SAVE IDENTIFIER  */
#line 278 "grsoft.y"
                   {
	if (im) {
		FILE * fp;
		fp=fopen(identifier,"w");
		for(int i=0;i<65536;i++) if (strcmp(lines[i],"")) fprintf(fp,"L%d: %s\n",i,lines[i]);
		fclose(fp);
 }
 }
#line 2034 "grsoft.tab.c"
    break;

  case 73: /* inst: NEW  */
#line 286 "grsoft.y"
       { for(int i=0;i<65536;i++) strcpy(lines[i],""); }
#line 2040 "grsoft.tab.c"
    break;

  case 75: /* inst: CLEAR  */
#line 288 "grsoft.y"
         { if (im) { r=NULL; root=NULL; } }
#line 2046 "grsoft.tab.c"
    break;

  case 80: /* $@28: %empty  */
#line 311 "grsoft.y"
      { sprintf(lines[l],"%s ( ",lines[l]); }
#line 2052 "grsoft.tab.c"
    break;

  case 81: /* $@29: %empty  */
#line 311 "grsoft.y"
                                                        { sprintf(lines[l],"%s %s ",lines[l],oper); }
#line 2058 "grsoft.tab.c"
    break;

  case 82: /* cond: $@28 expr oper $@29 expr  */
#line 311 "grsoft.y"
                                                                                                           { sprintf(lines[l],"%s ) ",lines[l]); }
#line 2064 "grsoft.tab.c"
    break;

  case 88: /* $@30: %empty  */
#line 317 "grsoft.y"
          { if (!im) strcat(lines[l],"(strcmp("); }
#line 2070 "grsoft.tab.c"
    break;

  case 89: /* $@31: %empty  */
#line 317 "grsoft.y"
                                                                 { if (!im) strcat(lines[l],","); }
#line 2076 "grsoft.tab.c"
    break;

  case 90: /* cond: $@30 string EQUAL $@31 string  */
#line 317 "grsoft.y"
                                                                                                           { if (!im) strcat(lines[l],")==0) "); }
#line 2082 "grsoft.tab.c"
    break;

  case 91: /* oper: EQUAL  */
#line 320 "grsoft.y"
            { strcpy(oper,"=="); }
#line 2088 "grsoft.tab.c"
    break;

  case 92: /* oper: PG  */
#line 321 "grsoft.y"
             { strcpy(oper,">"); }
#line 2094 "grsoft.tab.c"
    break;

  case 93: /* oper: PP  */
#line 322 "grsoft.y"
             { strcpy(oper,"<"); }
#line 2100 "grsoft.tab.c"
    break;

  case 95: /* sexpr: sexpr PLUS string  */
#line 326 "grsoft.y"
                            { if (im) strcat(string,chars); }
#line 2106 "grsoft.tab.c"
    break;

  case 99: /* $@32: %empty  */
#line 332 "grsoft.y"
            { if (!im) strcat(lines[l],"g\","); }
#line 2112 "grsoft.tab.c"
    break;

  case 100: /* multi_expr: $@32 expr  */
#line 332 "grsoft.y"
                                                       { if (im) {
	d=r;
	while (d) {
		if (strcmp(d->name,identifier)==0)
			printf("%g\n",d->value);
		d=d->next;
	}
}
}
#line 2126 "grsoft.tab.c"
    break;

  case 101: /* $@33: %empty  */
#line 341 "grsoft.y"
          { if (!im) strcat(lines[l],"s\","); }
#line 2132 "grsoft.tab.c"
    break;

  case 102: /* multi_expr: $@33 sexpr  */
#line 341 "grsoft.y"
                                                      { if (im) {
	D=root;
	while (D) {
		if (strcmp(D->name,identifier)==0)
			printf("%s\n",D->value);
		D=D->next;
	}
}
}
#line 2146 "grsoft.tab.c"
    break;

  case 103: /* $@34: %empty  */
#line 350 "grsoft.y"
          { if (!im) strcat(lines[l],"c\\n\","); }
#line 2152 "grsoft.tab.c"
    break;

  case 104: /* @35: %empty  */
#line 350 "grsoft.y"
                                                          { if (!im) strcat(lines[l],"(int)"); }
#line 2158 "grsoft.tab.c"
    break;

  case 105: /* multi_expr: $@34 CHR PO @35 expr PF  */
#line 350 "grsoft.y"
                                                                                                         { if (im) printf("%c",(int)yyvsp[-2]); }
#line 2164 "grsoft.tab.c"
    break;

  case 106: /* opt_print: %empty  */
#line 353 "grsoft.y"
           { if (!im) strcat(lines[l],";printf(\"\\n\")"); }
#line 2170 "grsoft.tab.c"
    break;

  case 113: /* string: STRING  */
#line 364 "grsoft.y"
               { if (im) strcpy(identifier,yytext); else sprintf(lines[l],"%s%s",lines[l],identifier); }
#line 2176 "grsoft.tab.c"
    break;

  case 114: /* string: CHARS  */
#line 365 "grsoft.y"
                { if (!im) strcat(lines[l],chars); else strcpy(string,chars+1);string[strlen(string)-1]=0; }
#line 2182 "grsoft.tab.c"
    break;

  case 115: /* $@36: %empty  */
#line 368 "grsoft.y"
                { if (!im) strcat(lines[l],"+"); }
#line 2188 "grsoft.tab.c"
    break;

  case 116: /* expr: expr PLUS $@36 expr  */
#line 368 "grsoft.y"
                                                        { if (im) yyval=yyvsp[-3]+yyvsp[0]; }
#line 2194 "grsoft.tab.c"
    break;

  case 117: /* $@37: %empty  */
#line 369 "grsoft.y"
              { if (!im) strcat(lines[l],"-"); }
#line 2200 "grsoft.tab.c"
    break;

  case 118: /* expr: expr MINUS $@37 expr  */
#line 369 "grsoft.y"
                                                      { if (im) yyval=yyvsp[-3]-yyvsp[0]; }
#line 2206 "grsoft.tab.c"
    break;

  case 119: /* $@38: %empty  */
#line 370 "grsoft.y"
                 { if (!im) strcat(lines[l],"*"); }
#line 2212 "grsoft.tab.c"
    break;

  case 120: /* expr: expr ASTERISK $@38 expr  */
#line 370 "grsoft.y"
                                                         { if (im) yyval=yyvsp[-3]*yyvsp[0]; }
#line 2218 "grsoft.tab.c"
    break;

  case 121: /* $@39: %empty  */
#line 371 "grsoft.y"
                { if (!im) strcat(lines[l],"/"); }
#line 2224 "grsoft.tab.c"
    break;

  case 122: /* expr: expr DIVIDE $@39 expr  */
#line 371 "grsoft.y"
                                                        { if (im) yyval=yyvsp[-3]/yyvsp[0]; }
#line 2230 "grsoft.tab.c"
    break;

  case 123: /* @40: %empty  */
#line 372 "grsoft.y"
      { if (!im) strcat(lines[l],"("); }
#line 2236 "grsoft.tab.c"
    break;

  case 124: /* expr: PO @40 expr PF  */
#line 372 "grsoft.y"
                                                 { if (im) yyval=yyvsp[-2]; else strcat(lines[l],")"); }
#line 2242 "grsoft.tab.c"
    break;

  case 125: /* expr: NUMBER  */
#line 373 "grsoft.y"
          { if (im) yyval=yyvsp[0]; else strcat(lines[l],yytext); }
#line 2248 "grsoft.tab.c"
    break;

  case 126: /* expr: FLOAT  */
#line 374 "grsoft.y"
         { if (im) yyval=yyvsp[0]; else strcat(lines[l],yytext); }
#line 2254 "grsoft.tab.c"
    break;

  case 127: /* expr: IDENTIFIER  */
#line 375 "grsoft.y"
              { if (!im) {
	strcat(lines[l],identifier);
	struct var * c=r;
	while(c) {
		if (strcmp(c->name,identifier)==0) {
                        notdef=0;
		}
		c=c->next;
	}
        } else {
	int fin=0;
	struct var* c=r;
	while(c) {
		if (strcmp(c->name,identifier)==0) {
			fin=1; notdef=0;
			yyval=c->value;
		}
		c=c->next;
	}
	if (!fin) yyval=0;
}
 }
#line 2281 "grsoft.tab.c"
    break;

  case 128: /* $@41: %empty  */
#line 397 "grsoft.y"
          { if (!im) strcat(lines[l],"cos(");  }
#line 2287 "grsoft.tab.c"
    break;

  case 129: /* expr: COS PO $@41 expr PF  */
#line 397 "grsoft.y"
                                                         { if (im) yyval=cos(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2293 "grsoft.tab.c"
    break;

  case 130: /* $@42: %empty  */
#line 398 "grsoft.y"
          { if (!im) strcat(lines[l],"sin(");  }
#line 2299 "grsoft.tab.c"
    break;

  case 131: /* expr: SIN PO $@42 expr PF  */
#line 398 "grsoft.y"
                                                         { if (im) yyval=sin(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2305 "grsoft.tab.c"
    break;

  case 132: /* expr: TAN PO expr PF  */
#line 399 "grsoft.y"
                  { if (im) yyval=tan(yyvsp[-1]); }
#line 2311 "grsoft.tab.c"
    break;

  case 133: /* $@43: %empty  */
#line 400 "grsoft.y"
          { if (!im) strcat(lines[l],"sqrt("); }
#line 2317 "grsoft.tab.c"
    break;

  case 134: /* expr: SQR PO $@43 expr PF  */
#line 400 "grsoft.y"
                                                         { if (im) yyval=sqrt(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2323 "grsoft.tab.c"
    break;

  case 135: /* expr: EXP PO expr PF  */
#line 401 "grsoft.y"
                  { if (im) yyval=exp(yyvsp[-1]); }
#line 2329 "grsoft.tab.c"
    break;

  case 136: /* $@44: %empty  */
#line 402 "grsoft.y"
         { if (!im) strcat(lines[l],"-"); }
#line 2335 "grsoft.tab.c"
    break;

  case 137: /* expr: MINUS $@44 expr  */
#line 402 "grsoft.y"
                                                 { if (im) yyval=-yyvsp[0]; }
#line 2341 "grsoft.tab.c"
    break;

  case 139: /* $@45: %empty  */
#line 404 "grsoft.y"
          { if (!im) 
#ifdef WIN32
strcat(lines[l],"rand()*");
#else
strcat(lines[l],"drand48()*");
#endif
}
#line 2353 "grsoft.tab.c"
    break;

  case 140: /* @46: %empty  */
#line 410 "grsoft.y"
       { if (im) 
#ifdef WIN32
yyval=rand()*yyvsp[0];
#else
yyval=drand48()*yyvsp[0];
#endif
}
#line 2365 "grsoft.tab.c"
    break;

  case 142: /* $@47: %empty  */
#line 417 "grsoft.y"
       { if (!im) strcat(lines[l],"roundf("); }
#line 2371 "grsoft.tab.c"
    break;

  case 143: /* expr: INT $@47 PO expr PF  */
#line 417 "grsoft.y"
                                                           { if (im) yyval=(int)yyvsp[-1]; else strcat(lines[l],")");  }
#line 2377 "grsoft.tab.c"
    break;


#line 2381 "grsoft.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 420 "grsoft.y"

#include"lex.yy.c"
void  yyerror(char *s) {
if (im) 
	fprintf(stderr,"%s on %d\n",s,yychar);
else
	fprintf(stderr,"%s on %d line %d\n",s,yychar,l);
	yyparse();
}

int main(int argc,char * argv[]) {
char rcsrev[]="$Revision: 1.23 $";

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->value=7;
r->next=(struct var*)malloc(sizeof(struct var));
r->next->value=atof(strtok(NULL,"."));
r->next->next=NULL;
strcpy(r->next->name,"VERSION");
#ifdef WIN32
srand(12345);
#else
srand48(12345);
#endif
yyparse();
fprintf(stderr,"FIN\n");
}

int WinMain() {
char rcsrev[]="$Revision: 1.23 $";

strtok(rcsrev,".");
r=(struct var*)malloc(sizeof(struct var));
strcpy(r->name,"HCOLOR");
r->value=7;
r->next=(struct var*)malloc(sizeof(struct var));
r->next->value=atof(strtok(NULL,"."));
r->next->next=NULL;
strcpy(r->next->name,"VERSION");

srand(12345);

return yyparse();
}

int yywrap() {
}

int process(char *s) {
}

int basic2c(FILE *fp) {
	fprintf(fp,"#include<stdio.h>\n");
	fprintf(fp,"#include<setjmp.h>\n");
	fprintf(fp,"#include<stdlib.h>\n");
	fprintf(fp,"#include<string.h>\n");
	fprintf(fp,"#include<math.h>\n");
	fprintf(fp,"#include<SDL2/SDL.h>\n");

	fprintf(fp,"SDL_Window* pWindow = NULL;\n");
	fprintf(fp,"SDL_Renderer* renderer = NULL;\n");
	if (hgr)
		fprintf(fp,"SDL_bool done;\n");
	else
		fprintf(fp,"SDL_bool done=SDL_TRUE;\n");
	
	fprintf(fp,"SDL_Event event;\n");

	fprintf(fp,"int b1,b2;\n");
	fprintf(fp,"static jmp_buf buf;\n");
	fprintf(fp,"void hplot(SDL_Renderer*s,int x, int y) {\n");
	fprintf(fp,"SDL_RenderDrawPoint(s,x,y);b1=x;b2=y;\n");
	fprintf(fp,"}\n");

	fprintf(fp,"void main(int argc, char * argv[]) {\n");
	fprintf(fp,"char s[1024];\n");
	fprintf(fp,"float I;\n");
	fprintf(fp,"float HCOLOR;\n");
	fprintf(fp,"float VERSION=20;\n");
	fprintf(fp,"srand48(1234);\n");
	for(int i=0;i<65536;i++) {
		if (strcmp(lines[i],"")) {
			if (trace) 
				fprintf(fp,"fprintf(stderr,\"#%%d\",%d);",i);
			fprintf(fp,"L%d: %s\n",i,lines[i]);
		}
	}
	fprintf(fp,"while(!done) {\n");
        fprintf(fp,"while (SDL_PollEvent(&event)) {\n");
        fprintf(fp,"if (event.type == SDL_QUIT) {\n");
        fprintf(fp,"done=SDL_TRUE;\n"); 
        fprintf(fp,"}\n");
        fprintf(fp,"}\n");
	fprintf(fp,"}\n");
	fprintf(fp,"SDL_Quit();\n");
	fprintf(fp,"}\n");
}

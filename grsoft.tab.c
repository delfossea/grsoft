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
SDL_Rect pos;
SDL_Surface * temp;
SDL_Texture * sprite;
int hgr=0;
void yyerror(char *s);
int basic2c(FILE *fp);
int yylex();
char oper[4];
int infor=0;

#line 131 "grsoft.tab.c"

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
    PR = 258,                      /* PR  */
    STR = 259,                     /* STR  */
    SAVE = 260,                    /* SAVE  */
    GET = 261,                     /* GET  */
    PEEK = 262,                    /* PEEK  */
    POKE = 263,                    /* POKE  */
    RUN = 264,                     /* RUN  */
    RND = 265,                     /* RND  */
    PRINT = 266,                   /* PRINT  */
    IDENTIFIER = 267,              /* IDENTIFIER  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    ASTERISK = 270,                /* ASTERISK  */
    DIVIDE = 271,                  /* DIVIDE  */
    NUMBER = 272,                  /* NUMBER  */
    LIST = 273,                    /* LIST  */
    INPUT = 274,                   /* INPUT  */
    LET = 275,                     /* LET  */
    SQR = 276,                     /* SQR  */
    SIN = 277,                     /* SIN  */
    COS = 278,                     /* COS  */
    TAN = 279,                     /* TAN  */
    EXP = 280,                     /* EXP  */
    DIM = 281,                     /* DIM  */
    ABS = 282,                     /* ABS  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    ASC = 285,                     /* ASC  */
    REM = 286,                     /* REM  */
    QUOTE = 287,                   /* QUOTE  */
    EQUAL = 288,                   /* EQUAL  */
    PO = 289,                      /* PO  */
    PF = 290,                      /* PF  */
    CO = 291,                      /* CO  */
    CF = 292,                      /* CF  */
    DP = 293,                      /* DP  */
    PG = 294,                      /* PG  */
    PP = 295,                      /* PP  */
    PE = 296,                      /* PE  */
    GE = 297,                      /* GE  */
    DIFF = 298,                    /* DIFF  */
    DOT = 299,                     /* DOT  */
    COMMA = 300,                   /* COMMA  */
    SEMICOLOMN = 301,              /* SEMICOLOMN  */
    CR = 302,                      /* CR  */
    RANDOMIZE = 303,               /* RANDOMIZE  */
    MOD = 304,                     /* MOD  */
    CHARS = 305,                   /* CHARS  */
    FLOAT = 306,                   /* FLOAT  */
    SYSTEM = 307,                  /* SYSTEM  */
    DUMP = 308,                    /* DUMP  */
    CLEAR = 309,                   /* CLEAR  */
    COLOR = 310,                   /* COLOR  */
    DRAW = 311,                    /* DRAW  */
    IF = 312,                      /* IF  */
    THEN = 313,                    /* THEN  */
    ELSE = 314,                    /* ELSE  */
    FOR = 315,                     /* FOR  */
    NEXT = 316,                    /* NEXT  */
    STEP = 317,                    /* STEP  */
    TO = 318,                      /* TO  */
    DEBUG = 319,                   /* DEBUG  */
    GOTO = 320,                    /* GOTO  */
    GOSUB = 321,                   /* GOSUB  */
    RETURN = 322,                  /* RETURN  */
    NEW = 323,                     /* NEW  */
    TRACE = 324,                   /* TRACE  */
    NOTRACE = 325,                 /* NOTRACE  */
    ON = 326,                      /* ON  */
    OFF = 327,                     /* OFF  */
    TEXT = 328,                    /* TEXT  */
    HTAB = 329,                    /* HTAB  */
    VTAB = 330,                    /* VTAB  */
    HOME = 331,                    /* HOME  */
    GR = 332,                      /* GR  */
    PLOT = 333,                    /* PLOT  */
    HGR = 334,                     /* HGR  */
    HPLOT = 335,                   /* HPLOT  */
    END = 336,                     /* END  */
    NOT = 337,                     /* NOT  */
    READ = 338,                    /* READ  */
    DATA = 339,                    /* DATA  */
    VLIN = 340,                    /* VLIN  */
    HLIN = 341,                    /* HLIN  */
    MID = 342,                     /* MID  */
    LEFT = 343,                    /* LEFT  */
    RIGHT = 344,                   /* RIGHT  */
    LEN = 345,                     /* LEN  */
    STRING = 346,                  /* STRING  */
    AMPER = 347,                   /* AMPER  */
    AT = 348,                      /* AT  */
    CHR = 349,                     /* CHR  */
    INT = 350                      /* INT  */
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
  YYSYMBOL_PR = 3,                         /* PR  */
  YYSYMBOL_STR = 4,                        /* STR  */
  YYSYMBOL_SAVE = 5,                       /* SAVE  */
  YYSYMBOL_GET = 6,                        /* GET  */
  YYSYMBOL_PEEK = 7,                       /* PEEK  */
  YYSYMBOL_POKE = 8,                       /* POKE  */
  YYSYMBOL_RUN = 9,                        /* RUN  */
  YYSYMBOL_RND = 10,                       /* RND  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_IDENTIFIER = 12,                /* IDENTIFIER  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_ASTERISK = 15,                  /* ASTERISK  */
  YYSYMBOL_DIVIDE = 16,                    /* DIVIDE  */
  YYSYMBOL_NUMBER = 17,                    /* NUMBER  */
  YYSYMBOL_LIST = 18,                      /* LIST  */
  YYSYMBOL_INPUT = 19,                     /* INPUT  */
  YYSYMBOL_LET = 20,                       /* LET  */
  YYSYMBOL_SQR = 21,                       /* SQR  */
  YYSYMBOL_SIN = 22,                       /* SIN  */
  YYSYMBOL_COS = 23,                       /* COS  */
  YYSYMBOL_TAN = 24,                       /* TAN  */
  YYSYMBOL_EXP = 25,                       /* EXP  */
  YYSYMBOL_DIM = 26,                       /* DIM  */
  YYSYMBOL_ABS = 27,                       /* ABS  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_ASC = 30,                       /* ASC  */
  YYSYMBOL_REM = 31,                       /* REM  */
  YYSYMBOL_QUOTE = 32,                     /* QUOTE  */
  YYSYMBOL_EQUAL = 33,                     /* EQUAL  */
  YYSYMBOL_PO = 34,                        /* PO  */
  YYSYMBOL_PF = 35,                        /* PF  */
  YYSYMBOL_CO = 36,                        /* CO  */
  YYSYMBOL_CF = 37,                        /* CF  */
  YYSYMBOL_DP = 38,                        /* DP  */
  YYSYMBOL_PG = 39,                        /* PG  */
  YYSYMBOL_PP = 40,                        /* PP  */
  YYSYMBOL_PE = 41,                        /* PE  */
  YYSYMBOL_GE = 42,                        /* GE  */
  YYSYMBOL_DIFF = 43,                      /* DIFF  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_SEMICOLOMN = 46,                /* SEMICOLOMN  */
  YYSYMBOL_CR = 47,                        /* CR  */
  YYSYMBOL_RANDOMIZE = 48,                 /* RANDOMIZE  */
  YYSYMBOL_MOD = 49,                       /* MOD  */
  YYSYMBOL_CHARS = 50,                     /* CHARS  */
  YYSYMBOL_FLOAT = 51,                     /* FLOAT  */
  YYSYMBOL_SYSTEM = 52,                    /* SYSTEM  */
  YYSYMBOL_DUMP = 53,                      /* DUMP  */
  YYSYMBOL_CLEAR = 54,                     /* CLEAR  */
  YYSYMBOL_COLOR = 55,                     /* COLOR  */
  YYSYMBOL_DRAW = 56,                      /* DRAW  */
  YYSYMBOL_IF = 57,                        /* IF  */
  YYSYMBOL_THEN = 58,                      /* THEN  */
  YYSYMBOL_ELSE = 59,                      /* ELSE  */
  YYSYMBOL_FOR = 60,                       /* FOR  */
  YYSYMBOL_NEXT = 61,                      /* NEXT  */
  YYSYMBOL_STEP = 62,                      /* STEP  */
  YYSYMBOL_TO = 63,                        /* TO  */
  YYSYMBOL_DEBUG = 64,                     /* DEBUG  */
  YYSYMBOL_GOTO = 65,                      /* GOTO  */
  YYSYMBOL_GOSUB = 66,                     /* GOSUB  */
  YYSYMBOL_RETURN = 67,                    /* RETURN  */
  YYSYMBOL_NEW = 68,                       /* NEW  */
  YYSYMBOL_TRACE = 69,                     /* TRACE  */
  YYSYMBOL_NOTRACE = 70,                   /* NOTRACE  */
  YYSYMBOL_ON = 71,                        /* ON  */
  YYSYMBOL_OFF = 72,                       /* OFF  */
  YYSYMBOL_TEXT = 73,                      /* TEXT  */
  YYSYMBOL_HTAB = 74,                      /* HTAB  */
  YYSYMBOL_VTAB = 75,                      /* VTAB  */
  YYSYMBOL_HOME = 76,                      /* HOME  */
  YYSYMBOL_GR = 77,                        /* GR  */
  YYSYMBOL_PLOT = 78,                      /* PLOT  */
  YYSYMBOL_HGR = 79,                       /* HGR  */
  YYSYMBOL_HPLOT = 80,                     /* HPLOT  */
  YYSYMBOL_END = 81,                       /* END  */
  YYSYMBOL_NOT = 82,                       /* NOT  */
  YYSYMBOL_READ = 83,                      /* READ  */
  YYSYMBOL_DATA = 84,                      /* DATA  */
  YYSYMBOL_VLIN = 85,                      /* VLIN  */
  YYSYMBOL_HLIN = 86,                      /* HLIN  */
  YYSYMBOL_MID = 87,                       /* MID  */
  YYSYMBOL_LEFT = 88,                      /* LEFT  */
  YYSYMBOL_RIGHT = 89,                     /* RIGHT  */
  YYSYMBOL_LEN = 90,                       /* LEN  */
  YYSYMBOL_STRING = 91,                    /* STRING  */
  YYSYMBOL_AMPER = 92,                     /* AMPER  */
  YYSYMBOL_AT = 93,                        /* AT  */
  YYSYMBOL_CHR = 94,                       /* CHR  */
  YYSYMBOL_INT = 95,                       /* INT  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_pgm = 97,                       /* pgm  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_line = 99,                      /* line  */
  YYSYMBOL_100_2 = 100,                    /* $@2  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_inst = 102,                     /* inst  */
  YYSYMBOL_103_4 = 103,                    /* $@4  */
  YYSYMBOL_104_5 = 104,                    /* $@5  */
  YYSYMBOL_105_6 = 105,                    /* $@6  */
  YYSYMBOL_106_7 = 106,                    /* $@7  */
  YYSYMBOL_107_8 = 107,                    /* $@8  */
  YYSYMBOL_108_9 = 108,                    /* $@9  */
  YYSYMBOL_109_10 = 109,                   /* $@10  */
  YYSYMBOL_110_11 = 110,                   /* $@11  */
  YYSYMBOL_111_12 = 111,                   /* $@12  */
  YYSYMBOL_112_13 = 112,                   /* $@13  */
  YYSYMBOL_113_14 = 113,                   /* $@14  */
  YYSYMBOL_114_15 = 114,                   /* $@15  */
  YYSYMBOL_115_16 = 115,                   /* $@16  */
  YYSYMBOL_116_17 = 116,                   /* $@17  */
  YYSYMBOL_117_18 = 117,                   /* $@18  */
  YYSYMBOL_118_19 = 118,                   /* $@19  */
  YYSYMBOL_119_20 = 119,                   /* $@20  */
  YYSYMBOL_120_21 = 120,                   /* $@21  */
  YYSYMBOL_121_22 = 121,                   /* $@22  */
  YYSYMBOL_122_23 = 122,                   /* $@23  */
  YYSYMBOL_123_24 = 123,                   /* $@24  */
  YYSYMBOL_124_25 = 124,                   /* $@25  */
  YYSYMBOL_125_26 = 125,                   /* $@26  */
  YYSYMBOL_126_27 = 126,                   /* $@27  */
  YYSYMBOL_127_28 = 127,                   /* $@28  */
  YYSYMBOL_opt_i = 128,                    /* opt_i  */
  YYSYMBOL_opt_prompt = 129,               /* opt_prompt  */
  YYSYMBOL_opt_then = 130,                 /* opt_then  */
  YYSYMBOL_list = 131,                     /* list  */
  YYSYMBOL_cond = 132,                     /* cond  */
  YYSYMBOL_133_29 = 133,                   /* $@29  */
  YYSYMBOL_134_30 = 134,                   /* $@30  */
  YYSYMBOL_135_31 = 135,                   /* $@31  */
  YYSYMBOL_136_32 = 136,                   /* $@32  */
  YYSYMBOL_oper = 137,                     /* oper  */
  YYSYMBOL_sexpr = 138,                    /* sexpr  */
  YYSYMBOL_multi_expr = 139,               /* multi_expr  */
  YYSYMBOL_140_33 = 140,                   /* $@33  */
  YYSYMBOL_141_34 = 141,                   /* $@34  */
  YYSYMBOL_142_35 = 142,                   /* $@35  */
  YYSYMBOL_143_36 = 143,                   /* $@36  */
  YYSYMBOL_opt_print = 144,                /* opt_print  */
  YYSYMBOL_sep = 145,                      /* sep  */
  YYSYMBOL_string = 146,                   /* string  */
  YYSYMBOL_expr = 147,                     /* expr  */
  YYSYMBOL_148_37 = 148,                   /* $@37  */
  YYSYMBOL_149_38 = 149,                   /* $@38  */
  YYSYMBOL_150_39 = 150,                   /* $@39  */
  YYSYMBOL_151_40 = 151,                   /* $@40  */
  YYSYMBOL_152_41 = 152,                   /* @41  */
  YYSYMBOL_153_42 = 153,                   /* $@42  */
  YYSYMBOL_154_43 = 154,                   /* $@43  */
  YYSYMBOL_155_44 = 155,                   /* $@44  */
  YYSYMBOL_156_45 = 156,                   /* $@45  */
  YYSYMBOL_157_46 = 157,                   /* $@46  */
  YYSYMBOL_158_47 = 158,                   /* @47  */
  YYSYMBOL_159_48 = 159                    /* $@48  */
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
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   350


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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   156,   156,   157,   160,   160,   161,   161,
     164,   164,   164,   166,   166,   166,   166,   176,   176,   176,
     176,   184,   184,   190,   190,   196,   196,   197,   200,   228,
     229,   242,   243,   244,   245,   246,   247,   247,   248,   248,
     249,   249,   250,   250,   251,   252,   252,   253,   253,   254,
     261,   262,   263,   284,   285,   286,   287,   287,   287,   287,
     288,   289,   290,   291,   292,   293,   293,   293,   293,   294,
     294,   294,   295,   296,   297,   306,   308,   309,   310,   325,
     326,   329,   330,   333,   334,   337,   338,   341,   341,   341,
     342,   343,   344,   345,   346,   347,   347,   347,   350,   351,
     352,   353,   354,   357,   358,   359,   360,   361,   362,   365,
     365,   374,   374,   383,   383,   383,   386,   387,   388,   389,
     390,   393,   394,   397,   398,   401,   401,   402,   402,   403,
     403,   404,   404,   405,   405,   406,   407,   408,   430,   431,
     431,   432,   432,   433,   434,   434,   435,   436,   436,   437,
     438,   444,   438,   451,   451
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
  "\"end of file\"", "error", "\"invalid token\"", "PR", "STR", "SAVE",
  "GET", "PEEK", "POKE", "RUN", "RND", "PRINT", "IDENTIFIER", "PLUS",
  "MINUS", "ASTERISK", "DIVIDE", "NUMBER", "LIST", "INPUT", "LET", "SQR",
  "SIN", "COS", "TAN", "EXP", "DIM", "ABS", "OR", "AND", "ASC", "REM",
  "QUOTE", "EQUAL", "PO", "PF", "CO", "CF", "DP", "PG", "PP", "PE", "GE",
  "DIFF", "DOT", "COMMA", "SEMICOLOMN", "CR", "RANDOMIZE", "MOD", "CHARS",
  "FLOAT", "SYSTEM", "DUMP", "CLEAR", "COLOR", "DRAW", "IF", "THEN",
  "ELSE", "FOR", "NEXT", "STEP", "TO", "DEBUG", "GOTO", "GOSUB", "RETURN",
  "NEW", "TRACE", "NOTRACE", "ON", "OFF", "TEXT", "HTAB", "VTAB", "HOME",
  "GR", "PLOT", "HGR", "HPLOT", "END", "NOT", "READ", "DATA", "VLIN",
  "HLIN", "MID", "LEFT", "RIGHT", "LEN", "STRING", "AMPER", "AT", "CHR",
  "INT", "$accept", "pgm", "$@1", "line", "$@2", "$@3", "inst", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "opt_i", "opt_prompt",
  "opt_then", "list", "cond", "$@29", "$@30", "$@31", "$@32", "oper",
  "sexpr", "multi_expr", "$@33", "$@34", "$@35", "$@36", "opt_print",
  "sep", "string", "expr", "$@37", "$@38", "$@39", "$@40", "@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "@47", "$@48", YY_NULLPTR
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
     345,   346,   347,   348,   349,   350
};
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-114)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,     5,  -164,  -164,  -164,  -164,   242,   242,   -46,  -164,
      -8,    -3,    -9,   130,  -164,  -164,  -164,   -44,   -80,  -164,
    -164,  -164,  -164,   130,  -164,  -164,    15,   -39,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   -34,
    -164,    43,   130,   130,   130,  -164,   -43,    25,    56,    25,
    -164,  -164,  -164,   130,    40,    45,  -164,  -164,    48,    62,
      64,    87,    88,    92,  -164,  -164,  -164,   156,     6,    31,
     116,    50,  -164,   131,    -1,    77,   136,  -164,  -164,  -164,
    -164,   130,   130,   130,   130,   130,    86,  -164,   111,    57,
     163,   174,   124,  -164,  -164,  -164,   262,  -164,   130,   130,
    -164,  -164,  -164,   130,   130,    67,   130,   127,  -164,  -164,
    -164,  -164,   130,  -164,   130,    19,    68,  -164,  -164,  -164,
     132,  -164,   130,   129,    77,    77,   -12,   130,   -42,   133,
      57,    57,    57,    57,    57,   130,   130,   130,   130,     6,
     242,   134,  -164,   130,   266,    57,   130,   130,   130,   316,
     322,   138,   326,   130,   130,   130,   130,   130,    57,     8,
      57,   141,  -164,   146,   148,   149,  -164,   171,  -164,   157,
      19,   159,   190,   130,    22,    38,    77,    77,  -164,   242,
     250,   160,  -164,   150,   207,    57,   103,   123,  -164,    25,
    -164,    57,  -164,   330,   334,   339,  -164,  -164,  -164,  -164,
     357,    57,    57,    57,    57,  -164,  -164,     8,    14,   130,
     -42,   -42,   -42,   -42,  -164,   171,  -164,   130,   362,  -164,
      38,    38,    25,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
     130,  -164,  -164,   130,   130,   130,   164,  -164,  -164,  -164,
    -164,    14,   171,    57,   366,   155,   168,   169,  -164,   130,
     130,    57,  -164,   130,   -42,    27,   130,   130,    57,    57,
      57,  -164,   171,    57,  -164,   130,   130,   130,   370,    57,
      57,  -164,  -164,    57,    57,   223,   374,   380,  -164,   130,
     130,  -164,  -164,    57,   397,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     8,     1,     6,     5,     3,    13,    13,     0,    78,
       0,     0,     0,     0,    28,    10,    27,    42,    17,    35,
      29,    30,    77,     0,    36,    56,    79,     0,    38,    40,
      63,    76,    31,    32,    50,    45,    47,    49,    52,    65,
      64,     0,     0,     0,     0,    21,     0,     9,     0,     7,
       4,    74,    55,     0,     0,   137,   147,   135,     0,     0,
       0,     0,     0,     0,   133,   136,   153,     0,   109,     0,
       0,     0,    23,     0,     0,    87,     0,    80,    60,    33,
      34,     0,     0,     0,     0,     0,     0,    62,    61,    85,
       0,     0,     0,    51,    25,    14,     0,   150,     0,     0,
     144,   141,   139,     0,     0,     0,     0,     0,   125,   127,
     129,   131,     0,    11,     0,     0,     0,    82,    43,    44,
       0,    18,     0,     0,    87,    87,    83,     0,     0,     0,
      39,    41,    46,    48,    66,     0,     0,     0,     0,   109,
      13,     0,    53,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,   116,
     110,     0,   124,     0,     0,     0,   123,   112,   103,     0,
       0,     0,     0,     0,     0,    94,    87,    87,    84,    13,
       0,     0,    57,     0,     0,    86,     0,     0,    22,    26,
      15,   151,   138,     0,     0,     0,   143,   146,   149,   134,
       0,   126,   128,   130,   132,   121,   122,    12,     0,     0,
       0,     0,     0,     0,   114,    24,    19,     0,     0,    91,
      92,    93,    37,    98,    99,   100,   101,   102,    88,    96,
       0,    67,    70,     0,     0,     0,     0,   145,   142,   140,
     154,     0,   118,   117,     0,     0,     0,     0,   104,     0,
       0,    75,    90,     0,     0,     0,     0,     0,    73,    72,
      16,   152,   120,   119,   108,     0,     0,     0,     0,    20,
      89,    97,    58,    68,    71,     0,     0,     0,   115,     0,
       0,   106,   107,    59,     0,   105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,  -164,    -5,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,    21,  -164,  -164,  -164,
    -164,  -164,  -163,    63,  -164,  -164,  -164,  -164,  -164,     2,
    -125,   -23,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     8,     5,     7,     6,    47,    68,   159,    48,
     141,   235,    73,   171,   250,    92,   120,   140,    75,    81,
      82,    70,    83,    84,    76,   230,   279,    85,   183,   256,
      86,   257,    78,    71,   179,    88,   126,   127,   253,   128,
     254,   228,   167,   113,   114,   115,   116,   249,   207,   208,
     168,    67,   154,   155,   156,   157,   106,   148,   147,   146,
      99,   143,   236,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    50,    49,   181,    51,     2,    69,   215,   162,    52,
    -111,    72,   108,   109,   110,   111,   176,   177,   161,    89,
      90,    91,     3,   161,    54,    53,    55,    77,    56,   -69,
      96,    57,    79,    80,    93,    58,    59,    60,    61,    62,
     108,   109,   110,   111,    63,   242,   178,   -81,    64,   166,
     176,   177,     4,   205,   206,    87,  -111,   219,   130,   131,
     132,   133,   134,    94,   162,    65,   176,   177,    95,   162,
     108,   109,   110,   111,    97,   144,   145,   117,   262,    98,
     149,   150,   100,   152,   123,   245,   246,   247,   248,   158,
     272,   160,   122,  -111,  -111,  -111,   101,  -111,   102,   172,
    -113,   163,   164,   165,   180,   166,   163,   164,   165,    66,
     166,   124,   184,   185,   186,   187,   108,   109,   110,   111,
     191,   103,   104,   193,   194,   195,   105,   -95,   118,   271,
     200,   201,   202,   203,   204,   189,   108,   109,   110,   111,
      54,   119,    55,   121,    56,   174,   175,    57,   129,   135,
     218,    58,    59,    60,    61,    62,   136,   139,   151,   125,
      63,   153,   169,   173,    64,   170,   182,   190,   -95,   108,
     109,   110,   111,   198,   222,   209,   108,   109,   110,   111,
     210,    65,   211,   212,   213,   243,   244,   108,   109,   110,
     111,   214,   216,   229,   251,   231,   233,   220,   221,   261,
     265,   112,   188,   108,   109,   110,   111,   255,   137,   241,
     258,   259,   260,   266,   267,     0,   234,     0,   263,   138,
     108,   109,   110,   111,     0,    66,   268,   269,     0,     0,
     270,     0,     0,   273,   274,   217,   108,   109,   110,   111,
       0,     0,   275,   276,   277,     9,     0,    10,    11,    12,
      13,    14,   232,    15,     0,     0,   283,   284,     0,     0,
      16,    17,    18,   108,   109,   110,   111,     0,   280,     0,
       0,     0,     0,    19,     0,   108,   109,   110,   111,   108,
     109,   110,   111,   223,     0,     0,     0,     0,     0,   224,
     225,   226,   227,     0,    20,    21,    22,   142,    23,    24,
       0,   192,    25,    26,     0,     0,    27,    28,    29,    30,
      31,    32,    33,     0,     0,    34,    35,    36,    37,     0,
       0,    38,    39,    40,     0,    41,    42,    43,    44,   108,
     109,   110,   111,    45,    46,   108,   109,   110,   111,   108,
     109,   110,   111,   108,   109,   110,   111,   108,   109,   110,
     111,   196,   108,   109,   110,   111,     0,   197,     0,     0,
       0,   199,     0,     0,     0,   237,     0,     0,     0,   238,
     108,   109,   110,   111,   239,   108,   109,   110,   111,   108,
     109,   110,   111,   108,   109,   110,   111,   108,   109,   110,
     111,     0,   240,   108,   109,   110,   111,   252,     0,     0,
       0,   264,     0,     0,     0,   278,     0,     0,     0,   281,
     108,   109,   110,   111,     0,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285
};

static const yytype_int16 yycheck[] =
{
      23,    47,     7,   128,    12,     0,    50,   170,    50,    12,
       4,    91,    13,    14,    15,    16,    28,    29,     4,    42,
      43,    44,    17,     4,    10,    34,    12,    12,    14,    63,
      53,    17,    71,    72,    77,    21,    22,    23,    24,    25,
      13,    14,    15,    16,    30,   208,    58,    91,    34,    91,
      28,    29,    47,    45,    46,    12,    50,    35,    81,    82,
      83,    84,    85,    38,    50,    51,    28,    29,    12,    50,
      13,    14,    15,    16,    34,    98,    99,    46,   241,    34,
     103,   104,    34,   106,     7,   210,   211,   212,   213,   112,
      63,   114,    93,    87,    88,    89,    34,    91,    34,   122,
      94,    87,    88,    89,   127,    91,    87,    88,    89,    95,
      91,    34,   135,   136,   137,   138,    13,    14,    15,    16,
     143,    34,    34,   146,   147,   148,    34,    50,    12,   254,
     153,   154,   155,   156,   157,   140,    13,    14,    15,    16,
      10,    91,    12,    12,    14,   124,   125,    17,    12,    63,
     173,    21,    22,    23,    24,    25,    45,    33,    91,    82,
      30,    34,    94,    34,    34,    33,    33,    33,    91,    13,
      14,    15,    16,    35,   179,    34,    13,    14,    15,    16,
      34,    51,    34,    34,    13,   208,   209,    13,    14,    15,
      16,    34,    33,    33,   217,    45,    93,   176,   177,    35,
      45,    45,   139,    13,    14,    15,    16,   230,    45,   207,
     233,   234,   235,    45,    45,    -1,    93,    -1,   241,    45,
      13,    14,    15,    16,    -1,    95,   249,   250,    -1,    -1,
     253,    -1,    -1,   256,   257,    45,    13,    14,    15,    16,
      -1,    -1,   265,   266,   267,     3,    -1,     5,     6,     7,
       8,     9,    45,    11,    -1,    -1,   279,   280,    -1,    -1,
      18,    19,    20,    13,    14,    15,    16,    -1,    45,    -1,
      -1,    -1,    -1,    31,    -1,    13,    14,    15,    16,    13,
      14,    15,    16,    33,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    52,    53,    54,    35,    56,    57,
      -1,    35,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    84,    85,    86,    13,
      14,    15,    16,    91,    92,    13,    14,    15,    16,    13,
      14,    15,    16,    13,    14,    15,    16,    13,    14,    15,
      16,    35,    13,    14,    15,    16,    -1,    35,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    35,    -1,    -1,    -1,    35,
      13,    14,    15,    16,    35,    13,    14,    15,    16,    13,
      14,    15,    16,    13,    14,    15,    16,    13,    14,    15,
      16,    -1,    35,    13,    14,    15,    16,    35,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    35,    -1,    -1,    -1,    35,
      13,    14,    15,    16,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,     0,    17,    47,    99,   101,   100,    98,     3,
       5,     6,     7,     8,     9,    11,    18,    19,    20,    31,
      52,    53,    54,    56,    57,    60,    61,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    75,    76,    79,    80,
      81,    83,    84,    85,    86,    91,    92,   102,   105,   102,
      47,    12,    12,    34,    10,    12,    14,    17,    21,    22,
      23,    24,    25,    30,    34,    51,    95,   147,   103,    50,
     117,   129,    91,   108,   147,   114,   120,    12,   128,    71,
      72,   115,   116,   118,   119,   123,   126,    12,   131,   147,
     147,   147,   111,    77,    38,    12,   147,    34,    34,   156,
      34,    34,    34,    34,    34,    34,   152,   159,    13,    14,
      15,    16,    45,   139,   140,   141,   142,    46,    12,    91,
     112,    12,    93,     7,    34,    82,   132,   133,   135,    12,
     147,   147,   147,   147,   147,    63,    45,    45,    45,    33,
     113,   106,    35,   157,   147,   147,   155,   154,   153,   147,
     147,    91,   147,    34,   148,   149,   150,   151,   147,   104,
     147,     4,    50,    87,    88,    89,    91,   138,   146,    94,
      33,   109,   147,    34,   132,   132,    28,    29,    58,   130,
     147,   146,    33,   124,   147,   147,   147,   147,   139,   102,
      33,   147,    35,   147,   147,   147,    35,    35,    35,    35,
     147,   147,   147,   147,   147,    45,    46,   144,   145,    34,
      34,    34,    34,    13,    34,   138,    33,    45,   147,    35,
     132,   132,   102,    33,    39,    40,    41,    42,   137,    33,
     121,    45,    45,    93,    93,   107,   158,    35,    35,    35,
      35,   145,   138,   147,   147,   146,   146,   146,   146,   143,
     110,   147,    35,   134,   136,   147,   125,   127,   147,   147,
     147,    35,   138,   147,    35,    45,    45,    45,   147,   147,
     147,   146,    63,   147,   147,   147,   147,   147,    35,   122,
      45,    35,    35,   147,   147,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    97,    97,   100,    99,   101,    99,
     103,   104,   102,   105,   106,   107,   102,   108,   109,   110,
     102,   111,   102,   112,   102,   113,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   114,   102,   115,   102,
     116,   102,   117,   102,   102,   118,   102,   119,   102,   102,
     102,   102,   102,   102,   102,   102,   120,   121,   122,   102,
     102,   102,   102,   102,   102,   123,   124,   125,   102,   126,
     127,   102,   102,   102,   102,   102,   102,   102,   102,   128,
     128,   129,   129,   130,   130,   131,   131,   133,   134,   132,
     132,   132,   132,   132,   132,   135,   136,   132,   137,   137,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   140,
     139,   141,   139,   142,   143,   139,   144,   144,   144,   144,
     144,   145,   145,   146,   146,   148,   147,   149,   147,   150,
     147,   151,   147,   152,   147,   147,   147,   147,   147,   153,
     147,   154,   147,   147,   155,   147,   147,   156,   147,   147,
     157,   158,   147,   159,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     4,     2,     0,     3,     0,     2,
       0,     0,     5,     0,     0,     0,     6,     0,     0,     0,
       7,     0,     4,     0,     5,     0,     4,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     5,     0,     3,
       0,     3,     0,     3,     3,     0,     3,     0,     3,     1,
       1,     2,     1,     4,     4,     2,     0,     0,     0,     9,
       2,     2,     2,     1,     1,     0,     0,     0,     7,     0,
       0,     7,     6,     6,     2,     6,     1,     1,     1,     0,
       1,     0,     2,     0,     1,     1,     3,     0,     0,     5,
       4,     3,     3,     3,     2,     0,     0,     5,     1,     1,
       1,     1,     1,     1,     3,     8,     6,     6,     4,     0,
       2,     0,     2,     0,     0,     6,     0,     2,     2,     3,
       3,     1,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     1,     1,     1,     4,     0,
       5,     0,     5,     4,     0,     5,     4,     0,     3,     4,
       0,     0,     6,     0,     5
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
#line 155 "grsoft.y"
{ printf("]"); }
#line 1660 "grsoft.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 156 "grsoft.y"
            { printf("]"); strcpy(chars,"");strcpy(string,""); }
#line 1666 "grsoft.tab.c"
    break;

  case 5: /* pgm: pgm CR  */
#line 157 "grsoft.y"
          { printf("]"); strcpy(chars,""); }
#line 1672 "grsoft.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 160 "grsoft.y"
             { im=0; l=atoi(yytext); strcpy(lines[l],""); }
#line 1678 "grsoft.tab.c"
    break;

  case 7: /* line: NUMBER $@2 inst  */
#line 160 "grsoft.y"
                                                                 { if (!im&&!infor) strcat(lines[l],";"); else infor=0;  }
#line 1684 "grsoft.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 161 "grsoft.y"
        { im=1; }
#line 1690 "grsoft.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 164 "grsoft.y"
            { if (!im) strcat(lines[l],"printf(\"%"); }
#line 1696 "grsoft.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 164 "grsoft.y"
                                                                   { if (!im) strcat(lines[l],")"); 
 }
#line 1703 "grsoft.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 166 "grsoft.y"
   { notdef=1; }
#line 1709 "grsoft.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 166 "grsoft.y"
                            { d=r; while(d) { if (strcmp(d->name,identifier)==0) notdef=0; d=d->next; } if (notdef&&!im) strcat(lines[l],"float "); strcpy(a,identifier); }
#line 1715 "grsoft.tab.c"
    break;

  case 15: /* $@8: %empty  */
#line 166 "grsoft.y"
                                                                                                                                                                                  { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  }
#line 1721 "grsoft.tab.c"
    break;

  case 16: /* inst: $@6 IDENTIFIER $@7 EQUAL $@8 expr  */
#line 166 "grsoft.y"
                                                                                                                                                                                                                                                    { 
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=yyvsp[0]; strcpy(d->name,a); d->next=r; r=d;
	} else {	
		if (im) d->value=yyvsp[0];
	}
}
#line 1734 "grsoft.tab.c"
    break;

  case 17: /* $@9: %empty  */
#line 176 "grsoft.y"
       { notdef=1; }
#line 1740 "grsoft.tab.c"
    break;

  case 18: /* $@10: %empty  */
#line 176 "grsoft.y"
                                { if (!im&&notdef) strcat(lines[l],"float "); d=r; strcpy(a,identifier); while (d) { if (strcmp(d->name,identifier)==0) { notdef=0; break; } d=d->next; } }
#line 1746 "grsoft.tab.c"
    break;

  case 19: /* $@11: %empty  */
#line 176 "grsoft.y"
                                                                                                                                                                                                  { if (!im) sprintf(lines[l],"%s%s=",lines[l],identifier);  }
#line 1752 "grsoft.tab.c"
    break;

  case 20: /* inst: LET $@9 IDENTIFIER $@10 EQUAL $@11 expr  */
#line 176 "grsoft.y"
                                                                                                                                                                                                                                                                    { if (im) {
	if (notdef) {
		d=(struct var*)malloc(sizeof(struct var));
		d->value=yyvsp[0]; strcpy(d->name,a); d->next=r; r=d;
	} else
		d->value=yyvsp[0];
} 
}
#line 1765 "grsoft.tab.c"
    break;

  case 21: /* $@12: %empty  */
#line 184 "grsoft.y"
          { if (im) strcpy(A,yytext); }
#line 1771 "grsoft.tab.c"
    break;

  case 22: /* inst: STRING $@12 EQUAL multi_expr  */
#line 184 "grsoft.y"
                                                          { if (im) {
	D=(struct str*)malloc(sizeof(struct str));
	strcpy(D->value,string);strcpy(D->name,A); D->next=root; root=D;	} else {
	sprintf(lines[l],"char * %s = %s",identifier,chars);
}
}
#line 1782 "grsoft.tab.c"
    break;

  case 23: /* $@13: %empty  */
#line 190 "grsoft.y"
              { if (im) strcpy(A,yytext); }
#line 1788 "grsoft.tab.c"
    break;

  case 24: /* inst: LET STRING $@13 EQUAL sexpr  */
#line 190 "grsoft.y"
                                                         { if (im) {
	D=(struct str*)malloc(sizeof(struct str));
	strcpy(D->value,string);strcpy(D->name,A); D->next=root; root=D;	} else {
	sprintf(lines[l],"char * %s = %s",identifier,chars);
}
}
#line 1799 "grsoft.tab.c"
    break;

  case 25: /* $@14: %empty  */
#line 196 "grsoft.y"
           { if (!im) sprintf(lines[l],"%s;",lines[l]); }
#line 1805 "grsoft.tab.c"
    break;

  case 27: /* inst: LIST  */
#line 197 "grsoft.y"
        {
	if (im) { int i; for(i=0;i<65536;i++) if (strcmp(lines[i],"")) printf("%d %s\n",i,lines[i]); }
 }
#line 1813 "grsoft.tab.c"
    break;

  case 28: /* inst: RUN  */
#line 200 "grsoft.y"
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
		printf("\nµsec=%d\n",(int)(diff*1000000 + tv2->tv_usec - tv1->tv_usec));
	}
	
 }
}
#line 1846 "grsoft.tab.c"
    break;

  case 29: /* inst: SYSTEM  */
#line 228 "grsoft.y"
          { if (im) exit(0); else sprintf(lines[l],"%s exit(0)",lines[l]); }
#line 1852 "grsoft.tab.c"
    break;

  case 30: /* inst: DUMP  */
#line 229 "grsoft.y"
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
#line 1870 "grsoft.tab.c"
    break;

  case 31: /* inst: TRACE  */
#line 242 "grsoft.y"
         { trace=1; }
#line 1876 "grsoft.tab.c"
    break;

  case 32: /* inst: NOTRACE  */
#line 243 "grsoft.y"
           { trace=0; }
#line 1882 "grsoft.tab.c"
    break;

  case 33: /* inst: DEBUG ON  */
#line 244 "grsoft.y"
            { yydebug=1; }
#line 1888 "grsoft.tab.c"
    break;

  case 34: /* inst: DEBUG OFF  */
#line 245 "grsoft.y"
             { yydebug=0; }
#line 1894 "grsoft.tab.c"
    break;

  case 36: /* $@15: %empty  */
#line 247 "grsoft.y"
      { sprintf(lines[l],"%sif ",lines[l]);}
#line 1900 "grsoft.tab.c"
    break;

  case 38: /* $@16: %empty  */
#line 248 "grsoft.y"
        { sprintf(lines[l],"%s%s",lines[l],"goto L"); }
#line 1906 "grsoft.tab.c"
    break;

  case 40: /* $@17: %empty  */
#line 249 "grsoft.y"
         { if (!im) strcat(lines[l],"if (!setjmp(buf)) goto L"); }
#line 1912 "grsoft.tab.c"
    break;

  case 42: /* $@18: %empty  */
#line 250 "grsoft.y"
         { if (!im) strcat(lines[l],"fgets(s,1024,stdin);float "); }
#line 1918 "grsoft.tab.c"
    break;

  case 43: /* inst: INPUT $@18 IDENTIFIER  */
#line 250 "grsoft.y"
                                                                                { if (!im) sprintf(lines[l],"%s%s=atof(s)",lines[l],identifier); else fprintf(stderr,"NO DIRECT COMMAND\n"); }
#line 1924 "grsoft.tab.c"
    break;

  case 44: /* inst: INPUT opt_prompt STRING  */
#line 251 "grsoft.y"
                           { if (!im) sprintf(lines[l],"%schar %s[256];fgets(%s,256,stdin)",lines[l],identifier,identifier); }
#line 1930 "grsoft.tab.c"
    break;

  case 45: /* $@19: %empty  */
#line 252 "grsoft.y"
        { if (!im) sprintf(lines[l],"%sprintf(\"%%c[%d;",lines[l],cx); }
#line 1936 "grsoft.tab.c"
    break;

  case 46: /* inst: HTAB $@19 expr  */
#line 252 "grsoft.y"
                                                                              { if (!im) sprintf(lines[l],"%sH\",27)",lines[l]); }
#line 1942 "grsoft.tab.c"
    break;

  case 47: /* $@20: %empty  */
#line 253 "grsoft.y"
        { if (!im) strcat(lines[l],"printf(\"%c["); }
#line 1948 "grsoft.tab.c"
    break;

  case 48: /* inst: VTAB $@20 expr  */
#line 253 "grsoft.y"
                                                           { if (!im) sprintf(lines[l],"%s;%dH\",27)",lines[l],cy); }
#line 1954 "grsoft.tab.c"
    break;

  case 49: /* inst: HOME  */
#line 254 "grsoft.y"
        { if (im)
#ifdef WIN32
system("cls");
#else /* ANSI */
printf("%c[2J",27);
#endif
else strcat (lines[l],"printf(\"%c[2J\",27)");   }
#line 1966 "grsoft.tab.c"
    break;

  case 50: /* inst: TEXT  */
#line 261 "grsoft.y"
        { if (im) { SDL_Quit(); hgr=0; } }
#line 1972 "grsoft.tab.c"
    break;

  case 52: /* inst: HGR  */
#line 263 "grsoft.y"
       { if (im) {
hgr=1;
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS )) fprintf(stderr, "Echec SDL retour au mode texte (%s)", SDL_GetError());
	if (SDL_CreateWindowAndRenderer(281,192,0,&pWindow,&renderer)==0) {
            done = SDL_FALSE;
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
               SDL_RenderClear(renderer);

               SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_QueryTexture(sprite, NULL, NULL, &pos.w, &pos.h);
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
#line 1998 "grsoft.tab.c"
    break;

  case 56: /* $@21: %empty  */
#line 287 "grsoft.y"
       { infor = 1; }
#line 2004 "grsoft.tab.c"
    break;

  case 57: /* $@22: %empty  */
#line 287 "grsoft.y"
                                       { strcat(lines[l],"for(I="); }
#line 2010 "grsoft.tab.c"
    break;

  case 58: /* $@23: %empty  */
#line 287 "grsoft.y"
                                                                              { strcat(lines[l],";I<="); }
#line 2016 "grsoft.tab.c"
    break;

  case 59: /* inst: FOR $@21 IDENTIFIER EQUAL $@22 expr TO $@23 expr  */
#line 287 "grsoft.y"
                                                                                                                { strcat(lines[l],";I++) {"); }
#line 2022 "grsoft.tab.c"
    break;

  case 60: /* inst: NEXT opt_i  */
#line 288 "grsoft.y"
              { if (!im) strcat(lines[l],"}"); }
#line 2028 "grsoft.tab.c"
    break;

  case 63: /* inst: RETURN  */
#line 291 "grsoft.y"
          { if (!im) strcat(lines[l],"longjmp(buf,1)"); }
#line 2034 "grsoft.tab.c"
    break;

  case 64: /* inst: END  */
#line 292 "grsoft.y"
       { if (!im) strcat(lines[l],"return"); else return 0;  }
#line 2040 "grsoft.tab.c"
    break;

  case 65: /* $@24: %empty  */
#line 293 "grsoft.y"
         { if (!im) strcat(lines[l],"hplot(renderer,(int)("); }
#line 2046 "grsoft.tab.c"
    break;

  case 66: /* $@25: %empty  */
#line 293 "grsoft.y"
                                                                     { if(im) b1=atoi(yytext); }
#line 2052 "grsoft.tab.c"
    break;

  case 67: /* $@26: %empty  */
#line 293 "grsoft.y"
                                                                                                       { if (!im) strcat(lines[l],"),(int)("); }
#line 2058 "grsoft.tab.c"
    break;

  case 68: /* inst: HPLOT $@24 expr $@25 COMMA $@26 expr  */
#line 293 "grsoft.y"
                                                                                                                                                      { b2=atoi(yytext); if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
#line 2064 "grsoft.tab.c"
    break;

  case 69: /* $@27: %empty  */
#line 294 "grsoft.y"
         { if (!im) strcat(lines[l],"SDL_RenderDrawLine(renderer,b1,b2,(int)("); }
#line 2070 "grsoft.tab.c"
    break;

  case 70: /* $@28: %empty  */
#line 294 "grsoft.y"
                                                                                                 { if (!im) strcat(lines[l],"),(int)("); }
#line 2076 "grsoft.tab.c"
    break;

  case 71: /* inst: HPLOT $@27 TO expr COMMA $@28 expr  */
#line 294 "grsoft.y"
                                                                                                                                                { if (!im) strcat(lines[l],"));\nSDL_RenderPresent(renderer)"); }
#line 2082 "grsoft.tab.c"
    break;

  case 74: /* inst: SAVE IDENTIFIER  */
#line 297 "grsoft.y"
                   {
	if (im) {
		FILE * fp;
		int i;
		fp=fopen(identifier,"w");
		for(i=0;i<65536;i++) if (strcmp(lines[i],"")) fprintf(fp,"L%d: %s\n",i,lines[i]);
		fclose(fp);
 }
 }
#line 2096 "grsoft.tab.c"
    break;

  case 75: /* inst: DRAW expr AT expr COMMA expr  */
#line 306 "grsoft.y"
                                { if (im) { pos.x=(int)yyvsp[-2]; pos.y=(int)yyvsp[0]; SDL_RenderCopy(renderer,sprite,NULL,&pos); SDL_RenderPresent(renderer);
 } }
#line 2103 "grsoft.tab.c"
    break;

  case 76: /* inst: NEW  */
#line 308 "grsoft.y"
       { int i; for(i=0;i<65536;i++) strcpy(lines[i],""); }
#line 2109 "grsoft.tab.c"
    break;

  case 77: /* inst: CLEAR  */
#line 309 "grsoft.y"
         { if (im) { r=NULL; root=NULL; } }
#line 2115 "grsoft.tab.c"
    break;

  case 82: /* opt_prompt: CHARS SEMICOLOMN  */
#line 330 "grsoft.y"
                             { if (!im) sprintf(lines[l],"%sprintf(%s);",lines[l],chars); }
#line 2121 "grsoft.tab.c"
    break;

  case 87: /* $@29: %empty  */
#line 341 "grsoft.y"
      { sprintf(lines[l],"%s ( ",lines[l]); }
#line 2127 "grsoft.tab.c"
    break;

  case 88: /* $@30: %empty  */
#line 341 "grsoft.y"
                                                        { sprintf(lines[l],"%s %s ",lines[l],oper); }
#line 2133 "grsoft.tab.c"
    break;

  case 89: /* cond: $@29 expr oper $@30 expr  */
#line 341 "grsoft.y"
                                                                                                           { sprintf(lines[l],"%s ) ",lines[l]); }
#line 2139 "grsoft.tab.c"
    break;

  case 95: /* $@31: %empty  */
#line 347 "grsoft.y"
          { if (!im) strcat(lines[l],"(strcmp("); }
#line 2145 "grsoft.tab.c"
    break;

  case 96: /* $@32: %empty  */
#line 347 "grsoft.y"
                                                                 { if (!im) strcat(lines[l],","); }
#line 2151 "grsoft.tab.c"
    break;

  case 97: /* cond: $@31 string EQUAL $@32 string  */
#line 347 "grsoft.y"
                                                                                                           { if (!im) strcat(lines[l],")==0) "); }
#line 2157 "grsoft.tab.c"
    break;

  case 98: /* oper: EQUAL  */
#line 350 "grsoft.y"
            { strcpy(oper,"=="); }
#line 2163 "grsoft.tab.c"
    break;

  case 99: /* oper: PG  */
#line 351 "grsoft.y"
             { strcpy(oper,">"); }
#line 2169 "grsoft.tab.c"
    break;

  case 100: /* oper: PP  */
#line 352 "grsoft.y"
             { strcpy(oper,"<"); }
#line 2175 "grsoft.tab.c"
    break;

  case 101: /* oper: PE  */
#line 353 "grsoft.y"
             { strcpy(oper,"<="); }
#line 2181 "grsoft.tab.c"
    break;

  case 102: /* oper: GE  */
#line 354 "grsoft.y"
             { strcpy(oper,">="); }
#line 2187 "grsoft.tab.c"
    break;

  case 104: /* sexpr: sexpr PLUS string  */
#line 358 "grsoft.y"
                            { if (im) strcat(string,chars); }
#line 2193 "grsoft.tab.c"
    break;

  case 106: /* sexpr: LEFT PO string COMMA expr PF  */
#line 360 "grsoft.y"
                                       { if (im) { chars[(int)yyvsp[-1]]=0;strcpy(string,chars); } }
#line 2199 "grsoft.tab.c"
    break;

  case 108: /* sexpr: STR PO expr PF  */
#line 362 "grsoft.y"
                         { if (im) sprintf(string,"%d",(int)yyvsp[-1]); }
#line 2205 "grsoft.tab.c"
    break;

  case 109: /* $@33: %empty  */
#line 365 "grsoft.y"
            { if (!im) strcat(lines[l],"g\","); }
#line 2211 "grsoft.tab.c"
    break;

  case 110: /* multi_expr: $@33 expr  */
#line 365 "grsoft.y"
                                                       { if (im) {
	d=r;
	while (d) {
		if (strcmp(d->name,identifier)==0)
			printf("%g\n",d->value);
		d=d->next;
	}
}
}
#line 2225 "grsoft.tab.c"
    break;

  case 111: /* $@34: %empty  */
#line 374 "grsoft.y"
          { if (!im) strcat(lines[l],"s\","); }
#line 2231 "grsoft.tab.c"
    break;

  case 112: /* multi_expr: $@34 sexpr  */
#line 374 "grsoft.y"
                                                      { if (im) {
	D=root;
	while (D) {
		if (strcmp(D->name,identifier)==0)
			printf("%s\n",D->value);
		D=D->next;
	}
}
}
#line 2245 "grsoft.tab.c"
    break;

  case 113: /* $@35: %empty  */
#line 383 "grsoft.y"
          { if (!im) strcat(lines[l],"c\","); }
#line 2251 "grsoft.tab.c"
    break;

  case 114: /* $@36: %empty  */
#line 383 "grsoft.y"
                                                       { if (!im) strcat(lines[l],"(int)"); }
#line 2257 "grsoft.tab.c"
    break;

  case 115: /* multi_expr: $@35 CHR PO $@36 expr PF  */
#line 383 "grsoft.y"
                                                                                                      { if (im) printf("%c",(int)yyvsp[-1]); }
#line 2263 "grsoft.tab.c"
    break;

  case 116: /* opt_print: %empty  */
#line 386 "grsoft.y"
           { if (!im) strcat(lines[l],";printf(\"\\n\")"); }
#line 2269 "grsoft.tab.c"
    break;

  case 123: /* string: STRING  */
#line 397 "grsoft.y"
               { if (im) strcpy(identifier,yytext); else sprintf(lines[l],"%s%s",lines[l],identifier); }
#line 2275 "grsoft.tab.c"
    break;

  case 124: /* string: CHARS  */
#line 398 "grsoft.y"
                { if (!im) strcat(lines[l],chars); else strcpy(string,chars+1);string[strlen(string)-1]=0; }
#line 2281 "grsoft.tab.c"
    break;

  case 125: /* $@37: %empty  */
#line 401 "grsoft.y"
                { if (!im) strcat(lines[l],"+"); }
#line 2287 "grsoft.tab.c"
    break;

  case 126: /* expr: expr PLUS $@37 expr  */
#line 401 "grsoft.y"
                                                        { if (im) yyval=yyvsp[-3]+yyvsp[0]; }
#line 2293 "grsoft.tab.c"
    break;

  case 127: /* $@38: %empty  */
#line 402 "grsoft.y"
              { if (!im) strcat(lines[l],"-"); }
#line 2299 "grsoft.tab.c"
    break;

  case 128: /* expr: expr MINUS $@38 expr  */
#line 402 "grsoft.y"
                                                      { if (im) yyval=yyvsp[-3]-yyvsp[0]; }
#line 2305 "grsoft.tab.c"
    break;

  case 129: /* $@39: %empty  */
#line 403 "grsoft.y"
                 { if (!im) strcat(lines[l],"*"); }
#line 2311 "grsoft.tab.c"
    break;

  case 130: /* expr: expr ASTERISK $@39 expr  */
#line 403 "grsoft.y"
                                                         { if (im) yyval=yyvsp[-3]*yyvsp[0]; }
#line 2317 "grsoft.tab.c"
    break;

  case 131: /* $@40: %empty  */
#line 404 "grsoft.y"
                { if (!im) strcat(lines[l],"/"); }
#line 2323 "grsoft.tab.c"
    break;

  case 132: /* expr: expr DIVIDE $@40 expr  */
#line 404 "grsoft.y"
                                                        { if (im) yyval=yyvsp[-3]/yyvsp[0]; }
#line 2329 "grsoft.tab.c"
    break;

  case 133: /* @41: %empty  */
#line 405 "grsoft.y"
      { if (!im) strcat(lines[l],"("); }
#line 2335 "grsoft.tab.c"
    break;

  case 134: /* expr: PO @41 expr PF  */
#line 405 "grsoft.y"
                                                 { if (im) yyval=yyvsp[-2]; else strcat(lines[l],")"); }
#line 2341 "grsoft.tab.c"
    break;

  case 135: /* expr: NUMBER  */
#line 406 "grsoft.y"
          { if (im) yyval=yyvsp[0]; else strcat(lines[l],yytext); }
#line 2347 "grsoft.tab.c"
    break;

  case 136: /* expr: FLOAT  */
#line 407 "grsoft.y"
         { if (im) yyval=yyvsp[0]; else strcat(lines[l],yytext); }
#line 2353 "grsoft.tab.c"
    break;

  case 137: /* expr: IDENTIFIER  */
#line 408 "grsoft.y"
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
#line 2380 "grsoft.tab.c"
    break;

  case 139: /* $@42: %empty  */
#line 431 "grsoft.y"
          { if (!im) strcat(lines[l],"cos(");  }
#line 2386 "grsoft.tab.c"
    break;

  case 140: /* expr: COS PO $@42 expr PF  */
#line 431 "grsoft.y"
                                                         { if (im) yyval=cos(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2392 "grsoft.tab.c"
    break;

  case 141: /* $@43: %empty  */
#line 432 "grsoft.y"
          { if (!im) strcat(lines[l],"sin(");  }
#line 2398 "grsoft.tab.c"
    break;

  case 142: /* expr: SIN PO $@43 expr PF  */
#line 432 "grsoft.y"
                                                         { if (im) yyval=sin(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2404 "grsoft.tab.c"
    break;

  case 143: /* expr: TAN PO expr PF  */
#line 433 "grsoft.y"
                  { if (im) yyval=tan(yyvsp[-1]); }
#line 2410 "grsoft.tab.c"
    break;

  case 144: /* $@44: %empty  */
#line 434 "grsoft.y"
          { if (!im) strcat(lines[l],"sqrt("); }
#line 2416 "grsoft.tab.c"
    break;

  case 145: /* expr: SQR PO $@44 expr PF  */
#line 434 "grsoft.y"
                                                         { if (im) yyval=sqrt(yyvsp[-1]); else strcat(lines[l],")"); }
#line 2422 "grsoft.tab.c"
    break;

  case 146: /* expr: EXP PO expr PF  */
#line 435 "grsoft.y"
                  { if (im) yyval=exp(yyvsp[-1]); }
#line 2428 "grsoft.tab.c"
    break;

  case 147: /* $@45: %empty  */
#line 436 "grsoft.y"
         { if (!im) strcat(lines[l],"-"); }
#line 2434 "grsoft.tab.c"
    break;

  case 148: /* expr: MINUS $@45 expr  */
#line 436 "grsoft.y"
                                                 { if (im) yyval=-yyvsp[0]; }
#line 2440 "grsoft.tab.c"
    break;

  case 150: /* $@46: %empty  */
#line 438 "grsoft.y"
          { if (!im) 
#ifdef WIN32
strcat(lines[l],"rand()*");
#else
strcat(lines[l],"drand48()*");
#endif
}
#line 2452 "grsoft.tab.c"
    break;

  case 151: /* @47: %empty  */
#line 444 "grsoft.y"
       { if (im) 
#ifdef WIN32
yyval=rand()*yyvsp[0];
#else
yyval=drand48()*yyvsp[0];
#endif
}
#line 2464 "grsoft.tab.c"
    break;

  case 153: /* $@48: %empty  */
#line 451 "grsoft.y"
       { if (!im) strcat(lines[l],"roundf("); }
#line 2470 "grsoft.tab.c"
    break;

  case 154: /* expr: INT $@48 PO expr PF  */
#line 451 "grsoft.y"
                                                           { if (im) yyval=(int)yyvsp[-1]; else strcat(lines[l],")");  }
#line 2476 "grsoft.tab.c"
    break;


#line 2480 "grsoft.tab.c"

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

#line 454 "grsoft.y"

#include"lex.yy.c"
void  yyerror(char *s) {
if (im) 
	fprintf(stderr,"%s on %d\n",s,yychar);
else
	fprintf(stderr,"%s on %d line %d\n",s,yychar,l);
	yyparse();
}

int main(int argc,char * argv[]) {
char rcsrev[]="$Revision: 1.30 $";

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
               temp = SDL_LoadBMP("/usr/lib64/sprite.bmp");
if (temp) {
                        sprite = SDL_CreateTextureFromSurface(renderer, temp);
                } else {
                        fprintf(stderr, "Error /usr/lib64/sprite.bmp\n");
                }

yyparse();
fprintf(stderr,"FIN\n");
}

int WinMain() {
char rcsrev[]="$Revision: 1.30 $";

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
	int i;
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
	for(i=0;i<65536;i++) {
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

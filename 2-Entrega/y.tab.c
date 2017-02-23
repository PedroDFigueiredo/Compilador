/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include "TabelaTipos.h"

#define YYSTYPE atributos

using namespace std;



struct atributos
{
    string label;
    string operador;
    string traducao;
    string tipo;
    string nomeTemp;
    vector<string> colLabels;
    
};

class VarNode{
    public: 
        string nomeTKid; //a, b;
        string nomeTemp; //Var0, Var2;
        string tipo;
        int tamString;
        VarNode(string , string, string, int);
};
VarNode::VarNode(string a, string b, string c, int d = 0){
    nomeTemp = a;
    tipo = b;
    nomeTKid = c;
    tamString = d;
};
class Funcao{
    public:
        string nomeTemp;
        string tkid;
        string tipo;
        string traducao;
        vector<VarNode*> parametros;
        vector<VarNode*> retornos;
        Funcao(string a, string b, string c);
};
Funcao::Funcao(string a, string b, string c){
    nomeTemp = a;
    tipo = b;
    tkid = c;
};
Funcao* getFunc(string nomeTemp);
VarNode* getVar(string nomeTemp);
VarNode* getLabel(string nomeTemp);
typedef map<string, VarNode*> MapVarNode;
typedef map<string, Funcao*> MapFuncao;
pair<string,string> geraLabelEscopo();

class Escopo{
    public:
        int nivel;
        int profundidade;
        bool isCondicional;
        string labelInicio;
        string labelFim;
        MapVarNode tkIdTable;
        MapVarNode varTable;
        MapFuncao funcTable;
        MapFuncao funcTempTable;
        vector<Escopo*> list_escopo;
        Escopo *escopoPai;
        Escopo(int);
        Escopo(int, int);

};
Escopo::Escopo(int n){
    nivel = n;
};
Escopo::Escopo(int a, int b){
    nivel = a;
    profundidade = b;

    pair<string,string> p = geraLabelEscopo();
    labelInicio = p.first;
    labelFim = p.second;
};

//vector< Escopo*> list_escopo;
Escopo *EscopoGlobal = new Escopo(0, 0);
Escopo *EscopoAtual = EscopoGlobal;


//Contagem para tabela de variaveis
//criar por escopo
int varCount=0;
int funcCount=0;
int nivel_escopo = 0;
int profu_escopo = 1;
int labelCount = 1;
string switch_var;
string condicional_label;

void iniEscopoIf();
void iniEscopo();
void fimEscopo();


void criaTabelaTipos();
void addNewVarToTable(string nomeTemp, string tipo);
void addNewFuncToTable(string nomeTemp, string tipo, vector<VarNode*> params);
void geraFuncao(string name, string tipo, vector<string> col);


//string verificaTipo(string tipoA, string operador, string tipoB);
string verificaTipo(atributos *a, atributos *b,string operador, atributos *c);
string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c);
pair<string, string> verificaTipoRelacional(string a, string operador, string b);
string verificaTipoAtribuicao(string label1, string operador, string label2);
string verificaTipoAtribuicao_func(string label1, string operador, string label2, string labelFunc);
string buscaTipoTabela(string tipoA, string operador, string tipoB);
string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c);
string geraVarString(atributos *a);
string geraVarSubrescritaString(string a, string b);

string to_string(int i);
string addNewVar();
string geraVar(string tipo);
string geraVar(string tipo, string tkid);
string geraFunc(string tipo);
string geraFunc(string tipo, string tkid, vector<VarNode*> params);
string decl = "";

//busca variaveis dentro do escopo
pair<bool, VarNode*> varByTkid(string tkid);
pair<bool, VarNode*> varByNameTemp(string nomeTemp);
pair<bool, Funcao*> getFuncByTkid(string tkid);
pair<bool, Funcao*> getFuncByNameTemp(string tkid);
pair<bool, VarNode*> getVarFuncEscopoAtual(string nomeTemp);

//prints declarações variáveis...
void printFuncDeclarations();
void printVarDeclarations();
void printFuncoes();

pair<string,string> geraLabelEscopo();

int yylex(void);
void yyerror(string);


#line 223 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIS = 258,
    TK_MENOS = 259,
    TK_MULT = 260,
    TK_RAZAO = 261,
    TK_POTENCIA = 262,
    TK_CONCAT = 263,
    TK_AND = 264,
    TK_OR = 265,
    TK_MAIOR = 266,
    TK_MENOR = 267,
    TK_DIFERENTE = 268,
    TK_IGUAL = 269,
    TK_MENOR_IGUAL = 270,
    TK_MAIOR_IGUAL = 271,
    TK_ATRIBUICAO = 272,
    TK_VAR = 273,
    TK_GLOBAL = 274,
    TK_TIPO_STRING = 275,
    TK_TIPO_FLOAT = 276,
    TK_TIPO_CHAR = 277,
    TK_TIPO_BOOL = 278,
    TK_TIPO_INT = 279,
    TK_INT = 280,
    TK_FLOAT = 281,
    TK_CHAR = 282,
    TK_BOOL = 283,
    TK_STRING = 284,
    TK_VOID = 285,
    TK_WHILE = 286,
    TK_FOR = 287,
    TK_SWITCH = 288,
    TK_CASE = 289,
    TK_IF = 290,
    TK_ELSE = 291,
    TK_ELIF = 292,
    TK_BREAK = 293,
    TK_CONTINUE = 294,
    TK_DO = 295,
    TK_DEFAULT = 296,
    TK_ABRE = 297,
    TK_FECHA = 298,
    TK_FUNC = 299,
    TK_RETORNA = 300,
    TK_RETURN = 301,
    TK_READ = 302,
    TK_WRITE = 303,
    TK_SUPER = 304,
    TK_MAIN = 305,
    TK_ID = 306,
    TK_FIM = 307,
    TK_ERROR = 308,
    TK_END_E = 309,
    TK_FIMLINHA = 310,
    TK_DIVISAO = 311
  };
#endif
/* Tokens.  */
#define TK_MAIS 258
#define TK_MENOS 259
#define TK_MULT 260
#define TK_RAZAO 261
#define TK_POTENCIA 262
#define TK_CONCAT 263
#define TK_AND 264
#define TK_OR 265
#define TK_MAIOR 266
#define TK_MENOR 267
#define TK_DIFERENTE 268
#define TK_IGUAL 269
#define TK_MENOR_IGUAL 270
#define TK_MAIOR_IGUAL 271
#define TK_ATRIBUICAO 272
#define TK_VAR 273
#define TK_GLOBAL 274
#define TK_TIPO_STRING 275
#define TK_TIPO_FLOAT 276
#define TK_TIPO_CHAR 277
#define TK_TIPO_BOOL 278
#define TK_TIPO_INT 279
#define TK_INT 280
#define TK_FLOAT 281
#define TK_CHAR 282
#define TK_BOOL 283
#define TK_STRING 284
#define TK_VOID 285
#define TK_WHILE 286
#define TK_FOR 287
#define TK_SWITCH 288
#define TK_CASE 289
#define TK_IF 290
#define TK_ELSE 291
#define TK_ELIF 292
#define TK_BREAK 293
#define TK_CONTINUE 294
#define TK_DO 295
#define TK_DEFAULT 296
#define TK_ABRE 297
#define TK_FECHA 298
#define TK_FUNC 299
#define TK_RETORNA 300
#define TK_RETURN 301
#define TK_READ 302
#define TK_WRITE 303
#define TK_SUPER 304
#define TK_MAIN 305
#define TK_ID 306
#define TK_FIM 307
#define TK_ERROR 308
#define TK_END_E 309
#define TK_FIMLINHA 310
#define TK_DIVISAO 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 386 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,    58,     2,     2,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    59,
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   202,   207,   212,   217,   221,   228,   233,
     237,   243,   247,   252,   255,   258,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   283,
     287,   288,   289,   290,   294,   299,   300,   305,   323,   328,
     331,   335,   336,   342,   347,   348,   351,   353,   357,   360,
     360,   368,   368,   370,   370,   370,   370,   372,   373,   374,
     375,   377,   378,   383,   402,   425,   426,   429,   434,   443,
     462,   463,   464,   465,   466,   470,   476,   482,   488,   495,
     503,   515,   521,   530,   536,   566,   574,   580,   593,   599,
     602,   613,   619,   630,   641,   649,   656,   659,   674,   689,
     699,   713,   726,   738,   753,   769,   782,   796,   809,   823,
     835,   847,   861,   871,   879,   885,   900,   931,   946,   954,
     978
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIS", "TK_MENOS", "TK_MULT",
  "TK_RAZAO", "TK_POTENCIA", "TK_CONCAT", "TK_AND", "TK_OR", "TK_MAIOR",
  "TK_MENOR", "TK_DIFERENTE", "TK_IGUAL", "TK_MENOR_IGUAL",
  "TK_MAIOR_IGUAL", "TK_ATRIBUICAO", "TK_VAR", "TK_GLOBAL",
  "TK_TIPO_STRING", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_TIPO_INT", "TK_INT", "TK_FLOAT", "TK_CHAR", "TK_BOOL", "TK_STRING",
  "TK_VOID", "TK_WHILE", "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_IF",
  "TK_ELSE", "TK_ELIF", "TK_BREAK", "TK_CONTINUE", "TK_DO", "TK_DEFAULT",
  "TK_ABRE", "TK_FECHA", "TK_FUNC", "TK_RETORNA", "TK_RETURN", "TK_READ",
  "TK_WRITE", "TK_SUPER", "TK_MAIN", "TK_ID", "TK_FIM", "TK_ERROR",
  "TK_END_E", "TK_FIMLINHA", "TK_DIVISAO", "'('", "')'", "';'", "','",
  "':'", "$accept", "S", "BLOCO", "BLOCO_IF", "BLOCO_SE", "COMANDOS",
  "INI_ESCOPO_IF", "INI_ESCOPO", "FIM_ESCOPO", "COMANDO", "BLOCO_",
  "OPERACAO", "ARITMETICO", "ARITMETICO2", "ARITs", "RELACIONAL", "RELs",
  "LOGICO", "LOGs", "OP_LOGICO", "OP_RELACIONAL", "OP_ARITMETICO",
  "OP_ARITMETICO2", "DECLARA", "ATRIBUICAO", "INCREMENTAL",
  "DECLARA_E_ATRIBUI", "TIPO", "NUMEROS", "IDs", "OPs", "CONDICIONAL",
  "IF", "ELSEs", "ELSE", "SWITCHCASE", "SWITCH", "CASEs", "CASE",
  "DEFAULT", "BREAK", "CONTINUE", "LOOP", "CMD_CIN", "CMD_COUT", "FUNCAO",
  "ASSINATURA", "ASSINATURA_VOID", "PARAMs", "EXECUTA_FUNCAO", "RETORNO",
  "RETORNOS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    40,    41,    59,
      44,    58
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    68,    42,    11,  -178,    29,    90,  -178,  -178,   222,
     177,   116,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,    86,    83,    91,  -178,  -178,    90,    92,    99,
      45,   100,  -178,   104,   108,   131,   122,   262,  -178,   107,
      30,  -178,     7,   194,   147,    37,    46,   117,   118,  -178,
    -178,   124,   136,  -178,  -178,   125,   151,   153,  -178,   154,
     164,  -178,   152,    90,   -29,   171,   177,   167,   145,   100,
     195,   174,   100,   226,   227,   100,    84,   175,    36,   178,
       8,   179,  -178,  -178,  -178,   176,    28,   199,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,   158,  -178,  -178,   163,  -178,
    -178,  -178,  -178,   145,  -178,  -178,   100,  -178,  -178,     2,
       9,  -178,  -178,  -178,  -178,  -178,  -178,   302,  -178,   240,
     207,   201,   145,    18,   208,   209,   206,   210,   213,  -178,
    -178,  -178,  -178,  -178,   -22,  -178,  -178,  -178,  -178,   145,
     230,   239,  -178,    28,   254,   158,    18,  -178,   158,  -178,
       7,  -178,   147,   205,  -178,    46,   241,   100,   247,   269,
     100,   260,   264,   261,   294,  -178,   256,    90,  -178,   145,
    -178,  -178,  -178,   100,   257,  -178,  -178,   382,   145,  -178,
     135,   253,   265,    36,    49,  -178,   177,   258,  -178,   100,
      32,   269,  -178,    71,   274,  -178,  -178,   289,  -178,   279,
    -178,   230,   222,  -178,   280,   145,  -178,  -178,  -178,  -178,
     288,    35,   282,   284,  -178,   303,  -178,  -178,   100,  -178,
    -178,   292,  -178,   304,   309,   230,   295,  -178,  -178,   177,
      90,    90,  -178,  -178,  -178,  -178,  -178,  -178,   254,  -178,
    -178,  -178,   297,   422,   462,  -178,  -178,   313,   342,   314,
    -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    14,     2,    13,
       0,     0,    70,    71,    72,    73,    74,    75,    77,    76,
      80,    79,     0,     0,     0,    99,   100,     0,     0,     0,
      78,     0,    29,     0,     0,     0,     0,    12,    28,     0,
      45,    35,     0,    32,     0,    31,     0,     0,     0,    66,
      65,     0,    40,    20,    27,     0,     0,     0,    21,     0,
       0,    26,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    45,    35,
      46,    49,    40,    37,     3,     0,    86,     0,     4,    11,
      16,    57,    58,    60,    59,     0,    62,    61,     0,    56,
      55,    53,    54,     0,    51,    52,     0,    18,    19,    82,
       0,    17,    14,    25,    24,    23,    22,    13,   110,     0,
       0,     0,     0,    45,    46,     0,     0,     0,     0,    68,
      67,    64,   117,    84,     0,    36,    39,    44,    48,     0,
      13,     0,    85,    89,     0,     0,    34,    78,     0,    41,
      38,    46,    43,    50,    49,    47,    14,     0,     0,     0,
       0,     0,     0,     0,     0,   113,    46,     0,    94,     0,
     106,   107,   116,     0,    46,    13,    91,    13,     0,    88,
       0,     0,     0,     0,     0,    14,     0,    69,    81,     0,
       0,    96,   120,     0,     0,   108,   104,     0,   101,    46,
      83,    13,    13,     7,    46,     0,    82,    42,   112,   115,
       0,     0,     0,     0,    92,     0,    95,   118,     0,   109,
     105,     0,    87,     0,     0,    13,    46,    63,   111,     0,
       0,     0,    93,   119,   103,     5,     6,    90,     0,   114,
      97,    98,     0,    13,    14,   102,    10,     0,    13,     0,
       8,     9
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,    -3,  -174,  -178,   -33,  -125,    -6,  -177,  -166,
    -178,   -56,   -25,   -26,   278,   -23,   255,   -21,   271,  -178,
    -178,  -178,  -178,  -172,  -135,  -178,  -178,    -8,    -9,  -178,
     221,  -178,  -178,   236,  -178,  -178,  -178,   192,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   -24,
     225,  -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    32,   176,   245,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   106,
     103,    95,    98,    47,    48,    49,    50,    51,    82,   110,
     134,    53,    86,   142,   143,    54,    55,   190,   191,   215,
      56,    57,    58,    59,    60,    61,    62,    63,   211,    64,
     162,   193
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,     9,    65,     8,    89,    79,    78,    83,    80,   181,
      81,   203,    96,   125,   209,   177,   128,   -50,   -50,   131,
     133,    91,    92,    93,    70,   224,   157,   222,    52,   -33,
     -33,   -33,   -33,    91,    92,    93,   172,     1,   173,    91,
      92,    93,     4,   123,    83,   124,   -49,   -49,    73,    74,
     202,   237,    91,    92,    93,   104,   105,   239,   120,   156,
     118,   -63,    75,    97,   140,   141,   137,   249,     5,   158,
     146,    83,   149,   213,    94,   214,   177,   246,   123,    83,
     151,   123,    83,   153,   161,   154,    94,     6,   -30,   -30,
     -30,   -30,    94,   228,   135,   229,    79,    78,    83,   166,
     177,   133,    76,   242,   192,    94,   159,   207,    52,    17,
      18,    19,    20,    21,   123,    83,   174,   200,     3,    79,
     183,    83,    79,   184,    83,    17,    18,    19,    20,    21,
     217,   218,     7,   212,    66,    77,   182,    67,    73,    74,
      68,    31,   132,    85,   123,    83,   199,    84,    69,    71,
     186,    77,    75,   123,    83,   204,    72,    31,    99,   100,
     101,   102,   233,    87,   198,    88,    90,   112,    52,   223,
      17,    18,    19,    20,    21,   109,   107,   108,   210,   208,
     123,    83,   226,    17,    18,    19,    20,    21,    17,    18,
      19,    20,    21,    52,   117,   111,    77,    12,    13,    14,
      15,    16,   122,   -50,   -50,   -46,   -46,   -46,   -46,    77,
     113,   247,   114,   115,   147,   145,   -46,   -46,   -46,   -46,
     148,   210,   119,   116,   121,   127,   126,   240,   241,   129,
     182,   130,    76,   139,    52,    52,   136,   138,   248,    52,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -14,    24,   144,   163,   164,   165,
      25,    26,    27,   169,     7,   -15,   167,   168,   170,    28,
      29,   171,   175,    30,    12,    13,    14,    15,    16,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -14,    24,   178,   -13,   188,   185,
      25,    26,    27,   189,     7,   180,   160,   195,   196,    28,
      29,   197,   205,    30,   137,   201,   206,   219,   173,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -14,    24,   220,   221,   225,   227,
      25,    26,    27,   230,     7,   231,   232,   235,   160,    28,
      29,   234,   236,    30,   238,   243,   250,   251,   152,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    87,    24,   150,   155,   187,   179,
      25,    26,    27,   216,     7,   -15,   194,     0,     0,    28,
      29,     0,     0,    30,     0,     0,     0,     0,     0,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -14,    24,     0,     0,     0,     0,
      25,    26,    27,     0,     7,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,     0,     0,     0,     0,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -14,    24,     0,     0,     0,     0,
      25,    26,    27,     0,   244,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,     0,     0,     0,     0,    31,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,     0,   -13,     0,     0,
      25,    26,    27,     0,     7,     0,     0,     0,     0,    28,
      29,     0,     0,    30,     0,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
       9,     7,    10,     6,    37,    31,    31,    31,    31,   144,
      31,   177,     5,    69,   186,   140,    72,     9,    10,    75,
      76,     3,     4,     5,    27,   202,    17,   201,    37,    58,
      59,    60,    61,     3,     4,     5,    58,    24,    60,     3,
       4,     5,     0,    68,    68,    68,     9,    10,     3,     4,
     175,   225,     3,     4,     5,     9,    10,   229,    66,    57,
      63,    59,    17,    56,    36,    37,    58,   244,    57,    60,
      95,    95,    98,    41,    56,    43,   201,   243,   103,   103,
     103,   106,   106,   106,   117,   106,    56,    58,    58,    59,
      60,    61,    56,    58,    58,    60,   122,   122,   122,   122,
     225,   157,    57,   238,   160,    56,   112,    58,   117,    25,
      26,    27,    28,    29,   139,   139,   139,   173,    50,   145,
     145,   145,   148,   148,   148,    25,    26,    27,    28,    29,
      59,    60,    42,   189,    18,    51,   144,    51,     3,     4,
      57,    57,    58,    35,   169,   169,   169,    43,    57,    57,
     156,    51,    17,   178,   178,   178,    57,    57,    11,    12,
      13,    14,   218,    32,   167,    43,    59,    42,   177,   202,
      25,    26,    27,    28,    29,    51,    59,    59,   186,   185,
     205,   205,   205,    25,    26,    27,    28,    29,    25,    26,
      27,    28,    29,   202,    42,    59,    51,    20,    21,    22,
      23,    24,    57,     9,    10,    11,    12,    13,    14,    51,
      59,   244,    59,    59,    51,    57,    11,    12,    13,    14,
      57,   229,    51,    59,    57,    51,    31,   230,   231,     3,
     238,     4,    57,    57,   243,   244,    58,    58,   244,   248,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    57,    17,    51,    58,
      38,    39,    40,    57,    42,    43,    58,    58,    58,    47,
      48,    58,    42,    51,    20,    21,    22,    23,    24,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    57,    35,    51,    58,
      38,    39,    40,    34,    42,    51,    46,    43,    47,    47,
      48,    17,    59,    51,    58,    58,    51,    43,    60,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    47,    58,    58,    51,
      38,    39,    40,    61,    42,    61,    43,    43,    46,    47,
      48,    59,    43,    51,    59,    58,    43,    43,   103,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    98,   106,   157,   143,
      38,    39,    40,   191,    42,    43,   161,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    35,    -1,    -1,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    63,    50,     0,    57,    58,    42,    64,    69,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    33,    38,    39,    40,    47,    48,
      51,    57,    64,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    85,    86,    87,
      88,    89,    90,    93,    97,    98,   102,   103,   104,   105,
     106,   107,   108,   109,   111,    89,    18,    51,    57,    57,
      64,    57,    57,     3,     4,    17,    57,    51,    74,    75,
      77,    79,    90,   111,    43,    35,    94,    32,    43,    67,
      59,     3,     4,     5,    56,    83,     5,    56,    84,    11,
      12,    13,    14,    82,     9,    10,    81,    59,    59,    51,
      91,    59,    42,    59,    59,    59,    59,    42,    64,    51,
      89,    57,    57,    74,    77,    73,    31,    51,    73,     3,
       4,    73,    58,    73,    92,    58,    58,    58,    58,    57,
      36,    37,    95,    96,    57,    57,    74,    51,    57,    75,
      76,    77,    78,    77,    79,    80,    57,    17,    60,    69,
      46,    67,   112,    17,    51,    58,    77,    58,    58,    57,
      58,    58,    58,    60,    77,    42,    65,    68,    57,    95,
      51,    86,    89,    74,    74,    58,    69,    92,    51,    34,
      99,   100,    73,   113,   112,    43,    47,    17,    64,    77,
      73,    58,    68,    71,    77,    59,    51,    58,    69,    85,
      89,   110,    73,    41,    43,   101,    99,    59,    60,    43,
      47,    58,    65,    67,    70,    58,    77,    51,    58,    60,
      61,    61,    43,    73,    59,    43,    43,    65,    59,    85,
      64,    64,    86,    58,    42,    66,    71,    67,    69,    70,
      43,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    67,    67,    68,    69,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      73,    73,    73,    73,    74,    74,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    85,    86,    86,    86,    87,    87,    88,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    95,    95,
      96,    96,    97,    97,    98,    99,    99,   100,   101,   102,
     103,   104,   104,   104,   105,   105,   105,   106,   107,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   113,
     113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     4,     2,     3,     3,
       1,     2,     1,     0,     0,     0,     2,     2,     2,     2,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     2,     5,     2,     1,
       5,     2,     5,     6,     4,     2,     1,     4,     3,     1,
       1,     5,    10,     7,     5,     6,     4,     4,     4,     5,
       2,     6,     5,     4,     3,     1,     4,     3,     3,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 192 "sintatica.y" /* yacc.c:1646  */
    {
                cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\n\n";
                printFuncDeclarations();
                printVarDeclarations();
                cout << "\nint main(void)\n{\n";
                cout <<"\n\n"<< (yyvsp[-4]).traducao << "\treturn 0;\n}" << endl; 
                printFuncoes();
            }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 203 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 208 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 213 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 218 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 222 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 229 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;

            }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 234 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
            }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 238 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 244 "sintatica.y" /* yacc.c:1646  */
    { 
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;        
            }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 248 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 252 "sintatica.y" /* yacc.c:1646  */
    { 
                iniEscopoIf();
            }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 255 "sintatica.y" /* yacc.c:1646  */
    { 
                iniEscopo();
            }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 258 "sintatica.y" /* yacc.c:1646  */
    { 
                fimEscopo();
            }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 283 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                fimEscopo();
            }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 295 "sintatica.y" /* yacc.c:1646  */
    { 
             
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipo(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
            }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 300 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 305 "sintatica.y" /* yacc.c:1646  */
    {

                Funcao *f = getFunc((yyvsp[0]).label);
                string aux;
                if(f->tipo != "void"){
                    string temp = geraVar(f->tipo);
                    aux = verificaTipoAtribuicao(temp, "=", f->retornos[0]->nomeTemp);
                    (yyval).label = temp;
                    (yyval).tipo = f->tipo;
                    
                }else{
                    yyerror("Operação com função tipo void '"+(yyvsp[0]).label+"'");
                }
                //$$.colLabels.push_back($$.label);
                (yyval).traducao = (yyvsp[0]).traducao + "\n" +aux;
            }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 324 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipo(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
                
            }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 328 "sintatica.y" /* yacc.c:1646  */
    { 
                
                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 336 "sintatica.y" /* yacc.c:1646  */
    {
            
                (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label;}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 343 "sintatica.y" /* yacc.c:1646  */
    {    
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipoRelacional(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
            
            }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 347 "sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo; }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 354 "sintatica.y" /* yacc.c:1646  */
    { 
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + verificaTipoLogico(&(yyval), &(yyvsp[-2]), (yyvsp[-1]).traducao, &(yyvsp[0]));
            }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 357 "sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = (yyvsp[-1]).traducao; (yyval).label = (yyvsp[-1]).label; (yyval).tipo = (yyvsp[-1]).tipo;  }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 384 "sintatica.y" /* yacc.c:1646  */
    {
                addNewVarToTable((yyvsp[0]).traducao, (yyvsp[0]).tipo);


                VarNode *var = getVar((yyvsp[0]).traducao);

                (yyval).traducao = "";
                (yyval).label = var->nomeTemp;

                
            }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 402 "sintatica.y" /* yacc.c:1646  */
    {
            string aux = "";
                //$$.traducao = $3.traducao + "\t"+ $1.label + " "+ $2.label + " " +$3.label + "\n";


                if((yyvsp[0]).label != ""){
                    if((yyvsp[0]).colLabels.size() > 0){
                        (yyval).traducao = (yyvsp[0]).traducao + verificaTipoAtribuicao_func(getVar((yyvsp[-2]).traducao)->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).colLabels[0], (yyvsp[0]).label);
                    }else{
                        aux = verificaTipoAtribuicao(getVar((yyvsp[-2]).traducao)->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).label);
                        
                        (yyval).traducao = (yyvsp[0]).traducao + aux;
                    }

                }
                else{
                    aux = verificaTipoAtribuicao(getVar((yyvsp[-2]).traducao)->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).traducao);
                    
                    (yyval).traducao = (yyvsp[0]).traducao + aux;
                    (yyval).traducao = "\t"+getVar((yyvsp[-2]).traducao)->nomeTemp +" "+(yyvsp[-1]).traducao+" "+getVar((yyvsp[0]).traducao)->nomeTemp+";\n";
                }

            }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 429 "sintatica.y" /* yacc.c:1646  */
    {
                VarNode *var = getVar((yyvsp[-2]).traducao); 

                (yyval).traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + (yyvsp[-1]).traducao +" 1;\n";
            }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 434 "sintatica.y" /* yacc.c:1646  */
    {
                VarNode *var = getVar((yyvsp[-2]).traducao); 

                (yyval).traducao = "\t" + var->nomeTemp + " = " + var->nomeTemp + " " + (yyvsp[-1]).traducao +" 1;\n";
            }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 444 "sintatica.y" /* yacc.c:1646  */
    {
                string aux = "";

                for (int i = 0; (i < (yyvsp[-2]).colLabels.size()) && (i < (yyvsp[0]).colLabels.size()); i++){

                    addNewVarToTable((yyvsp[-2]).colLabels[i], (yyvsp[-2]).tipo);
                    //não será necessário essa parte assim que a partede scopo for criada, 'geraVar' irá inseri a declaração para ser impressa no escopo  qual pertence
                    //aux += "\t"+getVar($2.colLabels[i])->tipo+" "+getVar($2.colLabels[i])->nomeTemp +";\n"; // DECLARA 
                    cout<<"\n//DeA:"<<(yyvsp[-2]).colLabels[i]<<":"<<(yyvsp[0]).colLabels[i]<<":"<<(yyvsp[-1]).label<<":"<<"\n";
                    aux += verificaTipoAtribuicao(getVar((yyvsp[-2]).colLabels[i])->nomeTemp, (yyvsp[-1]).traducao, (yyvsp[0]).colLabels[i]);

                }

                (yyval).traducao = (yyvsp[0]).traducao  + aux;
            }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 471 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
            }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 477 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
            }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 483 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
            }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 489 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = getVar((yyvsp[0]).traducao)->nomeTemp; //verfica se mome da variavel já foi declarado e retorna nome temporário
                (yyval).tipo = getVar((yyvsp[0]).traducao)->tipo; //verfica se mome da variavel já foi declarado e retorna tipo
                (yyval).traducao = "";

            }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 496 "sintatica.y" /* yacc.c:1646  */
    {
                //$1.tamString = $$.traducao.length()-1; //Pega o tamanho da string menos 1;
                (yyval).label = geraVarString(&(yyvsp[0]));
                //std::cout << "Teste: " << $1.traducao << $$.label << std::endl;
                (yyval).traducao = "\tstrcpy (" + (yyval).label + "," + (yyvsp[0]).traducao + ");\n";
                
            }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 504 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = geraVar((yyvsp[0]).tipo);
                //$$.traducao = "\t" + $1.tipo +" "+ $$.label +" = " + $1.traducao + ";\n";    
                (yyval).traducao = "\t" + (yyval).label +" = " + (yyvsp[0]).traducao + ";\n";    
                        
            }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 516 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).colLabels = (yyvsp[-2]).colLabels;

                (yyval).colLabels.push_back((yyvsp[0]).traducao);
            }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 522 "sintatica.y" /* yacc.c:1646  */
    { 


                vector<string> e;
                (yyval).colLabels = e;
                (yyval).colLabels.push_back((yyvsp[0]).traducao); 
            }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 531 "sintatica.y" /* yacc.c:1646  */
    {   
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
                (yyval).colLabels = (yyvsp[-2]).colLabels;
                (yyval).colLabels.push_back((yyvsp[0]).label);
            }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 537 "sintatica.y" /* yacc.c:1646  */
    {   

                vector<string> e;
                (yyval).colLabels = e;

                   for (int i = 0; i < (yyvsp[0]).colLabels.size(); i++)
                        {
                            cout<<"\t//::"<<(yyvsp[0]).colLabels[i]<<"\n";
                        }

                //if ($1.label != "")
                if ((yyvsp[0]).colLabels.size() == 0)
                    (yyval).colLabels.push_back((yyval).label);
                else{
                    if((yyvsp[0]).colLabels.size() > 0){
                        for (int i = 0; i < (yyvsp[0]).colLabels.size(); i++)
                        {
                            (yyval).colLabels.push_back((yyvsp[0]).colLabels[i]);
                        }
                    }
                    else
                        yyerror("ERRO");
                }
            }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 566 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao;
                (yyval).traducao += "\tgoto " + EscopoAtual->labelFim+";\n"; 
                (yyval).traducao += (yyvsp[-1]).label +":\n";
                (yyval).traducao += (yyvsp[0]).traducao + "\n" + EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 574 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao + (yyvsp[0]).label + ":\n//fim_if\n\n";
                fimEscopo();

            }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 580 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label  = EscopoAtual->labelFim;

                (yyval).traducao = "\n//ini_if\n" + (yyvsp[-2]).traducao;
                (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
                (yyval).traducao += "\n" + (yyvsp[0]).traducao +"\n";
                /*$$.traducao += "\tgoto " + EscopoAtual->escopoPai->labelFim+":\n"; 
                $$.traducao += EscopoAtual->labelFim +":\n\n";*/

                fimEscopo();
            }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 594 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;

            }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 602 "sintatica.y" /* yacc.c:1646  */
    {

                
                (yyval).traducao = "\n//ini_elif\n" +(yyvsp[-2]).traducao;
                (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
                (yyval).traducao += "\n" + (yyvsp[0]).traducao ;
                (yyval).traducao += "\ngoto " + EscopoAtual->escopoPai->labelFim +";\n"; 
                (yyval).traducao += "\n" + EscopoAtual->labelFim+":";
                fimEscopo();

            }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 613 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = "\n//ini_else\n" +(yyvsp[0]).traducao ;
                fimEscopo();
            }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 620 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-1]).label;
                (yyval).traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                (yyval).traducao += (yyvsp[-1]).traducao;
                (yyval).traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();


            }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 631 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = (yyvsp[-5]).traducao + (yyvsp[-2]).label + (yyvsp[-1]).label;
                (yyval).traducao += "\ngoto "+EscopoAtual->labelFim +";\n\n";
                (yyval).traducao += (yyvsp[-2]).traducao + (yyvsp[-1]).traducao;
                (yyval).traducao += "//fim_switch_case\n"+ EscopoAtual->labelFim +":\n\n";
                fimEscopo();

            }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 642 "sintatica.y" /* yacc.c:1646  */
    {
                switch_var = (yyvsp[-1]).label;
                (yyval).traducao = (yyvsp[-1]).traducao;


            }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 650 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;

            }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 660 "sintatica.y" /* yacc.c:1646  */
    {
                pair<string, string> rtn = verificaTipoRelacional(switch_var, "==", (yyvsp[-2]).label);
                (yyval).label = "\n//ini_case\n";
                (yyval).label += (yyvsp[-2]).traducao;
                (yyval).label += rtn.second;
                (yyval).label += "\n\tif ("+ rtn.first +") goto " + EscopoAtual->labelInicio +";\n"; 
                (yyval).traducao = EscopoAtual->labelInicio+ ":\n";
                (yyval).traducao += (yyvsp[0]).traducao ;
                (yyval).traducao += "//fim_case\n\n";
               // $$.traducao += EscopoAtual->labelFim+":\n\n";
                fimEscopo();


            }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 675 "sintatica.y" /* yacc.c:1646  */
    {
                pair<string, string> label = geraLabelEscopo();

                (yyval).label = "\n//ini_defalut";
                (yyval).label += "\n\tgoto " + EscopoAtual->labelInicio +";\n"; 
                (yyval).traducao = EscopoAtual->labelInicio + ":\n";
                (yyval).traducao += (yyvsp[0]).traducao ;
                (yyval).traducao += "//fim_default\n\n";

                fimEscopo();


            }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 689 "sintatica.y" /* yacc.c:1646  */
    {

                Escopo *e = EscopoAtual->escopoPai;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                (yyval).traducao = "\tgoto "+e->labelFim + ";//break\n";

            }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 699 "sintatica.y" /* yacc.c:1646  */
    {

                Escopo *e = EscopoAtual;
                while(e->escopoPai != 0 && e->isCondicional){
                    e = e->escopoPai;
                }
                (yyval).traducao = "\tgoto "+e->labelInicio + ";//continue\n";

            }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 713 "sintatica.y" /* yacc.c:1646  */
    {

            pair<string, string> label = geraLabelEscopo();

            (yyval).traducao = "//ini_while\n"+ EscopoAtual->labelInicio + ":\n";    
            (yyval).traducao += (yyvsp[-2]).traducao;
            (yyval).traducao += "\n\tif (!("+ (yyvsp[-2]).label +")) goto " + EscopoAtual->labelFim +";"; 
            (yyval).traducao += "\n" + (yyvsp[0]).traducao ;
            (yyval).traducao += "\n\tgoto " + EscopoAtual->labelInicio +";\n";
            (yyval).traducao += "\n" + EscopoAtual->labelFim +":\n//fim_while\n\n";
            fimEscopo();

        }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 726 "sintatica.y" /* yacc.c:1646  */
    {
            
            (yyval).traducao = "//ini_for\n"+(yyvsp[-6]).traducao;
            (yyval).traducao += "\n"+ EscopoAtual->labelInicio + "_l:\n"; 
            (yyval).traducao += (yyvsp[-4]).traducao ;
            (yyval).traducao += "\n\tif (!("+ (yyvsp[-4]).label +")) goto " + EscopoAtual->labelFim +";"; 
            (yyval).traducao += "\n" + (yyvsp[0]).traducao +"\n";
            (yyval).traducao +=  EscopoAtual->labelInicio +":\n"+ (yyvsp[-2]).traducao;
            (yyval).traducao += "\n\tgoto " + EscopoAtual->labelInicio +"_l;\n" + EscopoAtual->labelFim +":\n//fim_for\n\n";

            fimEscopo();
        }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 738 "sintatica.y" /* yacc.c:1646  */
    {

            (yyval).traducao = "\n//ini_do_while\n"+ EscopoAtual->labelInicio + ":\n"; 
            (yyval).traducao += (yyvsp[-5]).traducao;

            (yyval).traducao += (yyvsp[-2]).traducao ;
            (yyval).traducao += "\n\tif ("+ (yyvsp[-2]).label +") goto " + EscopoAtual->labelInicio +";\n";
            (yyval).traducao += EscopoAtual->labelFim+": //fim_do_while\n\n"; 

            fimEscopo();
            //$$.traducao += "\n goto " + label.first +";\n\n" + label.second +":\n";
        }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 754 "sintatica.y" /* yacc.c:1646  */
    {


                // if($2.tipoReal == "string"){
                //  nova_var_string($3.label, 0);
            //      resetaString($3.label, 1024);
            //      variavel var = use_var($3.label, $3.tipo);
                //  $$.traducao = "\t cin >> " + var.temp_name + " ;\n";
                // }
                // else
                // {
            //      $$.label = nova_var($3.label, $2.tipo);
                //  $$.traducao = "\t cin >> " + $$.label + " ;\n";
                // }
            }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 770 "sintatica.y" /* yacc.c:1646  */
    {
                // if($3.tipoReal == "string"){
                //  nova_var_string($4.label, 0);
            //      resetaString($4.label, 1024);
            //      variavel var = use_var($4.label, $4.tipo);
                //  $$.traducao = "\tcin >> " + var.temp_name + " ;\n"; 
                // }else
                // {
            //      $$.label = nova_var($4.label, $3.tipo);
                //  $$.traducao = "\tcin >> " + $$.label + " ;\n";
                // }
            }
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 783 "sintatica.y" /* yacc.c:1646  */
    {
                // if($3.tipoReal == "string"){
            //      resetaString($3.label, 1024);
            //      variavel var = use_var($3.label, $3.tipo);
                //  $$.traducao = "\t cin << " + var.temp_name + " ;\n";    
                // }
                // else{
                //  $$.traducao = "\t cin << " + $3.label + " ;\n"; 
                // }
            }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 797 "sintatica.y" /* yacc.c:1646  */
    {   
                (yyval).traducao = (yyvsp[-1]).traducao;
                (yyval).traducao += "\tcout << " + (yyvsp[-1]).label + " <<\"\\n\";\n";
            }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 810 "sintatica.y" /* yacc.c:1646  */
    {
                Funcao *func = getFunc((yyvsp[-3]).label);
                func->traducao = (yyvsp[-1]).traducao;
                //func->retornos = getVarByNameTemp($2.colLabels[i]);

                for (int i = 0; i < (yyvsp[-1]).colLabels.size(); ++i){
                    func->retornos.push_back(getLabel((yyvsp[-1]).colLabels[i]));
                }


                (yyval).traducao = "";
                fimEscopo();
            }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 823 "sintatica.y" /* yacc.c:1646  */
    {
                Funcao *func = getFunc((yyvsp[-4]).label);
                func->traducao = (yyvsp[-2]).traducao + (yyvsp[-1]).traducao;
                //func->retornos = getVarByNameTemp($2.colLabels[i]);

                for (int i = 0; i < (yyvsp[-1]).colLabels.size(); ++i){
                    func->retornos.push_back(getLabel((yyvsp[-1]).colLabels[i]));
                }

                (yyval).traducao = "";
                fimEscopo();
            }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 836 "sintatica.y" /* yacc.c:1646  */
    {

                Funcao *func = getFunc((yyvsp[-1]).label);
                func->traducao = (yyvsp[0]).traducao;

                (yyval).traducao = "";
                fimEscopo();
            }
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 848 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-4]).traducao;
                vector<VarNode*> v;

                for (int i = 0; i < (yyvsp[-1]).colLabels.size(); ++i){
                    v.push_back(getLabel((yyvsp[-1]).colLabels[i]));
                }
                Escopo *e = EscopoAtual;
                EscopoAtual = EscopoAtual->escopoPai;
                addNewFuncToTable((yyvsp[-4]).traducao, (yyvsp[-4]).tipo, v);
                EscopoAtual = e;

            }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 862 "sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-3]).traducao;
                vector<VarNode*> v;

                Escopo *e = EscopoAtual;
                EscopoAtual = EscopoAtual->escopoPai;
                addNewFuncToTable((yyvsp[-3]).traducao, (yyvsp[-3]).tipo, v);
                EscopoAtual = e;
            }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 872 "sintatica.y" /* yacc.c:1646  */
    {
                    (yyval).label = (yyvsp[-2]).traducao;
                    vector<VarNode*> vazio;
                    addNewFuncToTable((yyvsp[-2]).traducao, (yyvsp[-2]).tipo, vazio);

                }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 880 "sintatica.y" /* yacc.c:1646  */
    {
                (yyvsp[-2]).colLabels.push_back((yyvsp[0]).label);
                (yyval).colLabels = (yyvsp[-2]).colLabels;

            }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 886 "sintatica.y" /* yacc.c:1646  */
    {
                vector<string> v;
                (yyval).colLabels = v;
                (yyval).colLabels.push_back((yyvsp[0]).label);
            }
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 901 "sintatica.y" /* yacc.c:1646  */
    {
                    Funcao *func = getFunc((yyvsp[-3]).traducao);
                    if(func->parametros.size() != (yyvsp[-1]).colLabels.size())
                        yyerror("Funcao '"+(yyvsp[-3]).traducao+"' espera quantidade de parametros diferentes");
                    
                    VarNode *a;
                    VarNode *b;

                    (yyval).traducao = (yyvsp[-1]).traducao;
                    for (int i = 0; i < (yyvsp[-1]).colLabels.size(); ++i){
                        a = getLabel((yyvsp[-1]).colLabels[i]);
                        b = func->parametros[i];

                       // verificaTipoAtribuicao(a->tipo, "=", b->tipo);
                        if(a->tipo != b->tipo){
                            yyerror("Parametro na posição "+to_string(i)+" da função '"+(yyvsp[-3]).traducao+"' é do tipo '"+b->tipo+"' foi passado: '"+a->tipo+"'");
                        }
                        (yyval).traducao += "\t" + func->parametros[i]->nomeTemp + " = " + (yyvsp[-1]).colLabels[i]+";\n";
                        /* code */
                    }


                    (yyval).traducao += "\t"+ func->nomeTemp+"();  //"+func->tkid+"\n\n";
                    for (int j = 0; j < func->retornos.size(); j++)
                    {
                        (yyval).colLabels.push_back(func->retornos[j]->nomeTemp);
                    }
                    (yyval).label = (yyvsp[-3]).traducao;
                    
                }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 932 "sintatica.y" /* yacc.c:1646  */
    {
                    Funcao *func = getFunc((yyvsp[-2]).traducao);

                    if(func->parametros.size() != 0)
                        yyerror("Funcao '"+(yyvsp[-2]).traducao+"'espera quantidade de parametros diferentes");
                    
                    (yyval).traducao = "\t"+ func->nomeTemp+"();  //"+func->tkid+"\n\n";
                    for (int j = 0; j < func->retornos.size(); j++)
                    {
                        (yyval).colLabels.push_back(func->retornos[j]->nomeTemp);
                    }
                    (yyval).label = (yyvsp[-2]).traducao;
                }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao  = (yyvsp[-1]).traducao;
                (yyval).colLabels = (yyvsp[-1]).colLabels;

            }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 955 "sintatica.y" /* yacc.c:1646  */
    {
                 for (int i = 0; i < (yyvsp[-2]).colLabels.size(); ++i)
                    {
                    }
                    for (int i = 0; i < (yyvsp[0]).colLabels.size(); ++i)
                    {
                    }
                (yyval).traducao = (yyvsp[-2]).traducao;
                (yyval).traducao += (yyvsp[0]).traducao;
                (yyval).colLabels = (yyvsp[-2]).colLabels;
                
                if((yyvsp[-2]).label== "" && (yyvsp[0]).colLabels.size() != 0)
                {
                    for (int i = 0; i < (yyvsp[-2]).colLabels.size(); ++i)
                    {
                        (yyval).colLabels.push_back((yyvsp[-2]).colLabels[i]);            
                    }
                }else if ((yyvsp[-2]).label != "")
                {
                    (yyval).colLabels.push_back((yyvsp[0]).label);
                }
            
            }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 979 "sintatica.y" /* yacc.c:1646  */
    {
        
                vector<string> vazio;
                (yyval).colLabels = vazio;
                
                
                (yyval).traducao = (yyvsp[0]).traducao;

                if((yyvsp[0]).label == "" || (yyvsp[0]).colLabels.size() > 0){   
                        for (int i = 0; i < (yyvsp[0]).colLabels.size(); ++i){
                            (yyval).colLabels.push_back((yyvsp[0]).colLabels[i]);            
                        }
                    
                }
                else{

                    (yyval).colLabels.push_back((yyvsp[0]).label);
                }
            }
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2666 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 999 "sintatica.y" /* yacc.c:1906  */



#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{   
   
     char var0_0[6]; 

    strcpy (var0_0,"teste");

    yyparse();
    //for (map<string,VarNode*>::iterator it=tkIdTable.begin(); it!=tkIdTable.end(); ++it)

    return 0;
}

void yyerror( string MSG )
{
    cout<<"ERROR:\n"<<MSG<<"\n";
    exit (1);
}   

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

string geraVar(string tipo){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, "");

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}
string geraFunc(string tipo){
    string var =("func" + to_string(nivel_escopo) +"_"+ to_string(funcCount++));

    Funcao *func = new Funcao(var, tipo, "");

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->funcTempTable[var] = func;

    return var; 
}
string geraVarString(atributos *a){
   // std::cout << a->tamString << std::endl;
    //strcpy(dest, src);
    int tamString;
    
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    tamString = a->traducao.length()-1; //Pega o tamanho da string menos 1;
    std::cout <<  tamString << std::endl;
    //string varTamVetor = var + "[" + to_string(a->tamString) + "]";

    VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;

    return var; 
}




string geraVar(string tipo, string tkid){
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++));

    VarNode *varnode = new VarNode(var, tipo, tkid);

    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->varTable[var] = varnode;
    EscopoAtual->tkIdTable[var] = varnode;

    return var; 
}
string geraFunc(string tipo, string tkid, vector<VarNode*> params){
    string var =("func" + to_string(nivel_escopo) +"_"+ to_string(funcCount++));

    Funcao *func = new Funcao(var, tipo, tkid);
    func->parametros = params;
    //INCLUI EM BLOCO do ESCOPO atual
    EscopoAtual->funcTable[var] = func;
    EscopoAtual->funcTempTable[var] = func;

    return var; 
}
pair<bool, VarNode*> getVarByNameTemp(string nomeTemp){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
    if(e->escopoPai == 0){
        if(e->varTable.find(nomeTemp)!=e->varTable.end()){
            rtn.first = true;
            rtn.second = e->varTable[nomeTemp];
            return rtn;
        }        
    }
    while(e->escopoPai != 0){

        if(e->varTable.find(nomeTemp)!=e->varTable.end()){
            rtn.first = true;
            rtn.second = e->varTable[nomeTemp];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
pair<bool, VarNode*> getVarFuncEscopoAtual(string nomeTemp){
    Escopo *e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
    
    for( MapFuncao::const_iterator it = e->funcTempTable.begin(); it != e->funcTempTable.end(); ++it ){
        cout <<"//void "<< it->second->nomeTemp << "()\n";
        for (int i = 0; i < it->second->retornos.size(); ++i){
            if(it->second->retornos[i]->nomeTemp == nomeTemp){
                rtn.first = true;
                rtn.second = it->second->retornos[i];
                return rtn;
            }
        }
    }
    rtn.first = false;

    return rtn;
}
pair<bool, Funcao*> getFuncByNameTemp(string nomeTemp){
    Escopo * e = EscopoAtual;
    
    pair<bool, Funcao*> rtn;
    
    while(e->escopoPai != 0){

        if(e->funcTempTable.find(nomeTemp)!=e->funcTempTable.end()){
            rtn.first = true;
            rtn.second = e->funcTempTable[nomeTemp];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
pair<bool, VarNode*> getVarByTkid(string tkid){
    Escopo * e = EscopoAtual;
    
    pair<bool, VarNode*> rtn;
    if(e->escopoPai == 0){
        if(e->tkIdTable.find(tkid)!=e->tkIdTable.end()){
            rtn.first = true;
            rtn.second = e->tkIdTable[tkid];
            return rtn;
        }        
    }
    while(e->escopoPai != 0){

        if(e->tkIdTable.find(tkid)!=e->tkIdTable.end()){
            rtn.first = true;
            rtn.second = e->tkIdTable[tkid];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;

    return rtn;
}
pair<bool, Funcao*> getFuncByTkid(string tkid){
    Escopo * e = EscopoAtual;
    pair<bool, Funcao*> rtn;
     if(e->escopoPai == 0){
        if(e->funcTable.find(tkid)!=e->funcTable.end()){
            rtn.first = true;
            rtn.second = e->funcTable[tkid];
            return rtn;
        }        
    }
    while(e->escopoPai != 0){
        if(e->funcTable.find(tkid)!=e->funcTable.end()){
            rtn.first = true;
            rtn.second = e->funcTable[tkid];
            return rtn;
        }
        e = e->escopoPai;
    }
    rtn.first = false;
    return rtn;
}
void addNewVarToTable(string nomeTemp, string tipo){
    if(EscopoAtual->tkIdTable.find(nomeTemp)==EscopoAtual->tkIdTable.end()){
        //verifica se variavel existe noescopo atual
        EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];

    }else{
        //verifica se a nova variavel está na tabela
        pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
        if(p.first){
            yyerror("error: redeclaração da variavel '"+tipo+" "+nomeTemp+ "'\n");
        }else{
            EscopoAtual->tkIdTable[nomeTemp] = EscopoAtual->varTable[geraVar(tipo, nomeTemp)];
        }
    }
}
void addNewFuncToTable(string nomeTemp, string tipo, vector<VarNode*> params){
 
    if(EscopoAtual->funcTable.find(nomeTemp)==EscopoAtual->funcTable.end()){

        //verifica se variavel existe noescopo atual
        EscopoAtual->funcTable[nomeTemp] = EscopoAtual->funcTempTable[geraFunc(tipo, nomeTemp, params)];
    }else{

        //verifica se a nova variavel está na tabela
        pair<bool, Funcao*> p = getFuncByTkid(nomeTemp);
        if(p.first){
            //ALTERAR PARA PERMITIR FUNÇÕES COM DIFERENTES PARAMETROS
            yyerror("error: redeclaração da função '"+tipo+" "+nomeTemp+ "'\n");
        }else{
            EscopoAtual->funcTable[nomeTemp] = EscopoAtual->funcTempTable[geraFunc(tipo, nomeTemp, params)];
        }
    }
}
//busca variavel por tkid
VarNode* getVar(string nomeTemp){
    pair<bool, VarNode*> p = getVarByTkid(nomeTemp);
    if(!p.first){
        
        yyerror("error: variavel não foi declarada '"+nomeTemp+ "'\n");
    }

    return p.second;
}
//busca variavel por label
VarNode* getLabel(string label){
    pair<bool, VarNode*> p = getVarByNameTemp(label);
    if(!p.first){
        p = getVarFuncEscopoAtual(label);
        if(!p.first)
            yyerror("error: variavel temporária inexistente '"+label+ "'\n");

    }

    return p.second;
  
}
Funcao* getFunc(string nomeTemp){
    pair<bool, Funcao*> p = getFuncByTkid(nomeTemp);
    if(!p.first){
        yyerror("error: funcao não foi declarada '"+nomeTemp+ "'\n");
    }

    return p.second;
}
//busca função por label
Funcao* getFuncLabel(string label){
    pair<bool, Funcao*> p = getFuncByNameTemp(label);
    if(!p.first){
        yyerror("error: funcao temporária inexistente '"+label+ "'\n");
    }

    return p.second;
  
}

string verificaTipo(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo);
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}

string verificaTipoRelacional(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = buscaTipoTabela(b->tipo, operador, c->tipo); 
    string var = "", rtn = "";
/*
    if(b->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ b->label +";\n";
        b->label = var;
    }

    if(c->tipo != tipo) {
        var = geraVar(tipo);
        rtn += "\t" +  var +" = ";
        rtn += "("+ tipo +") "+ c->label +";\n";
        c->label = var;
    }
*/
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}
pair<string, string> verificaTipoRelacional(string a, string operador, string b){
    string tipo = buscaTipoTabela(getLabel(a)->tipo, operador, getLabel(b)->tipo);

    string var = geraVar(tipo);
 
    pair<string, string> rtn;
    rtn.second = "\t" +  var +" = "+a+" "+operador + " "+b+";\n";
    rtn.first = var;
    return rtn ;

}


string verificaTipoLogico(atributos *a, atributos *b,string operador, atributos *c){
    string tipo = "bool"; //buscaTipoTabela(b->tipo, operador, c->tipo); 
  
    string var = "", rtn = "";
    
    var = geraVar(tipo);

    a->label = var;
    rtn += "\t" +  var +" = "+ b->label+" "+operador + " "+c->label+";\n";
    
    return rtn ;
}


string verificaTipoAtribuicao(string label1, string operador, string label2){
    VarNode *a = getLabel(label1);
    VarNode *b = getLabel(label2);
    string tipo = buscaTipoTabela(a->tipo, operador, b->tipo);
    //std::cout << "tipo: " <<tipo << std::endl;
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        //rtn += "\t" + tipo + " " + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + a->nomeTemp +" = " + var + ";\n";
    } 
    else{
         //rtn += "\t" + tipo + " " + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
         { 
             geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
             rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
         }
         else
         {
             rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         }
         

    }
    return rtn;
}
string verificaTipoAtribuicao_func(string label1, string operador, string label2, string labelFunc){
    VarNode *a = getLabel(label1);
    VarNode *b;

    std::size_t found = labelFunc.find("var");
    if (found!=std::string::npos){
        b = getLabel(labelFunc);
    }else{
        Funcao *f = getFunc(labelFunc);
        
        for (int i = 0; i < f->retornos.size(); ++i){
            if(f->retornos[i]->nomeTemp == label2){
                b = f->retornos[i];
                break;
            }
        }   
    }

    string tipo = buscaTipoTabela(a->tipo, operador, b->tipo);
    //std::cout << "tipo: " <<tipo << std::endl;
    string var = "", rtn = "";

    if(b->tipo != tipo) {
        var = geraVar(tipo);
        //rtn += "\t" + tipo + " " + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + var +" = " + "("+ tipo +") "+ b->nomeTemp +";\n";
        rtn += "\t" + a->nomeTemp +" = " + var + ";\n";
    } 
    else{
         //rtn += "\t" + tipo + " " + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         if(a->tipo == "string") //caso seja string é necessário utilizar o strcpy;
         { 
             geraVarSubrescritaString(a->nomeTemp, b->nomeTemp);
             rtn += "\tstrcpy (" + a->nomeTemp + "," + b->nomeTemp  + ");\n";
         }
         else
         {
             rtn += "\t" + a->nomeTemp +" = " + b->nomeTemp  + ";\n";
         }
         

    }
    return rtn;
}


string geraVarSubrescritaString(string varA, string varB){
    VarNode *a = getLabel(varA);
    VarNode *b = getLabel(varB);
 
    int tamString = b->tamString; //Pega o tamanho da string menos 1;
     
    //std::cout << b->tamString << std::endl;
    string var =("var" + to_string(nivel_escopo) +"_"+ to_string(varCount++) );
    string varTamVetor = var + "[" + to_string(tamString) + "]";
    a->tamString = tamString;
    
    //a->nomeTemp = var;

    //VarNode *varnode = new VarNode(var, "string", "", tamString);

    //INCLUI EM BLOCO do ESCOPO atual
    //EscopoAtual->labelTable[var] = varnode;

    return "sas"; 
}

//busca na tabela tipo resultante de uma operação
string buscaTipoTabela(string tipoA, string operador, string tipoB){
    if(TabelaTipos.empty()){
        criaTabelaTipos();
    }
    string busca = tipoA+operador+tipoB;
    string retorno  = TabelaTipos.find(busca)->second;
    if(retorno == "ERRO")
        yyerror("Erro de inferencia de tipo, não é possivel executar a operação comos dados tipos: '"+tipoA+"' '"+operador+"'' '"+tipoB+"'");
    
    //TabelaTipos[busca]
    return retorno;
}
void iniEscopoIf(){
    iniEscopo();
    EscopoAtual->isCondicional = true;   
}
void iniEscopo(){
        
    nivel_escopo++;

    Escopo *e = new Escopo(nivel_escopo);

    pair<string,string> p = geraLabelEscopo();

    e->isCondicional = false;
    e->labelInicio = p.first;
    e->labelFim = p.second;

    e->profundidade = profu_escopo;
    profu_escopo++;
    
    EscopoAtual->list_escopo.push_back(e);
    e->escopoPai = EscopoAtual;
    EscopoAtual = e;

}
void fimEscopo(){
    nivel_escopo--;
    EscopoAtual = EscopoAtual->escopoPai;
}
void printVarDeclarations(Escopo *esc){
    string temp = "";

    for (int i = 0; i< esc->list_escopo.size(); ++i){
        temp="";

        for( MapVarNode::const_iterator it = esc->list_escopo[i]->varTable.begin(); it != esc->list_escopo[i]->varTable.end(); ++it ){
            temp += "\t"
                    + (it->second->tipo != "string" ? it->second->tipo : "char") +" " //Se tipo for string é necessário transformar para char na declaração
                    + it->second->nomeTemp
                    + (it->second->tamString > 0 ? "[" + to_string(it->second->tamString) + "]" : "") //verifica se é string, se for define o tamanho
                    + "; "+(it->second->nomeTKid == "" ? "" : " //variavel: "+it->second->nomeTKid) +"\n";
        }
        cout<<temp;
        printVarDeclarations(esc->list_escopo[i]);
        
    }


}
void printVarDeclarations(){
    printVarDeclarations(EscopoGlobal);
}
void printFuncDeclarations(Escopo *esc){
    string temp = "";

    for (int i = 0; i< esc->list_escopo.size(); ++i){
        temp="";

        for( MapFuncao::const_iterator it = esc->list_escopo[i]->funcTempTable.begin(); it != esc->list_escopo[i]->funcTempTable.end(); ++it ){
            temp += "\tvoid " + it->second->nomeTemp + "(); //função: "+it->second->tkid +"\n";
        }
        cout<<temp;
        printFuncDeclarations(esc->list_escopo[i]);
        
    }
}
void printFuncDeclarations(){
    printFuncDeclarations(EscopoGlobal);
}


pair<string,string> geraLabelEscopo(){
    pair<string, string> r;
    r.first = "INI_"+to_string(profu_escopo);
    r.second = "FIM_"+to_string(profu_escopo);

    return r;
}
string getLabelEscopoFim(){
    return EscopoAtual->labelFim;
}
void printFuncoes(Escopo *esc){
     string temp = "";

    for (int i = 0; i< esc->list_escopo.size(); ++i){
        for( MapFuncao::const_iterator it = esc->list_escopo[i]->funcTempTable.begin(); it != esc->list_escopo[i]->funcTempTable.end(); ++it ){
           
                cout <<"void "<< it->second->nomeTemp << "(){  //"+it->second->tkid+"\n";
                cout <<"\n" << it->second->traducao << "\n}\n"; 
        }
        printFuncoes(esc->list_escopo[i]);
    }
}
void printFuncoes(){
    printFuncoes(EscopoGlobal);
}

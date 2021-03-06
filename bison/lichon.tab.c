/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "lichon.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fun{
	char* type;
	struct decl* decl;
	struct declaration_node* declaration_head;
	char* body;
};

struct declaration{
	char* name;
	struct decl_node* decl_head;
};

struct decl{
	char* id;
	char* name;
	struct arg_node* arg_head;
};

struct argument{
	char* type;
	char* name;
	char* id;
};

struct arg_node{
	struct argument* val;
	struct arg_node* next;
};

struct decl_node{
	struct decl* val;
	struct decl_node* next;
};

struct declaration_node{
	struct declaration* val;
	struct declaration_node* next;
};

char* to_string(struct arg_node* head){
	struct arg_node* h=head;
	int size=3;
	while(h){
		size=size+strlen(h->val->type)+1+strlen(h->val->name);
		h=h->next;
	}
	char* toReturn=(char*) malloc(size);
	
	toReturn[0]=0;
	if(head==NULL)
		return toReturn;
	h=head;
	strcat(toReturn,"(");
	if(h){
		strcat(toReturn,h->val->type);
		strcat(toReturn," ");
		strcat(toReturn,h->val->name);
		h=h->next;
	}
		
	while(h){
		strcat(toReturn,",");
		strcat(toReturn,h->val->type);
		strcat(toReturn," ");
		strcat(toReturn,h->val->name);
		h=h->next;
	}
	strcat(toReturn,")");
	return toReturn;
}

void free_list(struct arg_node* head){
	if(head==NULL)
		return;
	if(head->next){
		free_list(head->next);
		head->next=NULL;
	}
	free(head);	
}

void log_exit(char* s){
	if(0)
		printf("exiting from %s\n",s);
	fflush(stdout);
}

int duplicated(struct decl* declarator){
	if(declarator==NULL || declarator->arg_head==NULL)
		return 0;
	for(struct arg_node* it1=declarator->arg_head;it1->next;it1=it1->next)
		for(struct arg_node* it2=it1->next;it2;it2=it2->next){
			if(strcmp(it1->val->id,it2->val->id)==0)
				return 1;
		}
	return 0;
}

char* find_arg(char* id,struct declaration_node* declaration_head){
	

		for(struct declaration_node* it2=declaration_head;it2;it2=it2->next){
			char* type=it2->val->name;
			fflush(stdout);
			for(struct  decl_node* it3=it2->val->decl_head;it3;it3=it3->next)
				if(strcmp(id,it3->val->id)==0){
					char* res=malloc(strlen(type)+strlen(it3->val->name)+2);
					sprintf(res,"%s %s",type,it3->val->name);
					return res;
				}
		}
		return NULL;
}

char* get_args(struct decl* declarator,struct declaration_node* declaration_head){
	struct arg_node* arg_head=declarator->arg_head;
	char* result=malloc(300);
	result[0]=0;
	for(struct arg_node* it=arg_head;it;it=it->next){
		if(find_arg(it->val->id,declaration_head)==NULL)
			return NULL;
		strcat(result,find_arg(it->val->id,declaration_head));
		if(it->next)
			strcat(result,",");
	}
	
	fflush(stdout);
	if(strcmp(result,"")==0)
		result="void";
	return result;
}

int all_types_exists(struct decl* declarator){

	
	if(declarator==NULL)
		return 1;
	for(struct arg_node* it=declarator->arg_head;it;it=it->next)
		if(it->val->type==NULL)
			return 0;
	return 1;
}


/* Line 371 of yacc.c  */
#line 218 "lichon.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "lichon.tab.h".  */
#ifndef YY_YY_LICHON_TAB_H_INCLUDED
# define YY_YY_LICHON_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECL_SPECIFIER = 258,
     POINTER = 259,
     IDENTIFIER = 260,
     NUM = 261,
     STR = 262
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 153 "lichon.y"

struct fun* function_t ;
struct declaration* declaration_t;
struct decl* declarator_t;
struct argument* argument_t;
struct arg_node* arg_list;
struct decl_node* decl_list;
struct declaration_node* declaration_list;
char* str_t;


/* Line 387 of yacc.c  */
#line 280 "lichon.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_LICHON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 308 "lichon.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   83

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  15
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  80

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   262

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      10,    11,     2,     2,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     8,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    14,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    14,    17,    21,    23,    26,
      28,    31,    34,    38,    40,    43,    46,    50,    53,    55,
      57,    61,    66,    70,    75,    80,    84,    86,    89,    92,
      96,    98,   101,   104,   108,   111,   114,   116,   118,   120,
     123,   127,   132,   136,   141,   145,   149,   152,   155,   157
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      16,     0,    -1,    17,    -1,     3,    23,    18,    32,    -1,
      23,    18,    32,    -1,    23,    32,    -1,     3,    23,    32,
      -1,    20,    -1,    20,    19,    -1,    20,    -1,    19,    20,
      -1,     3,     8,    -1,     3,    21,     8,    -1,    23,    -1,
      23,    22,    -1,     9,    23,    -1,    22,     9,    23,    -1,
       4,    24,    -1,    24,    -1,     5,    -1,    10,    23,    11,
      -1,    24,    12,     6,    13,    -1,    24,    12,    13,    -1,
      24,    10,    27,    11,    -1,    24,    10,    25,    11,    -1,
      24,    10,    11,    -1,     5,    -1,     5,    26,    -1,     9,
       5,    -1,    26,     9,     5,    -1,    29,    -1,    29,    28,
      -1,     9,    29,    -1,    28,     9,    29,    -1,     3,    23,
      -1,     3,    30,    -1,     3,    -1,     4,    -1,    31,    -1,
       4,    31,    -1,    10,    30,    11,    -1,    31,    12,     6,
      13,    -1,    31,    12,    13,    -1,    31,    10,    27,    11,
      -1,    10,    27,    11,    -1,    31,    10,    11,    -1,    10,
      11,    -1,    14,    33,    -1,     7,    -1,    33,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   189,   189,   222,   231,   240,   249,   259,   266,   274,
     281,   293,   300,   308,   315,   323,   330,   342,   351,   356,
     364,   372,   381,   389,   400,   411,   423,   434,   446,   457,
     473,   480,   488,   495,   507,   520,   533,   542,   550,   554,
     564,   572,   581,   589,   600,   606,   617,   624,   632,   633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECL_SPECIFIER", "POINTER",
  "IDENTIFIER", "NUM", "STR", "';'", "','", "'('", "')'", "'['", "']'",
  "'{'", "$accept", "functions", "function", "declaration_list",
  "declaration_list_tail", "declaration", "declarator_list",
  "declarator_list_tail", "declarator", "direct_declarator",
  "identifier_list", "identifier_list_tail", "param_list",
  "param_list_tail", "param_declaration", "abstract_declarator",
  "direct_abstract_declarator", "body", "str_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    59,    44,
      40,    41,    91,    93,   123
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    15,    16,    17,    17,    17,    17,    18,    18,    19,
      19,    20,    20,    21,    21,    22,    22,    23,    23,    24,
      24,    24,    24,    24,    24,    24,    25,    25,    26,    26,
      27,    27,    28,    28,    29,    29,    29,    30,    30,    30,
      31,    31,    31,    31,    31,    31,    31,    32,    33,    33
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     2,     3,     1,     2,     1,
       2,     2,     3,     1,     2,     2,     3,     2,     1,     1,
       3,     4,     3,     4,     4,     3,     1,     2,     2,     3,
       1,     2,     2,     3,     2,     2,     1,     1,     1,     2,
       3,     4,     3,     4,     3,     3,     2,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    19,     0,     0,     2,     0,    18,     0,
      17,     0,     1,     0,     0,     0,     7,     5,     0,     0,
       0,     6,    20,    11,     0,    13,    48,    47,     4,     8,
       9,    36,    26,    25,     0,     0,    30,     0,    22,     3,
      12,     0,    14,    49,    10,    37,     0,    34,    35,    38,
       0,    27,    24,    23,     0,    31,    21,    15,     0,    39,
      46,     0,     0,     0,     0,    28,     0,    32,     0,    16,
      44,    40,    45,     0,     0,    42,    29,    33,    43,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    15,    29,    16,    24,    42,    11,     8,
      34,    51,    35,    55,    36,    48,    49,    17,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int8 yypact[] =
{
       5,    43,    46,   -51,    43,    27,   -51,     3,     2,     3,
       2,    23,   -51,    35,    37,    40,    56,   -51,    21,    24,
      40,   -51,   -51,   -51,    52,    53,   -51,    54,   -51,    56,
     -51,    45,    55,   -51,    57,    58,    61,    50,   -51,   -51,
     -51,    43,    62,   -51,   -51,    47,    18,   -51,   -51,    26,
      60,    63,   -51,   -51,    64,    65,   -51,   -51,    43,    26,
     -51,    66,    67,    22,    29,   -51,    68,   -51,    64,   -51,
     -51,   -51,   -51,    69,    70,   -51,   -51,   -51,   -51,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    72,   -51,    -9,   -51,   -51,     0,     1,
     -51,   -51,   -44,   -51,   -50,    20,    30,    -4,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       7,     9,    61,    10,    67,    21,    13,    30,     1,     2,
       3,    28,    18,    25,    19,     4,    39,    14,    77,    73,
      44,    31,    45,     3,    31,    31,    32,    12,    46,    60,
      37,    47,    33,    72,    22,    74,    63,    38,    64,     2,
       3,    57,    75,    23,    26,     4,    10,     2,     3,    45,
       3,     3,     3,     4,    14,    46,     4,    46,    69,    13,
      40,    43,    41,    56,    50,    65,    62,    31,    52,    53,
      54,    58,    66,    76,    68,    59,     0,    70,    71,     0,
      78,    20,     0,    79
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       0,     1,    46,     2,    54,     9,     3,    16,     3,     4,
       5,    15,    10,    13,    12,    10,    20,    14,    68,    63,
      29,     3,     4,     5,     3,     3,     5,     0,    10,    11,
       6,    31,    11,    11,    11,     6,    10,    13,    12,     4,
       5,    41,    13,     8,     7,    10,    45,     4,     5,     4,
       5,     5,     5,    10,    14,    10,    10,    10,    58,     3,
       8,     7,     9,    13,     9,     5,    46,     3,    11,    11,
       9,     9,     9,     5,     9,    45,    -1,    11,    11,    -1,
      11,     9,    -1,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    10,    16,    17,    23,    24,    23,
      24,    23,     0,     3,    14,    18,    20,    32,    10,    12,
      18,    32,    11,     8,    21,    23,     7,    33,    32,    19,
      20,     3,     5,    11,    25,    27,    29,     6,    13,    32,
       8,     9,    22,     7,    20,     4,    10,    23,    30,    31,
       9,    26,    11,    11,     9,    28,    13,    23,     9,    31,
      11,    27,    30,    10,    12,     5,     9,    29,     9,    23,
      11,    11,    11,    27,     6,    13,     5,    29,    11,    13
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 189 "lichon.y"
    {
		
		if(duplicated((yyvsp[(1) - (1)].function_t)->decl)){
			yyerror("duplicated parameters");
			YYERROR;
			
		}
		if((yyvsp[(1) - (1)].function_t)->declaration_head!=NULL){
			char* arg = get_args((yyvsp[(1) - (1)].function_t)->decl,(yyvsp[(1) - (1)].function_t)->declaration_head);
			if(!(arg = get_args((yyvsp[(1) - (1)].function_t)->decl,(yyvsp[(1) - (1)].function_t)->declaration_head))){
				yyerror("no definition found for some parameters");
				YYERROR;
			}
			printf("%s %s(%s)\n%s",(yyvsp[(1) - (1)].function_t)->type,(yyvsp[(1) - (1)].function_t)->decl->name,arg,(yyvsp[(1) - (1)].function_t)->body);
		}else if(!all_types_exists((yyvsp[(1) - (1)].function_t)->decl)){
			yyerror("missing declarations");
			YYERROR;
		}
		else{
			printf("%s %s(",(yyvsp[(1) - (1)].function_t)->type,(yyvsp[(1) - (1)].function_t)->decl->name);
			for(struct arg_node* it=(yyvsp[(1) - (1)].function_t)->decl->arg_head;it;it=it->next){
				printf("%s %s",it->val->type,it->val->name);
				if(it->next)
				printf(",");
			}
			if((yyvsp[(1) - (1)].function_t)->decl->arg_head==NULL)
				printf("void");
			printf(")\n%s",(yyvsp[(1) - (1)].function_t)->body);
				
		}
		
	}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 222 "lichon.y"
    {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type=(yyvsp[(1) - (4)].str_t);
		result->decl=(yyvsp[(2) - (4)].declarator_t);
		result->declaration_head=(yyvsp[(3) - (4)].declaration_list);
		result->body=(yyvsp[(4) - (4)].str_t);
		(yyval.function_t)=result;
	}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 231 "lichon.y"
    {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type="void";
		result->decl=(yyvsp[(1) - (3)].declarator_t);
		result->declaration_head=(yyvsp[(2) - (3)].declaration_list);
		result->body=(yyvsp[(3) - (3)].str_t);
		(yyval.function_t)=result;
	}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 240 "lichon.y"
    {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type="void";
		result->decl=(yyvsp[(1) - (2)].declarator_t);
		result->declaration_head=NULL;
		result->body=(yyvsp[(2) - (2)].str_t);
		(yyval.function_t)=result;
	}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 249 "lichon.y"
    {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type=(yyvsp[(1) - (3)].str_t);
		result->decl=(yyvsp[(2) - (3)].declarator_t);
		result->declaration_head=NULL;
		result->body=(yyvsp[(3) - (3)].str_t);
		(yyval.function_t)=result;
	}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 259 "lichon.y"
    {
		log_exit("declaration_list");	
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=(yyvsp[(1) - (1)].declaration_t);
		head->next=NULL;
		(yyval.declaration_list)=head;
	}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 266 "lichon.y"
    {
		log_exit("declaration_list");
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=(yyvsp[(1) - (2)].declaration_t);
		head->next=(yyvsp[(2) - (2)].declaration_list);
		(yyval.declaration_list)=head;
	}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 274 "lichon.y"
    {
		log_exit("declaration_list_tail");
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=(yyvsp[(1) - (1)].declaration_t);
		head->next=NULL;
		(yyval.declaration_list)=head;
	}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 281 "lichon.y"
    {
		log_exit("declaration_list_tail");
		struct declaration_node* tail = malloc(sizeof(struct declaration_node));
		tail->val=(yyvsp[(2) - (2)].declaration_t);
		tail->next=NULL;
		struct declaration_node* it =(yyvsp[(1) - (2)].declaration_list);
		while(it->next)
			it=it->next;
		it->next=tail;
		(yyval.declaration_list)=(yyvsp[(1) - (2)].declaration_list);
	}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 293 "lichon.y"
    {
		log_exit("declaration");
		struct declaration* result = malloc(sizeof(struct declaration));
		result->name=(yyvsp[(1) - (2)].str_t);
		result->decl_head=NULL;
		(yyval.declaration_t)=result;
	}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 300 "lichon.y"
    {
		log_exit("declaration");
		struct declaration* result = malloc(sizeof(struct declaration));
		result->name=(yyvsp[(1) - (3)].str_t);
		result->decl_head=(yyvsp[(2) - (3)].decl_list);
		(yyval.declaration_t)=result;
	}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 308 "lichon.y"
    {
		log_exit("declarator_list");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=(yyvsp[(1) - (1)].declarator_t);
		head->next=NULL;
		(yyval.decl_list)=head;
	}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 315 "lichon.y"
    {
		log_exit("declarator_list");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=(yyvsp[(1) - (2)].declarator_t);
		head->next=(yyvsp[(2) - (2)].decl_list);
		(yyval.decl_list)=head;
	}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 323 "lichon.y"
    {
		log_exit("declarator_list_tail");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=(yyvsp[(2) - (2)].declarator_t);
		head->next=NULL;
		(yyval.decl_list)=head;
	}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 330 "lichon.y"
    {
		log_exit("declarator_list_tail");
		struct decl_node* tail = malloc(sizeof(struct decl_node));
		tail->val=(yyvsp[(3) - (3)].declarator_t);
		tail->next=NULL;
		struct decl_node* it = (yyvsp[(1) - (3)].decl_list);
		while(it->next)
			it=it->next;
		it->next=tail;
		(yyval.decl_list)=(yyvsp[(1) - (3)].decl_list);
	}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 342 "lichon.y"
    {
		log_exit("declarator");
		char* newName=malloc(strlen((yyvsp[(1) - (2)].str_t))+strlen((yyvsp[(2) - (2)].declarator_t)->name)+1);
		sprintf(newName,"%s%s",(yyvsp[(1) - (2)].str_t),(yyvsp[(2) - (2)].declarator_t)->name);
		free((yyvsp[(1) - (2)].str_t));
		free((yyvsp[(2) - (2)].declarator_t)->name);
		(yyvsp[(2) - (2)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(2) - (2)].declarator_t);
	}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 351 "lichon.y"
    {
		log_exit("declarator");
		(yyval.declarator_t)=(yyvsp[(1) - (1)].declarator_t);
	}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 356 "lichon.y"
    {
		log_exit("direct_declarator: IDENTIFIER");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=(yyvsp[(1) - (1)].str_t);
		result->id=strdup((yyvsp[(1) - (1)].str_t));
		result->arg_head=NULL;
		(yyval.declarator_t)=result;
	}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 364 "lichon.y"
    {
		log_exit("direct_declarator: ( eclarator )");
		char* newName = malloc(3+strlen((yyvsp[(2) - (3)].declarator_t)->name));
		sprintf(newName,"(%s)",(yyvsp[(2) - (3)].declarator_t)->name);
		free((yyvsp[(2) - (3)].declarator_t)->name);
		(yyvsp[(2) - (3)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(2) - (3)].declarator_t);
	}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 372 "lichon.y"
    {
		log_exit("direct_declarator: direct_declarator[NUM]");
		char* newName = malloc(strlen((yyvsp[(1) - (4)].declarator_t)->name)+strlen((yyvsp[(3) - (4)].str_t))+3);
		sprintf(newName,"%s[%s]",(yyvsp[(1) - (4)].declarator_t)->name,(yyvsp[(3) - (4)].str_t));
		free((yyvsp[(1) - (4)].declarator_t)->name);
		free((yyvsp[(3) - (4)].str_t));
		(yyvsp[(1) - (4)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(1) - (4)].declarator_t);
	}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 381 "lichon.y"
    {
		log_exit("direct_declarator: direct_declarator[]");
		char* newName = malloc(strlen((yyvsp[(1) - (3)].declarator_t)->name)+3);
		sprintf(newName,"%s[]",(yyvsp[(1) - (3)].declarator_t)->name);
		free((yyvsp[(1) - (3)].declarator_t)->name);
		(yyvsp[(1) - (3)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(1) - (3)].declarator_t);
	}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 389 "lichon.y"
    {
		log_exit("direct_declarator: direct_declarator(param_list)");
		if((yyvsp[(1) - (4)].declarator_t)->arg_head){
			char* newName=malloc(strlen((yyvsp[(1) - (4)].declarator_t)->name)+strlen(to_string((yyvsp[(1) - (4)].declarator_t)->arg_head))+1);
			sprintf(newName,"%s%s",(yyvsp[(1) - (4)].declarator_t)->name,to_string((yyvsp[(1) - (4)].declarator_t)->arg_head));
			free((yyvsp[(1) - (4)].declarator_t)->name);
			(yyvsp[(1) - (4)].declarator_t)->name=newName;
		}
		(yyvsp[(1) - (4)].declarator_t)->arg_head=(yyvsp[(3) - (4)].arg_list);
		(yyval.declarator_t)=(yyvsp[(1) - (4)].declarator_t);
	}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 400 "lichon.y"
    {
		log_exit("direct_declarator: direct_declarator(identifier_list)");
		if((yyvsp[(1) - (4)].declarator_t)->arg_head){
			char* newName=malloc(strlen((yyvsp[(1) - (4)].declarator_t)->name)+strlen(to_string((yyvsp[(1) - (4)].declarator_t)->arg_head))+1);
			sprintf(newName,"%s%s",(yyvsp[(1) - (4)].declarator_t)->name,to_string((yyvsp[(1) - (4)].declarator_t)->arg_head));
			free((yyvsp[(1) - (4)].declarator_t)->name);
			(yyvsp[(1) - (4)].declarator_t)->name=newName;
		}
		(yyvsp[(1) - (4)].declarator_t)->arg_head=(yyvsp[(3) - (4)].arg_list);
		(yyval.declarator_t)=(yyvsp[(1) - (4)].declarator_t);
	}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 411 "lichon.y"
    {
		log_exit("direct_declarator: direct_declarator()");
		if((yyvsp[(1) - (3)].declarator_t)->arg_head){
			char* newName=malloc(strlen((yyvsp[(1) - (3)].declarator_t)->name)+strlen(to_string((yyvsp[(1) - (3)].declarator_t)->arg_head))+1);
			sprintf(newName,"%s%s",(yyvsp[(1) - (3)].declarator_t)->name,to_string((yyvsp[(1) - (3)].declarator_t)->arg_head));
			free((yyvsp[(1) - (3)].declarator_t)->name);
			(yyvsp[(1) - (3)].declarator_t)->name=newName;
		}
		(yyvsp[(1) - (3)].declarator_t)->arg_head=NULL;
		(yyval.declarator_t)=(yyvsp[(1) - (3)].declarator_t);
	}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 423 "lichon.y"
    {
		log_exit("identifier_list: IDENTIFIER");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=(yyvsp[(1) - (1)].str_t);
		newArg->id=strdup((yyvsp[(1) - (1)].str_t));
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=NULL;
		(yyval.arg_list)=head;
	}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 434 "lichon.y"
    {
		log_exit("identifier_list");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=(yyvsp[(1) - (2)].str_t);
		newArg->id=strdup((yyvsp[(1) - (2)].str_t));
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=(yyvsp[(2) - (2)].arg_list);
		(yyval.arg_list)=head;
	}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 446 "lichon.y"
    {
		log_exit("identifier_list_tail");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=(yyvsp[(2) - (2)].str_t);
		newArg->id=strdup((yyvsp[(2) - (2)].str_t));
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=NULL;
		(yyval.arg_list)=head;
	}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 457 "lichon.y"
    {
		log_exit("identifier_list_tail");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=(yyvsp[(3) - (3)].str_t);
		newArg->id=strdup((yyvsp[(3) - (3)].str_t));
		newArg->type=NULL;
		struct arg_node* tail = malloc(sizeof(struct arg_node));
		tail->val=newArg;
		tail->next=NULL;
		struct arg_node* it=(yyvsp[(1) - (3)].arg_list);
		while(it->next)
			it=it->next;
		it->next=tail;
		(yyval.arg_list)=(yyvsp[(1) - (3)].arg_list);
	}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 473 "lichon.y"
    {
		log_exit("param_list");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=(yyvsp[(1) - (1)].argument_t);
		head->next=NULL;
		(yyval.arg_list)=head;		
	}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 480 "lichon.y"
    {
		log_exit("param_list");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=(yyvsp[(1) - (2)].argument_t);
		head->next=(yyvsp[(2) - (2)].arg_list);
		(yyval.arg_list)=head;
	}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 488 "lichon.y"
    {
		log_exit("param_list_tail");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=(yyvsp[(2) - (2)].argument_t);
		head->next=NULL;
		(yyval.arg_list)=head;
	}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 495 "lichon.y"
    {
		log_exit("param_list_tail");
		struct arg_node* tail = malloc(sizeof(struct arg_node));
		tail->val=(yyvsp[(3) - (3)].argument_t);
		tail->next=NULL;
		struct arg_node* it=(yyvsp[(1) - (3)].arg_list);
		while(it->next)
			it=it->next;
		it->next=tail;
		(yyval.arg_list)=(yyvsp[(1) - (3)].arg_list);
	}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 507 "lichon.y"
    {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument));
		newArg->type=(yyvsp[(1) - (2)].str_t);
		newArg->id=strdup((yyvsp[(2) - (2)].declarator_t)->id);
		char* newId=malloc(sizeof((yyvsp[(2) - (2)].declarator_t)->name)+sizeof(to_string((yyvsp[(2) - (2)].declarator_t)->arg_head))+1);
		sprintf(newId,"%s%s",(yyvsp[(2) - (2)].declarator_t)->name,to_string((yyvsp[(2) - (2)].declarator_t)->arg_head));
		free((yyvsp[(2) - (2)].declarator_t)->name);
		free_list((yyvsp[(2) - (2)].declarator_t)->arg_head);
		free((yyvsp[(2) - (2)].declarator_t));
		newArg->name=newId;
		(yyval.argument_t)=newArg;
	}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 520 "lichon.y"
    {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument));
		newArg->type=(yyvsp[(1) - (2)].str_t);
		newArg->id=strdup((yyvsp[(2) - (2)].declarator_t)->id);
		char* newId=malloc(sizeof((yyvsp[(2) - (2)].declarator_t)->name)+sizeof(to_string((yyvsp[(2) - (2)].declarator_t)->arg_head))+1);
		sprintf(newId,"%s%s",(yyvsp[(2) - (2)].declarator_t)->name,to_string((yyvsp[(2) - (2)].declarator_t)->arg_head));
		free((yyvsp[(2) - (2)].declarator_t)->name);
		free_list((yyvsp[(2) - (2)].declarator_t)->arg_head);
		free((yyvsp[(2) - (2)].declarator_t));
		newArg->name=newId;
		(yyval.argument_t)=newArg;
	}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 533 "lichon.y"
    {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument*));
		newArg->type=(yyvsp[(1) - (1)].str_t);
		newArg->id=NULL;
		newArg->name=NULL;
		(yyval.argument_t)=newArg;
	}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 542 "lichon.y"
    {
		log_exit("abstract_declarator");
		struct decl* result = malloc(sizeof(struct decl));
		result->name=(yyvsp[(1) - (1)].str_t);
		result->id=NULL;
		result->arg_head=NULL;
		(yyval.declarator_t)=result;
	}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 550 "lichon.y"
    {
		log_exit("abstract_declarator");
		(yyval.declarator_t)=(yyvsp[(1) - (1)].declarator_t);
	}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 554 "lichon.y"
    {
		log_exit("abstract_declarator");
		char* newName=malloc(strlen((yyvsp[(1) - (2)].str_t))+strlen((yyvsp[(2) - (2)].declarator_t)->name)+1);
		sprintf(newName,"%s%s",(yyvsp[(1) - (2)].str_t),(yyvsp[(2) - (2)].declarator_t)->name);
		free((yyvsp[(1) - (2)].str_t));
		free((yyvsp[(2) - (2)].declarator_t)->name);
		(yyvsp[(2) - (2)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(2) - (2)].declarator_t);
	}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 564 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		char* newName = malloc(3+strlen((yyvsp[(2) - (3)].declarator_t)->name));
		sprintf(newName,"(%s)",(yyvsp[(2) - (3)].declarator_t)->name);
		free((yyvsp[(2) - (3)].declarator_t)->name);
		(yyvsp[(2) - (3)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(2) - (3)].declarator_t);
	}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 572 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		char* newName = malloc(strlen((yyvsp[(1) - (4)].declarator_t)->name)+strlen((yyvsp[(3) - (4)].str_t))+3);
		sprintf(newName,"%s[%s]",(yyvsp[(1) - (4)].declarator_t)->name,(yyvsp[(3) - (4)].str_t));
		free((yyvsp[(1) - (4)].declarator_t)->name);
		free((yyvsp[(3) - (4)].str_t));
		(yyvsp[(1) - (4)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(1) - (4)].declarator_t);		
	}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 581 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		char* newName = malloc(strlen((yyvsp[(1) - (3)].declarator_t)->name)+3);
		sprintf(newName,"%s[]",(yyvsp[(1) - (3)].declarator_t)->name);
		free((yyvsp[(1) - (3)].declarator_t)->name);
		(yyvsp[(1) - (3)].declarator_t)->name=newName;
		(yyval.declarator_t)=(yyvsp[(1) - (3)].declarator_t);
	}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 589 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		if((yyvsp[(1) - (4)].declarator_t)->arg_head){
			char* newName=malloc(strlen((yyvsp[(1) - (4)].declarator_t)->name)+strlen(to_string((yyvsp[(1) - (4)].declarator_t)->arg_head))+1);
			sprintf(newName,"%s%s",(yyvsp[(1) - (4)].declarator_t)->name,to_string((yyvsp[(1) - (4)].declarator_t)->arg_head));
			free((yyvsp[(1) - (4)].declarator_t)->name);
			(yyvsp[(1) - (4)].declarator_t)->name=newName;
		}
		(yyvsp[(1) - (4)].declarator_t)->arg_head=(yyvsp[(3) - (4)].arg_list);
		(yyval.declarator_t)=(yyvsp[(1) - (4)].declarator_t);
	}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 600 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=NULL;
		result->arg_head=(yyvsp[(2) - (3)].arg_list);
	}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 606 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		if((yyvsp[(1) - (3)].declarator_t)->arg_head){
			char* newName=malloc(strlen((yyvsp[(1) - (3)].declarator_t)->name)+strlen(to_string((yyvsp[(1) - (3)].declarator_t)->arg_head))+1);
			sprintf(newName,"%s%s",(yyvsp[(1) - (3)].declarator_t)->name,to_string((yyvsp[(1) - (3)].declarator_t)->arg_head));
			free((yyvsp[(1) - (3)].declarator_t)->name);
			(yyvsp[(1) - (3)].declarator_t)->name=newName;
		}
		(yyvsp[(1) - (3)].declarator_t)->arg_head=NULL;
		(yyval.declarator_t)=(yyvsp[(1) - (3)].declarator_t);
	}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 617 "lichon.y"
    {
		log_exit("direct_abstract_declarator");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=NULL;
		result->arg_head=NULL;
	}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 624 "lichon.y"
    {
		log_exit("body");
		char* result = malloc(strlen((yyvsp[(2) - (2)].str_t))+2);
		sprintf(result,"{%s",(yyvsp[(2) - (2)].str_t));
		free((yyvsp[(2) - (2)].str_t));
		(yyval.str_t)=result;
	}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 633 "lichon.y"
    {
		log_exit("str_list");
		char* result = malloc(strlen((yyvsp[(1) - (2)].str_t))+strlen((yyvsp[(2) - (2)].str_t))+1);
		sprintf(result,"%s%s",(yyvsp[(1) - (2)].str_t),(yyvsp[(2) - (2)].str_t));
		free((yyvsp[(1) - (2)].str_t));
		free((yyvsp[(2) - (2)].str_t));
		(yyval.str_t)=result;
	}
    break;


/* Line 1787 of yacc.c  */
#line 2230 "lichon.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 643 "lichon.y"


int main() {

  yyparse(); 
}

int yyerror(char *s) {

   printf("blad: *%s*\n", s, yylval.str_t); 
}
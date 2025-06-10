
/*  A Bison parser, made from ./prime/parser_book.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	tident	258
#define	tnumber	259
#define	tconst	260
#define	tif	261
#define	teif	262
#define	telse	263
#define	tint	264
#define	treturn	265
#define	tvoid	266
#define	twhile	267
#define	taddAssign	268
#define	tsubAssign	269
#define	tmulAssign	270
#define	tdivAssign	271
#define	tmodAssign	272
#define	tor	273
#define	tand	274
#define	tequal	275
#define	tnotequ	276
#define	tgreate	277
#define	tlesse	278
#define	tinc	279
#define	tdec	280
#define	tlowerthanelse	281

#line 1 "./prime/parser_book.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

/*yacc source for Mini C*/
void semantic(int);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		155
#define	YYFLAG		-32768
#define	YYNTBASE	44

#define YYTRANSLATE(x) ((unsigned)(x) <= 281 ? yytranslate[x] : 89)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    43,     2,     2,     2,    42,     2,     2,    27,
    28,    40,    38,    29,    39,     2,    41,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    32,    37,
    33,    36,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    34,     2,    35,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    30,     2,    31,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    18,    20,    22,
    25,    27,    29,    31,    33,    35,    37,    41,    43,    44,
    46,    50,    53,    58,    60,    61,    63,    66,    70,    72,
    76,    78,    82,    84,    89,    91,    92,    94,    95,    97,
   100,   102,   104,   106,   108,   110,   113,   115,   116,   123,
   132,   138,   142,   144,   146,   150,   154,   158,   162,   166,
   170,   172,   176,   178,   182,   184,   188,   192,   194,   198,
   202,   206,   210,   212,   216,   220,   222,   226,   230,   234,
   236,   239,   242,   245,   248,   250,   255,   260,   263,   266,
   268,   269,   271,   273,   277,   279,   281
};

static const short yyrhs[] = {    45,
     0,    46,     0,    45,    46,     0,    47,     0,    62,     0,
    48,    59,     0,    49,    54,    55,     0,    50,     0,    51,
     0,    50,    51,     0,    52,     0,    53,     0,     5,     0,
     9,     0,    11,     0,     3,     0,    27,    56,    28,     0,
    57,     0,     0,    58,     0,    57,    29,    58,     0,    49,
    65,     0,    30,    60,    67,    31,     0,    61,     0,     0,
    62,     0,    61,    62,     0,    49,    63,    32,     0,    64,
     0,    63,    29,    64,     0,    65,     0,    65,    33,     4,
     0,     3,     0,     3,    34,    66,    35,     0,     4,     0,
     0,    68,     0,     0,    69,     0,    68,    69,     0,    59,
     0,    70,     0,    72,     0,    73,     0,    74,     0,    71,
    32,     0,    75,     0,     0,     6,    27,    75,    28,    69,
     7,     0,     6,    27,    75,    28,    69,     8,    69,     7,
     0,    12,    27,    75,    28,    69,     0,    10,    71,    32,
     0,    76,     0,    77,     0,    83,    33,    76,     0,    83,
    13,    76,     0,    83,    14,    76,     0,    83,    15,    76,
     0,    83,    16,    76,     0,    83,    17,    76,     0,    78,
     0,    77,    18,    78,     0,    79,     0,    78,    19,    79,
     0,    80,     0,    79,    20,    80,     0,    79,    21,    80,
     0,    81,     0,    80,    36,    81,     0,    80,    37,    81,
     0,    80,    22,    81,     0,    80,    23,    81,     0,    82,
     0,    81,    38,    82,     0,    81,    39,    82,     0,    83,
     0,    82,    40,    83,     0,    82,    41,    83,     0,    82,
    42,    83,     0,    84,     0,    39,    83,     0,    43,    83,
     0,    24,    83,     0,    25,    83,     0,    88,     0,    84,
    34,    75,    35,     0,    84,    27,    85,    28,     0,    84,
    24,     0,    84,    25,     0,    86,     0,     0,    87,     0,
    76,     0,    87,    29,    76,     0,     3,     0,     4,     0,
    27,    75,    28,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115
};

static const char * const yytname[] = {   "$","error","$undefined.","tident",
"tnumber","tconst","tif","teif","telse","tint","treturn","tvoid","twhile","taddAssign",
"tsubAssign","tmulAssign","tdivAssign","tmodAssign","tor","tand","tequal","tnotequ",
"tgreate","tlesse","tinc","tdec","tlowerthanelse","'('","')'","','","'{'","'}'",
"';'","'='","'['","']'","'>'","'<'","'+'","'-'","'*'","'/'","'%'","'!'","mini_c",
"translation_unit","external_dcl","function_def","function_header","dcl_spec",
"dcl_specifiers","dcl_specifier","type_qualifier","type_specifier","function_name",
"formal_param","opt_formal_param","formal_param_list","param_dcl","compound_st",
"opt_dcl_list","declaration_list","declaration","init_dcl_list","init_declarator",
"declarator","opt_number","opt_stat_list","statement_list","statement","expression_st",
"opt_expression","if_st","while_st","return_st","expression","assignment_exp",
"logical_or_exp","logical_and_exp","equality_exp","relational_exp","additive_exp",
"multiplicative_exp","unary_exp","postfix_exp","opt_actual_param","actual_param",
"actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    44,    45,    45,    46,    46,    47,    48,    49,    50,    50,
    51,    51,    52,    53,    53,    54,    55,    56,    56,    57,
    57,    58,    59,    60,    60,    61,    61,    62,    63,    63,
    64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
    69,    69,    69,    69,    69,    70,    71,    71,    72,    72,
    73,    74,    75,    76,    76,    76,    76,    76,    76,    76,
    77,    77,    78,    78,    79,    79,    79,    80,    80,    80,
    80,    80,    81,    81,    81,    82,    82,    82,    82,    83,
    83,    83,    83,    83,    84,    84,    84,    84,    84,    85,
    85,    86,    87,    87,    88,    88,    88
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     3,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
     3,     2,     4,     1,     0,     1,     2,     3,     1,     3,
     1,     3,     1,     4,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     2,     1,     0,     6,     8,
     5,     3,     1,     1,     3,     3,     3,     3,     3,     3,
     1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
     3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
     2,     2,     2,     2,     1,     4,     4,     2,     2,     1,
     0,     1,     1,     3,     1,     1,     3
};

static const short yydefact[] = {     0,
    13,    14,    15,     1,     2,     4,     0,     0,     8,     9,
    11,    12,     5,     3,    25,     6,    33,     0,     0,    29,
    31,    10,     0,    38,    24,    26,    36,    19,     7,     0,
    28,     0,    33,    95,    96,     0,    48,     0,     0,     0,
     0,     0,     0,    41,     0,    37,    39,    42,     0,    43,
    44,    45,    47,    53,    54,    61,    63,    65,    68,    73,
    76,    80,    85,    27,    35,     0,     0,     0,    18,    20,
    30,    32,     0,     0,     0,    83,    84,     0,    81,    82,
    23,    40,    46,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    88,    89,    91,     0,    34,    22,    17,     0,
     0,    52,     0,    97,    62,    76,    64,    66,    67,    71,
    72,    69,    70,    74,    75,    77,    78,    79,    56,    57,
    58,    59,    60,    55,    93,     0,    90,    92,     0,    21,
    48,    48,    87,     0,    86,     0,    51,    94,    49,    48,
     0,    50,     0,     0,     0
};

static const short yydefgoto[] = {   153,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    18,
    29,    68,    69,    70,    44,    24,    25,    13,    19,    20,
    21,    66,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
   136,   137,   138,    63
};

static const short yypact[] = {    60,
-32768,-32768,-32768,    60,-32768,-32768,   -25,     8,    60,-32768,
-32768,-32768,-32768,-32768,    60,-32768,     3,     4,   -19,-32768,
     1,-32768,    11,    75,    60,-32768,    32,    60,-32768,    11,
-32768,    82,    58,-32768,-32768,    66,    37,    67,    37,    37,
    37,    37,    37,-32768,    70,    75,-32768,-32768,    71,-32768,
-32768,-32768,-32768,-32768,    80,    87,    18,   -14,     5,    42,
    12,    43,-32768,-32768,-32768,    77,    11,    85,    81,-32768,
-32768,-32768,    37,    84,    37,-32768,-32768,    91,-32768,-32768,
-32768,-32768,-32768,    37,    37,    37,    37,    37,    37,    37,
    37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
    37,    37,-32768,-32768,    37,    37,-32768,-32768,-32768,    60,
    92,-32768,    93,-32768,    87,-32768,    18,   -14,   -14,     5,
     5,     5,     5,    42,    42,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    94,-32768,    95,    88,-32768,
   105,   105,-32768,    37,-32768,    39,-32768,-32768,-32768,   105,
   118,-32768,   126,   127,-32768
};

static const short yypgoto[] = {-32768,
-32768,   124,-32768,-32768,   -13,-32768,   122,-32768,-32768,-32768,
-32768,-32768,-32768,    23,   129,-32768,-32768,    17,-32768,   104,
    72,-32768,-32768,-32768,   -46,-32768,   100,-32768,-32768,-32768,
   -40,   -81,-32768,    54,    55,     2,   -16,    -2,   -36,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		148


static const short yytable[] = {    82,
    78,    23,    76,    77,    15,    79,    80,    88,    89,    30,
    17,    23,    31,    33,    67,   129,   130,   131,   132,   133,
   134,    90,    91,   135,    97,    98,    99,   100,   101,   -16,
    28,    26,   111,    32,   113,    65,    27,    86,    87,    34,
    35,    64,    92,    93,   102,   149,   150,   116,   116,   116,
   116,   116,   116,   116,   116,   116,   116,   126,   127,   128,
    39,    40,   148,    41,     1,   139,   103,   104,     2,   105,
     3,   120,   121,   122,   123,    42,   106,    34,    35,    43,
    36,    94,    95,    96,    37,    72,    38,   118,   119,   124,
   125,    27,    73,    75,   146,   147,    67,    84,    39,    40,
    81,    41,    83,   151,    15,    85,   -48,    34,    35,   110,
    36,   107,   109,    42,    37,   112,    38,    43,   114,   141,
   142,   143,   145,   144,   152,   154,   155,    14,    39,    40,
    22,    41,   140,    71,    15,    16,    74,   115,   108,   117,
     0,     0,     0,    42,     0,     0,     0,    43
};

static const short yycheck[] = {    46,
    41,    15,    39,    40,    30,    42,    43,    22,    23,    29,
     3,    25,    32,     3,    28,    97,    98,    99,   100,   101,
   102,    36,    37,   105,    13,    14,    15,    16,    17,    27,
    27,    15,    73,    33,    75,     4,    34,    20,    21,     3,
     4,    25,    38,    39,    33,     7,     8,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    24,    25,   144,    27,     5,   106,    24,    25,     9,    27,
    11,    88,    89,    90,    91,    39,    34,     3,     4,    43,
     6,    40,    41,    42,    10,     4,    12,    86,    87,    92,
    93,    34,    27,    27,   141,   142,   110,    18,    24,    25,
    31,    27,    32,   150,    30,    19,    32,     3,     4,    29,
     6,    35,    28,    39,    10,    32,    12,    43,    28,    28,
    28,    28,    35,    29,     7,     0,     0,     4,    24,    25,
     9,    27,   110,    30,    30,     7,    37,    84,    67,    85,
    -1,    -1,    -1,    39,    -1,    -1,    -1,    43
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 17 "./prime/parser_book.y"
{semantic(1);;
    break;}
case 2:
#line 18 "./prime/parser_book.y"
{semantic(2);;
    break;}
case 3:
#line 19 "./prime/parser_book.y"
{semantic(3);;
    break;}
case 4:
#line 20 "./prime/parser_book.y"
{semantic(4);;
    break;}
case 5:
#line 21 "./prime/parser_book.y"
{semantic(5);;
    break;}
case 6:
#line 22 "./prime/parser_book.y"
{semantic(6);;
    break;}
case 7:
#line 23 "./prime/parser_book.y"
{semantic(7);;
    break;}
case 8:
#line 24 "./prime/parser_book.y"
{semantic(8);;
    break;}
case 9:
#line 25 "./prime/parser_book.y"
{semantic(9);;
    break;}
case 10:
#line 26 "./prime/parser_book.y"
{semantic(10);;
    break;}
case 11:
#line 27 "./prime/parser_book.y"
{semantic(11);;
    break;}
case 12:
#line 28 "./prime/parser_book.y"
{semantic(12);;
    break;}
case 13:
#line 29 "./prime/parser_book.y"
{semantic(13);;
    break;}
case 14:
#line 30 "./prime/parser_book.y"
{semantic(14);;
    break;}
case 15:
#line 31 "./prime/parser_book.y"
{semantic(15);;
    break;}
case 16:
#line 32 "./prime/parser_book.y"
{semantic(16);;
    break;}
case 17:
#line 33 "./prime/parser_book.y"
{semantic(17);;
    break;}
case 18:
#line 34 "./prime/parser_book.y"
{semantic(18);;
    break;}
case 19:
#line 35 "./prime/parser_book.y"
{semantic(19);;
    break;}
case 20:
#line 36 "./prime/parser_book.y"
{semantic(20);;
    break;}
case 21:
#line 37 "./prime/parser_book.y"
{semantic(21);;
    break;}
case 22:
#line 38 "./prime/parser_book.y"
{semantic(22);;
    break;}
case 23:
#line 39 "./prime/parser_book.y"
{semantic(23);;
    break;}
case 24:
#line 40 "./prime/parser_book.y"
{semantic(24);;
    break;}
case 25:
#line 41 "./prime/parser_book.y"
{semantic(25);;
    break;}
case 26:
#line 42 "./prime/parser_book.y"
{semantic(26);;
    break;}
case 27:
#line 43 "./prime/parser_book.y"
{semantic(27);;
    break;}
case 28:
#line 44 "./prime/parser_book.y"
{semantic(28);;
    break;}
case 29:
#line 45 "./prime/parser_book.y"
{semantic(29);;
    break;}
case 30:
#line 46 "./prime/parser_book.y"
{semantic(30);;
    break;}
case 31:
#line 47 "./prime/parser_book.y"
{semantic(31);;
    break;}
case 32:
#line 48 "./prime/parser_book.y"
{semantic(32);;
    break;}
case 33:
#line 49 "./prime/parser_book.y"
{semantic(33);;
    break;}
case 34:
#line 50 "./prime/parser_book.y"
{semantic(34);;
    break;}
case 35:
#line 51 "./prime/parser_book.y"
{semantic(35);;
    break;}
case 36:
#line 52 "./prime/parser_book.y"
{semantic(36);;
    break;}
case 37:
#line 53 "./prime/parser_book.y"
{semantic(37);;
    break;}
case 38:
#line 54 "./prime/parser_book.y"
{semantic(38);;
    break;}
case 39:
#line 55 "./prime/parser_book.y"
{semantic(39);;
    break;}
case 40:
#line 56 "./prime/parser_book.y"
{semantic(40);;
    break;}
case 41:
#line 57 "./prime/parser_book.y"
{semantic(41);;
    break;}
case 42:
#line 58 "./prime/parser_book.y"
{semantic(42);;
    break;}
case 43:
#line 59 "./prime/parser_book.y"
{semantic(43);;
    break;}
case 44:
#line 60 "./prime/parser_book.y"
{semantic(44);;
    break;}
case 45:
#line 61 "./prime/parser_book.y"
{semantic(45);;
    break;}
case 46:
#line 63 "./prime/parser_book.y"
{semantic(46);;
    break;}
case 47:
#line 64 "./prime/parser_book.y"
{semantic(47);;
    break;}
case 48:
#line 65 "./prime/parser_book.y"
{semantic(48);;
    break;}
case 49:
#line 66 "./prime/parser_book.y"
{semantic(49);;
    break;}
case 50:
#line 67 "./prime/parser_book.y"
{semantic(50);;
    break;}
case 51:
#line 68 "./prime/parser_book.y"
{semantic(51);;
    break;}
case 52:
#line 69 "./prime/parser_book.y"
{semantic(52);;
    break;}
case 53:
#line 70 "./prime/parser_book.y"
{semantic(53);;
    break;}
case 54:
#line 71 "./prime/parser_book.y"
{semantic(54);;
    break;}
case 55:
#line 72 "./prime/parser_book.y"
{semantic(55);;
    break;}
case 56:
#line 73 "./prime/parser_book.y"
{semantic(56);;
    break;}
case 57:
#line 74 "./prime/parser_book.y"
{semantic(57);;
    break;}
case 58:
#line 75 "./prime/parser_book.y"
{semantic(58);;
    break;}
case 59:
#line 76 "./prime/parser_book.y"
{semantic(59);;
    break;}
case 60:
#line 77 "./prime/parser_book.y"
{semantic(60);;
    break;}
case 61:
#line 79 "./prime/parser_book.y"
{semantic(61);;
    break;}
case 62:
#line 80 "./prime/parser_book.y"
{semantic(62);;
    break;}
case 63:
#line 81 "./prime/parser_book.y"
{semantic(63);;
    break;}
case 64:
#line 82 "./prime/parser_book.y"
{semantic(64);;
    break;}
case 65:
#line 83 "./prime/parser_book.y"
{semantic(65);;
    break;}
case 66:
#line 84 "./prime/parser_book.y"
{semantic(66);;
    break;}
case 67:
#line 85 "./prime/parser_book.y"
{semantic(67);;
    break;}
case 68:
#line 86 "./prime/parser_book.y"
{semantic(68);;
    break;}
case 69:
#line 87 "./prime/parser_book.y"
{semantic(69);;
    break;}
case 70:
#line 88 "./prime/parser_book.y"
{semantic(70);;
    break;}
case 71:
#line 89 "./prime/parser_book.y"
{semantic(71);;
    break;}
case 72:
#line 90 "./prime/parser_book.y"
{semantic(72);;
    break;}
case 73:
#line 91 "./prime/parser_book.y"
{semantic(73);;
    break;}
case 74:
#line 92 "./prime/parser_book.y"
{semantic(74);;
    break;}
case 75:
#line 93 "./prime/parser_book.y"
{semantic(75);;
    break;}
case 76:
#line 94 "./prime/parser_book.y"
{semantic(76);;
    break;}
case 77:
#line 95 "./prime/parser_book.y"
{semantic(77);;
    break;}
case 78:
#line 96 "./prime/parser_book.y"
{semantic(78);;
    break;}
case 79:
#line 97 "./prime/parser_book.y"
{semantic(79);;
    break;}
case 80:
#line 98 "./prime/parser_book.y"
{semantic(80);;
    break;}
case 81:
#line 99 "./prime/parser_book.y"
{semantic(81);;
    break;}
case 82:
#line 100 "./prime/parser_book.y"
{semantic(82);;
    break;}
case 83:
#line 101 "./prime/parser_book.y"
{semantic(83);;
    break;}
case 84:
#line 102 "./prime/parser_book.y"
{semantic(84);;
    break;}
case 85:
#line 103 "./prime/parser_book.y"
{semantic(85);;
    break;}
case 86:
#line 104 "./prime/parser_book.y"
{semantic(86);;
    break;}
case 87:
#line 105 "./prime/parser_book.y"
{semantic(87);;
    break;}
case 88:
#line 106 "./prime/parser_book.y"
{semantic(88);;
    break;}
case 89:
#line 107 "./prime/parser_book.y"
{semantic(89);;
    break;}
case 90:
#line 108 "./prime/parser_book.y"
{semantic(90);;
    break;}
case 91:
#line 109 "./prime/parser_book.y"
{semantic(91);;
    break;}
case 92:
#line 110 "./prime/parser_book.y"
{semantic(92);;
    break;}
case 93:
#line 111 "./prime/parser_book.y"
{semantic(93);;
    break;}
case 94:
#line 112 "./prime/parser_book.y"
{semantic(94);;
    break;}
case 95:
#line 113 "./prime/parser_book.y"
{semantic(95);;
    break;}
case 96:
#line 114 "./prime/parser_book.y"
{semantic(96);;
    break;}
case 97:
#line 115 "./prime/parser_book.y"
{semantic(97);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 116 "./prime/parser_book.y"


void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}

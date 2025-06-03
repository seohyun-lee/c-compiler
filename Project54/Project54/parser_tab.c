
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TCONST	258
#define	TELSE	259
#define	TIF	260
#define	TINT	261
#define	TRETURN	262
#define	TVOID	263
#define	TWHILE	264
#define	TPLUS	265
#define	TMINUS	266
#define	TMUL	267
#define	TDIV	268
#define	TMOD	269
#define	TASSIGN	270
#define	TEQUAL	271
#define	TNOTEQU	272
#define	TLESSE	273
#define	TGREATE	274
#define	TAND	275
#define	TOR	276
#define	TINC	277
#define	TDEC	278
#define	TADDASSIGN	279
#define	TSUBASSIGN	280
#define	TMULASSIGN	281
#define	TDIVASSIGN	282
#define	TMODASSIGN	283
#define	TIDENT	284
#define	TLPAREN	285
#define	TRPAREN	286
#define	TLBRACE	287
#define	TRBRACE	288
#define	TLSQUARE	289
#define	TRSQUARE	290
#define	TCOMMA	291
#define	TDOT	292
#define	TSEMI	293
#define	TNOT	294
#define	TLESS	295
#define	TGREAT	296
#define	TINTNUM	297
#define	TFLOATNUM	298
#define	TSTRING	299
#define	TCHAR	300
#define	TFLOAT	301
#define	TERROR	302
#define	TLOWERTHANELSE	303

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

/*yacc source for Mini C*/
extern void update_sym_table(int id_index, int attr_num, int attr_value);
void update_sym_table_param(int id_index, int param_count, int param_type[], int param_ids[]);
extern yyerror(const char*);
int current_type;
int is_const = 0;
extern int st_index; /* lex에서 process_sym_table 후에 그 결과(id)가 저장되는 변수 */

/* 가변 길이 파라미터 타입 및 이름(string pool index) 리스트 */
int param_types[256];
int param_ids[256];
int param_capacity = 0;
int param_count = 0;
int saved_func_id = -1;


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



#define	YYFINAL		163
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 94)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    18,    20,    22,
    25,    27,    29,    31,    33,    35,    37,    39,    41,    45,
    48,    50,    52,    53,    55,    59,    62,    68,    73,    75,
    76,    78,    81,    85,    87,    91,    93,    97,   101,   105,
   107,   112,   114,   115,   117,   118,   120,   123,   125,   127,
   129,   131,   133,   136,   138,   139,   145,   153,   159,   163,
   165,   167,   171,   175,   179,   183,   187,   191,   193,   197,
   199,   203,   205,   209,   213,   215,   219,   223,   227,   231,
   233,   237,   241,   243,   247,   251,   255,   257,   260,   263,
   266,   269,   271,   276,   281,   284,   287,   289,   290,   292,
   294,   298,   300,   302,   304
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    67,     0,
    53,    64,     0,    54,    59,    60,     0,    55,     0,    56,
     0,    55,    56,     0,    57,     0,    58,     0,     3,     0,
     6,     0,     8,     0,    46,     0,    45,     0,    29,     0,
    30,    61,    31,     0,    30,     1,     0,     8,     0,    62,
     0,     0,    63,     0,    62,    36,    63,     0,    54,    29,
     0,    54,    29,    34,    71,    35,     0,    32,    65,    72,
    33,     0,    66,     0,     0,    67,     0,    66,    67,     0,
    54,    68,    38,     0,    69,     0,    68,    36,    69,     0,
    70,     0,    70,    15,    42,     0,    70,    15,    43,     0,
    70,    15,    44,     0,    29,     0,    29,    34,    71,    35,
     0,    42,     0,     0,    73,     0,     0,    74,     0,    73,
    74,     0,    64,     0,    75,     0,    77,     0,    78,     0,
    79,     0,    76,    38,     0,    80,     0,     0,     5,    30,
    80,    31,    74,     0,     5,    30,    80,    31,    74,     4,
    74,     0,     9,    30,    80,    31,    74,     0,     7,    76,
    38,     0,    81,     0,    82,     0,    88,    15,    81,     0,
    88,    24,    81,     0,    88,    25,    81,     0,    88,    26,
    81,     0,    88,    27,    81,     0,    88,    28,    81,     0,
    83,     0,    82,    21,    83,     0,    84,     0,    83,    20,
    84,     0,    85,     0,    84,    16,    85,     0,    84,    17,
    85,     0,    86,     0,    85,    41,    86,     0,    85,    40,
    86,     0,    85,    19,    86,     0,    85,    18,    86,     0,
    87,     0,    86,    10,    87,     0,    86,    11,    87,     0,
    88,     0,    87,    12,    88,     0,    87,    13,    88,     0,
    87,    14,    88,     0,    89,     0,    11,    88,     0,    39,
    88,     0,    22,    88,     0,    23,    88,     0,    93,     0,
    89,    34,    80,    35,     0,    89,    30,    90,    31,     0,
    89,    22,     0,    89,    23,     0,    91,     0,     0,    92,
     0,    81,     0,    92,    36,    81,     0,    29,     0,    42,
     0,    43,     0,    30,    80,    31,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    35,    37,    38,    40,    41,    43,    45,    65,    66,    67,
    68,    69,    70,    72,    73,    74,    75,    77,    80,    81,
    83,    84,    85,    86,    87,    89,   102,   116,   118,   119,
   120,   121,   123,   124,   125,   127,   128,   129,   130,   136,
   144,   153,   154,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
   183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
   203,   204,   205,   206,   209,   210,   211,   212,   213,   214,
   215,   216,   217,   218,   219
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TPLUS","TMINUS","TMUL","TDIV",
"TMOD","TASSIGN","TEQUAL","TNOTEQU","TLESSE","TGREATE","TAND","TOR","TINC","TDEC",
"TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TIDENT","TLPAREN",
"TRPAREN","TLBRACE","TRBRACE","TLSQUARE","TRSQUARE","TCOMMA","TDOT","TSEMI",
"TNOT","TLESS","TGREAT","TINTNUM","TFLOATNUM","TSTRING","TCHAR","TFLOAT","TERROR",
"TLOWERTHANELSE","mini_c","translation_unit","external_dcl","function_def","function_header",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    52,    53,    54,    55,    55,
    56,    56,    57,    58,    58,    58,    58,    59,    60,    60,
    61,    61,    61,    62,    62,    63,    63,    64,    65,    65,
    66,    66,    67,    68,    68,    69,    69,    69,    69,    70,
    70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
    74,    74,    75,    76,    76,    77,    77,    78,    79,    80,
    81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
    83,    84,    84,    84,    85,    85,    85,    85,    85,    86,
    86,    86,    87,    87,    87,    87,    88,    88,    88,    88,
    88,    89,    89,    89,    89,    89,    90,    90,    91,    92,
    92,    93,    93,    93,    93
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     3,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
     1,     1,     0,     1,     3,     2,     5,     4,     1,     0,
     1,     2,     3,     1,     3,     1,     3,     3,     3,     1,
     4,     1,     0,     1,     0,     1,     2,     1,     1,     1,
     1,     1,     2,     1,     0,     5,     7,     5,     3,     1,
     1,     3,     3,     3,     3,     3,     3,     1,     3,     1,
     3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
     2,     1,     4,     4,     2,     2,     1,     0,     1,     1,
     3,     1,     1,     1,     3
};

static const short yydefact[] = {     0,
    13,    14,    15,    17,    16,     1,     2,     4,     0,     0,
     8,     9,    11,    12,     5,     3,    30,     6,    40,     0,
     0,    34,    36,    10,     0,    45,    29,    31,    43,     0,
     7,     0,    33,     0,    40,     0,    55,     0,     0,     0,
     0,   102,     0,     0,   103,   104,    48,     0,    44,    46,
    49,     0,    50,    51,    52,    54,    60,    61,    68,    70,
    72,    75,    80,    83,    87,    92,    32,    42,     0,    20,
    15,     0,     0,    22,    24,    35,    37,    38,    39,     0,
     0,     0,    88,    90,    91,     0,    89,    28,    47,    53,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
    96,    98,     0,    41,    26,    19,     0,     0,    59,     0,
   105,    69,    83,    71,    73,    74,    79,    78,    77,    76,
    81,    82,    84,    85,    86,    62,    63,    64,    65,    66,
    67,   100,     0,    97,    99,     0,    43,    25,    55,    55,
    94,     0,    93,     0,    56,    58,   101,    27,    55,    57,
     0,     0,     0
};

static const short yydefgoto[] = {   161,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    20,
    31,    73,    74,    75,    47,    26,    27,    15,    21,    22,
    23,    69,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
   143,   144,   145,    66
};

static const short yypact[] = {    24,
-32768,-32768,-32768,-32768,-32768,    24,-32768,-32768,   -19,    -3,
    24,-32768,-32768,-32768,-32768,-32768,    24,-32768,   -24,    11,
    -7,-32768,    37,-32768,    51,    74,    24,-32768,    42,     8,
-32768,    51,-32768,     5,    59,    65,   115,    68,   115,   115,
   115,-32768,   115,   115,-32768,-32768,-32768,    61,    74,-32768,
-32768,    70,-32768,-32768,-32768,-32768,-32768,    78,    94,     2,
    32,    77,    64,    18,    52,-32768,-32768,-32768,    80,-32768,
    87,    90,    89,    85,-32768,-32768,-32768,-32768,-32768,   115,
    86,   115,-32768,-32768,-32768,    96,-32768,-32768,-32768,-32768,
   115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
   115,   115,   115,   115,   115,   115,   115,   115,   115,-32768,
-32768,   115,   115,-32768,    91,-32768,    24,    97,-32768,   102,
-32768,    94,-32768,     2,    32,    32,    77,    77,    77,    77,
    64,    64,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   103,-32768,    95,   101,    42,-32768,   100,   100,
-32768,   115,-32768,   105,   131,-32768,-32768,-32768,   100,-32768,
   141,   146,-32768
};

static const short yypgoto[] = {-32768,
-32768,   142,-32768,-32768,   -15,-32768,   136,-32768,-32768,-32768,
-32768,-32768,-32768,    33,   140,-32768,-32768,   -10,-32768,   119,
-32768,     6,-32768,-32768,   -49,-32768,   118,-32768,-32768,-32768,
   -42,   -84,-32768,    69,    60,    -4,   -61,    -8,   -36,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		160


static const short yytable[] = {    89,
    86,    25,    83,    84,    85,   -18,    28,    87,    70,    29,
     1,    25,    17,     2,    72,    71,    67,    93,    94,   136,
   137,   138,   139,   140,   141,    19,     1,   142,    32,     2,
    33,     3,   104,   127,   128,   129,   130,   118,   -23,   120,
    30,   105,   106,   107,   108,   109,    77,    78,    79,    95,
    96,    34,     4,     5,   123,   123,   123,   123,   123,   123,
   123,   123,   123,   123,   133,   134,   135,   157,     4,     5,
   146,    97,    98,   110,   111,   101,   102,   103,    36,    35,
    37,   112,    38,    68,    39,   113,    99,   100,   125,   126,
   131,   132,    29,    88,    80,    40,    41,    82,    91,   155,
   156,    72,    42,    43,    36,    17,    37,    90,    38,   160,
    39,   -55,    44,    92,   114,    45,    46,   -21,   115,   116,
   117,    40,    41,   119,   147,    39,   121,   149,    42,    43,
   152,    17,   150,   151,   159,   153,    40,    41,    44,   158,
   162,    45,    46,    42,    43,   163,    24,    16,    18,   148,
    76,   124,   154,    44,    81,     0,    45,    46,     0,   122
};

static const short yycheck[] = {    49,
    43,    17,    39,    40,    41,    30,    17,    44,     1,    34,
     3,    27,    32,     6,    30,     8,    27,    16,    17,   104,
   105,   106,   107,   108,   109,    29,     3,   112,    36,     6,
    38,     8,    15,    95,    96,    97,    98,    80,    31,    82,
    30,    24,    25,    26,    27,    28,    42,    43,    44,    18,
    19,    15,    45,    46,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   152,    45,    46,
   113,    40,    41,    22,    23,    12,    13,    14,     5,    29,
     7,    30,     9,    42,    11,    34,    10,    11,    93,    94,
    99,   100,    34,    33,    30,    22,    23,    30,    21,   149,
   150,   117,    29,    30,     5,    32,     7,    38,     9,   159,
    11,    38,    39,    20,    35,    42,    43,    31,    29,    31,
    36,    22,    23,    38,    34,    11,    31,    31,    29,    30,
    36,    32,    31,    31,     4,    35,    22,    23,    39,    35,
     0,    42,    43,    29,    30,     0,    11,     6,     9,   117,
    32,    92,   147,    39,    37,    -1,    42,    43,    -1,    91
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

case 7:
#line 45 "parser.y"
{
																int func_id = saved_func_id;
																/* 반환형 기록 */
																update_sym_table(func_id, 0, current_type);
																/* const 여부 기록 */
																update_sym_table(func_id, 1, is_const);
																is_const = 0;
																/* 파라미터 개수 기록 */
																update_sym_table(func_id, 3, param_count);
																/* 엔티티 종류 = 1 (함수) */
																update_sym_table(func_id, 4, 1);
																/* 파라미터 타입들만 저장(이름은 param_ids 위치에서 나중에 출력) */
																if (param_count) {
																	update_sym_table_param(func_id, param_count, param_types, param_ids);
																}
																/* 파라미터 배열 리셋 */
																param_capacity = 0;
																param_count = 0;
															;
    break;}
case 13:
#line 70 "parser.y"
{is_const = 1;;
    break;}
case 14:
#line 72 "parser.y"
{current_type=0;;
    break;}
case 15:
#line 73 "parser.y"
{current_type=1;;
    break;}
case 16:
#line 74 "parser.y"
{current_type=2;;
    break;}
case 17:
#line 75 "parser.y"
{current_type=3;;
    break;}
case 18:
#line 77 "parser.y"
{
																saved_func_id = st_index;
															;
    break;}
case 20:
#line 81 "parser.y"
{ /* 오류가 났지만, 일단 함수로 간주 */ ;
    break;}
case 26:
#line 89 "parser.y"
{
																int param_st_index = st_index;
																/* 스칼라 파라미터 */
																/* current_type: 기본 타입, 0=scalar */
          														update_sym_table(param_st_index, 1, is_const);
          														update_sym_table(param_st_index, 0, current_type);
																is_const = 0;
          														update_sym_table(param_st_index, 2, 0);	/* 0 = scalar */
																update_sym_table(param_st_index, 4, 3);	/* 3 = param */
																param_types[param_count] = current_type;
																param_ids  [param_count] = param_st_index;
																param_count++;
      														;
    break;}
case 27:
#line 102 "parser.y"
{
																int param_st_index = st_index;
          														/* 배열 파라미터 */
																/* current_type: 기본 타입, 1=array */
          														update_sym_table(param_st_index, 1, is_const);
         														update_sym_table(param_st_index, 0, current_type);
																is_const = 0;
         														update_sym_table(param_st_index, 2, 1);	/* 1 = array */
																update_sym_table(param_st_index, 4, 3);	/* 3 = param */
																param_types[param_count] = current_type;
																param_ids  [param_count] = param_st_index;
																param_count++;
     														;
    break;}
case 39:
#line 130 "parser.y"
{
																	// 한번 더 확인
																	int var_id = st_index;
																	update_sym_table(var_id, 0, 3);  // 3 = char
																	update_sym_table(var_id, 2, 1);  // 1 = array
																;
    break;}
case 40:
#line 136 "parser.y"
{
																	int var_id = st_index;
																	update_sym_table(var_id, 0, current_type);
																	update_sym_table(var_id, 1, is_const);
																	is_const = 0;
																	update_sym_table(var_id, 2, 0); /* 0 = scalar */
																	update_sym_table(var_id, 4, 2); /* 2 = variable */
																;
    break;}
case 41:
#line 144 "parser.y"
{
																	int var_id = st_index;
																	update_sym_table(var_id, 0, current_type);
																	update_sym_table(var_id, 1, is_const);
																	is_const = 0;
																	update_sym_table(var_id, 2, 1); /* 1 = array */
																	update_sym_table(var_id, 4, 2); /* 2 = variable */
																;
    break;}
case 94:
#line 206 "parser.y"
{
																	update_sym_table(saved_func_id, 4, 1);
																;
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
#line 220 "parser.y"

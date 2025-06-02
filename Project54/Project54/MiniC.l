%{
/*lex source for Mini C*/
#include <stdio.h>
#include <stdlib.h>
#include "parser_tab.h"
int process_sym_table(char*);
void print_error(int errno);
extern int line_num;
int st_index = 0;
%}
%%
"!"							return(TNOT);
"+"							return(TPLUS);
"-"							return(TMINUS);
"*"							return(TMUL);
"/"							return(TDIV);
"%"							return(TMOD);
"const"							return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"							return(TINT);
"char"							return(TCHAR);
"float"							return(TFLOAT);
"return"							return(TRETURN);
"void"							return(TVOID);
"while"							return(TWHILE);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<"							return(TLESS);
">"							return(TGREAT);
"<="							return(TLESSE);
">="							return(TGREATE);
"&&"							return(TAND);
"||"							return(TOR);
"++"							return(TINC);
"--"							return(TDEC);
"="							return(TASSIGN);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
[0-9]+[A-Za-z0-9_]+					print_error(1);
[A-Za-z_][A-Za-z0-9_]*					{if(yyleng>15) { print_error(2); return(TERROR); }
								else {st_index = process_sym_table(yytext);
								return(TIDENT);}}
[+-]?([1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?)		return(TINTNUM);
[+-]?([0-9]+"."[0-9]+(e[+-]?[0-9]+)?)			return(TFLOATNUM);
\"([^\"\\]|\\.)*\"						return(TSTRING);
"/*"([^*]|\*+[^*/])*\*\**"/"					for(int i=0;i<yyleng;i++) { if(yytext[i] == '\n') line_num++; }
"//".*								;
[ \t] 							;
[\n]							line_num++;
"("							return TLPAREN;
")"							return TRPAREN;
"{"							return TLBRACE;
"}"							return TRBRACE;
"["							return TLSQUARE;
"]"							return TRSQUARE;
","							return TCOMMA;
"."							return TDOT;
";"							return TSEMI;
.							print_error(3);
%%

int yywrap() {
	return 1;
}
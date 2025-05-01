%{
/*lex source for Mini C*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern int process_sym_table(char *);
extern void print_error(int err_num, int yylineno, char* token);
extern int sym_table_index;
extern int duplicate_flag;
%}
%option yylineno

%%
"const"							return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"                           return(TINT);
"float"                         return(TFLOAT);
"char"                          return(TCHAR);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"							return(TWHILE);
"/*"([^*]|\*+[^*/])*\**"*/"		;
"//".*							;
"+"                             return(TPLUS);
"-"                             return(TMINUS);
"*"                             return(TMUL);
"/"                             return(TDIV);
"%"                             return(TMOD);
"="                             return(TASSIGN);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<="							return(TLESSE);
">="							return(TGREATE);
"&&"							return(TAND);
"||"							return(TOR);
"++"							return(TINC);
"--"							return(TDEC);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
[0-9]+[A-Za-z0-9_]+				{
                                    print_error(4, yylineno, yytext);
                                    return(TERROR);
                                }
[+\-]?[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TINTNUM);
[+\-]?[0-9]+\.[0-9]+([eE][+\-]?[0-9]+)?         return(TFLOATNUM);
[A-Za-z_][A-Za-z0-9_]*			{
                                    if (yyleng > 15) {
                                        print_error(1, yylineno, yytext);
                                        return(TERROR);
                                    }
                                    int result = process_sym_table(yytext);
                                    if (result == -1) { // overflow
                                        print_error(3, yylineno, yytext);
                                        return(TERROR);
                                    }
                                    else if (result == 1) { // duplicated
                                        duplicate_flag = 1;
                                    }
                                    return(TIDENT);
                                }
                                return(TIDENT);
\"([^\"\\]|\\.)*\"              return(TSTRING);
"\."                            return(TDOT);
","                             return(TCOMMA);
";"                             return(TSEMI);
"("                             return(TLPAREN);
")"                             return(TRPAREN);
"{"                             return(TLBRACE);
"}"                             return(TRBRACE);
"["     return(TLSQUARE);
"]"     return(TRSQUARE);
[ \t\n] 						;
.							{
                                print_error(2, yylineno, yytext);
                                return TERROR;
                            }
%%

int yywrap() {
	return 1;
}
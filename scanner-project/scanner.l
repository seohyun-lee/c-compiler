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
%option     yylineno

%%
"const"							return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"                           return(TINT);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"							return(TWHILE);
"float"                         return(TFLOAT);
"char"                          return(TCHAR);
"/*"([^*]|\*+[^*/])*\**"*/"		;
"//".*							;
"+"                             return(TPLUS);
"-"                             return(TMINUS);
"*"                             return(TMUL);
"/"                             return(TDIV);
"%"                             return(TMOD);
"="                             return(TASSIGN);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
"!"                             return(TNOT);
"&&"							return(TAND);
"||"							return(TOR);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<"							    return(TLESS);
">"							    return(TGREAT);
"<="							return(TLESSE);
">="							return(TGREATE);
"++"							return(TINC);
"--"							return(TDEC);

[+\-]?[1-9][0-9]* {
    return TINTNUM;
}
[+\-]?0[0-7]* {
    return TINTNUM;
}
[+\-]?0[8-9][0-9]* {
    print_error(4, yylineno, yytext);
    return TERROR;
}
[+\-]?0[xX][0-9A-Fa-f]+ {
    return TINTNUM;
}
[+\-]?[0-9]+\.[0-9]+([eE][+\-]?[0-9]+)? {
    return TFLOATNUM;
}
[0-9]+[A-Za-z_][A-Za-z0-9_]* {
    print_error(4, yylineno, yytext);
    return TERROR;
}

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
","                             return(TCOMMA);
";"                             return(TSEMI);
\.                            return(TDOT);
"("                             return(TLPAREN);
")"                             return(TRPAREN);
"{"                             return(TLBRACE);
"}"                             return(TRBRACE);
"["                             return(TLSQUARE);
"]"                             return(TRSQUARE);
[ \t\n] 						;
.							{
                                print_error(2, yylineno, yytext);
                                return TERROR;
                            }
%%

int yywrap() {
	return 1;
}
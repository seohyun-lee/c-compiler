%{
#include <stdio.h>
#include <stdlib.h>
#include "cal.tab.h"
%}
%%
[a-z]*  { return NAME; }
[0-9]*  { yylval = atoi(yytext); return NUMBER; }
[ \t];  ;
"\n"    |
.       return yytext[0];
%%
int yywrap()
{
    return 1;
}
%{
#include <stdio.h>
#include <stdlib.h>
#include "cal_tab.h"
%}
%%
[ \t]           ;
[0-9]+          {yylval = atoi(yytext); return NUMBER;}
"mod"           return MOD;
"div"           return DIV;
"sqr"           return SQR;
\n              |
.               return yytext[0]; 
%%
int yywrap()
{   
    printf("    END of LEX\n");
    return 1;
}
%{
      	/* LEX source for calculator program */
#include <stdio.h>
#include <stdlib.h>
#include "cal2_tab.h"
%}
%%
[a-z]* 	{ return NAME; }
[0-9]+    	{ yylval = atoi(yytext); return NUMBER; }
[ \t]     	;
\n	|
.     	return yytext[0];
%%
int yywrap()
{
	printf(" END of LEX\n");
	return 1;
}
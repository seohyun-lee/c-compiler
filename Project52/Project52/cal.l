%{
      	/* LEX source for calculator program */
#include <stdio.h>
#include <stdlib.h>

enum tnumber { NUMBER=258, DIV, MOD, SQR};
extern int yylval;
%}
%%
[ \t]     	; /* ignore blanks and tabs */
[0-9]+    	{yylval = atoi(yytext); return NUMBER;}
"mod"     	return MOD;
"div"     	return DIV;
"sqr"     	return SQR;
\n 		|  
.     		return yytext[0];  /* return everything else */
%%
int yywrap()
{
	printf(" END of LEX\n");
	return 1;
}
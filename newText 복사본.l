%{
#include <stdio.h>
#include <stdlib.h>
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*	{
			printf("%s (%lu)\n", yytext, yyleng);
			}
%%
int main()
{
	while(yylex())
	{
	}
	return 0;
}

int yywrap()
{
	return 0;
}

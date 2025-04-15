%{
#include <stdio.h>
#include <stdlib.h>
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
"{"				printf("begin");
"}"				printf("end");
int				printf("integer");
[a-zA-Z_][a-zA-Z0-9_]*		ECHO;
.				printf("%s", yytext);
%%

int main()
{
	printf("   Start of Lex\n");
	while (yylex()) {
	}
}

int yywrap()
{
	printf("   End of Lex \n");
	return 1;
}
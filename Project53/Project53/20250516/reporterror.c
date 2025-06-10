#include <stdio.h>
#include <stdlib.h>

void yyerror(char* s)
{
	printf("%s\n", s);
}
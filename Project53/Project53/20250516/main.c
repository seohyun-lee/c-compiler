#include <stdio.h>
#include <stdlib.h>
extern int yyparse();

void main()
{
	printf("start of parser\n");
	yyparse();
	printf("end 	of parser\n");
}

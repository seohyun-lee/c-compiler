#include <stdio.h>
#include <stdlib.h>
extern int yyparse()

void yyerror(char* s)
{
    printf("%s\n", s);
}
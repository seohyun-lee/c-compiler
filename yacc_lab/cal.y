%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int yylex(void);
int yyerror(const char *s);
%}
%token NAME NUMBER UMINUS
%%
stat    : stat '\n'
        | lambda
        | NAME '=' expr '\n'
        | expr '\n' { printf("=%d\n", $1); }
        ;
expr    : expr '+' expr     { $$ = $1 + $3; }
        | expr '-' expr     { $$ = $1 - $3; }
        | expr '*' expr     { $$ = $1 * $3; }
        | expr '/' expr     { if ($3 == 0) yyerror ("divide by zero"); else $$ = $1 / $3;}
        | '-' expr %prec UMINUS         { $$ = -$2; }
        | NUMBER
        ;
lambda:
        ;
%%

int yyerror(const char* s)
{
    printf("%s\n", s);
    return -1;
}

int main()
{
    return yyparse();
}
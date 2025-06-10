%{
#include <stdio.h>
#include <ctype.h>
int yyerror(char *s);
extern int yylex();
%}
%token NUMBER DIV MOD SQR
%left '+' '-'
%left '*' DIV MOD
%left SQR
%%
comm :  comm '\n'
        | lambda
        | comm expr '\n' {printf("%d\n", $2);}
        | comm error '\n' {yyerrok; printf(" Try again \n");}
        ;
expr:   '(' expr ')' {$$ = $2;}
        | expr '+' expr {$$ = $1 + $3;}
        | expr '-' expr {$$ = $1 - $3;}
        | expr '*' expr {$$ = $1 * $3;}
        | expr DIV expr {$$ = $1 / $3;}
        | expr MOD expr {$$ = $1 % $3;}
        | SQR expr {$$ = $2 * $2;}
        | NUMBER {$$ = $1;}
        ;
primary_exp;: TIDENT    {sematic(95);}
lambda: /* empty */
;
%%
int yyerror(char *s)
{
    if(s != NULL)
        printf("%s\n",s);
    return -1;
}

int main()
{
    yyparse();
}
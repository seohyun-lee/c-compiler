%{
/* YACC source for calculator program */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

int yyerror(const char *s);
extern int yyparse();
%}
%token NAME NUMBER
%left	'-' '+'
%left	'*' '/'
%nonassoc	UMINUS
%%
stat	: stat '\n'
	| lambda
	| NAME '=' expr '\n' { printf("=%d\n", $3); }
	| expr '\n' { printf("=%d\n", $1); }
	;
expr 	: expr '+' expr 	{$$ = $1 + $3;}
	| expr '-' expr 	{$$ = $1 - $3;}
	| expr '*' expr 	{$$ = $1 * $3;}
	| expr '/' expr 	{ if ($3==0) yyerror("divide by zero");
			else $$ = $1 / $3;}
	| '-' expr %prec UMINUS     	{$$ = -$2;}
	| NUMBER
	;
lambda	:
	;
%%

int yyerror(const char *s)
{
	if(s != NULL)
		printf("%s\n",s);
	return -1;
}
void main()
{
	yyparse();
}

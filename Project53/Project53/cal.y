%{
/* YACC source for calculator program */
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
int yyerror(char *s);
extern yylex();

%}
%token  NUMBER  DIV  MOD  SQR
%left  '+'  '-'
%left  '*'  DIV  MOD
%left  SQR
%%
comm : 	comm '\n'
	| lambda
	| comm   expr    '\n' 	{printf("%d\n", $2);}
	| comm   error  '\n'	{yyerrok; printf(" Try again \n");}
	;
expr : 	'(' expr ')'  		{$$ = $2;}
	| expr  '+'  expr 	{$$ = $1 + $3;}
	| expr  '-'  expr 	{$$ = $1 - $3;}
	| expr  '*'  expr 	{$$ = $1 * $3;}
	| expr MOD expr 	{$$ = $1 % $3;}
	| SQR  expr     	{$$ = $2 * $2;}
	| NUMBER		{$$ = $1;}
	;
lambda: 	/* empty */
	;
%%

int yyerror(char *s)
{
	if(s != NULL)
		printf("%s\n",s);
	return -1;
}
void main()
{
	yyparse();
}

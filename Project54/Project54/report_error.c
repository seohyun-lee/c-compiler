#include <stdio.h>
#include <stdlib.h>

extern char* yytext;

void print_error(int err_num)
{
	switch (err_num)
	{
	case 1:
		/* start with digit */
		printf("Error - Start with digit (%s)\n", yytext);
		break;
	case 2:
		printf("Error - long identifier (%s)\n", yytext);
		break;
	case 3:
		printf("Error - Invalid character (%s)\n", yytext);
		break;
	default:
		printf("Error - Unknown\n");
		break;
	}

}

void yyerror(const char* s)
{
	printf("%s\n", s);
}
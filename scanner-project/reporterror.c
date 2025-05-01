#include <stdio.h>
#include <stdlib.h>

void print_error(int err_num, int yylineno, char *token)
{
	switch (err_num)
	{
		case 1:
			/* too long identifier */
			printf("%d\tERROR\t\t\ttoo long identifier (%s)\n", yylineno, token);
			break;
		case 2:
			/* illegal identifier */
			printf("%d\tERROR\t\t\tillegal identifier (%s)\n", yylineno, token);
			break;
		case 3:
			/* overflow */
			printf("%d\tERROR\t\t\toverflow\n", yylineno);
			break;
		default:
			printf("%d\tERROR\t\t\tunknown Error\n", yylineno);
			break;
	}
}

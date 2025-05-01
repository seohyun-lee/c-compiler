// reporterror.c: ���� �޽����� ����ϴ� �Լ��� ���ǵ� c ����
#include <stdio.h>

// ���� �޽����� ����ϴ� �Լ�
void print_error(int err_num, int yylineno, char *token)
{
	switch (err_num)
	{
		case 1:
			/* too long identifier */
			printf("%d\tERROR\t\t\t\tToo long identifier (%s)\n", yylineno, token);
			break;
		case 2:
			/* invalid character */
			printf("%d\tERROR\t\t\t\tInvalid character (%s)\n", yylineno, token);
			break;
		case 3:
			/* overflow */
			printf("%d\tERROR\t\t\t\tOverflow\n", yylineno);
			break;
		case 4:
			/* start with digit */
			printf("%d\tERROR\t\t\t\tStart with digit (%s)\n", yylineno, token);
			break;
		default:
			printf("%d\tERROR\t\t\t\tunknown Error\n", yylineno);
			break;
	}
}

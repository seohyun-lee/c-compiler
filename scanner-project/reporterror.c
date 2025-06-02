// reporterror.c: 에러 메시지를 출력하는 함수가 정의된 c 파일
#include <stdio.h>

// 에러 메시지를 출력하는 함수
void print_error(int err_num, int yylineno, char *token)
{
	switch (err_num)
	{
		case 1:
			/* too long identifier */
			printf("%d\tERROR - long identifier (%s)\n", yylineno, token);
			break;
		case 2:
			/* invalid character */
			printf("%d\tERROR - Invalid character (%s)\n", yylineno, token);
			break;
		case 3:
			/* overflow */
			printf("%d\tERROR - Overflow\n", yylineno);
			break;
		case 4:
			/* start with digit */
			printf("%d\tERROR - Start with digit (%s)\n", yylineno, token);
			break;
		default:
			printf("%d\tERROR - Unknown Error\n", yylineno);
			break;
	}
}

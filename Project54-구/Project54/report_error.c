// report_error.c: ���� ó�� �� ���� ����� ��� c ����
#include <stdio.h>
#include <stdlib.h>

extern char* yytext;

// �־��� ���� ��ȣ(err_num)�� ���� ������ ���� �޽����� ����ϴ� �Լ�
void print_error(int err_num)
{
	switch (err_num)
	{
		case 1:
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

// yacc/parser���� �߰ߵ� ����(syntax) ������ ����ϴ� �Լ�. �Ķ���ͷ� ���޹��� ���ڿ��� �״�� ���
void yyerror(const char* s)
{
	printf("%s\n", s);
}
// report_error.c: 에러 처리 및 보고 모듈이 담긴 c 파일
#include <stdio.h>
#include <stdlib.h>

extern char* yytext;

// 주어진 에러 번호(err_num)에 따라 적절한 에러 메시지를 출력하는 함수
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

// yacc/parser에서 발견된 구문(syntax) 오류를 출력하는 함수. 파라미터로 전달받은 문자열을 그대로 출력
void yyerror(const char* s)
{
	printf("%s\n", s);
}
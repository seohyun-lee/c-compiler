//  main.c: 정상적인 경우의 출력을 진행하는 c 파일
#include <stdio.h>
#include <stdlib.h>

// 외부 참조 변수 및 함수 프로토타입 선언
extern yyparse();
extern char* yytext;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int st_index;
extern int sym_table_index;

// 전역 변수 정의
int line_num = 1;

// 메인 함수 (심볼테이블 초기화, yyparse, 심볼테이블 출력, 해시테이블 출력 함수 호출)
void main()
{
	init_sym_table();

	yyparse();
	
	print_sym_table();
	print_hash_table();
}
// main.c: 정상적인 경우의 출력을 진행하는 c 파일
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"

// 외부 참조 변수 및 함수 프로토타입 선언
extern int yylex(void);
extern char *yytext;
extern int yylval;
extern int yylineno;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int sym_table_index;

// 중복 식별자 발견 여부를 나타내는 전역 플래그
int duplicate_flag = 0;

// 열거형인 토큰 타입명을 문자열로 매핑하기 위한 2차원 문자 배열
const char *token_names[] = {
    [TEOF] = "TEOF",
    [TCONST] = "TCONST",
    [TELSE] = "TELSE",
    [TIF] = "TIF",
    [TINT] = "TINT",
    [TFLOAT] = "TFLOAT",
    [TCHAR] = "TCHAR",
    [TRETURN] = "TRETURN",
    [TVOID] = "TVOID",
    [TWHILE] = "TWHILE",

    [TPLUS] = "TPLUS",
    [TMINUS] = "TMINUS",
    [TMUL] = "TMUL",
    [TDIV] = "TDIV",
    [TMOD] = "TMOD",

    [TASSIGN] = "TASSIGN",
    [TEQUAL] = "TEQUAL",
    [TNOTEQU] = "TNOTEQU",
    [TLESS] = "TLESS",
    [TGREAT] = "TGREAT",
    [TLESSE] = "TLESSE",
    [TGREATE] = "TGREATE",

    [TNOT] = "TNOT",
    [TAND] = "TAND",
    [TOR] = "TOR",
    [TINC] = "TINC",
    [TDEC] = "TDEC",

    [TADDASSIGN] = "TADDASSIGN",
    [TSUBASSIGN] = "TSUBASSIGN",
    [TMULASSIGN] = "TMULASSIGN",
    [TDIVASSIGN] = "TDIVASSIGN",
    [TMODASSIGN] = "TMODASSIGN",

    [TIDENT] = "TIDENT",
    [TINTNUM] = "TINTNUM",
    [TFLOATNUM] = "TFLOATNUM",
    [TSTRING] = "TSTRING",

    [TDOT] = "TDOT",
    [TCOMMA] = "TCOMMA",
    [TSEMI] = "TSEMI",
    [TLPAREN] = "TLPAREN",
    [TRPAREN] = "TRPAREN",
    [TLSQUARE] = "TLSQUARE",
    [TRSQUARE] = "TRSQUARE",
    [TLBRACE] = "TLBRACE",
    [TRBRACE] = "TRBRACE",

    [TERROR] = "TERROR"
};

// 메인 함수
void main(void)
{
	enum tnumber tn;

	init_sym_table(); // 심볼 테이블 초기화
	printf("Line\tToken type\tST-index\tToken\n");

	while((tn=yylex())!=TEOF) {
		if (tn == TERROR) continue; // tn이 에러인 경우는 lex에서 호출해 출력, main에서는 출력을 진행하지 않음
        const char *name = token_names[tn]; // 토큰 타입명을 출력하기 위해 문자열을 획득
        const char *tabs = (strlen(name) < 8) ? "\t\t" : "\t"; // 토큰 타입명 길이에 따라 탭의 갯수를 고려함
		char *suffix = duplicate_flag ? " (already exists)" : ""; // 중복인 경우 출력할 때도 이미 존재하는 식별자라는 것을 표시하고자 하였음
		switch(tn){ 
			case TIDENT:
				printf("%d\t%s%s%d\t\t%s%s\n", yylineno, name, tabs, sym_table_index, yytext, suffix);
				duplicate_flag = 0;
				break;
			default:
				printf("%d\t%s%s\t\t%s\n", yylineno, name, tabs, yytext);
				
		}
	}
	print_sym_table(); // 심볼 테이블 출력
	print_hash_table(); // 해시 테이블 출력
}
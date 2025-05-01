// main.c: �������� ����� ����� �����ϴ� c ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"

// �ܺ� ���� ���� �� �Լ� ������Ÿ�� ����
extern int yylex(void);
extern char *yytext;
extern int yylval;
extern int yylineno;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int sym_table_index;

// �ߺ� �ĺ��� �߰� ���θ� ��Ÿ���� ���� �÷���
int duplicate_flag = 0;

// �������� ��ū Ÿ�Ը��� ���ڿ��� �����ϱ� ���� 2���� ���� �迭
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

// ���� �Լ�
void main(void)
{
	enum tnumber tn;

	init_sym_table(); // �ɺ� ���̺� �ʱ�ȭ
	printf("Line\tToken type\tST-index\tToken\n");

	while((tn=yylex())!=TEOF) {
		if (tn == TERROR) continue; // tn�� ������ ���� lex���� ȣ���� ���, main������ ����� �������� ����
        const char *name = token_names[tn]; // ��ū Ÿ�Ը��� ����ϱ� ���� ���ڿ��� ȹ��
        const char *tabs = (strlen(name) < 8) ? "\t\t" : "\t"; // ��ū Ÿ�Ը� ���̿� ���� ���� ������ �����
		char *suffix = duplicate_flag ? " (already exists)" : ""; // �ߺ��� ��� ����� ���� �̹� �����ϴ� �ĺ��ڶ�� ���� ǥ���ϰ��� �Ͽ���
		switch(tn){ 
			case TIDENT:
				printf("%d\t%s%s%d\t\t%s%s\n", yylineno, name, tabs, sym_table_index, yytext, suffix);
				duplicate_flag = 0;
				break;
			default:
				printf("%d\t%s%s\t\t%s\n", yylineno, name, tabs, yytext);
				
		}
	}
	print_sym_table(); // �ɺ� ���̺� ���
	print_hash_table(); // �ؽ� ���̺� ���
}
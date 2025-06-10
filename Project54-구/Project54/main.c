//  main.c: �������� ����� ����� �����ϴ� c ����
#include <stdio.h>
#include <stdlib.h>

// �ܺ� ���� ���� �� �Լ� ������Ÿ�� ����
extern yyparse();
extern char* yytext;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int st_index;
extern int sym_table_index;

// ���� ���� ����
int line_num = 1;

// ���� �Լ� (�ɺ����̺� �ʱ�ȭ, yyparse, �ɺ����̺� ���, �ؽ����̺� ��� �Լ� ȣ��)
void main()
{
	init_sym_table();

	yyparse();
	
	print_sym_table();
	print_hash_table();
}
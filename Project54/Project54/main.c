#include <stdio.h>
#include <stdlib.h>

extern yyparse();
extern char* yytext;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);

int line_num = 1;
extern int st_index;
extern int sym_table_index;

void main()
{
	init_sym_table();

	yyparse();
	
	print_sym_table();
	print_hash_table();
}
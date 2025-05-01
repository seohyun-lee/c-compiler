#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"

extern int yylex();
extern char *yytext;
extern int yylval;
extern int yylineno;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int sym_table_index;

int duplicate_flag = 0;

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
    [TLESSE] = "TLESSE",
    [TGREATE] = "TGREATE",

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
    [TRSQUARE] = "TRSQUARE",
    [TLSQUARE] = "TLSQUARE",
    [TLBRACE] = "TLBRACE",
    [TRBRACE] = "TRBRACE",

    [TERROR] = "TERROR"
};

int main(void)
{
	enum tnumber tn;

	init_sym_table();
	printf("Line\tToken type\tST-index\tToken\n");

	while((tn=yylex())!=TEOF) {
		if (tn == TERROR) continue;
        const char *name = token_names[tn];
        const char *tabs = (strlen(name) < 8) ? "\t\t" : "\t";
		char *suffix = duplicate_flag ? " (already exists)" : "";
		switch(tn){ 
			case TIDENT:
				printf("%d\t%s%s%d\t\t%s%s\n", yylineno, name, tabs, sym_table_index, yytext, suffix);
				duplicate_flag = 0;
				break;
			default:
				printf("%d\t%s%s\t\t%s\n", yylineno, name, tabs, yytext);
				
		}
	}
	print_sym_table();
	print_hash_table();
}
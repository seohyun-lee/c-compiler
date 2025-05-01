#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern int yylex();
extern char *yytext;
extern int yylval;
extern int yylineno;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);
extern int sym_table_index;

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
		switch(tn){ 
			case TIDENT:
				printf("%d\t%s\t\t%d\t%s\n", yylineno, token_names[tn], sym_table_index, yytext);
				break;
			default:
				printf("%d\t%s\t\t\t%s\n", yylineno, token_names[tn], yytext);
				
		}
				// switch(tn){
			// case TCONST: print_token(yylineno, TCONST, sym_table_index, yytext); break;
			// case TELSE: printf("else\n"); break;
			// case TIF: printf("if\n"); break;
			// case TINT: printf("int\n"); break;
			// case TRETURN: printf("return\n"); break;
			// case TVOID: printf("void\n"); break;
			// case TWHILE: printf("while\n"); break;
			// case TEQUAL: printf("==\n"); break;
			// case TNOTEQU: printf("!=\n"); break;
			// case TLESSE: printf("<=\n"); break;
			// case TGREATE: printf(">=\n"); break;
			// case TAND: printf("&&\n"); break;
			// case TOR: printf("||\n"); break;
			// case TINC: printf("++\n"); break;
			// case TDEC: printf("--\n"); break;
			// case TADDASSIGN: printf("+=\n"); break;
			// case TSUBASSIGN: printf("-=\n"); break;
			// case TMULASSIGN: printf("*=\n"); break;
			// case TDIVASSIGN: printf("/=\n"); break;
			// case TMODASSIGN: printf("%%=\n"); break;
			// default: printf("%s\n", yytext); break;
		// }
	}
	// print_sym_table();
	print_hash_table();
}
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern yylex();
extern char* yytext;
extern void init_sym_table(void);
extern void print_sym_table(void);
extern void print_hash_table(void);

int line_num = 1;
extern int st_index;
extern int sym_table_index;

void main()
{
	enum tnumber tn;  // token number

	init_sym_table();

	printf("Line\tToken type\tST-index\tToken\n");
	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST: printf("%d\tTCONST\t\t\t\tconst\n", line_num);  break;
		case TELSE: printf("%d\tTELSE\t\t\t\telse\n", line_num);  break;
		case TIF: printf("%d\tTIF\t\t\t\tif\n", line_num);  break;
		case TINT: printf("%d\tTINT\t\t\t\tint\n", line_num);  break;
		case TRETURN: printf("%d\tTRETURN\t\t\t\treturn\n", line_num);  break;
		case TVOID: printf("%d\tTVOID\t\t\t\tvoid\n", line_num);  break;
		case TWHILE: printf("%d\tTWHILE\t\t\t\twhile\n", line_num);  break;
		case TEQUAL: printf("%d\tTEQUAL\t\t\t\t==\n", line_num);  break;
		case TNOTEQU: printf("%d\tTNOTEQU\t\t\t\t!=\n", line_num);  break;
		case TLESSE: printf("%d\tTLESSE\t\t\t\t<=\n", line_num);  break;
		case TGREATE: printf("%d\tTGREATE\t\t\t\t>=\n", line_num);  break;
		case TAND: printf("%d\tTAND\t\t\t\t&&\n", line_num);  break;
		case TOR: printf("%d\tTOR\t\t\t\t||\n", line_num);  break;
		case TINC: printf("%d\tTINC\t\t\t\t++\n", line_num);  break;
		case TDEC: printf("%d\tTDEC\t\t\t\t--\n", line_num);  break;
		case TADDASSIGN: printf("%d\tTADDASSIGN\t\t\t\t+=\n", line_num);  break;
		case TSUBASSIGN: printf("%d\tTSUBASSIGN\t\t\t\t-=\n", line_num);  break;
		case TMULASSIGN: printf("%d\tTMULASSIGN\t\t\t\t*=\n", line_num);  break;
		case TDIVASSIGN: printf("%d\tTDIVASSIGN\t\t\t\t/=\n", line_num);  break;
		case TMODASSIGN: printf("%d\tTMODASSIGN\t\t\t\t%=\n", line_num);  break;
		case TIDENT: printf("%d\tTIDENT\t\t%d\t\t%s %s\n", line_num, st_index, yytext, st_index < sym_table_index ? "(already exists)" : "");  break;
		case TPLUS: printf("%d\tTPLUS\t\t\t\t+\n", line_num); break;
		case TMINUS: printf("%d\tTMINUS\t\t\t\t-\n", line_num); break;
		case TMUL: printf("%d\tTMUL\t\t\t\t*\n", line_num); break;
		case TDIV: printf("%d\tTDIV\t\t\t\t/\n", line_num); break;
		case TMOD: printf("%d\tTMOD\t\t\t\t%\n", line_num); break;
		case TNOT: printf("%d\tTNOT\t\t\t\t!\n", line_num); break;
		case TLESS: printf("%d\tTLESS\t\t\t\t<\n", line_num); break;
		case TGREAT: printf("%d\tTGREAT\t\t\t\t>\n", line_num); break;
		case TINTNUM: printf("%d\tTINTNUM\t\t\t\t%s\n", line_num, yytext);  break;
		case TFLOATNUM:printf("%d\tTFLOATNUM\t\t\t%s\n", line_num, yytext);  break;
		case TSTRING: printf("%d\tTSTRING\t\t\t\t%s\n", line_num, yytext); break;
		case TLPAREN: printf("%d\tTLPAREN\t\t\t\t(\n", line_num); break;
		case TRPAREN: printf("%d\tTRPAREN\t\t\t\t)\n", line_num); break;
		case TLBRACE: printf("%d\tTLBRACE\t\t\t\t{\n", line_num); break;
		case TRBRACE: printf("%d\tTRBRACE\t\t\t\t}\n", line_num); break;
		case TLSQUARE: printf("%d\tTLSQUARE\t\t\t\t[\n", line_num); break;
		case TRSQUARE: printf("%d\tTRSQUARE\t\t\t\t]\n", line_num); break;
		case TCOMMA: printf("%d\tTCOMMA\t\t\t\t,\n", line_num); break;
		case TDOT: printf("%d\tTDOT\t\t\t\t.\n", line_num); break;
		case TSEMI: printf("%d\tTSEMI\t\t\t\t;\n", line_num); break;

		case TFLOAT: printf("%d\tTFLOAT\t\t\t\tfloat\n", line_num); break;
		case TCHAR: printf("%d\tTCHAR\t\t\t\tchar\n", line_num); break;
		case TASSIGN: printf("%d\tTASSIGN\t\t\t\t=\n", line_num); break;

		case TERROR: break;
		default: printf("%s\n", yytext); break;
		}
	}

	print_sym_table();
	print_hash_table();
}

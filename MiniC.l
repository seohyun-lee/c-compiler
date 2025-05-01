%{
/*lex source for Mini C*/
#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, 
				TEQUAL, TNOTEQU, TLESSE, TGREATE, TAND, TOR, TINC, TDEC, 
				TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER };
%}
%%
"const"							return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"							return(TINT);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"							return(TWHILE);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<="							return(TLESSE);
">="							return(TGREATE);
"&&"							return(TAND);
"||"							return(TOR);
"++"							return(TINC);
"--"							return(TDEC);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]*				return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*"			;
"//".*							;
[ \t\n] 						;
.							return(yytext[0]);
%%

void main()
{
	enum tnumber tn;
	printf("  Start of Lex\n");
	while((tn=yylex())!=TEOF) {
		switch(tn){
			case TCONST: printf("const\n"); break;
			case TELSE: printf("else\n"); break;
			case TIF: printf("if\n"); break;
			case TINT: printf("int\n"); break;
			case TRETURN: printf("return\n"); break;
			case TVOID: printf("void\n"); break;
			case TWHILE: printf("while\n"); break;
			case TEQUAL: printf("==\n"); break;
			case TNOTEQU: printf("!=\n"); break;
			case TLESSE: printf("<=\n"); break;
			case TGREATE: printf(">=\n"); break;
			case TAND: printf("&&\n"); break;
			case TOR: printf("||\n"); break;
			case TINC: printf("++\n"); break;
			case TDEC: printf("--\n"); break;
			case TADDASSIGN: printf("+=\n"); break;
			case TSUBASSIGN: printf("-=\n"); break;
			case TMULASSIGN: printf("*=\n"); break;
			case TDIVASSIGN: printf("/=\n"); break;
			case TMODASSIGN: printf("%=\n"); break;
			case TIDENT: printf("identifier (%s)\n", yytext); break;
			case TNUMBER: printf("number (%s)\n", yytext); break;
			default: printf("%s", yytext); break;
		}
	}
}

int yywrap() {
	return 1;
}
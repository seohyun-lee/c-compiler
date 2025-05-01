%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TINTEGER, TIDEN, TNUM, TASSIGN, TADD, TSEMI, TDOT, TBEGIN, TEND, TERROR};
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
"{"				return(TBEGIN);
"}"				return(TEND);
int				return(TINTEGER);
{letter}({letter}|{digit})*	return(TIDEN);
":="				return(TASSIGN);
"+"				return(TADD);
{digit}+			return(TNUM);
";"				return(TSEMI);
\.				return(TDOT);
[ \t\n]				;
.				return(TERROR);
%%

int main()
{
	enum tnumber tn;  // token number
	printf("  Start of Lex\n");
	while  ((tn = yylex()) != TEOF) {
		switch (tn) {
			case TBEGIN  : printf("begin");  break;
			case TEND    : printf("end"); break;
			case TINTEGER: printf("integer"); break;
			default: printf("%s", yytext); break;
		}
	}
}

int yywrap()
{
	printf("   End of Lex \n");
	return 1;
}
%{
/*lex source for assignment 2. Scanner*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern int process_sym_table(char *);
extern void print_error(int err_num, int yylineno, char* token);
extern int sym_table_index;
extern int duplicate_flag;
%}
%option     yylineno

%%
"const"							return(TCONST);
"else"							return(TELSE);
"if"							return(TIF);
"int"                           return(TINT);
"return"						return(TRETURN);
"void"							return(TVOID);
"while"							return(TWHILE);
"float"                         return(TFLOAT);
"char"                          return(TCHAR);
"/*"([^*]|\*+[^*/])*\**"*/"		;
"//".*							;
"+"                             return(TPLUS);
"-"                             return(TMINUS);
"*"                             return(TMUL);
"/"                             return(TDIV);
"%"                             return(TMOD);
"="                             return(TASSIGN);
"+="							return(TADDASSIGN);
"-="							return(TSUBASSIGN);
"*="							return(TMULASSIGN);
"/="							return(TDIVASSIGN);
"%="							return(TMODASSIGN);
"!"                             return(TNOT);
"&&"							return(TAND);
"||"							return(TOR);
"=="							return(TEQUAL);
"!="							return(TNOTEQU);
"<"							    return(TLESS);
">"							    return(TGREAT);
"<="							return(TLESSE);
">="							return(TGREATE);
"++"							return(TINC);
"--"							return(TDEC);

[+\-]?[1-9][0-9]*               {   // 10진수 정수 상수 (양수, 음수 포함)
                                    return TINTNUM;
                                }
[+\-]?0[0-7]*                   {   // 8진수 정수 상수
                                    return TINTNUM;
                                }
[+\-]?0[8-9][0-9]*              {   // 8진수로 잘못된 표기 (0 다음 8이나 9는 에러)
                                    print_error(4, yylineno, yytext);
                                    return TERROR;
                                }
[+\-]?0[xX][0-9A-Fa-f]+         {   // 16진수 정수 상수
                                    return TINTNUM;
                                }
[+\-]?[0-9]+\.[0-9]+([eE][+\-]?[0-9]+)? {   // 부동소수점 상수 (소수점 및 지수부 포함 가능)
                                    return TFLOATNUM;
                                }
[0-9]+[A-Za-z_][A-Za-z0-9_]*    {   // 숫자로 시작하고 뒤에 문자가 따라오는 경우 에러 (start with digit)
                                    print_error(4, yylineno, yytext);
                                    return TERROR;
                                }

[A-Za-z_][A-Za-z0-9_]*		{   // 식별자 처리 (길이 15 초과 시 에러)
                                    if (yyleng > 15) {
                                        print_error(1, yylineno, yytext);
                                        return(TERROR);
                                    }
                                    int result = process_sym_table(yytext);
                                    // 심볼 테이블 처리 (중복, 오버플로우 확인)
                                    if (result == -1) { // 오버플로우 시 에러
                                        print_error(3, yylineno, yytext);
                                        return(TERROR);
                                    }  else {
                                        if (duplicate_flag == 0) {
                                            printf("%d\tTIDENT\t\t%d\t\t%s\n", yylineno, result, yytext);
                                        } else {
                                            printf("%d\tTIDENT\t\t%d\t\t%s (already exists)\n", yylineno, result, yytext);
                                            duplicate_flag = 0;  // 중복 플래그 초기화
                                        }
				    }
                                    return(TIDENT); // 정상 식별자
                                }
\"([^\"\\]|\\.)*\"              return(TSTRING);    // 문자열 상수
","                             return(TCOMMA);
";"                             return(TSEMI);
\.                              return(TDOT);
"("                             return(TLPAREN);
")"                             return(TRPAREN);
"{"                             return(TLBRACE);
"}"                             return(TRBRACE);
"["                             return(TLSQUARE);
"]"                             return(TRSQUARE);
[ \t\n\r] 						;	// 캐리지리턴을 추가
.							    {   // 위의 패턴에 모두 해당되지 않는 경우 에러
                                    print_error(2, yylineno, yytext);
                                    return TERROR;
                                }
%%

int yywrap() {
	return 1;
}
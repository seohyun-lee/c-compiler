%{
/*yacc source for Mini C*/

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

extern void update_sym_table(int id_index, int attr_num, int attr_value);
void update_sym_table_param(int id_index, int param_count, int param_types[], int param_indexes[]);
extern yyerror(const char*);
int current_type;
int is_const = 0; /* TCONST 인식여부 확인 */
extern int st_index; /* lex에서 process_sym_table 후에 그 결과(id)가 저장되는 변수 */

/* 파라미터의 타입 및 인덱스(해시심볼테이블의 index) 보관용 배열 */
int param_types[256];
int param_indexes[256];
/* 파라미터 수 */
int param_count = 0;
/* 저장된 함수의 인덱스 */
int saved_func_index = -1;

%}

%token TCONST TELSE TIF TINT TRETURN TVOID TWHILE 
%token TPLUS TMINUS TMUL TDIV TMOD TASSIGN
%token TEQUAL TNOTEQU TLESSE TGREATE TAND TOR TINC TDEC 
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN TIDENT 
%token TLPAREN TRPAREN TLBRACE TRBRACE TLSQUARE TRSQUARE TCOMMA TDOT TSEMI
%token TNOT TLESS TGREAT TINTNUM TFLOATNUM TSTRING TCHAR TFLOAT TERROR

%nonassoc TLOWERTHANELSE 
%nonassoc TELSE

%%
/* 프로그램 전체 */
mini_c 				: translation_unit						;
/* 외부 선언 여러 개 */
translation_unit 	: external_dcl			
					| translation_unit external_dcl			;
/* 외부 선언: 함수 정의 혹은 전역 변수 선언 */
external_dcl 		: function_def				
		  			| declaration							;
/* 함수 정의(Function Definition) */
function_def 		: function_header compound_st			;
/* 함수 선언부*/
function_header 	: dcl_spec function_name formal_param	{
																int func_index = saved_func_index;
																/* 리턴 타입 기록 */
																update_sym_table(func_index, 0, current_type);
																/* const 여부 기록 */
																update_sym_table(func_index, 1, is_const);
																is_const = 0;
																/* 파라미터 개수 기록 */
																update_sym_table(func_index, 3, param_count);
																/* 엔티티 종류 = 1 (함수) */
																update_sym_table(func_index, 4, 1); /* 1 = function */
																/* 파라미터 바탕으로 함수 속성 업데이트 */
																if (param_count) {
																	update_sym_table_param(func_index, param_count, param_types, param_indexes);
																}
																/* 파라미터 갯수 리셋 */
																param_count = 0;
															};
/* 선언 사양자 const 및 타입 구분 */
dcl_spec 			: dcl_specifiers						;
dcl_specifiers 		: dcl_specifier							
		 			| dcl_specifiers dcl_specifier			;
dcl_specifier 		: type_qualifier				
					| type_specifier						;
type_qualifier 		: TCONST								{is_const = 1;};
/* 타입: int, void, float, char */
type_specifier 		: TINT									{current_type=0;}
		 			| TVOID									{current_type=1;}
					| TFLOAT								{current_type=2;}
					| TCHAR 								{current_type=3;};
/* 함수 이름 */
function_name 		: TIDENT								{saved_func_index = st_index;};
formal_param 		: TLPAREN opt_formal_param TRPAREN
					| TLPAREN error							/* 오류가 발생했어도 함수로 간주 */
					;
/* 파라미터가 있으면 formal_param_list 호출 */
opt_formal_param 	: TVOID									/* void만 있는 경우 → 파라미터 없음으로 처리 */
					| formal_param_list
		   			|										;
formal_param_list 	: param_dcl						
					| formal_param_list TCOMMA param_dcl 	;
/* 함수 매개변수 정의*/
param_dcl			: dcl_spec TIDENT						{
																int param_st_index = st_index;
																/* 스칼라 파라미터 */
          														update_sym_table(param_st_index, 0, current_type);
          														update_sym_table(param_st_index, 1, is_const);
																is_const = 0;
          														update_sym_table(param_st_index, 2, 0);	/* 0 = scalar */
																update_sym_table(param_st_index, 4, 3);	/* 3 = param */
																param_types[param_count] = current_type;
																param_indexes[param_count] = param_st_index;
																param_count++;
      														}
					| dcl_spec TIDENT TLSQUARE opt_number TRSQUARE  {
																int param_st_index = st_index;
          														/* 배열 파라미터 */
         														update_sym_table(param_st_index, 0, current_type);
          														update_sym_table(param_st_index, 1, is_const);
																is_const = 0;
         														update_sym_table(param_st_index, 2, 1);	/* 1 = array */
																update_sym_table(param_st_index, 4, 3);	/* 3 = param */
																param_types[param_count] = current_type;
																param_indexes[param_count] = param_st_index;
																param_count++;
     														};
/* 중괄호 블록 */
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE	;
/* 지역 변수 목록 */
opt_dcl_list 		: declaration_list
					|											;
declaration_list 	: declaration				
					| declaration_list declaration 				;
/* 선언 */
declaration 		: dcl_spec init_dcl_list TSEMI				;
init_dcl_list 		: init_declarator						
					| init_dcl_list TCOMMA init_declarator 		;
/* 초기화 가능 선언자: 변수 정의*/
init_declarator 	: declarator				
		 			| declarator TASSIGN TINTNUM				
		 			| declarator TASSIGN TFLOATNUM
					| declarator TASSIGN TSTRING				{
																	// 한번 더 확인
																	int var_id = st_index;
																	update_sym_table(var_id, 0, 3);  /* 3 = char */
																	update_sym_table(var_id, 2, 1);  /* 1 = array */
																};
declarator 			: TIDENT									{
																	int var_id = st_index;
																	update_sym_table(var_id, 0, current_type);
																	update_sym_table(var_id, 1, is_const);
																	is_const = 0;
																	update_sym_table(var_id, 2, 0); /* 0 = scalar */
																	update_sym_table(var_id, 4, 2); /* 2 = variable */
																}
	     			| TIDENT TLSQUARE opt_number TRSQUARE		{
																	int var_id = st_index;
																	update_sym_table(var_id, 0, current_type);
																	update_sym_table(var_id, 1, is_const);
																	is_const = 0;
																	update_sym_table(var_id, 2, 1); /* 1 = array */
																	update_sym_table(var_id, 4, 2); /* 2 = variable */
																};
/* 선택적 배열 크기 */
opt_number 			: TINTNUM				
	     			|											;
/* 선택적 문장 리스트 */
opt_stat_list 		: statement_list				
		 			|											;
statement_list 		: statement				
		 			| statement_list statement 					;
statement 			: compound_st				
	   				| expression_st				
	   				| if_st						
	   				| while_st					
	   				| return_st									;
expression_st 		: opt_expression TSEMI						;
opt_expression 		: expression					
		 			|											;
if_st 				: TIF TLPAREN expression TRPAREN statement %prec TLOWERTHANELSE 
					| TIF TLPAREN expression TRPAREN statement TELSE statement ;
while_st 			: TWHILE TLPAREN expression TRPAREN statement 		;
return_st 			: TRETURN opt_expression TSEMI				;
expression 			: assignment_exp							;
assignment_exp 		: logical_or_exp					
					| unary_exp TASSIGN assignment_exp 		
					| unary_exp TADDASSIGN assignment_exp 	
					| unary_exp TSUBASSIGN assignment_exp 	
					| unary_exp TMULASSIGN assignment_exp 	
					| unary_exp TDIVASSIGN assignment_exp 	
					| unary_exp TMODASSIGN assignment_exp 		;
logical_or_exp 		: logical_and_exp				
					| logical_or_exp TOR logical_and_exp 		;
logical_and_exp 	: equality_exp					
		 			| logical_and_exp TAND equality_exp 		;
equality_exp 		: relational_exp				
					| equality_exp TEQUAL relational_exp 
					| equality_exp TNOTEQU relational_exp 		;
relational_exp 		: additive_exp 				
					| relational_exp TGREAT additive_exp 		
					| relational_exp TLESS additive_exp 		
					| relational_exp TGREATE additive_exp 	
					| relational_exp TLESSE additive_exp 		;
additive_exp 		: multiplicative_exp			
					| additive_exp TPLUS multiplicative_exp 	
					| additive_exp TMINUS multiplicative_exp 	;
multiplicative_exp 	: unary_exp					
					| multiplicative_exp TMUL unary_exp 		
		   			| multiplicative_exp TDIV unary_exp 		
		   			| multiplicative_exp TMOD unary_exp			;
unary_exp 			: postfix_exp				
	   				| TMINUS unary_exp			
	   				| TNOT unary_exp				
	   				| TINC unary_exp			
	   				| TDEC unary_exp							;
postfix_exp 		: primary_exp					
	      			| postfix_exp TLSQUARE expression TRSQUARE 		
	      			| postfix_exp TLPAREN opt_actual_param TRPAREN 	{
																	update_sym_table(saved_func_index, 4, 1); /* 1 = function */
																}
	    			| postfix_exp TINC				
	   				| postfix_exp TDEC							;
opt_actual_param 	: actual_param			
		  			|											;
actual_param 		: actual_param_list							;
actual_param_list 	: assignment_exp				
		   			| actual_param_list TCOMMA assignment_exp 	;
primary_exp 		: TIDENT						
	     			| TINTNUM					
					| TFLOATNUM
	     			| TLPAREN expression TRPAREN				;
%%
%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

/*yacc source for Mini C */
void semantic(int);
void yyerror(char *s);
%}

%token TIDENT TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TINC TDEC TEIF

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE
%%
mini_c						: translation_unit							{ semantic(1); };
translation_unit	    	: external_dcl								{ semantic(2); }
							| translation_unit external_dcl			    { semantic(3); };
external_dcl				: function_def								{ semantic(4); }
							| declaration								{ semantic(5); };
function_def				: function_header compound_st				{ semantic(6); };
function_header	        	: dcl_spec function_name formal_param		{ semantic(7); };
dcl_spec					: dcl_specifiers							{ semantic(8); };
dcl_specifiers			    : dcl_specifier								{ semantic(9); }
							| dcl_specifiers dcl_specifier				{ semantic(10); };
dcl_specifier			    : type_qualifier							{ semantic(11); }
							| type_specifier							{ semantic(12); };
type_qualifier		    	: TCONST									{ semantic(13); };
type_specifier			    : TINT										{ semantic(14); }
							| TVOID										{ semantic(15); };
function_name		        : TIDENT									{ semantic(16); };
formal_param		    	: '(' opt_formal_param ')'					{ semantic(17); };
opt_formal_param 	        : formal_param_list							{ semantic(18); }
							|											{ semantic(19); };
formal_param_list       	: param_dcl									{ semantic(20); }
							| formal_param_list ',' param_dcl			{ semantic(21); };
param_dcl				    : dcl_spec declarator					    { semantic(22); };
compound_st		        	: '{' opt_dcl_list opt_stat_list '}'		{ semantic(23); };
opt_dcl_list				: declaration_list							{ semantic(24); }
							|											{ semantic(25); };
declaration_list		    : declaration								{ semantic(26); }
							| declaration_list declaration				{ semantic(27); };
declaration				    : dcl_spec init_dcl_list ';'				{ semantic(28); };
init_dcl_list				: init_declarator							{ semantic(29); }
							| init_dcl_list ',' init_declarator			{ semantic(30); };
init_declarator			    : declarator								{ semantic(31); }
							| declarator '=' TNUMBER				    { semantic(32); };
declarator				    : TIDENT									{ semantic(33); }
							| TIDENT '[' opt_number ']'					{ semantic(34); };
opt_number				    : TNUMBER									{ semantic(35); }
							|											{ semantic(36); };
opt_stat_list				: statement_list							{ semantic(37); }
							|											{ semantic(38); };
statement_list		    	: statement									{ semantic(39); }
							| statement_list statement					{ semantic(40); };
statement					: compound_st								{ semantic(41); }
							| expression_st								{ semantic(42); }
							| if_st										{ semantic(43); }
							| while_st									{ semantic(44); }
							| return_st									{ semantic(45); }
							;
expression_st	    		: opt_expression ';'						{ semantic(46); };
opt_expression	        	: expression								{ semantic(47); }
							|											{ semantic(48); };
if_st						: TIF '(' expression ')' statement %prec LOWER_THAN_ELSE			        { semantic(49); }
							| TIF '(' expression ')' statement TELSE statement							{ semantic(50); };
while_st		    		: TWHILE '(' expression ')' statement		{ semantic(51); };
return_st					: TRETURN opt_expression ';'				{ semantic(52); };
expression			    	: assignment_exp							{ semantic(53); };
assignment_exp		        : logical_or_exp							{ semantic(54); }
							| unary_exp '=' assignment_exp				{ semantic(55); }
							| unary_exp TADDASSIGN assignment_exp		{ semantic(56); }
							| unary_exp TSUBASSIGN assignment_exp		{ semantic(57); }
							| unary_exp TMULASSIGN assignment_exp		{ semantic(58); }
							| unary_exp TDIVASSIGN assignment_exp		{ semantic(59); }
							| unary_exp TMODASSIGN assignment_exp		{ semantic(60); }
							;
logical_or_exp   	    	: logical_and_exp         					{semantic(61);}
   							| logical_or_exp TOR logical_and_exp   		{semantic(62);};
logical_and_exp   	        : equality_exp         						{semantic(63);}
     						| logical_and_exp TAND equality_exp   		{semantic(64);};
equality_exp   			    : relational_exp         					{semantic(65);}
      						| equality_exp TEQUAL relational_exp   		{semantic(66);}
     						| equality_exp TNOTEQU relational_exp   	{semantic(67);};
relational_exp              : additive_exp                             {semantic(68);}
      						| relational_exp '>' additive_exp   		{semantic(69);}
      						| relational_exp '<' additive_exp   		{semantic(70);}
      						| relational_exp TGREATE additive_exp   	{semantic(71);}
      						| relational_exp TLESSE additive_exp   		{semantic(72);};
additive_exp   	    		: multiplicative_exp         				{semantic(73);}
      						| additive_exp '+' multiplicative_exp   	{semantic(74);}
      						| additive_exp '-' multiplicative_exp   	{semantic(75);};
multiplicative_exp          : unary_exp         						{semantic(76);}
     						| multiplicative_exp '*' unary_exp      	{semantic(77);}
      						| multiplicative_exp '/' unary_exp   		{semantic(78);}
      						| multiplicative_exp '%' unary_exp   		{semantic(79);};
unary_exp   				: postfix_exp         						{semantic(80);}
      						| '-' unary_exp         					{semantic(81);}
      						| '!' unary_exp        						{semantic(82);}
      						| TINC unary_exp         					{semantic(83);}
      						| TDEC unary_exp         					{semantic(84);};
postfix_exp 				: primary_exp 								{semantic(85);}
							| postfix_exp '[' expression ']' 			{semantic(86);}
							| postfix_exp '(' opt_actual_param ')' 		{semantic(87);}
							| postfix_exp TINC 							{semantic(88);}
							| postfix_exp TDEC							{semantic(89);};
opt_actual_param 	        : actual_param 								{semantic(90);}
							| 											{semantic(91);};
actual_param 			    : actual_param_list 						{semantic(92);};
actual_param_list 	        : assignment_exp 							{semantic(93);}
							| actual_param_list ',' assignment_exp 		{semantic(94);};
primary_exp 			    : TIDENT 									{semantic(95);}
							| TNUMBER 									{semantic(96);}
							| '(' expression ')' 						{semantic(97);};
%%

void semantic(int n)
{
	printf("reduced rule number = %d\n", n);
}


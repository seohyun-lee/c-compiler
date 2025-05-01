%%
[a-z]+	printf("ide=>%s\n", yytext);
integer	printf("kw integer\n");
%%

int main()
{
	while(yylex()){}
	return 0;
}


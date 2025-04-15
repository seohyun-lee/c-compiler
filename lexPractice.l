%%
Mega-	yymore();
Kludge	ECHO;
Foobar	ECHO; yyless(3); 
bar	ECHO;
[a-z]+	printf("IDENT\n");
.	;
%%

int main()
{
	while(yylex()){}
	return 0;
}


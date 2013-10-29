%{
/* log scanner */
%}


DIGIT    [0-9]

%%

%s TIME IP PROPERTIES FIRSTIP
^[0-9][0-9]:[0-9][0-9]:[0-9][0-9][.][0-9]{6}	{	printf("%s",yyless(8));
												yyin+=7;
												BEGIN(TIME);
											}
<TIME> arp[ ].*	{/*consume*/}											
<TIME> IP[ ]	{BEGIN(IP);}	
<IP> [(].*[)]	{BEGIN(PROPERTIES);}
<PROPERTIES> [0-9]+[.][0-9]+[.][0-9]+[.][0-9]+{ECHO; BEGIN(FIRSTIP);}
<FIRSTIP>[.]80	{}										
												

%%

int main() {
    printf("Zamiana lex na flex:\n");
    yylex();
    return 0;
}
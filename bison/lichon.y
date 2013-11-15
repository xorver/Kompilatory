/* lichon.y - wygenerowany parser będzie wykonywał dodawanie */

%{
#include<stdio.h>
#define YYSTYPE char*
%}

%token DECL_SPECIFIER

%%
function: DECL_SPECIFIER '+' DECL_SPECIFIER{printf("%s%s",$3,$1);};
		
%%

int main() {

  yyparse(); 
}

int yyerror(char *s) {

   printf("blad: %s\n", s); 
}
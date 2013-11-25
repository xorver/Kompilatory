/* add.l - skaner wspolpracujacy z parserem add.y */

%option noyywrap

%{
#include "lichon.tab.h"
#include<string.h>
int counter=0;

void log(char* msg){
	if(0)
		printf("%s",msg);
}
%}

ID [a-zA-Z][a-zA-Z0-9_]*
WHITESPACE [ \t\n\r]+
%x BODY
%%
void|char|short|int|long|float|struct{WHITESPACE}{ID}|enum{WHITESPACE}{ID}	{log("rozpoznano DECL_SPECIFIER\n"); yylval.str_t = (char*) strdup(yytext);  return DECL_SPECIFIER;}
[*]+ {log("rozpoznano POINTER\n");yylval.str_t = (char*) strdup(yytext); return POINTER;}
{ID} {log("rozpoznano IDENTIFIER\n");yylval.str_t = (char*) strdup(yytext); return IDENTIFIER;}
[0-9]+ {log("rozpoznano NUM\n");yylval.str_t = (char*) strdup(yytext); return NUM;}
{WHITESPACE}                    /* eat up whitespace */
[{] {log("rozpoznano {\n");BEGIN(BODY);counter++;return(yytext[0]);}
. {log("rozpoznano znak\n");return(yytext[0]);}
<BODY>[/][/].* {log("rozpoznano komentarz1\n");yylval.str_t = (char*) strdup(yytext);return(STR);}
<BODY>[/]\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+[/] {log("rozpoznano komentarz2\n");yylval.str_t=(char*)strdup(yytext);return(STR);}
<BODY>[{] {log("rozpoznano {\n");yylval.str_t = (char*) strdup(yytext);counter++;return(STR);}
<BODY>[}] {log("rozpoznano }\n");yylval.str_t = (char*) strdup(yytext);counter--;if(counter==0){BEGIN(0);}return(STR);}
<BODY>(.|\n|\r) {log("rozpoznano znak\n");yylval.str_t = (char*) strdup(yytext);return(STR);}

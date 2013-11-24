/* add.l - skaner wspolpracujacy z parserem add.y */

%option noyywrap

%{
#include "lichon.tab.h"
#include<string.h>
int counter=0;
%}

ID [a-zA-Z][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+
%x BODY
%%
void|char|short|int|long|float|struct{WHITESPACE}{ID}|enum{WHITESPACE}{ID}	{printf("rozpoznano DECL_SPECIFIER\n"); yylval.str_t = (char*) strdup(yytext);  return DECL_SPECIFIER;}
[*]+ {printf("rozpoznano POINTER\n");yylval.str_t = (char*) strdup(yytext); return POINTER;}
{ID} {printf("rozpoznano IDENTIFIER\n");yylval.str_t = (char*) strdup(yytext); return IDENTIFIER;}
[0-9]+ {printf("rozpoznano NUM\n");yylval.str_t = (char*) strdup(yytext); return NUM;}
{WHITESPACE}                    /* eat up whitespace */
[{] {printf("rozpoznano {\n");BEGIN(BODY);counter++;return(yytext[0]);}
. {printf("rozpoznano znak %c\n",yytext[0]);return(yytext[0]);}
<BODY>[/][/].* {printf("rozpoznano komentarz1\n");yylval.str_t = (char*) strdup(yytext);return(STR);}
<BODY>[/]\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+[/] {printf("rozpoznano komentarz2\n");yylval.str_t=(char*)strdup(yytext);return(STR);}
<BODY>[{] {printf("rozpoznano {\n");yylval.str_t = (char*) strdup(yytext);counter++;return(STR);}
<BODY>[}] {printf("rozpoznano }\n");yylval.str_t = (char*) strdup(yytext);counter--;if(counter==0){BEGIN(0);}return(STR);}
<BODY>(.|\n|\r) {printf("rozpoznano znak %c\n",yytext[0]);yylval.str_t = (char*) strdup(yytext);return(STR);}

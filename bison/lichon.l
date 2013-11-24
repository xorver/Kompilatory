/* add.l - skaner wspolpracujacy z parserem add.y */

%option noyywrap

%{
#include "lichon.tab.h"
#include<string.h>
%}

ID [a-zA-Z][a-zA-Z0-9_]*
WHITESPACE [ \t\n]+
%%
void|char|short|int|long|float|struct{WHITESPACE}{ID}|enum{WHITESPACE}{ID}	{printf("rozpoznano DECL_SPECIFIER\n"); yylval.str_t = (char*) strdup(yytext);  return DECL_SPECIFIER;}
[*]+ {printf("rozpoznano POINTER\n");yylval.str_t = (char*) strdup(yytext); return POINTER;}
{ID} {printf("rozpoznano IDENTIFIER\n");yylval.str_t = (char*) strdup(yytext); return IDENTIFIER;}
[0-9]+ {printf("rozpoznano num\n");yylval.str_t = (char*) strdup(yytext); return NUM;}
{WHITESPACE}                    /* eat up whitespace */
.      {printf("rozpoznano znak %c\n",yytext[0]);return(yytext[0]);}

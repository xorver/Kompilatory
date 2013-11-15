/* add.l - skaner wspolpracujacy z parserem add.y */

%option noyywrap

%{
#include "lichon.tab.h"
%}

%%
void|char|short|int|long|float|struct[ ]+[a-zA-Z][a-zA-Z0-9]*|enum[ ]+[a-zA-Z][a-zA-Z0-9]*	{yylval = yytext;  return DECL_SPECIFIER;}

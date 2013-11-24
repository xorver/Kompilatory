/* lichon.y - wygenerowany parser będzie wykonywał dodawanie */

%{
#include<stdio.h>
#include<string.h>

struct argument{
	char* type;
	char* id;
};

struct fun{
	char* type;
	char* name;
	char* body;
};

%}

%union {
struct function* function_t ;
struct argument* argument_t;
char* str_t;
}

%token <str_t> DECL_SPECIFIER
%token <str_t> POINTER
%token <str_t> IDENTIFIER
%token <str_t> NUM

%type <function_t> function
 /*%type <argument_t> */
%type <str_t> declaration_list
%type <str_t> declaration_list_tail
%type <str_t> declaration
%type <str_t> declarator_list
%type <str_t> declarator_list_tail
%type <str_t> declarator
%type <str_t> direct_declarator
%type <str_t> identifier_list
%type <str_t> identifier_list_tail
%type <str_t> param_list
%type <str_t> param_list_tail
%type <str_t> param_declaration
%type <str_t> abstract_declarator
%type <str_t> direct_abstract_declarator

%%
function: DECL_SPECIFIER declarator declaration_list {printf("%s %s\n%s",$1,$2,$3);}
declaration_list: declaration
	| declaration declaration_list_tail {
		char* result=malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
declaration_list_tail: declaration
	| declaration_list_tail declaration {
		char* result=malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
declaration: DECL_SPECIFIER ';' {
		char* result=malloc(strlen($1)+2);
		sprintf(result,"%s;\n",$1);
		free($1);
		$$=result;
	}
	| DECL_SPECIFIER declarator_list ';' {
		char* result=malloc(strlen($1)+strlen($2)+2);
		sprintf(result,"%s %s;\n",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
declarator_list: declarator {printf("declarator: %c\n",$1[0]);$$=$1;}
	| declarator declarator_list_tail {
		char* result=malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
declarator_list_tail: ',' declarator {
		char* result=malloc(strlen($2)+2);
		sprintf(result,",%s",$2);
		free($2);
		$$=result;
	}
	| declarator_list_tail ',' declarator {
		char* result=malloc(strlen($1)+strlen($3)+2);
		sprintf(result,"%s,%s",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	;
declarator: POINTER direct_declarator {
		char* result=malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	| direct_declarator
	;
direct_declarator: IDENTIFIER
	| '(' declarator ')' {
		char* result = malloc(3+strlen($2));
		sprintf(result,"(%s)",$2);
		free($2);
		$$=result;
	}
	| direct_declarator '[' NUM ']' {
		char* result = malloc(strlen($1)+strlen($3)+3);
		sprintf(result,"%s[%s]",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	| direct_declarator '[' ']' {
		char* result = malloc(strlen($1)+3);
		sprintf(result,"%s[]",$1);
		free($1);
		$$=result;
	}
	| direct_declarator '(' param_list ')' {
		char* result = malloc(strlen($1)+strlen($3)+3);
		sprintf(result,"%s(%s)",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	| direct_declarator '(' identifier_list ')' {
		char* result = malloc(strlen($1)+strlen($3)+3);
		sprintf(result,"%s(%s)",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	| direct_declarator '(' ')' {
		char* result = malloc(strlen($1)+3);
		sprintf(result,"%s()",$1);
		free($1);
		$$=result;
	}
	;
identifier_list: IDENTIFIER
	| IDENTIFIER identifier_list_tail {
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;	
	}
	;
identifier_list_tail: ',' IDENTIFIER {
		char* result = malloc(strlen($2)+2);
		sprintf(result,",%s",$2);
		free($2);
		$$=result;
	}
	| identifier_list_tail ',' IDENTIFIER {
		char* result = malloc(strlen($1)+strlen($3)+2);
		sprintf(result,"%s,%s",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	;
param_list: param_declaration
	| param_declaration param_list_tail {
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
param_list_tail: ',' param_declaration {
		char* result = malloc(strlen($2)+2);
		sprintf(result,",%s",$2);
		free($2);
		$$=result;
	}
	| param_list_tail ',' param_declaration {
		char* result = malloc(strlen($1)+strlen($3)+2);
		sprintf(result,"%s,%s",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	;
param_declaration: DECL_SPECIFIER declarator {
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s %s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	| DECL_SPECIFIER abstract_declarator {
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s %s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	| DECL_SPECIFIER
	;
abstract_declarator: POINTER
	| direct_abstract_declarator
	| POINTER direct_abstract_declarator {
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;
direct_abstract_declarator: '(' abstract_declarator ')'{
		char* result = malloc(strlen($2)+3);
		sprintf(result,"(%s)",$2);
		free($2);
		$$=result;	
	}
	| direct_abstract_declarator '[' NUM ']' {
		char* result = malloc(strlen($1)+strlen($3)+3);
		sprintf(result,"%s[%s]",$1,$3);
		free($1);
		free($3);
		$$=result;			
	}
	| direct_abstract_declarator '[' ']' {
		char* result = malloc(strlen($1)+3);
		sprintf(result,"%s[]",$1);
		free($1);
		$$=result;
	}
	| direct_abstract_declarator '(' param_list ')' {
		char* result = malloc(strlen($1)+strlen($3)+3);
		sprintf(result,"%s(%s)",$1,$3);
		free($1);
		free($3);
		$$=result;
	}
	| '(' param_list ')' {
		char* result = malloc(strlen($2)+3);
		sprintf(result,"(%s)",$2);
		free($2);
		$$=result;
	}
	| direct_abstract_declarator '(' ')' {
		char* result = malloc(strlen($1)+3);
		sprintf(result,"%s()",$1);
		free($1);
		$$=result;
	}
	| '(' ')' {
		char* result = malloc(3);
		sprintf(result,"()");
		$$=result;
	}
	;


%%

int main() {

  yyparse(); 
}

int yyerror(char *s) {

   printf("blad: *%s* in yylval=%s \n", s, yylval.str_t); 
}
/* lichon.y - parser funkcji C */

%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fun{
	char* type;
	struct decl* decl;
	struct declaration_node* declaration_head;
	char* body;
};

struct declaration{
	char* name;
	struct decl_node* decl_head;
};

struct decl{
	char* id;
	char* name;
	struct arg_node* arg_head;
};

struct argument{
	char* type;
	char* name;
	char* id;
};

struct arg_node{
	struct argument* val;
	struct arg_node* next;
};

struct decl_node{
	struct decl* val;
	struct decl_node* next;
};

struct declaration_node{
	struct declaration* val;
	struct declaration_node* next;
};

char* to_string(struct arg_node* head){
	struct arg_node* h=head;
	int size=3;
	while(h){
		size=size+strlen(h->val->type)+1+strlen(h->val->name);
		h=h->next;
	}
	char* toReturn=(char*) malloc(size);
	
	toReturn[0]=0;
	if(head==NULL)
		return toReturn;
	h=head;
	strcat(toReturn,"(");
	if(h){
		strcat(toReturn,h->val->type);
		strcat(toReturn," ");
		strcat(toReturn,h->val->name);
		h=h->next;
	}
		
	while(h){
		strcat(toReturn,",");
		strcat(toReturn,h->val->type);
		strcat(toReturn," ");
		strcat(toReturn,h->val->name);
		h=h->next;
	}
	strcat(toReturn,")");
	return toReturn;
}

void free_list(struct arg_node* head){
	if(head==NULL)
		return;
	if(head->next){
		free_list(head->next);
		head->next=NULL;
	}
	free(head);	
}

void log_exit(char* s){
	if(0)
		printf("exiting from %s\n",s);
	fflush(stdout);
}

int duplicated(struct decl* declarator){
	if(declarator==NULL || declarator->arg_head==NULL)
		return 0;
	for(struct arg_node* it1=declarator->arg_head;it1->next;it1=it1->next)
		for(struct arg_node* it2=it1->next;it2;it2=it2->next){
			if(strcmp(it1->val->id,it2->val->id)==0)
				return 1;
		}
	return 0;
}

char* find_arg(char* id,struct declaration_node* declaration_head){
	

		for(struct declaration_node* it2=declaration_head;it2;it2=it2->next){
			char* type=it2->val->name;
			fflush(stdout);
			for(struct  decl_node* it3=it2->val->decl_head;it3;it3=it3->next)
				if(strcmp(id,it3->val->id)==0){
					char* res=malloc(strlen(type)+strlen(it3->val->name)+2);
					sprintf(res,"%s %s",type,it3->val->name);
					return res;
				}
		}
		return NULL;
}

char* get_args(struct decl* declarator,struct declaration_node* declaration_head){
	struct arg_node* arg_head=declarator->arg_head;
	char* result=malloc(300);
	result[0]=0;
	for(struct arg_node* it=arg_head;it;it=it->next){
		if(find_arg(it->val->id,declaration_head)==NULL)
			return NULL;
		strcat(result,find_arg(it->val->id,declaration_head));
		if(it->next)
			strcat(result,",");
	}
	
	fflush(stdout);
	if(strcmp(result,"")==0)
		result="void";
	return result;
}

int all_types_exists(struct decl* declarator){

	
	if(declarator==NULL)
		return 1;
	for(struct arg_node* it=declarator->arg_head;it;it=it->next)
		if(it->val->type==NULL)
			return 0;
	return 1;
}

%}

%union {
struct fun* function_t ;
struct declaration* declaration_t;
struct decl* declarator_t;
struct argument* argument_t;
struct arg_node* arg_list;
struct decl_node* decl_list;
struct declaration_node* declaration_list;
char* str_t;
}

%token <str_t> DECL_SPECIFIER
%token <str_t> POINTER
%token <str_t> IDENTIFIER
%token <str_t> NUM
%token <str_t> STR

%type <function_t> function
%type <declaration_list> declaration_list
%type <declaration_list> declaration_list_tail
%type <declaration_t> declaration
%type <decl_list> declarator_list
%type <decl_list> declarator_list_tail
%type <declarator_t> declarator
%type <declarator_t> direct_declarator
%type <arg_list> identifier_list
%type <arg_list> identifier_list_tail
%type <arg_list> param_list
%type <arg_list> param_list_tail
%type <argument_t> param_declaration
%type <declarator_t> abstract_declarator
%type <declarator_t> direct_abstract_declarator
%type <str_t> body
%type <str_t> str_list

%%
functions: function {
		
		if(duplicated($1->decl)){
			yyerror("duplicated parameters");
			YYERROR;
			
		}
		if($1->declaration_head!=NULL){
			char* arg = get_args($1->decl,$1->declaration_head);
			if(!(arg = get_args($1->decl,$1->declaration_head))){
				yyerror("no definition found for some parameters");
				YYERROR;
			}
			printf("%s %s(%s)\n%s",$1->type,$1->decl->name,arg,$1->body);
		}else if(!all_types_exists($1->decl)){
			yyerror("missing declarations");
			YYERROR;
		}
		else{
			printf("%s %s(",$1->type,$1->decl->name);
			for(struct arg_node* it=$1->decl->arg_head;it;it=it->next){
				printf("%s %s",it->val->type,it->val->name);
				if(it->next)
				printf(",");
			}
			if($1->decl->arg_head==NULL)
				printf("void");
			printf(")\n%s",$1->body);
				
		}
		
	}
	;
function: DECL_SPECIFIER declarator declaration_list body {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type=$1;
		result->decl=$2;
		result->declaration_head=$3;
		result->body=$4;
		$$=result;
	}
	| declarator declaration_list body {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type="void";
		result->decl=$1;
		result->declaration_head=$2;
		result->body=$3;
		$$=result;
	}
	| declarator body {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type="void";
		result->decl=$1;
		result->declaration_head=NULL;
		result->body=$2;
		$$=result;
	}
	| DECL_SPECIFIER declarator body {
		log_exit("function");
		struct fun* result = malloc(sizeof(struct fun));
		result->type=$1;
		result->decl=$2;
		result->declaration_head=NULL;
		result->body=$3;
		$$=result;
	}
	;
declaration_list: declaration {
		log_exit("declaration_list");	
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=$1;
		head->next=NULL;
		$$=head;
	}
	| declaration declaration_list_tail {
		log_exit("declaration_list");
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=$1;
		head->next=$2;
		$$=head;
	}
	;
declaration_list_tail: declaration {
		log_exit("declaration_list_tail");
		struct declaration_node* head = malloc(sizeof(struct declaration_node));
		head->val=$1;
		head->next=NULL;
		$$=head;
	}
	| declaration_list_tail declaration {
		log_exit("declaration_list_tail");
		struct declaration_node* tail = malloc(sizeof(struct declaration_node));
		tail->val=$2;
		tail->next=NULL;
		struct declaration_node* it =$1;
		while(it->next)
			it=it->next;
		it->next=tail;
		$$=$1;
	}
	;
declaration: DECL_SPECIFIER ';' {
		log_exit("declaration");
		struct declaration* result = malloc(sizeof(struct declaration));
		result->name=$1;
		result->decl_head=NULL;
		$$=result;
	}
	| DECL_SPECIFIER declarator_list ';' {
		log_exit("declaration");
		struct declaration* result = malloc(sizeof(struct declaration));
		result->name=$1;
		result->decl_head=$2;
		$$=result;
	}
	;
declarator_list: declarator {
		log_exit("declarator_list");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=$1;
		head->next=NULL;
		$$=head;
	}
	| declarator declarator_list_tail {
		log_exit("declarator_list");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=$1;
		head->next=$2;
		$$=head;
	}
	;
declarator_list_tail: ',' declarator {
		log_exit("declarator_list_tail");
		struct decl_node* head = malloc(sizeof(struct decl_node));
		head->val=$2;
		head->next=NULL;
		$$=head;
	}
	| declarator_list_tail ',' declarator {
		log_exit("declarator_list_tail");
		struct decl_node* tail = malloc(sizeof(struct decl_node));
		tail->val=$3;
		tail->next=NULL;
		struct decl_node* it = $1;
		while(it->next)
			it=it->next;
		it->next=tail;
		$$=$1;
	}
	;
declarator: POINTER direct_declarator {
		log_exit("declarator");
		char* newName=malloc(strlen($1)+strlen($2->name)+1);
		sprintf(newName,"%s%s",$1,$2->name);
		free($1);
		free($2->name);
		$2->name=newName;
		$$=$2;
	}
	| direct_declarator {
		log_exit("declarator");
		$$=$1;
	}
	;
direct_declarator: IDENTIFIER {
		log_exit("direct_declarator: IDENTIFIER");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=$1;
		result->id=strdup($1);
		result->arg_head=NULL;
		$$=result;
	}
	| '(' declarator ')' {
		log_exit("direct_declarator: ( eclarator )");
		char* newName = malloc(3+strlen($2->name));
		sprintf(newName,"(%s)",$2->name);
		free($2->name);
		$2->name=newName;
		$$=$2;
	}
	| direct_declarator '[' NUM ']' {
		log_exit("direct_declarator: direct_declarator[NUM]");
		char* newName = malloc(strlen($1->name)+strlen($3)+3);
		sprintf(newName,"%s[%s]",$1->name,$3);
		free($1->name);
		free($3);
		$1->name=newName;
		$$=$1;
	}
	| direct_declarator '[' ']' {
		log_exit("direct_declarator: direct_declarator[]");
		char* newName = malloc(strlen($1->name)+3);
		sprintf(newName,"%s[]",$1->name);
		free($1->name);
		$1->name=newName;
		$$=$1;
	}
	| direct_declarator '(' param_list ')' {
		log_exit("direct_declarator: direct_declarator(param_list)");
		if($1->arg_head){
			char* newName=malloc(strlen($1->name)+strlen(to_string($1->arg_head))+1);
			sprintf(newName,"%s%s",$1->name,to_string($1->arg_head));
			free($1->name);
			$1->name=newName;
		}
		$1->arg_head=$3;
		$$=$1;
	}
	| direct_declarator '(' identifier_list ')' {
		log_exit("direct_declarator: direct_declarator(identifier_list)");
		if($1->arg_head){
			char* newName=malloc(strlen($1->name)+strlen(to_string($1->arg_head))+1);
			sprintf(newName,"%s%s",$1->name,to_string($1->arg_head));
			free($1->name);
			$1->name=newName;
		}
		$1->arg_head=$3;
		$$=$1;
	}
	| direct_declarator '(' ')' {
		log_exit("direct_declarator: direct_declarator()");
		if($1->arg_head){
			char* newName=malloc(strlen($1->name)+strlen(to_string($1->arg_head))+1);
			sprintf(newName,"%s%s",$1->name,to_string($1->arg_head));
			free($1->name);
			$1->name=newName;
		}
		$1->arg_head=NULL;
		$$=$1;
	}
	;
identifier_list: IDENTIFIER {
		log_exit("identifier_list: IDENTIFIER");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=$1;
		newArg->id=strdup($1);
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=NULL;
		$$=head;
	}
	| IDENTIFIER identifier_list_tail {
		log_exit("identifier_list");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=$1;
		newArg->id=strdup($1);
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=$2;
		$$=head;
	}
	;
identifier_list_tail: ',' IDENTIFIER {
		log_exit("identifier_list_tail");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=$2;
		newArg->id=strdup($2);
		newArg->type=NULL;
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=newArg;
		head->next=NULL;
		$$=head;
	}
	| identifier_list_tail ',' IDENTIFIER {
		log_exit("identifier_list_tail");
		struct argument* newArg=malloc(sizeof(struct argument));
		newArg->name=$3;
		newArg->id=strdup($3);
		newArg->type=NULL;
		struct arg_node* tail = malloc(sizeof(struct arg_node));
		tail->val=newArg;
		tail->next=NULL;
		struct arg_node* it=$1;
		while(it->next)
			it=it->next;
		it->next=tail;
		$$=$1;
	}
	;
param_list: param_declaration {
		log_exit("param_list");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=$1;
		head->next=NULL;
		$$=head;		
	}
	| param_declaration param_list_tail {
		log_exit("param_list");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=$1;
		head->next=$2;
		$$=head;
	}
	;
param_list_tail: ',' param_declaration {
		log_exit("param_list_tail");
		struct arg_node* head = malloc(sizeof(struct arg_node));
		head->val=$2;
		head->next=NULL;
		$$=head;
	}
	| param_list_tail ',' param_declaration {
		log_exit("param_list_tail");
		struct arg_node* tail = malloc(sizeof(struct arg_node));
		tail->val=$3;
		tail->next=NULL;
		struct arg_node* it=$1;
		while(it->next)
			it=it->next;
		it->next=tail;
		$$=$1;
	}
	;
param_declaration: DECL_SPECIFIER declarator {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument));
		newArg->type=$1;
		newArg->id=strdup($2->id);
		char* newId=malloc(sizeof($2->name)+sizeof(to_string($2->arg_head))+1);
		sprintf(newId,"%s%s",$2->name,to_string($2->arg_head));
		free($2->name);
		free_list($2->arg_head);
		free($2);
		newArg->name=newId;
		$$=newArg;
	}
	| DECL_SPECIFIER abstract_declarator {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument));
		newArg->type=$1;
		newArg->id=strdup($2->id);
		char* newId=malloc(sizeof($2->name)+sizeof(to_string($2->arg_head))+1);
		sprintf(newId,"%s%s",$2->name,to_string($2->arg_head));
		free($2->name);
		free_list($2->arg_head);
		free($2);
		newArg->name=newId;
		$$=newArg;
	}
	| DECL_SPECIFIER {
		log_exit("param_declaration");
		struct argument* newArg = malloc(sizeof(struct argument*));
		newArg->type=$1;
		newArg->id=NULL;
		newArg->name=NULL;
		$$=newArg;
	}
	;
abstract_declarator: POINTER {
		log_exit("abstract_declarator");
		struct decl* result = malloc(sizeof(struct decl));
		result->name=$1;
		result->id=NULL;
		result->arg_head=NULL;
		$$=result;
	}
	| direct_abstract_declarator {
		log_exit("abstract_declarator");
		$$=$1;
	}
	| POINTER direct_abstract_declarator {
		log_exit("abstract_declarator");
		char* newName=malloc(strlen($1)+strlen($2->name)+1);
		sprintf(newName,"%s%s",$1,$2->name);
		free($1);
		free($2->name);
		$2->name=newName;
		$$=$2;
	}
	;
direct_abstract_declarator: '(' abstract_declarator ')'{
		log_exit("direct_abstract_declarator");
		char* newName = malloc(3+strlen($2->name));
		sprintf(newName,"(%s)",$2->name);
		free($2->name);
		$2->name=newName;
		$$=$2;
	}
	| direct_abstract_declarator '[' NUM ']' {
		log_exit("direct_abstract_declarator");
		char* newName = malloc(strlen($1->name)+strlen($3)+3);
		sprintf(newName,"%s[%s]",$1->name,$3);
		free($1->name);
		free($3);
		$1->name=newName;
		$$=$1;		
	}
	| direct_abstract_declarator '[' ']' {
		log_exit("direct_abstract_declarator");
		char* newName = malloc(strlen($1->name)+3);
		sprintf(newName,"%s[]",$1->name);
		free($1->name);
		$1->name=newName;
		$$=$1;
	}
	| direct_abstract_declarator '(' param_list ')' {
		log_exit("direct_abstract_declarator");
		if($1->arg_head){
			char* newName=malloc(strlen($1->name)+strlen(to_string($1->arg_head))+1);
			sprintf(newName,"%s%s",$1->name,to_string($1->arg_head));
			free($1->name);
			$1->name=newName;
		}
		$1->arg_head=$3;
		$$=$1;
	}
	| '(' param_list ')' {
		log_exit("direct_abstract_declarator");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=NULL;
		result->arg_head=$2;
	}
	| direct_abstract_declarator '(' ')' {
		log_exit("direct_abstract_declarator");
		if($1->arg_head){
			char* newName=malloc(strlen($1->name)+strlen(to_string($1->arg_head))+1);
			sprintf(newName,"%s%s",$1->name,to_string($1->arg_head));
			free($1->name);
			$1->name=newName;
		}
		$1->arg_head=NULL;
		$$=$1;
	}
	| '(' ')' {
		log_exit("direct_abstract_declarator");
		struct decl* result=malloc(sizeof(struct decl));
		result->name=NULL;
		result->arg_head=NULL;
	}
	;
body: '{' str_list {
		log_exit("body");
		char* result = malloc(strlen($2)+2);
		sprintf(result,"{%s",$2);
		free($2);
		$$=result;
	}
	;
str_list: STR
	| str_list STR {
		log_exit("str_list");
		char* result = malloc(strlen($1)+strlen($2)+1);
		sprintf(result,"%s%s",$1,$2);
		free($1);
		free($2);
		$$=result;
	}
	;

%%

int main() {

  yyparse(); 
}

int yyerror(char *s) {

   printf("blad: *%s*\n", s, yylval.str_t); 
}
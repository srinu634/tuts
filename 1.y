%{
#include<stdio.h>
%}
%token lp rp 
%%
s:lp s rp s 
|
; 	
%%


int main(){
	printf("Enter the string\n");
	if ( yyparse() == 0 )
		printf("Valid String\n");	
return 0;	
}

yyerror(char *s) { 
	printf("Invalid String\n");
}


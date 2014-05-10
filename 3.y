%{
#include<stdio.h>
%}
%token lp rp 
%%
s:lp s rp  
|
; 	
%%

extern int flag;
int main(){
	printf("Enter the string\n");
	if ( yyparse() == 0 )
		if(flag >=3)
			printf("Valid String\n");
		else
			printf("Invalid String\n");	
return 0;	
}

yyerror(char *s) { 
	printf("Invalid String\n");
}


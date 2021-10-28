#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

YYSTYPE yylval;
extern YYSTYPE yylval;
char *yytext;
extern char *yytext;
FILE *yyin;
extern FILE *yyin;	

int main(void) {
	int token_type;
	
	yyin = fopen("input.txt", "r");
	if (yyparse()) {
		fprintf(stderr, "Error\n");
		exit(1);
	}
	fclose(yyin);
	free(yytext);
}

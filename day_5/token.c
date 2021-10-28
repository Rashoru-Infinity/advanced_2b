#include "syntax.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	extern int yyparse(void);
	extern FILE *yyin;

	yyin = fopen("input.txt", "r");
	if (yyparse()) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}
	fclose(yyin);
}

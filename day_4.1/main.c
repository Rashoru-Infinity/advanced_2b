#include <stdio.h>
#include <stdlib.h>
#include "type.h"

int main(void) {
	extern FILE *yyin;
	extern int yylex();
	yyin = fopen("./src", "r");
	if (yyin == NULL) {
		fprintf(stderr, "cannot open file\n");
		exit(1);
	}

	while (1) {
		int token_type = yylex();
		if (token_type == END) {
			printf("END OF FILE\n");
			break;
		}
		switch (token_type) {
		case INTEGER:
			printf("INTEGER\n");
			break;
		case DOUBLE:
			printf("DOUBLE\n");
			break;
		case IF:
			printf("IF\n");
			break;
		case ELSE:
			printf("ELSE\n");
			break;
		case ELSIF:
			printf("ELSIF\n");
			break;
		case WHILE:
			printf("WHILE\n");
			break;
		case FOR:
			printf("FOR\n");
			break;
		case RETURN:
			printf("RETURN\n");
			break;
		case BREAK:
			printf("BREAK\n");
			break;
		case CONTINUE:
			printf("CONTINUE\n");
			break;
		case TRUE:
			printf("TRUE\n");
			break;
		case FALSE:
			printf("FALSE\n");
			break;
		case BOOLEAN:
			printf("BOOLEAN\n");
			break;
		case ADD:
			printf("ADD\n");
			break;
		case SUB:
			printf("SUB\n");
			break;
		case MUL:
			printf("MUL\n");
			break;
		case DIV:
			printf("DIV\n");
			break;
		case MOD:
			printf("MOD\n");
			break;
		case AND:
			printf("AND\n");
			break;
		case OR:
			printf("OR\n");
			break;
		case MOV:
			printf("MOV\n");
			break;
		case CONDAND:
			printf("CONDAND\n");
			break;
		case CONDOR:
			printf("CONDOR\n");
			break;
		case NOT:
			printf("NOT\n");
			break;
		case LESS:
			printf("LESS\n");
			break;
		case GREAT:
			printf("GREAT\n");
			break;
		case LESSOREQ:
			printf("LESSOREQ\n");
			break;
		case GREATOREQ:
			printf("GREATOREQ\n");
			break;
		case ADDMOV:
			printf("ADDMOV\n");
			break;
		case SUBMOV:
			printf("SUBMOV\n");
			break;
		case MULMOV:
			printf("MULMOV\n");
			break;
		case DIVMOV:
			printf("DIVMOV\n");
			break;
		case MODMOV:
			printf("MODMOV\n");
			break;
		case RRNDBKT:
			printf("RRNDBKT\n");
			break;
		case LRNDBKT:
			printf("LRNDBKT\n");
			break;
		case COMMA:
			printf("COMMA\n");
			break;
		case SCLN:
			printf("SCLN\n");
			break;
		case CLN:
			printf("CLN\n");
			break;
		case INT_LITERAL:
			printf("INT_LITERAL: %d\n", yylval.iv);
			break;
		case DOUBLE_LITERAL:
			printf("DOUBLE_LITERAL: %f\n", yylval.dv);
			break;
		}
	}
	fclose(yyin);
}

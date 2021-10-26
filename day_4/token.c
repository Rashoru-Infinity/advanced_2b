#include "token.h"
#include <stdio.h>
#include <stdlib.h>

YYSTYPE yylval;
extern YYSTYPE yylval;
char *yytext;
extern char *yytext;
FILE *yyin;
extern FILE *yyin;	

int main(void) {
	int token_type;
	
	yyin = fopen("input.txt", "r");
	while ((token_type = yylex())) {
		switch(token_type) {
		case 258:
			printf("INTEGER");
			break;
		case 259:
			printf("DOUBLE");
			break;
		case 260:
			printf("IF");
			break;
		case 261:
			printf("ELSE");
			break;
		case 262:
			printf("ELSIF");
			break;
		case 263:
			printf("WHILE");
			break;
		case 264:
			printf("FOR");
			break;
		case 265:
			printf("RETURN");
			break;
		case 266:
			printf("BREAK");
			break;
		case 267:
			printf("CONTINUE");
			break;
		case 268:
			printf("TRUE");
			break;
		case 269:
			printf("FALSE");
			break;
		case 270:
			printf("BOOLEAN");
			break;
		case 271:
			printf("ADD");
			break;
		case 272:
			printf("SUB");
			break;
		case 273:
			printf("MUL");
			break;
		case 274:
			printf("DIV");
			break;
		case 275:
			printf("MOD");
			break;
		case 276:
			printf("AND");
			break;
		case 277:
			printf("OR");
			break;
		case 278:
			printf("MOV");
			break;
		case 279:
			printf("CONDAND");
			break;
		case 280:
			printf("CONDOR");
			break;
		case 281:
			printf("NOT");
			break;
		case 282:
			printf("LESS");
			break;
		case 283:
			printf("GRATE");
			break;
		case 284:
			printf("LESSOREQ");
			break;
		case 285:
			printf("GRATEOREQ");
			break;
		case 286:
			printf("ADDMOV");
			break;
		case 287:
			printf("SUBMOV");
			break;
		case 288:
			printf("MULMOV");
			break;
		case 289:
			printf("DIVMOV");
			break;
		case 290:
			printf("RRNDBKT");
			break;
		case 291:
			printf("LRNDBKT");
			break;
		case 292:
			printf("RCLYBKT");
			break;
		case 293:
			printf("LCLYBKT");
			break;
		case 294:
			printf("COMMA");
			break;
		case 295:
			printf("SCLN");
			break;
		case 296:
			printf("CLN");
			break;
		case 297:
			printf("INT_LITERAL");
			break;
		case 298:
			printf("DOUBLE_LITERAL");
			break;
		case 299:
			printf("IDENTIFIER");
			break;
		default:
			printf("EXCEPTION");
			break;
		}
		if (token_type == 297) { 
			printf(" : value = %d\n", yylval.int_value);
		} else if (token_type == 298) { 
			printf(" : value = %f\n", yylval.double_value);
		} else {
			printf(" : \"%s\"\n", yytext);
		}
	}
	fclose(yyin);
	free(yytext);
}

#ifndef SYNTAX_H
#define SYNTAX_H

typedef union YYSTYPE {
	int int_value;
	double double_value;
} YYSTYPE;

int yylex();
char *yyget_text();
extern YYSTYPE yylval;

#endif

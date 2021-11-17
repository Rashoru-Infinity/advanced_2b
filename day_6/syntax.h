#ifndef SYNTAX_H
#define SYNTAX_H
/*
typedef union YYSTYPE {
	int int_value;
	double double_value;
} YYSTYPE;
*/
int yyerror(char const *str);
int yylex();
//extern YYSTYPE yylval;

#endif

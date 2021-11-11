%{
#include <stdio.h>
#include "token.h"

enum yytokentype {
	INTEGER = 258,
	DOUBLE = 259,
	IF = 260,
	ELSE = 261,
	ELSIF = 262,
	WHILE = 263,
	FOR = 264,
	RETURN = 265,
	BREAK = 266,
	CONTINUE = 267,
	TRUE = 268,
	FALSE = 269,
	BOOLEAN = 270,
	ADD = 271,
	SUB = 272,
	MUL = 273,
	DIV = 274,
	MOD = 275,
	AND = 276,
	OR = 277,
	MOV = 278,
	CONDAND = 279,
	CONDOR = 280,
	NOT = 281,
	LESS = 282,
	GRATE = 283,
	LESSOREQ = 284,
	GRATEOREQ = 285,
	EQ = 286,
	NOTEQ = 287,
	ADDMOV = 288,
	SUBMOV = 289,
	MULMOV = 290,
	DIVMOV = 291,
	MODMOV = 292,
	RRNDBKT = 293,
	LRNDBKT = 294,
	RCLYBKT = 295,
	LCLYBKT = 296,
	COMMA = 297,
	SCLN = 298,
	CLN = 299,
	INT_LITERAL = 300,
	DOUBLE_LITERAL = 301,
	IDENTIFIER = 302,
	END = 303
};

int yywrap(void) {
	return 1;
}

extern YYSTYPE yylval;

%}
%%
"int" {
	return INTEGER;
}
"double" {
	return DOUBLE;
}
"if" {
	return IF;
}
"else" {
	return ELSE;
}
"elsif" {
	return ELSIF;
}
"while" {
	return WHILE;
}
"for" {
	return FOR;
}
"return" {
	return RETURN;
}
"break" {
	return BREAK;
}
"continue" {
	return CONTINUE;
}
"true" {
	return TRUE;
}
"false" {
	return FALSE;
}
"boolean" {
	return BOOLEAN;
}
"+" {
	return ADD;
}
"-" {
	return SUB;
}
"*" {
	return MUL;
}
"/" {
	return DIV;
}
"%" {
	return MOD;
}
"&" {
	return AND;
}
"|" {
	return OR;
}
"=" {
	return MOV;
}
"&&" {
	return CONDAND;
}
"||" {
	return CONDOR;
}
"!" {
	return NOT;
}
"<" {
	return LESS;
}
">" {
	return GRATE;
}
"<=" {
	return LESSOREQ;
}
">=" {
	return GRATEOREQ;
}
"+=" {
	return ADDMOV;
}
"-=" {
	return SUBMOV;
}
"*=" {
	return MULMOV;
}
"/=" {
	return DIVMOV;
}
"(" {
	return RRNDBKT;
}
")" {
	return LRNDBKT;
}
"{" {
	return RCLYBKT;
}
"}" {
	return LCLYBKT;
}
"," {
	return COMMA;
}
";" {
	return SCLN;
}
":" {
	printf("yytext : %s\n", yytext);
	return CLN;
}
([1-9][0-9]*)|0|(-[1-9][0-9])|-0 {
	int tmp;
	sscanf(yytext, "%d", &tmp);
	yylval.int_value = tmp;
	return INT_LITERAL;
}
([0-9]+\.[0-9][0-9]*)|(-[0-9]+\.[0-9][0-9]*) {
	double tmp;
	sscanf(yytext, "%lf", &tmp);
	yylval.double_value = tmp;
	return DOUBLE_LITERAL;
}
(([a-z]|[A-Z])([a-z]|[A-Z]|[0-9]|_)*) {
	printf("yytext : %s\n", yytext);
	return IDENTIFIER;}
[ \t\n\v\f\r] ;
%%

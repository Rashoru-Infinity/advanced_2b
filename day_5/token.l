%{
#include <stdio.h>
#include "syntax.h"
#include "y.tab.h"
/*
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
	ADDMOV = 286,
	SUBMOV = 287,
	MULMOV = 288,
	DIVMOV = 289,
	RRNDBKT = 290,
	LRNDBKT = 291,
	RCLYBKT = 292,
	LCLYBKT = 293,
	COMMA = 294,
	SCLN = 295,
	CLN = 296,
	INT_LITERAL = 297,
	DOUBLE_LITERAL = 298,
	IDENTIFIER = 299
};
*/

int yywrap(void) {
	return 1;
}

extern YYSTYPE yylval;

%}
%%
"int" return INTEGER;
"double" return DOUBLE;
"if" return IF;
"else" return ELSE;
"elsif" return ELSIF;
"while" return WHILE;
"for" return FOR;
"return" return RETURN;
"break" return BREAK;
"continue" return CONTINUE;
"true" return TRUE;
"false" return FALSE;
"boolean" return BOOLEAN;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;
"&" return AND;
"|" return OR;
"=" return MOV;
"&&" return CONDAND;
"||" return CONDOR;
"!" return NOT;
"<" return LESS;
">" return GRATE;
"<=" return LESSOREQ;
">=" return GRATEOREQ;
"+=" return ADDMOV;
"-=" return SUBMOV;
"*=" return MULMOV;
"/=" return DIVMOV;
"(" return RRNDBKT;
")" return LRNDBKT;
"{" return RCLYBKT;
"}" return LCLYBKT;
"," return COMMA;
";" return SCLN;
":" return CLN;
([1-9][0-9]*)|0|(-[1-9][0-9])|-0 {
	int tmp;
	sscanf(yytext, "%d", &tmp);
	yylval.iv = tmp;
	return INT_LITERAL;
}
([0-9]+\.[0-9][0-9]*)|(-[0-9]+\.[0-9][0-9]*) {
	double tmp;
	sscanf(yytext, "%lf", &tmp);
	yylval.dv = tmp;
	return DOUBLE_LITERAL;
}
(([a-z]|[A-Z])([a-z]|[A-Z]|[0-9]|_)*) {return IDENTIFIER;}
[ \t\n\v\f\r] ;
%%

%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
%}
%union {
    int iv;
    double dv;
}
%token <dv> DOUBLE_LITERAL
%token <iv> INT_LITERAL
%token INTEGER
%token DOUBLE
%token IF
%token ELSE
%token ELSIF
%token WHILE
%token FOR
%token RETURN
%token BREAK
%token CONTINUE
%token TRUE
%token FALSE
%token BOOLEAN
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token AND
%token OR
%token MOV
%token CONDAND
%token CONDOR
%token NOT
%token LESS
%token GRATE
%token LESSOREQ
%token GRATEOREQ
%token ADDMOV
%token SUBMOV
%token MULMOV
%token DIVMOV
%token RRNDBKT
%token LRNDBKT
%token RCLYBKT
%token LCLYBKT
%token COMMA
%token SCLN
%token CLN
%token IDENTIFIER
%%
translation_unit
	: statement
	;
statement
	: IDENTIFIER RRNDBKT LRNDBKT SCLN
	;

/*
line_list
    : line
    | line_list line
    ;
*/

%%
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}

/*
int main(void)
{
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }
}
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "syntax.h"
%}
%union {
    int iv;
    double dv;
	char *name;
}

%token DOUBLE_LITERAL
%token INT_LITERAL
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
%token GREAT
%token LESSOREQ
%token GREATOREQ
%token EQ
%token NOTEQ
%token ADDMOV
%token SUBMOV
%token MULMOV
%token DIVMOV
%token MODMOV
%token INCREMENT
%token DECREMENT
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
	: statement_list
	;

statement_list
	: statement
	| statement_list statement
	;

statement
	: expression SCLN
	;

expression
	: assignment_expression
	;

assignment_expression
	: logical_or_expression
	| postfix_expression assignment_operator assignment_expression {printf("assign\n");}
	;

assignment_operator
	: MOV {printf("=\n");}
	| ADDMOV {printf("+=\n");}
	| SUBMOV {printf("-=\n");}
	| MULMOV {printf("*=\n");}
	| DIVMOV {printf("/=\n");}
	| MODMOV {printf("%%=\n");}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression CONDOR logical_and_expression {printf("logical_or\n");}
	;

logical_and_expression
	: equality_expression
	| logical_and_expression CONDAND equality_expression {printf("logical_and\n");}
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression {printf("EQ\n");}
	| equality_expression NOTEQ relational_expression {printf("NE\n");}
	;

relational_expression
	: additive_expression
	| relational_expression GREAT additive_expression {printf("great\n");}
	| relational_expression LESS additive_expression {printf("less\n");}
	| relational_expression GREATOREQ additive_expression {printf("great_or_eq\n");}
	| relational_expression LESSOREQ additive_expression {printf("less_or_eq\n");}
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression {printf("add\n");}
	| additive_expression SUB multiplicative_expression {printf("sub\n");}
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression MUL unary_expression {printf("mul\n");}
	| multiplicative_expression DIV unary_expression {printf("div\n");}
	| multiplicative_expression MOD unary_expression {printf("mod\n");}
	;

unary_expression
	: postfix_expression
	| SUB unary_expression {printf("unary sub\n");}
	| NOT unary_expression {printf("unary exclamation\n");}
	;

postfix_expression
	: primary_expression
	| postfix_expression LRNDBKT RRNDBKT {printf("function call\n");}
	| postfix_expression INCREMENT {printf("increment\n");}
	| postfix_expression DECREMENT {printf("decrement\n");}
	;

primary_expression
	: LRNDBKT expression RRNDBKT {printf("LRNDBKT expr RRNDBKT\n");}
	| IDENTIFIER {printf("IDENTIFIER\n");}
	| INT_LITERAL {printf("INT_LITERAL\n");}
	| DOUBLE_LITERAL {printf("DOUBLE_LITERAL\n");}
	| TRUE {printf("TRUE\n");}
	| FALSE {printf("FALSE\n");}
	;

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

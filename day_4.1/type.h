#ifndef TYPE_H
#define TYPE_H
#include <unistd.h>

struct OPE *in_word_set(register const char *, register size_t);

struct OPE {
	char *name;
	int type;
};

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
	GREAT = 283,
	LESSOREQ = 284,
	GREATOREQ = 285,
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

typedef union {
	int iv;
	double dv;
	char *name;
} YYSTYPE;

YYSTYPE yylval;

#endif

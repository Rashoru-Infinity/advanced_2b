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
	EQ = 284,
	LESSOREQ = 285,
	GREATOREQ = 286,
	NOTEQ = 288,
	ADDMOV = 289,
	SUBMOV = 290,
	MULMOV = 291,
	DIVMOV = 292,
	MODMOV = 293,
	RRNDBKT = 294,
	LRNDBKT = 295,
	RCLYBKT = 296,
	LCLYBKT = 297,
	COMMA = 298,
	SCLN = 299,
	CLN = 300,
	INT_LITERAL = 301,
	DOUBLE_LITERAL = 302,
	IDENTIFIER = 303,
	END = 304
};

typedef union {
	int iv;
	double dv;
	char *name;
} YYSTYPE;

YYSTYPE yylval;

#endif

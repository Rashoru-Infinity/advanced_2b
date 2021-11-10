#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

char *yytext = NULL;
FILE *yyin = NULL;
static uint8_t offset = 0;

static void error_handler() {
	perror(strerror(errno));
	exit(errno);
}

static void append(char *src) {
	size_t src_len;
	size_t dest_len;
	char *tmp;

	if (!(src_len = strlen(src))) {
		return;
	}
	if (!yytext) {
		if (!(yytext = malloc(sizeof(char) * (src_len + 1)))) {
			error_handler();
		}
		strcpy(yytext, src);
		*(yytext + src_len) = '\0';
		return;
	}
	dest_len = strlen(yytext);
	if (!(tmp = realloc(yytext, sizeof(char) * (dest_len + src_len + 1)))) {
		free(yytext);
		error_handler();
	}
	memset(tmp + dest_len, 0, src_len + 1);
	strcat(tmp, src);
	yytext = tmp;
}

int yylex() {
	char buf[2];
	
	memset(buf, 0, 2);
	while (!feof(yyin)) {
		fread(buf, sizeof(char), 1, yyin);
		switch(*buf) {
		case ' ':
		case '\t':
		case '\n':
		case '\v':
		case '\f':
		case '\r':
			continue;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			append(buf);
			while (!feof(yyin)) {
				fread(buf, sizeof(char), 1, yyin);
				if (isdigit(*buf)) {
					append(buf);
				} else {
					break;
				}
			}
			if (*buf == '.') {
				uint8_t dbl_flg = 0;
				append(buf);
				while (!feof(yyin)) {
					fread(buf, sizeof(char), 1, yyin);
					if (isdigit(*buf)) {
						dbl_flg = 1;
						append(buf);
					} else {
						fseek(yyin, -1L, SEEK_CUR);
						break;
					}
				}
				if (dbl_flg) {
					sscanf(yytext + offset, "%lf", &(yylval.dv));
					offset = strlen(yytext);
					return DOUBLE_LITERAL;
				} else {
					fprintf(stderr, "double error\n");
					exit(1);
				}
			} else {
				sscanf(yytext + offset, "%d", &(yylval.iv));
				offset = strlen(yytext);
				fseek(yyin, -1L, SEEK_CUR);
				return INT_LITERAL;
			}
			break;
		case ';':
			return SCLN;
		case ':':
			return CLN;
		case '(':
			return LRNDBKT;
		case ')':
			return RRNDBKT;
		case '{':
			return LCLYBKT;
		case '}':
			return RCLYBKT;
		case ',':
			return COMMA;
		case '&':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '&') {
				return CONDAND;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return AND;
		case '|':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '|') {
				return CONDOR;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return OR;
		case '=':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return EQ;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return MOV;
		case '!':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return NOTEQ;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return NOT;
		case '>':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return GREATOREQ;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return GREAT;
		case '<':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return LESSOREQ;
			}
			return LESS;
		case '+':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return ADDMOV;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return ADD;
		case '-':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return SUBMOV;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return SUB;
		case '*':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return MULMOV;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return MUL;
		case '/':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return DIVMOV;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return DIV;
		case '%':
			fread(buf, sizeof(char), 1, yyin);
			if (*buf == '=') {
				return MODMOV;
			}
			fseek(yyin, -1L, SEEK_CUR);
			return MOD;
		default:
			append(buf);
			while (!feof(yyin)) {
				fread(buf, sizeof(char), 1, yyin);
				if (isdigit(*buf) || isalpha(*buf) || *buf == '_') {
					append(buf);
				} else if (isspace(*buf)) {
					break;
				} else {
					fseek(yyin, -1L, SEEK_CUR);
					break;
				}
			}
			if (!strlen(yytext + offset)) {
				break;
			}
			struct OPE *op = in_word_set(yytext + offset, strlen(yytext + offset));
			if (op) {
				offset = strlen(yytext);
				return op->type;
			}
			yylval.name = yytext + offset;
			offset = strlen(yytext);
			return IDENTIFIER;
		}
	}
	return END;
}

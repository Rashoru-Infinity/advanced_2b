#include <token.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <input.h>
#include <stdio.h>

static int isoperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static int isbrackets(char c) {
	return c == '(' || c == ')';
}

static token_t *extract_token(char *start, char *end, parse_status_t status) {
	token_t *new_token;
	size_t len;

	if (!start || !end || start >= end) {
		return NULL;
	}
	if (!(new_token = malloc(sizeof(token_t)))) {
		return NULL;
	}
	new_token->next = NULL;
	len = end - start;
	if (!(new_token->token = malloc(sizeof(len)))) {
		free(new_token);
		return NULL;
	}
	memcpy(new_token->token, start, len);
	*(new_token->token + len) = '\0';
	switch (status) {
	case zero:
		new_token->type = literal;
		break;
	case non_zero:
		new_token->type = literal;
		break;
	case brackets:
		new_token->type = separator;
		break;
	case op:
		new_token->type = operator;
		break;
	default:
		new_token->type = unknown;
	}
	return new_token;
}

void clear_tokens(token_t *tokens) {
	token_t *next;
	while (tokens) {
		next = tokens->next;
		free(tokens->token);
		free(tokens);
		tokens = next;
	}
}

token_t *tokenize(char *statement) {
	token_t *tokens = NULL;
	token_t *eol = NULL;
	parse_status_t status = init;
	char *start;
	if (!statement) {
		return NULL;
	}
	while (status != error) {
		switch(status) {
		case init:
			start = statement;
			if (*statement == '0') {
				status = zero;
			} else if (isdigit(*statement)) {
				status = non_zero;
			} else if (isoperator(*statement)) {
				status = op;
			} else if (isbrackets(*statement)) {
				status = brackets;
			} else if (!isspace(*statement)) {
				status = error;
			}
			statement++;
			break;
		case zero:
			if (!tokens) {
				if (!(tokens = extract_token(start, statement, status))) {
					return NULL;
				}
				eol = tokens;
			} else {
				if (!(eol->next = extract_token(start, statement, status))) {
					clear_tokens(tokens);
					return NULL;
				}
				eol = eol->next;
			}
			status = init;
			break;
		case non_zero:
			if (isdigit(*statement)) {
				statement++;
			} else {
				if (!tokens) {
					if (!(tokens = extract_token(start, statement, status))) {
						return NULL;
					}
					eol = tokens;
				} else {
					if (!(eol->next = extract_token(start, statement, status))) {
						clear_tokens(tokens);
						return NULL;
					}
					eol = eol->next;
				}
				status = init;
			}
			break;
		case brackets:
			if (!tokens) {
				if (!(tokens = extract_token(start, statement, status))) {
					return NULL;
				}
				eol = tokens;
			} else {
				if (!(eol->next = extract_token(start, statement, status))) {
					clear_tokens(tokens);
					return NULL;
				}
				eol = eol->next;
			}
			status = init;
			break;
		case op:
			if (!tokens) {
				if (!(tokens = extract_token(start, statement, status))) {
					return NULL;
				}
				eol = tokens;
			} else {
				if (!(eol->next = extract_token(start, statement, status))) {
					clear_tokens(tokens);
					return NULL;
				}
				eol = eol->next;
			}
			status = init;
			break;
		default:
			break;
		}
		if (status == init && !*statement) {
			break;
		}
	}
	if (status == error) {
		clear_tokens(tokens);
		printf("tokenize fail\n");
		return NULL;
	}
	return tokens;
}

#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
	init,
	zero,
	non_zero,
	brackets,
	op,
	error
} parse_status_t;

typedef enum {
	separator,
	operator,
	literal,
	unknown
} token_type_t;

typedef struct token_s {
	char *token;
	token_type_t type;
	struct token_s *next;
} token_t;

token_t *tokenize(char *statement);
void clear_tokens(token_t *tokens);

#endif

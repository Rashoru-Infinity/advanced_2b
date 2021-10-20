#ifndef PARSER_H
#define PARSER_H
#include <token.h>

typedef struct parse_tree_s {
	char *token;
	token_type_t type;
	struct parse_tree_s *right;
	struct parse_tree_s *left;
} parse_tree_t;

void clear_parse_tree(parse_tree_t * tree);
parse_tree_t *parse(token_t *tokens);

#endif

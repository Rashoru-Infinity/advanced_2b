#include <parser.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static parse_tree_t *number(token_t **tokens, int indent);
static parse_tree_t *factor(token_t **tokens, int indent);
static parse_tree_t *term(token_t **tokens, int indent);
static parse_tree_t *expression(token_t **tokens, int indent);

static parse_tree_t *number(token_t **tokens, int indent) {
	parse_tree_t * tree;

	if (!*tokens) {
		return NULL;
	}
	if (!(tree = malloc(sizeof(parse_tree_t)))) {
		return NULL;
	}
	*tree = (parse_tree_t){NULL, unknown, NULL, NULL};
	if ((*tokens)->type == literal) {
		tree->type = literal;
		if (!(tree->token = strdup((const char *)(*tokens)->token))) {
			free(tree);
			return NULL;
		}
	} else {
		free(tree);
		return NULL;
	}
	for (int i = 0;i < indent;i++) {
		printf(" ");
	}
	printf(":%s\n", (*tokens)->token);
	*tokens = (*tokens)->next;
	return tree;
}

static parse_tree_t *factor(token_t **tokens, int indent) {
	parse_tree_t * tree;

	for (int i = 0;i < indent;i++) {
		printf(" ");
	}
	printf("factor\n");
	if (!*tokens) {
		return NULL;
	}
	if ((*tokens)->type == literal) {
		if (!(tree = number(tokens, indent))) {
			free(tree);
			return NULL;
		}
	} else if ((*tokens)->type == separator) {
		if (strcmp((*tokens)->token, "(")) {
			return NULL;
		}
		for (int i = 0;i < indent;i++) {
			printf(" ");
		}
		printf("%s\n", (*tokens)->token);
		*tokens = (*tokens)->next;
		if (!*tokens) {
			return NULL;
		}
		if (!(tree = expression(tokens, indent + 2))) {
			clear_parse_tree(tree);
			return NULL;
		}
		if (!*tokens) {
			clear_parse_tree(tree);
			return NULL;
		}
		if (strcmp((*tokens)->token, ")")) {
			clear_parse_tree(tree);
			return NULL;
		}
		for (int i = 0;i < indent;i++) {
			printf(" ");
		}
		printf("%s\n", (*tokens)->token);
		*tokens = (*tokens)->next;
	} else {
		return NULL;
	}
	return tree;
}

static parse_tree_t *term(token_t **tokens, int indent) {
	parse_tree_t *tree;
	parse_tree_t *tmp;

	for (int i = 0;i < indent;i++) {
		printf(" ");
	}
	printf("term\n");
	if (!*tokens) {
		return NULL;
	}
	if (!(tree = factor(tokens, indent + 2))) {
			return NULL;
	}
	while (*tokens && (*((*tokens)->token) == '*' || *((*tokens)->token) == '/')) {
		for (int i = 0;i < indent;i++) {
			printf(" ");
		}
		printf("* | /\n");
		if (!(tmp = malloc(sizeof(parse_tree_t)))) {
			clear_parse_tree(tree);
		}
		tmp->left = tree;
		tmp->type = operator;
		if (!(tmp->token = strdup((const char *)((*tokens)->token)))) {
			clear_parse_tree(tmp);
			return NULL;
		}
		*tokens = (*tokens)->next;
		if (!(tmp->right = factor(tokens, indent + 2))) {
			clear_parse_tree(tmp);
			return NULL;
		}
		tree = tmp;
	}
	if (tree->type == unknown) {
		tmp = tree->left;
		free(tree);
		tree = tmp;
	}
	return tree;
}

static parse_tree_t *expression(token_t **tokens, int indent) {
	parse_tree_t *tree;
	parse_tree_t *tmp;

	for (int i = 0;i < indent;i++) {
		printf(" ");
	}
	printf("expression\n");
	if (!(tree = term(tokens, indent + 2))) {
			return NULL;
	}
	while (*tokens && (*((*tokens)->token) == '+' || *((*tokens)->token) == '-')) {
		for (int i = 0;i < indent;i++) {
			printf(" ");
		}
		printf("+ | -\n");
		if (!(tmp = malloc(sizeof(parse_tree_t)))) {
			clear_parse_tree(tree);
		}
		tmp->type = operator;
		tmp->left = tree;
		if (!(tmp->token = strdup((const char *)((*tokens)->token)))) {
			clear_parse_tree(tmp);
			return NULL;
		}
		*tokens = (*tokens)->next;
		if (!(tmp->right = term(tokens, indent + 2))) {
			clear_parse_tree(tmp);
			return NULL;
		}
		tree = tmp;
	}
	if (tree->type == unknown) {
		tmp = tree->left;
		free(tree);
		tree = tmp;
	}
	return tree;
}

parse_tree_t *parse(token_t *tokens) {
	int indent;

	indent = 0;
	printf("statement\n");
	parse_tree_t *tree = expression(&tokens, indent + 2);
	if (!tree || tokens) {
		clear_parse_tree(tree);
		printf("parse fail\n");
		return NULL;
	}
	printf("parse success\n");
	return tree;
}

void clear_parse_tree(parse_tree_t * tree) {
	if (tree) {
		clear_parse_tree(tree->right);
		clear_parse_tree(tree->left);
		free(tree->token);
		free(tree);
	}
}

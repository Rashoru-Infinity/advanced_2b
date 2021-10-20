#include <stdio.h>
#include <token.h>
#include <parser.h>
#include <stdlib.h>
#include <input.h>
#include <limits.h>
#include <string.h>

#ifdef CALC
int calc(parse_tree_t *p) {
	int n;

	if (p->type == literal) {
		n = atoi(p->token);
	} else {
		n = calc(p->left);
		if (!strcmp(p->token, "+")) {
			n += calc(p->right);
		} else if (!strcmp(p->token, "-")) {
			n -= calc(p->right);
		} else if (!strcmp(p->token, "*")) {
			n *= calc(p->right);
		} else {
			if (calc(p->right) == 0) {
				printf("devided by zero\n");
				return n > 0 ? INT_MAX : INT_MIN;
			}
			n /= calc(p->right);
		}
	}
	return n;
}
#endif

int main() {
	char *exp;
	parse_tree_t *p;
	token_t *t;

	exp = read_line(stdin);

	t = tokenize(exp);

	#ifdef TOKENIZER_TEST
	token_t *u;
	u = t;
	while (u) {
		switch (u->type) {
		case separator:
			printf("separator\n");
			break;
		case operator:
			printf("operator\n");
			break;
		case literal:
			printf("literal\n");
			break;
		default:
			printf("unknown\n");
		}
		printf("token : %s\n", u->token);
		u = u->next;
	}
	#endif

	p = parse(t);

	#ifdef CALC
	if (p) {
		printf("%d\n", calc(p));
	}
	#endif
	clear_parse_tree(p);
	clear_tokens(t);
	free(exp);
}

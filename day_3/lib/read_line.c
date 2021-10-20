#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_LEN 10

char *read_line(FILE *src) {
	int end_input = 0;
	int curr_len = 0;
	char buf[BUF_LEN];
	char *input = NULL;
	char *for_extend = NULL;

	if (!src) {
		return NULL;
	}
	while (!end_input) {
		memset(buf, 0, BUF_LEN);
		if (!fgets(buf, BUF_LEN - 1, src)) {
			free(input);
			return NULL;
		}
		if (input) {
			if (!(for_extend = realloc(input, curr_len + strlen(buf) + 1))) {
				free(input);
				return NULL;
			}
			input = for_extend;
			memset(input + curr_len, 0, strlen(buf) + 1);
		} else {
			if (!(input = calloc(strlen(buf), sizeof(char)))) {
				return NULL;
			}
		}
		memcpy(input + curr_len, buf, strlen(buf));
		curr_len += strlen(buf);
		if (strchr(buf, '\n')) {
			end_input = 1;
		}
	}
	return input;
}		

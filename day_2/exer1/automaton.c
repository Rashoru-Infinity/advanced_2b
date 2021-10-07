#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_LEN 10

static char *read_line() {
	int end_input = 0;
	int curr_len = 0;
	char buf[BUF_LEN];
	char *input = NULL;
	char *for_extend = NULL;

	while (!end_input) {
		memset(buf, 0, BUF_LEN);
		if (!fgets(buf, BUF_LEN - 1, stdin)) {
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

int main(void) {
	char *input = NULL;
	size_t read_index;
	int digit;
	int sign;
	int status;
	char *num;

	printf("INPUT: ");
	if (!(input = read_line())) {
		printf("fail to read stdin!\n");
		return 1;
	}
	read_index = 0;
	while (read_index < strlen(input) && input[read_index] != '\n' &&\
	input[read_index]) {
		status = 0;
		sign = 1;
		digit = 0;
		while (read_index < strlen(input) && input[read_index]) {
			switch (status) {
			case 0:
				if (input[read_index] == '+') {
					sign = 1;
					status = 1;
				} else if (input[read_index] == '-') {
					sign = -1;
					status = 2;
				} else if (input[read_index] == '0') {
					status = 3;
				} else if (isdigit(input[read_index])) {
					digit++;
					status = 4;
				} else if (input[read_index] == ' ') {
					status = 0;
				} else if (input[read_index] == '\n') {
					return 0;
				} else {
					status = 7;
				}
				read_index++;
				break;
			case 1:
				if (input[read_index] == '0') {
					status = 3;
				} else if (isdigit(input[read_index])) {
					digit++;
					status = 4;
				} else {
					status = 7;
				}
				read_index++;
				break;
			case 2:
				if (input[read_index] == '0') {
					status = 3;
				} else if (isdigit(input[read_index])) {
					digit++;
					status = 4;
				} else {
					status = 7;
				}
				read_index++;
				break;
			case 3:
				if (input[read_index] == ' ' || input[read_index] == '\n') {
					status = 5;
				} else {
					status = 7;
				}
				break;
			case 4:
				if (isdigit(input[read_index])) {
					digit++;
					read_index++;
				} else if (input[read_index] == ' ' || input[read_index] == '\n') {
					status = 5;
				} else {
					status = 7;
				}
				break;
			case 5:
				if (!(num = calloc(digit + 1, sizeof(char)))) {
					printf("fail to allocate memory!\n");
					free(input);
					return 1;
				}
				memcpy(num, input + read_index - digit, digit);
				printf("accept val = ");
				if (sign == -1) {
					printf("-");
				}
				printf("%s\n", num);
				free(num);
				num = NULL;
				status = 6;
				break;
			default:
				break;
			}
			if (status == 6) {
				break ;
			} else if (status == 7) {
				printf("invalid format!\n");
				return 1;
			}
		}
	}
	free(input);
}

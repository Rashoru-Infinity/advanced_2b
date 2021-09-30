#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int stack[100];
int next;

extern int stack[100];
extern int next;

extern void push(int value);
extern int pop();
void show();

int main(void) {
	memset(stack, 0, sizeof(int) * 100);
	next = 0;
	char s[100];
	int n;
	while (1) {
		memset(s, 0, 100);
		printf(">");
		if (!fgets(s, 99, stdin)) {
			exit(1);
		}
		int offset = 0;
		while (!isdigit(s[offset])) {
			++offset;
		}
		n = atoi(s + offset);
		if (!strncmp(s, "push", 4)) {
			push(n);
		}
		if (!strncmp(s, "pop", 3)) {
			printf("%3d\n", pop());
		}
		if (!strncmp(s, "show", 4)) {
			show();
		}
	}
}

void show() {
	if (next == 0) {
		printf("stack is empty\n");
		return ;
	}
	for (int i = next - 1;i >= 0;i--) {
		printf("%3d\n", stack[i]);
	}
}

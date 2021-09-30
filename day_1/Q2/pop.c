#include <stdio.h>

int stack[100];
int next;

extern int stack[100];
extern int next;

int pop() {
	if (next == 0) {
		printf("stack is empty\n");
		return -1;
	}
	return stack[--next];
}

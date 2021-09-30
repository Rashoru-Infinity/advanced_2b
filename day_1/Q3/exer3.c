#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union union_int {
	int i;
	long l;
	short s[2];
	char c[4];
}u;

int main(void) {
	char s[21];
	int input;
	memset(s, 0, sizeof(char) * 21);
	printf("Val\t:\t");
	if (!fgets(s, 20, stdin)) {
		exit(1);
	}
	u.i = atoi(s);
	printf("int\t:\t0x%08x\n", u.i);
	printf("long\t:\t0x%08x\n", (unsigned int)u.l);
	printf("short\t:\t0x%04x, 0x%04x\n", u.s[0], u.s[1]);
	printf("int\t:\t0x%02x, 0x%02x, 0x%02x, 0x%02x\n", u.c[0], u.c[1], u.c[2], u.c[3]);
}

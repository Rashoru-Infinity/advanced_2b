int stack[100];
int next;

extern int stack[100];
extern int next;

void push(int value) {
	if (next >= 100) {
		return ;
	}
	stack[next++] = value;
}

#include <stdio.h>

int global_i = 0;  // Visible to all funcs in every file.
static int global_static_i = 0;  // Visible only for funcs in same file.

int add(int a, int b) {
	return a + b;
}

int inc_static() {
	// Function call creates stack frame w/ local vars.
	// Static vars are allocated in data frame, not destroyed after func call.
	static int x = 0;
	x += 1;
	return x;
}

int main() {
	printf("3+5=%d\n", add(3, 5));

	printf("%d ", inc_static());
	printf("%d\n", inc_static());

	printf("global_i=%d\n", global_i);
	printf("global_static_i=%d\n", global_static_i);
}

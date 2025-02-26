#include <stdio.h>

void change_fail(int x) {
	// A new stack frame is created, x is copied and passed by value.
	x = 69;
}

void change_arr(int a[]) {
	// Arrays decay into pointers to first elem.
	a[0] = 69;
}

int main() {
	int a[3] = {1, 2, 3};
	printf("%d %d %d\n", a[0], a[1], a[2]);

	char s[] = "Hello";
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); ++i) {
		printf("%c %d   ", s[i], s[i]);
	}
	printf("\n");

	int x = 3;
	change_fail(x);
	printf("x=%d\n", x);

	change_arr(a);
	printf("a[0]=%d\n", a[0]);

	int* px = &x;
	printf("px=%p, *px=%d\n", px, *px);

	int md[2][3] = {{0, 1, 2}, {3, 4, 5}};
	printf("%d\n", md[1][0]);
}

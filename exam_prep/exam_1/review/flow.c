#include <stdio.h>

int main() {
	int a = 1;
	int b = 2;

	int min;
	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}
	printf("min=%d\n", min);

	min = a < b ? a : b;
	printf("min=%d\n", min);

	int i = 0;
	while (i < 10) {
		printf("%d ", i);
		++i;
	}
	printf("\n");

	for (i = 0; i < 10; ++i) {
		printf("%d ", i);
	}
	printf("\n");

	switch (b) {
		case 1: printf("1\n"); break;
		case 2: printf("2\n"); break;
		default: printf("other\n");
	}
}

#include <stdio.h>
#include <stdlib.h>

// Forward declaration of function.
int add(int, int);

int* rptr(int* p) {
	return p;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int (*f)(int, int) = add;
	printf("%d\n", f(3, 5));

	int* (*f1)(int*) = rptr;
	int a = 5;
	printf("%p\n", f1(&a));

	int nums[] = {5, 4, 3, 2, 1};
	qsort(nums, 5, sizeof(nums[0]), compare);
	for (int i = 0; i < 5; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int add(int a, int b) {
	return a + b;
}

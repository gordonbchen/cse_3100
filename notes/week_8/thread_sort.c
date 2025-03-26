#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Array {
	int* nums;
	int len;
} Array;

int compare_ints(const void* a, const void* b) {
	int ia = *(int*) a;
	int ib = *(int*) b;
	return ia - ib;
}

void* thread_sort(void* parr) {
	Array* arr = (Array*) parr;
	qsort(arr->nums, arr->len, sizeof(int), compare_ints);
	pthread_exit(NULL);
	return NULL;
}

void merge(Array* a, Array* b, int* out) {
	int ia = 0;
	int ib = 0;
	while ((ia < a->len) && (ib < b->len)) {
		if (a->nums[ia] <= b->nums[ib]) {
			out[ia + ib] = a->nums[ia];
			++ia;
		}
		else {
			out[ia + ib] = b->nums[ib];
			++ib;
		}
	}
	while (ia < a->len) {
		out[ia + ib] = a->nums[ia];
		++ia;
	}
	while (ib < b->len) {
		out[ia + ib] = b->nums[ib];
		++ib;
	}
}

int main() {
	srand(0);

	int n = 10;
	int u[n];
	int half = n / 2;
	int* a = u;
	int* b = u + half;

	for (int i = 0; i < n; ++i) {
		u[i] = rand() % n;
	}

	printf("Before sorting: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", u[i]);
	}
	printf("\n");

	Array array_a;
	array_a.nums = a;
	array_a.len = half;
	
	Array array_b;
	array_b.nums = b;
	array_b.len = n - half;

	pthread_t thread_a;
	pthread_t thread_b;
	pthread_create(&thread_a, NULL, thread_sort, &array_a);
	pthread_create(&thread_b, NULL, thread_sort, &array_b);
	pthread_join(thread_a, NULL);
	pthread_join(thread_b, NULL);

	int out[n];
	merge(&array_a, &array_b, out);
	
	printf("After sorting: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", out[i]);
	}
	printf("\n");

	return 0;
}


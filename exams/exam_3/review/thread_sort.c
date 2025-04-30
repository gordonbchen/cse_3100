#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_NUMS 32

void print_nums(int* x, int len) {
	printf("[");
	for (int i = 0; i < len; ++i) {
	  printf("%d ", x[i]);
	}
	printf("]\n");
}

int compare_ints(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

typedef struct {
	int* x;
	int len;
} array;

void sort_nums(void* thread_arg) {
	array* arr = (array*) thread_arg;
	qsort(arr->x, arr->len, sizeof(int), compare_ints);
}

int main() {
	int nums[N_NUMS];
	for (int i = 0; i < N_NUMS; ++i) {
		nums[i] = (rand() % 10);
	}
	print_nums(nums, N_NUMS);

	pthread_t threads[2];
	array thread_args[2];

	int half_len = N_NUMS / 2;
	thread_args[0].x = nums;
	thread_args[0].len = half_len;
	pthread_create(threads+0, NULL, (void*) sort_nums, thread_args+0);

	int* right_nums = nums + half_len;
	thread_args[1].x = right_nums;
	thread_args[1].len = half_len;
	pthread_create(threads+1, NULL, (void*) sort_nums, thread_args+1);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	print_nums(nums, N_NUMS);

	int merged_nums[N_NUMS];
	int i = 0, j = 0;
	while ((i < half_len) && (j < half_len)) {
		if (nums[i] < right_nums[j]) {
			merged_nums[i+j] = nums[i];
			++i;
		}
		else {
			merged_nums[i+j] = right_nums[j];
			++j;
		}
	}
	while (i < half_len) {
		merged_nums[i + j] = nums[i];
		++i;
	}
	while (j < half_len) {
		merged_nums[i + j] = right_nums[j];
		++j;
	}
	print_nums(merged_nums, N_NUMS);
}

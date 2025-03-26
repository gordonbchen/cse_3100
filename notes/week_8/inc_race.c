#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

void* inc(void* n_ptr) {
	int n = *((int*) n_ptr);
	for (int i = 0; i < n; ++i) {
		usleep(rand() % 100);
		++count;
	}
	pthread_exit(NULL);
}

int main() {
	int n_threads = 100;
	pthread_t threads[n_threads];
	int n = 1000;
	for (int i = 0; i < n_threads; ++i) {
		pthread_create(threads + i, NULL, inc, &n);
	}
	for (int i = 0; i < n_threads; ++i) {
		pthread_join(threads[i], NULL);
	}

	printf("count = %d\n", count);
}


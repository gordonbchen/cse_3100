#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_barrier_t barrier;

void* thread(void* id) {
	pthread_barrier_wait(&barrier);
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];

	int rc;
	long t;
	pthread_barrier_init(&barrier, NULL, NUM_THREADS);
	for (t = 0; t < NUM_THREADS; t++) {
	  rc = pthread_create(&threads[t], NULL, thread, (void*) t);
	}
	
	pthread_barrier_wait(&barrier);
	for (t = 0; t < NUM_THREADS; t++) {
	  pthread_join(threads[t], NULL);
	}
	pthread_barrier_destroy(&barrier);
	return 0;
}

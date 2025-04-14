#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_barrier_t barrier;

void* thread_func(void* arg) {
	int id = *(int*) arg;
	printf("BEFORE barrier: thread %d\n", id);
	// Waits until enough threads have hit barrier.
	pthread_barrier_wait(&barrier);
	printf("AFTER barrier: thread %d\n", id);
}

int main() {
	pthread_barrier_init(&barrier, NULL, 2);
	
	pthread_t t0, t1;
	int ids[2] = {0, 1};

	pthread_create(&t0, NULL, thread_func, &ids[0]);

	sleep(3);
	pthread_create(&t1, NULL, thread_func, &ids[1]);
	
	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	
	pthread_barrier_destroy(&barrier);
}

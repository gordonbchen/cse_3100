#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int max_buffer_size = 5;
int buffer_val = 0;
pthread_cond_t produced_cond;
pthread_cond_t consumed_cond;
pthread_mutex_t mtx;

void consumer(void) {
	printf("Consumer thread\n");
	while (1) {
		pthread_mutex_lock(&mtx);
		if (buffer_val == 0) {
			pthread_cond_wait(&produced_cond, &mtx);
		}
		--buffer_val;
		printf("Consumer took from buffer: %d\n", buffer_val);

		pthread_cond_signal(&consumed_cond);
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
}

void producer(void* arg) {
	printf("Producer %d thread\n", *((int*) arg));
	while (1) {
		pthread_mutex_lock(&mtx);
		if (buffer_val >= max_buffer_size) {
			pthread_cond_wait(&consumed_cond, &mtx);
		}
		++buffer_val;
		printf("Producer added to buffer: %d\n", buffer_val);
		
		pthread_cond_signal(&produced_cond);
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
}

int main(void) {
	pthread_mutex_init(&mtx, NULL);
	pthread_cond_init(&produced_cond, NULL);
	pthread_cond_init(&consumed_cond, NULL);

	pthread_t ct, p0t, p1t;
	pthread_create(&ct, NULL, (void*) consumer, NULL);
	
	int p0_name = 0;
	int p1_name = 1;
	pthread_create(&p0t, NULL, (void*) producer, &p0_name);
	pthread_create(&p1t, NULL, (void*) producer, &p1_name);

	pthread_join(ct, NULL);
	pthread_join(p0t, NULL);
	pthread_join(p1t, NULL);

	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&produced_cond);
	pthread_cond_destroy(&consumed_cond);
	return 0;
}

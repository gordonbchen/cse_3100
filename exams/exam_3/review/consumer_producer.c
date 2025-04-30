#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
	int n_items;
	int max_items;
	int n_remaining_items;
	pthread_mutex_t mutex;
	pthread_cond_t producer_cond;
	pthread_cond_t consumer_cond;
} thread_arg;

void producer_thread(void* targ) {
	thread_arg* arg = targ;

	while (1) {
		pthread_mutex_lock(&arg->mutex);
		while ((arg->n_remaining_items != 0) && (arg->n_items == arg->max_items)) {
			pthread_cond_wait(&arg->producer_cond, &arg->mutex);
		}
		
		if (arg->n_remaining_items == 0) {
			pthread_cond_signal(&arg->consumer_cond);
			pthread_mutex_unlock(&arg->mutex);
			break;
		}

		usleep(rand() % 1000);
		++arg->n_items;
		--arg->n_remaining_items;
		printf("Producer: n_items=%d, n_remaining_items=%d\n", arg->n_items, arg->n_remaining_items);
		
		pthread_cond_signal(&arg->consumer_cond);
		pthread_mutex_unlock(&arg->mutex);
	}
}

void consumer_thread(void* targ) {
	thread_arg* arg = targ;

	while (1) {
		pthread_mutex_lock(&arg->mutex);
		while ((arg->n_remaining_items != 0) && (arg->n_items == 0)) {
			pthread_cond_wait(&arg->consumer_cond, &arg->mutex);
		}
		if (arg->n_remaining_items == 0) {
			pthread_cond_signal(&arg->producer_cond);
			pthread_mutex_unlock(&arg->mutex);
			break;
		}
		
		usleep(rand() % 1000);
		--arg->n_items;
		printf("Consumer: n_items=%d\n", arg->n_items);

		pthread_cond_signal(&arg->producer_cond);
		pthread_mutex_unlock(&arg->mutex);
	}
}

int main() {
	thread_arg arg;
	arg.n_items = 0;
	arg.max_items = 5;
	arg.n_remaining_items = 20;
	pthread_mutex_init(&arg.mutex, NULL);
	pthread_cond_init(&arg.producer_cond, NULL);
	pthread_cond_init(&arg.consumer_cond, NULL);

	pthread_t t0;
	pthread_t t1;
	pthread_create(&t0, NULL, (void*) producer_thread, &arg);
	pthread_create(&t1, NULL, (void*) consumer_thread, &arg);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
}

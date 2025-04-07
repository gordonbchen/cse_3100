#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Counter {
	pthread_mutex_t _mtx;
	int _val;
} Counter;

Counter* make_counter() {
	Counter* c = malloc(sizeof(Counter));
	pthread_mutex_init(&(c->_mtx), NULL);
	c->_val = 0;
	return c;
}

void destroy_counter(Counter* c) {
	pthread_mutex_destroy(&(c->_mtx));
	free(c);
}


void inc_counter(Counter* c) {
	pthread_mutex_lock(&(c->_mtx));
	c->_val++;
	pthread_mutex_unlock(&(c->_mtx));
}


void* inc1000(void* c_ptr) {
	for (int i = 0; i < 1000; ++i) {
		usleep(rand() % 100);
		inc_counter((Counter*) c_ptr);
	}
	pthread_exit(NULL);
}

int main() {
	Counter* c = make_counter();

	int n_threads = 100;
	pthread_t threads[n_threads];
	for (int i = 0; i < n_threads; ++i) {
		pthread_create(threads + i, NULL, inc1000, c);
	}
	for (int i = 0; i < n_threads; ++i) {
		pthread_join(threads[i], NULL);
	}

	printf("count = %d\n", c->_val);
	destroy_counter(c);
}


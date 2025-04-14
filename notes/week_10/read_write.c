#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t rwlock;
int buffer_val = 0;

void reader(void* arg) {
	int reader_id = *(int*) arg;
	printf("HI reader %d\n", reader_id);
	while (1) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Reader %d read value: %d\n", reader_id, buffer_val);
		// No need to unlock here. Multiple readers can read lock.
		// Thread can get read lock if no writer has lock or is blocked on lock.
		// Thread gets write lock if no reader or other writer has lock.
		sleep(5);
	}
}

int main(void) {
	pthread_rwlock_init(&rwlock, NULL);

	int reader_ids[2];
	pthread_t readers[2];
	for (int i = 0; i < 2; ++i) {
		reader_ids[i] = i;
		pthread_create(readers+i, NULL, (void*) reader, reader_ids+i);
	}
	for (int i = 0; i < 2; ++i) {
		pthread_join(readers[i], NULL);
	}

	pthread_rwlock_destroy(&rwlock);
	return 0;
}

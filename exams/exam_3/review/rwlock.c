#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t rwlock;
int value = 0;

void reader(void* id) {
	while (1) {
		pthread_rwlock_rdlock(&rwlock);
		printf("Reader %d: %d\n", *(int*) id, value);

		if (value >= 5) {
			break;
		}
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void writer() {
	while (1) {
		pthread_rwlock_wrlock(&rwlock);
		 ++value;
		printf("Writer: %d\n", value);

		if (value >= 5) {
			pthread_rwlock_unlock(&rwlock);
			break;
		}
		pthread_rwlock_unlock(&rwlock);
		sleep(2);
	}
}

int main() {
	pthread_t t0;
	pthread_create(&t0, NULL, (void*) writer, NULL);
	
	pthread_t t1;
	int id1 = 0;
	pthread_create(&t1, NULL, (void*) reader, &id1);
	
	pthread_t t2;
	int id2 = 1;
	pthread_create(&t2, NULL, (void*) reader, &id2);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_rwlock_destroy(&rwlock);
}

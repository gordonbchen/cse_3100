#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int hours = 3;
int mins = 59;
int secs = 59;

pthread_mutex_t mtx;

void* clock_tick(void) {
	pthread_mutex_lock(&mtx);
	secs += 1;
	if (secs == 60) {
		secs = 0;
		mins += 1;

		if (mins == 60) {
			mins = 0;

			sleep(2);
			hours += 1;
		}
	}
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

void* read_time(void) {
	pthread_mutex_lock(&mtx);
	printf("%d %d %d\n", hours, mins, secs);
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

int main() {
	pthread_mutex_init(&mtx, NULL);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, (void*) clock_tick, NULL);
	pthread_create(&t2, NULL, (void*) read_time, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mtx);
}

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int hours = 3;
int mins = 59;
int secs = 59;

void* clock_tick(void) {
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
	pthread_exit(NULL);
}

void* read_time(void) {
	printf("%d %d %d\n", hours, mins, secs);
	pthread_exit(NULL);
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, (void*) clock_tick, NULL);
	pthread_create(&t2, NULL, (void*) read_time, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

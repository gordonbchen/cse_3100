#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* my_alarm(void* sec_ptr) {
	int sec = *((int*) sec_ptr);
	for (int i = 0; i < sec; ++i) {
		sleep(1);
		printf("sec = %d\n", i);
	}
	printf("Alarm done!\n");
	pthread_exit(NULL);
	return NULL;
}

void* fail(void* x_ptr) {
	sleep(5);
	int x = *((int*) x_ptr);
	int y = 1;
	int z = x / (y-1);
}

int main() {
	pthread_t thread1, thread2;
	int x = 10;
	pthread_create(&thread1, NULL, my_alarm, &x);
	pthread_create(&thread2, NULL, fail, &x);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}


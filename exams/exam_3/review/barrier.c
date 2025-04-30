#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


typedef struct {
	int id;
	int sleep_time;
	pthread_barrier_t* barrier;
} thread_arg;

void thread(void* targ) {
	thread_arg* arg = targ;

	sleep(arg->sleep_time);
	printf("Thread %d reached barrier, waiting!\n", arg->id);
	pthread_barrier_wait(arg->barrier);
	printf("Thread %d passed barrier!\n", arg->id);
}

int main() {
	pthread_barrier_t barrier;
	pthread_barrier_init(&barrier, NULL, 2);
	
	thread_arg arg0;
	arg0.id = 0;
	arg0.sleep_time = 0;
	arg0.barrier = &barrier;
	
	thread_arg arg1;
	arg1.id = 1;
	arg1.sleep_time = 3;
	arg1.barrier = &barrier;

	pthread_t thread0;
	pthread_create(&thread0, NULL, (void*) thread, &arg0);
	
	pthread_t thread1;
	pthread_create(&thread1, NULL, (void*) thread, &arg1);

	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
}

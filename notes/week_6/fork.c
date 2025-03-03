#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Before fork\n\n");
	int a = 5;

	pid_t pid = fork();
	printf("After fork\n");
	printf("pid=%d\n", pid);
	if (pid == 0) {
		printf("Child process\n");
	}
	else {
		printf("Parent process\n");
	}
	printf("a=%d\n", a);
	printf("\n");

	pid = fork();
	printf("\npid=%d", pid);
	printf("\n");
}

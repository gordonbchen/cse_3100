#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("Error creating fork");
		return 1;
	}

	if (pid == 0) {
		printf("Child: pid %d\n", pid);
	}
	else {
		waitpid(pid, NULL, 0);
		printf("Parent: pid %d\n", pid);
	}
}

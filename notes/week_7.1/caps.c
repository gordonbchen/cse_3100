#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1) {
		perror("Failed to create pipe");
		exit(-1);
	}

	pid_t pid = fork();
	if (pid == 0) {
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execlp("cat", "cat", "caps.c", NULL);
		printf("Child 1 failed to exec\n");
		exit(-1);
	}
	
	close(pipe_fd[1]);

	pid_t pid1 = fork();
	if (pid1 == 0) {
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		execlp("tr", "tr", "[a-z]", "[A-Z]", NULL);
		printf("Child 2 failed to exec\n");
		exit(-1);
	}

	close(pipe_fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid1, NULL, 0);
	return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
	int pipe_fd[2];
	pipe(pipe_fd);

	int sol[2];
	pid_t pid = fork();
	if (pid == 0) {
		sol[0] = 10;
		sol[1] = 15;

		close(pipe_fd[0]);
		write(pipe_fd[1], sol, sizeof(sol));
		close(pipe_fd[1]);
	}
	else {
		close(pipe_fd[1]);
		read(pipe_fd[0], sol, sizeof(sol));
		close(pipe_fd[0]);
		printf("sol: %d %d\n", sol[0], sol[1]);
	}
}


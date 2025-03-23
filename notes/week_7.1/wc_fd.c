#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("Failed to fork");
		return -1;
	}

	if (pid == 0) {
		int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1) {
			perror("Failed to open file");
			return -1;
		}

		dup2(fd, 1);
		close(fd);

		execlp("wc", "wc", argv[1], NULL);
		printf("Failed to execute wc\n");
		return -1;
	}
	else {
		printf("Parent printing to terminal!\n");
	}
}

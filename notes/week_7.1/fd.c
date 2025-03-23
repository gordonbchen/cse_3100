#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("dup.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		perror("Failed to open dup.txt");
		return -1;
	}
	printf("fd: %d\n", fd);

	int fd_copy = dup(fd);
	printf("fd_copy: %d\n", fd_copy);
	write(fd, "Writing from fd\n", 16);
	write(fd_copy, "Writing from fd_copy\n", 21);

	printf("Before dup2\n");
	dup2(fd, fileno(stdout));
	printf("After dup2\n");

	close(fd);
	close(fd_copy);

	printf("After closing fd and fd_copy\n");
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1) {
		perror("Error opening test.txt");
		exit(1);
	}

	printf("%d %d %d\n", fileno(stdin), fileno(stdout), fileno(stderr));
}

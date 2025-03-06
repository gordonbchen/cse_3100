#include <stdio.h>
#include <unistd.h>

int main() {
	char* cmd = "./adder";
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child\n");
		execl(cmd, cmd, "1", "2", "3", NULL);
		printf("PARENT FAILED\n");
		perror(cmd);
		return -1;
	}
	else {
		printf("Parent\n");
		execl(cmd, cmd, "10", "20", NULL);
		printf("PARENT FAILED\n");
		perror(cmd);
		return -1;
	}
}

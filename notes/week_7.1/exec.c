#include <stdio.h>
#include <unistd.h>
#include <error.h>

int main() {
	pid_t pid = fork();
	char* cmd = "./adder";
	if (pid == 0) {
		printf("Child: pid %d\n", pid);
		execl(cmd, cmd, "1", "2", "3", "4", NULL);
		printf("An error ocurred. This should never run.\n");
		perror(cmd);
		return 1;
	}
	else {
		printf("Parent: pid %d\n", pid);
		execl(cmd, cmd, "4", "5", "6", NULL);
		printf("An error ocurred. This should never run.\n");
		perror(cmd);
		return 1;
	}
}


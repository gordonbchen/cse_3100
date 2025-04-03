#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Usage: %s command\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork() failed.");
        exit(-1);
    }

    if (pid == 0) {
        printf("Child process\n");
        execvp(argv[1], argv+1);
        perror("execvp() failed");
        exit(-1);
    }

    waitpid(pid, NULL, 0);
    printf("Parent process\n");
    exit(0);
}

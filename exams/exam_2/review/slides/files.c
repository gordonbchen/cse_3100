#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork() failed");
        exit(-1);
    }

    if (pid == 0) {
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        dup2(fd, 1);
        close(fd);
        execlp("wc", "wc", argv[1], NULL);
        perror("execlp() failed");
        exit(-1);
    }

    waitpid(pid, NULL, 0);
    printf("Parent process\n");
}


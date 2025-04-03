#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pd[2];
    if (pipe(pd) == -1) {
        perror("pipe() failed");
        exit(-1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        dup2(pd[1], 1);
        close(pd[0]);
        close(pd[1]);

        execlp("cat", "cat", argv[1], NULL);
        perror("execlp() failed");
        exit(-1);
    }
    close(pd[1]);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pd[0], 0);
        close(pd[0]);

        execlp("tr", "tr", "[a-z]", "[A-Z]", NULL);
        perror("execlp() failed");
        exit(-1);
    }
    close(pd[0]);

    waitpid(pid, NULL, 0);
    waitpid(pid1, NULL, 0);
}


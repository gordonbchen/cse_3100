#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    // Run cmd 1.
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork()");
        exit(1);
    }
    else if (pid == 0) {
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp()");
        exit(1);
    }

    int exitStatus;
    pid = waitpid(pid, &exitStatus, 0);
    if (pid == -1) {
        perror("waitpid()");
        exit(1);
    }
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));

    // Run cmd 2;
    pid = fork();
    if (pid < 0) {
        perror("fork()");
        exit(1);
    }
    else if (pid == 0) {
        execvp(argv[3], &argv[3]);
        perror("execlp()");
        exit(1);
    }

    pid = waitpid(pid, &exitStatus, 0);
    if (pid == -1) {
        perror("waitpid()");
        exit(1);
    }
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

#define MAX 1000000

int main() {
    int pd[2];
    assert(pipe(pd) != -1);
    pid_t pid = fork();
    if (pid == 0) {
        char* msg = "Hello world!\n";
        close(pd[0]);
        for (int i = 0; i < MAX; i++) {
            write(pd[1], &msg[i], sizeof(char));
        }
        close(pd[1]);
        return 0;
    }
    close(pd[1]);
    waitpid(pid, NULL, 0);
    int count = 0, k;
    for (int i = 0; i < MAX; i++)
        if (read(pd[0], &k, sizeof(int))) count++;
    close(pd[0]);
    printf("count = %d\n", count);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pd[2];
    pipe(pd);

    int solution[2];
    pid_t pid = fork();
    if (pid == 0) {
        solution[0] = 10;
        solution[1] = 15;
        close(pd[0]);
        write(pd[1], solution, sizeof(solution));
        close(pd[1]);
        printf("Child: %d %d\n", solution[0], solution[1]);
    }
    else {
        sleep(2);
        close(pd[1]);
        read(pd[0], solution, sizeof(solution));
        printf("Parent: %d %d\n", solution[0], solution[1]);
        close(pd[0]);
    }
}
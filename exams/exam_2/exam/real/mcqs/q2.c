#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int count = 0;
    if (fork()) {
        printf("%p\n", &count);
        wait(NULL);
    }
    else {
        printf("%p\n", &count);
        count++;
    }
    printf("%d\n", count);
    return 0;
}
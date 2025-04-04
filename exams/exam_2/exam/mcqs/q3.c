#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char* args[] = {"ls", NULL};
    execv(args[0], args);
    printf("This is bad!\n");
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    printf("first line\n");
    int fd = open("dup2-output.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("Error opening file\n");
        return -1;
    }
    dup2(fd, 1);
    close(fd);
    printf("second line");
    return 0;
}
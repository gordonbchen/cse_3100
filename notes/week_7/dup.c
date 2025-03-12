#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {    
    int fd = open("dup.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);  // 3->dup.txt
    if (fd < 0) {
        printf("Failed to open file.\n");
        return -1;
    }
    
    int copy_fd = dup(fd);  // 4->dup.txt
    printf("%d %d\n", fd, copy_fd);

    write(copy_fd, "output to dup.txt\n", 18);
    write(fd, "output to dup.txt\n", 18);
    
    printf("Before dup2\n");
    dup2(fd, 1);  // 1->dup.txt
    printf("After dup2\n");
    
    close(copy_fd);
    close(fd);  // closes 3->dup.txt, 1 still -> dup.txt
    printf("After close\n");
    printf("After close\n");
}
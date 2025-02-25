#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;  // A global var defined in another file.

int main() {
    printf("errno=%d\n", errno);

    FILE* file_ptr;
    file_ptr = fopen("unexist.txt", "r"); 

    if (file_ptr == NULL) {
        printf("%d %s\n", errno, strerror(errno));
    }
    else {
        fclose(file_ptr);
    }
    return 0;
}

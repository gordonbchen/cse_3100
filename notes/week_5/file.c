#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", strerror(errno));
        return errno;
    }

    int MAX_LINE_LENGTH = 1000;
    char line[1000];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

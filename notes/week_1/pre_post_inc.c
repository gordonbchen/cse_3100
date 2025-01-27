#include <stdio.h>

int main(void) {
    int i = 0;
    printf("i=%d\n", i);

    int c = i++;
    printf("i=%d, c=%d\n", i, c);

    int d = ++i;
    printf("i=%d, d=%d\n", i, d);
}


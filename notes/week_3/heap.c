#include <stdio.h>
#include <stdlib.h>

size_t get_len(int x[]) {
    size_t len = sizeof(x) / sizeof(x[0]);
    return len;  // This will be wrong.
}

int main() {
    int* x = malloc(sizeof(int) * 8);
    if (x == NULL) {
        printf("Failed to malloc.\n");
        exit(1); 
    }
    printf("%d\n", x[7]);
    printf("sizeof(x)=%ld\n", sizeof(x));

    int a[8];
    int len = sizeof(a) / sizeof(a[0]);
    printf("sizeof(a)=%ld\n", sizeof(a));
    printf("len=%d\n", len);
    printf("get_len(a)=%ld\n", get_len(a));
}


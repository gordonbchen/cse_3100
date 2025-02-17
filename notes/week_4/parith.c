#include <stdio.h>
#include <stdlib.h>

int main() {
    int* x = malloc(3 * sizeof(int));
    printf("%p %p %p\n", x, x+1, x-1);
    
    printf("%ld\n", x+3 - x);
    printf("%ld\n", x - (x+3));

    printf("%d\n", x < (x+1));

    printf("%p %p\n", ((char*) x) + 1, (char*) (x + 1));
}


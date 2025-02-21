#include <stdio.h>

void swap(int* a, int*b) {
    printf("a=%p  b=%p  ", a, b);
    int c = *a;
    printf("c=%d\n", c);

    printf("*a=%d  *b=%d\n", *a, *b);
    *a = *b;
    printf("*a=%d  *b=%d\n", *a, *b);
    *b = c;
    printf("*a=%d  *b=%d\n", *a, *b);
}

void swap_bad(int* a, int*b) {
    printf("a=%p  b=%p  ", a, b);
    int* c = a;
    printf("c=%p  *c=%d\n", c, *c);

    printf("*a=%d  *b=%d\n", *a, *b);
    *a = *b;
    printf("*a=%d  *b=%d  *c=%d\n", *a, *b, *c);
    *b = *c;
    printf("*a=%d  *b=%d\n", *a, *b);
}

int main() {
    int a = 2;
    int b = 3;
    printf("%d, %d\n", a, b);
    
    swap_bad(&a, &b);
    printf("%d, %d\n", a, b);
}


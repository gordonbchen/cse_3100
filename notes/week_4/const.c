#include <stdio.h>

int main() {
    const int a = 1;
    const int b = 2;
    const int* pa = &a; // pointer to const int. pointer can point to different places.

    printf("%d\n", *pa);

    pa = &b;
    printf("%d\n", *pa);

    int c = 3;
    int* const pb = &b; // const pointer to int. int can change.
    printf("%d\n", *pb);
    c = 4;
    printf("%d\n", *pb);

    const int* const pc = &b; // const pointer to const int.
}

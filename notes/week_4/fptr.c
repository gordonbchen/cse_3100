#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int (*f_ptr)(int a, int b) = max;

    printf("%d\n", f_ptr(3, 4));
}

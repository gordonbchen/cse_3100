#include <stdio.h>

typedef enum {
    Red, Green, Blue
} Color;

int main() {
    Color r = Red;
    printf("%d %d %d %d\n", Red, Green, Blue, r);
}



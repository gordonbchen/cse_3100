#include <stdio.h>

struct bad {
    char a;
    int b;
};

struct good {
    int b;
    char a;
};

int main() {
    printf("%ld %ld\n", sizeof(struct bad), sizeof(struct good));

    struct bad b;
    struct good g;

    printf("%p, %p\n", &b.a, &b.b);
    printf("%p, %p\n", &g.b, &g.a);
}

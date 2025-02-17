#include <stdio.h>

struct coord {
    int x;
    int y;
};

void print_coord(struct coord* c) {
    printf("%d, %d\n", c->x, c->y);
}

typedef struct Person {
    char name[32];
    int age;
    char gender;
} TPerson;

int main() {
    struct coord c1;
    c1.x = 1;
    c1.y = 2;
    printf("%d, %d\n", c1.x, c1.y);
    print_coord(&c1);

    struct coord c2 = {2, 3};
    print_coord(&c2);

    struct coord cs[3] = {
        {3, 4},
        {4, 5},
        {5, 6}
    };
    for (int i = 0; i < sizeof(cs) / sizeof(cs[0]); ++i) {
        printf("%d: ", i);
        print_coord(cs+i);
    }

    TPerson me = {"Gordon", 18, 'm'};
    printf("%s, %d, %c\n", me.name, me.age, me.gender);
}


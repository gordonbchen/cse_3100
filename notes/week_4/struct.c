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

void birthday(TPerson* p) {
    ++(p->age);
}

void print_person(TPerson* p) {
    printf("%s, %d, %c\n", p->name, p->age, p->gender);
}


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
    print_person(&me);
    birthday(&me);
    print_person(&me);
}


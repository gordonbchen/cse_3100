#include <stdio.h>

int* get_arr() {
    static int nums[] = {1, 2};
    return nums;
}

void add_3(int* x, int* sol) {
    for (int i = 0; i < 3; ++i) {
        sol[i] = x[i] + 3;
    }
}

void add_3_inplace(int* x, int size) {
    for (int i = 0; i < size; ++i) {
        x[i] += 3;
    }
}

void show_arr(int* x, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main() {
    int x = 10;
    int* px = &x;
    *px = 20;

    printf("x=%d\n", *px);
    printf("&x=%p\n", &x);
    printf("&x=%p\n", px);
    printf("&px=%p\n", &px);

    int y = 11;
    printf("&y=%p\n", &y);
    
    int* a = get_arr();
    printf("%d, %d\n", a[0], a[1]);

    int nums[] = {1, 2, 3};
    int sol[3];
    add_3(nums, sol);
    show_arr(nums, 3);
    show_arr(sol, 3);

    add_3_inplace(nums, 3);
    show_arr(nums, 3);
}


#include <stdio.h>

void change(int x) {
    x = 69;
}

void change_arr(int x[]) {
    x[0] = 69;
}

int main() {
    int x = 0;
    printf("x=%d ", x);
    change(x);
    printf("x=%d\n", x);
    
    int x_arr[] = {0};
    printf("x_arr[0]=%d ", x_arr[0]);
    change_arr(x_arr);
    printf("x_arr[0]=%d\n", x_arr[0]);
}


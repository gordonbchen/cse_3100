#include <stdio.h>

int main(void) {
    int i = 3;
    int j = 2;
    if (i == j) {
        printf("i == j\n");
    }
    else if (i < j) {
        printf("i < j\n");
    }
    else {
        printf("i > j\n");
    }

    int min = (i < j) ? i : j;
    printf("min=%d\n", min);

    i = 0;
    int sum = 0;
    while (i < 100) {
        sum += i;
        ++i;
    }
    printf("sum=%d\n", sum);
    
    sum = 0;
    for (int i = 0; i < 100; ++i) {
        sum += i;
    }
    printf("sum=%d\n", sum);

    switch (min) {
        case 0: {
            printf("0\n",i);
            break;
        }
        case 2: {
            printf("2\n", j);
            break;
        }
        default: {
            printf("Default\n");
        }
    }
}


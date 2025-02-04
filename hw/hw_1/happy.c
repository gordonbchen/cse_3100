#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int m = n;
    int x;
    int ones;
    while ((n != 4) && (n != 1)) {
        x = 0;
        while (n != 0) {
            ones = n % 10;
            x += ones * ones;
            n /= 10;
        }
        n = x;
        printf("%d\n", n);
    }

    if (n == 1) {
        printf("%d is a happy number.\n", m);
    }
    else {
        printf("%d is NOT a happy number.\n", m);
    }
    return 0;
}

#include <stdio.h>

// Calculate x ^ y, where x and y are both positive ints. 
int power(int x, int y) {
    int p = 1;
    for (int i = 0; i < y; ++i) {
        p *= x;
    }
    return p;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    double pi = 0.0;
    double a, b;
    for (int i = 0; i <= n; ++i) {
        a = 8.0 * i;
        b = (4.0/(a+1.0)) - (2.0/(a+4.0)) - (1.0/(a+5.0)) - (1.0/(a+6.0));
        pi += b / power(16, i);
    }

    printf("PI = %.10f\n", pi);
    return 0;
}

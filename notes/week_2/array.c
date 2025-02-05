#include <stdio.h>

int main() {
    int x[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; ++i) {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str1[] = "Hello";
    printf("%s %s\n", str, str1);
    
    for (int i = 0; i < 6; ++i) {
        printf("%c%d ", str[i], str[i]);
    }
    printf("\n");
}


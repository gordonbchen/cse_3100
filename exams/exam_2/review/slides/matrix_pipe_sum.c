#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rows = 3;
    int cols = 4;
    int matrix[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int pd[2];
    pipe(pd);
    for (int i = 0; i < rows; ++i) {
         if (fork() == 0) {
            int row_sum = 0;
            for (int j = 0; j < cols; ++j) {
                row_sum += matrix[i][j];
            }
            write(pd[1], &row_sum, sizeof(row_sum));
            close(pd[0]);
            close(pd[1]);
            exit(0);
        }
    }

    int sum = 0;
    int row_sum;
    for (int i = 0; i < rows; ++i) {
        read(pd[0], &row_sum, sizeof(row_sum));
        sum += row_sum;
    }
    close(pd[0]);
    close(pd[1]);
    printf("sum = %d\n", sum);
}

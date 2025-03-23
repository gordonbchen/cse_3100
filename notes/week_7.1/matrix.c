#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 3

int main() {
	int A[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

	int pd[2];
	if (pipe(pd) == -1) {
		perror("Failed to create pipe");
		exit(-1);
	}

	for (int i = 0; i < N; ++i) {
		if (fork() == 0) {
			int row_sum = 0;
			for (int j = 0; j < N; ++j) {
				row_sum += A[i][j];
			}
			write(pd[1], &row_sum, sizeof(row_sum));
			return 0;
		}
	}
	
	int sum = 0;
	int row_sum = 0;
	for (int i = 0; i < N; ++i) {
		read(pd[0], &row_sum, sizeof(row_sum));
		sum += row_sum;
	}
	printf("sum = %d\n", sum);
}

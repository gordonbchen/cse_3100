#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_array(int* nums, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int compare_ints(const void* a, const void* b) {
	return *(int*) a - *(int*) b;
}

int main() {
	// Create array of random ints.
	int n = 10;
	int u[n];
	srand(42);
	for (int i = 0; i < n; ++i) {
		u[i] = rand() % n;
	}
	printf("Unsorted:\n");
	print_array(u, n);

	// Create process to sort first half.
	int fd1[2];
	if (pipe(fd1) == -1) {
		perror("Failed to create pipe");
		exit(-1);
	}

	pid_t pid1 = fork();
	if (pid1 == -1) {
		perror("Failed to fork");
		exit(-1);
	}
	
	int half = n / 2;
	if (pid1 == 0) {
		qsort(u, half, sizeof(int), compare_ints);
		write(fd1[1], u, half*sizeof(int));
		close(fd1[0]);
		close(fd1[1]);
		return 0;
	}
	close(fd1[1]);

	// Create process to sort second half.
	int fd2[2];
	if (pipe(fd2) == -1) {
		perror("Failed to create pipe");
		exit(-1);
	}

	pid_t pid2 = fork();
	if (pid2 == -1) {
		perror("Failed to fork");
		exit(-1);
	}
	
	int len2 = n - half;
	if (pid2 == 0) {
		qsort(u+half, len2, sizeof(int), compare_ints);
		write(fd2[1], u+half, len2*sizeof(int));
		close(fd2[0]);
		close(fd2[1]);
		return 0;
	}
	close(fd2[1]);

	read(fd1[0], u, half*sizeof(int));
	close(fd1[0]);
	read(fd2[0], u+half, len2*sizeof(int));
	close(fd2[0]);

	printf("\nSorted halves:\n");
	print_array(u, n);

	int merged[n];
	int ia = 0;
	int ib = 0;
	while ((ia < half) && (ib < len2)) {
		if (u[ia] < u[half + ib]) {
			merged[ia + ib] = u[ia];
			++ia;
		}
		else {
			merged[ia + ib] = u[half + ib];
			++ib;
		}
	}
	while (ia < half) {
		merged[ia + ib] = u[ia];
		++ia;
	}
	while (ib < len2) {
		merged[ia + ib] = u[half + ib];
		++ib;
	}

	printf("\nSorted:\n");
	print_array(merged, n);
}


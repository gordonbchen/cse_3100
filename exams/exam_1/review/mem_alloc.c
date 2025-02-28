#include <stdio.h>
#include <stdlib.h>

int main() {
	int* arr = malloc(sizeof(int) * 3);
	if (arr == NULL) {
		perror("malloc failed");
		exit(1);
	}
	
	arr[2] = 69;
	printf("%d\n", arr[2]);

	free(arr);

	arr = calloc(sizeof(int), 3);
	for (int i = 0; i < 3; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	arr = realloc(arr, 10*sizeof(int));
	arr[9] = 69;
	printf("%d\n", arr[9]);
	free(arr);
	arr = NULL;

	int* multi[3];
	for (int i = 0; i < 3; ++i) {
		multi[i] = malloc(sizeof(int) * 4);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			multi[i][j] = (i*4) + j;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%d ", multi[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; ++i) {
		free(multi[i]);
		multi[i] = NULL;
	}
}

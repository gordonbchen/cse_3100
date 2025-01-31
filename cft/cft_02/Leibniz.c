#include <stdio.h>

int main() {
	float sum = 0.0;
	int n = 10000;
	for (int i = 0; i <= n; ++i) {
		sum += 8.0 / (4.0*i + 1.0) / (4.0*i + 3.0);
	}

	printf("The sum is %.2f\n", sum);
	return 0;
}

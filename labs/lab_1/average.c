#include <stdio.h>

int main(void) {
	double total = 0.0;
	double average = 0.0;
	int n_nums = 0;

	double x;
	while (scanf("%lf", &x) == 1) { 
		total += x;
		++n_nums;
		average = total / n_nums;

		printf("Total=%f Average=%f\n", total, average);
	}

	return 0;
}


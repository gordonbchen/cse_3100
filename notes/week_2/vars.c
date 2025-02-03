#include <stdio.h>

int global_x = 5;
void inc_global_x() {
	++global_x;
}

static double pi = 3.14;
double calc_area(double radius) {
	return pi * radius * radius;
}

int static_func() {
	static int x = 0;
	++x;
	return x;
}

int main() {
	printf("%d\n", static_func());
	printf("%d\n", static_func());
	
	inc_global_x();
	printf("%d\n", global_x);

	printf("%f\n", calc_area(1.0));
}


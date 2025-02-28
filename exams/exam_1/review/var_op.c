#include <stdio.h>
#include <stdint.h>

#define TRUE 1

int main(void) {
	int i = 0;
	int a = i++;  // a = i, then i += 1.
	int b = ++i;  // i += 1; then b = i.
	printf("i++=%d ++i=%d\n", a, b);

	printf("sizeof: char=%ld, short=%ld, int=%ld, long=%ld, long long=%ld\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
	printf("sizeof: int=%ld, unsigned int=%ld\n", sizeof(int), sizeof(unsigned int));
	printf("sizeof: float=%ld, double=%ld, long double=%ld\n", sizeof(float), sizeof(double), sizeof(long double));
	
	printf("sizeof: int32_t=%ld\n", sizeof(int32_t));
	printf("TRUE: %d\n", TRUE);

	printf("10.0 / 3 = %f\n", ((double) 10) / 3);
}

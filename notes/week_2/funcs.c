#include <stdio.h>

#define MIN(x,y) (x<y ? x : y)

int add(int x, int y) {
	return x + y;
} 

void add_print(int x, int y) {
	printf("%d\n", x+y);
}

int subtract(int, int);

int main(void) {
	int a = 2;
	int b = 3;

	int c = add(a,b);
	printf("%d\n", c);
	
	add_print(a, b);
	
	printf("%d\n", subtract(a,b));
	printf("%d\n", MIN(a,b));
}

int subtract(int x, int y) {
	return x - y;
}


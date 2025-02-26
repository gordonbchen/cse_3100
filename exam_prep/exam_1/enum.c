#include <stdio.h>

typedef enum {
	Red, Green, Blue
} Color;

int main() {
	Color c = Red;
	printf("%d %d %d %d\n", c, Red, Green, Blue);
}

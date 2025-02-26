#include <stdio.h>

// Structs are padded to maintain alignment (int multiples of size).
// Define largest to smallest.
typedef struct PersonT {
	char name[32];
	int age;
	char gender;
} Person;

void print_person(Person* p) {
	printf("name=%s, age=%d, gender=%c\n", p->name, p->age, p->gender);
}

int main() {
	int a = 2;
	int* pa = &a;
	printf("%p, %p, %ld\n", pa, pa+1, (pa+1) - pa);

	Person me = {"Gordon", 18, 'M'};
	print_person(&me);
}

#include <stdio.h>

int main() {
	const int a = 10;    // const int. can't change a.
	const int* pa = &a;  // pointer to const int. can't change *pa, can change pa.

	int b = 7;
	int* const pb = &b;  // const pointer to int. can change *pb, can't change pb.

	const int* const pc = &a; // const pointier to const int. *can't change pc or *pc
}

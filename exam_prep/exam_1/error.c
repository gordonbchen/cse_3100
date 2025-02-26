#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;  // extern means global but defined in other file.

int main() {
	FILE* pf = fopen("fail.txt", "r");
	if (pf == NULL) {
		printf("errno=%d: %s\n", errno, strerror(errno));
		perror("perror");
	}
	else {
		fclose(pf);
	}
}

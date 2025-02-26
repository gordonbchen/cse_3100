#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("io.c filename\n");
		exit(1);
	}
	
	FILE* pf = fopen(argv[1], "r+");
	if (pf == NULL) {
		perror("Failed to open file");
		exit(errno);
	}

	char line[100];
	while (fgets(line, 100, pf)) {
		printf("%s", line);
	}

	fprintf(pf, "\nHELLO!");

	printf("# bytes in file: %ld\n", ftell(pf));

	fclose(pf);
}


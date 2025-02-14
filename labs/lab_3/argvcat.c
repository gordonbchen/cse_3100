#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    int len = strlen(s1) + strlen(s2) + 1;
    char* s3 = (char*) malloc(len * sizeof(char));
    if (s3 == NULL) {
        my_error("Failed to malloc.\n");
    }
    s3[0] = '\0';
    s3 = strcat(s3, s1);
    s3 = strcat(s3, s2);
    return s3;
}

int main(int argc, char *argv[])
{
    char *s;
    char *prev;
    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i++) {
        prev = s;
        s = my_strcat(prev, argv[i]);
        free(prev);
    }

    printf("%s\n", s);

    free(s);
    return 0;
}

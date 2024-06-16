#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char bfr[5], str[5];
    // char cnst[5] = "Hello World.\n";
    int len = sizeof(bfr);

    // strcpy(str, "Hello World.\n");

    for (int i = 0; i < len + 2; i++) {
        bfr[i] = 65;
        printf("%s\n", bfr);
    }

    exit(EXIT_SUCCESS);
}
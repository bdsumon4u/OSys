#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    while (1) {
        printf("Loop.\n");
    }
}

// gcc -o stress stress-infinite-loop.c && ./stress-infinite-loop

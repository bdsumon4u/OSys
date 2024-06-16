#include <stdio.h>
#include <stdlib.h>

int main();
void fun() {
    unsigned long* return_address = (unsigned long*)main;

    for (int i = 0; i < 5; i++) {
        *(return_address+i) = 'T';
    }
}

int main() {
    char buf[5];
    for (int i = 0; i < 5; i++) {
        buf[i] = 'H';
    }
    fun();

    printf("Main: %s\n", buf);

    exit(EXIT_SUCCESS);
}

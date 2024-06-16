#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    printf("Address of main: %p\n", main);
    printf("Address of argc: %p\n", &argc);
    printf("Address of argv: %p\n", &argv);

    int amiPariNa;

    printf("Address of amiPariNa: %p\n", &amiPariNa);

    int pid = fork();
    if (pid == 0) {
        for (int i = 0; i < 500; i++)
        {
            printf("[Child]: %d\n", i);
        }
        
    } else {
        int pid = fork();
        if (pid == 0) {
            for (int i = 0; i < 200; i++)
            {
                printf("[Nest]: %d\n", i);
            }
        } else {
            wait(NULL);
            for (int i = 0; i < 200; i++)
            {
                printf("[Parent]: %d\n", i);
            }
        }
    }

    exit(0);
}
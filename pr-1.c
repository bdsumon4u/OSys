#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Fork Failed!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        int i = 0;
        while(1) {
            printf("Child: %d; PID: %u\n", i, getpid());
            i++;
        }
        exit(EXIT_SUCCESS);
    } else {
        sleep(3);
        printf("Parent: PID: %u\n", getpid());
        // wait(NULL);
    }

    exit(EXIT_SUCCESS);
}

// exec

// execlp
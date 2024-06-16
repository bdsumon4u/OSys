#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork Failed!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("I'm child.\n");
        sleep(20);
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent: PID: %u, My Child: %u\n", getpid(), pid);
        exit(EXIT_SUCCESS);
    }

    exit(EXIT_SUCCESS);
}

// gcc -o zombie zombie-process.c && ./zombie
// ps aux | grep zombie

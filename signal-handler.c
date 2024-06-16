/*
    **Signal Handler
    **Interrupt Handler
    ***System Call Handler
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void signal_handler(int sig) {
    printf("Found Signal: %d\n", sig);
}

int main() {
    for (int i = 1; i <= 64; i++) {
        signal(i, signal_handler);
        kill(getpid(), i);
    }

    /*
        Can Handle: 1-8 10-18 20-31 34-64

        Can't Handle: 9:SIGKILL 19:SIGSTOP

        Unknown: 32-33
    */

    exit(EXIT_SUCCESS);
}
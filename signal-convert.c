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

void sigint_handler(int sig) {
    // printf("SIGINT.\n");
    kill(getpid(), SIGILL);
}

void sigill_handler(int sig) {
    printf("Performed SIGILL.\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGILL, sigill_handler);
    
    for (int i = 1; i <= 100; i++) {
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}
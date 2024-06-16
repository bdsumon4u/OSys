#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        int i = 0;
        while (1) {
            printf("Child: %d\n", ++i);
            usleep(250000);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            printf("Parent: %d\n", i+1);
            sleep(1);
        }
        int killFlg = kill(pid, SIGKILL);
        if(killFlg == 0){
            printf("Successfully killed child process\n");
        }
    }

    exit(EXIT_SUCCESS);
}
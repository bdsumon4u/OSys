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
        for (int i = 0; i < 5; i++) {
            printf("Child: %d\n", i+1);
            sleep(1);
        }
        int killFlg = kill(getppid(), SIGKILL);
        if(killFlg == 0){
            printf("Successfully killed parent process\n");
        }
    } else {
        int i = 0;
        while (1) {
            printf("Parent: %d\n", ++i);
            usleep(250000);
        }
    }

    exit(EXIT_SUCCESS);
}
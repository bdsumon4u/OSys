#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
            usleep(350000);
            if(!kill(getppid(), SIGKILL)) {
                printf("Parent process has been killed by child process.\n");
                // break;
            }
        }
    } else {
        wait(NULL);
        int i = 0;
        while (1) {
            printf("Parent: %d\n", ++i);
            sleep(1);
            if(!kill(pid, SIGKILL)) {
                printf("Child process has been killed by parent process.\n");
                break;
            }
        }
    }

    exit(EXIT_SUCCESS);
}
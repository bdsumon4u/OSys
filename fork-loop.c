#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int cores = sysconf(_SC_NPROCESSORS_ONLN);
    cores = 3;

    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    int *count = (int*)shmat(shmid, NULL, 0);

    for (int i = 1; i <= cores; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            // exit(EXIT_SUCCESS);
        } else {
            // exit(EXIT_SUCCESS);
        }
    }

    for (int i = 1; i <= cores; i++) {
        int status;
        pid_t wpid = waitpid(-1, &status, 0);
        if (wpid == -1) {
            break;
        }
        *count = *count+1;
        printf("Child process %d with PID %d has terminated\n", *count, wpid);
    }

    exit(EXIT_SUCCESS);
}
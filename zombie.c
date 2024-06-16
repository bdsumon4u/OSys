// Zombie: Living Dead.
// 1. A zombie is a process that has completed execution but still has an entry in the process table.
// 2. The entry is still needed to allow the parent process to read the child's exit status.
// 3. Once the exit status is read via the wait system call, the zombie's entry is removed from the process table and it is said to be "reaped".
// 4. If a parent fails to call wait, the zombie will be left in the process table.
// 5. Zombies can be identified in the output of the ps command.
// 6. Zombies are not dangerous, but they can be a sign of a bug in the program.
// 7. To remove zombies from the system, the parent must execute the wait system call to read the exit status of the child.
// 8. If the parent does not issue a wait, the zombie will stay in the process table.
// 9. If the parent is unable to issue a wait, the parent process can issue a signal to the child process to reap it.
// 10. The SIGCHLD signal is sent to the parent process when the child process terminates.
// 11. The parent process can then call wait to read the child's exit status.
// 12. If the parent ignores the SIGCHLD signal, the zombie will stay in the process table.
// 13. If the parent catches the SIGCHLD signal, the parent can call wait to read the child's exit status.
// 14. If the parent catches the SIGCHLD signal, the parent can call waitpid to read the child's exit status.
// 15. If the parent catches the SIGCHLD signal, the parent can call waitid to read the child's exit status.
// 16. If the parent catches the SIGCHLD signal, the parent can call wait3 to read the child's exit status.
// 17. If the parent catches the SIGCHLD signal, the parent can call wait4 to read the child's exit status.

// Create a zombie process.
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
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent: PID: %u, My Child: %u\n", getpid(), pid);
        sleep(20);
        // wait(NULL);
    }

    exit(EXIT_SUCCESS);
}

// gcc -o zombie zombie.c && ./zombie
// ps -l
// ps -l | grep zombie
// kill -9 <zombie_pid>

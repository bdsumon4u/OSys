#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int x = 5, y =2;

void *sum() {
    for (int i = 0; i < 300; i++) {
        printf("%d+%d: %d\n", x, y, x + y);
    }
}

void *sub() {
    for (int i = 0; i < 300; i++) {
        printf("%d-%d: %d\n", x, y, x - y);
    }
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sub, NULL);

    printf("T1: %lu; T2: %lu\n", t1, t2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    exit(EXIT_SUCCESS);
}

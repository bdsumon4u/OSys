#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_key;
int balance = 0;

void *deposit(void *amount) {
    for (int i = 0; i < 100; i++) {
        sem_wait(&sem_key);
        balance += *(int*)amount;
        printf("%d: After deposit: %d\n", i, balance);
        sem_post(&sem_key);
    }

    // return NULL;
}

void *withdraw(void *amount) {
    for (int i = 0; i < 100; i++) {
        sem_wait(&sem_key);
        balance -= *(int*)amount;
        printf("%d: After withdraw: %d\n", i, balance);
        sem_post(&sem_key);
    }

    // return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem_key, 0, 1); // 1: binary semaphore (mutex), 0: shared between threads (not processes)

    int amount = 10;

    pthread_create(&t1, NULL, deposit, (void*)&amount);
    pthread_create(&t2, NULL, withdraw, (void*)&amount);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    exit(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

pthread_mutex_t K1, K2;

void *thread1routine() {
    // pthread_mutex_lock(&K1);
    // pthread_mutex_lock(&K1);
    // pthread_mutex_lock(&K1);
    // pthread_mutex_lock(&K1);
    sleep(1);
    // pthread_mutex_unlock(&K2);
    // pthread_mutex_unlock(&K2);
    // pthread_mutex_lock(&K2);
    // pthread_mutex_lock(&K2);
}

void *thread2routine() {
    // pthread_mutex_lock(&K1);
    // pthread_mutex_lock(&K2);
    // pthread_mutex_unlock(&K1);
    // pthread_mutex_unlock(&K2);
    sleep(1);
    // pthread_mutex_unlock(&K2);
    // pthread_mutex_unlock(&K1);
    // pthread_mutex_unlock(&K2);
    // pthread_mutex_unlock(&K1);
}

int main() {
    pthread_mutex_init(&K1, NULL);
    pthread_mutex_init(&K2, NULL);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread1routine, NULL);
    pthread_create(&tid2, NULL, thread2routine, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    exit(EXIT_SUCCESS);
}

/*

T1            T2
-----------------------
Lock K1     | Lock K1
Unlock K2   | Unlock K2
= DeadLock


T1            T2
-----------------------
Lock K1     | Lock K2
Unlock K2   | Unlock K1
= NotLock


T1            T2
-----------------------
Lock K1     | Unlock K1
Lock K2     | Unlock K2
= NotLock


T1            T2
-----------------------
Lock K1     | Unlock K2
Lock K2     | Unlock K1
= NotLock

*/
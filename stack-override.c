#include <stdio.h>
#include <stdlib.h>

void main() {
    char buf[5];
    char buf1[15];
    char x;
    char str[5];
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("&buf[%d]: %lu\n", i, (unsigned long)(buf+i));
    }

    for (int i = 0; i < 5; i++) {
        printf("&buf1[%d]: %lu\n", i, (unsigned long)(buf1+i));
    }
    printf("%lu\n", (unsigned long)&x);
    for (int i = 0; i < 5; i++) {
        printf("&str[%d]: %lu\n", i, (unsigned long)(str+i));
    }
    printf("\n\n");
    for (int i = 0; i < 5; i++) {
        printf("&arr[%d]: %lu\n", i, (unsigned long)(arr+i));
    }
    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%d%c", arr[i], " \n"[i==5-1]);
    }
    int len = sizeof(buf);
    for (int i = 0; i < len+3; i++) {
        buf[i] = 'H';
    }
    for (int i = 0; i < 5; i++) {
        printf("%d%c", arr[i], " \n"[i==5-1]);
    }
}
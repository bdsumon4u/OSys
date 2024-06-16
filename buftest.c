#include <stdio.h>
#include <string.h>
// #define N 5

void test() {
    const int N = 5;
    char buf1[N], buf2[N];
    printf("|---------------------------------------|\n");
    for (int i = 0; i < N; i++)
    {
        buf1[i] = 'A' + i;
        printf("| &buf1[%d]: %lu, buf1[%d]: %c |\n", i, (unsigned long)(buf1+i), i, buf1[i]);
    }
    printf("| ------------------------------------- |\n");
    for (int i = 0; i < N; i++)
    {
        buf2[i] = 'A' + i;
        printf("| &buf2[%d]: %lu, buf2[%d]: %c |\n", i, (unsigned long)(buf2+i), i, buf2[i]);
    }
    printf("|---------------------------------------|\n");
}

void atest() {
    const int N = 5;
    char buf1[] = {'a', 'b', 'c', 'd', 'e'}, buf2[] = {'a', 'b', 'c', 'd', 'e'};
    printf("|---------------------------------------|\n");
    for (int i = 0; i < N; i++)
    {
        printf("| &buf1[%d]: %lu, buf1[%d]: %c |\n", i, (unsigned long)(buf1+i), i, buf1[i]);
    }
    printf("| ------------------------------------- |\n");
    for (int i = 0; i < N; i++)
    {
        printf("| &buf2[%d]: %lu, buf2[%d]: %c |\n", i, (unsigned long)(buf2+i), i, buf2[i]);
    }
    printf("|---------------------------------------|\n");
}

void ptest() {
    printf("|---------------------------------------|\n");
    char *ptr1 = "Hotash", *ptr2 = "Tech";
    for (int i = 0; i < strlen(ptr1); i++)
    {
        printf("| &ptr1[%d]: %lu, ptr1[%d]: %c |\n", i, (unsigned long)(ptr1+i), i, ptr1[i]);
    }
    printf("| ------------------------------------- |\n");
    for (int i = 0; i < strlen(ptr2); i++)
    {
        printf("| &ptr2[%d]: %lu, ptr2[%d]: %c |\n", i, (unsigned long)(ptr2+i), i, ptr2[i]);
    }
    printf("|---------------------------------------|\n");
}

void main() {
    for (int i = 1; i <= 10; i++)
    {
        printf("Test %d\n", i);
        atest();
        printf("\n");
    }
}
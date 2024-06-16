#include <stdio.h>

void main() {
    printf("Hi.\n");
}
// gcc -o strace strace.c && ./strace
// strace ./strace
// strace -e trace=signal ./strace
// strace -e trace=fork,execve ./strace
/*
    3 (7) types of files in linux

    @See:
        - Linux Case Study
        - Windows Case Study
    
    -: Regular File
    d: Directory
    c: Character Device
    b: Block Device
    l: Symbolic Link
    s: Socket
    p: Pipe

    ls: list files
    ls -a: list all files
    ls -i: list inode number
    ls -l: list file details
    ls -lh: list file details with human readable format
    ls -R: list files recursively
    ls -t: list files by time
    ls -S: list files by size
    ls -r: list files in reverse order
    ls -1: list files in single column
    ls -d: list directories
    ls -F: list files with type
    ls -p: list files with type
    ls -q: list files with type
    ls -Q: list files with type
    ls -s: list files with size
    ls -x: list files in horizontal format
    ls -X: list files in horizontal format
    ls -Z: list files with security context
    ls -c: list files by time
*/

#include <signal.h>

int main() {
    kill(0, SIGKILL);
}
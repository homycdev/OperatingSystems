#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int s, d;
    char *src, *dest;

    size_t fsize;

    s = open("ex1.txt", O_RDONLY);
    fsize = lseek(s, 0, SEEK_END);

    src = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, s, 0);

    d = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(d, fsize);

    dest = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, d, 0);

    memcpy(dest, src, fsize);

    munmap(src, fsize);
    munmap(dest, fsize);

    close(s);
    close(d);

    return 0;
}
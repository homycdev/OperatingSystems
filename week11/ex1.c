#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    size_t strlength = strlen("This is a nice day");
    int myFile = open("./ex1.txt", O_RDWR);
    struct stat buf;

    fstat(myFile, &buf);
    ftruncate(myFile, strlength);

    void *addr = mmap(0, strlength, PROT_WRITE, MAP_SHARED, myFile, 0);
    memcpy(addr, "This is a nice day", strlength);
}
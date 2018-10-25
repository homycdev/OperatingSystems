#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <sys/resource.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dirp;
    struct dirent *dp, stat buff;

    dirp = opendir("/home/user/Desktop/os_fixed/OperatingSystems/week10/tmp");
    while ((dp = readdir(dirp)) != NULL)
    {
        stat(dp, &buff);
        printf("%s: \n", dp -> d_name);
    }
}
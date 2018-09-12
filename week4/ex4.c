#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cmd[99];
    while(1)
    {   
        printf(">");
        gets(cmd);
        system(cmd);
    }
    return 0;
}
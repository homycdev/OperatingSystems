#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    char cmd[99];
    while (1)
    {
        printf(">");
        scanf("%s", cmd);
        system(cmd);
    }
    return 0;
}

#include <zconf.h>
#include <stdio.h>

int main()
{
    int rd = open("dev/random", O_RDONLY);
    
    unsigned char rs[20];
    
    read(rd, rs, sizeof(rs));
    
    for (int i = 0; i < sizeof(rs); i++)
    {
        printf("%c", rs[i]);
    }
    
    printf("\n");
}
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int x, z;
    for ( x = 0 ; x < n ; x++ )
    {
        for ( z = 0 ; z <= ( n - x - 2 ) ; z++ )
            printf(" ");
        for( z = 0 ; z <= x ; z++ )
            printf("%c", "*");
 
        printf("\n");
    }
    return 0;
}
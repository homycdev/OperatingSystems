#include <stdio.h>
long fun(int y)
{
    int z;
    long result = 1;
 
    for( z = 1 ; z <= y ; z++ )
        result = result*z;
 
    return ( result );
}
int main()
{
    int n = 6;
    int x, z;
    for ( x = 0 ; x < n ; x++ )
    {
        for ( z = 0 ; z <= ( n - x - 2 ) ; z++ )
            printf(" ");
        for( z = 0 ; z <= x ; z++ )
            printf("%ld ",fun(x)/(fun(z)*fun(x-z)));
 
        printf("\n");
    }
    return 0;
}
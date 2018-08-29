#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    
    int i1 = (int)sizeof(i);
    int f1 = (int)sizeof(f);
    int d1 = sizeof(d);

    printf("%d\n %d\n %d\n", i1, f1, d1);
    printf("%d\n %f\n %lf\n", i, f, d);
    
    return 0;
    
}
#include<stdio.h>
void swapf(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int main()
{   
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    swapf(&a,&b);
    printf("%d %d",a ,b);
    
    return 0;
}
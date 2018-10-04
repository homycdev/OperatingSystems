#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *array;
    
    printf("Please enter N: ");
    scanf("%d", &n);

    array = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        array[i] = i;
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
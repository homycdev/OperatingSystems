#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    int n = 011;
    if (pid > 0)
    {
        /* Parent */
        printf("Hello from parent [%d - %d]\n", pid, n);
    }    
    else if (pid == 0)
    {
        /* Child */
        printf("Hello from child [%d - %d]\n", pid, n);
    }else
    {
        /* ERROR */
        return 1;    
    }
    return 0;
}
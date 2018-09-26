#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void report(int hotkey)
{   
    if(hotkey == SIGINT)
    {
        printf("\n Combinataion detected! \n\n");
        exit(0);
    }
}
int main()
{    
    while(1)
    {
        signal(SIGINT, report);
    }
    
    return 0;
}
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void report(int inp)
{    
    if(inp == SIGUSR1) printf("\nSIGUSR1 detected!\n");
}

void reportKill(int inp)
{
    if(inp == SIGKILL) printf("\n SIGKILL declared.");
    // no output, because you cannot catch the signal when you're killing the program
}

void reportStop(int inp)
{
    if(inp == SIGSTOP) printf("\n SIGSTOP declared.");
    // no output, because you cannot catch the signal when you're stopping the program
}


int main()
{    
    while(1)
    {
        signal(SIGUSR1,report);
        signal(SIGKILL,reportKill);
        signal(SIGSTOP,reportStop);    
    }

    return 0;
}
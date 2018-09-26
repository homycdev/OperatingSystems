#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void task()
{
    int child = fork();
    
    if (child == -1)
    {
        printf("ERROR!\n");
        exit(0);
    }

    else if(child != 0)
    {
        sleep(10);
        kill(child, SIGTERM);
        printf("Child process killed [%d]\n",getpid() );
        
    }

    else
    {
        while(1)
        {
         printf("I'm alive\n");
         sleep(1);
        }
    }
}


int main()
{
    task();
    
    return 0;
}
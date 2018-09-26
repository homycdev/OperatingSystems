#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int descriptor[2], errPipe, errFork;

    char baseOfStr[] = "Some text\n";
    char output[sizeof(baseOfStr)/sizeof(baseOfStr[0])];
    
    
    errPipe = pipe(descriptor);
    
    if (errPipe < 0)
    {
        printf("Error!\n");
        return 0;
    }

    else
    {
        errFork = fork();
        if (errFork == -1){
            printf("Fork Error!\n");
        
            return 1;
        }
        else if(errFork != 0)
        {
            close(descriptor[0]);
            write(descriptor[1], baseOfStr, sizeof(baseOfStr));
        
            return 1;
        }
        else{
            close(descriptor[1]);
            read(descriptor[0], output, sizeof(output));
            
            printf("Successful!\n");
            printf("Output: %s\n", output);
        }
        return 0;
        
    }
    
}
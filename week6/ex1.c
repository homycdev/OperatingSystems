#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int descriptor[2],err;
    
    char baseOfStr[] = "Some text \n";
    char output[sizeof(baseOfStr)/sizeof(baseOfStr[0])];
    
    err = pipe(descriptor);
    
    if (err < 0)
    {
        printf("Error!\n");
        return 0;
    }

    else
    {
        
        write(descriptor[1], baseOfStr, sizeof(baseOfStr));
        read(descriptor[0], output, sizeof(output));
        
        printf("Succeed!\n");
        printf("Output: %s\n", output);
        
        return 0;
        
    }
    
}
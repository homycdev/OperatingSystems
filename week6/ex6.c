#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>


int main(){
  int descriptor[2];
  pipe(descriptor);

  pid_t child1, child2;
  
  child1 = fork();
  
  if(child1 == -1)
  {
    printf("Fork1 error");
    exit(1);
  }
  
  
  if(child1 != 0)
  {
    child2 = fork();
    if(child2 == -1)
    {
      printf("Fork2 error");
      exit(1);
    }
    if(child2 == 0)
    {
      pause();
    }
    else
    {
      int status;
      close(descriptor[0]);
      write(descriptor[1], &child2, sizeof(child2));
      
      waitpid(child2, &status, WUNTRACED);
      
      printf("Child2 status had been changed to.. %d\n", status);
    }
  }
  else
  {
    close(descriptor[1]);
    pid_t pid_num;
    
    read(descriptor[0], &pid_num, sizeof(pid_num));
    printf("PID to block: %d\n", pid_num);
    
    sleep(2);

    printf("Pushing SIGKILL signal to child2..\n");
    kill(pid_num, SIGSTOP);
    
    printf("Signal recieved!\n");
  }
  
  return 0;
}
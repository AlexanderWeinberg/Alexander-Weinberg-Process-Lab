#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX 2

  void main(int argc, char *arg[]){
  srand(time(NULL));
    int pid;
    int status = wait(&status);
    int i;
    int x;
    int sleeping = (1 +  rand()%10);
    int looping = (1 +  rand()%30);
    
    for(i=0;i<MAX; i++){  //NEVER use while(1)  (while true) => infinite loop
      
      pid = fork();  //creates a child 
      
    if (pid ==0){
     for(x = 0; x < looping; x++){
       printf("Child Pid: <%d> is going to sleep!\n",getpid());
       sleep(sleeping);
       printf("Child Pid: <%d> is awake!\nWhere is my Parent: <%d>?\n",getpid(),getppid());
     } exit(0); 
    }
     else if(pid > 0){//parent process
       printf("Child Pid: <%d> has completed\n",status);
       }
      else{
       printf("An ERROR Occured\n");
       exit(0);
     }
    
    
    }
  }  
      
      
  
     
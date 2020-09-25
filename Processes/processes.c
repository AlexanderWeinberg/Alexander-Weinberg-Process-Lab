#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX 2

  void main(int argc, char *arg[]){
  srand(time(NULL));
    int pid;
    
    int i;
    int x;
    
    
    for(i=0;i<MAX; i++){  //NEVER use while(1)  (while true) => infinite loop
      
      pid = fork();  //creates a child 
      
    if (pid ==0){
      
      
    int sleeping = (1 +  rand()%10);//sleeping for at most 10 seconds
    int looping = (1 +  rand()%30); // looping for at most 30 iterations
     
      for(x = 0; x < looping; x++){
       printf("Child Pid: <%d> is going to sleep!\n",getpid());
       sleep(sleeping);
       printf("Child Pid: <%d> is awake!\nWhere is my Parent: <%d>?\n",getpid(),getppid());
     } exit(0); 
    }
     else if(pid > 0){//parent process
       int status = wait(&status);
       printf("\n");
       printf("Child Pid: <%d> has completed\n",status);
       printf("\n");
       }
      else{
       printf("An ERROR Occured\n");
       exit(0);
     }
    
    
    }
  }  
      
      
  
     
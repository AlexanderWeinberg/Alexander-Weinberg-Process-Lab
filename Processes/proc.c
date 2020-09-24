#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 5

  void main(int argc, char *arg[]){
    int pid[MAX];
//     int pid;
    int status;
    int i;
    
    for(i=0;i<MAX; i++){  //NEVER use while(1)  (while true) => infinite loop
      
      pid[i] = fork();  //creates a child 
  
      srandom(getpid());
  switch(pid[i]){
    case 0:     //child
      
      
      printf("In child, pid =%d, parent pid = %d...\n",getpid(), getppid());
      sleep(random() % 3);//sleeps random number betweeen 0 and 3
      
     
      printf("Child Terminates\n");
      execl("/bin/ls","-l",(char*)0);
//       exit(0);
      break;
      
    case -1:    //error
      break;
      
      
  
    default:  //parent, PID is childpid
    
//      printf("Parent waiting on CHild\n");
//      wait(&status); //parent waits for child to terminate before it reeps child
       
//       wait(NULL); //parent waits for child to terminate before it reeps child
        
      
//       printf("In Parent...\n");
//       exit(0);
      break;
    }
  }
    
    for(i=0;i<MAX; i++){
     printf("Parent waiting on CHild\n");
     wait(&status); //parent waits for child to terminate before it reeps child
    }
    
    printf("Parent Terminating,   Child Status= %d\n",status);
  
  }
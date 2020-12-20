#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==-1)
    {   
        perror("fork error");
        exit(1);
    }   
    else if(pid>0)
    {   
        printf("parent process:pid=%d\n",getpid());
    }   
    else if(pid==0)
    {   
        printf("child process:pid=%d\n",getpid());
        //execl("/bin/ls","-a","-l","test_fork.c",NULL);	//①
        //execlp("ls","-a","-l","test_fork.c",NULL);		//②
        //char *arg[]={"-a","-l","work_exec.c",NULL};			//③
        char *arg[]={"netstat" ,"-A","inet",NULL};
	execvp("netstat",arg);
        perror("error exec\n");
        printf("child process:pid=%d\n",getpid());
     }  
    
   return 0; 
 }


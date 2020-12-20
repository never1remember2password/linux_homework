#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main()
{
	pid_t pid;
	pid = fork();
	if(pid==-1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid==0)
	{
		printf("I'm child process,pid=%d\n",getpid());		
	}
	else if(pid>0)
	{
		printf("This is a parent process,pid=%d\n",getpid());
	}
	return 0;
}

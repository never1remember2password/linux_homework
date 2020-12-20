#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
//编程实现在父进程中一次创建5个子进程
int main()
{
	pid_t pid;
	int i;
	for(i=0;i<5;i++){
	   if((pid=fork())==0) //这里判断为0直接退出结束循环的原因前面提到过是因为子进程和父进程运行时共享同一个程序，只是简单地把程序指针指向父进程的代码，不然子进程自己会一直循环递归创建子进程。
		  break;
	}
	if(pid==-1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid==0)
	{
		 printf("I am child=%d,pid=%d\n",i+1,getpid());  	
	}
	else if(pid>0)
	{
		printf("This is a parent process,pid=%d\n",getpid());
	}
	return 0;
}

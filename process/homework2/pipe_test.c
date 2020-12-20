#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//作者：何陈龙  时间：2020.12.19
//子进程和父进程在匿名管道下进行进程之间的通信
int main()
{
    int fd[2];//定义文件描述符数组
    int ret=pipe(fd);//创建管道
    if(ret==-1)//函数pipe调用失败
    {   
        perror("pipe");
        exit(1);
    }   
    pid_t pid=fork();//创建子进程
    if(pid>0)//在父进程中：
    {   
	printf("I'm parent process ,and I will write char to My child process;\n");
        close(fd[0]);//关闭父进程的读端
        char *p="hello,pipe\n";
        write(fd[1],p,strlen(p)+1);//进行写操作
        close(fd[1]);//关闭写端
        wait(NULL);//父进程挂起，等待子进程结束
    }
    else if(pid==0)//子进程开始
    {
        close(fd[1]);//关闭写端
        char buf[64]={0};
        ret=read(fd[0],buf,sizeof(buf));//进行读操作
	printf("I'm child process,I have received the message from parent process,here is:\n");
        close(fd[0]);//读取完成，关闭读端
        write(STDOUT_FILENO,buf,ret);
    }
    return 0;
}

#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdlib.h>
 #include <stdlib.h> 
#include <stdio.h> 
int main() 
{ 
pid_t pid,pc;
 pid=fork(); 
int status,i=1; 
if(pid<0) 
{ 
printf("创建进程失败fork error!\n"); 
} 
else if(pid==0) 
{ 
printf("我是Child process:pid=%d,打算执行10秒，请父进程等待\n",getpid());
 sleep(10); 
exit(7); 
} 
else 
{ 
do
{ 
pc=waitpid(pid,&status,WNOHANG);//使用了WNOHANG参数,waitpid就不会等待,直接返回0. 
// pc=waitpid(pid,&status,0); 
if(pc==0) 
{ 
printf("No child exited(%d)!\n",i++); 
sleep(1); 
} 
}while(pc==0);//等不到,继续等, 
if(pid==pc) 
printf("Catch a Child process:\n");
 else printf("出错了waitpid error\n");
 printf("我是父进程,我已经等待子进程结束，子进程的id是==d\n",pc); 
} 
exit(0); 
}

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
int count1=0;
int main(void)
{
    int pid;
    int count2=0;
    count1++;
    count2++;
    printf("count1=%d,count2=%d\n",count1,count2);
 
    pid=fork();
    count1++;
    count2++;
    printf("count1=%d,count2=%d\n",count1,count2);
    printf("pid=%d\n",pid);
 
    return 0;
/*证明了父进程和子进程运行的是同一个程序，也正是这个理由，系统并未在内存中给子进程配置独立的程序运行空间，而只是简单地将程序指针指向父进程的代码；
栈（操作系统）：由操作系统自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
堆（操作系统）： 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS（操作系统）回收，分配方式倒是类似于链表。
*/
}

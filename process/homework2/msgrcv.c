#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TEXT 512
struct my_msg_st{
    long int my_msg_type;
    char anytext[MAX_TEXT];
};
int main()
{
    int idx=1;
    int msgid;
    struct my_msg_st data;
    long int msg_to_rcv=0;
    msgid=msgget((key_t)1000,0664|IPC_CREAT);////从队列中读取对应标识的信息
    if(msgid==-1){
        perror("msgget err");
        exit(-1);
    }   
    while(idx<5){
        
        if(msgrcv(msgid,(void*)&data,BUFSIZ,msg_to_rcv,0)==-1){//接收消息：magrcv()，这两个函数实现进程间的双向通信 
            perror("msgrcv err");
            exit(-1);
        }
        
        printf("msg type:%ld\n",data.my_msg_type);
        printf("msg content is:%s",data.anytext);
        idx++;
    }
    
    if(msgctl(msgid,IPC_RMID,0)==-1){//删除队列消息
        perror("msgctl err");
        exit(-1);
    }
    exit(0);
}

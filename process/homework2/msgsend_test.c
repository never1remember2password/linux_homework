//作者：何陈龙   时间：2020.12.19
//消息队列发送端
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
//收发消息需要特定的格式: 定义消息结构体
#define MAX_TEXT 512
struct my_msg_st{
long int my_msg_type; //消息的标识，必须是long类型
char anytext[MAX_TEXT];//消息的正文，可以是任意类型，且大小自定 
};

int main()
{
    int idx=1;
    int msgid;
    struct my_msg_st data;
    char buf[BUFSIZ];
    msgid=msgget((key_t)1000,0664|IPC_CREAT);//根据key值申请消息队列ID号

    if(msgid==-1){
        perror("msgget err");
        exit(-1);
    }   
    while(idx<5){
        printf("enter some text:");
        fgets(buf,BUFSIZ,stdin);//fgets函数功能为从指定的流中读取数据，每次读取一行
        data.my_msg_type=rand()%3+1;
        strcpy(data.anytext,buf);//即string copy（字符串复制）,buf写到前者中
        
        if(msgsnd(msgid,(void*)&data,sizeof(data),0)==-1){ //向消息队列发送数据
            perror("msgsnd err");
            exit(-1);
        }
        idx++;
    }
    return 0;
}

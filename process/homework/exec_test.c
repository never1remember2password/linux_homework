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
         printf("parent process(pid=%d):do nothing\n",getpid());
     }   
     else if(pid==0)
     {   
         printf("child process(pid=%d) will do {\n",getpid());
         //netstat -r 显示路由表
	 execlp("ls","-l","./","NULL");
	 
         perror("error exec\n"); 
         printf("child process(pid=%d):done }\n",getpid());
     }   
     return 0;
 }

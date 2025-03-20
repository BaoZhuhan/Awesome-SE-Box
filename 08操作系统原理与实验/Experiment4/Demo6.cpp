#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();      //创建一个进程
    if (pid == 0)      //子进程
    {
       printf("child:I am the child process.\n");         
       printf("child:pid: %d\tppid:%d\n", getpid(), getppid());//输出进程ID和父进程ID
       printf("child:I will sleep for five seconds.\n");         
       sleep(5);//睡眠5s，保证父进程先退出
       printf("child:pid: %d\tppid:%d\n", getpid(), getppid());
       printf("Child process exited.\n");
     }     
     else//父进程
     {
       printf("I am the father process.\n");         
       sleep(1);//父进程睡眠1s，保证子进程输出进程id
       printf("Father process exited.\n");
     }
     exit(0);
}
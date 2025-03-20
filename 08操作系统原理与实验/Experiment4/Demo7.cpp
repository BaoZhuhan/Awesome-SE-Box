#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("I am the child process. I existed.\n");
        exit(0);
    }
    printf("I am the father process.I will sleep for two seconds\n");
    // 等待子进程先退出
    sleep(2);
    // 输出进程信息
    system("ps -o pid,ppid,state,tty,command");
    printf("Father process exited.\n");
    exit(0);
}
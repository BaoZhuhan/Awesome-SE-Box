#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    char buf[100];
    pid_t cld_pid;
    int fd;

    if ((fd = open("temp", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU)) == -1)
    {
        std::cout << "open error" << errno << std::endl;
        exit(1);
    }
    strcpy(buf, "This is parent process write\n");

    if ((cld_pid = fork()) == 0)
    { // 这里是子进程执行的代码
        strcpy(buf, "This is child process write\n");
        std::cout << "This is child process" << std::endl;
        // sleep(1);
        std::cout << "My PID (child) is " << getpid() << std::endl; // 打印出本进程的ID
        // sleep(1);
        std::cout << "My parent PID is " << getppid() << std::endl; // 打印出父进程的ID
        // sleep(1);
        write(fd, buf, strlen(buf));
        close(fd);
        exit(0);
    }
    else
    {            // 这里是父进程执行的代码
        wait(0); // 如果此处没有这一句会如何？
        std::cout << "This is parent process" << std::endl;
        // sleep(1);
        std::cout << "My PID (parent) is " << getpid() << std::endl; // 打印出本进程的ID
        // sleep(1);
        std::cout << "My child PID is " << cld_pid << std::endl; // 打印出子进程的ID
        // sleep(1);
        write(fd, buf, strlen(buf));
        close(fd);
    }
    return 0;
}
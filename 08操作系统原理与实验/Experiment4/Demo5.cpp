#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t a_pid, b_pid;
    if ((a_pid = fork()) < 0)
        printf("error!");
    else if (a_pid == 0)
        printf("b");
    else
        printf("a");

    if ((b_pid = fork()) < 0)
        printf("error!");
    else if (b_pid == 0)
        printf("c");
    else
        printf("a");
}
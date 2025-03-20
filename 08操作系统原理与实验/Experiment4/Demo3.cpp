#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        printf("Error in fork!");
    } else if (pid == 0){
        printf("I am the child process, my process id is %d\n", pid);
    } else {
        printf("I am the parent process, my process id is %d\n", pid);
    }
}
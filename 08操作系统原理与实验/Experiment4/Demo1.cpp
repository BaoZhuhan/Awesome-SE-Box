#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int pid;
    pid = fork();
    // std::cout << "pid = " << pid << std::endl;
    std::cout << "fun() getpid = " << getpid() << std::endl;
    sleep(1);
}
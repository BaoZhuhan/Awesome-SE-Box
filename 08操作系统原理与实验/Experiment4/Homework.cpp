#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        // 子进程
        for (int i = 0; i < 5; ++i) {
            std::cout << "子进程ID: " << getpid() << ", 父进程ID: " << getppid() << std::endl;
            system("/bin/ps");
            sleep(3);
        }
        exit(0);
    } else {
        // 父进程
        wait(NULL); // 等待子进程结束
        std::cout << "子进程结束，父进程ID: " << getpid() << std::endl;
    }

    return 0;
}

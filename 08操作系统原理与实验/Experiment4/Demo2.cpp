#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int p1, p2, p3;
    while((p1 = fork()) == -1);
    if(p1 == 0){
        while((p2 = fork()) == -1);
        if(p2 == 0){
            std::cout << 'c' << std::endl;
        }else{
            std::cout << 'b' << std::endl;
        }
    }else{
        std::cout << 'a' << std::endl;
    } 
}
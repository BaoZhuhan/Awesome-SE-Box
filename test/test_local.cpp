#include <bits/stdc++.h>

void f(int &c){
    std::cout << c << std::endl ;
    c++;
    return;
}

int main(){
    int a = 1;
    int &b = a;
    std::cout << b << std::endl;
    f(a);
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    return 0;
}
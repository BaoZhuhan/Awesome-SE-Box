#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int x;
    scanf("%d",&x);
    switch(x){
        case 1: cout << 1;break;
        case 2: cout << 2;break;
        case 3: cout << 3;break;
        default : cout << -1;break;
    }
}
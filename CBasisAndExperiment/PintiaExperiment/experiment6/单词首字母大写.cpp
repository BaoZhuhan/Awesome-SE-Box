#include <bits/stdc++.h>
using namespace std;
int main(void){
    int flag = 1;
    char c;
    while((c = getchar()) != '\n'){
        if(c == ' ') flag = 1;
        else if(flag){
            flag = 0 ;
            if( c >= 'a' &&  c <= 'z') c-= 32;
        }
        cout << (char)c;
    }
    return 0;
}
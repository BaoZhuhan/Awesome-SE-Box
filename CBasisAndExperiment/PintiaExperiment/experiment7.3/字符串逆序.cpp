#include <bits/stdc++.h>
using namespace std;

int main(void){
    char str[100];
    int i = 0 ;
    while((str[i++] = getchar()) != '\n'){}
    str[--i] = '\0';
    for(--i ; i >= 0 ; i--){
        cout << str[i];
    }
    return 0;
}
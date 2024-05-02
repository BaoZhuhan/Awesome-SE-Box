#include <bits/stdc++.h>
using namespace std;

int main(void){
    char n ;
    cin >> n ;
    string tmp ;
    getline(cin , tmp);
    char str[100] ;
    int i = 0;
    while((str[i++] = getchar()) != '\n'){}
    str[--i] = '\0';
    int res = -1;
    for(int i = 0 ; str[i] != '\0' ; i++ ){
        if(str[i] == n) res = i;
    } 
    if(res == -1){
        cout << "Not Found";
    }
    else {
        cout << "index = " << res;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int i = 0 ;
    char tmp;
    set<char> s;
    while((tmp = getchar()) != '\n'){
        if(tmp >= 'A' and tmp <= 'Z'){
            if(s.count(tmp) == 0){
                s.insert(tmp);
                cout << tmp;
            }
        }
    }
    if(s.empty()){
        cout << "Not Found";
    }
    return 0;
}
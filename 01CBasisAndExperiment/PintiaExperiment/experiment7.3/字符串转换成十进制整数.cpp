#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[100];
    int i = 0 ;
    int flag_p = 1 ; 
    int flag_16 = 0;
    stack<int> s;
    int res = 0;
    while((str[i] = getchar()) != '#'){
        if((str[i] >= '0' and str[i] <= '9') or (str[i] >= 'a' and str[i] <= 'f') or (str[i] >= 'A' and str[i] <= 'F')){
            flag_16 = 1;
            if(str[i] >= '0' and str[i] <= '9'){
                s.push((int)(str[i] - '0'));
            }else if(str[i] >= 'a' and str[i] <= 'f'){
                s.push((int)(str[i] - 'a' + 10));
            }else if(str[i] >= 'A' and str[i] <= 'F'){
                s.push((int)(str[i] - 'A' + 10));
            }
        }
        if(flag_16 == 0 and str[i] == '-'){
            flag_p = 0;
        }
        i++;
    }str[i] = '\0';
    int tmp = 0;
    while(!s.empty()){
        res += s.top() * pow(16,tmp);
        s.pop();
        tmp++;
    }
    if(flag_p == 0){
        res *= -1;
    }
    cout << res;
    return 0;
}
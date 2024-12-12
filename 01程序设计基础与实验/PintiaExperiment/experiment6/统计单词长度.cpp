#include <bits/stdc++.h>
using namespace std;

int main(){
    char tmp ; 
    int flag = 0 ;
    int res = 0 ;
    bool bug_flag = true;
    int bug_num = 0 ;
    while((tmp = getchar()) != '\n'){
        if(tmp != ' ' and flag == 0 ){
            flag = 1;
            res++;
        }
        else if(tmp == ' ' and flag == 1){
            flag = 0;
            cout << res << ' ';
            res = 0;
            bug_num++;
        }
        else if(tmp != ' ' and flag == 1){
            res++;
        }
        
    }
    if (res == 0 and bug_num !=0){
        return 0;
    }
    cout << res << ' ';
    return 0;
}
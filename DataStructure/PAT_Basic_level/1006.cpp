#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string res;
    if(s.size() == 3){
        for(int i = 0; i < (s[0] - '0'); i++){
            res = res + "B";
        }
        for(int i = 0; i < (s[1] - '0'); i++){
            res = res + "S";
        }
        for(int i = 1; i <= (s[2] - '0'); i++){
            res += (char)('0' + i);
        }
    }
    else if(s.size() == 2){

        for(int i = 0; i < (s[0] - '0'); i++){
            res = res + "S";
        }
        for(int i = 1; i <= (s[1] - '0'); i++){
            res += (char)('0' + i);
        }
    }
    else{
        for(int i = 1; i <= (s[0] - '0'); i++){
            res += (char)('0' + i);
        }
    }

    cout << res << endl;
    return 0;
}
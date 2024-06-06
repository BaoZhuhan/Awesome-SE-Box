#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string res;
    getline(cin, s);
    int pre = 0;
    while(s.find(' ') <= s.size()){
        int loc = s.find(' ');
        string tmp;
        for(int i = pre; i < loc; i++){
            tmp += s[i];
        }
        res = tmp + " " + res;
        pre = loc + 1;
    }
    for(int i = 0; i < res.size() - 1; i++){
        cout << res[i];
    }
    return 0;
}
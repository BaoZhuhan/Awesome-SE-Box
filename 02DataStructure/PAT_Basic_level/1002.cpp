#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int sm = 0 ;
    for(int i = 0 ; i < s.size() ; i++){
        sm += (s[i]-'0');
    }
    std::vector<std::string> num = {"lin","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string res;
    if(sm == 0){
        cout << "lin";
        return 0;
    }
    while(sm){
        int loc = sm%10;
        res = num[loc] + res;
        res =  " " + res;
        sm /= 10; 
    }
    for(int i = 1 ; i < res.size() ; i ++){
        cout << res[i];
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


void solve(){
    //不要忘记main函数的T
    int n;cin >> n;
    string s;cin >> s;
    string s1 = "dfs\n" ,s2 = "DFS\n" ;
    int p1 = 0 , p2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == s1[p1]){
            p1++;
        }else if (s[i] == s2[p2]){
            p2++;
        }
    }
    cout << (p2 == 3 ? 1 : 0) << ' ' << (p1 == 3 ? 1 : 0) << '\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
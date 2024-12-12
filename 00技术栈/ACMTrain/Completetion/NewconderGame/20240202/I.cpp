#include <bits/stdc++.h>
using namespace std;


void solve(){
    //不要忘记main函数的T
    int n ;cin >> n;
    int res = n%6 == 0 ? n/6 : (n/6)*2;
    cout << res << '\n';
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
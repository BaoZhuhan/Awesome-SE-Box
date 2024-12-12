#include <bits/stdc++.h>
using namespace std;


void solve(){
    //不要忘记main函数的T
    int a , b , c ; cin >> a >> b >> c;
    int res = 0;
    switch(a){
        case 150 : res += 1;break;
        case 200 : res += 2;break;  
    }
    if(b >= 34 and b <= 40) res += 1;
    if(b == 45) res += 2;
    if(c >= 34 and c <= 40) res += 1;
    if(c == 45) res += 2;
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
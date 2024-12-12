#include <bits/stdc++.h>
using namespace std;

void solve(){
    //不要忘记main函数的T
    int n ; cin >> n ; 
    int flag1 = 0 ; // 数字是啥
    bool flag2 = true; // 是否段中
    vector<int> col(n+1 , 0);
    int ans = 0 ;
    int lastp = n ; 
    for(int i = 1 ; i <= n ; i++ ) cin >> col[i];
    flag1 = col[n];
    for(int i = n - 1 ; i > 0 ; i--) {
        if(flag2 == true and col[i] != flag1) {
            flag2 = false;
            ans += 1;
        }
        else if(flag2 == false){
            flag1 = col[i];
            flag2 = true;
            lastp = i;
        }
        if(i == 1){
            if(flag2 == false) break;
            if(flag2 == true) ans += lastp;
        }
    }
    if(n == 1) ans = 1;
    cout << ans << '\n' ;

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
#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n , k ;
    cin >> n >> k ;
    int sum = (1+n)*n/2;
    if(sum%n == k) cout << n << '\n'; 
    else cout << n-1 << '\n' ;
}
signed main(void){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T ;cin >> T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{

    int n; cin >> n ;
    vector<int> a(n+1 , 0);
    
    for(int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }

    if(n == 1){
        cout << 0 << '\n' ;
        return;
    } 

    int ans = 0 ;
    sort(a.begin() , a.end());
    for(int i = 2 ; i <= n ; i++ ){
        ans += a[i] * 2 * ( i - 1 ) ; 
    }
    cout << ans * 2 << '\n';
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
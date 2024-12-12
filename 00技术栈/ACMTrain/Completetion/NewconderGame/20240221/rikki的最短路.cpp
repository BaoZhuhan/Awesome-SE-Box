#include <bits/stdc++.h>
using namespace std ;
#define int long long 

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int t , a , k ;
    cin >> t >> a >> k;

    int r = 0;
    int ans = 0;

    int ll = min(t - k ,r - k );
    int rr= max(t + k ,r + k );

    if(a >= ll and a <= rr){
        ans += fabs(a - r);
        r = a;
    }else{
        ans += fabs(t - r);
        r = t;

        ans += fabs(a - r);
        r = a;
    }

    ans += fabs(t - r);
    r = t;

    cout << ans ;
    return 0;
}
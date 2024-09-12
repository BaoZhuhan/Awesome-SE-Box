#include <bits/stdc++.h>
using namespace std ;

#define int long long 
signed main(){
    int res = 1 ;
    int x , n , m; 
    cin >> x >> n >> m;
    int nn = n ;
    int xx = x ;
    while(n > 0){
        if(n&1){
            res= (res*x)%m;
        }

        x = (x*x)%m;
        n >>= 1;
    }

    cout << xx << "^" << nn << " mod " << m << "=" << res;
    return 0;
}
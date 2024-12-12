//f(n)代表 1-n中与n互质的个数
/*
性质
若n 为质数， 则f(n) = n-1;
若n 为质数， 则f(n^k) = (n-1)n^(k-1)
gcd(m,n) == 1 -->  f(m*n) = f(m)*f(n)
唯一分解定理：


*/
#include <bits/stdc++.h>
using namespace std;




void ola(int n){
    int ans = n ;
    for(int i  =2 ; i * i <= n ; ++i){
        if(n % i == 0){
            ans = ans * (i -1) / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans = ans *(n-1) / n;
    cout << ans ;
}

void solve(){
    int n ; cin >> n;
    ola(n);
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


#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4+5;
const int M = 1e7+5;

void run(){
    int n , m  , k ;cin >> n >> m >> k ;
    vector<int> w(N);
    vector<int> v(N);
    vector<int> dp(M);
    for(int i = 1 ; i <= m ; i++ ) cin >> w[i] >> v[i];
    for(int i = 1 ; i <= m ; i++ ){
        for(int j = w[i] ; j <= t ; j++){
            dp[j] = max(dp[j] , dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[t] ;
    return;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
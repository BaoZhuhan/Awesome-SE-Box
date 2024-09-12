#include <bits/stdc++.h>
using namespace std ;

int run(vector<int>& a, int k , int n ) {
    vector<int> dp(n + 1, 0);
    vector<int> prefix_sum(n + 1, 0);
    unordered_map<int, int> mod_map;
    mod_map[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = ((prefix_sum[i - 1] + a[i - 1]) % k + k) % k;
        dp[i] = dp[i - 1];
        if (mod_map.count(prefix_sum[i])) {
            dp[i] = max(dp[i], dp[mod_map[prefix_sum[i]]] + 1);
        }
        mod_map[prefix_sum[i]] = i;
    }
    return dp[n];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n , k ; cin >> n >> k ;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << run(a , k , n);
    return 0;
}
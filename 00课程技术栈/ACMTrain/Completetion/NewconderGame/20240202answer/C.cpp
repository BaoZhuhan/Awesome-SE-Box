#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios::sync_with_stdio(0),cin.tie(0);

    int n , q, tc ; cin >> n >> q >> tc ;
    vector<int> t(n);
    for(int i = 0 ; i <n ; i++) cin >> t[i];
    sort(t.begin() , t.end()) ;

    vector<long long > sum(n+1);
    for(int i = 0 ; i< n ;i ++) sum[i + 1] = sum[i] + t[i] ;

    while(q--){
        long long m ; cin >> m ; 
        int c = min((long long)n , m / tc) ;
        cout << sum[n-c] + tc << '\n' ; 
    }
    return 0;
}
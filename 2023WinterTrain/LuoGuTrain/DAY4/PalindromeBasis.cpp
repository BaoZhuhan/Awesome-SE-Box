#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int mod = 1e9 + 7 ;

int t , n , dp[40005] ;
vector<int> hw ;

inline bool ish(int x) {
    vector<int> c;
    while(x){
        c.push_back(x % 10) ;
        x /= 10 ;
    }
    for(int i = 0 ; i < (int)c.size() ; i++ ) if(c[i] != c[ (int)c.size() - i - 1]) return false ;
    return true ;
}

void init(){
    dp[0] = 1;
    for(int i = 1 ; i <= 40004 ; i++) if(ish(i)) hw.push_back(i) ;
    for(auto x : hw ){
        for(int i = x ; i <= 40004 ; i++) {
            dp[i] = (dp[i] + dp[i - x]) % mod ;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);

    init();
    cin >> t;
    while(t--){
        cin >> n ; 
        cout << dp[n] << '\n' ;
    }
}
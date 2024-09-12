#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n ; cin >> n;
    set<pair<int , int>> s;

    int ans0 = 2 , ans1 = 2;
    for(int i = 0 ;  i < n ; i++){
        int r ,c ;cin >> r >> c;
        s.insert({r,c});
        if(c <= 0 ) ans0 = 1;
        if(c >= 0 ) ans1 = 1;
    }

    for(auto [r,c] : s){
        for(int i = -1 ; i < 2 ; i++ ){
            if(s.count({r^3 , c + i})) { 
                if(c < 0) ans0 = 0 ;
                if(c > 0) ans1 = 0 ; 
            }
        }
    }

    int ans = 3 - s.count({2,0}) - s.count({1,-1}) - s.count({1,1});
    cout << min(ans , ans0 + ans1) << '\n' ; 

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--) solve();
    return 0;
}
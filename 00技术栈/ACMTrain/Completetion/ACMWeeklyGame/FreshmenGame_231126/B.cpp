#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    int res = 0 ; 
    for(int i = 1 ; i < n ; i++ ){
        res=res^i;
    }
    if(res == 0){
        cout << "YES" << '\n'; 
        for(int i = 0 ; i < n ; i++ ) cout << i << ' ' ;
        cout << '\n'; 
    }
    else cout << "NO" << '\n';

}
int main(void){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T ; cin >> T;
    while(T--) solve();
    return 0;
}
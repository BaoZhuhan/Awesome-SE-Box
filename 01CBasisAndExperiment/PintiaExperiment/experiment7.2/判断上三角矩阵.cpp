#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m ; cin >> m;
    int flag = 1;
    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            int tmp ;cin >> tmp ;
            if(j < i){
                if(tmp != 0 ){
                    flag = 0;
                }
            }
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int T ; cin >> T ;
    while(T--) solve();
    return 0;
}
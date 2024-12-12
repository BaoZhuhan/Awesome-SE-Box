#include <bits/stdc++.h>
using namespace std;

void solve(){
    int ans = 0;
    int x , y ; 
    cin >> x >> y;
    bitset<32> a(x) , b(y);

    for(int i = 31 ; i >= 0 ; i--){
        if(a[i] == b[i] ){
            continue;
        }else if(a[i] == 1){
            x -= (1 << i);
            ans += (1 << i);
        }else{
            break;
        }
    }

    ans += y - x;
    cout << ans << '\n';
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T ; 
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
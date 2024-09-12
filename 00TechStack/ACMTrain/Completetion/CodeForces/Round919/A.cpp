#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int t;
    cin >> t;
    int mx = 99999999999999;
    int mi = -99999999999999;
    vector<int> v;
    for(int i = 0 ;i < t ;i++){
        int cnt , tmp;
        cin >> cnt >> tmp;
        if(cnt == 1){
            if(tmp > mi){
                mi = tmp;
            }
        }else if(cnt == 2){
            if(tmp < mx){
                mx = tmp;
            }
        }else{
            v.push_back(tmp);
        }
    }
    int res = 0;
    for(auto i:v){
        if((i >= mi ) and (i <= mx)){
            res--;
        }
    }
    res += (mx - mi +1);
    if(mx < mi){
        res = 0;
    }

    cout << res << '\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
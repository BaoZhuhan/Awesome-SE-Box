#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    int p_mx = 0;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        if(fabs(tmp) >= fabs(a[p_mx])){
            p_mx = i;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] != a[p_mx]){
            b.push_back(a[i]);
        }else{
            c.push_back(a[i]);
        }
    }
    if(b.size() == 0){
        cout << -1 << '\n';
    }else{
        for(auto i : b){
            cout << i << ' ' ;
        }cout << '\n';
        for(auto i : c){
            cout << i << ' ';
        }cout << '\n';
    }

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
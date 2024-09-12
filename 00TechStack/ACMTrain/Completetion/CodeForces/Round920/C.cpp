#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,f,a,b;
    cin >> n >> f >> a >> b;
    vector<int> v;
    vector<int> diff;
    v.push_back(0);
    diff.push_back(0);
    int stand = b/a;
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        diff.push_back(0);
        diff[i] =  v[i] - diff[i-1];
        if(diff[i] > stand){
            sum += (b);
        }else{
            sum += (diff[i]*a);
        }
    }
    if(sum >= f){
        cout << "NO\n";
    }else{
        cout << "YES\n";
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
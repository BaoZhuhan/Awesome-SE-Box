#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node {
    int aa , bb ;
};

bool cmp(node x , node y ){
    return x.aa < y.aa;
}
void solve(){
    //不要忘记main函数的T
    int n, m;
    cin >> n >> m;
    vector<node> v(n + 1);
    vector<int> sumb(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].aa >> v[i].bb;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++) {
        sumb.push_back(sumb[i - 1] + v[i].bb);
        if (v[i].aa - sumb[i] <= m) {
            cnt = i;
        }
    }
    cout << (v[cnt].aa + m - (v[cnt].aa - sumb[cnt])) << '\n' ;
    return ;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
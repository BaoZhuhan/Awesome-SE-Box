#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
const ll inf = 4e18 , p = 998244353;

int pre[N];
int root(int x){
    return pre[x] == x ? x : root(pre[x]);
}

void merge(int x , int y){
    x = root(x), y = root(y);
    if(x == y)return;
    pre[x] = y;
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1 ; i <= n ;++i ){
        pre[i] = i;
    }
    while(m--){
        int op , x , y;
        cin >> op >> x >> y;
        if(op==1)merge(x,y);
        else cout << (root(x) == root(y) ? 'Y':'N') << '\n' ;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
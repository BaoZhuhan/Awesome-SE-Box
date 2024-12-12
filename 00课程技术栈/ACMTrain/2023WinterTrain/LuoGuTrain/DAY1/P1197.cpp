#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    DSU(int n ){
        this->n = n;
        pre.resize(n+1);
        iota(pre.begin(),pre.end(),0ll);
        sz.resize(n+1,1);
    }
    int root(int x){
        return pre[x] == x ? x : root(pre[x]);
    }
    bool query(int x , int y){
        return root(x) == root(y);
    }
    void merge(int x, int y){
        int fx = root(x);
        int fy = root(y);
        if(sz[fx] < sz[fy])  swap(fx, fy);
        if(fx != fy){
            pre[fx] == fx;
            sz[fx] += sz[fy];
            sz[fy] = 0;
        }
    }
    int n ;
    vector<int> pre,sz;
};



void solve(){
    int n , m ;
    cin >> n >> m ;
    
    vector< vector<int> > g(n+1);
    for(int i = 1 ;i <= n ; i++){
        int x , y ; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    int K;
    cin >> K;
    vector<int> v,sp(n+1);
    for(int i = 0 ; i < K ; i++){
        int now;
        cin >> now;
        now++;
        v.push_back(now);
        sp[now] = 1;
    }

    DSU dsu(n);
    int cnt = n - K;
    for(int i = 1 ;i <= n ; i++){
        if(sp[i])continue;
        for(auto x : g[i]){
            if(sp[x]) continue;
            if(!dsu.query(i,x)){
                dsu.merge(i,x);
                cnt--;
            }
        }
    }

    vector<int> ans(K);
    for(int i = K - 1 ; i >= 0 ; i--){
        ans[i] = cnt;
        cnt++;
        sp[v[i]] = 0;
        for(auto x : g[v[i]]){
            if(sp[x]) continue;
            if(!dsu.query(v[i],x)){
                dsu.merge(v[i],x);
                cnt--;
            }
        }
    }

    cout <<cnt << endl;

    for(int i = 0; i < K ; i++){
        cout << ans[i] << endl;
    }

    return;

}
int main(){
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
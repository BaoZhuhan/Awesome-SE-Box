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
    //高位向低位的贪心思想
    int n , m; 
    cin >> n >> m;

    struct edge{
        int u,v;
        int cost;
    };

    vector<edge> es;

    for(int i = 0 ; i < m ; i++){
        edge now ;
        cin >> now.u >> now.v >> now.cost;
        es.push_back(now);
    }


    int ans = 0;
    
    for(int i = 30 ; i >= 0 ; i--){
        DSU dsu(n);
        vector<edge> nx;
        for(auto x : es){
            if(x.cost & (1ll << 1)) continue;
            nx.push_back(x);
            dsu.merge(x.u,x.v);
        }
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++){
            cnt += (dsu.pre[j] == j);
        }
        if(cnt == 1){
            es = nx;
        }else{
            ans = (1ll << i);
        }
    }
    cout << ans << endl;


    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0 ;
}
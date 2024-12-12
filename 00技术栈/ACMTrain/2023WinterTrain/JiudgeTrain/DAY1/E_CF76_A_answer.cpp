#include <bits/stdc++.h>
using namespace std;
#define inf (long long)(1e15);
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
    int g ,s;
    cin >> g >> s;
    struct edge{
        int u , v;
        int g ,s;
    };
    vector<edge> es;
    for(int i = 1 ; i <= m ; i++){
        edge now;
        cin >> now.u >> now.v >> now.g >> now.s;
        es.emplace_back(now);
    }
    long long ans = inf;
    sort(es.begin(),es.end(),[&](edge a ,edge b){
        return a.g < b.g;
    });

    vector<edge> tmpes;

    for(auto x : es){
        tmpes.emplace_back(x);
        sort(tmpes.begin() , tmpes.end() , [&](edge a , edge b){
            return a.s < b.s;
        });
        DSU dsu(n);
        int mxg = 0 , mxs = 0;
        vector<edge> nx;
        for(auto xx : tmpes){
            if(dsu.query(xx.u ,xx.v)) continue;
            mxg = max(mxg , xx.g);
            mxs = max(mxs , xx.s);
            dsu.merge(xx.u ,xx.v);
            nx.emplace_back(xx);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(dsu.pre[i] == i) cnt++;
        }
        if(cnt == 1) ans = min(ans , mxg*g + )
    }


}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
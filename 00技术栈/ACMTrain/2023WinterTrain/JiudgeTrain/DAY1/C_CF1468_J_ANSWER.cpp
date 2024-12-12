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

void run(){
    int n , m;cin>> n >> m ;
    struct edge{
        int u ,v;
        int cost;
    };
    vector<edge> es;
    for(int i = 0 ; i < m ; i++){
        edge now ; 
        cin >> now.u >> now.v >> now.cost;
        es.emplace_back(now);
    }
    sort(es.begin() , es.end() , [&](edge a , edge b));
    DSU dsu(n);

    int ans = 0 , mi = 2e15;
    for(auto x : es){
        mi = min(mi,fabs(mi -k));
        if(dsu.query(x.u,x.v)){
            dsu.merge(x.u,x.v);
            ans += max(0,x.cost - k);
        }
    }

    if(ans != 0){
        cout << ans <<endl;
    
    }else{
        cout << mi << endl;
    }


}
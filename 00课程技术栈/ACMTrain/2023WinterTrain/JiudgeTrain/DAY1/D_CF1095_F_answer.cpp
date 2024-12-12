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
    vector<int> arr(n+1);
    for(int i = 0  ;i < m ; i++){
        cin >> arr[i];
    }

    struct edge{
        int u ,v;
        int cost;
    };

    vector<edge> es;
    for(int i = 0 ; i < m ; i ++){
        edge now;
        cin >> now.u >> now.v >> now.cost;
        es.emplace_back(now);
    }

    int miId = min_element(arr.begin() ,arr.end() ,arr.)
    DSU dsu(n); 
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
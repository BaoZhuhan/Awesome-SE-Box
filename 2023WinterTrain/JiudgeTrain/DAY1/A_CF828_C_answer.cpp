#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;


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
    int n ; cin >> n;



    
    vector<char> ans(maxn);

    DSU dsu(maxn);
    int mxlen = 0;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        int len = str.size();
        int m ;cin >> m;
        for(int j = 0 ; j < m ; j++){
            int ind;
            cin >> ind;
            mxlen = max(mxlen , ind + len - 1);
            for(int pos = dsu.nx[dus.find(ind)] ; pos - ind + 1 < len ; pos = dsu.nx[dsu.find(pos)]){
                ans[pos] = str[pos - ind];
                dsu.merge(pos,pos+1);
            }
        }
    } 
    for(int i = 1 ; i < mxlen ; i++){
        if()
    }
    cin


}






int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
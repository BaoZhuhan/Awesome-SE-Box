#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e5 + 9;
const long long inf = 1e18;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int v;

void dijkstra(int s){
    fill(d,d+v,inf);
    fill(used,used+v,false);
    d[s] = 0;

    while(true){
        int v = -1;
        for(int u = 0 ; u < v ; u++){
            if(!used[u] and (v == -1 or d[u] < d[v])) v = u;
        }

        if(v == -1 ) break;
        used[v] = true;

        for(int u = 0 ; u < v ; u++ ){
            d[u] = min(d[u] , d[v] + cost[v][u] );
        }
    }
}

void solve(){
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
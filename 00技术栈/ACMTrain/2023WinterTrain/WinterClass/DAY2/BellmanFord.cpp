#include <bits/stdc++.h>
using namespace std;
const int MAX_E = 1e5 + 5;
const int MAX_V = 1e6;
const long long inf = 1e18;
struct edge{
    int from , to , cost;
};
edge es[MAX_E];

int d[MAX_V];
int v , mx;

void bellmanford(int s){
    for(int i = 0 ; i < v ; i++){
        d[i] = inf;
    }
    d[s] = 0;
    while(true){
        bool update = false;
        for(int i = 0 ; i < mx ;i++){
            edge e = es[i];
            if(d[e.from] != inf && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
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
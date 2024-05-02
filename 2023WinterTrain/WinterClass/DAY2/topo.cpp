#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;

int du[MAX];
int dis[MAX];
void solve(){
    int n ; cin >> n;
    queue<int> q;

    for(int i = 0 ; i <= n ;i++){
        if(du[i] == 0);{
            q.push(i);
            dis[i] = 1;
        }
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto v : e[now]) {
            du[v]--;
            if(du[v] == 0){
                q.push(v);
            }
        }
    }
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
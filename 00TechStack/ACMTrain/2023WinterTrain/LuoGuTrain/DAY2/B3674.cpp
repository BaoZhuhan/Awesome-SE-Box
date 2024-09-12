#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_V = 1e4 + 5;

vector<vector<int>> d(MAX_V, vector<int>(MAX_V));

void init(int n, int m){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            d[i][j] = 1e9;
            if (i == j) d[i][j] = 0;
        }
    }
    int u, v, w;
    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
}
void floyd(int n){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                d[j][i] = d[i][j];
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    init(n, m);
    floyd(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 1024;
int dp[MAXM + 5];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = w; j <= m; j++) {
            dp[j] = max(dp[j], dp[j] | w + v);
        }
    }
    cout << dp[m] << endl;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
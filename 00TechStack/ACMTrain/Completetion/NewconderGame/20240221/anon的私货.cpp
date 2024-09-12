#include <bits/stdc++.h>
using namespace std;
#define int long long

void run()
{
    int n;
    cin >> n;
    pair<int, int> a[n + 2];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = a[i].first - 1;
        a[i].first--;
    }
    int tmp;
    a[0].second = 1e9;
    a[n + 1].first = 1e9;
    for (int i = 1; i <= n + 1; i++)
    {
        tmp = min(a[i].first, a[i - 1].second);
        a[i].first -= tmp;
        a[i - 1].second -= tmp;
        a[i].second -= tmp;
        ans += tmp;
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
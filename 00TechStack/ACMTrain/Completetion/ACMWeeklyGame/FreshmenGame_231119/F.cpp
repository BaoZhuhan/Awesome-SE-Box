#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (v[0] == 1)
        v[0]++;
    for (int i = 1; i < n; ++i)
    {
        while (v[i] % v[i - 1] == 0 or v[i] == 1)
            v[i]++;
    }
    
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
}

signed main(void)
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
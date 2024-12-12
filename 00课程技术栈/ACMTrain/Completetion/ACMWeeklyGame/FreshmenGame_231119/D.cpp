#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string mid[n], a[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> mid[i];
    for (int i = 1; i <= n; ++i)
    {
        a[i] += ' ';
        a[i] += mid[i - 1];
    }
    int ans = 0;
    array<char, 4> s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            s[0] = a[i][j];
            s[1] = a[j][n - i + 1];
            s[2] = a[n - i + 1][n - j + 1];
            s[3] = a[n - j + 1][n - (n - i + 1) + 1];
            int mx = s[0] - 'a';
            for (int i = 1; i < 4; ++i)
                mx = max(mx, s[i] - 'a');
            for (int i = 0; i < 4; ++i)
                ans += mx - (s[i] - 'a');
        }
    }
    cout << ans / 4 << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
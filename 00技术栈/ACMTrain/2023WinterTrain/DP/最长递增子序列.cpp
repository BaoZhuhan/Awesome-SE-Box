#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> d;
int DP(int t)
{
    int res = 0;
}
void solve()
{
    int n;
    cin >> n;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        d.push_back(tmp);
    }
    int res = DP(n);
    cout << res << endl;
}
int main()
{
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
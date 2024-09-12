#include <bits/stdc++.h>
using namespace std;
string a;
int sec_solve(int p, int t)
{
    int res = 0;
    if (t == 0)
    {
        for (int i = p - 1; i >= 0; i--)
        {
            if (a[i] == '0' or a[i] == '5')
            {
                return res;
            }
            res++;
        }
    }
    else
    {
        for (int i = p - 1; i >= 0; i--)
        {
            if (a[i] == '7' or a[i] == '2')
            {
                return res;
            }
            res++;
            // cout << "函数sec_solve res-->" << res << endl;
        }
    }
    return 100;
}

void solve()
{
    cin >> a;
    //cout << "a-->  " << a << endl;
    int res = 0;int tmp = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '0')
        {
            res += sec_solve(i, a[i] - '0');
            break;
        }
        res++;
        // cout << "函数solve  res-->" << res << endl;
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '5')
        {
            tmp += sec_solve(i, a[i] - '0');
            break;
        }
        tmp++;
        // cout << "函数solve  res-->" << res << endl;
    }
    if(res > tmp) res = tmp;
    cout << res << '\n';
}
signed main(void)
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
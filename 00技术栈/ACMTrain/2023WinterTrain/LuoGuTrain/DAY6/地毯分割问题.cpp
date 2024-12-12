#include <bits/stdc++.h>
using namespace std;

long long x, y, len;
int k;
long long fun(int k)
{
    long long sum = 1;
    for (int i = 1; i <= k; ++i)
        sum *= 2;
    return sum;
}
void solve(long long x, long long y, long long a, long long b, long long l)
{
    if (l == 1)
        return;
    if (x - a <= l / 2 - 1 && y - b <= l / 2 - 1)
    {
        cout << a + l / 2 << ' ' << b + l / 2 << ' ' << 1 << endl;
        solve(x, y, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    }
    else if (x - a <= l / 2 - 1 && y - b > l / 2 - 1)
    {
        cout << a + l / 2 << ' ' << b + l / 2 - 1 << ' ' << 2 << endl;
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(x, y, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    }
    else if (x - a > l / 2 - 1 && y - b <= l / 2 - 1)
    {

        cout << a + l / 2 - 1 << ' ' << b + l / 2 << ' ' << 3 << endl;
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(x, y, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    }
    else
    {
        cout << a + l / 2 - 1 << ' ' << b + l / 2 - 1 << ' ' << 4 << endl;
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(x, y, a + l / 2, b + l / 2, l / 2);
    }
}

int main()
{
    cin >> k >> x >> y;
    len = fun(k);
    solve(x, y, 1, 1, len);
    return 0;
}

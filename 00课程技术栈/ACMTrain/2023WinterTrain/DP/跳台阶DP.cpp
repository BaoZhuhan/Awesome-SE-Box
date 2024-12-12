#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int mem[N];

int dfs(int t)
{
    if(t <= 0){
        return 0;
    }
    int sum = 0;
    if (mem[t])
    {
        return mem[t];
    }
    else if (t == 1 or t == 2)
    {
        sum = t;
    }
    else
    {
        sum = dfs(t - 1) + dfs(t - 2);
    }
    mem[t] = sum;
    return sum;
}
void solve()
{
    memset(mem , sizeof(mem),0);
    int t;
    cin >> t;
    int res = dfs(t);
    cout << res;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans[45][45], m, f[45][45], fx[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1}, fy[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
bool check(int u,int v)
{
    if (u < 0 or v< 0)
    {
        return false;
    }
    else if (u > n or v > m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
struct node
{
    int x, y;
};
void bfs(){
    queue<node> q;
    q.push({0, 0});
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        int tx = now.x, ty = now.y;
        if (tx > n || ty > m || f[tx][ty])
            continue;
        f[tx][ty] = 1;
        q.push({tx + 1, ty}), q.push({tx, ty + 1});
        ans[tx + 1][ty] += ans[tx][ty], ans[tx][ty + 1] += ans[tx][ty];
    }
}
signed main()
{
    int x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i <= 8; ++i)
    {
        int ux = x + fx[i], uy = y + fy[i];
        if (!check(ux, uy))
            continue;
        f[ux][uy] = 1;
    }
    ans[0][0] = 1;
    bfs();
    cout << ans[n][m];
}
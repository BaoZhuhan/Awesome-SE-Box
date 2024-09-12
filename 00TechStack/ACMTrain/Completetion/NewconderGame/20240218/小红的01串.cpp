#include <bits/stdc++.h>
using namespace std;

string a;
int sorce = 0;

struct node
{
    int cnt;
    int cnt2;
    int cot;
};

void bfs()
{
    queue<node> q;

    node root;
    root.cnt = 0;
    root.cnt2 = root.cnt;
    root.cot = sorce;

    q.push(root);

    while (!q.empty())
    {
        node now = q.front();
        q.pop();

        sorce = sorce > now.cot ? sorce : now.cot;
        // cout << now.cnt << ' ' << now.cnt2 << ' ' << now.cot << endl ; 

        if (now.cnt2 + 1 >= a.size())
            continue;

        node left;
        left.cnt = now.cnt2 + 1;
        left.cnt2 = left.cnt;
        left.cot = (a[now.cnt] == '1' ? now.cot - 1 : now.cot + 1);

        node right;
        right.cnt = now.cnt;
        right.cnt2 = now.cnt2 + 1;
        right.cot = (a[right.cnt2] == '1' ? now.cot - 1 : now.cot + 1);
        
        q.push(left);
        q.push(right);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a;

    for (int i = 0; i < a.size(); i++)
        a[i] == '1' ? sorce++ : sorce--;

    bfs();

    sorce = sorce < 0 ? 0 : sorce;

    cout << sorce;

    return 0;
}
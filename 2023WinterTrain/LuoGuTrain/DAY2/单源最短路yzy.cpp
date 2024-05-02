#include <bits/stdc++.h>

using namespace std;

const int MX = 100010;
const int INF = 1e9;

struct Edge
{
    int to, weight;
};

vector<Edge> adj[MX];
int dist[MX];
bool visited[MX];

void solve()
{
    int n, m, ss;
    cin >> n >> m >> ss;
    for(int i = 0 ; i < m ;i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    fill(dist, dist + n + 1, INF);
    dist[ss] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, ss));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto &e : adj[u])
        {
            int v = e.to;
            int weight = e.weight;
            if (dist[u] + weight <= dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i  = 1 ; i <= n ;i++ )
        cout << dist[i] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    // std::cin>>t;
    while (t--)
        solve();
    return 0;
}

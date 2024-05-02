#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 4e6 + 9;
const int M = 1e9 + 10;
vector<int> pre(MAXN);
vector<int> ans(2);
int k = 0;

struct edge{
    int left,right;
    long long val;
}bian[MAXN];

void init(int n , int m){
    for(int i = 1 ; i <= n ; i++) pre[i] = i;
    for(int i = 1 ; i <= m ; i++) cin >> bian[i].left >> bian[i].right >> bian[i].val;
}

int root(int i)
{
    if(pre[i] == i){
        return i;
    }else{
        pre[i] = root(pre[i]); 
        return pre[i];
    }
}

void kruskal(int n , int m)
{
    int total = 0 ;
    for(int i = 1 ; i <= m; i++)
    {
        int u=root(bian[i].left);
        int v=root(bian[i].right);
        if(u == v) continue;
        else{
            int anstmp = bian[i].val - k;
            if(anstmp >= 0 and fabs(anstmp) < ans[0]){
                ans[0] = fabs(anstmp);
            }else if(anstmp < 0 and fabs(anstmp) < ans[1]){
                ans[1] = fabs(anstmp);
            }
            pre[u] = v;
            total++;
            if(total == n-1) break;
        }
    }
}

bool cmp(edge a,edge b)
{
    return fabs(a.val - k) < fabs(b.val - k);
}

void solve()
{   
    k = 0;pre.clear();ans[0] = MAXN ; ans[1] = MAXN;
    int n , m;cin >> n >> m >> k;
    init(n , m);
    sort(bian+1,bian+m+1,cmp);
    kruskal(n , m);
    cout << (ans[0] > ans[1] ? ans[1] : ans[0]) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
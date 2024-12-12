#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() , a.end()) ; 
    
    int ans = 0;
    bool flag = false;
    int tmp = a[1] * 4;


    for (int i = 1; i < n; i++)
    {   
        if(flag) break;
        if( a[i] == a[1] ){
            ans += tmp / 2 * (n - i);
            continue;
        }

        for(int j = i + 1; j <= n ; j++ ){
            // ans += min(a[i] * 2 , a[1] * 4);
            if(a[i] * 2 < tmp) ans += a[i] * 2;
            else {
                ans += tmp * (1 + n - i ) * (n - i) / 2;
                flag = true;
                break;
            }
        }
    }
    cout << ans * 2<< '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
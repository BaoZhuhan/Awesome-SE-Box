#include <bits/stdc++.h>
#define ll long long
using namespace std;
signed solve(void)
{
    int n, k;
    cin >> n >> k;
    cout << (n + k- 1 +  k - 1) / k  << '\n'; // but why can i made this ,what's the meaning of  k - 1 in the last ;
    
    return 0;
}
//n+k-1+k-1/k
signed main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve();
    }
    return 0;
}
// 1001001   n=8 k= 3

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 1e9 + 7;

int n, a[N], f[N];
int mn = 1e9, mx = -1e9;

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        f[a[i]]++;
    }


    long long ans = 0 ;
    for (int i = mn + 1; i <= mx; i++)
    {
        if (f[i] <= 1) {continue ;}

        for (int j = mn; j <= i / 2; j++){
            if (f[j] and f[i - j]){
                if (j != i - j){ans = ans + ((f[i] * (f[i] - 1) >> 1) * f[j] * f[i - j]) % mod;}
                else if (f[j] >= 2) {ans = ans + ((f[i] * (f[i] - 1) >> 1) * (f[j] * (f[j] - 1) >> 1) % mod) % mod;}
            }
        }
    }

    printf("%lld\n", ans % mod);
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void run()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<bool> used(1e4+9 , false);
    vector<int> a(1e4 + 9, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int x = a[i] ;

        for(int j = 1 ; j <= a[i] ; j++ ) {x -= used[j] ;}

        used[a[i]] = 1;
        a[i] = x - 1 ;

    }
    a[n] += m ;

    for(int i = n ; i > 0 ; i--) {
        a[i-1] += a[i]/(n-i+1) ;
        a[i] %= n-i+1;
    }

    used = vector<bool> (1e4+9,false);
    
    for(int i = 1; i <= n ; i++) {
        for(int j = 0 ; j <= a[i] ; j++ ){
            if(used[j]) {a[i]++ ;}
        }
        cout << a[i] + 1<< ' ';
        used[a[i]] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        run();
    }
    return 0;
}
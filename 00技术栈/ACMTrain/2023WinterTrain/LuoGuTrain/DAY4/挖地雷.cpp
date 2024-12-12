#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

void run(){
    int n ;cin >> n;
    vector<int> num(MAXN);
    vector< vector<bool> > mp(MAXN,vector<bool> (MAXN , false)) ;
    vector<int> dp(MAXN);
    vector<int> pre(MAXN);
    for(int i = 1 ; i <= n ; i++ ) cin >> num[i];
    for(int i = 1 ; i <= n ; i++ ) {
        for(int j = i + 1 ; j <= n ; j++){
            int u ; cin >> u;
            mp[i][j] = (u == 1) ? true : false;
        }
    }

    dp[n] = num[n];
    int maxi = n;
    for(int i = n-1 ; i >= 1 ; i-- ){
        dp[i] = num[i];
        pre[i] = 0;
        for(int j = i+1 ; j <= n ; j++ ){
            if(mp[i][j] == 1 and (dp[j] + num[i] > dp[i]) ){
                dp[i] = dp[j] + num[i];
                pre[i] = j;
            }
        }
        if(dp[i] > dp[maxi]) maxi = i;
    }
    int p = maxi;
    while(p > 0){
        cout << p << ' ';
        p = pre[p];
    }
    cout << endl;
    cout << dp[maxi]; 
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
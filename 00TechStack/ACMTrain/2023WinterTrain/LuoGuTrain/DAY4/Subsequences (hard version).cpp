#include <bits/stdc++.h>
using namespace std ;

int n ; 
long long k;

string s;
int pre[105] , last[105];
long long dp[105][105];

int main(){
    cin >> n >> k;
    cin >> s;
    
    s = "&" + s;
    for(int i = 1 ; i <= n ; i++) {
        int c = s[i] - 'a';
        pre[i] = last[c];
        last[c] = i;
    }

    for(int i = 0 ;i <= n ; i++){
        dp[i][0] = 1;
    }

    for(int i = 1 ;i <= n ; i++){
        for(int j = 1; j <= i ; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ;
            if(pre[i]) dp[i][j] -= dp[pre[i] -1][j-1] ; 
        }
    }

    long long ans = 0;

    for(int j = n ; j >= 0 ; j--){
        if(k >= dp[n][j] ) {
            ans += (long long)(n - j ) * dp[n][j] ;
            k -= dp[n][j] ;
        }
        else{
            ans += (long long)(n - j)*k;
            k = 0 ;
            break;
        }
    }

    if(k) cout << "-1" <<endl;
    else cout << ans << endl;

    return 0;

}
#include <bits/stdc++.h>
using namespace std ;


void run(){
    int n ;cin >> n ;
    
    int dp[n][n];
    memset(dp,0,sizeof(dp));


    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            cin >> dp[i][j] ;

            if( i == 0 and j == 0 ) continue ;

            else if( j == 0 ) dp[i][j] = dp[i][j] + dp[i-1][j];

            else if( j == i ) dp[i][j] = dp[i][j] + dp[i-1][j-1];

            else dp[i][j] = dp[i][j] + max(dp[i-1][j] , dp[i-1][j-1]) ;
        }
    }

    int ans = 0;

    for(int i = 0 ; i < n ; i++) ans = ans > dp[n-1][i] ? ans : dp[n-1][i] ;

    cout << ans ;


}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    run();

    return 0;
}
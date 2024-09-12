#include <bits/stdc++.h>
using namespace std;

const int MAXN=20;

int dx[4]={-1,-2,-2,-1};
int dy[4]={-2,-1,1,2};
int dp[MAXN][MAXN];



void run(){
    int n , m ; cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 0 ; i <= m ; i++){
        for(int j = 0 ; j <= n ; j++){
            for(int k = 0 ; k < 4 ;k++ ){
                int tx = i + dx[k];
                int ty = j + dy[k];
                if( 0 <= tx and tx <= m and 0 <= ty and ty <= n){
                    dp[i][j] += dp[tx][ty];
                }
            }
        }
    }
    cout << dp[m][n];
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}


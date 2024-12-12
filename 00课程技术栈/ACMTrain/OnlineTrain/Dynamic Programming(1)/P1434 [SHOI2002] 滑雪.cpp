#include <bits/stdc++.h>

int f[105][105];
int a[105][105];

int n = 0 , m = 0  , sum = 0  ;

int dp(int x , int y ) {
    if(f[x][y]) return f[x][y];
    
    int sum = 0 ;
    if(x-1 > 0 ) if(a[x-1][y] > a[x][y]) sum = std::max(sum , dp(x-1 , y));
    if(x+1 > 0 ) if(a[x+1][y] > a[x][y]) sum = std::max(sum , dp(x+1 , y));
    if(y+1 > 0 ) if(a[x][y+1] > a[x][y]) sum = std::max(sum , dp(x , y+1));
    if(y-1 > 0 ) if(a[x][y-1] > a[x][y]) sum = std::max(sum , dp(x , y-1));
    f[x][y] = sum + 1;
    
    return f[x][y];

}
void run(){
    std::cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) {

        for(int j = 1 ; j <= m ; j++ ) {

            std::cin >> a[i][j];
        }
    }

    for(int i = 1 ; i <= n ; i++) {

        for(int j = 1 ; j <= n ; j++) {
            
            if(f[i][j] == 0) f[i][j] = dp(i,j);
            sum = std::max(sum ,f[i][j]);

        }
    }

    std:: cout << sum ;
    
}
int main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0);

    run();

    return 0;
}
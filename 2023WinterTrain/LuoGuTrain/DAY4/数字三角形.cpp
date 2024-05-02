#include <bits/stdc++.h>
using namespace std;

#define MAXN 


void run(){
    int n ; cin >> n;
    vector<vector <int> > mp( n+1 , vector<int>(n+1) );
    int res = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++ ){
            cin >> mp[i][j];
            mp[i][j] += max(mp[i-1][j-1] , mp[i-1][j]);
            if(i == n ){
                res = (res > mp[i][j] )? res : mp[i][j] ;
            }
        }
    }
    cout << res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
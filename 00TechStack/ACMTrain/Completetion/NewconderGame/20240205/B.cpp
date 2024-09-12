#include <bits/stdc++.h>
using namespace std;

int xx[4] = {0,1,-1,0};
int yy[4] = {1,0,0,-1};

void solve(){
    //不要忘记main函数的T
    int n , m , k ; cin >> n >> m >> k ;
    vector<vector<int> > mp(305,vector<int> (305 , 0));
    int res = 0 ; 
    for(int i = 0 ; i < k ; i++) {
        
        int x , y ; 
        cin >> x >> y ; 
        mp[x][y] = 1;
        res += 4;
        for(int j = 0 ; j< 4 ; j++ ){
            if(mp[x+xx[j]][y+yy[j]] == 1) res -= 1;
        }
    }
    // for(int i = 0 ; i < n+1 ; i++) {
    //     for(int j = 0 ; j < m+1 ; j++) {
    //         cout << mp[i][j] <<' ' ;

    //     }
    //     cout << endl;
    // }

    cout << res ;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
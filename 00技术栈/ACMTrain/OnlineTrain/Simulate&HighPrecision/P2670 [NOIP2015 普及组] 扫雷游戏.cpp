#include <bits/stdc++.h>
using namespace std;

int xx[8] = {0,0,1,-1,1,1,-1,-1};
int yy[8] = {1,-1,0,0,1,-1,-1,1};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n , m ;cin >> n >> m;
    vector<vector<int> > mp(n + 2,vector<int> (m + 2 , 0)) ;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            char tmp ; cin >> tmp ;
            mp[i][j] = (tmp == '*' ? -1 : 0 );
        }
    }
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(mp[i][j] == -1) cout << '*';
            else{
                for(int k = 0 ; k < 8 ; k ++) {
                    if(mp[i+xx[k]][j+yy[k]] == -1) mp[i][j]++;
                }
                cout << mp[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}
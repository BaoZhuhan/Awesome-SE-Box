#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e5 + 5;
vector<vector<int> > d(MAX_V, vector<int>(MAX_V));
int v;
void floyd(){
    for(int k = 0 ; k < v ; k++){
        for(int  i = 0 ; i < v ;i++){
            for(int j = 0 ; j < v ; j++){
                d[i][j] == min(d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }
}
int solve(){
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
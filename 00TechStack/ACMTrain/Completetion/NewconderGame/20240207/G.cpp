#include <bits/stdc++.h>
using namespace std;

struct node {
    int x , y ,z;
};

void solve(){
    int n ; cin >> n ;
    node a[n+1];
    bool ans = true;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].x >> a[i].y >> a[i].z ; 
        ans = (a[i].x == a[i].y and a[i].z == 1) ? false : ans ; 
    }
    if(n != 1){
        ans = (a[1].z == 1 and a[2].z == 1 and a[2].x == a[1].y and a[2].y == a[1].x) ? false : ans ;
        ans = (a[1].z == 1 and a[2].z == 0 and a[2].x == a[1].x and a[2].y == a[1].y) ? false : ans ;
        ans = (a[1].z == 0 and a[2].z == 1 and a[2].x == a[1].x and a[2].y == a[1].y) ? false : ans ;
    }
    cout << (ans ? "Yes\n" : "No\n");
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
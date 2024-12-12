#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n , m ;
    cin >> m >> n ;
    for(int i = 0 ; i < m ; i++ ){
        int res = 0 ; 
        for(int j = 0 ; j < n ; j++ ){
            int tmp ; 
            cin >> tmp ;
            res += tmp ;
        }
        cout << res << '\n';
    }
    return 0;
}
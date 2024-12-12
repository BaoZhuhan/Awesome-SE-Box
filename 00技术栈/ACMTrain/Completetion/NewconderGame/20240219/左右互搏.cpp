#include <bits/stdc++.h>
using namespace std;

#define int long long
void run(){

    int n ; cin >> n ;
    int sm; 
    for(int i = 0 ; i < n ; i ++) {
        int tmp ; cin >> tmp; 
        sm = sm + tmp - 1;
    } 
    cout << (sm % 2 == 0 ? "sweet" : "gui") ;
    return ;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    run() ;
    return 0;
}
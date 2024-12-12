#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n ){
    //朴素求单个质数
    if(n < 2) return false;
    for(int i = 2 ; i*i <= n ; ++i){
        if(n % i == 0) return false;
    }
    return true;
}


void solve(){
    
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
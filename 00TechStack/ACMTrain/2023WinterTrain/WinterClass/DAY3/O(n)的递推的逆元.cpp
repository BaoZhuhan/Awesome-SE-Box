#include <bits/stdc++.h>
using namespace std;


vector<int> prime;
void get_prime(int n){
    vector<bool> not_prime(n + 1);

    for(int i = 2 ; i <= n ; i++){
        if( !not_prime[i]) prime.emplace_back(i);
        for(int pri_j : prime){
            if(i * pri_j > n ) break;
            not_prime[i * pri_j] = true;
            if(i % pri_j == 0) break;
        }
    }
    return;
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
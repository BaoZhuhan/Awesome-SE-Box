#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void get_prime(int n){
    //复杂度 nloglogn  名称：埃式筛
    //判断所有质数
    vector<bool> vis( n + 1 );
    for(int i = 2 ; i <= n ; i++){
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i *2 ; j <= n ;j += i ) vis[j] = true;
    }
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
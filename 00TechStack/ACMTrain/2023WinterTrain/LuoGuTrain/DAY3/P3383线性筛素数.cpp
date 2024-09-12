#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
void get_prime(int n){
    //线性筛 ，复杂度 n ， 依据：所有合数都可以写成质数的和
    vector<bool> vis(n+1);
    for(int i =2 ; i <= n ; i++){
        if(!vis[i]) prime.push_back(i);
        for(auto j : prime){
            if(i *j > n) break;
            vis[ i * j] = true;
            if(i % j == 0) break;
        }
    }
}
void solve(){
    int n , m ; cin >> n >> m;
    get_prime(n);

    for(int i = 0 ; i < m ; i++){
        int tmp; cin >> tmp;
        cout << prime[tmp -1] << '\n';
    }
    return ;
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
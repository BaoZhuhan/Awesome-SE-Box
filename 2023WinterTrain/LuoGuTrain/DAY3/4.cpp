#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> get_phi(int n){
    vector<int> prime ,phi(n+1);
    vector<bool> vis;
    phi[1] = 1;
    for(int i = 2; i <= n ; i++){
        if(!vis[i]){
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for(int j = 0 ; i * prime[j] <= n and j < prime.size() ; j++){
            int k = i * prime[j];
            vis[k] = 1;
            if(i % prime[j] == 0){
                phi[k] = phi[i] * prime[j];
            }else{
                phi[k] = (prime[j] - 1) * phi[i];   
            }
        }
    }
    return move(phi);
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n ;
    cin >> n ; 
    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }
    vector<int> phi = get_phi(n);
    int ans = 0;
    for(int i = 1 ; i < n ; i++) ans += phi[i];
    cout << ans*2 + 1;
    return 0;
}
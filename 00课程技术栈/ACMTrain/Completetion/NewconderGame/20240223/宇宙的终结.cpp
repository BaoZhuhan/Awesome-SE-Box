#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void get_prime(int n){
    vector<bool> vis( n + 1 );
    for(int i = 2 ; i <= n ; i++){
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i *2 ; j <= n ;j += i ) vis[j] = true;
    }
}

void run(){
    int l , r ; 
    cin >> l >> r;
    get_prime(r);


    for(int i = 0 ; i < prime.size() - 2; i++){
        for(int j = i+1 ; j < prime.size() - 1; j++){
            for(int k = j+1; k < prime.size() ; k++){
                int x = prime[i] * prime[j] * prime[k] ;
                if(x >= l and x <= r ){
                    cout << x;
                    return ;
                }
            }
        }
    }
    cout << -1 ;
    return ;

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}
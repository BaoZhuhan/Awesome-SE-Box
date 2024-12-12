#include <bits/stdc++.h>
using namespace std;

const int M = 100;
void run(){
    int t , m ; cin >> t >> m;
    vector<int> time(M , 0);
    vector<int> value(M , 0);
    for(int i = 1 ; i <= m ; i++) cin >> time[i] >> value[i];
    vector<int> dp(t+1 , 0);
    for(int i = 1 ; i <= m ;i++){
        for(int j = t ; j >= time[i] ; j-- ){
            dp[j] = max(dp[j] , dp[j - time[i]] + value[i]);
        }
    }
    cout << dp[t];
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
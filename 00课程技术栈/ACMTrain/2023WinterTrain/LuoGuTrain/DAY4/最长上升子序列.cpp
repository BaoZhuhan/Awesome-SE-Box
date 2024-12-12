#include <bits/stdc++.h>
using namespace std;

void run(){
    int n ; cin >> n;
    vector<int> num(n+1);
    vector<int> dp(n+1);
    int ans = 1;
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    for(int i = 0 ; i < n ; i++){
        dp[i] = 1;
        for(int j = 0 ; j < i ;j++ ){
            if(num[j] < num[i]){
                dp[i] = max(dp[i] , dp[j] + 1);            
            }
            ans = dp[i] > ans ? dp[i] : ans ;
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
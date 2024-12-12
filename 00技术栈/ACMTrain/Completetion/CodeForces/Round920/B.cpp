#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin >> t;
    string s1,s2;
    cin >> s1 >> s2;
    int cot_0 = 0;
    int cot_1 = 0; 
    for(int i = 0 ; i < t; i++){
        if(s1[i] != s2[i] and s1[i] == '1'){
            cot_0++;
        }else if(s1[i] != s2[i]){
            cot_1++;
        }
    }
    int ans = (cot_1 >= cot_0)? cot_1 : cot_0;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
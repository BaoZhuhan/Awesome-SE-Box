#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int l;
    cin >> l;
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0 ; i < l ; i++){
        if(s[i] == '+'){
            res++;
        }else{
            res--;
        }
    }
    cout << fabs(res) << '\n';
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
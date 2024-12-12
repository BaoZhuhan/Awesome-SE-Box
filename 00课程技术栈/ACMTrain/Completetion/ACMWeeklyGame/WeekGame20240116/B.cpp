#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin >> t;
    int cot = 0;
    vector<int> a;
    for(int i = 0 ; i < t ;i ++){
        int n;
        cin >> n;
        cot++;
        for(int j = 0 ; j < n ;j++){
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
    }
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
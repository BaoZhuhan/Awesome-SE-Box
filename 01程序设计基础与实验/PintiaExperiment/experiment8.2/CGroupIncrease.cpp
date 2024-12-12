#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

void solve(){
    int l;
    cin >> l;
    vector<int> v;
    vector<int> s(l);
    vector<int> t(l);

    int mx;
    bool flag = false;
    for(int i = 0 ; i < l ;i++ ){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(i == 0){
            mx = tmp;
        }
        if(v[i] > mx){
            mx= v[i] ;
        }
    }
    int res = 0;
    for(int i = 0 ; i < l ;i++){
        if(flag == false and v[i] == mx){
            flag =true;
            continue;
        }
        if(flag == true and v[i] <)
    }
    if(res == 0) res = 1;
    cout << (res-1) << '\n';
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
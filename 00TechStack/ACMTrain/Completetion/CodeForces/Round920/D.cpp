#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n ,m ;
    cin >> n >> m;
    deque<int> s1;
    deque<int> s2;
    int tmp;
    for(int i = 0 ; i< n ; i++){
        cin >> tmp;
        s1.push_back(tmp);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> tmp;;
        s2.push_back(tmp);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int res = 0;
    int res1;
    int res2;
    for(int i = 0 ;i < n ; i++){
        int res1 = fabs(s1.back() - s2.front());
        int res2 = fabs(s2.back() - s1.front()); 
        int p_mx = (res1 > res2)? 1 : 2;
        if(p_mx == 1){
            res += res1;
            s1.pop_back();
            s2.pop_front();
        }else{
            res += res2;
            s1.pop_front();
            s2.pop_back();
        }
    }
    cout << res << '\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int a[N];
int pre[N];

void solve(){
    memset(a,sizeof(a),0);
    memset(pre,sizeof(pre),0);
    int n , k , x;
    cin >> n >> k >> x;
    for(int i = 1; i <= n ;i++ ){
        cin >> a[i];
    }
    sort(a,a+n+1);
    for(int i = 1; i <= n ;i++ ){
        pre[i] = pre[i-1] + a[i];
    }

    int res = 0;
    bool flag = false;

    for(int i = 0; i <= k ;i++){
        int tmp = pre[n];
        tmp -= (pre[n] - pre[n-i]);
        if(n - i -x >= 0 ){
            tmp -= 2*(pre[n-i] - pre[n-i-x]);
        }else{
            tmp -= 2*(pre[n-i]);
        }
        if(flag == false){
            res = tmp;
            flag = true;
        }else{
            if(res < tmp){
                res = tmp;
            }
        }
    }
    cout << res << '\n';
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
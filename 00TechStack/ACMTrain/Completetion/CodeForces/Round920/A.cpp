#include <bits/stdc++.h>
using namespace std;
#define int long long
int cal(int x1, int y1,int x2,int y2){
    int xx = fabs(x1-x2) * fabs(x1-x2);
    int yy = fabs(y1-y2) * fabs(y1-y2);
    return (xx+yy);
}
void solve(){
    int x1,y1;
    int x2,y2;
    int x3,y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int tmp;
    for(int i =0 ; i < 2 ; i ++){
        cin >> tmp;
    }
    int res = cal(x1,y1,x2,y2);
    int rev = cal(x1,y1,x3,y3);
    if( rev < res){
        res = rev;
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
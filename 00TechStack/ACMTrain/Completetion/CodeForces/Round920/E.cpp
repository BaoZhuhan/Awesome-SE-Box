#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int m , n , xa,ya,xb,yb;
    cin >> m >> n >> xa >> ya >> xb >> yb ;
    bool flag = true;
    int res = 0;
    // if(fabs(ya - yb) > 1){
    //     flag = false;
    //     cout << 1 << '\n';
    // }
    if(xa >= xb){
        flag = false;
        // cout << 2 << '\n';
    }
    res = ((xb - xa)%2 == 1)? 1:2;
    if(res == 1){
        if(fabs(m-yb) < (fabs(xa-xb)/2) and (m-ya) > (fabs(xa-xb)/2) + 1 ){
            flag = false;
        }else if(fabs(yb) < (fabs(xa-xb)/2) and (ya) >  (fabs(xa-xb)/2) + 1 ){
            flag = false;
        }   
    }else{
        if(fabs(m-ya) < (fabs(xa-xb)/2) and (m-yb) > (fabs(xa-xb)/2) + 1 ){
            flag = false;
        }else if(fabs(ya) < (fabs(xa-xb)/2) and (yb) >  (fabs(xa-xb)/2) + 1 ){
            flag = false;
        }  
    }
    if(flag == true){
        if(res == 1){
            cout << "Alice\n";
        }else{
            cout << "Bob\n";
        }
    }else{
        cout << "Draw\n";
    }
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
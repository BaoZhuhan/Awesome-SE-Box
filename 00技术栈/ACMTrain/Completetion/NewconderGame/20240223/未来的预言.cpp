#include <bits/stdc++.h>
using namespace std;

void run(){
    int n ;
    scanf("BO%d",&n);
    string s;
    cin >> s;

    int sa = 0 , sb = 0 ;
    bool flag = false;
    int ans = 0 ;
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == 'R') sa++;
        if(s[i] == 'P') sb++;
        ans++;
        if(sa == (int)(n/2+1) or sb == (int)(n/2+1)) {
            flag = true;
            break;
        } 
    }
    if(flag) {cout << (sa > sb ? "kou!" : "yukari!") << endl ;}
    else cout << "to be continued." << endl;

    cout << ans;
}
int main(){
    // ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}
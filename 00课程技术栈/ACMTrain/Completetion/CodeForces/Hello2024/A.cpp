#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int a , b;
    cin >> a >> b;
    if((a+b) % 2 == 0){
        cout << "Bob\n";
    }else{
        cout << "Alice\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
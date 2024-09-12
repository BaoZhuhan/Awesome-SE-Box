#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T ;cin >> T;
    while(T--){
        string a , b ; cin >> a >> b ;
        if(a[0] == b[0] or (a[0] - 'a' + 'A') == b[0] or (a[0] - 'A' + 'a') == b[0]) cout << "Yes" << '\n' ;
        else cout << "No" << '\n' ; 
    }
    return 0;
}
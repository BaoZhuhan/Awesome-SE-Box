#include <bits/stdc++.h>
#define int long long
using namespace std;
int n ;
string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZA" ;
signed zf( int index ) {
    for(int i = 0 ; i < index ; ++i ) {
        cout << str[i] ; 
    }
    for(int i = index - 2 ; i >= 0 ; --i ) {
        cout << str[i] ;
    }
    return 0 ;
}

signed blank( int index ) {
    for(int i = 0 ; i < n - index ; ++i ) cout << ' ' ; 
    return 0;
}
signed main(void){
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) {
        blank(i);
        zf(i);
        cout << '\n' ; 
    }

    return 0;
}
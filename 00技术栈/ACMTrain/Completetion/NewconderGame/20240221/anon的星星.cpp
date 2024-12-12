#include <bits/stdc++.h>
using namespace std ;

int main() {
    int n ,x  ;
    cin >> n >> x;
    
    bool flag = true;
    if((n + x) % 2 != 0 ) flag = false ;

    int a = (n + x) / 2 ;
    int b = a - x ;

    if(flag) cout << a << ' ' << b;
    else cout << -1;

    return 0;
}
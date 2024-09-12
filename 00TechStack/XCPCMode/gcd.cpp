#include <bits/stdc++.h>
using namespace std;

int main(){
    int a , b ,c , mx , mn ;
    cin >> a >> b >> c;
    mx = max(a , max(b,c));
    mn = min(a , min(b,c));
    cout << mn/__gcd(mx, mn) << "/" << mx/__gcd(mx , mn);
    return 0;
}
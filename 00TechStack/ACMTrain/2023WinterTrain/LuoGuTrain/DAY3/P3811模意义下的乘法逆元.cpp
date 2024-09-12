#include <bits/stdc++.h>
using namespace std;

static vector<int> get_inv(int n , int p){
    vector<int> inv(n+1);
    inv[1] = 1;
    for(int i = 2 ; i <= n ; i++) inv[i] = (long long)(p - p / i ) * inv[p%i] % p;
    return move(inv);
}

int main(){
    int n , q;
    cin >> n >> q;
    vector<int> a = get_inv(n,q);
    for(int i = 1 ; i <= n ; i++)cout << a[i] << '\n';
    return 0;
}
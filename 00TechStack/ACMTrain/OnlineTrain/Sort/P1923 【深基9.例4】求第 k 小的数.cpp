#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9 ; 

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int n , k ; cin >> n >> k ;

    vector<int> a(n) ;

    for(int i = 0 ; i < n ; i++ ){
        cin >> a[i];
    }

    sort(a.begin() , a.end()) ;

    cout << a[k] ; 
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

int main(){

    int n ; 
    cin >> n ;

    vector<int> a(n) ;

    for(int i = 0 ; i < n ; i ++) cin >> a[i] ;

    sort( a.begin() , a.end() );

    int cost = 0;

    for(int i = 0 ; i < n; i++ ){
        if(i == 0) cost += 1;
        else{
            if(a[i] != a[i-1] + 1) cost += 1;
        }
    }

    cout << cost ;

    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int n , x , k ; cin >> n >> x >> k ;
    
    int res = n*x / k ; cout << res << endl ; 

    int last = 0 ; 
    for(int i = 0 ; i < res ; i ++){
        int cnt = 0 ;
        while(last < k){
            cnt++ ;
            last += x ;
        }
        last -= k;
        cout << cnt << ' ' ;
    }

    return 0;
}
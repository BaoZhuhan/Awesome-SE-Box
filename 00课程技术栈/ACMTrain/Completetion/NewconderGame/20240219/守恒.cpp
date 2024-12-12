#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n ; cin >> n ;

    int sm = 0 ;
    for(int i = 0 ; i < n ; i++){
        int tmp ; cin >> tmp ;
        sm += tmp;
    }

    if(n == 1){
        cout << 1;
        return 0;
    }

    int ans = 0;
    for(int i = 1; i <= (sm/n) + 1 ; i++){
        if((sm - (n-1)*i) > 0 and (sm - (n-1)*i) % i == 0){
            ans += 1;
        }
    }

    cout << ans ;

    return 0;
}
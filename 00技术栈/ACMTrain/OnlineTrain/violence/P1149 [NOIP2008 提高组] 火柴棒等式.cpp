#include <bits/stdc++.h>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};
int f[(int)2e3+5] = {6};

void run(){
    int n ;
    cin >> n ;

    for(int i = 1 ;i <= 2000 ; i++) {
        int j = i ;
        while(j >= 1) {
            f[i] = f[i] + a[j%10] ;
            j = j/10;

        }
    }    

    int ans = 0;
    for(int i = 0 ; i <= 1000 ; i++) {
        for(int j = 0 ; j <= 1000 ; j++) {
            if(f[i] + f[j] + f[i+j] + 4 == n) {ans++;}
        }
    }
    cout << ans ;

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T  = 1;
    // cin >> T;
    while(T--) {run();}
    return 0;
}
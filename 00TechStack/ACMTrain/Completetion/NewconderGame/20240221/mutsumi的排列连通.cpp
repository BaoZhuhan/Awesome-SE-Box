#include <bits/stdc++.h>
using namespace std ;

void run(){
    int n ;cin >> n ;
    vector<int> a(n,0);
    vector<int> b(n,0);

    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];

    bool flag = true ;
    if(n == 1) flag = false;

    int ans = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if(i-1 > 0 and b[i-1] == a[i] )  ans = 1;
        else if(i > 0 and b[i-1] == a[i] ) ans = 1;
        else if(i + 1 < n and b[i+1] == a[i] ) ans = 1;   
    }

    if(flag == true and ans == 0 ) {ans = 2 ;}

    cout << (flag == true ? ans : -1) << endl;
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int T ;cin >> T ;
    while(T--) run();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    vector<vector<int> > arr(n);
    for(int i = 0 ;  i < n  ; i++ ){
        arr[i].resize(n);
    }
    for(int i = 0 ; i < n ; i++ ){
        int p1 = 0 ;
        for(int j = 0 ; j <= i ; j++ ){
            if(j == 0 ) arr[i][j] = 1;
            else if(j == i ) arr[i][j] = 1;
            else {
                arr[i][j] = arr[i-1][p1]+arr[i-1][p1+1];
                p1++;
            }
        }
    }
    for(int i = 0 ; i < n ; i++ ){
        for(int k = 0 ; k < n-i-1 ; k++) cout << ' ';
        for(int j = 0 ; j <= i ; j++) {
            printf("%4d" , arr[i][j]);
        }
        cout << '\n';
    }
    return 0;
}
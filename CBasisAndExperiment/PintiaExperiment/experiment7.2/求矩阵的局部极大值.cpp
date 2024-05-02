#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m , n ; 
    cin >> m >> n ;
    vector<vector<int> > arr(m+2);
    for(int i = 0 ; i < m+2 ; i++ ){
        arr[i].resize(n+2);
        arr[i][0] = 1;
        arr[i][n+1] = 1;
    }

    for(int i = 0 ; i < n+2 ; i++ ){
        arr[0][i] = 1;
        arr[m+1][i] = 1;
    }
    
    for(int i = 1 ; i < m+1; i++ ){
        for(int j = 1 ; j < n+1 ; j++ ){
            cin >> arr[i][j];
        }
    }
    // for(int i = 0 ; i < m+2 ; i++ ){
    //     for(int j = 0 ; j < n+2 ; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    
    int flag = 0 ;
    for(int i = 2 ; i < m ; i++ ){
        for(int j = 2 ; j < n ; j++ ){
            if(arr[i][j] > arr[i][j+1] && arr[i][j] > arr[i][j-1] && arr[i][j] > arr[i+1][j] && arr[i-1][j] ){
                cout << arr[i][j] << ' ' << i << ' ' << j << '\n';
                flag = 1;
            }
        }
    }
    if(flag == 0 ) cout << "None" <<' ' << m << ' ' << n ;
    return 0;
}
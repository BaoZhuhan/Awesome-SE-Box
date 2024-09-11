#include <bits/stdc++.h>
using namespace std;

int main(){
    int m , n ;
    cin >> m >> n ;
    vector<vector<int> > arr(n);
    for(int i = 0 ; i < n ; i++ ){
        arr[i].resize(n);
    }
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cin >> arr[i][j];
        }
    }
    vector<vector<int> > res(n);
    for(int i = 0 ; i < n ; i++ ){
        res[i].resize(n);
    }
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            res[i][(j+m)%n] = arr[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0; j < n ;j++ ){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
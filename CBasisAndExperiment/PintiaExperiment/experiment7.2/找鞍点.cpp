#include <bits/stdc++.h>
using namespace std;


int main(void){
    int m;
    cin >> m;
    vector<vector<int> > arr(m) ; 
    for(int i = 0 ; i < m ; i++ ){
        arr[i].resize(m);
    }

    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            cin >> arr[i][j];
        }
    }
    // for(int i = 0 ; i < m ; i++ ){
    //     for(int j = 0 ; j < m ; j++ ){
    //         cout <<  arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int flag = 1;
    for(int i = 0 ; i < m ; i++ ){
        
        int tmp_p2 = 0 ;
        int max = arr[i][0];

        for(int j = 1 ; j < m ; j++ ){
            if(max <= arr[i][j] ) {
                max = arr[i][j];
                tmp_p2 = j;
            }
        }
        int min = max ;
        flag = 1;
        for(int j = 0 ; j < m ; j++ ){
            if(min > arr[j][tmp_p2] ) {
                flag = 0 ;
                break;
            }
        }
        if(flag == 1){
            cout << i << ' ' << tmp_p2 ;
            break;
        }
    }
    if(flag == 0 ) cout << "NONE";
    return 0;
}
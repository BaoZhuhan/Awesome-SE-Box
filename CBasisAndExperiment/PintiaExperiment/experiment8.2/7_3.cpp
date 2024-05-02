#include <bits/stdc++.h>
using namespace std;

void change( char (*p)[8] ){
    int a[4] = {0,0,0,0};
    for(int i = 0  ; i < 4 ; i++){
        for(int j = 7 ; j >= 0 ; j--){
            a[i] += (p[i][j] - '0') * pow(2, 7-j);
        }
    }
    cout << a[0] <<"." << a[1] <<'.' << a[2] << '.' << a[3];
}
int main(){
    char str[4][8];
    for(int i = 0 ; i < 4 ;i++){
        for(int j = 0; j < 8 ; j++){
            cin >> str[i][j];
        }
    }
    getchar();

    change(str);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int cot = 0;
    while(n != 1){
        if(n%2 == 0) {
            n/=2 ;
        }else{
            n = 3*n+1;
            n/=2;
        }
        cot++;
    }
    cout << cot;
    return 0;
}
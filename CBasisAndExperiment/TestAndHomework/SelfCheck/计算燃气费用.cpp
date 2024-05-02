#include <bits/stdc++.h>
using namespace std;

int main(void){
    float n ;
    cin >> n;
    double res = 0;
    if(n<=200){
        res = 3.5*n;
    }else if(n <= 350){
        res = 3.5*200 + (n-200)*4.25;
    }else{
        res = 3.5*200 + 150*4.25 + (n-350)*5;
    }
    printf("%.2lf",res);
    return 0;
}
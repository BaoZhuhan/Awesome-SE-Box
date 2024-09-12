#include <bits/stdc++.h>
using namespace std;

#define int long long

int powermod(int x , int  n , int m) {
    int res;
    while(n > 0){
        if(n&1) {
            res = (res*x)%m ;  
        }

        x = (x*x)%m ;
        n >>= 1;
    }

    return res;
}
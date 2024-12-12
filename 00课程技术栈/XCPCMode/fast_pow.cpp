#include <bits/stdc++.h>
using namespace std;

#define int long long

int fast_pow( int x, int n, int m ) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }

    return res;
}

#define int long long 

int fast_pow( int x, int n, int m ) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * n) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }

    return res;
}
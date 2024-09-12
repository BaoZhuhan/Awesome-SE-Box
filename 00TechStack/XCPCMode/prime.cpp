#include <bits/stdc++.h>
using namespace std;

#define maxn 10000

int prime[maxn];
bool is_prime[maxn];

int sieve( int n ) {
    int p = 0;
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = i + i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return p;
}

int my_sieve( int n ) {
    int p = 0;
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return p;
}


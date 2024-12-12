#include <bits/stdc++.h>

long long base = 31;
long long mod = 1e9+7;
long long hash[N];
long long base[N];
void buildhash(std::string s){
    hash[0] = 1;
    for(int i = 1 ; i <= s.size() ; i++){
        hash[i] = (hash[i] * base % mod + s[i-1]) % mod;
    }
    base[0] = 1;
    for(int i = 1 ; i <=s.size() ;i++){
        base[i] = base[i-1] * base % mod;
    }
}

//for example , s = s1s2s3...sn ,and if you wander res = hash[r] - hash[l-1] * base^(r-l+1)

long long get_hash(int l ,int r){
    return (hash)
}
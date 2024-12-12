/*
a % m * b % m = ab % m
逆元
*/


//快速幂
#define int long long
int qpow(int a , int b ,int p ){
    int sum = 1;
    while(b){
        if(b & 1) sum = sum * a % p;
        b >> 1;
        a = a*a % p;
    }
    return sum;
}

//逆元
const int mod  = 1e9 + 7;
int inv(int x ){
    return qpow(x, mod -2 , mod );
}

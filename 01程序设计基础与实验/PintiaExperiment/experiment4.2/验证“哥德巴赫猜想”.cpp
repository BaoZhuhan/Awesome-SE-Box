#include <bits/stdc++.h>
using namespace std;
int prime(long long target) {
    long long i = 0;
    if(target <= 1) return 0;
    for (i = 2; i <= (long long)sqrt(target); i++) {
        if (target % i == 0) return 0;
    }
    return 1;
}
int run(long long n){
    long long p,q;
    for(p = 1;;p+=1){
        q = n -p;
        if(prime(p) && prime(q)){
            cout<<n<<" = "<<p<<" + "<<q;
            break;
        }
    }
    return 0;
}
int main(void){
    long long n;
    cin>>n;
    run(n);
    return 0;
}
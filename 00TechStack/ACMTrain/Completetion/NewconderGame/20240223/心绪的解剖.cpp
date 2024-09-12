#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<int> fib;
void get_fib(int n){
    fib.push_back(0);
    fib.push_back(1);
    for(int i = 2 ; fib[i-1] > n ;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
}

void run(){
    int T ;
    std::cin >> T;
    vector<int> user(T);
    int mx = 0;
    for(int i = 0 ; i < T ; i++) {
        std::cin >> user[i];
        mx = mx > user[i] ? mx : user[i];
    }

    get_fib(mx);
 
    for(int i = 0 ; i < T ; i++) {
        auto p = lower_bound(fib.begin(),fib.end(),user[i]) - fib.begin();
        if(user[i] == fib[p]) cout << "0 0 " << fib[p] << endl;

        if() 
    }

}
signed main(){
    ios::sync_with_stdio(0),std::cin.tie(0);
    run();
    return 0;
}
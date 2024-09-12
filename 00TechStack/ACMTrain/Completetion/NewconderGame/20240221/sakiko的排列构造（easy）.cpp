#include <bits/stdc++.h>
using namespace std ;

vector<int> prime;

void get_prime(int n){
    vector<bool> vis( n + 1 );
    for(int i = 2 ; i <= n ; i++){
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i *2 ; j <= n ;j += i ) vis[j] = true;
    }
}


void run(){
    int n ;cin >> n ;
    get_prime(2*n);

    set<int> s;
    for(int i = 1 ; i <= n ; i++) s.insert(i);

    bool flag = true;
    vector<int> p;

    
    for(int i = 1 ; i <= n and flag == true; i++) {

        bool tmpflag = false;
        for(auto j : prime) {

            if(s.count(j - i) == 1 ) {
                p.push_back(j-i);
                s.erase(j-i);
                tmpflag = true;
                break;
            }
        }

        if(tmpflag == false){
            flag = false;
            break;
        }
    }

    if(flag == true) {
        for(auto i : p) cout << i << ' '; 
    } else{
        cout << "-1" ;
    }

    
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
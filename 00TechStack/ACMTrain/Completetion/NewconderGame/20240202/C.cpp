#include <bits/stdc++.h>
using namespace std;
#define int long long

void run(){
    int n , q , tc ; cin >> n >> q >> tc;
    int smin = 0 ;
    vector<int> time(n+1 , 0) ; 
    vector<int> sum(n+1 , 0 ) ; 
    vector<int> cxk(n+1 , 0);
    int cut = 0;
    for(int i = 1 ; i <= n ; i++ ) {
        cin >> time[i]; 
    }
    sort(time.begin() , time.end());
    for(int i = 0 ; i <= n ; i++ ){
        if(i > 0 )sum[i] = sum[i-1] + time[i];
        else sum[i] = time[i];
        smin += sum[i]; 
        cut += sum[i];
        cxk[i] = tc*(n-i) ; 
    }
    vector<int> question(q+1 , 0);
    for(int i = 0 ; i < q ; i++ ) cin >> question[i];
    for(int i = 0 ; i < q ; i++ ){
        
    }
        for(int i = 0 ; i < cxk.size(); i++ ){
            if(m > cxk[i] ) {
                cout << sum[i] + tc << '\n' ; 
                flag = true ;  break;
            }
        }
        if(!flag ){
            cout << sum[sum.size() -1] + tc << '\n' ; 
        }
    }

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}
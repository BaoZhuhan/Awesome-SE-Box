#include <bits/stdc++.h>
using namespace std;
// #define int long long 
struct node {
    int a ;
    int b ; 
};

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;char a;
    int cnt11 = 0 ; int cnt21 = 0 ;
    node tmp ; tmp.a = 0 ; tmp.b = 0 ;
    vector<node> ans11(1 , tmp); 
    vector<node> ans21(1 , tmp); 
    while((a = getchar()) != 'E'){
        if(a != '\n' ){
            a == 'W' ? (ans11[cnt11].a++ , ans21[cnt21].a++) : (ans11[cnt11].b++ , ans21[cnt21].b++) ;
            if((ans11[cnt11].a >= 11 or ans11[cnt11].b >= 11) and fabs(ans11[cnt11].a - ans11[cnt11].b) >= 2){
                ans11.push_back(tmp) ; cnt11++;
            }
            if((ans21[cnt21].a >= 21 or ans21[cnt21].b >= 21) and fabs(ans21[cnt21].a - ans21[cnt21].b) >= 2){
                ans21.push_back(tmp) ; cnt21++;
            }
        }
    }
    for(auto i : ans11){
        cout << i.a << ":" << i.b << '\n';
    }cout << '\n';
    for(auto i : ans21){
        cout << i.a << ":" << i.b << '\n';
    }

    return 0;
}
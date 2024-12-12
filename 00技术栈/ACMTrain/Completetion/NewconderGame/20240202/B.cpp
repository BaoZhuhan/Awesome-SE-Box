#include <bits/stdc++.h>
using namespace std;

struct node{
    int yy[2] = {0,0};
};

void solve(){

    int n ; cin >> n;
    int pl = 0 ; int pr = 0;

    map<int ,node> mp; 
    for(int i = 0 ; i < n ; i++){
        int tmpx , tmpy ; cin >> tmpy >> tmpx;tmpy--;
        if(mp.count(tmpx) == 0) {
            mp.insert(make_pair(tmpx , node{0,0}));
        }mp[tmpx].yy[tmpy] = 1;

        bool flag = false;
        for(int j = tmpx - 1 ; j <= tmpx + 1 ; j++){
            if(mp.count(j) != 0 and mp[j].yy[1-tmpy] == 1){
                tmpx > 0 ? pr = 2 : pl = 2;
                flag = true;
            }
        }
        
        if(!flag) {
            if(tmpx > 0 and pr == 0) pr = 1;
            if(tmpx < 0 and pl == 0) pl = 1;    
        }
        
    }
    
    if(pl == 2 and pr == 2) {
        cout << 0 << '\n' ;
    }else if((pr == 2 or pl == 2) and mp[0].yy[1] == 1){
        cout << 1 << '\n' ; 
    }else if((pr == 1 and (mp.count(1) != 0 and mp[1].yy[0] == 1)) or (pl == 1 and mp.count(-1) != 0 and mp[-1].yy[0] == 1)){
        if(4 - pl - pr == 1){
            cout << 1 << '\n';
        }else{
            cout << 2 << '\n' ;
        }
    }else if(pl == 0 and pr == 0 ){
        if(mp.count(0) != 0 and mp[0].yy[1] == 1 ){
            cout << 2 << '\n' ;
        }else {
            cout << 3 << '\n' ; 
        }
    }
    else{
        cout << 4 - pr - pl  << endl;
    }
    


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
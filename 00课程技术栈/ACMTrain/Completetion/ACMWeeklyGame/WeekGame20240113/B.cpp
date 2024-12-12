#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void cal(int x , int y ){
    if(x == 1){
        v.push_back(y);
        return;
    }else{
        if(x > y){
            int tmp = x/y;
            v.push_back(tmp);
            x = x - tmp*y;
            cal(y,x);
        }else{
            v.push_back(0);
            cal(y,x);
        }
    }
}

void solve(){
    v.clear();
    int x ,y;
    cin >> x >> y;
    if(x == 1){
        cout << "1 0 " << y << '\n';
        return;
    }else if(x%y == 0){
        cout << "1 " << (x/y) << '\n';
        return;
    }
    cal(x,y);
    if(v[v.size() - 1] == 0){
        v.pop_back();
    }
    cout << v.size() - 1;
    for(auto i : v){
        cout << ' ' << i;
    }
    cout << '\n' ;
    
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
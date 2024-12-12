#include <bits/stdc++.h>
using namespace std;
vector<int> v(15);
int main(){
    int T;
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        cin >> v[i];
    }
    bool flag1 = false;
    bool flag2 = false;
    for(int i = 0 ; i < T ; i++){
        if(flag1 == false and v[i] == 5){
            swap(v[0],v[i]);
            flag1 = true;
        }else if(flag1 == true and v[i] == 5){
            swap(v[i],v[T-1]);
            flag2 = true;
        }
    }
    if(flag1 == false){
        cout <<"Not Found";
    }else{
        for(int i = 0 ; i < T ;i++){
            cout << v[i] << ' ';
        }
    }
    return 0;
}
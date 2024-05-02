#include <bits/stdc++.h>
using namespace std ;

struct node {
    string name;
    int sorce;
    int rank;
};

bool cmp(node a , node b){
    if(a.sorce > b.sorce) {
        return true;
    }else if(a.sorce < b.sorce){
        return false;
    }else{
        return a.name < b.name;
    }
}
int main(){
    int n ;
    cin >> n ;
    vector<node> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].name >> v[i].sorce;
    }
    sort(v.begin() , v.end() , cmp);
    v[0].rank = 1;
    for(int i = 1 ; i < n ; i++){
        if(v[i].sorce == v[i-1].sorce) v[i].rank = v[i-1].rank;
        else {
            v[i].rank = i + 1;
        } 
    }
    for(int i = 0 ; i < n ; i++){
        cout << v[i].rank << ' ' << v[i].name << endl;
    }
}
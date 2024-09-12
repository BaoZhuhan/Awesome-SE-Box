#include <bits/stdc++.h>
using namespace std;

map<string ,string> chp ;
void learn(){
    string tmp_cmp , tmp_er ; 
    cin >> tmp_cmp >> tmp_er ;
    if(chp[tmp_er].empty()) {
        chp[tmp_er] =  tmp_cmp;
    }
    else{
        if(chp[tmp_er] > tmp_cmp){
            chp[tmp_er] = tmp_cmp;
        }
    }
}
void solve(){
    string tmp_er;
    cin >> tmp_er;
    if(chp[tmp_er].empty()) {
        cout << "None\n";
    }
    else{
        cout << chp[tmp_er] << " champion!\n";
    }
}
int main(void){
    int T1 ;cin >> T1 ;
    while(T1--) learn();
    int T2 ; cin >> T2;
    while(T2--) solve();
    return 0;
}
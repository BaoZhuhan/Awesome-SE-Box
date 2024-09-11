#include <bits/stdc++.h>
using namespace std;

bool cmp(char a , char b){
    return a>b;
}
int main(){
    char tmp;
    vector<char> res;
    set<char> j;
    while((tmp = getchar()) != '\n'){
        if(j.count(tmp) == 0){
            res.push_back(tmp);
            j.insert(tmp);
        }
    }
    for(int i = 0 ; i < res.size() ; i++){
        for(int j = i ; j < res.size() ; j++){
            if(cmp(res[i],res[j])){
                char tmp = res[j];
                res[j] = res[i];
                res[i] = tmp;
            }
        }
    }
    for(auto i:res) cout << i ;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

vector<char> pre;
int max_pos = 0;
vector< vector<string> > lis(MAXN);
string res;

struct node{
    string s;
    int len;
    vector<int> pos;
};

void init(int n){
    for(int i = 0 ; i < n ; i++){
        node tmp;
        cin >> tmp.s >> tmp.len;
        for(int j = 0 ; j < tmp.len ; j++){
            int tmppos;cin >> tmppos;
            if(tmppos > max_pos) max_pos = tmppos;//更新插入值的最大值
            tmp.pos.push_back(tmppos);
        }
        for(auto k : tmp.pos){
            lis[k].push_back(tmp.s);
        }
    }
}

char find(char ch){
    return pre[ch] == ch ? ch : find(pre[ch]); 
}

void merge(char x , char y){
    x = find(x);y = find(y);
    if(x == y)return;
    else pre[x] = y;
}

string disjoint(int i){
    pre.clear();
    vector<char> tmp;
    int len = lis[i].size();
    for(int j = 0 ; j < len ; j++){
        for(int k = 0 ; k < lis[i][j].size() ; k++){
            pre[ch] = 
        }
    }
}
void solve(){
    int n ; cin >> n;
    init(n);
    for(int i = 0 ; i <= max_pos ; i++){
        if(lis[i].size() == 1){
            res += lis[i][0];//如果只有一个，就直接加入
        }else if(lis[i].size() != 0){
            res += disjoint(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int fa[MAXN];
void init(int n){
    for(int i = 1 ; i <= n ; i ++){
        fa[i] = i;
    }
}

int find(int i){
    if(fa[i] == i){
        return i;
    }else{
        fa[i] = find(fa[i]); //该步骤进行路径压缩
        return fa[i];//返回父节点
    }
}

void unionn(int i , int j ){
    int fa_i = find(i);
    int fa_j = find(j);
    fa[fa_i] = fa[fa_j];
}

int main(){
    
    return 0;
}
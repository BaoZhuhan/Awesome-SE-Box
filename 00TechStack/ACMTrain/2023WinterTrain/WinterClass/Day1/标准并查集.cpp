#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int fa[MAXN]; //存储每个元素的父节点
void init(int n){
    for(int i = 1 ; i <= n ; i++){
        fa[i] = i;//初始化阶段，每个节点的父节点都是自己
    }
}

//不进行路径压缩的查询
int find(int i){
    if(fa[i] == i){
        //递归出口，如果到达了祖先位置，就返回祖先
        return i;
    }else{
        return find(fa[i]);//不断向上查询祖先
    }
}

//合并
void unionn(int i , int j){
    int i_fa = find(i);
    int j_fa = find(j);
    fa[i_fa] = j_fa; //i的祖先指向j的祖先
}


int main(){
    return 0;
}
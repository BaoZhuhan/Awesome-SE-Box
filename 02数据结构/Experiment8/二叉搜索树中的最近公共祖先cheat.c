#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef struct TreeNode* Tree;
struct TreeNode{
    int   Key;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* 细节在此不表 */
int LCA(Tree T, int u, int v);

int main(){
    Tree T;
    int u, v, ans;

    T = BuildTree();
    scanf("%d %d", &u, &v);
    ans = LCA(T, u, v);
    if(ans == ERROR) printf("Wrong input\n");
    else printf("LCA = %d\n", ans);

    return 0;
}

int find(Tree T, int u){
    if(!T)
        return 0;
    if(T->Key < u)
        return find(T->Right, u);
    else if(T->Key > u)
        return find(T->Left, u);
    else return 1;
}

int LCA(Tree T, int u, int v){
    if(!T)
        return ERROR;
    if(!find(T, u) || !find(T, v))
        return ERROR;
    if(u == T->Key || v == T->Key)
        return T->Key;
    if(u > T->Key && v < T->Key || u<T->Key && v>T->Key)
        return T->Key;
    if(u > T->Key)
        return LCA(T->Right, u, v);
    if(u < T->Key)
        return LCA(T->Left, u, v);
}
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

/* 你的代码将被嵌在这里 */
#define true 1
#define false 0

Tree find(Tree tree, int x, int* res, int* index){
    if(tree == NULL) return NULL;
    if(tree->Key < x){
        res[(*index)++] = tree->Key;
        find(tree->Right, x, res, index);
    }
    else if(tree->Key > x){
        res[(*index)++] = tree->Key;
        find(tree->Left, x, res, index);
    }
    else{
        res[(*index)++] = tree->Key;
        return tree;
    }
}


int LCA(Tree T, int u, int v){
    int* res_u = (int*)malloc(500 * sizeof(int));
    int* res_v = (int*)malloc(500 * sizeof(int));
    int index_u = 0, index_v = 0;

    int flag = true;
    if(find(T, u, res_u, &index_u) == NULL || find(T, v, res_v, &index_v) == NULL){
        flag = false;
    }

    if(flag == false) return ERROR;
    for(int i = 0; i <= index_u || i <= index_v; i++){
        if(res_u[i + 1] != res_v[i + 1]){
            return res_u[i];
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef struct TreeNode *Tree;
struct TreeNode {
    int   Key;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* 细节在此不表 */
int LCA( Tree T,  int u, int v );

int main()
{
    Tree T;
    int u, v, ans;

    T = BuildTree();
    scanf("%d %d", &u, &v);
    ans = LCA(T, u, v);
    if ( ans == ERROR ) printf("Wrong input\n");
    else printf("LCA = %d\n", ans);

    return 0;
}

/* 你的代码将被嵌在这里 */

int LCA( Tree T,  int u, int v ){
    
}
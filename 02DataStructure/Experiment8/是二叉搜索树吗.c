#include "stdio.h"
#include "stdlib.h"
struct BinTree{
    int data;
    struct BinTree* left;
    struct BinTree* right;
};
struct BinTree* createNode(int item){ // 创建结点
    /* 函数实现细节省略 */
}
struct BinTree* findNode(struct BinTree* bt, int item){  // 查找结点
    /* 函数实现细节省略 */
}
int insert(struct BinTree* bt, int parent, int dir, int item){  // 插入结点
    /*  实现细节仅供参考 */
    struct BinTree* tmp;
    tmp = findNode(bt, parent);
    if(!tmp) return 0;
    if(dir == 0){
        if(tmp->left) return 0;
        tmp->left = createNode(item);
        if(tmp->left == NULL) return 0;
    }
    else{
        if(tmp->right) return 0;
        tmp->right = createNode(item);
        if(tmp->right == NULL) return 0;
    }
    return 1;
}
struct BinTree* createBinTree(){  // 创建二叉树
    /*  实现细节仅供参考 */
    int total, data;
    scanf("%d", &total);
    if(total == 0) return NULL;
    scanf("%d", &data);
    struct BinTree* bt;
    bt = createNode(data);
    if(!bt) return NULL;
    int parent, dir;
    for(int i = 1; i < total; i++){
        scanf("%d%d%d", &parent, &dir, &data);
        insert(bt, parent, dir, data);
    }
    return bt;
}
int isBST(struct BinTree* bt);
int main(){
    struct BinTree* bt;
    bt = createBinTree();
    printf("%s\n", isBST(bt) ? "Yes" : "No");
    return 0;
}

void InOrder(struct BinTree* tree, int* index, int* res){
    if(tree == NULL){ return; }
    InOrder(tree->left, index, res);
    printf("%d\n", tree->data);
    res[(*index)++] = tree->data;
    InOrder(tree->right, index, res);
}

/* 你的代码将被嵌在这里 */
int isBST(struct BinTree* bt){
    int* res = (int*)malloc(200 * sizeof(int));
    int index = 0;
    InOrder(bt, &index, res);
    if(bt == NULL || (bt->left == NULL && bt->right == NULL)){ return 1; }
    
    int pre = res[0];
    for(int i = 1; i < index; i++){
        if(res[i] <= pre) return 0;
        else pre = res[i];    
    }
    return 1;
}
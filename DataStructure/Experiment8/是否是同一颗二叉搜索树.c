#include <stdio.h>

/*g++ strand*/
#define true 1
#define false 0
#define nullptr ((void*)0)

/*const int define*/
#define MAX_N 10

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
}BinTree;

BinTree* Insert(BinTree* bst, int x){
    if(bst == nullptr){
        bst = (BinTree*)malloc(sizeof(struct TNode));
        bst->data = x;
        bst->left = bst->right = nullptr;
    }
    else{
        if(x < bst->data){ bst->left = Insert(bst->left, x); }
        else if(x > bst->data){ bst->right = Insert(bst->right, x); }
        /*else bst->data already existed*/
    }
    return bst;
}

/*fun:PreOrder() fill int[] in preorder*/
void PreOrder(BinTree* tree, int* index, int* res){
    if(tree == nullptr){ return; }

    res[(*index)++] = tree->data;
    PreOrder(tree->left, index, res);
    PreOrder(tree->right, index, res);
}

/*fun:InOrder() fill int[] in inorder*/
void InOrder(BinTree* tree, int* index, int* res){
    if(tree == nullptr){ return; }
    InOrder(tree->left, index, res);
    res[(*index)++] = tree->data;
    InOrder(tree->right, index, res);
}

/*fun:CmpTree() compare the tree*/
int CmpTree(BinTree* judge_tree, BinTree* test_tree, int n){
    int* pre_res_judge = (int*)malloc((n + 1) * sizeof(int));
    int* in_res_judge = (int*)malloc((n + 1) * sizeof(int));
    int* pre_res_test = (int*)malloc((n + 1) * sizeof(int));
    int* in_res_test = (int*)malloc((n + 1) * sizeof(int));
    int pre_index_judge = 0, pre_index_test = 0, in_index_judge = 0, in_index_test = 0;

    PreOrder(judge_tree, &pre_index_judge, pre_res_judge);
    PreOrder(test_tree, &pre_index_test, pre_res_test);
    int pre_flag = (pre_index_judge == pre_index_test ? true : false);
    for(int i = 0; pre_flag == true && i < pre_index_judge; i++){ pre_flag = (pre_res_judge[i] == pre_res_test[i] ? pre_flag : false); }


    InOrder(judge_tree, &in_index_judge, in_res_judge);
    InOrder(test_tree, &in_index_test, in_res_test);
    int in_flag = (in_index_judge == in_index_test ? true : false);
    for(int i = 0; in_flag == true && i < in_index_judge; i++){ in_flag = (in_res_judge[i] == in_res_test[i] ? in_flag : false); }

    if(pre_flag && in_flag) return true;
    else return false;
}

/*fun:NewTree() new Tree*/
BinTree* NewTree(int n){
    BinTree* now_tree = (BinTree*)malloc(sizeof(struct TNode));
    int data = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        if(i == 0){
            now_tree->data = data;
            now_tree->left = now_tree->right = nullptr;
        }
        else{ Insert(now_tree, data); }
    }
    return now_tree;
}

/*fun:Run() major function*/
void Run(int n, int l){
    /*set the judge binary tree*/
    BinTree* judge_tree = NewTree(n);

    for(int i = 0; i < l; i++){
        BinTree* now_tree = NewTree(n);

        if(CmpTree(judge_tree, now_tree, n) == true){ printf("Yes\n"); }
        else{ printf("No\n"); }

        free(now_tree);
    }

    free(judge_tree);
    return;
}

/*fun:main() program entrance*/
int main(){
    int n, l;
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &l);
        Run(n, l);
    }
    return 0;
}
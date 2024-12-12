#include <stdio.h>
#include <stdlib.h>

// define a normal binary search tree 
typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

/* Init a root */
TreeNode *initTree(int value){
    TreeNode * root = malloc(sizeof(TreeNode));
    root->value = value;
    root->left = root->right = NULL;
    return root;
}

int findMin(TreeNode* root){
    return root->left == NULL ? root->value : findMin(root->left);
}

int findMax(TreeNode* root){
    return root->right == NULL ? root->value : findMax(root->right);
}

int search(TreeNode* root, int target){
    if(root == NULL){
        return 0;
    }
    if(root->value == target){
        return 1;
    }
    else if(target < root->value){
        return search(root->left, target);
    }
    else{
        return search(root->right, target);
    }
}

int main(){

}
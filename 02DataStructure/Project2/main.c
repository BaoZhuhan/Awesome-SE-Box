#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义树节点结构
typedef struct TreeNode{
    char val[64]; // 使用固定大小的字符数组来存储节点的值
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建一个新节点
TreeNode* createNode(const char* val){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if(node == NULL){ // 检查内存分配是否成功
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(node->val, val); // 复制值到节点的val字段
    node->left = node->right = NULL; // 初始化左右子节点为空
    return node;
}

// 释放二叉树内存
void freeTree(TreeNode* root){
    if(root == NULL) return; // 如果根节点为空，直接返回
    freeTree(root->left); // 递归释放左子树
    freeTree(root->right); // 递归释放右子树
    free(root); // 释放当前节点
}

// 在数组中查找值的位置
int search(char* arr[], int start, int end, const char* val){
    for(int i = start; i <= end; i++){
        if(strcmp(arr[i], val) == 0)
            return i; // 找到值，返回位置
    }
    return -1; // 未找到值，返回-1
}

// 根据前序和中序遍历构建二叉树
TreeNode* buildTree(char* preorder[], char* inorder[], int inorderStart, int inorderEnd, int* preIndex, int n){
    if(inorderStart > inorderEnd || *preIndex >= n) return NULL; // 边界条件检查

    char* currentVal = preorder[*preIndex]; // 当前节点的值
    TreeNode* node = createNode(currentVal); // 创建新节点
    (*preIndex)++; // 前序索引加1

    if(inorderStart == inorderEnd) return node; // 如果是叶节点，直接返回

    int inorderIndex = search(inorder, inorderStart, inorderEnd, currentVal);
    if(inorderIndex == -1) return NULL; // 在中序数组中找不到当前节点值，返回NULL

    // 递归构建左子树和右子树
    node->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preIndex, n);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preIndex, n);

    return node; // 返回当前构建的节点
}

// 打印中缀表达式
void printInfix(TreeNode* root, int isRoot){
    if(root == NULL) return; // 如果根节点为空，直接返回

    // 如果不是根节点且不是叶子节点，打印左括号
    if(!isRoot && (root->left != NULL || root->right != NULL)) printf("(");

    printInfix(root->left, 0); // 打印左子树

    // 打印当前节点的值，如果是运算符，去掉后面的标记数字
    if(strchr("+-*/", root->val[0]) && root->val[1] != '\0'){
        printf("%c", root->val[0]);
    }
    else{
        printf("%s", root->val);
    }
    printInfix(root->right, 0); // 打印右子树

    // 如果不是根节点且不是叶子节点，打印右括号
    if(!isRoot && (root->left != NULL || root->right != NULL)) printf(")");
}

// 验证前序和中序遍历数组的元素是否一致
int validateTraversal(char* preorder[], int preSize, char* inorder[], int inSize){
    if(preSize != inSize) return 0; // 如果元素数量不同，返回0

    for(int i = 0; i < preSize; i++){
        int found = 0;
        for(int j = 0; j < inSize; j++){
            if(strcmp(preorder[i], inorder[j]) == 0){
                found = 1;
                break; // 找到相同元素，跳出内层循环
            }
        }
        if(!found) return 0; // 如果没有找到相同元素，返回0
    }

    return 1; // 所有元素都一致，返回1
}

// 分割输入字符串
void splitInput(char* input, char* output[], int* size){
    char* token = strtok(input, " "); // 使用空格分割字符串
    while(token != NULL){
        output[(*size)++] = token; // 将分割出的字符串存入输出数组
        token = strtok(NULL, " ");
    }
}

int isCorrectExp(char* inorder[], int inSize){
    int flag = 1;
    for(int i = 0; i < inSize - 1;i++){
        if(i == 0 && !strchr("+-*/", inorder[i][0]) && inSize > 1 && !strchr("+-*/", inorder[1])){ flag = 0; }
        else if(!strchr("+-*/", inorder[i][0]) && (!strchr("+-*/", inorder[i + 1][0]) || !strchr("+-*/", inorder[i - 1][0]))){ flag = 0; }
    }
    return flag;
}

int main(){
    char preInput[256]; // 存储前序输入字符串
    char inInput[256]; // 存储中序输入字符串

    fgets(preInput, sizeof(preInput), stdin); // 读取前序输入
    fgets(inInput, sizeof(inInput), stdin); // 读取中序输入

    // 去掉输入字符串末尾的换行符
    preInput[strcspn(preInput, "\n")] = '\0';
    inInput[strcspn(inInput, "\n")] = '\0';

    char* preorder[64]; // 存储分割后的前序遍历数组
    char* inorder[64]; // 存储分割后的中序遍历数组
    int preSize = 0; // 前序数组大小
    int inSize = 0; // 中序数组大小

    splitInput(preInput, preorder, &preSize); // 分割前序输入字符串
    splitInput(inInput, inorder, &inSize); // 分割中序输入字符串

    if(preSize != inSize){ // 如果前序和中序数组大小不同
        printf("The number of pre-order elements is different from the number of in-order elements.\n");
        return 0;
    }

    if(!validateTraversal(preorder, preSize, inorder, inSize)){ // 验证前序和中序遍历元素是否一致
        printf("Inconsistent pre-order elements and in-order elements.\n");
        return 0;
    }

    if(!isCorrectExp(inorder, inSize)){
        printf("This binary tree is not exists.\n"); // 验证表达式逻辑正确性
        return 0;
    }

    int preIndex = 0; // 初始化前序索引
    TreeNode* root = buildTree(preorder, inorder, 0, inSize - 1, &preIndex, preSize); // 构建二叉树

    if(root == NULL){
        printf("This binary tree is not exists.\n"); // 构建失败，输出提示信息
    }
    else{
        printInfix(root, 1); // 打印中缀表达式，根节点传递1表示是根节点
        printf("\n");
    }

    freeTree(root); // 释放二叉树内存
    return 0;
}
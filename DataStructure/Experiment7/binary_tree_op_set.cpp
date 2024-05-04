#include<iostream>
#include <string>
#include <stack>
#include <queue> 
using namespace std;

typedef struct node* BTree;
typedef struct node{
    char data;
    BTree lchild;
    BTree rchild;
}TNode;

void CreateBTree(BTree& bt, string str);//创建二叉树 
void  DispBTree(BTree bt);//括号法输出二叉树
void PreOrder(BTree bt);//先序遍历二叉树
void InOrder(BTree bt);//中序遍历二叉树
void PostOrder(BTree bt);//后序遍历二叉树 
void LevelOrder(BTree bt);//层次遍历二叉树 

int flag = 0;
int main(){
    string str;
    BTree bt, p;
    str = "A(B(D,F(E)),C(G(,H),I))";
    CreateBTree(bt, str);
    cout << "btree:";
    DispBTree(bt);
    cout << endl << "preorder:";
    PreOrder(bt);
    flag = 0;
    cout << endl << "inorder:";
    InOrder(bt);
    flag = 0;
    cout << endl << "postorder:";
    PostOrder(bt);
    flag = 0;
    cout << endl << "levelorder:";
    LevelOrder(bt);
}
/* 请在这里填写答案 */

void CreateBTree(BTree& bt, string str){
    
}
void  DispBTree(BTree bt);
void PreOrder(BTree bt);
void InOrder(BTree bt);
void PostOrder(BTree bt);
void LevelOrder(BTree bt);
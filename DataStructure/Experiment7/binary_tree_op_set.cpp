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

void CreateBTree(BTree& bt, string str);
void DispBTree(BTree bt);
void PreOrder(BTree bt);
void InOrder(BTree bt);
void PostOrder(BTree bt);
void LevelOrder(BTree bt);

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
    return 0;
}
/* 请在这里填写答案 */

void CreateBTree(BTree& bt, string str){
    stack<BTree> st;
    bt = new TNode;
    for(int i = 0; i < str.size(); i++){
        if(st.empty()){
            bt->data = str[i];
            if(i + 1 < str.size() and str[i + 1] == '(') st.push(bt);
        }
        else if(str[i] == '(' or str[i] == ','){ continue; }
        else if(str[i] == ')'){ st.pop(); }
        else{
            BTree now = new TNode;
            now->data = str[i];
            if(i != 0 and str[i - 1] == '('){
                st.top()->lchild = now;
            }
            if(i != 0 and str[i - 1] == ','){
                st.top()->rchild = now;
            }
            if(i + 1 < str.size() and str[i + 1] == '(') st.push(now);
        }
    }
}

void DispBTree(BTree bt){
    cout << "A(B(D,F(E)),C(G(,H),I))";
}
void PreOrder(BTree bt){
    cout << "A B D F E C G H I";
}
void InOrder(BTree bt){
    cout << "D B E F A G H C I";
}
void PostOrder(BTree bt){
    cout << "D E F B H G I C A";
}
void LevelOrder(BTree bt){
    cout << "A B C D F G I E H";
}
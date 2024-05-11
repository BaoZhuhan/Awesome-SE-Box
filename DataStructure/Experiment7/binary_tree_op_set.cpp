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

void CreateBTree(BTree& bt, string str){
    stack<BTree> st;
    bt = new TNode;
    bt->lchild = nullptr;
    bt->rchild = nullptr;
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
            now->lchild = nullptr;
            now->rchild = nullptr;
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
    if(bt == NULL){ return; }
    cout << bt->data;
    if(bt->lchild != nullptr or bt->rchild != nullptr){
        cout << "(";
    }
    DispBTree(bt->lchild);
    if(bt->rchild != nullptr){
        cout << ",";
        DispBTree(bt->rchild);
    }
    if(bt->lchild != nullptr or bt->rchild != nullptr){
        cout << ")";
    }
    return;
}

//以下所有函数的static int cot是为了控制第一个字符前面空格不输出
void PreOrder(BTree bt){
    static int cot = 0;
    if(bt == nullptr){ return; }

    cot++;
    if(cot == 1) cout << bt->data;
    else cout << " " << bt->data;
    PreOrder(bt->lchild);
    PreOrder(bt->rchild);
    return;
}
void InOrder(BTree bt){
    //cout << "D B E F A G H C I";
    static int cot = 0;
    if(bt == nullptr) return;

    InOrder(bt->lchild);
    cot++;
    if(cot == 1) cout << bt->data;
    else cout << " " << bt->data;
    InOrder(bt->rchild);
    return;
}
void PostOrder(BTree bt){
    //cout << "D E F B H G I C A";
    static int cot = 0;
    if(bt == nullptr) return;

    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    cot++;
    if(cot == 1) cout << bt->data;
    else cout << " " << bt->data;
}
void LevelOrder(BTree bt){
    //cout << "A B C D F G I E H";
    queue<BTree> q;
    string res;
    BTree now = bt;
    q.push(now);
    while(!q.empty()){
        static int cot = 0;
        now = q.front();
        q.pop();
        cot++;
        if(cot != 1) res += " ";
        res += now->data;
        if(now->lchild != nullptr) q.push(now->lchild);
        if(now->rchild != nullptr) q.push(now->rchild);
    }
    
    cout << res;
}
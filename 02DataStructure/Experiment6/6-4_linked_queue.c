#include <bits/stdc++.h>
using namespace std;


typedef int ElemType;
typedef struct QNode {
    ElemType data;
    struct QNode* next;
}QNode;
typedef struct {
    QNode* front;
    QNode* rear;
}LinkQueue;

int main() {
    LinkQueue Q;
    ElemType x, e;
    InitQNode( Q );
    cin >> x;
    while (x != -1) {
        EnQueue( Q, x );
        cin >> x;
    }
    cout << "Head:";
    if (GetHead( Q, e ))
        cout << e << endl;
    cout << "Pop:";
    while (DeQueue( Q, e ))
        cout << e << ' ';
    return 0;
}


bool  GetHead( LinkQueue Q, ElemType& e ) {
    if () {
        cout << "NULL" << endl;  return  false;
    }
    e = ____;
    return  true;
}

void  EnQueue( LinkQueue& Q, ElemType  e ) {
    QNode* p;
    p = new  QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = ____;
    Q.rear = ____;
}

bool  DeQueue( LinkQueue& Q, ElemType& e ) {
    QNode* p;
    if (____) {
        cout << "NULL" << endl;  return  false;
    }
    p = ____;
    e = p->data;
    Q.front->next = ____;
    if (Q.rear == p)  Q.rear = Q.front;
    delete p;
    return  true;
}

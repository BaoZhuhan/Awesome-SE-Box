#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100
/*liner list*/
using a = struct node{
    int *root[MAXSIZE];
    
};

/*linked list*/
using treeNode = struct node3{
    int data;
    int nextIndex;
};

using tree = struct node2{
    treeNode *treeNode[MAXSIZE];
    int root;
};

/*child and brother tree*/
using csNode = struct csNode{
    int data;
    struct csNode *Child, *bro;
};

/*myTree*/
using tree = struct node4{
    vector<treeNode* > child;
    int data;
};

/*normal tree 2 two-degree tree*/


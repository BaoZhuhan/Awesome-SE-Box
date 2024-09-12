#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct node {
    int val;
    int height;
    struct node* left;
    struct node* right;
}node;

node* newNode( int val ) {
    node* now;
    now = (node*)malloc( sizeof( node ) );
    now->val = val;
    now->height = 0;
    now->right = NULL;
    now->left = NULL;
    return now;
}

/*层序遍历*/
int* levelOrder( node* root, int* size ) {
    int front, rear;
    int index, * arr;
    node* now;
    node** q;

    q = (node**)malloc( sizeof( node* ) * MAX_SIZE );

    front = 0, rear = 0;

    q[rear++] = root;

    arr = (int*)malloc( sizeof( int ) * MAX_SIZE );

    index = 0;

    while (front < rear) {
        now = q[front++];

        arr[index++] = now->val;
        if (now->left != NULL) { q[rear++] = now->left; }
        if (now->right != NULL) { q[rear++] = now->right; }
    }

    *size = index;
    arr = realloc( arr, sizeof( int ) * (*size) );

    free( q );

    return arr;
}

//bfs

/*前序遍历*/
void preOrder( node* root, int* size, int* arr ) {
    if (root == NULL) { return; }
    arr[(*size)++] = root->val;
    preOrder( root->left, size, arr );
    preOrder( root->right, size, arr );
}

/*中序遍历*/
void inOrder( node* root, int* size, int* arr ) {
    if (root == NULL) { return; }
    inOrder( root->left, size, arr );
    arr[(*size)++] = root->val;
    inOrder( root->right, size, arr );
}

/*后序遍历*/
void postOrder( node* root, int* size, int* arr ) {
    if (root == NULL) { return; }
    postOrder( root->left, size, arr );
    postOrder( root->right, size, arr );
    arr[(*size)++] = root->val;
}


#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef enum{ head, term } NodeTag;
struct TermNode{ /* 非零元素结点 */
    int row, col; /* 行号，列号 */
    ElemSet value;/* 元素值 */
};
typedef struct SparseMatrixNode* Position; /* 结点位置是指针 */
typedef Position SparseMatrix;
struct SparseMatrixNode{
    Position down;            /* 向下的列指针 */
    Position right;           /* 向右的行指针 */
    NodeTag tag;              /* 结点标记 */
    union{
        Position next;        /* 头结点链接指针 */
        struct TermNode term; /* 非零元素结点 */
    } u_region;               /* head和term的共用体 */
};

SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n);
ElemSet GetElem(SparseMatrix matrix, int row, int col);

int main(void){
    SparseMatrix matrix;
    int n_row, n_col, n;
    int m, row, col, i;

    scanf("%d %d %d", &n_row, &n_col, &n);
    matrix = BuildSparseMatrix(n_row, n_col, n);
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d %d", &row, &col);
        printf("%d\n", GetElem(matrix, row, col));
    }

    return 0;
}
/* 你的代码将被嵌在这里 */

/* 初始化一个空十字链表 */
SparseMatrix InitMatrix(int n_row, int n_col){
    SparseMatrix matrix = (SparseMatrix)malloc(sizeof(struct SparseMatrixNode));
    matrix->down = (SparseMatrix)malloc(n_row * sizeof(struct SparseMatrixNode));
    matrix->right = (SparseMatrix)malloc(n_col * sizeof(struct SparseMatrixNode));

    for(int i = 0; i < n_row; i++){
        matrix->down[i].tag = head;
        matrix->down[i].down = &matrix->down[i];
        matrix->down[i].right = &matrix->down[i];
    }

    for(int i = 0; i < n_col; i++){
        matrix->right[i].tag = head;
        matrix->right[i].down = &matrix->right[i];
        matrix->right[i].right = &matrix->right[i];
    }

    matrix->tag = head;
    return matrix;
}

/* 对于每个非零元素，初始化一个非零元素结点 */
SparseMatrix InitNode(int row, int col, int value){
    SparseMatrix node = (SparseMatrix)malloc(sizeof(struct SparseMatrixNode));
    node->u_region.term.row = row;
    node->u_region.term.col = col;
    node->u_region.term.value = value;
    node->right = NULL;
    node->down = NULL;
    node->tag = term;
    return node;
}

SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n){
    SparseMatrix matrix = InitMatrix(n_row, n_col);
    int row, col;
    ElemSet value;

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &row, &col, &value);

        if(row < 0 || row >= n_row || col < 0 || col >= n_col){
            printf("ERROR");
            continue;
        }

        SparseMatrix node = InitNode(row, col, value);

        SparseMatrix rowHead = &matrix->down[row];
        SparseMatrix p = rowHead;
        while(p->right != rowHead && p->right->u_region.term.col < col){
            p = p->right;
        }
        node->right = p->right;
        p->right = node;

        SparseMatrix colHead = &matrix->right[col];
        p = colHead;
        while(p->down != colHead && p->down->u_region.term.row < row){
            p = p->down;
        }
        node->down = p->down;
        p->down = node;
    }
    return matrix;
}

ElemSet GetElem(SparseMatrix matrix, int row, int col){
    if(row < 0 || col < 0 || matrix->down[row].down == NULL || matrix->right[col].right == NULL){
        printf("ERROR\n");
        return 0;
    }

    SparseMatrix rowHead = &matrix->down[row];
    SparseMatrix p = rowHead->right;

    while(p != rowHead && p->u_region.term.col < col){
        p = p->right;
    }

    if(p != rowHead && p->u_region.term.col == col){
        return p->u_region.term.value;
    }

    return 0; 
}


// /* 初始化一个空十字链表 */
// SparseMatrix InitMatrix(int n_row, int n_col){
//     SparseMatrix matrix = (SparseMatrix)malloc(sizeof(struct SparseMatrixNode));
//     matrix->down = (SparseMatrix)malloc(n_row * sizeof(struct SparseMatrixNode));
//     matrix->right = (SparseMatrix)malloc(n_col * sizeof(struct SparseMatrixNode));
//     for(int i = 0; i < n_row; i++){
//         matrix->down[i].tag = head;
//         matrix->down[i].down = (i == n_row - 1 ? NULL : &matrix->down[i + 1]);
//         matrix->down[i].right = NULL;
//         matrix->u_region.next = NULL;
//     }
//     for(int i = 0; i < n_col; i++){
//         matrix->right[i].tag = head;
//         matrix->right[i].down = NULL;
//         matrix->right[i].right = (i == n_col - 1 ? NULL : &matrix->right[i + 1]);
//         matrix->right[i].u_region.next = NULL;
//     }
//     matrix->tag = head;
//     matrix->u_region.next = NULL;
//     return matrix;
// }

// /* 对于每个非零元素，设置一个初始节点 */
// SparseMatrix InitNode(int row, int col, int value){
//     SparseMatrix node = (SparseMatrix)malloc(sizeof(struct SparseMatrixNode));
//     node->u_region.term.row = row;
//     node->u_region.term.col = col;
//     node->u_region.term.value = value;
//     node->right = NULL;
//     node->down = NULL;
//     node->tag = term;
//     return node;
// }

// /* 查找最下面的元素 */
// SparseMatrix FindDown(SparseMatrix head){
//     return head->down == NULL ? head : FindDown(head->down);
// }

// /* 查找最右边的元素 */
// SparseMatrix FindRight(SparseMatrix head){
//     return head->right == NULL ? head : FindRight(head->right);
// }

// SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n){
//     SparseMatrix matrix = InitMatrix(n_row, n_col);
//     int row, col;
//     ElemSet value;
//     for(int i = 0; i < n; i++){
//         scanf("%d%d%d", &row, &col, &value);
//         SparseMatrix node = InitNode(row, col, value);
//         SparseMatrix p_left = FindRight(&(matrix->down[row]));
//         SparseMatrix p_upper = FindRight(&(matrix->down[col]));
//         p_left->right = node;
//         p_upper->down = node;
//     }
//     return matrix;
// }

// ElemSet GetElem(SparseMatrix matrix, int row, int col){
//     SparseMatrix rowHead = &matrix->down[row];
//     while(rowHead != NULL && rowHead->tag != term){
//         rowHead = rowHead->right;
//     }
//     if(rowHead != NULL && rowHead->u_region.term.col == col){
//         return rowHead->u_region.term.value;
//     }
//     printf("ERROR\n");
//     return 0; 
// }
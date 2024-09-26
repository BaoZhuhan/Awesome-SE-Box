#include <stdio.h>
#include <stdlib.h>

#define ElemSet int

typedef enum { head, term } NodeTag;
struct TermNode { /* 非零元素结点 */
    int row, col; /* 行号，列号 */
    ElemSet value; /* 元素值 */
};
typedef struct SparseMatrixNode* Position; /* 结点位置是指针 */
typedef Position SparseMatrix;
struct SparseMatrixNode {
    Position down; /* 向下的列指针 */
    Position right; /* 向右的行指针 */
    NodeTag tag; /* 结点标记 */
    union {
        Position next; /* 头结点链接指针 */
        struct TermNode term; /* 非零元素结点 */
    } u_region; /* head和term的共用体 */
};

SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n) {
    
}

ElemSet GetElem(SparseMatrix matrix, int row, int col) {
}
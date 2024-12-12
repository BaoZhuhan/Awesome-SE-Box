首先简单复习一下链表的定义[^1]

[^1]:[链表 - OI Wiki](https://oi-wiki.org/ds/linked-list/)


```c
/*a struct define of one-way linked list*/
typedef struct node {
    int value;
    struct node* next;
}node;
```

同时复习一下邻接表的定义[^2]

[^2]:[C Program to Implement Adjacency List - GeeksforGeeks](https://www.geeksforgeeks.org/c-program-to-implement-adjacency-list/)

```c
typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct Graph{
    int numV;
    struct Node** List;
    int isD;
}Graph;
```

简单学习一下什么是逆邻接表[^3][^4]

[^3]:[邻接表和逆邻接表-CSDN博客](https://blog.csdn.net/ASJBFJSB/article/details/100887364)

[^4]:https://courses.edx.org/c4x/PekingX/04830050x/asset/chapter7_002_en.pdf



看一眼题目：

```c
#include <stdio.h>
#include <stdlib.h>

#define ElemSet int

typedef enum{ head, term } NodeTag;
struct TermNode{ /* 非零元素结点 */
    int row, col; /* 行号，列号 */
    ElemSet value; /* 元素值 */
};
typedef struct SparseMatrixNode* Position; /* 结点位置是指针 */
typedef Position SparseMatrix;
struct SparseMatrixNode{
    Position down; /* 向下的列指针 */
    Position right; /* 向右的行指针 */
    NodeTag tag; /* 结点标记 */
    union{
        Position next; /* 头结点链接指针 */
        struct TermNode term; /* 非零元素结点 */
    } u_region; /* head和term的共用体 */
};

SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n){

}
```

关于union的解释

在C语言中，`union`是一种数据结构，它允许在同一个内存位置存储不同类型的数据。`union`中的所有成员共享同一块内存，因此在任意时刻，`union`只能存储一个成员的值。使用`union`可以节省内存空间。

在你提供的代码中，`union`被定义在`SparseMatrixNode`结构体中，具体如下：

```c
union{
    Position next; /* 头结点链接指针 */
    struct TermNode term; /* 非零元素结点 */
} u_region; /* head和term的共用体 */
```

这个`union`有两个成员：
1. `Position next`：用于存储头结点的链接指针。
2. `struct TermNode term`：用于存储非零元素结点的信息。

`u_region`是这个`union`的名字。根据`SparseMatrixNode`结构体的`tag`字段（`NodeTag tag`），可以判断当前`union`存储的是哪种类型的数据：
- 如果`tag`是`head`，则`u_region`存储的是`next`指针。
- 如果`tag`是`term`，则`u_region`存储的是`term`结构体。

这种设计允许在同一个结点中存储不同类型的数据，从而实现稀疏矩阵的高效存储和操作。


尝试实现一份答题代码

```c

/* 初始化一个空十字链表 */
SparseMatrix InitMatrix(int n_row, int n_col){
    SparseMatrix matrix = (SparseMatrix)malloc(sizeof(struct SparseMatrixNode));
    matrix->down = (SparseMatrix)malloc(n_row * sizeof(struct SparseMatrixNode));
    matrix->right = (SparseMatrix)malloc(n_col * sizeof(struct SparseMatrixNode));
    for(int i = 0; i < n_row; i++){
        matrix->down[i].tag = head;
        matrix->down[i].down = (i == n_row - 1 ? NULL : &matrix->down[i + 1]);
        matrix->down[i].right = NULL;
        matrix->u_region.next = NULL;
    }
    for(int i = 0; i < n_col; i++){
        matrix->right[i].tag = head;
        matrix->right[i].down = NULL;
        matrix->right[i].right = (i == n_col - 1 ? NULL : &matrix->right[i + 1]);
        matrix->right[i].u_region.next = NULL;
    }
    matrix->tag = head;
    matrix->u_region.next = NULL;
    return matrix;
}

/* 对于每个非零元素，设置一个初始节点 */
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

/* 查找最下面的元素 */
SparseMatrix FindDown(SparseMatrix head){
    return head->down == NULL ? head : FindDown(head->down);
}

/* 查找最右边的元素 */
SparseMatrix FindRight(SparseMatrix head){
    return head->right == NULL ? head : FindRight(head->right);
}

SparseMatrix BuildSparseMatrix(int n_row, int n_col, int n){
    SparseMatrix matrix = InitMatrix(n_row, n_col);
    int row, col;
    ElemSet value;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &row, &col, &value);
        SparseMatrix node = InitNode(row, col, value);
        SparseMatrix p_left = FindRight(&(matrix->down[row]));
        SparseMatrix p_upper = FindRight(&(matrix->down[col]));
        p_left->right = node;
        p_upper->down = node;
    }
    return matrix;
}

ElemSet GetElem(SparseMatrix matrix, int row, int col){
    SparseMatrix rowHead = &matrix->down[row];
    while(rowHead != NULL && rowHead->tag != term){
        rowHead = rowHead->right;
    }
    if(rowHead != NULL && rowHead->u_region.term.col == col){
        return rowHead->u_region.term.value;
    }
    printf("ERROR\n");
    return 0; 
}
```
chatgpt 给出的评价

### 关键问题与改进

1. **`InitMatrix` 函数：**
   - 你使用了二维数组的形式为 `matrix->down` 和 `matrix->right` 分配空间，这是不正确的，应该为每个行和列头节点分配单个节点。
   - `matrix->down[i].down` 和 `matrix->right[i].right` 应该指向头节点而不是 `NULL`。这些指针应该形成一个环形链表的结构。

2. **`BuildSparseMatrix` 函数：**
   - 你使用了两个 `FindRight` 和 `FindDown` 函数来查找当前行和列的最后一个元素，这虽然在简单情况下可行，但会降低效率。应该根据插入位置直接找到需要插入的位置，而不是总是从头开始查找。
   - 你在 `FindRight` 和 `FindDown` 中没有考虑 `tag` 是否为 `term`，因此会陷入错误。

3. **`GetElem` 函数：**
   - 你在查找行时使用了一个错误的方式。应该从 `matrix->down[row]` 开始遍历该行的所有节点，直到找到 `col` 位置对应的节点，而不是简单地查找第一个非零元素。

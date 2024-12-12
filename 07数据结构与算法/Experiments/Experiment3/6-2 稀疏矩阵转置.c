#include <stdio.h>
#define N 5 //二维数组的行列值
#define t 10 //稀疏矩阵最大长度

typedef  struct{
    int  row, col;     //行号、列号
    int    val;
}elem;

void trans_mat(elem a[], int n, elem b[]);
void show_mat(elem a[], int n);

void input(elem a[], int n){
    int i;
    for(i = 0;i < n;i++)
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].val);
}

int main(){
    int n;
    elem a[t], b[t];
    scanf("%d", &n);
    input(a, n);
    trans_mat(a, n, b);
    show_mat(b, n);
    return 0;
}


/* 请在这里填写答案 */

int cmp(const void *a, const void *b) {
    elem *elemA = (elem *)a;
    elem *elemB = (elem *)b;
    return (elemA->row - elemB->row);
}

void trans_mat(elem a[], int n, elem b[]) {
    for (int i = 0; i < n; i++) {
        b[i].col = a[i].row;
        b[i].row = a[i].col;
        b[i].val = a[i].val;
    }
    qsort(b, n, sizeof(elem), cmp);
    return;
}

void show_mat(elem* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);
    }
}
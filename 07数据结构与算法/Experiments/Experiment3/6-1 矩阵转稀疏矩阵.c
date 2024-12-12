#include <stdio.h>
#define M 10  //行
#define N 10  //列

typedef struct{
    int row, col;     //行号、列号
    int val;
}elem;

int create_mat(int (*d)[N], int m, int n, elem* a);//创建稀疏矩阵
void show_mat(elem* a, int n);//输出稀疏矩阵

int main(){
    int a[M][N], m, n, n1, i, j;
    elem b[M * N];
    scanf("%d%d", &m, &n);
    for(i = 0;i < m;i++)
        for(j = 0;j < n;j++)
            scanf("%d", &a[i][j]);
    n1 = create_mat(a, m, n, b);
    show_mat(b, n1);
    return 0;
}

/* 请在这里填写答案 */

int create_mat(int (*d)[N], int m, int n, elem* a){
    int idx = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j] != 0){
                a[idx].row = i;
                a[idx].col = j;
                a[idx].val = d[i][j];
                idx++;
            }
        }
    }
    // qsort()
    return idx;
}


void show_mat(elem* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);
    }
}
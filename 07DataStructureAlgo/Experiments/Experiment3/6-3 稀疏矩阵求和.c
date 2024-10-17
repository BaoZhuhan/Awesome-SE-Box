#include <stdio.h>
#define M 10  //行
#define N 10  //列
typedef  struct{
    int  row, col;     //行号、列号
    int    val;
}elem;

void input(elem a[], int m);
void show_mat(elem a[], int n);
int add_mat(elem a[], int t1, elem b[], int t2, elem c[]);

void input(elem a[], int m){
    int i;
    for(i = 0;i < m;i++)
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].val);
}

void show_mat(elem a[], int n)//输出
{
    int i;
    for(i = 0;i < n;i++)
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);
}


int main(){
    int t, m, n;
    elem a[M * N], b[N * M], c[N * M];
    scanf("%d%d", &m, &n);
    input(a, m);
    input(b, n);
    t = add_mat(a, m, b, n, c);//c=a+b
    show_mat(c, t);
    return 0;
}

/* 请在这里填写答案 */

void show_mat(elem* a, int n){
    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);
    }
}


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

int d[10][10];
int add_mat(elem a[], int t1, elem b[], int t2, elem c[]){
    for(int i = 0; i < t1; i++){
        d[a[i].row][a[i].col] += a[i].val;
    }
    for(int i = 0; i < t2; i++){
        d[b[i].row][b[i].col] += b[i].val;
    }
    int idx = create_mat(d,10,10,c);
    return idx;
}
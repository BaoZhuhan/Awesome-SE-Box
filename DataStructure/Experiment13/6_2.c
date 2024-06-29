#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct{
    KeyType* elem; /*elem[0]一般作哨兵或缓冲区*/
    int Length;
}SqList;

void CreatSqList(SqList* L);/*待排序列建立，由裁判实现，细节不表*/
int Partition(SqList  L, int low, int  high);
void Qsort(SqList  L, int low, int  high);

int main(){
    SqList L;
    int i;
    CreatSqList(&L);
    Qsort(L, 1, L.Length);
    for(i = 1;i <= L.Length;i++)
        printf("%d ", L.elem[i]);
    return 0;
}

void Qsort(SqList  L, int low, int  high){
    int  pivotloc;
    if(low < high){
        pivotloc = Partition(L, low, high);
        Qsort(L, low, pivotloc - 1);
        Qsort(L, pivotloc + 1, high);
    }
}
/*你的代码将被嵌在这里 */
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//WA
int Partition(SqList L, int low, int high){
    int center = (low + high) >> 1;

    if(L.elem[low] > L.elem[center]) swap(&L.elem[low], &L.elem[center]);
    if(L.elem[low] > L.elem[high]) swap(&L.elem[low], &L.elem[high]);
    if(L.elem[center] > L.elem[high]) swap(&L.elem[center], &L.elem[high]);

    swap(&L.elem[center], &L.elem[high - 1]);
    return L.elem[high - 1];
}

//WA
int Partition(SqList L, int low, int high){
    while(low < high){
        while(low < high && L.elem[low] <= L.elem[high]) high--;
        if(low < high){
            int temp = L.elem[low];
            L.elem[low] = L.elem[high];
            L.elem[high] = temp;
            low++;
        }
        while(low < high && L.elem[low] <= L.elem[high]) low++;
        if(low < high){
            int temp = L.elem[low];
            L.elem[low] = L.elem[high];
            L.elem[high] = temp;
            high--;
        }
        return low;
    }
}

int Partition(SqList L, int low, int high){
    int temp = L.elem[low];
    L.elem[0] = L.elem[low];

    while(low < high){
        while(low < high && L.elem[high] >= temp) high--;
        L.elem[low] = L.elem[high];
        while(low < high && L.elem[low] <= temp) low++;
        L.elem[high] = L.elem[low];
    }
    L.elem[low] = L.elem[0];
    return low;
}
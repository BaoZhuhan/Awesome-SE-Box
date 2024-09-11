#include<stdio.h>
#include<stdlib.h>

typedef  int  KeyType;
typedef  struct{
    KeyType* elem; /*elem[0]一般作哨兵或缓冲区*/
    int Length;
}SqList;
typedef SqList HeapType;

void CreatSqList(HeapType* L);/*待排序列建立，由裁判实现，细节不表*/
void HeapAdjust(HeapType  H, int s, int m);
void HeapSort(HeapType  H);

int main(){
    HeapType L;
    int i;
    CreatSqList(&L);
    HeapSort(L);
    for(i = 1;i <= L.Length;i++){
        printf("%d ", L.elem[i]);
    }
    return 0;
}

void HeapSort(HeapType  H){ /*堆顺序表H进行堆排序*/
    int i; KeyType rc;
    /*建立初始堆*/
    for(i = H.Length / 2;i > 0; i--){
        HeapAdjust(H, i, H.Length);
    }
    for(i = H.Length;i > 1;i--){
        rc = H.elem[1];
        H.elem[1] = H.elem[i];
        H.elem[i] = rc;
        HeapAdjust(H, 1, i - 1);
    }
}

/*你的代码将被嵌在这里 */
void HeapAdjust(HeapType  H, int s, int m){
    while(1){
        // 判断节点 i, l, r 中值最大的节点，记为 ma
        int l = 2 * s;
        int r = 2 * s + 1;
        int ma = s;
        if(l < m && H.elem[l] > H.elem[ma])
            ma = l;
        if(r < m && H.elem[r] > H.elem[ma])
            ma = r;
        // 若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
        if(ma == s){
            break;
        }
        // 交换两节点
        int temp = H.elem[s];
        H.elem[s] = H.elem[ma];
        H.elem[ma] = temp;
        // 循环向下堆化
        s = ma;
    }
}
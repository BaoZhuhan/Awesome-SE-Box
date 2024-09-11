#include <stdio.h>
#include <stdlib.h>
struct Heap{
    int* data;
    int capacity;
    int size;
};
struct Heap* initHeap(int capacity){   // 初始化堆
    struct Heap* h;
    h = (struct Heap*)malloc(sizeof(struct Heap));
    if(!h) return NULL;
    h->data = (int*)malloc(sizeof(int) * capacity + 1);
    if(h->data == NULL){
        free(h);
        return NULL;
    }
    h->capacity = capacity;
    h->size = 0;
    return h;
};
void printHeap(struct Heap* h){  // 打印堆元素
    for(int i = 1; i <= h->size;i++){
        printf("%d, ", h->data[i]);
    }
    printf("\n");
}
int insertIntoHeap(struct Heap* h, int x);
int deleteMin(struct Heap* h, int* pElement);
int main(){
    struct Heap* h;
    int n;
    scanf("%d", &n);   // 输入堆容量
    h = initHeap(n);
    int op, x;
    scanf("%d", &op);
    while(op){    // 输入操作： -1表示删除   1表示插入   0表示结束
        if(op == 1){
            scanf("%d", &x);
            printf("Insertion %s. ", insertIntoHeap(h, x) ? "succeeded" : "failed");
            printHeap(h);
        }
        else{
            if(deleteMin(h, &x)) printf("%d deleted. ", x);
            else printf("Deletion failed. ");
            printHeap(h);
        }
        scanf("%d", &op);
    }
    return 0;
}

/*你提交的代码将被嵌在这里 */
#define false 0
#define true 1
int IsFull(struct Heap* h){
    return (h->size == h->capacity);
}
void ShiftUp(struct Heap* h, int i){
    while(true){
        int p = i / 2;
        if(p < 1 || h->data[i] >= h->data[p]){ break; }

        int temp = h->data[i];
        h->data[i] = h->data[p];
        h->data[p] = temp;

        i = p;
    }
}
int insertIntoHeap(struct Heap* h, int x){
    if(IsFull(h)) return false;

    ++h->size;
    h->data[h->size] = x;
    ShiftUp(h, h->size);

    return true;
}
void ShiftDown(struct Heap* h, int i){
    while(true){
        int l = i * 2;
        int r = i * 2 + 1;
        int mn = i;
        if(l <= h->size && h->data[l] < h->data[mn]){
            mn = l;
        }
        if(r <= h->size && h->data[r] < h->data[mn]){
            mn = r;
        }
        if(mn == i){ break; }

        int temp = h->data[i];
        h->data[i] = h->data[mn];
        h->data[mn] = temp;

        i = mn;
    }
}
int deleteMin(struct Heap* h, int* pElement){
    if(h->size == 0) return false;

    *pElement = h->data[1];

    h->data[1] = h->data[h->size];
    --h->size;
    ShiftDown(h, 1);

    return true;
}
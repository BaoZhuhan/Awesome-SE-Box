#include<stdio.h>
#include<stdlib.h>
#define MAX 1010
int N;
int arr[MAX], mid[MAX];
int f = 1;

int cmp(){
    int i;
    for(i = 0; i < N; i++){
        if(arr[i] != mid[i]) return 0;
    }
    return 1;
}

int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void Mer(int h){
    int i = 0;
    while(i + 2*h <= N){
        qsort(arr + i, 2*h, sizeof(int), cmpfunc);
        i = i + 2*h;
    }
    if(i + h < N){
        qsort(arr + i, N - i, sizeof(int), cmpfunc);
    }
}

int main(){
    int i, h = 1, id = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++){ scanf("%d", &arr[i]); }
    for(i = 0; i < N; i++){ scanf("%d", &mid[i]); }

    for(i = 0; i < N - 1; i++){
        if(mid[i] > mid[i + 1]){
            id = i + 1;
            break;
        }
    }
    for(i = id; i < N; i++){
        if(mid[i] != arr[i])
            f = 0;
    }
    if(f){
        qsort(mid, id + 1, sizeof(int), cmpfunc);
        printf("Insertion Sort\n");
        for(i = 0; i < N; i++){
            if(i) printf(" %d", mid[i]);
            else printf("%d", mid[i]);
        }
    } else {
        while(h < N){
            if(!cmp()){
                Mer(h);
                h *= 2;
            } else {
                printf("Merge Sort\n");
                Mer(h);
                for(i = 0; i < N; i++){
                    if(i) printf(" %d", arr[i]);
                    else printf("%d", arr[i]);
                }
                return 0;
            }
        }
    }
    return 0;
}
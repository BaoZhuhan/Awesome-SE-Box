#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int cmp(const void *a , const void *b){
    return *(int*)a > *(int*)b; //小到大
    return *(int*)a < *(int*)b; //大到小
}

int main(){
    int a[5] = {1,2,3,4,0};
    qsort(a, 5 , sizeof(int) , cmp);

    for(int i = 0 ; i < 5 ; i++) {
        printf("%d " , a[i]);
    }
    return 0;
}
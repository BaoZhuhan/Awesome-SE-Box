#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int cmp(const void *a , const void *b){
    return *(int*)a > *(int*)b ;
}

void run(){
    int n ;
    scanf("%d", &n);

    int *a;
    a = (int*)malloc((n + 1) * sizeof(int));

    for(int i = 0 ; i < n ; i ++ ){
        scanf("%d" , &a[i]);
    }

    scanf("%d" , &a[n]);

    qsort(a , n+1 , sizeof(int) , cmp);

    for(int i = 0 ; i < n+1 ; i++) {
        printf("%d " , a[i]);
    }
}

int main(){
    int T = 1;
    while(T--) run();
    return 0;
}
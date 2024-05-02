#include <stdio.h>
int a[100];
int main(void){
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i < n  ;i ++){
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n-1 ; j ++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i = 0 ; i < n ;i++){
        printf("%d ", a[i]);
    }
}
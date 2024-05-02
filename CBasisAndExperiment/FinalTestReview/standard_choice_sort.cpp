#include <stdio.h>
int a[100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        int p_min = i;
        for(int j = i ; j < n ; j++){
            if(a[j] < a[p_min]){
                p_min = j;
            }
        }
        int tmp = a[i];
        a[i] = a[p_min];
        a[p_min] = tmp;
    }
    return 0 ;
}
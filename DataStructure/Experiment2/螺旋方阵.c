#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int a[10][10] = {0};
int n ;

int fill(int layer,int len,int val){
    for(int i = layer ; i < layer + len ; i++){
        val = val + 1;
        if(val > n*n ) break;
        a[layer][i] = val;
    }

    for(int i = layer + 1 ; i < layer + len - 1 ; i++){
        val = val + 1;
        if(val > n*n ) break;
        a[i][layer + len - 1] = val;
    }

    for(int i = layer + len - 1 ; i >= layer ; i--){
        val = val + 1;
        if(val > n*n ) break;
        a[layer + len - 1][i] = val;
    }

    for(int i = layer + len - 2 ; i > layer ; i--){
        val = val + 1;
        if(val > n*n ) break;
        a[i][layer] = val;
    }

    return val;
}

int main(){
    
    scanf("%d",&n);

    int val = 0;
    
    for(int i = n ; i > 0 ; i -= 2){
        val = fill((n-i)/2 , i , val);
    }
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
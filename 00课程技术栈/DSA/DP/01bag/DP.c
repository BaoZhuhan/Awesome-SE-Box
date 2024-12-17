#include <stdio.h>
#include <stdlib.h>

int max(int a,int b) {return a > b ? a : b;}

int dp(int wgt[], int value[], int cap, int wgtSize){
    int n = wgtSize;
    int **dp = malloc((n + 1)*sizeof(int *));
    for(int i = 0 ; i <= n ; i++){
        dp[i] = calloc(cap+1,sizeof(int));
    }
    for(int i = 1; i <= n ;i++) {
        for(int c = 1; c <= cap ; c++) {
            if(wgt[i-1] > c){
                dp[i][c] = dp[i-1][c];
            }else{
                dp[i][c] = max(dp[i-1][c],dp[i-1][c-wgt[i-1]] + value[i-1]);
            }
        } 
    }
    int res = dp[n][cap];
    free(dp);
    return res;
}


int main(){

}
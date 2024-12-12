#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    
    int t1 = (a/100)*60 + a%100;
    int t2 = (b/100)*60 + b%100;

    int res = t2 - t1;

    printf("%02d:%02d",(res/60),(res%60));

    return 0;
}
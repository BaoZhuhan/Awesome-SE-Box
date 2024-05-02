#include <stdio.h>

int main(void){
    //setting and input
    int m,n,mid;
    double sum;
    scanf("%d %d",&m,&n);
    if(m > n){
        mid = m;
        m = n;
        n = mid;
    }

    //calculate
    for(double i=m;i<=n;i++){
        sum += i*i;
    }
    for(double i=m;i<=n;i++){
        sum += 1/i;
    }

    printf("sum = %.6lf",sum);
    return 0;
    
}
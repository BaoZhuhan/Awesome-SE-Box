#include <stdio.h>

int main(void){
    double eps=0.0,sum=0,last=1;
    scanf("%lf",&eps);
    if(eps>=1){
        printf("sum = 1.000000");
        return 0;
    }
    for(double i = 1;last>eps;i+=3){
        last=1/i;
        if((int)i%2==0) sum-=last;
        else sum+=last;
    }
    printf("sum = %.6lf",sum);
    return 0;
}

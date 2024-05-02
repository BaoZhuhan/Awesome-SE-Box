#include <stdio.h>

int main(void){
    double a=0,b=0;
    scanf("%lf",&a);
    for(double i = 1; i<= a ;i++){
        if((long)i%2 == 0){
            b += (-1)*1/(1+3*(i-1));
        }
        else{
            b += (1)*1/(1+3*(i-1));
        }
    }
    printf("sum = %.3lf",b);
    return 0;
}
#include <stdio.h>

int main(void){
    double a=0,b=0;
    scanf("%lf",&a);
    for(double i = 1; i<= a ;i++){
        b += 1/(2*i-1);
    }
    printf("sum = %.6lf",b);
    return 0;
}
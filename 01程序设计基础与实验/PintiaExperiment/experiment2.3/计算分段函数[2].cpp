#include <stdio.h>
#include <math.h>

int main(void){
    //setting and i
    float a,b;
    
    scanf("%f",&a);

    //calculate
    if(a >= 0){
        b = pow(a,0.5);
    }
    else{
        b = (a+1)*(a+1)+2*a+1/a;
    }

    //o
    printf("f(%.2f) = %.2f",a,b);
    return 0;
    
}
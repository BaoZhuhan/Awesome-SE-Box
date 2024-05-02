#include <stdio.h>
int main(void){
    float x,r;
    scanf("%f",&x);
    if(x == 0){
        r =0;
    }
    else{
        r = 1/x;
    }
    printf("f(%.1f) = %.1f",x,r);

    return 0;
}
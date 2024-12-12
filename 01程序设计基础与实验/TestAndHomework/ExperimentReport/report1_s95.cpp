#include <stdio.h>

int main(void){
    //setting and input
    double a,b,sum;
    char c;
    scanf("%lf %lf %c",&a,&b,&c);

    //calculate
    if(b==90) sum = 6.95*a;
    else if(b==93) sum =7.44*a;
    else sum =7.93*a;

    if(c=='e') sum*=0.97;
    else sum*=0.95;

    //output
    printf("%.2lf",sum);
    return 0;
    
}
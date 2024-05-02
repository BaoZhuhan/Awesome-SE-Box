#include <stdio.h>
#include <math.h>
int main(void){
    double a,b,c,d,s,area;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a>b){
        d=a;a=b;b=d;
    }
    if(b>c){
        d=b;b=c;c=d;
    }
    if(a+b<=c){
        printf("These sides do not correspond to a valid triangle");
        return 0;
    }
    s = (a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("area = %.2lf; perimeter = %.2lf",area,(a+b+c));
    return 0;
}
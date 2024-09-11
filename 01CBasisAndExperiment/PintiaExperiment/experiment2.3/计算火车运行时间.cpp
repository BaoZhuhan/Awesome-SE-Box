#include <stdio.h>

int main(void){
    int a,b,c,d,e,f,g,h,i,hh,mm;
    scanf("%d %d",&a,&b);
    c = (a-a%100)/100;
    d = (a%100);
    e = (b - b%100)/100;
    f = (b %100);
    g = 60*c+d;
    h = 60*e+f;
    i =h-g;
    hh = i/60;
    mm = i%60;
    if(hh>10 && mm>10 )
        printf("%d:%d",hh,mm);
    else if(hh<10 && mm>10 )
        printf("0%d:%d",hh,mm);
    else if(hh>10 && mm<10)
        printf("%d:0%d",hh,mm);
    else
        printf("0%d:0%d",hh,mm);
    return 0;
}


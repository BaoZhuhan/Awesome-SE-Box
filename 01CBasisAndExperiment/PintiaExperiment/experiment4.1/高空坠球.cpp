#include <stdio.h>

int main(void){
    double height=-1,n=-1,mile=0;
    scanf("%lf%lf",&height,&n);
    if(n==0) printf("0.0 0.0");
    else
    {
        for(int i=0;i<n;i++)
        {
            mile+=height;
            height/=2;
            mile+=height;
        }
        printf("%.1lf %.1lf",(mile-height),height);
    }
    return 0;
}
#include <stdio.h>

int main(void){
    long a=0,n=0,sum=0;
    scanf("%d %d",&a,&n);
    long q=a;
    for(int i=0;i<n;i++){
        if(i>0) a=a*10+q;
        sum+=a;
    }
    printf("s = %ld",sum);
    return 0;
}
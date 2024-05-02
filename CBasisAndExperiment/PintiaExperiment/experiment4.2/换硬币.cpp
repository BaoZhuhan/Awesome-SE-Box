#include <stdio.h>

int main(void){
    int count=0,total=0,x=0;
    scanf("%d",&x);
    for(int i = (int)(x/5) ;i>0;i-=1){
        for(int j = (int)(x-5*i)/2;j>0;j-=1){
            int k = x-5*i-2*j;
            if(k==0) continue;
            total=i+j+k;
            printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,total);
            count+=1;
        }
    }
    printf("count = %d",count);
    return 0;
}
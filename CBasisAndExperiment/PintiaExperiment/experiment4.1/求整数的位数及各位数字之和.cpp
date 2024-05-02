#include <stdio.h>

int main(void){
    long n,sum=0;
    scanf("%ld",&n);
    int i=0;
    for(i=0;n>0;i++){
        sum+=n%10;
        n/=10;
    }
    printf("%ld %ld",i,sum);
}
#include <stdio.h>


int prime( int p ){
    if(p==1 || p<=0 ) return 0;
    int flag =1;
    for(int i=2;i<p;i++){
        if(p%i ==0) flag = 0;
    }
    return flag;
}
int PrimeSum( int m, int n ){
    int sum =0;
    for(int i = m;i<=n;i++){
        if(prime(i)) sum+=i;
    }
    return sum;
}
int main(void){
    int count = 0,m,n;
    scanf("%d %d",&m,&n);
    for(int i = m;i<=n;i++){
        if(prime(i)) count++;
    }
    printf("%d %d",count,PrimeSum(m,n));
    return 0;
}
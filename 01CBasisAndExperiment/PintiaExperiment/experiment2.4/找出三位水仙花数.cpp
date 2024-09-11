#include <stdio.h>

int main(void){
    long m,n;
    scanf("%ld %ld",&m,&n);

    if(((100<=m)&&(m<=n))&&(n<=999)){
        
    }
    else{
        printf("Invalid Value.");
        return 0;
    }

    for(int i=m,a,b,c;i<=n;i++){
        a = i%10;
        b = ((i-a)%100)/10;
        c = (i - i%100)/100;
        if(a*a*a+b*b*b+c*c*c == i){
            printf("%d\n",i);
        }
    }
    return 0;
}
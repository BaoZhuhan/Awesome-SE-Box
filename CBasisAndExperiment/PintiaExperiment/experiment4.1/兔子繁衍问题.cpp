#include <stdio.h>

int main(void){
    //setting
    int N;
    scanf("%d",&N);
    if(N==1) printf("1");
    else{
        //prepare for Fibonacci
        int x1=1,x2=1,x,month=2;

        for(month=2;x2<N;month++){
            x=x2+x1;
            //next_month = last_month+new=last_month+(last_month_new+last_two_month_new)
            //[2,0,4,6,]
            x1=x2;
            x2=x;
        }
        printf("%d",month);
    }
    return 0;
}
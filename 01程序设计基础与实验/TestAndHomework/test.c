#include<stdio.h>
#include<math.h>
int main(void)
{
    int a,b,c,d;
    scanf("%d",&a);
    if(a<100 || a>999){
        printf("Invalid Value.");
    }
    b = a/100;
    c = a%100/10;
    d = a%100%10;
    if(pow(b,3)+pow(c,3)+pow(d,3)==a){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}
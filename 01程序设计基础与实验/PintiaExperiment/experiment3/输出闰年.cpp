#include<stdio.h>
int main(){
    int y,a=2004;
    scanf("%d",&y);
    if(y<=2000||y>2100) printf("Invalid year!");
    else if(y>2000&&y<2004) printf("None");
    else {
        while(a<=y&&a<=2096){
            printf("%d\n",a);
            a=a+4;
        }
    }
    return 0;
}
#include <stdio.h>

int main(void){
    int final =1;
    int getnum = 1;
    scanf("%d",&getnum);

    while(getnum>= 1){
        final = final*getnum;
        getnum -=1;
        
    }
    printf("%d",final);
}

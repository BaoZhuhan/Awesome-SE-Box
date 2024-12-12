#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);

    if(a > 999 || a < 100){
        printf("Invalid Value.");
        return 0;
    }

    int b = (a / 100);
    int c = (a % 100) / 10;
    int d = (a % 100) % 10;
    if(a == b * b * b + c * c * c + d * d * d){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}




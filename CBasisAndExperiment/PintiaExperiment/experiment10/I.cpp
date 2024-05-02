#include <stdio.h>

void dectobin( int n ){
    if(n == 0) printf("0");
    else if(n == 1) printf("1");
    else{
        int tmp = n % 2;
        dectobin( (int)(n/2) );
        printf("%d",tmp);
    }
}
int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
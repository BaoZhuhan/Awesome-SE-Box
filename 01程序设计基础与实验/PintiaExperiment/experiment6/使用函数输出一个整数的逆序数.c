#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int reverse(int number ){
    int flag = 0;
    if(number == 0) return 0;
    if(number < 0) {
        flag = 1;        
        number = -1 * number;
    }

    int tmp = 0;
    for(int i =  0 ; number > 0  ; ++i){
        tmp *= 10;
        tmp += number - number/10*10;
        number /= 10;
    }
    if(flag) return tmp*(-1);
    else return tmp;
}
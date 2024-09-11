#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );
    
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int fib( int n ){
    if( n == 1) return 1;
    if( n == 2) return 1;
    return fib(n-1) + fib(n-2);
}
void PrintFN( int m, int n ){
    int flag = 0 ;
    for(int i = 1 ; fib(i) <= n ; i++){
        int fib_i = fib(i);
        if( fib_i >= m && fib_i <=n && flag == 0){
            printf("%d" ,fib_i);
            flag = 1;
        }
        else if(fib_i >= m && fib_i <=n) printf(" %d" ,fib_i);
    }
    if(flag == 0) printf("No Fibonacci number");
}

#include <stdio.h>

double mypow( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%f\n", mypow(x, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double mypow( double x, int n ){
    double c =1;
    for(int i=1;i <= n;i++){
        c *= x;
    }
    return c;
}
#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic(int number) {
    int sum = 0;
    int temp = number;
    int n = 0;
    while (temp > 0) {
        temp /= 10;
        n++;
    }
    temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < n; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    return sum == number;
}

void PrintN(int m, int n) {
    for (int i = m + 1; i < n; i++) {
        if (narcissistic(i)) {
            printf("%d\n", i);
        }
    }
}
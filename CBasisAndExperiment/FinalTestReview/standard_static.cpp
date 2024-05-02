#include <stdio.h>

void f(int a){
    static int x = 1;
    x++;
    a++;
    printf("%d %d\n",x,a);
}
int main(void){
    int a = 1;
    f(a);
    f(a);
    f(a);
    return 0;
}
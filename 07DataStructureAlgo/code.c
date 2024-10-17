#include <stdio.h>

void p(){
    static int x = 1;
    x++;
    printf("%d\n",x);
}

int main(){
    p();
    p();
    return 0;
}
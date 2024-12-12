#include <stdlib.h>
#include <stdio.h>

union node {
    char x1;
    char x2;
    int t;
};

int main(){
    union node a;
    a.x1 = 'A' ;

    printf("%c, %c, %d" , a.x2 , a.x1 , a.t);

    return 0;
}
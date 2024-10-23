#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "code.c"

int main(){
    int w[5] = {2,8,31,19,28};
    int N = 5;
    char **res = huffmanCode(w,N);
    for(int i = 0 ; i < N ;i++) {
        printf("%d : %s\n",w[i],res[i]);
    }
    return 0;
}
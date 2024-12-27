#include <stdio.h>
#include <stdlib.h>

double *bolts;
double *nuts;

int op(double bolt, double nut){
    if(bolt == nut) return 0;
    return bolt > nut ? 1 : -1;
}

int solve(){
    
}

int main(){
    int n;
    scanf("%d", &n);

    blots = calloc(n, sizeof(double));
    nuts = calloc(n, sizeof(double));

    for(int i = 0 ; i < n ; i++) scanf("%d" , nuts + i);
    for(int i = 0 ; i < n ; i++) scanf("%d" , bolts + i);

    
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int *prime;
int prime_size = 0;

void get_prime(int n){
    prime = (int*)malloc(n * sizeof(int));
    
    int *vis;
    vis = (int*)malloc((n+1) * sizeof(int));

    memset(prime ,0 , n);
    memset(vis ,0 , n+1);

    int p = 0;    
    for(int i = 2 ; i <= n ; i++){
        if(vis[i] == 1) continue;
        
        prime[p] = i;
        ++p;

        for(int j = i ; j <= n ;j += i ) vis[j] = 1;
    }

    prime_size = p;
    return ;
}

void run(){
    int m , n ;
    scanf("%d%d" ,&m , &n);

    get_prime(n);

    int cot = 0;
    int sm = 0;

    for(int i = 0 ; i < prime_size ; i++) {
        if(prime[i] >= m &&  prime[i] <= n){
            cot++;
            sm += prime[i];
        }
    }
    
    printf("%d %d",cot , sm) ;
    return ;
}

int main(){
    int T = 1;
    while(T--) run();
    return 0;
}
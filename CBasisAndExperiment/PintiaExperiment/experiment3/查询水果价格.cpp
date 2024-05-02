#include <stdio.h>

int main(){
    float p[4] = {3.00,2.50,4.10,10.20};
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    for(int i = 0 ;i<5;i++){
        int n = 0;
        scanf("%d",&n);
        if(n==0) return 0;
        else if(n == 1 || n ==2||n ==3||n == 4) printf("price = %.2f\n",p[n-1]);
        else  printf("price = 0.00\n");
    }
    return 0;

}
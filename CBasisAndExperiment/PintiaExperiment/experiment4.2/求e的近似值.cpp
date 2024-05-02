#include <stdio.h>

double fact( int n ){
    double m =1;
    for(double i=1;i<=n;i++){
        m*=i;
    }
    return m;
}
int main(void){
    double e=1,n=-1;
    int x1=1;
    scanf("%lf",&n);
    
    for(int i = 0;i<n;i++){
        e+=1/fact(x1);
        x1++;
    }
    printf("%.8lf",e);
    return 0;
}
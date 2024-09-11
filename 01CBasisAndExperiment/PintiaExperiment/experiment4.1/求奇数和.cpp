#include <stdio.h>

int main(){
    int sum = 0,q=0;
    while(1){
        scanf("%d",&q);
        if(q<=0) break;
        else if(q%2 == 1) sum+=q;
        else continue;
    }
    printf("%d",sum);
}

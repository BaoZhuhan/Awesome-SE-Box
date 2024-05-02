#include <stdio.h>

int main(void){
    float a,b;
    scanf("%f",&a);

    if(a<0){
        printf("Invalid Value!");
        
    }
    else if(a<=50){
        printf("cost = %.2f",(a*0.53));
    }
    else{
        printf("cost = %.2f",(50*0.53+(a-50)*0.58));
    
    }
    return 0;
}
#include <stdio.h>

int main(void){
	
    long a=0,b=0,c=0,i=0;
    scanf("%d",&i);
    
    if(i<100 || i>999){
        printf("Invalid Value.");
        return 0;
    }
    a = i%10;
    b = ((i-a)%100)/10;
    c = (i - i%100)/100;
    if(a*a*a+b*b*b+c*c*c == i){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0; 
}




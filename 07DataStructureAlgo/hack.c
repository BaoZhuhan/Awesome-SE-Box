#include <stdio.h>

int main(){
    for(int i = 0; i < 7; i++){
        printf("\n7\n");
        for(int j = 0 ; j < 7; j++){
            printf("%d ",(i+j) % 7);
        }
        
    }
    return 0;
}
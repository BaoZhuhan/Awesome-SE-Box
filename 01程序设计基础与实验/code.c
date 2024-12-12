#include<stdio.h>
int main(){
    int N, n, a, i = 0;
    scanf("%d %d", &n, &N);

    do{
        i++;
        scanf("%d", &a);
        if(a < 0){
            printf("Game Over\n");
            break;
        }
        else{
            if(a == n){
                if(i == 1){
                    printf("Bingo!\n");
                    break;
                }
                else if(i <= 3){
                    printf("Lucky You!");
                    break;
                }
                else if(i <= N){
                    printf("Good Guess!");
                    break;
                }else{
                    printf("Game over");
                    break;
                }
            }
            else if(a < n && i <= N){
                printf("Too small\n");
            }
            else if(a > n && i <= N){
                printf("Too big\n");
            }
            else{
                printf("Game Over\n");
            }
        }
    } while(i <= N);
    return 0;

}
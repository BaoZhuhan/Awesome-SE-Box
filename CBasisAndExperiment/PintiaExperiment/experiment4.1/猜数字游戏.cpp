#include <stdio.h>

int main(void){
    //setting
    int target=-1,max=-1,count=0,user=-1,flag = 0;
    scanf("%d%d",&target,&max);

    //get user input
    for(int i=0;i<max;i++){
        //input and refresh
        scanf("%d",&user);
        count++;
        //win and fall           
        if(user<0) break;   
        else if(user == target){
            flag = 1;
            break;
        }
        //big and small
        else if(user>target) printf("Too big\n");
        else printf("Too small\n");
    }
    //end output
    if(flag == 0) printf("Game Over");
    else if(count == 1) printf("Bingo!");
    else if(count <= 3) printf("Lucky You!");
    else printf("Good Guess!");

    return 0;
}
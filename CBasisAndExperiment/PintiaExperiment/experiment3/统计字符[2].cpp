#include <stdio.h>

int main(void){
    //setting and input n
    int n,ltr=0,blk=0,dgt=0,other=0 ;
    char c;
    scanf("%d%c",&n,&c);

    //input and count
    for(int i = 0;i<n;i++){
        scanf("%c",&c);
        if(('a'<=c && c<='z') || ('A'<=c && c<='Z')) ltr++;
        else if(c==' ' || c=='\n') blk++;
        else if('0'<=c && c<='9') dgt++;
        else other++;
    }

    //output 
    printf("letter = %d, blank = %d, digit = %d, other = %d",ltr,blk,dgt,other);
    return 0;
}
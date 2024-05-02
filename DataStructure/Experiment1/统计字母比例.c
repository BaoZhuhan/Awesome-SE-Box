#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int loc;
    char wrd;
    int nxt;
}node;

node *a;
int ans[26] = {0};
int sum = 0 ;

void run(){
    int head , n;
    scanf("%d%d", &head , &n);

    a = (node*)malloc(n * sizeof(node));

    for(int i = 0 ; i < n ; i ++){
        scanf("%d%c%d" , &a[i].loc , &a[i].wrd , &a[i].nxt); 
        
    }
    printf("%d %d\n" , head , n);
    
    for(int i = 0 ; i < n; i++ ){
        printf("%d %c %d\n" , a[i].loc , a[i].wrd , a[i].nxt);
    }

    // int flag = 1;
    // int p = head;

    // while(flag == 1) {
    //     for(int i = 0 ; i < n ; i++) {
    //         if(a[i].loc == p){
    //             ans[(a[i].wrd - 'A')] ++;
    //             sum ++;
    //             p = a[i].nxt;
    //             if(a[i].loc == -1) flag = 0;
    //             break;
    //         }
    //     }
    // }    

    // for(int i = 0 ; i < 26 ; i++){
    //     if(ans[i] != 0 ) printf("%c %.2f\%\n",'A'+i , ((float)ans[i]/(float)sum)*100  );
    // }
}


int main(){
    run();
    return 0;
}



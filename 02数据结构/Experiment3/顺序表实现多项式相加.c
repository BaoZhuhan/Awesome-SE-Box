#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 105

typedef struct node {
    int coef;
    int exp;
}node;

typedef struct lnode{
    node data[N];
    int last;
}list;

list *init(){
    list *L;
    L = (list*)malloc(sizeof(list));
    L->last = -1;
    return L;
}

int findexp(list *L ,int exp ){
    for(int i = 0 ; i <= L->last ; i++){
        if(L->data[i].exp == exp){
            return i;
        }
    }
    return -1;
}

void insert(list *L , node x , int loc){
    // printf("loc-->%d\n",loc);//debug

    if(L->last == N) return;
    if(loc < 0 || loc>L->last+1 ) return;

    if(loc < L->last+1) {
        for(int j = L->last ; j >= loc; j--){
            L->data[j+1] = L->data[j];
        }
    }
    L->data[loc] = x;
    L->last++;

}

int delete(list *L , int loc){

    if(loc < 0 || loc > L->last ) return 0;

    for(int j = loc ; j < L->last ;j++){
        L->data[j] = L->data[j+1] ;
    }
    L->last--;

    return 1;
}

void output(list *L){
    if(L->last == -1) return;
    printf("%dx^%d" ,L->data[0].coef , L->data[0].exp);
    for(int i = 1 ; i <= L->last ;i++){
        if(L->data[i].coef > 0 ){
            printf("+%dx^%d",L->data[i].coef , L->data[i].exp);
        }else{
            printf("%dx^%d",L->data[i].coef , L->data[i].exp);
        }
        
    }
    printf("\n");
    // printf("last-->%d\n",L->last); // debug
    return;
}

void debug(list *L , int n){
    if(n == 1){
        printf("debug1-1--> %d\n",L->last);
        printf("debug1-2--> %dx^%d\n",L->data[0].coef , L->data[0].exp);
    }

    
    if(n == 2){
        output(L);
        printf("\n");
    }
}

void run(){
    list* L;
    L = init();

    for(int i = 0 ; i < 2 ; i ++ ){    
        int n ;
        scanf("%d" , &n);
        
        for(int j = 0 ; j < n ; j++) {
            // debug(L , 2);

            node tnode;
            scanf("%d%d" ,&tnode.exp , &tnode.coef);

            int loc = findexp(L , tnode.exp);
            if(loc != -1){
                L->data[loc].coef += tnode.coef;
                
                if(L->data[loc].coef == 0){
                    delete(L , loc);
                }
            }else{
                if(L->last == -1) insert(L , tnode , 0);
                else{
                    if(L->data[L->last].exp < tnode.exp){
                        insert(L , tnode , L->last+1);
                    }else{
                        for(int k = 0 ; k <= L->last ; k++){
                            if(L->data[k].exp > tnode.exp){
                                // printf("here comes , k--> %d , data[k].exp--> %d , tnode.exp--> %d\n" , k , L->data[k].exp , tnode.exp) ;//debug
                                insert(L , tnode , k);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    //debug(L ,1);
    output(L);
}

int main(){
    int T = 1;
    scanf("%d" , &T);
    while(T--) run();
    return 0;
}

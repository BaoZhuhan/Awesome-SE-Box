#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}list;

list* create(){
    list* H;
    H = (list*)malloc(sizeof(struct node));
    H->next = NULL;
    return H;
}

list* insert(list *pre , int x){
    list* now;
    now = (list*)malloc(sizeof(list));
    now->data = x;
    now->next = pre->next;
    pre->next = now;

    return now;
}

list* find(list *H , int x){
    list *p = H->next;
    while(p && p->data != x){
        p = p->next;
    }
    return p;
}

void print(list *H){
    if(H->next == NULL) {return;}
    list *p = H->next;
    while(p->next){
        printf("%d " , p->data);
        p = p->next;
    }
    printf("%d" , p->data);

}

int main(){
    list* H = create();

    int n ;
    scanf("%d" , &n);

    list *p = H; //我们需要一个指针

    for(int i = 0 ; i < n ; i ++){
        int t;
        scanf("%d" , &t);
        
        p = insert(p, t);
    }

    int x;
    scanf("%d" , &x);

    if(find(H , x) == NULL){
        list *p = H;
        while(p->next->data < x){
            p = p->next;
        }
        insert(p, x);
    }

    print(H);

    return 0;
}
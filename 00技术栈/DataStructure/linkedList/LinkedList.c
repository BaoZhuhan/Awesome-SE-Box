#include <stdio.h>
#include <stdlib.h>

typedef int ElementType ;

typedef struct node {
    ElementType data;
    struct node *next;
}node;

int length(node *H){
    node *p = H;
    int ans = 0 ;

    while(p){
        p = p->next;
        ans++;
    }
    return ans;
}

void output(node *H){
    node *p = H;
    while(p != NULL) {
        printf("%d " , p->data);
        p = p->next ;
    }
}

void insertH(node *H , ElementType data){
     node *now = (node*)malloc(sizeof(node));
     now->data = data;

     now->next = H;

     H = now;
}

void insertend(node *H , node *now){
    node *p = H;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = now;
}

void insert(node *pre , ElementType data){
    node *now = (node*)malloc(sizeof(node));
    now->data = data;
    now->next = pre->next;
    pre->next = now;
}

void delH(node *H){
    H = H->next;
}

void delnode(node *H , int key){
    node *tmp = H ;
    node *pre = NULL;

    if(tmp != NULL && tmp->data == key) {
        H = tmp->next ;
        return ;
    }

    while(tmp != NULL && tmp->data != key){
        pre = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL) return ;

    pre->next = tmp->next;

    return ;
}

int search(node *H , int key){
    node *tmp = H ;

    while(tmp != NULL) {
        if(tmp->data == key) {
            return 1;
        } 
        tmp = tmp->next;
    }
    return 0;
}


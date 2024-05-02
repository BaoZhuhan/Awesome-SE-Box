#define FLAG  -1
#include <stdio.h>
#include <malloc.h>
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}LNode, *LinkList;

LinkList Creat_LinkList();/*这里忽略函数的实现*/

void  pur_LinkList(LinkList L);

void Print_LinkList(LinkList L);/*这里忽略函数的实现*/


int main()
{
    LinkList L;

    L = Creat_LinkList();
    if(L == NULL)
    { 
        printf("L=NULL,error!"); 
        return 0;  
    }

    pur_LinkList(L);
    Print_LinkList(L);

    return 0;
}
/* 请在这里填写答案 */

LinkList find(LinkList start , int x){
    LinkList p = start->next;
    while(p->next && p->next->data != x){
        p = p->next;
    }
    return p;
}

void del(LinkList pre){
    pre->next = pre->next->next;
}


void pur_LinkList(LinkList L){
    LinkList p = L;
    while(p){
        while(find(p,p->data)->next != NULL){
            del(find(p,p->data));
        }
    }
}

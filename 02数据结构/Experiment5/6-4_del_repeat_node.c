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

//有头节点

void  pur_LinkList(LinkList L){
    int h[10005] = {0}; 
    LinkList p = L;

    while(p->next != NULL){
        if(h[p->next->data] == 1){
            p->next = p->next->next;
        }else{
            h[p->next->data] = 1;
            p = p->next;
        }
    }

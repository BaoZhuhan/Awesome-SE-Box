
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList Create();/* 细节在此不表 */

int CharacterCount(LinkList L);
int main()
{
    LinkList L, p;
    ElemType e;
    L = Create();
    printf("The number of numeric characters is %d.\n", CharacterCount(L));
    return 0;
}
/* 你的代码将被嵌在这里 */

int CharacterCount(LinkList L){
    if(L->next == )
}
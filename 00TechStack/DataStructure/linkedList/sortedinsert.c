#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(node *h)
{
    node *p, *cp, *ap;
    int x;
    scanf("%d", &x);

    while (x != -1)
    {
        p = (node *)malloc(sizeof(node));
        p->data = x;
        ap = NULL;
        cp = h;

        while (cp)
        {
            if (cp->data <= x)
            {
                ap = cp;
                cp = cp->next;
            }
            else
            {
                break;
            }
        }
    }
}
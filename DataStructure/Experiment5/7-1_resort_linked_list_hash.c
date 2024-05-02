#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>

#define M 100000

typedef struct node {
    int add;
    int data;
    int next;
}node;

node* createNode( int add, int data, int next ) {
    node* now = (node*)malloc( sizeof( node ) );

    now->add = add;
    now->data = data;
    now->next = next;

    return now;
}

int main() {
    int head, n;
    scanf( "%d%d", &head, &n );

    node* nodes[M] = {0};
    for (int i = 0; i < n; i++) {
        int add, data, next;
        scanf( "%d%d%d", &add, &data, &next );
        nodes[add] = createNode( add, data, next );
    }

    node* list[M];
    int cot = 0;

    int p = head;
    while (p != -1) {
        list[cot++] = nodes[p];
        p = nodes[p]->next;
    }

    int i = 0, j = cot - 1;
    while (i < j) {
        printf("%05d %d %05d\n", list[j]->add, list[j]->data, list[i]->add);
        if (i + 1 != j) {
            printf("%05d %d %05d\n", list[i]->add, list[i]->data, list[j - 1]->add);
        } else {
            printf("%05d %d -1\n", list[i]->add, list[i]->data);
        }
        i++;
        j--;
    }
    if (i == j) {
        printf("%05d %d -1\n", list[i]->add, list[i]->data);
    }
    return 0;
}

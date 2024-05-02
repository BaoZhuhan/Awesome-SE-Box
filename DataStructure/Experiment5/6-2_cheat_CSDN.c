#include <stdio.h>
#include <stdlib.h>

struct stud_node {
    int num;
    char name[20];
    int score;
    struct stud_node* next;
};

struct stud_node* createlist();
struct stud_node* deletelist( struct stud_node* head, int min_score );

int main() {
    int min_score;
    struct stud_node* p, * head = NULL;

    head = createlist();
    scanf( "%d", &min_score );
    head = deletelist( head, min_score );
    for (p = head; p != NULL; p = p->next)
        printf( "%d %s %d\n", p->num, p->name, p->score );

    return 0;
}

/* 你的代码将被嵌在这里 */

struct stud_node* createlist() {
    struct stud_node* head = NULL, * tail = NULL, * s;
    while (1) {
        s = (struct stud_node*)malloc( sizeof( struct stud_node ) );
        scanf( "%d", &s->num );
        if (s->num == 0)
            break;
        scanf( "%s", s->name );
        scanf( "%d", &s->score );
        s->next = NULL;
        if (head == NULL) {
            head = s;
        }
        else {
            tail->next = s;
        }
        tail = s;
    }
    return head;
}

struct stud_node* deletelist( struct stud_node* head, int min_score ) {
    struct stud_node* p, * s;
    while (head != NULL && head->score < min_score) {
        p = head;
        head = head->next;
        free( p );
    }
    if (head == NULL)
        return NULL;
    s = head;
    p = head->next;
    while (p != NULL) {
        if (p->score < min_score) {
            s->next = p->next;
            free( p );
        }
        else {
            s = p;
        }
        p = s->next;
    }
    return head;
}

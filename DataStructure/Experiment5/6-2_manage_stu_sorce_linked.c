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
struct stud_node* init() {
    struct stud_node* H;
    H = (struct stud_node*)malloc( sizeof( struct stud_node ) );
    H->next = NULL;
    return H;
}


struct stud_node* createlist() {
    struct stud_node* H;
    H = init();

    int num = 0;
    scanf("%d" , &num);

    struct stud_node* pre = H;

    while(num != 0){
        struct stud_node *now;
        now = (struct stud_node*)malloc(sizeof(struct stud_node));
        now->num = num;
        getchar();
        int i = 0 ;
        while((now->name[i] = getchar()) != ' '){
            i++;
        }
    
        now->name[i] = '\0';
        scanf("%d" , &now->score);


        now->next =  pre->next;
        pre->next = now;
        pre = now;

        scanf("%d" , &num);
    }

    return H;
}

struct stud_node* deletelist( struct stud_node* head, int min_score ) {
    struct stud_node *p = head;

    while(p->next != NULL){
        if(p->next->score < min_score){
            if(p->next->next != NULL)p->next = p->next->next;
            else {
                p->next = NULL;
                break;
            }
        }
        p = p->next;
    }

    return head->next;
}

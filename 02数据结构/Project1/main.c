#include <stdio.h>
#include <stdlib.h>
#include  <stdbool.h>

#define MAX_SIZE 10000

/* Define the node of a two-way linked list*/
typedef struct node {
    struct node* pre;
    struct node* next;
    char data;
} node;

void Run();/* Control function*/
node* Init();/* Init a new two-way linked list and return its pointer*/
char* GetInput();/* Get user input and return a pointer (to string)*/
node* End( node* p );/* move p to the end of the list*/
node* Left( node* p );/* move p to the left*/
node* Right( node* p );/* move p to the right*/
node* Backspace( node* p );/* Replace next node*/
node* Add( node* p, char x );/* Add new node*/
node* Replace( node* p, char x );/* Delete pre node*/
void Print( node* L );/* print the linked list*/

/* main：link to Fun: run()*/
int main() {
    Run();
    return 0;
}

/* Control function*/
void Run() {
    char* str = GetInput();

    node* L = Init();  /* L: the head pointer of linked list*/
    node* p = L;       /* p: the user cursor (update every operate)*/

    bool* flag_insert;
    flag_insert = (bool*)malloc( sizeof( bool ) );
    *flag_insert = true;  /* true : insert ; false : replace*/

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '[') { p = L; }
        else if (str[i] == ']') { p = End( p ); }
        else if (str[i] == '{') { p = Left( p ); }
        else if (str[i] == '}') { p = Right( p ); }
        else if (str[i] == '=') { p = Backspace( p ); }
        else if (str[i] == '-') { *flag_insert = (*flag_insert == true ? false : true); }
        else if (str[i] == '#') { break; }
        else {
            if (*flag_insert == true) { p = Add( p, str[i] ); }
            else { p = Replace( p, str[i] ); }
        }
    }

    Print( L );

    return;
}

/* Init a new two-way linked list and return its pointer*/
node* Init() {
    node* L;
    L = (node*)malloc( sizeof( node ) );
    L->next = NULL;
    L->pre = NULL;
    return L;
}

/* Get user input and return a pointer (to string)*/
char* GetInput() {
    char* str;
    str = (char*)malloc( MAX_SIZE * sizeof( char ) );

    int size = 0;
    while ((str[size] = getchar()) != '#') { size++; }
    str[size] = '\0';

    str = realloc( str, sizeof( char ) * (++size) ); /*free extra size*/

    return str;
}

/* move p to the end of the list*/
node* End( node* p ) {
    while (p->next != NULL) { p = p->next; }
    return p;
}

/* move p to the left*/
node* Left( node* p ) {
    if (p->pre == NULL) { return p; }
    return p->pre;
}

/* move p to the right*/
node* Right( node* p ) {
    if (p->next == NULL) { return p; }
    return p->next;
}

/* Delete pre node*/
node* Backspace( node* p ) {
    if (p->pre == NULL) return p;

    node* tmp = p;
    p = p->pre;
    p->next = p->next->next;
    if (p->next != NULL) { p->next->pre = p; }
    free( tmp );
    return p;
}

/* Add new node*/
node* Add( node* p, char x ) {
    node* now;
    now = (node*)malloc( sizeof( node ) );

    now->data = x;
    now->next = p->next;
    p->next = now;

    now->pre = p;
    if (now->next != NULL) { now->next->pre = now; }

    return now;
}

/* Replace next node*/
node* Replace( node* p, char x ) {
    if (p->next != NULL) {
        p->next->data = x;
        return p->next;
    }
    else {
        return Add( p, x );
    }
}

/* print the linked list*/
void Print( node* L ) {
    node* p = L->next;
    while (p != NULL) {
        printf( "%c", p->data );
        p = p->next;
    }
}



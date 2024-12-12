#include <bits/stdc++.h>
using namespace std;

// 链表
struct node
{
    int num;
    int score;
    struct node *next;
};

int main()
{
    struct node *head, *tail, *p;
    int n, s;
    head = tail = NULL;
    cin >> n >> s;
    while (n != 0)
    {
        p = (struct node *)malloc(sizeof(struct node)); // malloc的作用是分配一块空间
        p->num = n;
        p->score = s;

        // 尾部插入法
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }
        tail = p;
    }

    while(n != 0){
        p = (struct node*)malloc(sizeof(struct node));
        p -> num ;
        p -> score;
        //头部插入
        p->next = head;
        head = p;
    }

    for (p = head; p != NULL; p = p->next)
    {
        cout << p->num << p->score;
    }
}
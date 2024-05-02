#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct Node {
    int address;
    int data;
    int next;
} Node;

Node* createNode(int address, int data, int next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->address = address;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

int main() {
    int start, n;
    scanf("%d %d", &start, &n);
    Node* nodes[MAX_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf("%d %d %d", &address, &data, &next);
        nodes[address] = createNode(address, data, next);
    }

    Node* list[MAX_SIZE];
    int count = 0;
    while (start != -1) {
        list[count++] = nodes[start];
        start = nodes[start]->next;
    }

    int i = 0, j = count - 1;
    while (i < j) {
        printf("%05d %d %05d\n", list[j]->address, list[j]->data, list[i]->address);
        if (i + 1 != j) {
            printf("%05d %d %05d\n", list[i]->address, list[i]->data, list[j - 1]->address);
        } else {
            printf("%05d %d -1\n", list[i]->address, list[i]->data);
        }
        i++;
        j--;
    }
    if (i == j) {
        printf("%05d %d -1\n", list[i]->address, list[i]->data);
    }

    return 0;
}
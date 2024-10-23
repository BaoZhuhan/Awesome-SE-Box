// test_test.c
#include <stdio.h>
#include <assert.h>
#include "code.c"

void test_test_initNode() {
    struct node* n = initNode(10);
    assert(n != NULL);
    assert(n->weight == 10);
    assert(n->left == NULL);
    assert(n->right == NULL);
    free(n);
    printf("test_initNode tested\n");
}

void test_test_nodeCopy() {
    struct node* source = initNode(20);
    struct node* target = initNode(0);
    nodeCopy(source, target);
    assert(target->weight == 20);
    assert(target->left == NULL);
    assert(target->right == NULL);
    free(source);
    free(target);
    printf("test_nodeCopy tested\n");
}

void test_test_swapNode() {
    struct node* a = initNode(30);
    struct node* b = initNode(40);
    swapNode(a, b);
    assert(a->weight == 40);
    assert(b->weight == 30);
    free(a);
    free(b);
    printf("test_swapNode tested\n");
}

void test_test_insertNode() {
    struct node heap[3];
    heap[0] = *initNode(10);
    heap[1] = *initNode(20);
    heap[2] = *initNode(5);
    insertNode(heap, 2);
    assert(heap[0].weight == 5);
    assert(heap[1].weight == 20);
    assert(heap[2].weight == 10);
    printf("test_insertNode tested\n");
}

void test_test_deleteRoot() {
    struct node heap[3];
    heap[0] = *initNode(10);
    heap[1] = *initNode(20);
    heap[2] = *initNode(30);
    int heapSize = 3;
    deleteRoot(heap, &heapSize);
    assert(heapSize == 2);
    assert(heap[0].weight == 20);
    assert(heap[1].weight == 30);
    printf("test_deleteRoot tested\n");
}

void test_test_wwl() {
    struct node heap[5];
    heap[0] = *initNode(10);
    heap[1] = *initNode(20);
    heap[2] = *initNode(35);
    heap[3] = *initNode(45);
    heap[4] = *initNode(55);
    int heapSize = 5;
    wwl(heap, &heapSize);
    assert(heapSize == 4);
    for(int i = 0 ; i < heapSize; i++) {
        printf("%d ",heap[i].weight);
    }
    printf("\n");
    assert(heap[0].weight == 30);
    assert(heap[1].weight == 35);
    printf("test_wwl tested\n");
}

void test_test_huffmanCode() {
    int weights[] = {10, 20, 30, 40};
    int N = 4;
    char** codes = huffmanCode(weights, N);
    for (int i = 0; i < N; i++) {
        printf("Weight %d: Code %s\n", weights[i], codes[i]);
        free(codes[i]);
    }
    free(codes);
    printf("test_huffmanCode tested\n");
}

void DebugTest() {
    test_test_initNode();
    test_test_nodeCopy();
    test_test_swapNode();
    test_test_insertNode();
    test_test_deleteRoot();
    test_test_wwl();
    test_test_huffmanCode();
    printf("All tests passed!\n");
}

int main() {
    DebugTest();
    return 0;
}
/* offical */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct HuffmanTree{
    char c;
    int weight;
    struct HuffmanTree* left;
    struct HuffmanTree* right;
};



// 定义一个函数来实现层序遍历并输出权重
void LevelPrint(struct HuffmanTree *root) {
    if (root == NULL) return;

    // 初始化队列大小
    int queueSize = 100;
    struct HuffmanTree** queue = (struct HuffmanTree**)malloc(queueSize * sizeof(struct HuffmanTree*));
    int front = 0, rear = 0;

    // 将根节点入队
    queue[rear++] = root;

    // 当队列不为空时，继续遍历
    int cot = 0;
    while (front < rear && cot <= 10) {
        cot++;
        // 取出队头节点
        struct HuffmanTree* node = queue[front++];

        // 输出当前节点的权重
        printf("%d ", node->weight);

        // 如果左子树存在，则左子树入队
        if (node->left != NULL) {
            // 检查队列是否需要扩展
            if (rear >= queueSize) {
                queueSize *= 2;
                queue = (struct HuffmanTree**)realloc(queue, queueSize * sizeof(struct HuffmanTree*));
            }
            queue[rear++] = node->left;
        }

        // 如果右子树存在，则右子树入队
        if (node->right != NULL) {
            // 检查队列是否需要扩展
            if (rear >= queueSize) {
                queueSize *= 2;
                queue = (struct HuffmanTree**)realloc(queue, queueSize * sizeof(struct HuffmanTree*));
            }
            queue[rear++] = node->right;
        }
    }
    printf("\n");

    // 释放队列内存
    free(queue);
}


/* debug */

void printNode(struct HuffmanTree * node){
    if(node == NULL) {
        printf("node is NULL\n");
        return;
    }
    if(node != NULL) printf("c->%c, weight->%d, ",node->c, node->weight);
    if(node->left != NULL) printf("left->(c->%c weight->%d), ", node->left->c, node->left->weight);
    if(node->right != NULL)printf("right->(c->%c weight->%d)", node->right->c, node->right->weight);
    printf(" \n");
    
}
void printHeap(struct HuffmanTree **Heap ,int heapSize){
    static int time = 0;
    time++;
    printf("-----Print Heap Below--%d--\n",time);
    for(int i = 0 ; i < heapSize ; i++) {
        printf("Heap[%d] : ", i);
        printNode(Heap[i]);
    }
    printf("--------------------------\n");
}
#include "test.c"


struct HuffmanTree* initNode(char c, int weight, struct HuffmanTree* left, struct HuffmanTree* right){
    struct HuffmanTree* newNode = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    newNode->c = c;
    newNode->weight = weight;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}


void copyNode(struct HuffmanTree* source, struct HuffmanTree* target){
    target->c = source->c;
    target->weight = source->weight;
    target->left = source->left;
    target->right = source->right;
}

void swapNode(struct HuffmanTree* a, struct HuffmanTree* b){
    struct HuffmanTree* temp = initNode('\0', 0, NULL, NULL);
    copyNode(a, temp);
    copyNode(b, a);
    copyNode(temp, b);
    free(temp);
}


void shiftUp(struct HuffmanTree** Heap, int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(Heap[index]->weight < Heap[parent]->weight){
            swapNode(Heap[index], Heap[parent]);
        }
        index = parent;
    }
}


void shiftDown(struct HuffmanTree** Heap, int size){
    int index = 0;
    while(index * 2 + 1 < size){
        int child = index * 2 + 1;
        if(child + 1 < size && Heap[child]->weight > Heap[child + 1]->weight) child++;
        if(Heap[index]->weight <= Heap[child]->weight) break;
        swapNode(Heap[index], Heap[child]);
        index = child;
    }
}


struct HuffmanTree* CreateHuffmanTree(int n){
    struct HuffmanTree** Heap = (struct HuffmanTree**)malloc(n * sizeof(struct HuffmanTree*));

    char c;int weight;
    for(int i = 0; i < n; i++){
        scanf(" %c %d", &c, &weight); //!!!: the first blank is for '\n'
        Heap[i] = initNode(c, weight, NULL, NULL);
        shiftUp(Heap, i);
    }

    int heapSize = n;

    for(int i = 0; i < n - 1; i++){
        /* original fun : wwl */
        struct HuffmanTree* nodeA = initNode('\0', 0, NULL, NULL);
        struct HuffmanTree* nodeB = initNode('\0', 0, NULL, NULL);

        copyNode(Heap[0], nodeA);
        swapNode(Heap[0], Heap[--heapSize]);
        shiftDown(Heap, heapSize);

        copyNode(Heap[0], nodeB);
        swapNode(Heap[0], Heap[--heapSize]);
        shiftDown(Heap, heapSize);

        struct HuffmanTree* nodeSum = initNode('\0', nodeA->weight + nodeB->weight, nodeA, nodeB);
        Heap[heapSize] = nodeSum;
        shiftUp(Heap, heapSize++);       
    }

    struct HuffmanTree* root = Heap[0];
    free(Heap);
    return root;
}


struct CodeTable {
    char c;
    char code[256];
};


int compare(const void* a, const void* b) {
    struct CodeTable* codeA = (struct CodeTable*)a;
    struct CodeTable* codeB = (struct CodeTable*)b;
    return codeA->c - codeB->c;
}


void generateCodes(struct HuffmanTree* root, struct CodeTable* table, int* index, char* path, int pathLen) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        table[*index].c = root->c;
        path[pathLen] = '\0';
        strcpy(table[*index].code, path);
        (*index)++;
        return;
    }

    path[pathLen] = '0';
    generateCodes(root->left, table, index, path, pathLen + 1);
    path[pathLen] = '1';
    generateCodes(root->right, table, index, path, pathLen + 1);
}

void HuffmanCoding(struct HuffmanTree* root, int n) {
    struct CodeTable* table = (struct CodeTable*)malloc(n * sizeof(struct CodeTable));
    int index = 0;
    char path[256];

    generateCodes(root, table, &index, path, 0);
    
    qsort(table, n, sizeof(struct CodeTable), compare);
    
    for (int i = 0; i < n; i++) {
        printf("\n%c:%s", table[i].c, table[i].code);
    }

    free(table);
}
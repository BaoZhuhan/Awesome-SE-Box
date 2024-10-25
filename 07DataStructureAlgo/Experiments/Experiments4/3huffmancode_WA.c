#include <string.h>

struct node{
    int weight;
    struct node* left;
    struct node* right;
};

/* init a node with weight */
/* DEBUG: correct the pointer */
struct node* initNode(int weight){
    struct node* now = (struct node*)malloc(sizeof(struct node));
    now->weight = weight;
    now->left = NULL;
    now->right = NULL;
    return now;
}

/* copy node by value */
/* DEBUG: fix the fucking Segment error when source or target is NULL */
void nodeCopy(struct node* source, struct node* target){
    if(target == NULL){
        return;
    }
    if(source == NULL){
        target->weight = 0;
        target->left = NULL;
        target->right = NULL;
        return;
    }
    target->weight = source->weight;
    target->left = source->left;
    target->right = source->right;
}

/* swap node by value */
/* DEBUG: using fun */
void swapNode(struct node* a, struct node* b){
    struct node* temp = initNode(0);
    nodeCopy(a, temp);
    nodeCopy(b, a);
    nodeCopy(temp, b);
    free(temp);
}

/* insert node into heap */
/* DEBUG: using mode */
void insertNode(struct node* heap, int size){
    //the insert value was already inside, at loc heap[size].
    /* shift up */
    while(size > 0){
        int parent = (size - 1) / 2;
        if(heap[parent].weight > heap[size].weight){
            swapNode(&heap[parent],&heap[size]);
            size = parent;
        }else{
            break;
        }
    }
    //size++ (useless code)
}

/* delete the top of the heap*/
void deleteRoot(struct node* heap, int* heapSize){
    if(heap == NULL || *heapSize <= 0) {
        printf("ERRORd1\n");
    }
    if(*heapSize == 1) {
        return;
    }

    nodeCopy(&heap[*heapSize-1],&heap[0]);
    *heapSize -= 1;
    //shift down
    int index = 0; int child = 2*index + 1;
    while(child  < *heapSize){
        if(child + 1 < *heapSize && heap[child].weight > heap[child + 1].weight){
            child++;
        }
        if(heap[index].weight > heap[child].weight){
            swapNode(&heap[index], &heap[child]);
        }
        index = child;
        child = 2*index + 1;
    }
}

/* pop 2 node and insert their sum */
void wwl(struct node* heap, int* heapSize){
    struct node* node1 = initNode(0);
    struct node* node2 = initNode(0);
    struct node* sumNode = initNode(0);

    if(*heapSize == 2){
        nodeCopy(&heap[0],node1);
        nodeCopy(&heap[1],node2);
        struct node* mi = node1->weight > node2->weight ? node2 : node1;
        struct node* mx = node1->weight > node2->weight ? node1 : node2;
        sumNode->weight = node1->weight + node2->weight;
        sumNode->left = mi;
        sumNode->right = mx;
        nodeCopy(sumNode, &heap[0]);
        *heapSize = 1;
        return;
    }

    nodeCopy(&heap[0], node1);
    deleteRoot(heap, heapSize);
    nodeCopy(&heap[0], node2);
    deleteRoot(heap, heapSize);

    sumNode->weight = node1->weight + node2->weight;
    sumNode->left = node1;
    sumNode->right = node2;

    nodeCopy(sumNode, &heap[*heapSize]);
    *heapSize += 1;
    insertNode(heap, *heapSize-1);
}


// Helper function to recursively generate Huffman codes
void generateHuffmanCode(struct node* root, char** res, char* code, int depth, int original[], int N , int visit[]) {
    if (root->left == NULL && root->right == NULL) {
        // Leaf node: find the original weight and map it to the correct index
        int index = -1;
        for (int i = 0; i < N; i++) {
            if (original[i] == root->weight && visit[i] == 0) {
                index = i;
                visit[i] = 1;
                break;
            }
        }
        code[depth] = '\0';  // Null-terminate the string
        res[index] = (char*)malloc((depth + 1) * sizeof(char));
        strcpy(res[index], code);  // Copy the code to the result array
        return;
    }
    if (root->left != NULL) {
        code[depth] = '0';
        generateHuffmanCode(root->left, res, code, depth + 1, original, N, visit);
    }
    if (root->right != NULL) {
        code[depth] = '1';
        generateHuffmanCode(root->right, res, code, depth + 1, original, N, visit);
    }
}

char** get_huffmancode(struct node* huffmanTree, int original[], int N) {
    // Allocate space for the result
    char** res = (char**)malloc(N * sizeof(char*));
    
    // Maximum possible depth of a Huffman code is N-1 (when tree is linear)
    char* code = (char*)malloc(N * sizeof(char));
    int *visit = (int*)malloc(N*sizeof(int));
    memset(visit,0,N);
    // Generate Huffman codes starting from the root of the tree
    generateHuffmanCode(huffmanTree, res, code, 0, original, N, visit);
    
    free(code);  // Free temporary storage for code
    return res;
}

int huffmancmp(const void *a, const void *b) {
    // Cast the void pointers to char** and then dereference them to get the actual strings
    const char* strA = *(const char**)a;
    const char* strB = *(const char**)b;

    // Compare by length first
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    
    if (lenA == lenB) {
        // If lengths are the same, compare by binary value (lexicographically for binary strings)
        return strcmp(strA, strB);
    }
    // Otherwise, compare by length
    return lenB - lenA;
}

int numcmp(const void *a ,const void *b){
    return *(int*)a-*(int*)b;
}


/* main fun */
char** huffmanCode(int w[], int N){
    if(N == 1){
        char **res = (char**)malloc(sizeof(char*));
        res[0] = (char*)malloc(2*sizeof(char));
        res[0][0] = '0' , res[0][1] = '\0';
        return res;
    }

    // qsort(w,N,sizeof(int),numcmp);

    /* init heap and turn int array into node array. */
    struct node* heap = (struct node*)malloc(N * sizeof(struct node));
    for(int i = 0; i < N; i++){
        heap[i] = *(initNode(w[i]));
    }

    /* insert heap by update size. */
    for(int i = 0; i < N; i++){
        insertNode(heap, i);
    }

    /* Maintain a heap size */
    int *heapSize = (int*)malloc(sizeof(int));
    *heapSize = N;

    /* Build Huffman Tree */
    while(*heapSize > 1){
        wwl(heap, heapSize);
    }

    // for(int i = 0 ; i < 2; i++) {
    //     printf("heap[%d]->%d\n",i,heap[i].weight);
    //     if(heap[i].left != NULL) printf("heap[%d]->left->%d\n",i,heap[i].left->weight);
    //     if(heap[i].right != NULL) printf("heap[%d]->right->%d\n",i,heap[i].right->weight);
    // }

    struct node* huffmanTree = &heap[0];

    //TODO: Finish the huffman tree output
    char ** huffmanCode = get_huffmancode(huffmanTree,w,N);
    // qsort(huffmanCode,N,sizeof(char*),huffmancmp);
    free(heap);
    free(heapSize);
    return huffmanCode;
}

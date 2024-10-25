#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int* w, int* visit, int size){
    int index = -1;
    for(int i = 0; i < size; i++){
        if(visit[i] == 1) continue;
        if(index == -1 || w[i] < w[index]){
            index = i;
        }
    }
    return index;
}

void initHuffman(int** weights, int** parents, int** left, int** right, int** visit, int* w, int N){
    *weights = (int*)malloc((N * 2 - 1) * sizeof(int));
    *parents = (int*)malloc((N * 2 - 1) * sizeof(int));
    *left = (int*)malloc((N * 2 - 1) * sizeof(int));
    *right = (int*)malloc((N * 2 - 1) * sizeof(int));
    *visit = (int*)malloc((N * 2 - 1) * sizeof(int));

    memset(*weights, 0, (N * 2 - 1) * sizeof(int));
    memset(*parents, 0, (N * 2 - 1) * sizeof(int));
    memset(*left, 0, (N * 2 - 1) * sizeof(int));
    memset(*right, 0, (N * 2 - 1) * sizeof(int));
    memset(*visit, 0, (N * 2 - 1) * sizeof(int));

    for(int i = 0; i < N; i++){
        (*weights)[i] = w[i];
    }
}

void BuildHuffman(int* weights, int* parents, int* left, int* right, int* visit, int* w, int* size){
    int loc_min1 = findMin(weights, visit, *size);
    visit[loc_min1] = 1;
    int loc_min2 = findMin(weights, visit, *size);
    visit[loc_min2] = 1;
    weights[*size] = weights[loc_min1] + weights[loc_min2];
    parents[loc_min1] = *size;
    parents[loc_min2] = *size;
    left[*size] = loc_min1;
    right[*size] = loc_min2;
    *size += 1;
}

void getHuffmanCode(char** code, int target, int* weights, int* parents, int* left, int* right, int N){
    char* temp = (char*)malloc((N+5) * sizeof(char));
    int len = 0;
    int loc = target;
    int parent = parents[loc];
    while(parent != 0){
        if(left[parent] == loc){
            temp[len++] = '0';
        }else{
            temp[len++] = '1';
        }
        loc = parent;
        parent = parents[loc];
    }
    *code = (char*)malloc((len+1) * sizeof(char));
    for(int i = 0 ; i < len ; i++) {
        (*code)[i] = temp[len - i - 1];
    }
    (*code)[len] = '\0';
    free(temp);
}

char** huffmanCode(int w[], int N){
    int *weights, *parents, *left, *right, *visit;
    initHuffman(&weights, &parents, &left, &right, &visit, w, N);

    int size = N;
    for(int i = 0; i < N - 1; i++){
        BuildHuffman(weights, parents, left, right, visit, w, &size);
    }
   
    char **huffmanCodes = (char**)malloc(N * sizeof(char*));
    
    for(int i = 0 ; i < N; i++) {
        getHuffmanCode(&huffmanCodes[i], i, weights, parents, left, right, N);
    }

    free(weights);
    free(parents);
    free(left);
    free(right);
    free(visit);

    return huffmanCodes;
}
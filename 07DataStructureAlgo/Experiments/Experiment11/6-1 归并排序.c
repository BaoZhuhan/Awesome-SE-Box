void Merge(SqList L, int low, int m, int high) {
    int tempSize = high - low + 1;
    int *temp = (int *)malloc(tempSize * sizeof(int));
    int i = low, j = m + 1, k = 0;
    while (i <= m && j <= high) {
        if (L.elem[i] <= L.elem[j]) {
            temp[k++] = L.elem[i++];
        } else {
            temp[k++] = L.elem[j++];
        }
    }
    while (i <= m) {
        temp[k++] = L.elem[i++];
    }
    while (j <= high) {
        temp[k++] = L.elem[j++];
    }
    for (k = 0; k < tempSize; k++) {
        L.elem[low + k] = temp[k];
    }
    free(temp);
}
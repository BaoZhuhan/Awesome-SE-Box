#include <stdio.h>
#include <stdlib.h>

int Median3(int A[], int left, int right){
    int center = (left + right) >> 1;

    if(A[left] > A[center]){ swap(&A[left], &A[center]); }
    if(A[left] > A[right]){ swap(&A[left], &A[right]); }
    if(A[center] > A[right]){ swap(&A[center], &A[right]); }

    swap(&A[center], &A[right - 1]);

    return A[right - 1];
}

void QSort(int A[], int left, int right){
    int pivot = Median3(A, left, right);
    int low = left;
    int high = right - 1;

    while(1){
        while(A[++low] < pivot);
        while(A[--high] > pivot);
        if(low < high) swap(&A[low], &A[high]);
        else break;
    }

    swap(&A[low], &A[high]);
    QSort(A, left, low - 1);
    QSort(A, low + 1, right);
}

void QuickSort(int A[], int N){
    Qsort(A, 0, N - 1);
}

int main(){
    
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int nums[], int size){
    for(int i = size - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

void selection_sort(int nums[], int size){
    for(int i = 0; i < size - 1; i++){
        int p_min = i;
        for(int j = i + 1; j < size; j++){
            p_min = (nums[p_min] < nums[j] ? p_min : j);
        }
        swap(&nums[i], &nums[p_min]);
    }
}

void insert_sort(int nums[], int size){
    for(int i = 1; i < size; i++){
        int base = nums[i], j = i - 1;
        while(j >= 0 && nums[j] > base){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

void bucket_sort(int nums[],int size){
    
}

int main(){
    int size_a;
    scanf("%d", &size_a);

    int* a = (int*)malloc(size_a * sizeof(int));

    for(int i = 0; i < size_a; i++){
        scanf("%d", &a[i]);
    }

    int choice = -1;
    scanf("%d", &choice);

    switch(choice){
    case 1:bubble_sort(a, size_a);break;
    case 2:selection_sort(a, size_a);break;
    case 3:insert_sort(a, size_a);break;
    }

    for(int i = 0; i < size_a; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

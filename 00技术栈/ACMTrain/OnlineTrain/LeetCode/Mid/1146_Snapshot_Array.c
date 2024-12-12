#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int first;
    int second;
} Element;

typedef struct{
    int snap_cnt;
    int length;
    int* col_size;
    int* capability;
    Element** data;
} SnapshotArray;

#define MIN_ARRAY_SIZE 64

SnapshotArray* snapshotArrayCreate(int length){
    SnapshotArray* obj = (SnapshotArray*)malloc(sizeof(SnapshotArray));
    obj->snap_cnt = 0;
    obj->length = length;
    obj->data = (Element**)malloc(sizeof(Element*) * length);
    obj->col_size = (int*)malloc(sizeof(int) * length);
    obj->capability = (int*)malloc(sizeof(int*) * length);

    for(int i = 0; i < length; i++){
        obj->data[i] = NULL;
        obj->col_size[i] = 0;
        obj->capability[i] = MIN_ARRAY_SIZE;
    }

    return obj;

}

void snapshotArraySet(SnapshotArray* obj, int index, int val){
    if(obj->col_size[index] == 0){
        obj->data[index] = (Element*)malloc(sizeof(Element) * obj->capability[index]);
    }
    else if(obj->col_size[index] == obj->capability[index]){
        obj->capability[index] *= 2;
        Element* arr = (Element*)malloc(sizeof(Element) * obj->capability[index]);
        memcpy(arr, obj->data[index], sizeof(Element) * obj->col_size[index]);
        free(obj->data[index]);
        obj->data[index] = arr;
    }
    obj->data[index][obj->col_size[index]].first = obj->snap_cnt;
    obj->data[index][obj->col_size[index]].second = val;
    obj->col_size[index]++;
}

int snapshotArraySnap(SnapshotArray* obj){
    return obj->snap_cnt++;
}

int binarySearch(int index, int snap_id, SnapshotArray* obj){
    int low = 0, high = obj->col_size[index];
    while(low < high){
        int mid = low + (high - low) / 2;
        int x = obj->data[index][mid].first;
        int y = obj->data[index][mid].second;
        if(x > snap_id + 1 || (x == snap_id + 1 && y >= 0)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id){
    int x = binarySearch(index , snap_id , obj);
    return x == 0 ? 0 : obj->data[index][x-1].second;
}

void snapshotArrayFree(SnapshotArray* obj){
    for(int i = 0; i < obj->length;i++){
        free(obj->data[i]);
    }
    free(obj->data);
    free(obj->col_size);
    free(obj->capability);
    free(obj);
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);

 * int param_2 = snapshotArraySnap(obj);

 * int param_3 = snapshotArrayGet(obj, index, snap_id);

 * snapshotArrayFree(obj);
*/
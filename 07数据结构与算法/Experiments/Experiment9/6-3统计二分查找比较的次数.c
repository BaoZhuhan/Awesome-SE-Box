#include "test.c"
typedef int Position;
int bi_searchSq(SqList L, ElemType x) {
    int res = 0;
    Position left = 0;
    Position right = L.len - 1;
    while (left <= right) {
        Position mid = left + (right - left) / 2;
        res++;
        if (L.data[mid] < x)
            left = mid + 1;
        else if (L.data[mid] > x)
            right = mid - 1;
        else
            return res;     
    }
    return res;
}
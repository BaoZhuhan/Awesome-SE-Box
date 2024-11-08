#include "test.h"

bool testPair(int origin, int target, int Seq[], int length) {
    bool flag = 0;
    for (int i = 0; i < length; i++) {
        if (Seq[i] == origin)
            flag = 1;
        if (Seq[i] == target && flag == 0)
            return 0;
    }
    return 1;
}

bool IsTopSeq(LGraph Graph, Vertex Seq[]) {
    int length = Graph->Nv;
    for (int i = 0; i < Graph->Nv; i++) {
        Seq[i]--;
    }
    for (int i = 0; i < length; i++) {
        struct AdjVNode *ptr = Graph->G[i].FirstEdge;
        while (ptr != NULL) {
            if (testPair(i, ptr->AdjV, Seq, length) == 0)
                return 0;
            ptr = ptr->Next;
        }
    }
    return 1;
}
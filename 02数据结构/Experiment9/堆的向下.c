void PercolateDown(int p, PriorityQueue H){
    int  child;
    ElementType  Tmp = H->Elements[p];
    for(; p * 2 <= H->Size; p = child){
        child = p * 2;
        if(child != H->Size && H->Elements[child] < H->Elements[child + 1])
            child++;
        if(H->Elements[child] > Tmp)
            H->Elements[p] = H->Elements[child];
        else  break;
    }
    H->Elements[p] = Tmp;
}
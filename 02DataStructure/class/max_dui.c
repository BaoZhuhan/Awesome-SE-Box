void insert(MaxHeap H , int item){
    int i ;
    if(IsFull(H)){
        printf("full");
        return;
    }
    i = ++H->Size;
    for(; H->Elements[i/2] < item; i/= 2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] 
}
/// @brief insert x into an array
/// @param L 
/// @param X 
/// @return 
bool Insert(List L, ElementType X) {
    if (L->Last == MAXSIZE - 1)
        return false;
    int index = 0; // the loc should be
    for (; index < L->Last; index++) {
        if (L->Data[index] == X)
            return false;
        if (L->Data[index] < X)
            break;
        if (index == L->Last-1) index++;
    }
    for (int i = L->Last; i >= index; i--) {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[index] = X;
    L->Last++;
    return true;
}
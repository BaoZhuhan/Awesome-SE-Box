#include "code.c"

int main()
{
    int n;
    struct HuffmanTree *ht;
    scanf("%d",&n);
    ht = CreateHuffmanTree(n);
    LevelPrint(ht);
    HuffmanCoding(ht,n);
    return 0;    
}
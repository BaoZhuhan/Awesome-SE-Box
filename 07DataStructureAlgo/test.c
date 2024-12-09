#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
void  MergeSort(SqList L,int low,int high);
void Merge(SqList L,int low,int m,int high); 
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  MergeSort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
   {        
      printf("%d ",L.elem[i]);
   }
  return 0;
}
void MergeSort(SqList L,int low,int high)  
{     
    /*用分治法进行二路归并排序*/  
    int mid;  
    if(low<high)  /*区间长度大于1*/
    {      
        mid=(low+high)/2;               /*分解*/
        MergeSort(L,low,mid);           /*递归地对low到mid序列排序 */ 
        MergeSort(L,mid+1,high);        /*递归地对mid+1到high序列排序 */ 
        Merge(L,low,mid,high);          /*归并*/  
    }  
}
/*你的代码将被嵌在这里 */
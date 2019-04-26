#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}
//大小堆都是向下调整
//小堆
void HeapAdjustDown_small(int *arr,int size,int pParent)
{
  assert(arr);
  int min_child = pParent*2+1;
  while(min_child<size)
  {
    if((min_child+1)<size && arr[min_child]>arr[min_child+1])
      min_child += 1;
    if(arr[pParent]>arr[min_child])
      Swap(&arr[pParent],&arr[min_child]);
    else 
      break;
    pParent = min_child;
    min_child = pParent*2+1;
  }
}

//大堆
void HeapAdjustDown_big(int *arr,int size,int pParent)
{
  assert(arr);
  int max_child = pParent*2+1;
  while(max_child<size)
  {
    if((max_child+1)<size && arr[max_child]<arr[max_child+1])
      max_child += 1;
    if(arr[pParent]<arr[max_child])
      Swap(&arr[pParent],&arr[max_child]);
    else 
      break;
    pParent = max_child;
    max_child = pParent*2 + 1;
  }
}
//获取堆顶元素
int HeapTop(int *arr)
{
  return arr[0];
}

void HeapAdjustUp(int *arr,int child)
{
  int parent = (child-1)>>2;
  while(child != 0)
  {
    if(arr[parent]>arr[child])
      Swap(&arr[parent],&arr[child]);
    else 
      break;
    child = parent;
    parent = (child-1)>>2;
  }
}

//插入：向上调整
int * HeapInsert(int *arr,int size,int data)
{
  //1.将元素放入堆
  ++size;
  int *Newarr = (int *)malloc(sizeof(int)*size);
  assert(Newarr);
  int i = 0;
  for(;i<size-1;i++)
    Newarr[i] = arr[i];
  Newarr[size-1] = data;
  //2.对堆进行向上调整
   HeapAdjustUp(Newarr,size-1);
   return Newarr;
}


//堆的删除（一般删除堆顶元素）
//void HeapRemove(int *arr,int )
//{
//  ;
//}
void HeapPrint(int *arr,int size)
{
  assert(arr);
  int i = 0;
  for(;i<size;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {53,17,78,9,45,65,87,23,31};
  int size = sizeof(arr)/sizeof(arr[0]);
  int i = 0;
  HeapPrint(arr,size);
  for(i = (size-2)/2;i>=0;i--)
    HeapAdjustDown_small(arr,size,i);
  HeapPrint(arr,size);
  int *Newarr = HeapInsert(arr,size,6);
  HeapPrint(Newarr,10);
  return 0;
}

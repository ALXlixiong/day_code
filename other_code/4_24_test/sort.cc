#include<stdio.h>
#include<stdlib.h>

void Swap(int *p1,int *p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void BubbleSort(int *arr,int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int flag = 0;
    int j = 0;
    for(;j<size-i-1;j++)
    {
      if(arr[j+1]<arr[j]){
        Swap(&arr[j+1],&arr[j]);
        flag = 1;
      }
    }
    if(flag == 0)
      break;
  }
}

void InsertSort(int *arr,int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int end = i-1;
    int key = arr[i];
    while(end>=0 && key<arr[end])
    {
      arr[end+1] = arr[end];
      end--;
    }
    arr[end+1] = key;
  }
}

void BInsertSort(int *arr,int size)
{
  int i = 1;
  for(;i<size;i++)
  {
    int left = 0;
    int right = i-1;
    int key = arr[i];
    int end = i-1;
    //[left,right]
    while(left<=right)
    {
      int mid = left + ((right-left)>>1);
      if(arr[mid]<key)
        left = mid+1;
      else if(arr[mid]>key)
        right = mid-1;
      else 
      {
        right = mid;
        break;
      }
    }
    //最终要插入的位置就是right+1
    while(end>right)
    {
      arr[end+1] = arr[end];
      end--;
    }
    arr[end+1] = key;
  }
}

void ShellSort(int *arr,int size)
{
  int gap = size/3+1;
  while(1)
  {
    gap = gap/3+1;
    int i = 0;
    for(i = gap;i<size;i++)
    {
      int end = i-gap;
      int key = arr[i];
      while(end>=0 && arr[end]>key)
      {
        arr[end+gap] = arr[end];
        end -=gap;
      }
      arr[end+gap] = key;
    }
    if(gap == 1)
      break;
  }
}

void Print(int *arr,int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void SelectSort(int *arr,int size)
{
  int i = 0;
  for(;i<size;i++)
  {
    int max = 0;
    int j = 1;
    for(;j<size-i;j++)
    {
      if(arr[max]<arr[j])
        max = j;
    }
    if(max != size-i-1)
      Swap(&arr[max],&arr[size-i-1]);
  }
}

void SelectSortTwo(int *arr,int size)
{
  int left = 0;
  int right = size-1;
  while(left<right)
  {
    int minPos = left;
    int maxPos = left;
    int index = left;
    while(index<=right)
    {
      if(arr[minPos]>arr[index])
        minPos = index;
      if(arr[maxPos]<arr[index])
        maxPos = index;
      index++;
    }
    Swap(&arr[minPos],&arr[left]);
    if(maxPos == left)
      maxPos = minPos;
    Swap(&arr[maxPos],&arr[right]);
    left++;
    right--;
  }
}

void AdjustDown(int *arr,int size,int parent)
{
  int max_child = parent*2+1;
  while(max_child<size)
  {
    if(max_child+1<size && arr[max_child+1]>arr[max_child])
      max_child +=1;
    if(arr[parent]<arr[max_child])
      Swap(&arr[parent],&arr[max_child]);
    else 
      return;
    parent = max_child;
    max_child = parent*2+1;
  }
}

void HeapSort(int *arr,int size)
{
  int root = (size-2)/2;
  for(;root>=0;root--)
    AdjustDown(arr,size,root);
  
  int end = size-1;
  while(end>0)
  {
    Swap(&arr[0],&arr[end]);
    AdjustDown(arr,end,0);
    end--;
  }
}

int Partion1(int *arr,int left,int right)
{
  int start = left;
  int end = right;//end不可以等于right-1；如6，7，8，会导致7和8交换
  int key = arr[right];
  while(start<end)
  {
    //基准值取最右边，先要走左边，在走右边，如：1，4，5，6，7，2；导致2和1交换
    while(start<end && arr[start]<=key)//不可一世arr[start]<key;容易导致死循环，如1，1，1，1，1
      start++;
    while(start<end && arr[end]>=key)
      end--;
    if(start<end)
      Swap(&arr[start],&arr[end]);
  }
  if(start != right)
    Swap(&arr[start],&arr[right]);
  return start;
}

//挖坑法
int Partion2(int *arr,int left,int right)
{
  int start = left;
  int end = right;
  int key = arr[right];
  while(start<end)
  {
    while(start<end && arr[start]<=key)
      start++;
    arr[end] = arr[start];
    while(start<end && arr[end]>=key)
      end--;
    arr[start] = arr[end];
  }
  arr[start] = key;
  return start;
}

//前后指针
int Partion3(int *arr,int left,int right)
{
  int prev = left;
  int cur = left;
  for(;cur<right;cur++)
  {
    if(arr[cur]<=arr[right])
    {
      if(cur != prev)
        Swap(&arr[cur],&arr[prev]);
      prev++;
    }
  }
  Swap(&arr[prev],&arr[right]);
  return prev;
}

void _QuickSort(int *arr,int left,int right)
{
  //[]
  //区间内只剩一个数或者没有数字，退出
  if(left >= right)
    return;
  int mid = Partion3(arr,left,right);
  _QuickSort(arr,left,mid-1);
  _QuickSort(arr,mid+1,right);
}

void QuickSort(int *arr,int size)
{
  _QuickSort(arr,0,size-1);
}

#include<assert.h>
#include<malloc.h>

void Merge(int *arr,int left,int mid,int right,int *extra)
{
  int left_index = left;
  int right_index = mid;
  int extra_index = left;
  while(left_index<mid && right_index<right)
  {
    if(arr[left_index]<=arr[right_index])
      extra[extra_index++] = arr[left_index++];
    else 
      extra[extra_index++] = arr[right_index++];
  }
  while(left_index<mid)
  {
    extra[extra_index++] = arr[left_index++];
  }
  while(right_index<right)
  {
    extra[extra_index++] = arr[right_index++];
  }
  
  int i = 0;
  for(i = left;i<right;i++)
  {
    arr[i] = extra[i];
  }
}

void _MergeSort(int *arr,int left,int right,int *extra)
{
  //区间只剩一个元素
  if(left+1 == right)
    return;
  //区间没有元素
  if(left>=right)
    return;
  int div = left + ((right-left)>>1);
  //分组
  _MergeSort(arr,left,div,extra);
  _MergeSort(arr,div,right,extra);
  //合并
  Merge(arr,left,div,right,extra);
}

void MergeSort(int *arr,int size)
{
  //[left,right)
  int *extra = (int *)malloc(sizeof(int)*size);
  assert(extra);
  _MergeSort(arr,0,size,extra);
  free(extra);
}


int main()
{
  int arr[] = {10,3,4,3,1,0,9,5,7,8,4,7,2,12};
  //int arr[] = {4};
  int size = sizeof(arr)/sizeof(int);
  Print(arr,size);
  //BubbleSort(arr,size);
  //InsertSort(arr,size);
  //BInsertSort(arr,size);
  // ShellSort(arr,size);
  //SelectSort(arr,size);
  //SelectSortTwo(arr,size);
  //HeapSort(arr,size);
  //QuickSort(arr,size);
  MergeSort(arr,size);
  Print(arr,size);
  return 0;
}

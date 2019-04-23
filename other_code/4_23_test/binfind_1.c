//[)
#include<stdio.h>


void BinFind_1(int *arr,int size,int key)
{
  int left = 0;
  int right = size;
  //半开半闭区间【left,right）当left不等于right这种里面有一个元素，否则两者还有一个元素
  while(left<right)
  {
    int mid = left + ((right-left)>>1);
    if(arr[mid] == key)
    {
      printf("找到了key = %d arr[mid] = %d\n",key,arr[mid]);
      return;
    }
    else if(arr[mid]<key)
      left = mid+1;
    else 
      right = mid;
  }
  printf("没找到\n");
}
//【】
void BinFind_2(int *arr,int size,int key)
{
  int left = 0;
  int right = size-1;
  while(left<=right)
  {
    int mid = left + ((right-left)>>1);
    if(arr[mid] == key)
    {
      printf("找到了key = %d arr[mid] = %d\n",key,arr[mid]);
      return;
    }
    else if(arr[mid]>key)
      right = mid-1;
    else 
      left = mid+1;
  }
  printf("没找到\n");
}


int main()
{
  int arr[] = {1,3,6,9,12,13,13,24,55};
  int size = sizeof(arr)/sizeof(arr[0]);
  BinFind_2(arr,size,55);
  return 0;
}

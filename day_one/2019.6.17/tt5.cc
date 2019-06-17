#include<stdio.h>
#include<malloc.h>
 
 
int fun(int *arr_1,int *arr_2,int len)
{
  int i = 0;
  for(;i<len;i++)
  {
    arr_2[i] = 1;
  }
 
  for(i = 0;i<len;i++)
  {
    int j = 0;
    for(;j<=i;j++)
    {
      if(arr_1[j]< arr_1[i])
      {
        arr_2[i] = arr_2[j]+1;
      }
    }
  }
  int max = 0;
  for(i = 0;i<len;i++)
  {
    printf("%d ",arr_2[i]);
    if(arr_2[i]>max)
    {
      max = arr_2[i];
    }
  }
  printf("\n");
  return max;
}
 
 
 
int main()
{
  int arr_1[] = {1,7,3,5,9,4,8};
  int len = sizeof(arr_1)/sizeof(int);
  int *arr_2 = (int *)malloc(sizeof(int)*len);
  int res = fun(arr_1,arr_2,len);
  printf("res = %d\n",res);
  return 0;
}

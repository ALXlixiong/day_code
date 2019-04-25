#include<iostream>
#include<vector>
//插入排序
//最好O(N)
//最坏O(N^2)
//可以采用二分查找
void InsertSort(std::vector<int> &v)
{
  int end = 0;
  for(size_t i =1;i<v.size();++i)
  {
    end = i-1;
    int key = v[i];
    while(end>=0)
    {
      if(key<v[end])
      {
        v[end+1] = v[end];
        --end;
      }
      else 
        break;
    }
    v[end+1] = key;
  }
}

int BinaryFind(std::vector<int> v,int key,int end)
{
  int begin = 0;
  while(begin<=end)
  {
    int mid = begin+((end-begin)>>1);
    if(v[mid] == key)
      return mid;
    else if(v[mid]>key)
      end = mid-1;
    else 
      begin = mid+1;
  }
  return begin;
}
void InsertBinSort(std::vector<int> &v)
{
  int end = 0;
  for(size_t i = 0;i<v.size();++i)
  {
    end = i-1;
    int key = v[i];
    if(end == -1)
    {
      v[end+1] = key;
      continue;
    }
    int index = BinaryFind(v,key,end);
    while(end != index)
    {
      v[end+1] = v[end];
      --end;
    }
    v[index+1] = key;
  }
}

void Print(std::vector<int> v)
{
  for(auto i = 0;i<v.size();++i)
    std::cout<<v[i]<<" ";
  std::cout<<std::endl;
}

void ShellSort(std::vector<int> &v)
{
  size_t gap = v.size();
  while(gap != 1)
  {
    gap = gap/3 + 1;
    for(size_t i = gap;i<v.size();i = i+gap)
    {
      int key = v[i];
      int end = i-gap;
      while(end>=0)
      {
        if(v[end]>key)
        {
          v[end+gap] = v[end];
          end = end-gap;
        }
        else 
          break;
      }
      v[end+gap] = key;
    }
  }
}

void SelectSort(std::vector<int> &v)
{
  size_t end = v.size()-1;

  while(end != 0)
  {
    size_t max = 0;
    for(size_t i = 0;i<=end;++i)
    {
      if(v[max]<v[i])
        max = i;
    }
    if(max != end)
    {
      size_t tmp = v[max];
      v[max] = v[end];
      v[end] = tmp;
    }
    --end;
  }
}

void Swap(int &left,int &right)
{
  int tmp = left;
  left = right;
  right = tmp;
}
void SelectTwoSort(std::vector<int> &v)
{
  int begin = 0;
  int end = v.size()-1;
  while(begin<end)
  {
    int minPos = begin;
    int maxPos = begin;
    for(int i = begin;i<=end;++i)
    {
      if(v[minPos]>v[i])
        minPos = i;
      if(v[maxPos]<v[i])
        maxPos = i;
    }
    if(begin != minPos)
    {
      if(maxPos == begin)
        maxPos = minPos;
      Swap(v[begin],v[minPos]);
    }
    if(end != maxPos)
      Swap(v[end],v[maxPos]);
    --end;++begin;
  }
}
void AdjustDown(std::vector<int> &v,int index,int root)
{
  size_t leftChild = (root<<1)+1;
  while(leftChild<(v.size()-index-1))
  {
    size_t rightChild = leftChild+1;
    int maxChild = leftChild;
    if(rightChild<(v.size()-index-1) && v[maxChild]<v[rightChild])
      maxChild = rightChild;
    if(v[root]<v[maxChild])
      Swap(v[root],v[maxChild]);
    else 
      break;
    root = maxChild;
    leftChild = (root<<1)+1;
  }
}
void CreateHeap(std::vector<int> &v,int parent)
{
  AdjustDown(v,0,parent);
}
void HeapSort(std::vector<int> &v)
{
  for(int i = (v.size()-2)>>1;i>=0;--i)
    CreateHeap(v,i);
  for(size_t i = 0;i<v.size();++i)
  {
    Swap(v[0],v[v.size()-1-i]);
    AdjustDown(v,i,0);
  }
}
void BubbleSort(std::vector<int> &v)
{
  for(size_t i = 0;i<v.size();++i)
  {
    bool flag = false;
    for(size_t j = 0;j<v.size()-1-i;++j)
    {
      if(v[j]>v[j+1])
      {
        Swap(v[j],v[j+1]);
        flag = true;
      }
    }
    if(flag == false)
      break;
  }
}

int Partition_1(std::vector<int> &v,int left,int right)
{
  int begin = left;//此处不是0
  int end = right;
  while(begin<end)
  {
    //基准值选右边，begin开始走
    //这里是小于等于，不能为小于
    while(begin<end && v[begin]<=v[right])
      ++begin;
    while(begin<end && v[end]>=v[right])
      --end;

    if(begin<end)
      Swap(v[begin],v[end]);
  }
  Swap(v[begin],v[right]);
  return begin;
}

int Partition_2(std::vector<int> &v,int left,int right)
{
  int begin = left;
  int end = right;
  int key = v[right];
  while(begin<end)
  {
    while(begin<end && v[begin]<=key)
      ++begin;
    v[end] = v[begin];
    while(begin<end && v[end]>=key)
      --end;
    v[begin] = v[end];
  }
  v[begin] = key;
  return begin;
}
int Partition_3(std::vector<int> &v,int left,int right)
{
  int div = left;
  int cur = left;

  while(cur != right)
  {
    while(cur != right && v[cur]>=v[right])
      ++cur;
    if(cur != right){
      Swap(v[div],v[cur]);
      ++div;++cur;
    }
  }
  Swap(v[div],v[right]);
  return div;
}
void _QuickSort(std::vector<int> &v,int left,int right)
{
  if(left>=right)
    return;

  int div = Partition_3(v,left,right);//基准值位置

  _QuickSort(v,left,div-1);
  _QuickSort(v,div+1,right);
}

void QuickSort(std::vector<int> &v)
{
  _QuickSort(v,0,v.size()-1);
}

void Merge(std::vector<int> &v,int left,int mid,int right,int *newArr)
{
  int begin_1 = left;
  int begin_2 = mid;
  int indexNew = left;

  while(begin_1<mid && begin_2<right)
  {
    if(v[begin_1]<=v[begin_2])
      newArr[indexNew++] = v[begin_1++];
    else 
      newArr[indexNew++] = v[begin_2++];
  }
  while(begin_1<mid)
    newArr[indexNew++] = v[begin_1++];
  while(begin_2<right)
  {
      newArr[indexNew++] = v[begin_2++];
  }
  for(int i = left;i<right;++i)
    v[i] = newArr[i];
}
//左闭右开
void _MergeSort(std::vector<int> &v,int left,int right,int *newArr)
{
  //剩下一个数据退出递归
  if((right-left) == 1)
    return;
  //没有数据退出递归
  if(left>=right)
    return;
  int mid = left + ((right-left)>>1);
  _MergeSort(v,left,mid,newArr);
  _MergeSort(v,mid,right,newArr);
  Merge(v,left,mid,right,newArr);
}
void MergeSort(std::vector<int> &v)
{
  int *newArr = new int[v.size()];
  _MergeSort(v,0,v.size(),newArr);
  delete[] newArr;
}
int main()
{
  std::vector<int> v1{3,9,0,7,8,6,3,4,2,5,0,10,1,5};
  std::vector<int> v2{1,2,3,4,5,6,7};
  std::vector<int> v3{1};
  std::vector<int> v4{1,0,1,1,1};
  //InsertSort(v1);
  //Print(v1);
  //ShellSort(v1);
  //Print(v1);
  //SelectSort(v1);
  //Print(v1);
  //SelectTwoSort(v1);
  //HeapSort(v1);
  //BubbleSort(v1);
  //QuickSort(v1);
  MergeSort(v1);
  Print(v1);
  return 0;
}

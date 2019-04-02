#include<iostream>
using namespace std;
#include<vector>


void Swap(int &left,int &right)
{
  int tmp = left;
  left = right;
  right = tmp;
}

int Partition(vector<int> &v,int left,int right)
{
  int key = v[right];
  int end = right;
  int start = left;
  while(start<end)
  {
    while(start<end && v[start]<=key)
      ++start;
    while(start<end && v[end]>=key)
      --end;
    if(start != end)
      Swap(v[start],v[end]);
  }
  Swap(v[start],v[right]);
  return start;
}

void _QuickSort(vector<int> &v,int left,int right)
{
  int mid = Partition(v,left,right);
  _QuickSort(v,left,mid-1);
  _QuickSort(v,mid+1,right);
}
void QuickSort(vector<int> &v)
{
  _QuickSort(v,0,v.size()-1);
}

int main()
{
  vector<int> v{3,2,5,4,1,7,5,8};
  QuickSort(v);
  for(auto& e:v)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}

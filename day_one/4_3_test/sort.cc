#include<iostream>
#include<vector>
using namespace std;

void Swap(int &left,int& right)
{
  int tmp = left;
  left = right;
  right = tmp;
}
int Partion1(vector<int> &v,int left,int right)
{
  int begin = left;
  int end = right;
  while(begin<end)
  {
    while(begin<end && v[begin]<=v[right])
      ++begin;
    while(begin<end && v[end]>=v[right])
      --end;
    Swap(v[begin],v[end]);
  }
  Swap(v[begin],v[right]);
  return begin;
}
int Partion2(vector<int>& v,int left,int right)
{
  int key = v[right];
  int begin = left;
  int end = right;
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
int Partion3(vector<int>& v,int left,int right)
{
  int div = left;
  int cur = left;
  while(cur<right)
  {
    if(v[cur]<=v[right])
    {
      Swap(v[div],v[cur]);
      ++cur;
      ++div;
    }
    else 
    {
      ++cur;
    }
  }
  Swap(v[div],v[right]);
  return div;
}
void _QuickSort(vector<int> &v,int left,int right)
{
  if(left<right)
  {
    int div = Partion3(v,left,right);
    _QuickSort(v,left,div-1);
    _QuickSort(v,div+1,right);
  }
}

void QuickSort(vector<int> &v)
{
  _QuickSort(v,0,v.size()-1);
}

int main()
{
  vector<int> v1{3,2,1,5,6,4,8,9,0,4};
  vector<int> v2{1,1,1,0,1,0,1,1};
  vector<int> v3{1,2,3,4,5,6,7,8};
  vector<int> v4{9,8,7,5,4,3,2,1};
  QuickSort(v1);
  for(auto & e: v1)
    cout<<e<<" ";
  cout<<endl;
  QuickSort(v2);
  for(auto & e: v2)
    cout<<e<<" ";
  cout<<endl;
  QuickSort(v3);
  QuickSort(v4);
  for(auto & e: v3)
    cout<<e<<" ";
  cout<<endl;
  for(auto & e: v4)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}

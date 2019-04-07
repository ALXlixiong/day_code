//给定序列中找逆序对
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
  private:
    long long _count = 0;
  public:
    void Merge(vector<int> &v,int left,int div,int right,vector<int> &tmp)
    {
      int end1 = div-1;
      int end2 = right-1;
      int index = right-1;
      while(end1>=left && end2>=div)
      {
        if(v[end1]>v[end2])
        {
          tmp[index--] = v[end1--];
          _count += end2-div+1;
        }
        else 
        {
          tmp[index--] = v[end2--];
        }
      }
      while(end1>=left)
      {
        tmp[index--] = v[end1--];
      }
      while(end2>=div)
      {
        tmp[index--] = v[end2--];
      }
      for(int i = left;i<right;++i)
        v[i] = tmp[i];
    }
    void _InversePairs(vector<int> &v,int left,int right,vector<int> &tmp)
    {
      if(left<right-1)
      {
        int div = left + ((right-left)>>1);
        _InversePairs(v,left,div,tmp);
        _InversePairs(v,div,right,tmp);
        Merge(v,left,div,right,tmp);
      }
    }
    int InversePairs(vector<int> data)
    {
      if(data.empty())
        return 0;
      vector<int> tmp(data.size());
      _InversePairs(data,0,data.size(),tmp);
      return _count%1000000007;
    }
};

int main()
{
  vector<int> v{1,2,3,4,5,6,7,0};
  Solution s;
  int ret = s.InversePairs(v);
  cout<<ret<<endl;
  return 0;
}

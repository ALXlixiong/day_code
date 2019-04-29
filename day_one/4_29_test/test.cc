#include <iostream>
using namespace std;
#include <vector>
class Solution
{
  public:
    static int GetMaxSolve(vector<int> &v)
    {
      //求最长子序列
      vector<int> dp(v.size(),1);
      for(int i = 0;i<v.size();++i)
      {
        for(int j = 0;j<=i;++j)
        {
          if(v[j]<v[i])
            dp[i] = dp[j] + 1;
        }
      }

      //求最大值
      int ret = 1;
      for(int i = 0;i<dp.size();++i)
      {
        if(dp[i]>ret)
          ret = dp[i];
      }
      return ret;
    }
};

int main()
{
  vector<int> v{10,4,5,12,8};
  int ret = Solution::GetMaxSolve(v);
  cout<<"ret = "<<ret<<endl;
  return 0;
}

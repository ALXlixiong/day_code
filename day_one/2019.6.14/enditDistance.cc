#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
class Solution
{
    private:
        string _str1;
        string _str2;
    public:
        Solution(string str1,string str2):_str1(str1),_str2(str2)
    {}
        void GetEnditDistance()
        {
            vector<vector<int> > dp(_str1.size()+1,vector<int>(_str2.size()+1,0));
            for(int i = 0;i<dp[0].size();++i)
            {
                if(i == 0)
                    dp[0][0] = 0;
                else
                {
                    dp[0][i] = dp[0][i-1] + 1;
                }
            }

            for(int i = 1;i<dp.size();++i)
            {
                dp[i][0] = dp[i-1][0] + 1;
            }

            for(int i = 1;i<dp.size();++i)
            {
                for(int j = 1;j<dp[0].size();++j)
                {
                    if(_str1[i-1] == _str2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
            for(int i = 0;i<dp.size();++i)
            {
                for(int j = 0;j<dp[0].size();++j)
                    cout<<dp[i][j]<<" ";
                cout<<endl;
            }
            cout<<dp[_str1.size()][_str2.size()]<<endl;
        }
};
int main()
{
    string str1 ="";
    string str2 ="";
    while(cin>>str1>>str2)
    {
        Solution s(str1,str2);
        s.GetEnditDistance();
    }
    return 0;
}
